#include "global.h"

#define FILE_PREFIX "misc"
#define NAME_PREFIX "mi"

/*
Title 	Misc.txt File Guide
Description 	by Kingpin & Ric Faith
Sent by 	
OVERVIEW

Armor.txt, Misc.txt and Weapons.txt have many identical columns. That's because in fact these 3 text files are part of 1 bigger file : when the game reads these 3 tables, it merges them all, one after another, into one and unique table.These 3 text 
files contain all the base items of the game : normal / exceptional / elite
versions of items like armor, helm, gaunt, shield, weapon, gems, potion, key, scroll ...Incidently, that means you can add columns to any one of these 3 files. For instance if you add the columns , TransmogrifyTMogType,
TMogMin and TMogMax to
Armor.txt and use them for an Helm, then this Helm will be able to be Transmute into another item, something that doesn't look possible at first glance since the 4 columns are not originally in Armor.txt.Note : to add columns in a .txt, don't use D2Excel
, as this program can't do the job. Instead, use MS Excel or another spreadsheet that can import and export tab-delimited .txt files.

RELATED .TXT FilES


This file is using:

* AutoMagic.TxT
* Belt.txt
* Composit.txt
* ItemTypes.txt
* Missiles.txt
* Sound.txt



This file is used by :

* CharStats.txt
* CompCode.txt
* CubeMain.txt
* SetItems.txt
* UniqueItems.txt


COLUMN DESCRIPTIONS :

________________________________________________________________________

name: Reference only, its a comment field.
______________________________________________________________________________

*name: Reference only, its a comment field.
______________________________________________________________________________
szFlavorText: unknown if used
______________________________________________________________________________

compactsave: 1=use ompactsave 0=don't use compactsave. This is used to get a smaller filesize. This will not save
any stats to the item, this means it will not save any quantity, automagic, affixes, damage, armor, durability e.tc.
(This is used by items that don't need any stats stored like Healing potions, gems).

______________________________________________________________________________

version: 0=Classic D2, 100=Expansion (A item set to 100 here cannot
be generated in classic d2).

______________________________________________________________________________

level: base item level (aka a monster with a mlvl of 20 cannot drop a lvl30 armor for eg, used by the "armo#" preset TCs)

______________________________________________________________________________

levelreq: the minimum level you need to have to use that item

______________________________________________________________________________

rarity: 0 = Exclude this item from armor rack, 1 and higher sets the rarity for this item to be droped from an armor rack.(There need to be atleast one armor with rarity 1 othervise the game will crash when you use an armor rack).

______________________________________________________________________________

spawnable: 1=can be sold by NPCs, 0=can never be sold by NPCs (even if you make them sell it thru the vendor columns)

______________________________________________________________________________

speed: Possitive value = slower run, negative value = faster run.

______________________________________________________________________________

nodurability: 1=indestructible, 0=use durability

______________________________________________________________________________

gamble cost: only used by Amulets/Rings.

______________________________________________________________________________

Code : is not needed to be added to string table anymore. This is a 3 letter/number code that need to be unique and not used by other items.

______________________________________________________________________________

alternategfx: This is the code of the DCC to use for a Player Animation. [For instance, the Gothic Shield (code=gts) has kit in its alternategfx column. That means that if a Barbarian equip himself whith that shield, in his A1 (Attack 1) mode animation 
his SH (Shield) layer component will use the DCC BASHKITA11HS.DCC, and NOT the
file BASHGTSA11HS.DCC nor the file BASHBUCA11HS.DCC.

______________________________________________________________________________

name str: If namestr code is not added to a string table it will use that name in the field.If you want a string name with space you need to add it to your string table.

______________________________________________________________________________

component: This tells what layer it should use from composit.txt to show the item on the character. (composit.txt are 16
lines that range from 0 (HD) to 15 (S8) and 16 means "no player animation").

______________________________________________________________________________	

invwidth: width in inventory cells

______________________________________________________________________________	

invheight: height in inventory cells

______________________________________________________________________________

hasinv: 1 can be socketed,0 cannot be socketed (You need to set MaxSock 1/25/40 in itemtypes.txt to at least 1 to have sockets in the item)

________________________________________________________________________

gemsockets: maximum number of sockets

______________________________________________________________________________

gemapplytype: gem effecs 0=weapon, 1=armor/helm, 2=shield (If you add a higher value it wouldn't add the socket)

______________________________________________________________________________

fflippyfile: flip gfx (dropping gfx)

______________________________________________________________________________

invfile: inventory gfx

______________________________________________________________________________

uniqueinvfile: unique inventory gfx

______________________________________________________________________________

special:special: Not used, Comment field.

______________________________________________________________________________

Transmogrify: Whether or not the item can be right clicked and be changed into another item

______________________________________________________________________________

TMogType: The 3 character code which respresents the item that this item becomes when right clicked (see Transmogrify)

______________________________________________________________________________

TMogMin: Min quantity appearing of the item in Transmogrify

______________________________________________________________________________

TMogMax: Min quantity appearing of the item in Transmogrify

______________________________________________________________________________

useable: 0=you cannot rightclick, 1=you can rightclick on this item

______________________________________________________________________________

throwable: can this item be thrown 1=yes, 0=no

______________________________________________________________________________

type: first base type (code from itemtypes.txt)

______________________________________________________________________________

type2: second base type (code from itemtypes.txt)
______________________________________________________________________________

dropsound: tells what sound you use when the item is dropped. The name it uses is from Sound column in sounds.txt

______________________________________________________________________________

dropsfxframe: Number of frames the sound will use when dropped.

_____________________________________________________________________________

usesound: tells what sound you use when the item is used. The name it uses is from Sound column in sounds.txt.

______________________________________________________________________________

unique: 1 = always unique, 0 = not always unique (This is used by questitems to have the item as always unique)

______________________________________________________________________________


transparent: unknown function

______________________________________________________________________________


transtbl: unknown function (But are always using 5)
______________________________________________________________________________


lightradius: Not used.

______________________________________________________________________________

belt: numberic Id from belts.txt (defines number of potion slots)
______________________________________________________________________________


autobelt: Whether or not the item appears in your belt when picked up

______________________________________________________________________________


stackable: can this item be stacked 1=yes, 0=no

______________________________________________________________________________
minstack: min ammount of quantity

______________________________________________________________________________


maxstack: max ammount quantity

______________________________________________________________________________


spawnstack: when randomly spawned, how many in a stack

______________________________________________________________________________


quest: sets if this item is a ques titem

______________________________________________________________________________


questdiffcheck: sets in what difficulty this item is a quest item.

______________________________________________________________________________


missiletype: missile to shoot if you throw this item (id from missiles.txt)

______________________________________________________________________________


spellicon: Which spellicon should be used, when you use the item (eg. the throwing-icon for jav's )

______________________________________________________________________________


pSpell: All temporary potions can use pSpell = 6. This is a parameter for the function that handles the temporary items.

______________________________________________________________________________


state: this parameter is for Overlay effect. this is only visualeffect. (state and cstate1 needs to be the same stat id from states.txt)

______________________________________________________________________________


cstate1: this parameter is used to get a stat from states.txt. It's really important that you remember what stat you have choose when you are going to use stat1. Othervise you will get the known bug, or what it actually is a missunderstanding of how 
temporary items works.

______________________________________________________________________________


cstate2: this is a second parameter. See cstate1 for more information. But you can add two different states to an item.

______________________________________________________________________________


len: This parameter is used to set the time for the temporal items. This cannot be 0.

______________________________________________________________________________

stat1: This tells what stat to add to the player. This stat is entered in cstate1 stat id.

______________________________________________________________________________


calc1: This is what value you want to add.

______________________________________________________________________________

stat2: This tells what stat to add to the player.
This stat is entered in cstate2 stat id.

______________________________________________________________________________


calc1: This is what value you want to add.

_____________________________________________________________________________



calc2: This is what value you want to add.

_____________________________________________________________________________



stat3: This tells what stat to add to the player.

]_____________________________________________________________________________


calc3: This is what value you want to add.

______________________________________________________________________________


spelldesc:
0 = don't use any description or calculation.
1 = use spelldescrtr only
2 = use spelldescrtr and spelldesccalc.

]_____________________________________________________________________________

spelldescstr: This gives an description to your temporal item what it does.

]_____________________________________________________________________________



spelldesccalc: This shows the total effect of all your items for this stats based on stat1-3.

______________________________________________________________________________


durwarning: the dur warning icon to display when the item is about to break

______________________________________________________________________________

_
qntwarning: quantity warning icon to display if you wasted most of the stack

______________________________________________________________________________


gemoffset: unknown

_______________________________________________________________________________

nameable: 1=can be personalized, 0=cannot be

_______________________________________________________________________________

BetterGem: (Gems only) What gem code is the next step up when it's upgraded by a shrine or cube (non=none,else follow "code")

______________________________________________________________________________

bitfield1: set to 1 for leather items, to 3 for metal ones.
______________________________________________________________________________

Vendor Columns: (replace Vendor with the vendor name aka CharsiMin etc)

______________________________________________________________________________

VendorsMin: minimum amount of items of this type the vendor can sell

______________________________________________________________________________

VendorsMax: maximum amount of items of this type the vendor can sell

______________________________________________________________________________

VendorsMagicMin: minimum amount of magic items of this type the vendor can sell

______________________________________________________________________________

VendorsMagicMax: maximum amount of magic items of this type the vendor can sell

______________________________________________________________________________


vendorsMagicLvl: Max magic level an item can get from the affixes.

______________________________________________________________________________

Source Art: unknown

______________________________________________________________________________

Game Art: unknown

______________________________________________________________________________

Transform and invTrans : Index telling which colormap .dat to use for this item
(like 1=dataglobalitemspalettegrey.dat, 8=dataglobalitemspaletteinvgreybrown.dat).
This is telling what are the pixels that will change colors
(only transform brown pixels to dark green ? transform all pxiels to dark green ?). For details, check http://d2mods.xfernet.com/colormaps.php
Transform is for the Animation of the player, while InvTrans is for the
Inventory gfx

_______________________________________________________________________________[u[/u]

SkipName: for items like the viper amulet (which dosent say viperamulet two times) (skips the base name)

______________________________________________________________________________	

NightmareUpgrade: item code of the item the vendor will sell instead

of this item on NM (xxx=no change)
______________________________________________________________________________

HellUpgrade: item code of the item the vendor will sell instead of this item on HELL (xxx=no change)

______________________________________________________________________________


mindam: smite damage for shields/kick damage for boots

______________________________________________________________________________


maxdam: smite damage for shields/kick damage for boots (maximum)

______________________________________________________________________________

PermStoreItem: Boolean will item always be sold by sellers? Item cannot be depletedmultibuy - 0 = Multibuy is not used, 1 = Multibuy is used, when you right click and buying a potion. It will fill up
your belt.
.

______________________________________________________________________________


nameable: 1=can be personalized, 0=cannot be personalized

______________________________________________________________________________

*eol: End of Line

(Formatting by Lord_Drekas)

*/

