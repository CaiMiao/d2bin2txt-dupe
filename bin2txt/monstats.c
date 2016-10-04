#include "global.h"

#define FILE_PREFIX "monstats"
#define NAME_PREFIX "ms"

/*
 MonStats.txt File Guide
By Nefarius
This guide is based on Kingpin's 1.10 update to my 1.09 MonStats.txt guide.

#I have posted this outside of the fileguide thread because most of the fileguides in there are preliminary as I see it.










ID Settings

ID �C this column contains the pointer that will be used in other txt files such as levels.txt and superuniques.txt.

HCIDX �C this is the actual internal ID of the unit (this is what the ID pointer actually points at) remember that no two units can have the same ID, this will result in lots of unpredictable behaviour and crashes so please don��t do it. This "
HarcCodedInDeX" is used for several things, such as determining whenever the unit uses DCC or DC6 graphics (like mephisto and the death animations of Diablo, the Maggoc Queen etc.), the HCIDX column also links other hardcoded effects to the units, such 
as the transparency on necro summons and the name-color change on unique boss units (thanks to Kingpin for the info)

BASEID �C this column contains the ID pointer of the ��base�� unit for this specific monster type (ex. There are five types of ��Fallen��; all of them have fallen1 as their ��base�� unit). The baseID is responsible for some hardcoded behaviours, for 
example moving thru walls (ghosts), knowing what units to ressurect, create etc (putrid defilers, shamans etc), the explosion appended to suicide minions (either cold, fire or ice). Thanks to Kingpin for additional info on this column.

NEXTINCLASS �C this column contains the ID of the next unit in the chain. (Continuing on the above example, fallen1 has the ID pointer of fallen2 in here). If you want to make a monster subtype less you should simply leave this blank and make BaseId 
point at itself (its ID pointer). I assume the game may use this for ��map generated�� monsters such as the fallen in the fallen camps, which get picked based on area level (the same camp, that in the cold plains contains normal fallen will contain 
carvers and devilkin elsewhere).






Display Settings I

TRANSLVL �C this indicates which palette entry the unit will use, most monsters have a palshift.dat file in their COF folder, this contains 8 palettes (5 of them are used normally), these palettes are used by the game to make the various subtypes appear 
in ��a different light�� icon_wink.gif. Note that some tokens such as FC do not accept any palettes whatsoever.

NAMESTR �C this column contains the string-key used in the TBL files to make this monsters name appear when you highlight it. Note that string keys are case sensitive, so if you enter a key like ��Foo�� in monstats.txt you must enter exactly that in the 
TBL file! (IE if you enter ��foo�� or ��fOO�� you will get a nice ��not xlated call ken�� or ��an evil force�� displayed instead of your enemies name).

MONSTATSEX �C this column contains the ID pointer to an entry in MonStats2.txt. In 1.10 Blizzard have moved all the graphical aspects (light radius, bleeding etc) to a new file to conserve space (monstats.txt is one column short of 256, the maximum M$ 
Excel can handle, and that��s what they used for their files I guess).






Other links to external files/code

MONPROP �C this column contains the ID pointer to an entry in MonProp.txt. MonProp.txt controls what special modifiers are appended to the unit, for example you can use it to give your monsters random resistances or immunities, give them ��get hit skills
�� and almost anything else (look at the MCML).

MONTYPE �C this column contains the group ID of the ��super group�� this monster belongs to, IE all skeletons belong to the ��super group�� skeleton. The 1.10 MonType.txt works exactly like ItemTypes.txt, furthermore this file is used for special 
modifiers. (Additional damage vs. monster-class)

AI �C this column tells the game which AI to use for this monster, note that every AI needs a set amount of animation modes (GH, A1, A2, S1, WL, RN etc). If you want to make a melee unit shoot missiles you must edit the COF files for its attack 
animations to use trigger ID #2 and not trigger ID #1 otherwise the missile will either not be released or won��t do any damage, the same change must also be done in ANIMDATA.D2.






Display Settings II

DESCSTR �C this column contains the string-key for the monsters description (leave it blank for no description), IE ever wandered how to make it say something below the monster name (such as ��Drains Mana and Stamina etc), well this is how you do it. 
Just put the string-key of the string you want to display below the monsters name in here.

CODE �C this is the only graphical setting (besides TRANSLVL) left in MonStats.txt, this controls which token the game uses for this monster (IE in what folder it looks for animations).






Misc Boolean Settings I

ENABLED �C Boolean, 1=enabled, 0=disabled. This controls whenever the unit can be used at all for any purpose whatsoever. This is not the only setting that controls this; there are some other things that can also disable the unit. (RARITY and ISSPAWN 
columns see those for description)

RANGEDTYPE �C Boolean, 1=ranged attacker, 0=melee attacker. This tells the game whenever this is a ranged attacker; I suspect this has to do with the RANGEDSPAWN column in levels.txt. (Could it be the game uses this for preference settings when spawning 
monsters to avoid areas being populated only with melee monsters, IE the game picks a set amount of monsters for every level, randomly, only based on their rarity values, from those specified in Levels.txt, now I assume that it could pick 4 melee 
monsters, however in 1.10 Blizzard added a check to prevent this from happening AFAIK and this could be how they control it.)






Nest/Spawner Settings

PLACESPAWN �C Boolean, 1=spawner, 0=not a spawner. This tells the game whenever this unit is a ��nest��. IE, monsters that spawn new monsters have this set to 1. Note that you can make any monster spawn new monsters, irregardless of its AI, all you need 
to do is adjust these four columns and make sure one of its skills is either ��Nest�� or ��Minion Spawner��.

SPAWN �C this column contains the ID pointer of the unit to spawn. (in case it is a spawner that is), so if you want to make a new monster that generates Balrogs this is where you would put the Balrogs ID pointer.

SPAWNX, SPAWNY �C the x/y offsets at which spawned monsters are placed. IE. This prevents the spawned monsters being created at the same x/y coordinates as the spawner itself, albeit its not needed, Blizzards collision detection system is good enough to 
prevent them from getting stuck.

SPAWNMODE �C which mode will the spawned monster be spawned in. IE. If you make a golem summoner (yes I know, ��very original��) you could put S1 in here to make it look as if the golems are really summoned (otherwise they would just appear).






Group and Minion Settings

MINION1, MINION2 �C these columns contain the ID pointers to the minions that spawn around this unit when it is created. Lets say you want your super-strong boss to spawn with 5 Oblivion Knights. To do this you would simply enter the Oblivion Knights ID 
pointer in the MINION1 column. And set PARTYMIN and PARTYMAX both to 5. MINION1/2 are used for several other things. If the monster spawns as unique or superunique then it will have the unit from MINION1/2 set as its minion instead of monsters of its 
own type. That��s why Lord De Seis doesn��t spawn with other oblivion knights anymore. To semi-circumvent this I suggest you simply put the monsters ID pointer in the MINION2 column (I.E. if you give the Oblivion Knights their own ID pointer in MINION2, 
Lord De Seis should spawn with both Doom Knights and Oblivion Knights again). The other use controls what monster is created when this unit dies. For example Flayer Shamans will spawn a regular Flayer when they are killed. To enable this you must set 
SPLENDDEATH to 1, make sure the unit you spawn this was has a raise or resurrect sequence otherwise it will look weird (but it works).

SETBOSS �C Boolean, 1=set unit as boss, 0=don��t set unit as boss. The original guide stated that this controls which type of minion the unit spawns with when it��s a boss. This column however does not influence this behaviour. I believe this has to do 
with AI (IE some units can pass on commands to their minions, maybe this specifies which unit can do so).

BOSSXFER �C Boolean, 1=true, 0=false. Unknown, either related to boss modifiers (Lightning enchanted etc) or to AI.

PARTYMIN, PARTYMAX �C How many minions are spawned together with this unit. As mentioned above in the MINION1/2 columns, this controls the quantity of minions this unit has. Id avoid setting this to more 15.

MINGRP, MAXGRP �C Exactly like the previous two columns, just that this controls how many units of the base unit to spawn. In the past (1.00-1.06), setting the minimum to more then 99 would crash the game. I am not aware if this also occurs in 1.07-1.10 
but I��d avoid doing it anyway.





Population Control and Dynamics Settings I

SPARSEPOPULATE �C This column is a great tool for us balance freaks. This is like a ��second layer of security�� when it comes to population control. Lets say you have a really tough enemy and want it to occur less densely then the other monsters in a 
level. So, you have the choice of either lowering MONDEN (levels.txt) or MINGRP and MAXGRP. But this would in every case not produce exactly what you want, lowering MONDEN would make the monster population, irregardless of type less dense and lowering 
the amount of monsters in the group wouldn��t help either (it would possibly make your tough monster easier then you want). So what to do? This column controls the overall chance something will spawn (0-100%), Leaving it blank is the same as 100%. If 
you enter ��80�� in this column then whenever the game chooses to spawn this unit it will first roll out the chances. So in 2 out of 10 cases the monster will not be spawned. Setting it lower then 50 is however not recommended. Note, this does not mean 
that lower values don't work or do something bad. In case the game doesn't roll out the monster and this monster has units specified in minion1/minion2 columns it will only spawn those minions without the "main" unit.






Velocity Settings

VELOCITY, RUN �C controls the walking and running speed of this monster (respectively), note that RUN is only used if the monster has a RN mode and its AI uses that mode. I��d suggest staying below 25 on this one.






Population Control and Dynamics Settings II

RARITY �C This one also helps controlling the monster population, it controls the overall odds that this monster will be spawned. I.E. Lets say in levels.txt you have two monsters set to spawn Monster A has a rarity of 10 whereas Monster B has a rarity 
of 1 and the level in question is limited to 1 monster type. First the game sums up the chances (11) and then calculates the odds of the monster spawning. Which would be 1/11 (9% chance) for Monster B and 10/11 (91% chance) for Monster A, thus Monster A 
is a lot more common then monster B. If you set this column to 0 then the monster will never be selected by Levels.txt (for obvious reasons, and I dare to say, it could lead to a crash if this is the only monster to spawn on the level, it would lead to 
a division by zero, unless Blizzard added some double checks here).






Level Settings

LEVEL, LEVEL(N), LEVEL(H) �C Controls the monsters level on the specified difficulty. This setting is only used on normal, on nightmare and hell (thus the two later columns are actually obsolete) the monsters level is identical with the area level. I 
did some tests on this and found it to not matter if the level is higher or lower. It will be set to it indefinitely. Note that the monsters level is used by the game to evaluate the stats the monster will have in 1.10 (look at the stats section for 
more info).






Sound Settings

MONSOUND �C Specifies the ID pointer to this monsters ��Sound Bank�� in MonSound.txt when this monster is normal.

UMONSOUND �C Specifies the ID pointer to this monsters ��Sound Bank�� in MonSounds.txt when this monster is unique or champion. For Superunique monsters this is controlled by SuperUniques.txt.






AI Settings

THREAT �C Used by the games Threat Rating System to tell AIs which unit to target first. The higher this is the higher the Threat level. So I guess setting this to 25 or so on Maggot Eggs would make your Merc try to destroy those first.

AIDEL, AIDEL(N), AIDEL(H) �C The controls delays between AI ticks, however how exactly this is used is still shrouded in mystery. Its likely that each AI may use this in a sightley different fashion. In general however, the higher the number the slower 
something should become (after all the delay increases that way), what part of the AI this delay applies to however is uncertain due to the quantity of different observations.

AIDIST, AIDIST(N), AIDIST(H) �C The distance in cells required for this AI to be enabled. This is only used for mephisto on nightmare and hell, I assume the game otherwise uses some hardcoded default value. For the units ��Radius of Awareness��.

AIP1-8, AIP1-8(N), AIP1-8(H) �C These cells pass on parameters (usually in percentage) to the AI code. For descriptions about what all these AIs do check MonAI.txt. Note that some AIs are very badly or not at all, explained there (��Thanks�� Blizzard!). 
Many people have trouble with the AI of the Imps, this AI is special and uses multiple rows, to understand what the cells do look at the original monstats.txt file (from D2EXP.MPQ).






Projectile Settings

MISSA1, MISSA2, MISSS1, MISSS3, MISSS4, MISSC, MISSSQ �C These columns control ��non-skill-related�� missiles used by the monster. For example if you enter a missile ID pointer (from Missiles.txt) in MissA1 then, whenever the monster uses its Attack1 
Mode it will shoot a missile, this however will not work properly if 1. The COF files of A1 use the #1 trigger (to get it to work change the trigger in the COF files and in ANIMDATA.D2 to #2). And 2. If the AI of the monster doesn��t support missiles it 
will usually look very weird (but this can sometimes create nice effects). For the beginners, A1=Attack1, A2=Attack2, S1=Skill1, S2=Skill2, S3=Skill3, S4=Skill4, C=Cast, SQ=Sequence.





Misc Boolean Settings II (especially NPC related!)

ALIGN �C Switch, 1=aligned, 0=enemy, 2=neutral. This setting controls whenever the monster fights on your side or fights against you (or if it just walks around, IE a critter). If you want to turn some obsolete NPCs into enemies like I usually do this 
is one of the settings you will need to modify. Setting it to 2 without adjusting other settings (related to AI and also some in MonStats2) it will simply attack everything.

ISSPAWN �C Boolean, 1=spawnable, 0=not spawnable. This controls whenever this unit can be spawned via Levels.txt.

ISMELEE �C Boolean, 1=melee attacker, 0=not a melee attacker. This controls whenever this unit can spawn with boss modifiers such as Multiple Shot or not. IE Melee monsters will never spawn with MS.

NPC �C Boolean, 1=I��m a NPC, 0=I��m not. This controls whenever the unit is a NPC or not. See below.

INTERACT �C Boolean, 1=Special NPC features enabled, 0=No special NPC features.
This controls whenever you can interact with this unit. IE. This controls whenever it opens a speech-box or menu when you click on the unit. To turn units like Kaeleen or Flavie into enemies you will need to set this to 0 (you will also need to set NPC 
to 0 for that).

INVENTORY �C Boolean, 1=Has an inventory, 0=Has no inventory. Controls whenever this NPC or UNIT can carry items with it. For NPCs this means that you can access their Inventory and buy items (if you disable this and then try to access this feature it 
will cause a crash so don��t do it unless you know what you��re doing). For Monsters this means that they can access their equipment data in MonEquip.txt.

INTOWN �C Boolean, 1=I can enter towns, 0=I can��t enter towns. This controls whenever enemies can follow you into a town or not. This should be set to 1 for everything that spawns in a town.






Type Settings

LUNDEAD �C Boolean, 1=True, 0=False. Blizzard used this to differentiate High and Low Undead (IE. Low undead like Zombies, Skeletons etc are set to 1 here), both this and HUNDEAD will make the unit be considered undead so I don��t see how these two 
actually differ. This may have to with the Unravelers resurrecting behaviour (IE they only ressurect low undead), thanks to Brother Laz for this input.

HUNDEAD �C Boolean, 1=True, 0=False. This is usually set for large magical undead monsters Lichs, Unravelers etc. See comments under the previous column.

DEMON �C Boolean, 1=True, 0=False. This makes the game consider this unit a demon.






Misc Boolean Settings III

FLYING �C Boolean, 1=I can fly, 0=I can��t fly. If you set this to 1 the monster will be able to move fly over obstacles such as puddles and rivers.

OPENDOORS �C Boolean, 1=I can open doors, 0=I��m to stupid to open doors. Ever wanted to make the game more like D1 (where closing doors could actually protect you), then this column is all you need. By setting this to 0, the monster in question will 
not be able to open doors any more.

BOSS �C Boolean, 1=I��m a boss, 0=I��m not a boss. This controls whenever this unit is a special boss, monsters set as boss IGNORE the level settings, IE. they will always spawn w the levels specified in MonStats.txt. Setting this to 1 for monsters does 
not cause a crash in 1.10. The only effects it has are that the monster will always use the mlvl specified in MonStats.txt (and it will probably gain the special boss resistances, IE it will not be effected by things like Deadly Strike the way normal 
monsters are. Though I didn't have time to do test on this yet)

PRIMEEVIL �C Boolean, 1=I��m a prime evil, 0=I��m not a prime evil. (=Act Boss). Changing this could lead to unpredictable results, however I assume this controls the Act Boss Specific resistances to special damage modifiers (like Deadly Strike etc).

KILLABLE �C Boolean, 1=Mortal, 0=Immortal. Setting this to 0 will make the monster unkillable. There is no reason to set this to 1 for enemies, it will just result in your userbase decreasing.

SWITCHAI �C Boolean, 1=Can chance sides, 0=Cannot change sides. Can this units mind be altered by ��mind altering skills�� like Conversion, Revive etc.

NOAURA �C Boolean, 1=Can��t get an aura, 0=Can get an aura. Monsters set to 0 here will not be effected by friendly auras.

NOMULTISHOT �C Boolean, 1=Can��t get multishot modifier, 0=Can get multishot modifier. This is another layer of security to prevent this modifier from spawning, besides the ISMELEE layer.

NEVERCOUNT �C Boolean, 1=Never accounted for, 0=Accounted for. Unknown but I assume this may have to do with population dynamics and level building. Some also believe this may be related to multi-missile attacks.

PETIGNORE �C Doesn't work in 1.10 anymore (thanks Snowknight), previously it was a Boolean, 1=Summons ignore this unit, 0=Summons notice this unit. If you set this to 1 this monster will not be targeted by summons (and mercs?) irregardless of its THREAT 
level.

DEATHDMG �C Boolean, 1=Damage players colliding with my death animation, 0=Don��t damage anything. This works similar to corpse explosion (its based on hitpoints) and damages the surrounding players when the unit dies. (Ever wanted to prevent those 
undead stygian dolls from doing damage when they die, this is all there is to it)

GENERICSPAWN �C Boolean, 1=Use generic spawning, 0=Don��t use generic spawning. Unknown but probably has to do with population dynamics and level building like NEVERCOUNT.

ZOO �C Boolean, 1=true, 0=false. Unknown it could be related to AI when this unit spawns as part of a boss pack, but this is just a wild guess rather then knowledge.






Skill Settings

SENDSKILLS �C Switch, 1=Unknown, 2=Used for assassin traps, 0=Don��t send skills. This is only used by two of the Assassin traps, but what exactly it is used for is unknown.

SKILL1-8 �C The ID Pointer to the skill the monster will cast when this specific slot is accessed by the AI. (from Skills.txt). Which slots are used is determined by the units AI.

SK1MODE-SK8MODE �C The graphical MODE (or SEQUENCE) this unit uses when it uses this skill.

SK1LVL-SK8LVL �C The skill level of the skill in question. This gets a bonus on nightmare and hell which you can modify in DifficultyLevels.txt.






Resistance Settings

DRAIN, DRAIN(N), DRAIN(H) �C Controls the effectiveness of Life and Mana steal equipment on this unit on the respective difficulties. 0=Can��t leech at all. (negative values don't damage you, thanks to Doombreed-x for testing this), setting it to more 
then 100 would probably make LL and ML more effective. Remember that besides this, Life and Mana Steal is further limited by DifficultyLevels.txt.

COLDEFFECT, COLDEFFECT(N), COLDEFFECT(H) �C Controls the effectiveness of cold damage on this unit. The lower this value is, the more speed this unit looses when its frozen. �C100 will probably make it stop completely. Positive values will make the unit 
faster (thanks to Brother Laz for confirming my assumption), and 0 will make it unfreezeable. The cold length is NOT effected by this, for cold length and freeze length settings refer to DifficultyLevels.txt.


HINT: If you want to give units random resistances and immunities you can use MonProp.txt.

RESDM, RESDM(N), RESDM(H) �C Damage resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.

RESMA, RESMA(N), RESMA(H) �C Magic resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.

RESFI, RESFI(N), RESFI(H) �C Fire resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.

RESLI, RESLI(N), RESLI(H) �C Lightning resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.

RESCO, RESCO(N), RESCO(H) �C Cold resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.

RESPO, RESPO(N), RESPO(H) �C Poison resistance on the respective difficulties. Negative values mean that the unit takes more damage from this element, values at or above 100 will result in immunity.






Misc Settings

DAMAGEREGEN �C This controls how much health this unit regenerates. Sometimes this is altered by the units AI. The formula in 1.09 was (REGEN * HP) / 4096. So a monster with 200 hp and a regen rate of 10 would regenerate ~0,5 HP every frame.

SKILLDAMAGE �C ID Pointer to the skill that controls this units damage. This is used for the druids summons. (I.E. their damage is specified solely by Skills.txt and not by MonStats.txt)






Stat Settings

NORATIO �C Boolean, 1=Don��t use MonLevel.txt, 0=Use MonLevel.txt. Does this unit use MonLevel.txt or does it use the stats listed in MonStats.txt as is. Setting this to 1 will result in an array of problems, such as the appended elemental damage being 
completely ignored, irregardless of the values in it.

NOSHLDBLOCK �C Boolean, 1=Can block without a blocking animation, 0=Can��t block without a blocking animation. Quite self explanatory, in order for a unit to block it needs the BL mode, if this is set to 1 then it will block irregardless of what modes 
it has.

TOBLOCK, TOBLOCK(N), TOBLOCK(H) �C This units chance to block. See the above column for details when this applies or not. Monsters are capped at 75% block as players are AFAIK.

CRIT �C This units chance of scoring a critical hit.

Hint: The values below are percentages (if NORATIO is set to 0). The game first checks the monsters level and then uses these percentages to calculate the actual stats from the ��general stats�� listed in MonLevel.txt. This is done by regular percentage 
calculation, IE: S/100*P (S=Stat, P=Percentage). As an example, if your monster is level 50, and has 200 listed in MINHP in MonStats.txt and the ��general stat�� for HP at mlvl 50 is 100 then the following calculation is done: 100/100*200 which results 
in 200 HP. In the same way, if S=300 and P=200 the result will be 600. If you want the game to use the values directly from monstats.txt and don��t want to set NORATIO to 0 (to avoid the bugs related to doing that), simply change all entries in MonLevel.
txt to 100).

MINHP, MAXHP, MINHP(N), MAXHP(N), MINHP(H), MAXHP(H) �C This units minimum and maximum HP on the respective difficulties.

AC, AC(N), AC(H) �C This units Armor Class on the respective difficulties.

EXP, EXP(N), EXP(H) �C The experience you get when killing this unit on the respective difficulty.

A1MIND, A1MAXD, A1MIND(N), A1MAXD(N), A1MIND(H), A1MAXD(H) �C This units minimum and maximum damage when it uses Attack 1.

A2MIND, A2MAXD, A2MIND(N), A2MAXD(N), A2MIND(H), A2MAXD(H) �C This units minimum and maximum damage when it uses Attack 2.

S1MIND, S1MAXD, S1MIND(N), S1MAXD(N), S1MIND(H), S1MAXD(H) �C This units minimum and maximum damage when it uses Special Attack 1 (or Skill 1), usually used for missiles like Arrows etc.

A1TH, A1TH(N), A1TH(H) �C This units attack rating for Attack 1 on the respective difficulties.

A2TH, A2TH(N), A2TH(H) �C This units attack rating for Attack 2 on the respective difficulties.

S1TH, S1TH(N), S1TH(H) �C This units attack rating for Special Attack 1 (or Skill 1) on the respective difficulties. Usually used for missiles like Arrows etc.






Xtra Elemental Damage Settings

HINT: These columns are not used correctly if you set NORATIO to 1. (thanks to Sduibek for finding this stupid little typo that snuck in here)

EL1MODE-EL3MODE �C The mode to which the elemental damage is appended. The modes to which you would usually attack elemental damage are A1, A2, S1, S2, S3, S4, SQ or C as these are the only ones that naturally contain trigger bytes.

EL1TYPE-EL3TYPE �C The type of the elemental damage appended to an attack. There are several elements: fire=Fire Damage, ltng=Lightning Damage, cold=Cold Damage (uses duration), pois = Poison Damage (uses duration), mag=Magic Damage, life=Life Drain (
the monster heals the specified amount when it hits you), mana=Mana Drain (the monster steals the specified amount of mana when it hits you), stam=Stamina Drain (the monster steals the specified amount of stamina when it hits you), stun=Stun Damage (
uses duration, damage is not used, this only effects pets and mercs, players will not get immobilized but they will get thrown into hit recovery whenever they get hit by an attack, no matter what type of attack it is, thanks to Brother Laz clearing this 
one up), rand=Random Damage (uses duration, either does Poison, Cold, Fire or Lightning damage, randomly picked for every attack), burn=Burning Damage (uses duration, this damage type cannot be resisted and shouldn��t be used), frze=Freezing Damage (
uses duration, this will effect players like normal cold damage but will freeze and shatter pets). If you want to give your monster knockback use MonProp.txt.

EL1PCT-EL3PCT, EL1PCT(N)-EL3PCT(N), EL1PCT(H)-EL3PCT(H) �C Chance to append elemental damage to an attack on the respective difficulties. 0=Never append, 100=Always append.

EL1MIND-EL3MIND, EL1MAXD-EL3MAXD, EL1MIND-EL3MIND(N), EL1MAXD-EL3MAXD(N), EL1MIND-EL3MIND(H), EL1MAXD-EL3MAXD(H) �C Minimum and Maximum elemental damage to append to the attack on the respective difficulties. (See the hints under the Stat Settings 
section, this uses the same calculations). Note that you should only append elemental damage to those missiles that don��t have any set in Missiles.txt.

EL1DUR-EL3DUR, EL1DUR(N)-EL3DUR(N), EL1DUR(H)-EL3DUR(H) �C Duration of the elemental effect (for freeze, burn, cold, poison and stun) on the respective difficulties.






Treasureclass Settings

HINT: Because of the new Treasureclass system introduced in 1.10 these entries are only of minor influence regarding what TC is being selected unless you change the system by editing TreasureClassEX.txt.

TREASURECLASS1, TREASURECLASS1(N), TREASURECLASS1(H) �C The Treasureclass used by this unit as a normal monster on the respective difficulties.

TREASURECLASS2, TREASURECLASS2(N), TREASURECLASS2(H) �C The Treasureclass used by this unit as a champion on the respective difficulties.

TREASURECLASS3, TREASURECLASS3(N), TREASURECLASS3(H) �C The Treasureclass used by this unit as a unique or superunique on the respective difficulties.

TREASURECLASS4, TREASURECLASS4(N), TREASURECLASS4(H) �C The Quest Treasureclass used by this monster. (For example, the act bosses always have better odds of dropping rare, set and unique items the first time you kill them).

TCQUESTID �C The ID of the Quest that triggers the Quest Treasureclass drop.

TCQUESTCP �C The ID of the Quest State that you need to complete to trigger the Quest Treasureclass trop.






Special Settings

SPLENDDEATH �C Switch, 0=no special death, 1=spawn the monster in the MINION1 column when I die, 2=kill whatever monster is mounted to me when I die (used by guard towers that kill the imps that are on top of them when they die I guess).

SPLGETMODECHART �C Boolean, 1=Get Special Mode Chart, 0=Don��t get special mode chart. Unknown but could be telling the game to look at some internal table. This is used for some Act Bosses and monsters like Putrid Defilers.

SPLENDGENERIC �C Boolean, 1=true, 0=false. Works in conjunction with SPLCLIENTEND, this makes the unit untargetable when it is first spawned (used for those monsters that are under water, under ground or fly above you)

SPLCLIENTEND�C Boolean, 1=true, 0=false. Works in conjunction with SPLENDGENERIC, this makes the unit invisible when it is first spawned (used for those monsters that are under water, under ground or fly above you), this is also used for units that have 
other special drawing setups.






EOL

EOL �C End of Line, used to avoid the trailing bit error M$ Excel usually causes when adjusting the end of the rows. This column must contain 0 unless you want to crash when the game loads.






















Subsequently updated BOSS column (and related ones).

*/

