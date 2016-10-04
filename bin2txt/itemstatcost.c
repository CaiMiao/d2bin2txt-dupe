#include "global.h"

#define FILE_PREFIX "itemstatcost"
#define NAME_PREFIX "is"

/*
Stat - An Id pointer used in other *.txt files (Properties.txt, Skills.txt, States.txt and also within ItemStatCost.txt) to refer to this stat, this field must be unique, otherwise you're looking into a world of glitches and bugs.

Id - This field isn't compiled into the bin files, and thus only serves as reference for the internal numeric Id. The internal idea is identical to the # of the record in the array (that is, the first stat would be 0, the second 1 and so on).

Send Other - A boolean that controls whenever the value of this stat is sent to other players, this is only semi functional because most of this is hardcoded to specific stats only, leave it set only for the stats that are being sent in vanilla (Strength
, Dexterity etc) because the game needs to keep clients up to date on these values to function properly (otherwise you'll just glitch up the game).

Signed - A boolean that controls whenever the stat is signed (can be both positive and negative) or unsigned (can only be positive), this doesn't really seam to make any difference because whenever a stat is really signed or unsigned depends on how the 
code is designed to use it, and not on this column, for example Life, Mana, Stamina (etc) can all become negative when they exceed 8388607 * 256 no matter what you set this too, I suspect this simply has to do with the way the game reads stat packets 
because these packets generally only transmit stats in WORD size and it would need to know if they are signed or unsigned for a semi-proper conversion (...)

Send Bits - How many bits of data the game will attempt to fit into a stat update packet for the value of the stat if the stat is sent to clients, again this is not really utilized too a very great extent because most of this is hardcoded, in general 
for signed stats, it is best to set this to 1 more then Save Bits (so say, if save bits is 31 then set this to 32), for unsigned stats it shouldn't matter. Stats with Save Bits of 32 are never treated as signed, always unsigned, and you can't really set 
Send Bits to above 32 bits anyway (for very obvious reasons).

Send Param - How many bits of data the game will attempt to fit into a stat update packet for the parameter of the stat if the stat is sent to clients, it is best to set this to 1 more then Save Param Bits unless it is set to 32 bits (in which case it 
is unsigned), otherwise the param is always signed. This is used to transmit things like the skill granted by oskills (etc), however the same applies here as applied to the previous column, this is almost entirely hardcoded.

UpdateAnimRate - This boolean tells the game to call the speed handler and properly adjust the speed of a unit when a stat with this boolean set to true is altered on the unit (via a skill for example), this is for example the case when an aura is 
applied, so that the speed of the unit changes immediately and not after the current cycle (either attack, walk to a cell etc) ends... As usual, this is rather hardcoded so you'd need to expand the code if you add custom speed stats like these!

Saved - This boolean controls whenever the value of the stat is saved on characters inside the *.d2s file after you leave the game, be aware that statNo 511 is used to signify the "End-Of-Stat-Section" and cannot be used, there are reports that only 
stats 0 to 255 are saveable and other reports that all 510 stats are saveable, I haven't tested this myself so I cannot validate either claim ATM... Looking at the *.d2s reading and writing code I however could not find any artificially imposed 
limitation (other then the aforementioned fact stat 511 cannot be used for anything).

CSvSigned - If the previous column is set to true, this boolean controls whenever the stat is saved in signed or unsigned format, this makes no real difference, other then the fact the way it is written and read from the *.d2s is different (this has 
more revelance when you have the source code at hand and don't want to get tons of warning messages about signed / unsigned mismatch I guess)...

CSvBits - How many bits of data are allocated to the value of this stat within the *.d2s file stat section when the stat is saved (only used if the Saved boolean is true), for unsigned stats you can go all the way to 32 bits (allowing for a range of 0 
to 4294967295), for signed stats you can go only to 31 bits (allowing for a range of -2147483648 to 2147483647), it makes no real difference as stated for the previous column, keep it like in vanilla for the existing stats though, it works so no need to 
fix it. Setting this field to 32 bits for a signed stat has the same effect as setting CSvSigned to false.

CSvParam - How many bits of data are allocated to the parameter of this stat within the *.d2s file stat section when the stat is saved (only used if the Saved boolean is true), the parameter is always signed, unless you set this to 32 bits, in which 
case it becomes unsigned. The same applies here as for the previous column...

fCallback - This boolean controls whenever the stat-assignment callback function is called by the game if the value of this stat changes, this is used to assign / remove item events, skills, auras, states and more to the character / monster... For new 
special effects you have to expand the callback function... It will work fine for new stats that trigger item events however!

fMin - This boolean controls whenever the game will attempt to keep the stat in range calling a special function (and at times doing this inline, such as when the stats are altered by an aura), this prevents stats like strength, dexterity, energy, 
vitality (etc) from dropping below zero...

MinAccr - This field (a DWORD btw) controls the minimum value that the stat is capped to, this seams (I haven't verified this) to work hand-in-hand with fMin, however the times I've seen the code access that flag inline I haven't seen it utilize this 
column, but rather use hardcoded minimum values!

Encode - This field tells the game whenever to encode the stat (and in this case in what way to encode it) when it is saved to conserve space, this is used for complex stats with more then just a parameter and a value such as 'chance to cast on event', 
which have to store the chance, sLvl and the skill to cast, the arithmetics of this are rather complex and aren't within the scope of this fileguide, you can read about them in several old forum posts however... For new stats, follow the theme vanilla 
is using and use this only if you try to duplicate a stat that is encoded in vanilla!

Add and Multiply - These two fields control the additional price added to an item's cost (be aware that certain stats like armorclass on armors (etc) are treated more then once as there are hardcoded cases for them!), the bonus equals: cost * (1 + value 
* multiply / 1024)) + add (...)

Divide - This field is not used by the code anymore, the game uses a inline function for all this price judgling, and it never accesses divide, rather it uses a hardcoded division by 1024!

ValShift - This field tells the game how the stat is going to be read from and written to items, it does not control whenever the stat is generally used in higher precision, this is entirely hardcoded! Basically this field is only there to save space in 
the *.d2s file, so that instead of having to save +256 life it will simply save +1 life when this stat is present on an item!

1.09-Save Bits and 1.09-Save Add - These fields are used only for items imported from v1.07 - v1.09, they replace Save Bits and Save Add so that you can convert the items to the old stat format to the new one, character stats didn't use ItemStatCost.txt 
prior to v1.10 so this doesn't apply to those stats... If you want to prevent people from cheating by creating a v1.09 character and then entering your mod with hacked items (that will get automatically converted by the game), simply blank out all these 
columns and they'll get a nice "bad stats" or "bad inventory" error in their face icon_wink.gif

Save Bits and Save Add - These fields control how many bits of data are allocated to the value of this stat within the *.d2s file item stat section ONLY, they have almost no realtime application at all, stats granted by skills and monster stats (etc) 
are not in any way or form bound to this! The only realtime application this has is when an item is getting compressed / decompressed (which happens every time you pick it up or do anything with it) any way, with this misconception taken off the shelf, 
lets look at how they work. Save Bits controls how many bits of data are allocated to the stat value (see discussion under CSvBits for more info about unsigned / signed implications on what values you can use in this field), the actual maximum value of 
the stat is therefore equal to 2^SaveBits-1, now Save Add comes into play, this controls how large the negative range of the stat can be, for example a Save Add equal to 100 would allow you to use -100 for this stat on an item, this also means the 
maximum value possible for the stat decreases by 100, thus the final range possible for a stat is -SaveAdd to 2^SaveBits-(SaveAdd+1).

Save Param Bits - This field controls how many bits of data are allocated to the parameter of this stat when it is saved on items, the same applies here as to the previous column and to CSvParam so refer to the description of these columns, Save Add 
does not effect the maximum or minimum value of the stat's parameter however... It is best to set this to 17 for all stats that use any form of Id for their parameter (either a skill or a monster etc), because most Id ranges are capped to 65,535, and 
these parameters always being signed unless they are set to store 32 bits means this will allow you to use all Ids without any fear of glitches or bugs!

KeepZero - This boolean supposedly controls whenever to prevent the stat from going negative, probably working hand-in-hand with some of the fMin implementations, at best the effect is however only client-side, as we all know stats like mana and stamina 
can roll over when they exceed 8388607 * 256!

Op, Op Param, Op Base and Op Stat1 to Op Stat3 - These fields control special forms of stat assignment used for example for stats that add a bonus depending on cLvl (etc), I'll explain each of the op methods in detail below (there are in total 13 op 
formulae, but not all are used by the game)... Leaving this field blank or setting it to 0 will use the default op, that just adds the stat to the unit directly... In the below formulae, opstat refers to the stats set in the three Op Stat columns, 
statvalue refers to the value of the stat itself (the stat that has the op stuff assigned to it), basevalue refers to the stat set in the Op Base column and param refers to the value set in the Op Param column!

1 - adds opstat.base * statvalue / 100 to the opstat.

2 - adds (statvalue * basevalue) / (2 ^ param) to the opstat, this does not work properly with any stat other then level because of the way this is updated, it is only refreshed when you re-equip the item, your character is saved or you level up, 
similar to passive skills, just because it looks like it works in the item description does not mean it does, the game just recalculates the information in the description every frame, while the values remain unchanged serverside.

3 - this is a percentage based version of op #2, look at op #2 for information about the formula behind it, just remember the stat is increased by a percentage rather then by adding an integer.

4 - this works the same way op #2 works, however the stat bonus is added to the item and not to the player (so that +defense per level properly adds the defense to the armor and not to the character directly!)

5 - this works like op #4 but is percentage based, it is used for percentage based increase of stats that are found on the item itself, and not stats that are found on the character.

6 - like for op #7, however this adds a plain bonus to the stat, and just like #7 it also doesn't work so I won't bother to explain the arithmetic behind it either.

7 - this is used to increase a stat based on the current daytime of the game world by a percentage, there is no need to explain the arithmetics behind it because frankly enough it just doesn't work serverside, it only updates clientside so this op is 
essentially useless.

8 - hardcoded to work only with maxmana, this will apply the proper amount of mana to your character based on CharStats.txt for the amount of energy the stat added (doesn't work for non characters)

9 - hardcoded to work only with maxhp and maxstamina, this will apply the proper amount of maxhp and maxstamina to your character based on CharStats.txt for the amount of vitality the stat added (doesn't work for non characters)

10 - doesn't do anything, this has no switch case in the op function.

11 - adds opstat.base * statvalue / 100 similar to 1 and 13, the code just does a few more checks

12 - doesn't do anything, this has no switch case in the op function.

13 - adds opstat.base * statvalue / 100 to the value of opstat, this is useable only on items it will not apply the bonus to other unit types (this is why it is used for +% durability, +% level requirement, +% damage, +% defense [etc]).


Direct - this boolean controls whenever this stat has a maximum stat associated with it, which among others means that unless you screw up something badly, this stat can never exceed the value of the maximum stat and that any change to this stat is 
permanent (a skill that alters mana, hitpoints or stamina is permanent, while a skill that alters maxmana, maxhp and maxstamina is temporary). You do not need to specify a maximum stat for the effect to be permanent, this can be used to get kill 
counters to work (look for SVR's old post).

MaxStat - the maximum stat associated with this stat, this field only ever has an effect if Direct is set to true, see the discussion under that field. Percentage based increases to the max stat will usually alter this stat too, however this has some 
hardcoded aspects to it and is not entirely softcoded.

ItemSpecific - this boolean controls whenever this stat is specific to a single item, that is, if you socket a jewel that adds +durability or +quantity into something else, the quantity or durability of both items will not stack when a general call to 
GetStat is returned, however whenever this works properly is unknown, I at least haven't tested it and nobody else has either. It should also prevent the stat from being added to the item owners accumulated total of that stat.

DamageRelated - this boolean controls whenever the stat will be restricted to a single weapon and not stack with the item owners accumulated total of that stat when he equips the weapon (this is used to prevent barbarians who dual wield from for example 
having 50% lifesteal if one weapon has 1% and the other 49% no matter what weapon they swing). To explain this more indepth, when you swing your weapon the game copies all these stats (from the weapon involved) to a temporary statlist that is then 
flushed after the attack is completed (this is not 100% what happens, but it should give you an idea).

ItemEvent1 and ItemEvent2 - the event (from Events.txt) that will trigger the associated event function be aware that not every event will work with every event function, and some event functions will not work when set as an item event!

ItemEventFunc1 and ItemEventFunc2 - the event function associated with the corresponding event set in the previous columns. Below is a list of events and what they do.

1 - shoots a missile at the owner of a missile that has just hit you (Chilling Armor uses this)
2 - freezes the attacker for a set duration the attacker (Frozen Armor uses this)
3 - does cold damage to and chills the attacker (Shiver Armor uses this)
4 - % of damage taken is done to the attacker (Iron Maiden, thorns uses a hardcoded stat)
5 - % of damage done added to life, bypassing the targets resistance (used by Life Tap)
6 - attacker takes physical damage of #
7 - knocks the target back
8 - induces fear in the target making it run away
9 - applies Dim Vision to the target (it casts the actual curse on the monster)
10 - attacker takes lightning damage of #
11 - attacker takes fire damage of #
12 - attacker takes cold damage of #
13 - % damage taken is added to mana
14 - freezes the target
15 - causes the target to bleed and lose life (negative life regen)
16 - crushing blow against the target
17 - mana after killing a monster
18 - life after killing a demon
19 - slows the target
20 - casts a skill against the defender
21 - casts a skill against the attacker
22 - absorbs physical damage taken (used by Bone Armor)
23 - transfers damage done from the summon to the owner (used by Blood Golem)
24 - used by Energy Shield to absorb damage and shift it from life to mana
25 - absorbs elemental damage taken (used by Cyclone Armor)
26 - transfers damage taken from the summon to the owner (used by Blood Golem)
27 - used to slow the attacker if he hits a unit that has the slow target stat (used by Clay Golem)
28 - life after killing a monster
29 - destroys the corpse of a killed monster (rest in peace effect)
30 - cast a skill when the event occurs, without a target
31 - reanimate the target as the specified monster


DescPriority - the higher this value is the further up in the item description this stat will be listed, if more then one stat share the same priority they are listed in the order they are inside the file, valid values range between 0 and 255.

DescFunc - the function used for generating the description for this stat, this works like the descfuncs in SkillDesc.txt pretty much. See below for an explanation of individual functions, these are listed the way they would show up if DescVal is set to 
1. This follows the syntax Char used in the old fileguide, but includes the functions he didn't cover.

1 - +[value] [string1]
2 - [value]% [string1]
3 - [value] [string1]
4 - +[value]% [string1]
5 - [value*100/128]% [string1]
6 - +[value] [string1] [string2]
7 - [value]% [string1] [string2]
8 - +[value]% [string1] [string2]
9 - [value] [string1] [string2]
10 - [value*100/128]% [string1] [string2]
11 - Repairs 1 Durability In [100 / value] Seconds
12 - +[value] [string1]
13 - +[value] to [class] Skill Levels
14 - +[value] to [skilltab] Skill Levels ([class] Only)
15 - [chance]% to case [slvl] [skill] on [event]
16 - Level [sLvl] [skill] Aura When Equipped
17 - [value] [string1] (Increases near [time])
18 - [value]% [string1] (Increases near [time])
19 - this is used by stats that use Blizzard's sprintf implementation (if you don't know what that is, it won't be of interest to you eitherway I guess), look at how prismatic is setup, the string is the format that gets passed to their sprintf spinoff.
20 - [value * -1]% [string1]
21 - [value * -1] [string1]
22 - [value]% [string1] [montype] (warning: this is bugged in vanilla and doesn't work properly, see CE forum)
23 - [value]% [string1] [monster]
24 - used for charges, we all know how that desc looks icon_wink.gif
25 - not used by vanilla, present in the code but I didn't test it yet
26 - not used by vanilla, present in the code but I didn't test it yet
27 - +[value] to [skill] ([class] Only)
28 - +[value] to [skill]

DescVal - Controls whenever and if so in what way the stat value is shown, 0 = doesn't show the value of the stat, 1 = shows the value of the stat infront of the description, 2 = shows the value of the stat after the description.

DescStrPos - The string used for the description when the stat value is positive.

DescStrNeg - The string used for the description when the stat value is negative.

DescStr2 - An additional string used by some DescFuncs, usually used as a suffix or for aditional info (such as per character level etc).

dGrp - When all stats in this group are present on the same item and they all have the same value, replace their description with the associated group description.

dGrpFunc - The same as DescFunc, just for the group description

dGrpVal - The same as DescVal, just for the group description

dGrpStrPos - The same as DescStrPos, just for the group description

dGrpStrNeg - The same as DescStrNeg, just for the group description

dGrpStr2 - The same as DescStr2, just for the group description

Stuff - Stay far away from this column unless you really know what you're doing and / or work for Blizzard, this column is used during bin-file creation to generate a cache regulating the op-stat stuff and other things, changing it can be futile, it 
works like the constants column in MonUMod.txt and has no other relation to ItemStatCost.txt, the first stat in the file simply must have this set or else you may break the entire op stuff.

*/