/*
name:��Ʒ�ο���,ע����.
*name:ͬ��.
szFlavorText:δ֪����
compactsave:1=ѹ���浵��0=��ѹ���浵��˵����ͨ������ʹ�浵����С��������������Ʒ�йصġ�����������ħ��ǰ��׺�������;öȡ�����ֵ��������(��Ҫ���ڡ�ҩˮ��һ�����Ʒ)��
version:��Ʒ�İ汾��0=ԭ��, 100=����Ƭ(���һ����Ʒ�Ĵ�����ֵ���趨Ϊ100�Ļ�����ô�����޷���ԭ���г���)��
level:��Ʒ����.
levelreq:��ɫʹ�ø���Ʒ����Ҫ�ļ���.
rarity:0=��װ�������޳�������Ʒ���κ���Ϣ;1���߸�������ֿ��Ե���������Ʒ�ĵ����ʡ�˵��:������Ӧ��ӵ��1�����ϵĴ�����ֵ��Ϊ���װ����������Ϸ�ͻ������޷���������.
spawnable:�Ƿ��ܹ���NPC����.1=�ܹ���NPC����,0=�޷�����.
speed:�����ٶȵĲ���;Possitive value(��ֵ)=�ٶȼ���,negative value(��ֵ)=�����ٶ�.
nodurability:1=�޷��ƻ�;0=ʹ���;ö�(durability)ֵ;
cost:�۸�.
gamble cost:ֻ������Amulete/Rings.
code:�ڲ�����;Ϊ3���ֽ�(���ֻ�����ĸ),unique��Ʒ����,�����Լ�����Ʒʱ�ر�.
alternategfx:DCC����.˵��:����ɫʹ�ô���Ʒʱ�����õĶ���.��������ʱʹ��.
namestr:���������Ʒ���Ƶ���ӦTBL�ļ���û�ж������Ʒ������,�Ͳ������������.����Ҫ,����ҽ����Ƽ���TBL�ļ��У�
component:��ɫʹ�ô���Ʒʱ��������һ��(Layer);ͬcomposit.txt�ļ���.˵��:composit.txt��ֵ��0(HD)��15(S8)��16�У�16��ʾ�޶���.
invwidth:��Ʒ����Ʒ���еĿ��.
invheight:��Ʒ����Ʒ���еĸ߶�.
hasinv:��Ʒ�ܷ񱻴��.1=�ܴ��,0=���ܴ��.˵��:itemtypes.txt�ļ��е�MaxSock 1/25/40������ȷ���׵�����,�޸ķ�������ؽ̳̣�Сվ���н���.
gemsockets:��Ʒ�������������.
gemapplytype:��ʯ����Ʒ��������Ӱ��;0=����,1=װ��/ͷ��,2=����.(����ֵ��Ч).
flippyfile:����ʱ���õ�Ӱ��(gfx).
invfile:��Ʒ���в��õ�Ӱ��(gfx).
uniqueinvfile:unique��Ʒ���õ�Ӱ��(gfx).
special:δʹ��,ע����.
Transmogrify:��Ʒ�ܷ��Ҽ�����Ƿ��Ϊ��һ��Ʒ(item),��id roll.
TMogType:��Ʒ���һ�ʱ��ɵ���Ʒcode(��Transmogrify).
TMogMin:������Transmogrify����Ʒ����С����.
TMogMax:������Transmogrify����Ʒ���������.
useable:�趨�һ�����.0=�����Ա��Ҽ����,1=���ԣ�
throwable:�ܷ�Ͷ��;1=����,0=������.
type:��������(��itemtypes.tx.t����).
type2:��Ҫ����(��itemtypes.tx.t����).
dropsound:��Ʒ����ʱ����;ͬsounds.txt����.
dropsfxframe:��Ʒ����ʱ���������ö�����.
usesound:��Ʒʹ��ʱ������;ͬsounds.txt����.
unique:1=������unique��Ʒ,0=��������unique��Ʒ.(������Ʒһ������������Ʒ,�緽��).
transparent:δ֪������
transtbl:δ֪������һ��ʹ��5��
lightradius:δʹ��.
belt:ͬbelts.txt�е�����ID(����ҩˮ�ķ�������).
autobelt:��Ʒ������ʱ�Ƿ������������.
stackable:�Ƿ�Ϊһ������(����˵"����" ;1=��,0=����.
minstack:��Ϊ�������С����.
maxstack:��Ϊ������������.
spawnstack:һ���۳�ʱ������.
quest:������Ʒʱ����.
questdiffcheck:����������Ʒ�������ĸ��Ѷ�.(������ֻ��������Ʒ)
missiletype:�����Ͷ����Ʒ��,��ʩ�ų���Missile����(ͬmissiles.txt����).
spellicon:��ɫʹ�ô���Ʒʱ���õ�ͼ��(spellicon)?,��jav��Ͷ��ͼ��.
pSpell:������ʱ��(temporary)ҩ��ʹ��pSpell=6.������ʱ����Ʒ�Ĳ��������ڴ˲����ĸ�����Ϣ�����Բ鿴����Դ����Ŀ�еġ�Psepll����ȫ��������.
state:�������ò���(��ⶾ���ڻ�),ֻ���Ӿ��ϵ�Ч��.(��cstate1����ͬ��stat id,��states.txt����).
cstate1:״̬����,��states.txt�������Ӻ��߻�ȡһ��״̬.ʹ��stat1ʱ����ؼ�ס���Ѿ�ѡ���״̬�Ա���һ�£����򽫲���bug.
cstate2:��Ҫ�����������Ϣ��cstate1.����Զ�һ����Ʒ��������״̬.
len:��ʱ����Ʒ��������ʱ�����������Ϊ0.
stat1:���״̬1,��cstates1��״̬idΪ���.������ֿ�.
calc1:�趨״ֵ̬.
stat2:���״̬2,��cstates2��״̬idΪ���.
calc2:�趨״ֵ̬.
stat3:���״̬3,���ò���.
calc3:�趨״ֵ̬,���ò���.
spelldesc:0=��ʹ���κ����������.
1:ֻʹ��spelldescstr.
2:ʹ��spelldescstr��spelldesccalc��
spelldescstr:����ʱ����Ʒ�������õ�����.
spelldesccalc:״̬(stat1-3)��Ч������ֵ.
durwarning:���;öȽ��͵�����ʱ������Ʒ����ʾ(��Ļ�ҷ�������ʾ).
qntwarning:�����Ϊ������Ʒ,�������½�������ʱ��������������ʾ.
gemoffset:δ֪����.
BetterGem:��ʯ(gem)ͨ����ʯ���򷽿�cube������Ĵ���(ֻ�Ա�ʯ��Ч)��non=û��,����Ϊ"code"ֵ.
bitfield1:װ�����ڲ���������.1Ϊ������Ʒ;3Ϊ��������Ʒ.��AkaraMin�ȵ�.
Vendor Columns:NPC���ֵĴ���vendor����ÿ��NPC���������в���.��
VendorsMin:NPC�ܳ��۵ĸ���Ʒ��С����.
VendorsMax:NPC�ܳ��۵ĸ���Ʒ�������.
VendorsMagicMin:NPC���������Ʒʱ�����ܰ�����ħ�����Ե�������.
VendorsMagicMax:NPC���������Ʒʱ�����ܰ�����ħ�����Ե������.
VendorsMagicLvl:ħ������Ʒ�ڳ���ʱ���ܰ���������ħ��ǰ��׺����.ͬMagicPrefix.txt,MagicSuffix,AutoMagic�����ļ�����.
Source Art:δ֪����.
Game Art:δ֪����.
Transform and invTrans:����,���߳���ʹ����һ�����嶯��.
SkipName:�Ƿ��������������,����˵:viper amulet.
NightmareUpgrade:��"����"�Ѷ���,����Ʒ�ĳ��۴���(xxx=�ޱ仯).
HellUpgrade:��"����"�Ѷ���,����Ʒ�ĳ��۴���(xxx=�ޱ仯).
mindam:��Ь�༰�������С�˺�ֵ.
maxdam:��Ь�༰���������˺�ֵ.
PermStoreItem:NPC���۵ĸ���Ʒ����ʱ,����һ��Ϊ1.
multibuy:һ�ι���ʱ�ܷ���һ����.0=������,1=����.(���統����ҩ��ʱ���Ҽ������ʹ������ȫ��).
nameable:�ܷ񱻸��˻�(��ACT5�е�Q3)1=����,0=������.
*eol:�н�����־.
*/