/*
�ļ���������
Mon��Monster�������
Stat(s)��State(s)��״̬��
���ļ����������й����״̬���ԡ�
�ļ��е�ÿһ�б�ʾһ�ֹ��

ÿ�еĺ������£�

Id���˹����������

hcIdx���˹���ı�š�

BaseId���˹����Ӧ�Ļ�����0�ף������ͬװ������ͨ����չ������һ�����ܶ���ﶼ�м������ߵĽ�λ��

NextInClass���˹����Ӧ����һ����λ�Ĺ��

TransLvl���˹���Ľ�λ��

NameStr���˹�������֣���tbl�ļ�������

MonStatsEx���˹������չ���ԣ���MonStats2.txt������

MonProp���˹�����������ԣ���MonProp.txt������

MonType���˹���������MonType.txt������

AI���˹����AI����MonAi.txt������

DescStr���˹���Ķ�����������tbl�ļ�������

Code���˹�������Ρ�

enabled���˹����Ƿ������Ϸ�г��֡�

rangedtype���˹����Ƿ���Զ�̹����ġ�

placespawn���˹����Ƿ���������������Ĺ��

spawn���˹�������������Ĺ��

spawnx���������Ĺ���ĳ���λ������1��

spawny���������Ĺ���ĳ���λ������2��

spawnmode���������Ĺ���ĳ�����������Ѫ�񸴻�Ľ�ʬ�Ǵӵ����������Ķ�����������ֱ�ӳ��֡�

minion1���˹������ӹ���1�������ħ��ʦ������ǳ���ħ��

minion2���˹������ӹ���2��

SetBoss���˹��������Ƿ��Դ˹���Ϊ���ġ�

BossXfer���˹��������Ƿ���д˹���Ľ������ԡ�

PartyMin���˹��������м�����ӡ�

PartyMax���˹�������м�����ӡ�

MinGrp���˹����Ⱥ���ֵ���С��Ŀ��

MaxGrp���˹����Ⱥ���ֵ������Ŀ��

sparsePopulate���Ƿ����ƴ˹������Ŀ��

Velocity���˹�����ƶ��ٶȡ�

Run���˹����ܲ�ʱ���ƶ��ٶȡ�

Rarity���˹���ĳ���Ƶ�ʣ�����ͬ�����ܶȵ�����£���ֵԽ�߳��ֵ�Խ�ࡣ

Level���˹�������ͨ�Ѷ��µļ���

Level(N)���˹����ڶ����Ѷ��µļ���ֻ��BOSS���á������Ѷ��µĹ��Ｖ���������ڳ���������

Level(H)���˹����ڵ����Ѷ��µļ���ֻ��BOSS���á������Ѷ��µĹ��Ｖ���������ڳ���������

MonSound���˹����ܹ���������������MonSound.txt������

UMonSound�����˹�����Ϊ��ֻ�ͷĿ��ʱ�ܹ���������������MonSound.txt������

threat���˹����Σ�յȼ���

aidel /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ�AI������϶���������ƶ������ܶ�������һ��AI������

aidist /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ���Ұ��С��

aip 1-8 /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĵ�1-8��AI�����Ĳ�����

MissA1���˹����õ�һ����ͨ����ʱ�ķ����

MissA2���˹����õڶ�����ͨ����ʱ�ķ����

MissS1���˹����ü���1ʱ�Ķ��ⷢ���

MissS2���˹����ü���2ʱ�Ķ��ⷢ���

MissS3���˹����ü���3ʱ�Ķ��ⷢ���

MissS4���˹����ü���4ʱ�Ķ��ⷢ���

MissC���˹���ʩ��ʱ�Ķ��ⷢ���

MissSQ���˹�����˳����ʱ�ķ����

Align���˹������Ӫ��0���������Ӫ��1���������Ӫ��2����������Ӫ��

isSpawn���˹����Ƿ�����Levels.txt�������ɡ�

isMelee���˹����Ƿ��ǽ�ս�ġ�

npc���˹����Ƿ���NPC��

interact���˹��NPC���Ƿ��ܸ���ҽ�����

inventory���˹����Ƿ�����Ʒ����ռ䡣

inTown���˹����ܷ�����������������ù�����׷��׷�������

 lUndead���˹����Ƿ��ǵͼ��������

hUndead���˹����Ƿ��Ǹ߼��������

demon���˹����Ƿ��Ƕ�ħ��

flying���˹����Ƿ��Է��з�ʽ�ƶ���

opendoors���˹����Ƿ�Ὺ�š�

boss���˹����Ƿ���BOSS��

primeevil���˹����Ƿ���ʼħ��

killable���˹����Ƿ�ɱ�ɱ����

switchai���˹����Ƿ��ı�AI�����統�������

noAura���˹����ܷ񱻹⻷Ӱ�졣

nomultishot���˹����ܷ���ж���������ԡ�

neverCount���˹����Ƿ���������

petIgnore�����ò�����

deathDmg���˹�������ʱ�Ƿ����Χ���˺���

genericSpawn���˹����Ƿ����ͨ�õ����ɷ�ʽ��

zoo������԰����֪��ʲô��˼�Ĳ�����

SendSkills�����ò�����

 Skill 1-8���˹���ĵ�1-8�����ܡ�

Sk 1-8 mode���˹���ʹ�õ�1-8������ʱ�Ķ�����

Sk 1-8 lvl���˹���ĵ�1-8�����ܵĻ����ȼ����ڶ��κ͵����Ѷ��»��ж������ߣ��μ�DifficultyLevels.txt����

Drain /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ�����/����͵ȡЧ����

coldeffect /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µı���/����״̬�ĳ���ʱ��˥����

ResDm /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ������ԡ�

ResMa /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ�ħ�����ԡ�

ResFi /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĻ��濹�ԡ�

ResLi /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ����翹�ԡ�

ResCo /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µı��俹�ԡ�

ResPo /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĶ��ؿ��ԡ�

DamageRegen������������ظ��ٶȡ�ÿ��ظ���������Ϊ��������ֵ * �������� * 25 / 4096����

SkillDamage���˹�����˺����ĸ����ܾ�����

noRatio���˹���������Ƿ�ʹ��MonLvl.txt�ķ���������1����ʹ�á�

NoShldBlock���˹����ʱ�Ƿ��и񵲶�����

ToBlock /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĸ񵲼��ʡ�

Crit���˹��﹥��ʱ��������һ���ļ��ʡ�

minHP /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĻ�����С����ֵ��

maxHP /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĻ����������ֵ��

AC /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĻ���������

Exp /(N)/(H)���� ��ͨ/����/���� �Ѷ���ɱ���˹�������õĻ�������ֵ��

A1/A2/S1 MinD /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ���ʹ�� ��ͨ����1/��ͨ����2/����1 �Ļ�����С�˺���

A1/A2/S1 MaxD /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ���ʹ�� ��ͨ����1/��ͨ����2/����1 �Ļ�������˺���

A1/A2/S1 TH /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ���ʹ�� ��ͨ����1/��ͨ����2/����1 ʱ�Ļ��������ʡ�

El 1-3 Mode���˹����и��������˺��ĵ�1-3���������ࡣ

El 1-3 Type���˹����и��������˺��ĵ�1-3�����������и��ӵ������˺������ElemTypes.txt������

El 1-3 Pct /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĵ�1-3���������฽�������˺��ļ��ʡ�

El 1-3 MinD /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĵ�1-3���������฽�ӵ������˺���Сֵ��

El 1-3 MaxD /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĵ�1-3���������฽�ӵ������˺����ֵ��

El 1-3 Dur /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µĵ�1-3���������฽�ӵ������˺�Ч���ĳ���ʱ�䡣

TreasureClass1 /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ��µ�TC��

TreasureClass2 /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ�����ΪͷĿʱ��TC��

TreasureClass3 /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ�����Ϊ���ʱ��TC��

TreasureClass4 /(N)/(H)���˹����� ��ͨ/����/���� �Ѷ�����Ϊ�����ʱ��TC��

TCQuestId���˹�����Ϊ�����ʱ�������š�

TCQuestCP���ܹ���������ɱ��ӦTC������״̬��

SplEndDeath������ʱ������Ч����0����������Ч����1���������������1��2������������ڴ˹������ϵĹ���һ��������

SplGetModeChart���Ƿ�������mode��

SplEndGeneric���ճ���ʱ�Ƿ�ɱ�ѡ����ΪĿ�ꡣ��Ǳ��ˮ��Ĺ֡�

SplClientEnd���ճ���ʱ�Ƿ�ɼ�����Ǳ��ˮ��Ĺ֡�

*eol����β��־������Ϊ0��

���Գ�����zoo��Ч�����������Ϊ1
���ù�����level������Ϊ���������ʱ��
��ӽ��������ͻ��ƶ��뿪�㣨�ͺ����޸�Ӫ�صļ���

����ǰ������swithAI=1��monstats2��mWL=1
�������ƶ��Ķ���

���ˣ�zoo=1
����һ��Ч���ǣ�����ƽʱҲ����Ŀ�ĵ��ƶ�


 ��ã�
�ҷ�������ļ��� ��ͨ�Ѷȵ�minHP��maxHP��MinD��MaxD��ò�ƶ������⣬����ʵ�ʣ���d2data.mpq���monstats.txt ��minHP��maxHP��MinD��MaxD������ʵ�ģ� �������ô���£�
�����޸�crit�� ����Ϸ���ƺ�Ҳû������(-direct -txt)��
���֣�лл��


����ظ�

14¥
2012-12-29 21:49

�ٱ� |

zqtjingzi: ��ͨ�ѶȵĹ��ﲻ���ļ����ƣ�ֱ������
2012-12-29 21:54�ظ�
0��������0: �ظ� zqtjingzi :��Ȼֱ�����ɣ���ôd2data.mpq���monstats.txt�Ǹ�ʲô���ã���patch_D2.mpq���ͬ·��ͬ���ļ���ʲô��ϵ�� ����ܷ��Ƽ�Щ������ֵ��������¿�����thx!
2012-12-29 22:07�ظ�
zqtjingzi: �ظ� 0��������0 :ֻ����ͨ�Ѷ�����������ʵ�����ļ��Ǹ��ǵĹ�ϵ�����������á�������ֵ�Ļ���Ʒ��Ӧ����һЩ�����뿴ʲô������ֵ������ȥ����֮������
2012-12-29 22:35�ظ�
0��������0: �ظ� zqtjingzi :������ϸ����monstats������ �����Щ���� ��ĸĹ������ֵ�����ܡ���ͼ�ֲ�֮���
*/