/*
A.Stat = ��������
B.ID = ����ID��
C.Send Other = �ܿ�������������������Ϸʱ���������Ƿ��͸�������,ֻ�����Щ��ͼ��Ҫ��ϸߵ�����(faster attack/cast/gethit rate)������ĳЩԭ��,����(dexterity)������(strength)Ҳͬʱ�����͡�����һ��txt�ļ���֪��
D.Signed = ������ֵ�Ƿ�Ϊ�з�������Ҳ����˵�������Ƿ���Ϊ��ֵ(negative)��
E.Sendbits = �ڿͻ��˺ͷ�����֮�䴫�ʹ�ֵʱ���õ�λ����
F.Send Param = ��ͻ��˺ͷ������йصĲ�����
G.UpdateAnimateRate = ???�����������ȡ����ֵ�����߿ͻ��˸��½�ɫ���������ʡ�
H.Saved = ��ɫ�浵ʱ�������Ƿ�ͬʱ�����档��Ʒ�ϵ���������Ʒһ�𱣴档
I.CSvSigned = �ڽ�ɫ�浵�Ƿ�����з���������������ԡ�1=��,0=��
J.CSvBits = �洢λ��,�ڽ�ɫ�浵�в�ȡ����λ���档�ܹ���������ֵΪ''2^CSvBits-1''��
K.CSvParam = �洢����,�뱣��ĳЩ���ԵĲ����йء�
L.fCallback = ???
M.fMin = ???
N.MinAccr = ???
O.Encode = ����뷽ʽ�йء�
P/Q/R.Add/Multiply/Divide = ������Ʒ�۸�ʱ�Ĳ���ֵ��(����txt�ļ�ͬ)
S.ValShift = ����ֵ�Զ��ľ��ȱ仯?����1����ʾ��2^1=2�׾���,��2������2^2=4�׾���,��8������2^8=256�׾���,����������Ͱ�1/256�ľ��Ƚ��м��㡣
T/U.1.09-Save Bits/1.09-Save Add = ��1.09���еĴ洢λ��/���1.09������ֵ���������ɫת���й�,��1.09�Ĵ浵����1.10��
V/W.Save Bits/Save Add = ����������Ʒ����ֵ�ı��档ͬʱҲ�����˸����Կ��ܵ���С�����ֵ������,����Save Bits��������������ֵ�Ĵ洢λ��,����Save Add������������Сֵ,�Һ�''Save Bits'һ��������ֵ��
���Ϊ:stat��Сֵ = - [Save Add];
stat���ֵ = 2^[Save Bits] - [Save Add] - 1;
����:"Save Add'' = 32,"Save Bits = 8"
����:��Сֵ = - 32;
���ֵ = 2^8 - 32 -1 = 256 - 33 = 223
X.SaveParamBits = ���������Զ���λ(bits)����(???)��
Y.keepzero = ����ֵ�����Ƹ������ܷ���ָ�ֵ(�������Ϊ������Ч��)��1=���ܡ�
Z.op = ������ID��������������Բ�����Ч����
��֪��ID����Ч��:
1 : op ״̬�� [statvalue] �ٷֱ����ӣ�op stats are increased by [statvalue] percent��
2 : op ״̬�� [statvalue] * [op base] / 2^[op param]���ӣ�op stats are increased by [statvalue] * [op base] / 2^[op param]��
3 : δʹ�ã�Ч��δ֪��not used, effect unknown��
4 : �ƺ��Ǻ�2��Ч����ͬ��seems to have the same effect as 2��
5 : op ״̬�� [statvalue] * [op base] / 2^[op param]�ٷֱ����ӣ�op stats are increased by [statvalue] * [op base] / 2^[op param] percent��
6 : op ״̬��ʱ�����ӣ�op stats are increased by time��
7 : op ״̬��ʱ��Ͱٷֱ����ӣ�op stats are increased by time and percent��
8 : �������㷨��ֵ��������ֵ�����ӣ�used to calculate the mana based on energy��
9 : ��������������������ֵ���ڻ���ֵ�����ӣ�used to calculate the hitpoints and stamina based on vitality��
AA.op param = ����op����
AB.op base = ����op����
AC/AD/AE.op stat1-op stat3 = ����״̬,����op����
AF.direct = ����������ܼӳɵ�����������,�˴�����Ϊ1�����統װ����һ��+30mana����Ʒʱ,������manaֵҲ��ͬʱ���ӡ�
AG.maxstat = ������direct=1����ʱ,�������ܼӳɵ���������ԡ�
AH.itemspecific = �������Ƿ�Ϊĳ��(��)��Ʒ����(��ֻ��Ӱ�����/����Ʒ),�����;ö�,�����ȡ��������������������ʹ��ĵڶ��������������ӵ�һ�������Ĺ����ٶȡ�
AI.damagerelated = �������Ƿ��롮���˺�����(damage)�йء�1=�ǡ�(Ч��δ֪)
AJ.itemevent1 = ���¼�(event)����ʱ,��������intemeventfuc1����(����)�� 
AK.itemeventfunc1 = �����ڡ���itemevent1�����ϵĺ�����ʹ�õĺ�������:
6:attacker takes damage of [statvalue] // �����߻���˺�
7:knockback // ����
8:howl effect // bar�ĺ��Ч��
9:stupidity effect // ��äЧ��
10:attacker takes lightning damage of [statvalue] // �����߻�������˺�
14:freeze effect // ����Ч��
15: openwounds effect // ˺���˿�Ч��
16:crushing blow // һ������(���ߡ������Դ����?!)
17:get mana (after kill) // ÿɱ��һ������õ�ħ��ֵ
18:get life (after demon kill) 
19:slow effect // �ٻ�Ч��
20:skill is released // �����ͷ�,�����¼�:��Χ��&ɱ�������
21:skill is released //����20?!
28:get life (after kill) // ÿɱ��һ������õ�����ֵ
29:slain monster rests in peace // ɱ������ظ�ƽ��
30:skill is released // �ͷż���,�����¼�:��ɱ��&����
31:reanimate slain monster // ɱ������󱻹���
AL.itemevent2 = ���¼�(event)����ʱ,ִ�С���intemeventfuc2����
AM.itemeventfunc2 = �����ڡ���itemevent2�����ϵĺ�����
AN.descpriority =���Ƹ���������Ʒ����ʾ�����ȼ���ֵԽ��,����Ʒ�ϳ��ֵ�Խ�硣(�в���ȷ��)
AO.descfunc = ����������ʾ��ʽ�ĺ��������������е�һЩ:
1 : + [��ֵ] [�ַ���]��+[value] [string]��
2 : [��ֵ]% [�ַ���]��[value]% [string]��
3 : [��ֵ] [�ַ���]��[value] [string]��
4 : + [��ֵ]% [�ַ���]��+[value]% [string]��
5 : [��ֵ/1.28]% [�ַ���]��Ұ���˵ĺ�м���ʹ�ã�[value/1.28]% [string] // used for howl��
6 : + [��ֵ] [�ַ���] (���ڽ�ɫ�ȼ�)��+[value] [string] (based on character level)��
7 : [��ֵ]% [�ַ���] (���ڽ�ɫ�ȼ�)��[value]% [string] (based on character level)��
8 : + [��ֵ]% [�ַ���] (���ڽ�ɫ�ȼ�)��+[value]% [string] (based on character level)��
9 : [��ֵ] [�ַ���] (���ڽ�ɫ�ȼ�)��[value] [string] (based on character level)��
10 : [��ֵ/1.28]% [�ַ���] (���ڽ�ɫ�ȼ�)��[value/1.28]% [string] (based on character level)��
11 : ÿ [100/��ֵ] ���Զ��޸�1���;öȣ�Repairs 1 durability in [100/value] seconds��
12 : + [��ֵ] [�ַ���]����ä�ͱ���ʹ�ã�+[value] [string] // used for stupidity, freeze��
13 : + [��ֵ] �� [��ɫ] ���ܵȼ���+[value] to [class] skill levels��
14 : + [��ֵ] �� [��ɫ����ҳ] (����[��ɫ])��+[value] to [skilltab] skills ([class] only)��
16 : װ��ʱ���ֵȼ� %d %s ������Level %d %s Aura When Equipped��
AP.descval = 
0:����ʾֵ��
1:ֵ����ʾ,����ʾ˳��Ϊ����ֵ+�ַ������������硰+5 to strength����(��5������)��
2:�ַ�������ʾ,Ȼ�����ֵ,�������ַ���+ֵ���������确��strenght +5����(������5)��
AQ.descstrpos = ֵΪ��ʱʹ�õ��������ַ�����
AR.descstrneg = ֵΪ��ʱʹ�õ��������ַ�����
AS.descstr2 = �ڶ�����ʾ�ַ�(�롯��attributes/per level�����й�--��ȼ���������,�硯��item-resist-cold-perlevel,ID=230����)��
AT.dgrp = ��ʾ�顣ͬһ��ʾ���е���ͬ���Խ�һ����ʾ��
˵��:��txtԴ�ļ���һ��ֻ������,ÿ�麬�ĸ����ԡ�
��һ:����dgrp=1����,��������strength(����,ID=0)����,����energy(����,ID=1)����,����dexterity(����,ID=2)'',''vitality(����,ID=3)''��
���:''dgrp=2'',��������fireresist(����,ID=39)'',''lightresist(������,ID=41)'',''coldresist(����,ID=43)'',''poisonresist(����,ID=45)''��
AU.dgrpfunc = �롮��descfunc����ͬ,������ʾ��(display groups)����ʾ��ʽ��
AV.dgrpval = �롮��descval����ͬ,�����ʾ�顣
AW.dgrpstrpos = �롯��descstrpos����ͬ,�����ʾ�顣
AX.dgrpstrneg = �롯��descstrneg����ͬ,�����ʾ�顣
AY.dgrpstr2 = �롯��descstr2����ͬ,�����ʾ�顣
AZ.stuff = ???
BA.*eol = �н�������0����

ע: op��������ʾ��ʽ�ο���Sloovy������,�ڴ˱�ʾ��л��
*/