/*
�ļ���������
misc�����������ָ��װ�����һ�е��ߡ�
���ļ��е�ÿһ�б�ʾһ�����ߡ�


�ظ�

    2¥
    2011-09-07 20:27

    �ٱ� |

    zqtjingzi
    С����
    12

���ڴ��ļ��еĲ������Ѿ���Armor.txthttp��//tieba��baidu��com/f?kz=1201381062��Weapons.txthttp://tieba.baidu.com/p/1201415437�г��ֲ����͹�������������ֻ������������еĽ��͡�

��Щ�еĺ������£�


�ظ�

    3¥
    2011-09-07 20:27

    �ٱ� |

    zqtjingzi
    С����
    12

���ڴ��ļ��еĲ������Ѿ���
Armor.txt
http��//tieba.baidu.com/f?kz=1201381062
��Weapons.txt
http://tieba.baidu.com/p/1201415437
�г��ֲ����͹�������������ֻ������������еĽ��͡�

��Щ�еĺ������£�



�ظ�

    4¥
    2011-09-07 20:28

    �ٱ� |

    zqtjingzi
    С����
    12

*name�����ֵ�ע��

szFlavorText����֪��ʲô��˼�Ĳ��������������ڴ��ж�û��ֵ��

special����֪��ʲô��˼�Ĳ��������������ڴ��ж�û��ֵ��

Transmogrify����Ʒ�ܷ��Ҽ��������Ϊ��һ��Ʒ���ڵ��������ƺ�û���õ�������ս���е����Ӻ����ʹ������һ�С�

TMogType������Ʒ���Ҽ����ʱ��ɵ���Ʒ���롣�����ɱ�򲻱����xxx��

TMogMin���������Ʒ����С������

TMogMax���������Ʒ�����������

lightradius����֪��ʲô��˼�Ĳ�����������Ϸ��Ӧ��û�б�ʹ�á�

autobelt����Ʒ������ʱ�Ƿ��Զ������������С�0�����1�����ǡ�

spawnstack����Ʒ����ʱ�������Ŀ��һ����maxStackһ�¡�

spellicon����ɫʹ�ô���Ʒʱ�ڼ����������õ�ͼ�꣬һ�㶼��-1����ʾ��Ĭ��ֵ��



�ظ�

    5¥
    2011-09-07 20:29

    �ٱ� |

    zqtjingzi
    С����
    12

pSpell��ʹ�ô˵���ʱ����ʲô����Ч����
���ܵ�ֵ��Ч�����¡�
1 = ��������/����֮�顣
2 = �سǾ���/�س�֮�飻
3 = �ָ���ҩˮ��
4 = δʹ�ã�Ч��δ֪��
5 = �ٷֱȻָ���ҩˮ����100%ȫ�ָ�ҩˮ����
6 = Ͷ��ҩˮ��
7 = �����Ͽ˷��飻
8 = ���Ա�Elixirҩˮʹ�ã���Ҫ���ܾ�����������ֵ��
9 = ����ֵҩˮ���߲�ҩ��


�ظ�

    6¥
    2011-09-07 20:29

    �ٱ� |

    zqtjingzi
    С����
    12

state��ʹ�ô˵��߶�����״̬��Ӱ�죬��states.txt������

cstate1-2������stateЧ������������states.txt�������������о�Ϊ�գ���ʼ�մ���stateЧ�����������ﵱǰ״̬���������������һ������ż���state״̬����ֻ�е��ж���Żἤ���ⶾЧ����

len���˵��ߵĳ�������ʱ�䣬������Ҫ�������������0��

stat1-3��ʹ�ô˵��ߺ��Ч����

calc1-3��Ч��������

SpellDesc���Ƿ��ж����Ч����0����û�У�1������SpellDescStr��������Ч����2������SpellDescStr��SpelldescCalc��������Ч����

spelldescstr������Ч����Ч��������

spelldesccalc������Ч����Ч��������

BetterGem����һ����ʯ��ָ�룬����覴õ���ʯ���е�ֵΪ������ʯ�Ĵ��롣�Ǳ�ʯ�������non��

*/