typedef struct
{//total 424 bytes
    unsigned short vhcIdx;
    unsigned short vBaseId; //monstats

    unsigned short vNextInClass;    //monstats
    unsigned short vNameStr;    //strings

    unsigned short vDescStr;    //strings
    unsigned short iPadding2;

#if 1
    unsigned char vBitCombined1;
    unsigned char vBitCombined2;
    unsigned char vBitCombined3;
    unsigned char vBitCombined4;
#else
    //0B
    unsigned char vprimeevil : 1;
    unsigned char vboss : 1;
    unsigned char vBossXfer : 1;
    unsigned char vSetBoss : 1;

    unsigned char vopendoors : 1;
    unsigned char vnoRatio : 1;
    unsigned char visMelee : 1;
    unsigned char visSpawn : 1;

    //88
    unsigned char vkillable : 1;
    unsigned char vflying : 1;
    unsigned char vdemon : 1;
    unsigned char vhUndead : 1;

    unsigned char vlUndead : 1;
    unsigned char vinTown : 1;
    unsigned char vinteract : 1;
    unsigned char vnpc : 1;

    //41
    unsigned char vplacespawn : 1;
    unsigned char vzoo : 1;
    unsigned char vgenericSpawn : 1;
    unsigned char vdeathDmg : 1;

    unsigned char vpetIgnore : 1;
    unsigned char vneverCount : 1;
    unsigned char vnomultishot : 1;
    unsigned char vswitchai : 1;

    //02
    unsigned char iPadding3 : 3;
    unsigned char vrangedtype : 1;

    unsigned char vnoAura : 1;
    unsigned char vNoShldBlock : 1;
    unsigned char venabled : 1;
    unsigned char vinventory : 1;
#endif

    unsigned char vCode[4];

    unsigned short vMonSound;   //monsounds
    unsigned short vUMonSound;  //monsounds

    unsigned short vMonStatsEx; //monstats2
    unsigned short vMonProp;    //MonProp

    unsigned short vMonType;    //montype
    unsigned short vAI; //monai

    unsigned short vspawn;  //monstats
    char vspawnx;
    char vspawny;

    unsigned short vspawnmode;  //monmode
    unsigned short vminion1;    //monstats

    unsigned short vminion2;    //monstats
    unsigned short iPadding10;

    unsigned char vPartyMin;
    unsigned char vPartyMax;
    unsigned char vRarity;
    unsigned char vMinGrp;

    unsigned char vMaxGrp;
    unsigned char vsparsePopulate;
    unsigned char vVelocity;

    unsigned short vRun;
    unsigned short iPadding13;

    unsigned short iPadding14;
    unsigned short vMissA1; //Missiles

    unsigned short vMissA2;
    unsigned short vMissS1;

    unsigned short vMissS2;
    unsigned short vMissS3;

    unsigned short vMissS4;
    unsigned short vMissC;

    unsigned short vMissSQ;
    unsigned short iPadding18;

    unsigned char vAlign;
    unsigned char vTransLvl;
    unsigned char vthreat;
    unsigned char vaidel;

    unsigned char vaidelmybr1Nmybr2;
    unsigned char vaidelmybr1Hmybr2;
    unsigned char vaidist;
    unsigned char vaidistmybr1Nmybr2;

    unsigned char vaidistmybr1Hmybr2;
    unsigned char iPadding21;
    unsigned short vaip1;

    unsigned short vaip1mybr1Nmybr2;
    unsigned short vaip1mybr1Hmybr2;

    unsigned short vaip2;
    unsigned short vaip2mybr1Nmybr2;

    unsigned short vaip2mybr1Hmybr2;
    unsigned short vaip3;

    unsigned short vaip3mybr1Nmybr2;
    unsigned short vaip3mybr1Hmybr2;

    unsigned short vaip4;
    unsigned short vaip4mybr1Nmybr2;

    unsigned short vaip4mybr1Hmybr2;
    unsigned short vaip5;

    unsigned short vaip5mybr1Nmybr2;
    unsigned short vaip5mybr1Hmybr2;

    unsigned short vaip6;
    unsigned short vaip6mybr1Nmybr2;

    unsigned short vaip6mybr1Hmybr2;
    unsigned short vaip7;

    unsigned short vaip7mybr1Nmybr2;
    unsigned short vaip7mybr1Hmybr2;

    unsigned short vaip8;
    unsigned short vaip8mybr1Nmybr2;

    unsigned short vaip8mybr1Hmybr2;
    unsigned short vTreasureClass1; //33 treasureclassex

    unsigned short vTreasureClass2;
    unsigned short vTreasureClass3;

    unsigned short vTreasureClass4;
    unsigned short vTreasureClass1mybr1Nmybr2;

    unsigned short vTreasureClass2mybr1Nmybr2;
    unsigned short vTreasureClass3mybr1Nmybr2;

    unsigned short vTreasureClass4mybr1Nmybr2;
    unsigned short vTreasureClass1mybr1Hmybr2;

    unsigned short vTreasureClass2mybr1Hmybr2;
    unsigned short vTreasureClass3mybr1Hmybr2;

    unsigned short vTreasureClass4mybr1Hmybr2;
    unsigned char vTCQuestId;
    unsigned char vTCQuestCP;

    unsigned char vDrain;
    unsigned char vDrainmybr1Nmybr2;
    unsigned char vDrainmybr1Hmybr2;
    unsigned char vToBlock;

    unsigned char vToBlockmybr1Nmybr2;
    unsigned char vToBlockmybr1Hmybr2;
    unsigned short vCrit;

    unsigned short vSkillDamage;    //skills
    unsigned short vLevel;

    unsigned short vLevelmybr1Nmybr2;
    unsigned short vLevelmybr1Hmybr2;

    unsigned short vminHP;
    unsigned short vMinHPmybr1Nmybr2;

    unsigned short vMinHPmybr1Hmybr2;
    unsigned short vmaxHP;

    unsigned short vMaxHPmybr1Nmybr2;
    unsigned short vMaxHPmybr1Hmybr2;

    unsigned short vAC;
    unsigned short vACmybr1Nmybr2;

    unsigned short vACmybr1Hmybr2;
    unsigned short vA1TH;

    unsigned short vA1THmybr1Nmybr2;
    unsigned short vA1THmybr1Hmybr2;

    unsigned short vA2TH;
    unsigned short vA2THmybr1Nmybr2;

    unsigned short vA2THmybr1Hmybr2;
    unsigned short vS1TH;

    unsigned short vS1THmybr1Nmybr2;
    unsigned short vS1THmybr1Hmybr2;

    unsigned short vExp;
    unsigned short vExpmybr1Nmybr2;

    unsigned short vExpmybr1Hmybr2;
    unsigned short vA1MinD;

    unsigned short vA1MinDmybr1Nmybr2;
    unsigned short vA1MinDmybr1Hmybr2;

    unsigned short vA1MaxD;
    unsigned short vA1MaxDmybr1Nmybr2;

    unsigned short vA1MaxDmybr1Hmybr2;
    unsigned short vA2MinD;

    unsigned short vA2MinDmybr1Nmybr2;
    unsigned short vA2MinDmybr1Hmybr2;

    unsigned short vA2MaxD;
    unsigned short vA2MaxDmybr1Nmybr2;

    unsigned short vA2MaxDmybr1Hmybr2;
    unsigned short vS1MinD;

    unsigned short vS1MinDmybr1Nmybr2;
    unsigned short vS1MinDmybr1Hmybr2;

    unsigned short vS1MaxD;
    unsigned short vS1MaxDmybr1Nmybr2;

    unsigned short vS1MaxDmybr1Hmybr2;
    unsigned char vEl1Mode; //monmode
    unsigned char vEl2Mode;

    unsigned char vEl3Mode;
    unsigned char vEl1Type; //elemtypes
    unsigned char vEl2Type;
    unsigned char vEl3Type;

    unsigned char vEl1Pct;
    unsigned char vEl1Pctmybr1Nmybr2;
    unsigned char vEl1Pctmybr1Hmybr2;
    unsigned char vEl2Pct;

    unsigned char vEl2Pctmybr1Nmybr2;
    unsigned char vEl2Pctmybr1Hmybr2;
    unsigned char vEl3Pct;

    unsigned char vEl3Pctmybr1Nmybr2;
    unsigned char vEl3Pctmybr1Hmybr2;
    unsigned char iPadding67;
    unsigned short vEl1MinD;

    unsigned short vEl1MinDmybr1Nmybr2;
    unsigned short vEl1MinDmybr1Hmybr2;

    unsigned short vEl2MinD;
    unsigned short vEl2MinDmybr1Nmybr2;

    unsigned short vEl2MinDmybr1Hmybr2;
    unsigned short vEl3MinD;

    unsigned short vEl3MinDmybr1Nmybr2;
    unsigned short vEl3MinDmybr1Hmybr2;

    unsigned short vEl1MaxD;
    unsigned short vEl1MaxDmybr1Nmybr2;

    unsigned short vEl1MaxDmybr1Hmybr2;
    unsigned short vEl2MaxD;

    unsigned short vEl2MaxDmybr1Nmybr2;
    unsigned short vEl2MaxDmybr1Hmybr2;

    unsigned short vEl3MaxD;
    unsigned short vEl3MaxDmybr1Nmybr2;

    unsigned short vEl3MaxDmybr1Hmybr2;
    unsigned short vEl1Dur;

    unsigned short vEl1Durmybr1Nmybr2;
    unsigned short vEl1Durmybr1Hmybr2;

    unsigned short vEl2Dur;
    unsigned short vEl2Durmybr1Nmybr2;

    unsigned short vEl2Durmybr1Hmybr2;
    unsigned short vEl3Dur;

    unsigned short vEl3Durmybr1Nmybr2;
    unsigned short vEl3Durmybr1Hmybr2;

    short vResDm;
    short vResDmmybr1Nmybr2;

    short vResDmmybr1Hmybr2;
    short vResMa;

    short vResMamybr1Nmybr2;
    short vResMamybr1Hmybr2;

    short vResFi;
    short vResFimybr1Nmybr2;

    short vResFimybr1Hmybr2;
    short vResLi;

    short vResLimybr1Nmybr2;
    short vResLimybr1Hmybr2;

    short vResCo;
    short vResComybr1Nmybr2;

    short vResComybr1Hmybr2;
    short vResPo;

    short vResPomybr1Nmybr2;
    short vResPomybr1Hmybr2;

    char vcoldeffect;
    char vcoldeffectmybr1Nmybr2;
    char vcoldeffectmybr1Hmybr2;
    unsigned char iPadding90;

    unsigned int vSendSkills;

    unsigned short vSkill1; //skills
    unsigned short vSkill2;

    unsigned short vSkill3;
    unsigned short vSkill4;

    unsigned short vSkill5;
    unsigned short vSkill6;

    unsigned short vSkill7;
    unsigned short vSkill8;

    unsigned char vSk1modeType;
    unsigned char vSk2modeType;
    unsigned char vSk3modeType;
    unsigned char vSk4modeType;

    unsigned char vSk5modeType;
    unsigned char vSk6modeType;
    unsigned char vSk7modeType;
    unsigned char vSk8modeType;

    unsigned short vSk1mode;   //monseq
    unsigned short vSk2mode;

    unsigned short vSk3mode;
    unsigned short vSk4mode;

    unsigned short vSk5mode;
    unsigned short vSk6mode;

    unsigned short vSk7mode;
    unsigned short vSk8mode;

    unsigned char vSk1lvl;
    unsigned char vSk2lvl;
    unsigned char vSk3lvl;
    unsigned char vSk4lvl;

    unsigned char vSk5lvl;
    unsigned char vSk6lvl;
    unsigned char vSk7lvl;
    unsigned char vSk8lvl;

    unsigned int vDamageRegen;

    unsigned char vSplEndDeath;
    unsigned char vSplGetModeChart;
    unsigned char vSplEndGeneric;
    unsigned char vSplClientEnd;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vId[32];
} ST_MONSTAT;