/*
�ļ���������
Item�����ߣ��������ʾװ����
Stat��״̬���������ʾ���ԡ�
Cost���������������ʾĳЩ�����Ϣ��
���Դ��ļ������������п�����װ�����ֵ����Ե������Ϣ��1.10�汾�Ժ���ļ����ּ������������Ե�һЩ��Ϣ��
���ļ��е�ÿһ�б�ʾһ�����ԡ�


�ظ�

    2¥
    2011-09-20 23:48

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-20 23:48

    �ٱ� |

    ��ʦ����
    ������ͽ
    11

����


�ظ�

    4¥
    2011-09-20 23:49

    �ٱ� |

    zqtjingzi
    С����
    12

Stat�������������������ļ��ж�ʹ�ô��е�������ָ��ĳ�����ԡ�

ID�����Ա�š�ʵ����û���õ���

Send Other�������Ƿ񽫴����Է��͸������ˣ��������ʱ����Ӳ����д����

Signed��������ֵ�Ƿ�Ϊ�з��������������˲��Բ���Ч��������Ӳ����д���ġ���˵����������ʱ���õ����С�

Sendbits���������������ʱ���õ�λ�����������ʱ����Ӳ����д�������������ֵΪ�з�����������е�ֵ���ΪSave Bits + 1���Ҳ�Ҫ����32��

Send Param��������������ԵĲ���ʱ���õ�λ�����������ʱ����Ӳ����д��������Param��Ϊ�з����������Դ��е�ֵ���ΪSave Param Bits + 1�Ҳ�Ҫ����32��

UpdateAnimateRate���������Ա仯ʱ�Ƿ�����ڼ��ѭ������£����ܻ����Ļ��Ч�������������ʱ����Ӳ����д����

Saved�������Ե�ֵ�Ƿ����.d2s�ļ��У�����ֻ�����������ԡ�

CSvSigned���������Դ���.d2s�ļ��У��Ƿ�ʹ���з������洢�������ʱ����Ӳ����д����

CSvBits���������Դ���.d2s�ļ��У��洢��λ���Ƕ��١�

CSvParam���������Դ���.d2s�ļ��У������Բ����Ĵ洢λ���Ƕ��١�

fCallback���������Ա仯ʱ���Ƿ���÷��������Դﵽ�����Ե�Ч����������ĳһ���ܣ����޸����＼���б���

fMin�������Ե�ֵ�Ƿ��޶���һ����Χ�ڡ�

MinAccr���������Ե�ֵ���ޣ���ô����Сֵ�Ƕ��١�ʵ���ϴ��в������ã���Ӳ����д����

Encode���������ԵĲ�����Ϊ����ʱ�������������ܣ���ʹ�ú��ֱ��뷽ʽ�洢���Բ�����

Add���۸���������a��

Multiply���۸���������b��

Divide���۸���������ȫΪ1024��ʵ���϶��������ã�Ӳ������д����1024��

�����Զ���Ʒ�۸��Ӱ��ӦΪ cost * (1 + value * multiply / 1024) + add��

ValShift��������ֵ�ľ��ȡ���ʽΪ1/2^n��nΪ���е�ֵ��

1.09-Save Bits����1.07-1.09���еĴ洢λ����

1.09-Save Add����1.07-1.09���еĴ洢ƫ������

Save Bits���洢λ����Ӳ��������д��������Ϸ��ʼʱ���⣬���޸���ᵼ����Ϸ����
Save Add���洢ƫ������

�����Կ��ܴ��ڵ�ֵ�������������ƣ���СֵΪ-1 * SaveAdd�����ֵΪ 2^SaveBits - SaveAdd - 1��

SaveParamBits��Param�����Ĵ洢λ����

keepzero���������Ƿ��ܳ��ָ�ֵ����ʵ���ϲ�û�����á�




�ظ�

    5¥
    2011-09-20 23:49

    �ٱ� |

    zqtjingzi
    С����
    12

op��������ֵ�ļ��㹫ʽ��������г�op��ȡֵ**����Ӧ�ļ��㹫ʽ��

op param�����㹫ʽ�еĲ�����

op base�����㹫ʽ�еĲ�����

op stat1����������Ӱ�������1��

op stat2����������Ӱ�������2��

op stat3����������Ӱ�������3��

direct���������Ƿ��й��������ֵ���ԡ�

maxstat�������������������ֵ���ԣ�����direct=1ʱ�����á�

itemspecific���������Ƿ�ֻ�����ڵ�һ��Ʒ�������������;öȵ����Բ���ı�Ь�ӵ��;öȡ�

damagerelated���������Ƿ�ֻ�����ڵ�һ��������ڶ��������ϵĻ����˺�����ӵ���һ�������ϡ�

itemevent1�����������Ժ���1���¼�����Events.txt��������CB��Ҫ�Ȼ��й�����ܴ�����

itemeventfunc1���¼�1����ʱ�����ĺ�����������ȡֵ**�������ں��漯��˵����

itemevent2�����������Ժ���2���¼�����Events.txt������

itemeventfunc2���¼�2����ʱ�����ĺ�����

descpriority����Ʒ������ʾʱ�����ȼ������е�ֵԽ�����������װ���������б���Խ���ϣ�ȡֵ��ΧΪ0-255��

descfunc���������������Եķ�ʽ��ȡֵ**�Ͷ�Ӧ������ʽ���漯��˵����

descval�������ʾ�����Ե�ֵ��0��ʾ����ʾֵ��1��ʾ����ʾֵ����+5������2��ʾ����ʾֵ��������+5��

descstrpos������ֵΪ����ʱ��������䡣

descstrneg������ֵΪ����ʱ��������䡣

descstr2��������ʽ�е����2��

dgrp�����������������������ͬ��������������ֵ��Ȼ�ͳһ��ʾ����+1������+1���ݡ�+1������+1��������+1�������ԡ�����Ҳһ����Ŀǰֻ�����������м�������

dgrpfunc������ͬdescfunc����������ʾ�С�

dgrpval������ͬdescval����������ʾ�С�

dgrpstrpos������ͬdescstrpos����������ʾ�С�

dgrpstrneg������ͬdescstrneg����������ʾ�С�

dgrpstr2������ͬdescstr2����������ʾ�С�

stuff������㲻�Ǳ�ѩ�Ĺ�����Ա�Ļ��벻Ҫ����һ�С�bin�ļ�����ʱ���á�

*eol����β��־������Ϊ0��


�ظ�

    6¥
    2011-09-20 23:49

    �ٱ� |

    zqtjingzi
    С����
    12

˵��1��op��ȡֵ��Χ�����㷽ʽ��
��op param = p��op base = b��ԭ����ֵΪv����������ֵΪs��
op = 1 ���� s = b * v / 100
op = 2 ���� s = b * v / 2^p
op = 3 ���� s = b * v / 2^p ���ڰ��ٷֱ����ӵ����ԡ�
op = 4 ���� s = b * v / 2^p ����������װ�������ԡ�
op = 4 ���� s = b * v / 2^p ���ڰ��ٷֱ�������������װ�������ԡ�
op = 6 ���� ������ʱ��仯�����ԣ��Ѿ�û���ˡ�
op = 7 ���� ������ʱ��仯�Ұ��ٷֱ����ӵ����ԣ��Ѿ�û���ˡ�
op = 8 ���� ֻ���ھ������ԣ������CharStats.txt�е����ԶԲ�ͬ�Ľ�ɫ�Ӳ�ͬ�����ħ��ֵ��
op = 9 ���� ֻ�����������ԣ������CharStats.txt�е����ԶԲ�ͬ�Ľ�ɫ�Ӳ�ͬ���������ֵ���������ֵ��
op = 11���� s = b * v / 100 ��1����һЩ��صļ�顣
op = 13���� s = b * v / 100 ���ڽ�������һ��װ�������ԡ�


�ظ�

    7¥
    2011-09-20 23:49

    �ٱ� |

    zqtjingzi
    С����
    12

˵��2��ItemEventFunc��ȡֵ��Χ���������ã�
func = 1 ���� ����Զ�̹���������ʱ����һ���������纮��װ�ס�
func = 2 ���� �������������ˡ�
func = 3 ���� �Խ�������������һ���ı����˺���
func = 4 ���� ����������������������ɵ��˺���
func = 5 ���� ���������Ե��˵��˺�ת��Ϊ������
func = 6 ���� �������ܵ��˺���
func = 7 ���� ���ˡ�
func = 8 ���� �־塣
func = 9 ���� ��ä��
func = 10���� �������ܵ������˺���
func = 11���� �������ܵ������˺���
func = 12���� �������ܵ������˺���
func = 13���� �����������ת��Ϊ������
func = 14���� ����Ŀ�ꡣ
func = 15���� ˺���˿ڡ�
func = 16���� ѹ���Դ����
func = 17���� ɱ�������÷�����
func = 18���� ɱ����ħʱ���������
func = 19���� ���١�
func = 20���� ������ӵ���ߵĹ�������ʩ�ŷ�����
func = 21���� �Թ�������ӵ���ߵĶ���ʩ�ŷ�����
func = 22���� ���������˺���
func = 23���� ���ٻ�����ɵ��˺�ת����ɫ���ϡ�
func = 24���� �÷��������˺���
func = 25���� ����Ԫ���˺���
func = 26���� ���ٻ����ܵ����˺�ת����ɫ���ϡ�
func = 27���� ���˺���������ӵ���ߵĻ������ӵ�����˺����ļ��١�
func = 28���� ɱ������ʱ���������
func = 29���� ɱ������ָ�ƽ����
func = 30���� ��ĳһ�¼�����ʱʩ�ż��ܣ�����ѡ��ʩ�Ŷ���
func = 31���� ����Ŀ���Ϊĳһָ��Ŀ�ꡣ


�ظ�

    8¥
    2011-09-20 23:50

    �ٱ� |

    zqtjingzi
    С����
    12

˵��3��descfunc��ȡֵ��Χ������������ʽ��
valueΪ���Ե�ֵ��string1Ϊ�����Ա����Ӧ���ַ�����string2Ϊdescstr2�ж�Ӧ���ַ�����
func = 1 ���� +[value] [string1]
func = 2 ���� [value]% [string1]
func = 3 ���� [value] [string1]
func = 4 ���� +[value]% [string1]
func = 5 ���� [value*100/128]% [string1]
func = 6 ���� +[value] [string1] [string2]
func = 7 ���� [value]% [string1] [string2]
func = 8 ���� +[value]% [string1] [string2]
func = 9 ���� [value] [string1] [string2]
func = 10���� [value*100/128]% [string1] [string2]
func = 11���� �ظ�װ���;ö� 1 �� [100/value] ����
func = 12���� +[value] [string1]
func = 13���� +[value] [ĳһְҵ] ���ܵȼ�
func = 14���� +[value] [ĳһϵ] ϵ����
func = 15���� [��ĳһ�¼�����ʱ��] [chance]% ����ʩչ�ȼ� [���ܵȼ�] [������]
func = 16���� ����ȼ� [value] [������] ����
func = 17���� [value] [string1] "(Increases near" [time] ")"
func = 18���� [value]% [string1] "(Increases near" [time] ")"
func = 20���� [value * -1]% [string1]
func = 21���� [value * -1] [string1]
func = 22���� [value]% [string1] [montype]
func = 23���� [value]% [string1] [monster]
func = 24���� �ȼ� [���ܵȼ�] ([ʣ�������/�ܾ�����] ���� )
func = 27���� +[value] [������] (��[ĳһְҵ]ʹ��)
func = 28���� +[value] [������]


�ظ�

    9¥
    2011-09-20 23:50

    �ٱ� |

    zqtjingzi
    С����
    12

����˵�������ļ������ο���ĳǰ�������ӣ����˽�ʲô�ˣ�����Ǹ���¾�


�ظ�

    10¥
    2011-09-20 23:50

    �ٱ� |

    zqtjingzi
    С����
    12

��ϡ�
����д�����ָ����
ף��λ��Ϸ��졣

7¥�и�С����
������op = 4����һ��û���ڶ���op = 4Ӧ����op = 5��
Ӧ�ú����׿������ɣ�������������һ�µĺá�
*/