typedef struct
{//total 424 bytes
    unsigned char vflippyfile[32];  //��Ʒ�����ʹ�õ�ͼ��ָ�롣
    unsigned char vinvfile[32];     //��Ʒ����Ʒ������ʹ�õ�ͼ��ָ�롣
    unsigned char vuniqueinvfile[32];   //��װ���ײĶ�Ӧ��Ψһ��Ʒ��������ʹ�õ�ͼ��ָ�롣

    unsigned char acPadding[32];

    unsigned char vcode[4]; //32 ��Ʒ���롣

    unsigned char acPad2[12];

    unsigned char valternategfx[4]; //����ɫʹ�ô���Ʒʱ�����õĶ�����

    unsigned int vpSpell;  //ʹ�ô˵���ʱ����ʲô����Ч����
    /*
    ���ܵ�ֵ��Ч�����¡�
    1 = ��������/����֮�顣
    2 = �سǾ���/�س�֮�飻
    3 = �ָ���ҩˮ��
    4 = δʹ�ã�Ч��δ֪��
    5 = �ٷֱȻָ���ҩˮ����100%ȫ�ָ�ҩˮ����
    6 = Ͷ��ҩˮ��
    7 = �����Ͽ˷��飻
    8 = ���Ա�Elixirҩˮʹ�ã���Ҫ���ܾ�����������ֵ��
    9 = ����ֵҩˮ���߲�ҩ��
    */

    unsigned short vstate;  //ʹ�ô˵��߶�����״̬��Ӱ�죬��states.txt������
    unsigned short vcstate1;//����stateЧ������������states.txt�������������о�Ϊ�գ���ʼ�մ���stateЧ�����������ﵱǰ״̬���������������һ������ż���state״̬����ֻ�е��ж���Żἤ���ⶾЧ����
    unsigned short vcstate2;//����stateЧ������������states.txt�������������о�Ϊ�գ���ʼ�մ���stateЧ�����������ﵱǰ״̬���������������һ������ż���state״̬����ֻ�е��ж���Żἤ���ⶾЧ����
    unsigned short vstat1;  //ʹ�ô˵��ߺ��Ч����
    unsigned short vstat2;  //ʹ�ô˵��ߺ��Ч����
    unsigned short vstat3;  //ʹ�ô˵��ߺ��Ч����

    unsigned int vcalc1;    //41 ItemsCode
    unsigned int vcalc2;
    unsigned int vcalc3;

    unsigned int vlen;  //44 ItemsCode

    unsigned short vspelldesc;   //�Ƿ��ж����Ч����0����û�У�1������SpellDescStr��������Ч����2������SpellDescStr��
    unsigned short vspelldescstr;   //strings

    unsigned int vspelldesccalc;    //46 ItemsCode

    unsigned char vBetterGem[4];    //��һ����ʯ��ָ�룬����覴õ���ʯ���е�ֵΪ������ʯ�Ĵ��롣�Ǳ�ʯ�������non��

    unsigned char acPad6[8];

    unsigned char vTMogType[4]; //����Ʒ���Ҽ����ʱ��ɵ���Ʒ���롣�����ɱ�򲻱����xxx��

    unsigned char acPad7[8];

    unsigned int vgamblemyspcost;   //53 ������Ӧ���Ǳ���������Ĳ�ʱ���ļ۸񣬵�ʵ����û��������ܣ����Դ���Ӧ��û�����á����Կ϶����Ǵ��в�Ӱ��Ĳ�ʱ�ļ۸�

    unsigned char vspeed;   //�˷��߶��ٶȵĽ��ͳ̶ȡ�0�������ͣ�����Խ���ٶ�Խ����
    unsigned char acPad9[3];

    unsigned char vbitfield1;   //װ�����ڲ��������͡�˵����1Ϊ������Ʒ��3Ϊ������Ʒ��
    unsigned char acPad10[3];

    unsigned int vcost;   //��Ʒ����ʱ�Ļ����۸�

    unsigned int vminstack; //�ɵ�����Ʒ����ʱ����С������
    unsigned int vmaxstack; //�ɵ�����Ʒһ���ĵ����������
    unsigned int vspawnstack;   //��Ʒ����ʱ�������Ŀ��һ����maxStackһ�¡�

    unsigned short vgemoffset;  //��֪��ʲô��˼�Ĳ�����������0��
    unsigned char acPad12[2];

    unsigned short vnamestr;    //������������tbl�еļ�����ʵ������Code���Ǳ���һ�£������ΪʲôҪ�������С�
    unsigned char vversion; //��Ʒ�����ð汾�����Ắ��˵����0����1.07֮ǰ�İ汾��1����1.07֮��ķ�����Ƭ�汾��100��������Ƭ����Ȼ����û����ôЩ�汾�ɹ�ʵ�飬�����������Ắ�Ļ���
    unsigned char acPad13[1];

    unsigned short vautomyspprefix;//62 �Զ��������ԡ��編��ļ�Ѫ������ʥ��ר�öܵļ��˺���׼ȷ�ʡ���AutoMagic.txt������
    unsigned char vmissiletype; //Ͷ����Ʒר�á�Ͷ��������Ʒ�����ͣ�ͬmissiles.txt�ļ�������
    unsigned char bPad;

    unsigned char vrarity;  //ϡ�жȡ���ͬһTC�г��ֵĸ��ʣ�ֵԽ�����ĸ���Խ����ο���Ʒ����ԭ��
    unsigned char vlevel;   //��Ʒ�ȼ���������ο��Ắ����Ʒ����ԭ��
    unsigned char vmindam;  //��С�˺�ֵ��������ֻ�ж��ƣ��ܻ�����Ь�ӣ��߻���ʹ�ô����ԡ�
    unsigned char vmaxdam;  //����˺�ֵ��������ֻ�ж��ƣ��ܻ�����Ь�ӣ��߻���ʹ�ô����ԡ�

    unsigned char acPad14[15];
    unsigned char vinvwidth;    //��Ʒ����Ʒ���еĿ�ȡ�

    unsigned char vinvheight;   //68 ��Ʒ����Ʒ���еĸ߶ȡ�
    unsigned char acPad15[2];
    unsigned char vnodurability;    //û���;öȣ��������޷��ƻ�����û�֮�У�����������ʱû�С�

    unsigned char bPad2;
    unsigned char vcomponent;   //��ɫʹ�ô���Ʒʱ��������һ�㣨Layer����ͬ�ļ������������ҳ����ģ���Ҳû��⡣
    unsigned char acPad16[7];
    unsigned char vuseable; //�ܷ����Ҽ�ʹ�á�0��ʾ�����ԣ�1��ʾ���ԡ�
    unsigned short vtype;    //�������͡�ͬitemtypes.txt������

    unsigned short vtype2;   //��Ҫ���ͣ�ͬitemtypes.txt������
    unsigned char acPad17[2];

    unsigned short vdropsound;  //��Ʒ����ʱ��������ͬsounds.txt������
    unsigned short vusesound;   //��Ʒʹ��ʱ��������ͬsounds.txt������

    unsigned char vdropsfxframe;    //��Ʒ����ʱ������ռ��������
    unsigned char vunique;  //����Ʒ�Ƿ�ֻ����Ψһ��������Ʒ��0��ʾ���ǣ�1�����ǡ��缪�ñ�����Ϊ1�����ڷ�����Ŀǰ��û����������Ʒ��
    unsigned char vquest;   //������Ʒר�ã���������ı�š�
    unsigned char vquestdiffcheck;  //

    unsigned char vtransparent; //��֪��ʲô��˼�Ĳ�����������0��
    unsigned char vtranstbl;    //��֪��ʲô��˼�Ĳ�����������5��
    unsigned char bPad4;
    unsigned char vlightradius; //��֪��ʲô��˼�Ĳ�����

    unsigned char vbelt;    //����ר�ã���ʾ��belts.txt�е�λ�á�
    unsigned char vautobelt;    //��Ʒ������ʱ�Ƿ��Զ������������С�0�����1�����ǡ�
    unsigned char vstackable;   //ͬ����Ʒ�ܷ���ӡ�0��ʾ�����ԣ�1��ʾ���ԡ����ʸ����Ϊ1��
    unsigned char vspawnable;   //�Ƿ������Ϸ�����ɡ�1������ԣ�0�������ԡ�����������ж���1��

    char vspellicon;    //��ɫʹ�ô���Ʒʱ�ڼ����������õ�ͼ�꣬һ�㶼��-1����ʾ��Ĭ��ֵ��
    unsigned char vdurwarning;  //���;öȽ��͵�����ʱ������Ʒ����ʾ��������Ļ�ҷ���ͼ����ʾ����
    unsigned char vqntwarning;  //�ɵ�����Ʒר�ã����������½�������ʱ��������������ʾ��
    unsigned char vhasinv;  //��Ʒ�Ƿ��ܹ�����ף�1�ܹ���ף�0���ܴ�ס�

    unsigned char vgemsockets;  //��Ʒ������������������ܳ�������Ʒ��������������������������Ϊ׼��
    unsigned char vTransmogrify;    //��Ʒ�ܷ��Ҽ��������Ϊ��һ��Ʒ���ڵ��������ƺ�û���õ�������ս���е����Ӻ����ʹ������һ�С�
    unsigned char vTMogMin; //�������Ʒ����С������
    unsigned char vTMogMax; //�������Ʒ�����������

    unsigned char acPad18[2];
    unsigned char vgemapplytype;    //����Ʒ����Ƕ�ϱ�ʯ����Ʒ��ʹ�ñ�ʯ������Ч����0=������1=װ��/ͷ����2=���ߡ�
    unsigned char vlevelreq;    //װ���ĵȼ�����

    unsigned char bPad5;
    unsigned char vTransform;   //����������
    unsigned char vInvTrans;    //�����������������о�˵ҪЭͬʹ�á�
    unsigned char vcompactsave; //����Ʒ�Ƿ�ѹ���洢��0����ѹ����1����ѹ��������ֻ��**��Կ��������û�б������ԵĽ�������Ϊ1���Խ�ʡ�洢�ռ䡣

    unsigned char vSkipName;    //�Ƿ���ʾ�ײĵ����֡��缪�ñ���
    unsigned char vNameable;    //�Ƿ��ܹ��������������ܷ񱻸��˻���0��ʾ���ܣ�1��ʾ�ܡ�
    unsigned char vAkaraMin;    //������***��NPC���������Ʒʱ����С������
    unsigned char vGheedMin;

    unsigned char vCharsiMin;
    unsigned char vFaraMin;
    unsigned char vLysanderMin;
    unsigned char vDrognanMin;

    unsigned char vHraltiMin;
    unsigned char vAlkorMin;
    unsigned char vOrmusMin;
    unsigned char vElzixMin;

    unsigned char vAshearaMin;
    unsigned char vCainMin;
    unsigned char vHalbuMin;
    unsigned char vJamellaMin;

    unsigned char vMalahMin;
    unsigned char vLarzukMin;
    unsigned char vDrehyaMin;
    unsigned char vAkaraMax;    //������***��NPC���������Ʒʱ�����������

    unsigned char vGheedMax;
    unsigned char vCharsiMax;
    unsigned char vFaraMax;
    unsigned char vLysanderMax;

    unsigned char vDrognanMax;
    unsigned char vHraltiMax;
    unsigned char vAlkorMax;
    unsigned char vOrmusMax;

    unsigned char vElzixMax;
    unsigned char vAshearaMax;
    unsigned char vCainMax;
    unsigned char vHalbuMax;

    unsigned char vJamellaMax;
    unsigned char vMalahMax;
    unsigned char vLarzukMax;
    unsigned char vDrehyaMax;

    unsigned char vAkaraMagicMin;   //NPC���������Ʒʱ�����ܰ�����ħ�����Ե���������Ϊ0��NPC�Ż����ħ����Ʒ��
    unsigned char vGheedMagicMin;
    unsigned char vCharsiMagicMin;
    unsigned char vFaraMagicMin;

    unsigned char vLysanderMagicMin;
    unsigned char vDrognanMagicMin;
    unsigned char vHraltiMagicMin;
    unsigned char vAlkorMagicMin;

    unsigned char vOrmusMagicMin;
    unsigned char vElzixMagicMin;
    unsigned char vAshearaMagicMin;
    unsigned char vCainMagicMin;

    unsigned char vHalbuMagicMin;
    unsigned char vJamellaMagicMin;
    unsigned char vMalahMagicMin;
    unsigned char vLarzukMagicMin;

    unsigned char vDrehyaMagicMin;
    unsigned char vAkaraMagicMax;   //NPC���������Ʒʱ�����ܰ�����ħ�����Ե������������1��NPC�Ż������2�����Ե�ħ����Ʒ��
    unsigned char vGheedMagicMax;
    unsigned char vCharsiMagicMax;

    unsigned char vFaraMagicMax;
    unsigned char vLysanderMagicMax;
    unsigned char vDrognanMagicMax;
    unsigned char vHraltiMagicMax;

    unsigned char vAlkorMagicMax;
    unsigned char vOrmusMagicMax;
    unsigned char vElzixMagicMax;
    unsigned char vAshearaMagicMax;

    unsigned char vCainMagicMax;
    unsigned char vHalbuMagicMax;
    unsigned char vJamellaMagicMax;
    unsigned char vMalahMagicMax;

    unsigned char vLarzukMagicMax;
    unsigned char vDrehyaMagicMax;
    unsigned char vAkaraMagicLvl;   //ħ����Ʒ�ڳ���ʱ���ܰ���������ħ��ǰ��׺����˵����ͬMagicPrefix.txt��MagicSuffix��AutoMagic�����ļ�������
    unsigned char vGheedMagicLvl;

    unsigned char vCharsiMagicLvl;
    unsigned char vFaraMagicLvl;
    unsigned char vLysanderMagicLvl;
    unsigned char vDrognanMagicLvl;

    unsigned char vHraltiMagicLvl;
    unsigned char vAlkorMagicLvl;
    unsigned char vOrmusMagicLvl;
    unsigned char vElzixMagicLvl;

    unsigned char vAshearaMagicLvl;
    unsigned char vCainMagicLvl;
    unsigned char vHalbuMagicLvl;
    unsigned char vJamellaMagicLvl;

    unsigned char vMalahMagicLvl;
    unsigned char vLarzukMagicLvl;
    unsigned char vDrehyaMagicLvl;
    unsigned char bPad6;

    unsigned char vNightmareUpgrade[4]; //�ڡ����Ρ��Ѷ��£�����������Ʒ��NPC����ʲô��Ʒ��xxx��ʾ���������������΢����ҩ��hp1�ڴ��е�ֵΪhp4����ʾ����ͨ�Ѷ�����΢����ҩ����NPC�ڶ����Ѷȸ���ǿ��ҩ���ˡ�
    unsigned char vHellUpgrade[4];  //�ڡ��������Ѷ��£�����������Ʒ��NPC����ʲô��Ʒ��xxx��ʾ���������������΢����ҩ��hp1�ڴ��е�ֵΪhp5����ʾ����ͨ�Ѷ�����΢����ҩ����NPC�ڶ����Ѷȸ�����������ҩ���ˡ�

    unsigned char vPermStoreItem;   //�Ƿ�����NPC���г��ۡ�
    unsigned char vmultibuy;    //
    unsigned char acPad20[2];
} ST_LINE_INFO;