static char *m_apcInternalProcess[] = 
{
    "Id",
    "*eol",
    NULL,
};

static unsigned int m_iMonStatsCount = 0;
static ST_MONSTAT *m_astMonStats = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astMonStats, ST_MONSTAT);

static int MonStats_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Id") )
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

        strncpy(m_astMonStats[pstLineInfo->vhcIdx].vId, acOutput, sizeof(m_astMonStats[pstLineInfo->vhcIdx].vId));
        String_Trim(m_astMonStats[pstLineInfo->vhcIdx].vId);
        m_iMonStatsCount++;
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

static int MonStats_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Id") )
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

char *MonStats_GetStatsName(unsigned int id)
{
    if ( id >= m_iMonStatsCount )
    {
        return NULL;
    }

    return m_astMonStats[id].vId;
}

static int MonStats_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( !strcmp(acKey, "BaseId") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vBaseId);

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
    else if ( !strcmp(acKey, "NextInClass") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vNextInClass);

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
    else if ( !strcmp(acKey, "NameStr") )
    {
        pcResult = String_FindString(pstLineInfo->vNameStr, NULL);

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
    else if ( !strcmp(acKey, "DescStr") )
    {
        pcResult = String_FindString(pstLineInfo->vDescStr, "dummy");

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
    else if ( !strcmp(acKey, "MonSound") )
    {
        pcResult = MonSounds_GetItemSoundsCode(pstLineInfo->vMonSound);

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
    else if ( !strcmp(acKey, "UMonSound") )
    {
        pcResult = MonSounds_GetItemSoundsCode(pstLineInfo->vUMonSound);

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
    else if ( !strcmp(acKey, "MonStatsEx") )
    {
        pcResult = MonStats2_GetStatsName(pstLineInfo->vMonStatsEx);

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
    else if ( !strcmp(acKey, "MonProp") )
    {
        pcResult = MonProp_GetPropId(pstLineInfo->vMonProp);

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
    else if ( !strcmp(acKey, "MonType") )
    {
        pcResult = MonType_GetType(pstLineInfo->vMonType);

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
    else if ( !strcmp(acKey, "AI") )
    {
        pcResult = MonAi_GetAiName(pstLineInfo->vAI);

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
    else if ( !strcmp(acKey, "spawn") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vspawn);

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
    else if ( !strcmp(acKey, "spawnmode") )
    {
        pcResult = MonMode_GetCode(pstLineInfo->vspawnmode);

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
    else if ( !strcmp(acKey, "minion1") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vminion1);

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
    else if ( !strcmp(acKey, "minion2") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vminion2);

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
    else if ( !strcmp(acKey, "MissA1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissA1);

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
    else if ( !strcmp(acKey, "MissA2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissA2);

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
    else if ( !strcmp(acKey, "MissS1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissS1);

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
    else if ( !strcmp(acKey, "MissS2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissS2);

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
    else if ( !strcmp(acKey, "MissS3") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissS3);

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
    else if ( !strcmp(acKey, "MissS4") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissS4);

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
    else if ( !strcmp(acKey, "MissC") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissC);

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
    else if ( !strcmp(acKey, "MissSQ") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vMissSQ);

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
    else if ( !strcmp(acKey, "TreasureClass1") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass1);

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
    else if ( !strcmp(acKey, "TreasureClass2") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass2);

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
    else if ( !strcmp(acKey, "TreasureClass3") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass3);

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
    else if ( !strcmp(acKey, "TreasureClass4") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass4);

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
    else if ( !strcmp(acKey, "TreasureClass1(N)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass1mybr1Nmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass2(N)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass2mybr1Nmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass3(N)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass3mybr1Nmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass4(N)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass4mybr1Nmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass1(H)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass1mybr1Hmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass2(H)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass2mybr1Hmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass3(H)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass3mybr1Hmybr2);

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
    else if ( !strcmp(acKey, "TreasureClass4(H)") )
    {
        pcResult = TreasureClassEx_GetItemTreasureClass(pstLineInfo->vTreasureClass4mybr1Hmybr2);

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
    else if ( !strcmp(acKey, "SkillDamage") )
    {
        pcResult = Skills_GetSkillName(pstLineInfo->vSkillDamage);

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
    else if ( !strcmp(acKey, "El1Mode") )
    {
        pcResult = MonMode_GetCode(pstLineInfo->vEl1Mode);

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
    else if ( !strcmp(acKey, "El2Mode") )
    {
        pcResult = MonMode_GetCode(pstLineInfo->vEl2Mode);

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
    else if ( !strcmp(acKey, "El3Mode") )
    {
        pcResult = MonMode_GetCode(pstLineInfo->vEl3Mode);

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
    else if ( !strcmp(acKey, "El1Type") )
    {
        pcResult = ElemTypes_GetElemStr(pstLineInfo->vEl1Type);

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
    else if ( !strcmp(acKey, "El2Type") )
    {
        pcResult = ElemTypes_GetElemStr(pstLineInfo->vEl2Type);

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
    else if ( !strcmp(acKey, "El3Type") )
    {
        pcResult = ElemTypes_GetElemStr(pstLineInfo->vEl3Type);

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
    else if ( strlen("Skill1") == strlen(acKey) && 1 == sscanf(acKey, "Skill%d", &id) )
    {
        unsigned short *pwSkill = &pstLineInfo->vSkill1;

        pcResult = Skills_GetSkillName(pwSkill[id - 1]);

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
    else if ( strlen("Sk1mode") == strlen(acKey) && 1 == sscanf(acKey, "Sk%dmode", &id) )
    {
        unsigned char *pbType = &pstLineInfo->vSk1modeType;
        unsigned short *pwSkill = &pstLineInfo->vSk1mode;

        if ( 0xFFFF == pwSkill[id - 1] && 0 != pbType[id - 1] )
        {
            pcResult = MonMode_GetCode(pbType[id - 1]);
            if ( pcResult )
            {
                strcpy(acOutput, pcResult);
            }
            else
            {
                acOutput[0] = 0;
            }
        }
        else
        {
            pcResult = MonSeq_GetSequence(pwSkill[id - 1]);

            if ( pcResult )
            {
                strcpy(acOutput, pcResult);
            }
            else
            {
                acOutput[0] = 0;
            }
        }

        result = 1;
    }

    return result;
}

static int MonStats_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "primeevil") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "boss") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "BossXfer") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "SetBoss") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "opendoors") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "noRatio") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "isMelee") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "isSpawn") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined1 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "killable") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "flying") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "demon") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "hUndead") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "lUndead") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "inTown") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "interact") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "npc") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined2 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "placespawn") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "zoo") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "genericSpawn") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "deathDmg") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "petIgnore") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "neverCount") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "nomultishot") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "switchai") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined3 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rangedtype") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined4 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "noAura") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined4 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "NoShldBlock") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined4 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "enabled") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined4 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "inventory") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined4 & 1) != 0);
        result = 1;
    }

    return result;
}

int process_monstats(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hcIdx, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BaseId, USHORT); //monstats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextInClass, USHORT);    //monstats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameStr, USHORT);    //strings

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DescStr, USHORT);    //strings

    //0B
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, primeevil, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, boss, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, BossXfer, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, SetBoss, BitCombined1, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, opendoors, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, noRatio, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, isMelee, BitCombined1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, isSpawn, BitCombined1, BIT);

    //88
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, killable, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, flying, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, demon, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, hUndead, BitCombined2, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, lUndead, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, inTown, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, interact, BitCombined2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, npc, BitCombined2, BIT);

    //41
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, placespawn, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, zoo, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, genericSpawn, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, deathDmg, BitCombined3, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, petIgnore, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, neverCount, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, nomultishot, BitCombined3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, switchai, BitCombined3, BIT);

    //02
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rangedtype, BitCombined4, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, noAura, BitCombined4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, NoShldBlock, BitCombined4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, enabled, BitCombined4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, inventory, BitCombined4, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSound, USHORT);   //monsounds
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UMonSound, USHORT);  //monsounds

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonStatsEx, USHORT); //monstats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonProp, USHORT);    //MonProp

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonType, USHORT);    //montype
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AI, USHORT); //monai

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawn, USHORT);  //monstats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnx, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawny, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnmode, USHORT);  //monmode
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minion1, USHORT);    //monstats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minion2, USHORT);    //monstats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PartyMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PartyMax, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinGrp, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxGrp, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sparsePopulate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Velocity, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Run, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA1, USHORT); //Missiles

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissA2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissS4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissC, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MissSQ, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Align, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TransLvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, threat, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidel, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidelmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidelmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidist, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidistmybr1Nmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aidistmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip1mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip2mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip3mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip4mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip5mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip6mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip7mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aip8mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1, USHORT); //treasureclassex

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3mybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4mybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass1mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass2mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass3mybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass4mybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCQuestId, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TCQuestCP, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drainmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Drainmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlock, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlockmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToBlockmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Crit, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SkillDamage, USHORT);    //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Levelmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minHP, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinHPmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxHP, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxHPmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AC, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1TH, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1THmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1THmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2TH, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2THmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2THmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1TH, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1THmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1THmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Exp, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, A2MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, S1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Mode, UCHAR); //monmode
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Mode, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Mode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Type, UCHAR); //elemtypes
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Type, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Type, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pct, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Pctmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pct, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Pctmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pct, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pctmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Pctmybr1Hmybr2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MinDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MinDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxD, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxDmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2MaxDmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxD, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxDmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3MaxDmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Dur, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Durmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El1Durmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Dur, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Durmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El2Durmybr1Hmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Dur, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Durmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, El3Durmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDm, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDmmybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResDmmybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMa, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMamybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResMamybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFi, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFimybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResFimybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLi, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLimybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResLimybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResCo, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResComybr1Nmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResComybr1Hmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPo, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPomybr1Nmybr2, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResPomybr1Hmybr2, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffect, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffectmybr1Nmybr2, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, coldeffectmybr1Hmybr2, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SendSkills, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, USHORT); //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill6, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill7, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill8, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk1mode, USHORT);   //monseq
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk2mode, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk3mode, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk4mode, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk5mode, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk6mode, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk7mode, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk8mode, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk1lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk2lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk3lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk4lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk5lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk6lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk7lvl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sk8lvl, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRegen, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndDeath, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplGetModeChart, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplEndGeneric, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SplClientEnd, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = MonStats_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            m_iMonStatsCount = 0;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats2, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monsounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monprop, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(montype, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monai, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monmode, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monseq, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(treasureclassex, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = MonStats_FieldProc;
            m_stCallback.pfnConvertValue = MonStats_ConvertValue;
            m_stCallback.pfnBitProc = MonStats_BitProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