typedef struct
{
    unsigned int vID;

#if 1
    unsigned char vCombinedBits1;
    unsigned char vCombinedBits2;
#else
    unsigned char iPadding1_1 : 3;
    unsigned char vdirect : 1;

    unsigned char vitemspecific : 1;
    unsigned char vdamagerelated : 1;
    unsigned char vSigned : 1;
    unsigned char vSendmyspOther : 1;

    unsigned char iPading1 : 1;
    unsigned char iPading1_1 : 1;
    unsigned char vCSvSigned : 1;
    unsigned char vSaved : 1;

    unsigned char vfCallback : 1;
    unsigned char vfMin : 1;
    unsigned char vUpdateAnimRate : 1;
    unsigned char iPadding1_2 : 1;
#endif

    unsigned char iPadding1[2];

    unsigned char vSendmyspBits;
    unsigned char vSendmyspParammyspBits;
    unsigned char vCSvBits;
    unsigned char vCSvParam;

    unsigned int vDivide;
    int vMultiply;
    unsigned int vAdd;

    unsigned char vValShift;
    unsigned char vSavemyspBits;
    unsigned char v1mypoint09mysubSavemyspBits;
    unsigned char bUnKnown;

    int vSavemyspAdd;

    int v1mypoint09mysubSavemyspAdd;

    unsigned int vSavemyspParammyspBits;

    unsigned int iPadding10;
    unsigned int vMinAccr;

    unsigned char vEncode;
    unsigned char bUnKnown2;
    unsigned short vmaxstat;  //��������

    unsigned short vdescpriority;
    unsigned char vdescfunc;
    unsigned char vdescval;

    unsigned short vdescstrpos; //strings
    unsigned short vdescstrneg; //strings

    unsigned short vdescstr2;   //strings
    unsigned short vdgrp;

    unsigned char vdgrpfunc;
    unsigned char vdgrpval;
    unsigned short vdgrpstrpos; //strings

    unsigned short vdgrpstrneg; //strings
    unsigned short vdgrpstr2;   //strings

    unsigned short vitemevent1; //events
    unsigned short vitemevent2; //events

    unsigned short vitemeventfunc1;
    unsigned short vitemeventfunc2;

    unsigned int vkeepzero;

    unsigned char vop;
    unsigned char vopmyspparam;
    unsigned short vopmyspbase;   //��������

    unsigned short vopmyspstat1;  //��������
    unsigned short vopmyspstat2;  //��������

    unsigned short vopmyspstat3;  //��������
    unsigned short iPadding23;

    unsigned int iPadding24;
    unsigned int iPadding25;
    unsigned int iPadding26;
    unsigned int iPadding27;
    unsigned int iPadding28;
    unsigned int iPadding29;

    unsigned int iPadding30;
    unsigned int iPadding31;
    unsigned int iPadding32;
    unsigned int iPadding33;
    unsigned int iPadding34;
    unsigned int iPadding35;
    unsigned int iPadding36;
    unsigned int iPadding37;
    unsigned int iPadding38;
    unsigned int iPadding39;

    unsigned int iPadding40;
    unsigned int iPadding41;
    unsigned int iPadding42;
    unsigned int iPadding43;
    unsigned int iPadding44;
    unsigned int iPadding45;
    unsigned int iPadding46;
    unsigned int iPadding47;
    unsigned int iPadding48;
    unsigned int iPadding49;

    unsigned int iPadding50;
    unsigned int iPadding51;
    unsigned int iPadding52;
    unsigned int iPadding53;
    unsigned int iPadding54;
    unsigned int iPadding55;
    unsigned int iPadding56;
    unsigned int iPadding57;
    unsigned int iPadding58;
    unsigned int iPadding59;

    unsigned int iPadding60;
    unsigned int iPadding61;
    unsigned int iPadding62;
    unsigned int iPadding63;
    unsigned int iPadding64;
    unsigned int iPadding65;
    unsigned int iPadding66;
    unsigned int iPadding67;
    unsigned int iPadding68;
    unsigned int iPadding69;

    unsigned int iPadding70;
    unsigned int iPadding71;
    unsigned int iPadding72;
    unsigned int iPadding73;
    unsigned int iPadding74;
    unsigned int iPadding75;
    unsigned int iPadding76;
    unsigned int iPadding77;
    unsigned int iPadding78;
    unsigned int iPadding79;

    unsigned int vstuff;
} ST_LINE_INFO;