typedef struct
{
    unsigned char vcode[5];
} ST_MISC;

static char *m_apcInternalProcess[] =
{
    "name",
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] = 
{
    "*name",
    "throwable",
    "szFlavorText",
    "Source Art",
    "Game Art",
    "special",
    NULL,
};

static unsigned int m_iMiscCount = 0;
static ST_MISC *m_astMisc = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astMisc, ST_MISC);

char *Misc_GetItemUniqueCode(unsigned int id)
{
    unsigned int iWeaponCnt, iArmorCnt, iMiscCnt;

    iWeaponCnt = Weapons_GetWeaponCount();
    iArmorCnt = Armor_GetArmorCount();
    iMiscCnt = m_iMiscCount;

    //weapon
    if ( id < iWeaponCnt )
    {
        return Weapons_GetWeaponCode(id);
    }

    id -= iWeaponCnt;
    //armor
    if ( id < iArmorCnt )
    {
        return Armor_GetArmorCode(id);
    }

    id -= iArmorCnt;
    //misc
    if ( id < iMiscCnt )
    {
        return m_astMisc[id].vcode;
    }

    return NULL;
}

static int Misc_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "name") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

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

static int Misc_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "code") )
    {
        strncpy(m_astMisc[m_iMiscCount].vcode, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        String_Trim(m_astMisc[m_iMiscCount].vcode);
        m_iMiscCount++;
    }

    return result;
}