typedef struct
{
    char vStat[64];
} ST_ITEM_STATES;

static char *m_apcInternalProcess[] =
{
    "Stat",
    "*eol",
    NULL,
};

static unsigned int m_iItemStatesCount = 0;
static ST_ITEM_STATES *m_astItemStates = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astItemStates, ST_ITEM_STATES);

static int ItemStatCost_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Stat") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vID);
        }

        strncpy(m_astItemStates[m_iItemStatesCount].vStat, acOutput, sizeof(m_astItemStates[m_iItemStatesCount].vStat));
        String_Trim(m_astItemStates[m_iItemStatesCount].vStat);
        m_iItemStatesCount++;
        return 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int ItemStatCost_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Stat") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vID);
        }

        return 1;
    }

    return 0;
}

static int ItemStatCost_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "maxstat") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vmaxstat);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "descstrpos") )
    {
        pcResult = String_FindString(pstLineInfo->vdescstrpos, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "descstrneg") )
    {
        pcResult = String_FindString(pstLineInfo->vdescstrneg, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "descstr2") )
    {
        pcResult = String_FindString(pstLineInfo->vdescstr2, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "dgrpstrpos") )
    {
        pcResult = String_FindString(pstLineInfo->vdgrpstrpos, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "dgrpstrneg") )
    {
        pcResult = String_FindString(pstLineInfo->vdgrpstrneg, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "dgrpstr2") )
    {
        pcResult = String_FindString(pstLineInfo->vdgrpstr2, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "itemevent1") )
    {
        pcResult = Events_GetEventName(pstLineInfo->vitemevent1);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "itemevent2") )
    {
        pcResult = Events_GetEventName(pstLineInfo->vitemevent2);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "op stat1") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vopmyspstat1);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "op stat2") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vopmyspstat2);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "op stat3") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vopmyspstat3);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "op base") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vopmyspbase);
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }

    return result;
}

static int ItemStatCost_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "CSvSigned") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Saved") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "fCallback") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "fMin") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "UpdateAnimRate") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "direct") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "itemspecific") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "damagerelated") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Signed") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Send Other") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & 1) != 0);
        result = 1;
    }

    return result;
}

static char *ItemStatCost_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    sprintf(pcKey, "%u", pstLineInfo->vID);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

int process_itemstatcost(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ID, UINT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, CSvSigned, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Saved, CombinedBits2, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, fCallback, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, fMin, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, UpdateAnimRate, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, direct, CombinedBits1, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, itemspecific, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, damagerelated, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Signed, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, SendmyspOther, CombinedBits1, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendmyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendmyspParammyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CSvBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CSvParam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Multiply, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Add, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ValShift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspBits, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1mypoint09mysubSavemyspBits, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspAdd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1mypoint09mysubSavemyspAdd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SavemyspParammyspBits, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinAccr, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Encode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxstat, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descpriority, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descfunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descval, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstrpos, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstrneg, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, descstr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrp, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpfunc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpval, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstrpos, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstrneg, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dgrpstr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemevent1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemevent2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemeventfunc1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemeventfunc2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, keepzero, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspparam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspbase, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, opmyspstat3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stuff, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_iItemStatesCount = 0;

            //m_stCallback.pfnGetKey = ItemStatCost_GetKey;
            m_stCallback.pfnFieldProc = ItemStatCost_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            //m_stCallback.pfnGetKey = ItemStatCost_GetKey;
            m_stCallback.pfnConvertValue = ItemStatCost_ConvertValue;
            m_stCallback.pfnFieldProc = ItemStatCost_FieldProc;
            m_stCallback.pfnBitProc = ItemStatCost_BitProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

char *ItemStatCost_GetStateName(unsigned int id)
{
    if ( id >= m_iItemStatesCount )
    {
        return NULL;
    }

    return m_astItemStates[id].vStat;
}