static int Misc_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "type") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vtype);
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
    else if ( !strcmp(acKey, "type2") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vtype2);
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
    else if ( !strcmp(acKey, "dropsound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vdropsound);
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
    else if ( !strcmp(acKey, "usesound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vusesound);
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
    else if ( !strcmp(acKey, "state") )
    {
        pcResult = States_GetStateName(pstLineInfo->vstate);
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
    else if ( !strcmp(acKey, "cstate1") )
    {
        pcResult = States_GetStateName(pstLineInfo->vcstate1);
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
    else if ( !strcmp(acKey, "cstate2") )
    {
        pcResult = States_GetStateName(pstLineInfo->vcstate2);
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
    else if ( !strcmp(acKey, "stat1") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vstat1);
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
    else if ( !strcmp(acKey, "stat2") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vstat2);
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
    else if ( !strcmp(acKey, "stat3") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vstat3);
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
    else if ( !strcmp(acKey, "namestr") )
    {
        pcResult = String_FindString(pstLineInfo->vnamestr, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            strcpy(acOutput, pstLineInfo->vcode);
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "spelldescstr") )
    {
        pcResult = String_FindString(pstLineInfo->vspelldescstr, "dummy");
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
    else if ( !strcmp(acKey, "rarity") )
    {
        if ( (999 % 256) == pstLineInfo->vrarity )
        {
            strcpy(acOutput, "999");
            result = 1;
        }
    }
    else if ( !strcmp(acKey, "calc1") )
    {
        pcResult = ItemsCode_GetExpression(pstLineInfo->vcalc1);
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
    else if ( !strcmp(acKey, "calc2") )
    {
        pcResult = ItemsCode_GetExpression(pstLineInfo->vcalc2);
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
    else if ( !strcmp(acKey, "calc3") )
    {
        pcResult = ItemsCode_GetExpression(pstLineInfo->vcalc3);
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
    else if ( !strcmp(acKey, "len") )
    {
        pcResult = ItemsCode_GetExpression(pstLineInfo->vlen);
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
    else if ( !strcmp(acKey, "spelldesccalc") )
    {
        pcResult = ItemsCode_GetExpression(pstLineInfo->vspelldesccalc);
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

static void Misc_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniqueinvfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, alternategfx, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSpell, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, state, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cstate1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cstate2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldesc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldescstr, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BetterGem, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogType, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gamblemyspcost, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, speed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bitfield1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnstack, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemoffset, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, namestr, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missiletype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mindam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxdam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, automyspprefix, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invwidth, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invheight, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nodurability, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, component, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, useable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, unique, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questdiffcheck, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transparent, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transtbl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightradius, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, belt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, autobelt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stackable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spellicon, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qntwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hasinv, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemsockets, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Transmogrify, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TMogMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemapplytype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Transform, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvTrans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, compactsave, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkipName, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Nameable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicMin, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AkaraMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GheedMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CharsiMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FaraMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LysanderMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrognanMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HraltiMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlkorMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OrmusMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ElzixMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AshearaMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CainMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HalbuMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, JamellaMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MalahMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LarzukMagicLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrehyaMagicLvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NightmareUpgrade, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HellUpgrade, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PermStoreItem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multibuy, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, calc3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, len, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spelldesccalc, UINT);
}

int process_misc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(armor, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(weapons, acTemplatePath, acBinPath, acTxtPath);

            Misc_InitValueMap(pstValueMap, pstLineInfo);

            m_iMiscCount = 0;

            m_stCallback.pfnConvertValue = Misc_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);

            if ( 0 == ItemsCode_ParseBin(acTemplatePath, acBinPath, acTxtPath) )
            {
                return 0;
            }
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            Misc_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Misc_ConvertValue;
            m_stCallback.pfnFieldProc = Misc_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

