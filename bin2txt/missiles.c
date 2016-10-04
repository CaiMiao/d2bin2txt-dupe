#include "global.h"

#define FILE_PREFIX "missiles"
#define NAME_PREFIX "ml"

/*
Title 	Missiles.txt File Guide v. 2
Description 	by Nefarius and Brother Laz
Sent by 	
Missiles.txt File Guide
By Nefarius and Brother Laz








Initialization

Missile �C ID Pointer, this pointer is used to assign the missile to skills and units (Skills.txt and Monstats.txt), never use the same name twice (it won't cause you to crash, but only the first instance will be used when accessed via txt-linkage, note
, if the ID is different you still can launch the missile via code).

Id �C The actual ID of the missile the pointer above refers to, if you would access your missile via code directly, you would use this! The ID must be different for each missile (ranging between 0 and 32767). You must also take care to not leave gaps 
between IDs, this is known to lead to unexplained errors and other weird behaviour.




Functions

Note: I will not detail any of the missile functions here, I don't have enough experience in this field (and there already is a missile-function guide by Mishy23 -> which you can read by clicking here). You should also be aware that some functions will 
work properly only when linked to a skill, such as homing missiles! - Nefarius

pCltDoFunc �C Client movement function. Defines the graphical behavior of the missile while it is active ("before it vanishes").

pCltHitFunc �C Client collision function. Defines the graphical behaviour of the missile at the moment of collision ("the warhead" if you want to call it that way icon_razz.gif).

pSrvDoFunc �C Server movement function. Defines the actual behavior of the missile while it is active ("before it vanishes"), note, without a matching client function, the effect will not be displayed, for example if it is to launch additional missiles, 
these missiles will be invisible. A "server-side-only" missile cannot initialize any client-side code, thus any missile it will launch will also be invisible!

pSrvHitFunc �C Server collision function. Defines how the missile behaves at the moment of collision, the same rules apply here as they did for the server movement function.

pSrvDmgFunc �C Server damage function. Defines special routines to be done when the missile damages ("hits") a unit. This ranges from stunning units (without using stun damage!) to "damaging" mana instead of life.




Calculations

Note: These columns are only used if the proper functions are called by this missile. Also, all columns preceded by an asterisk ("*") are comment fields!

SrvCalc1 �C This column contains the server movement calculation.

Param1-5 �C These columns contain parameters passed on to the server movement function (these parameters can also be used by the server movement calculation).

CltCalc1 �C This column is the client side equivalent to the SrvCalc1 column.

CltParam1-5 �C These columns are the client side equivalents to the Param1-5 columns. Normally their values should not be different to the Param1-5 columns, some specially client-side effects such as trails will require them to be different however (the 
trails are a client-side only, so they do not need a server part)!

SHitCalc1 �C This column contains the server collision calculation.

sHitPar1-3 �C These columns contain the server collision parameters, as with those for the movement functions, they can be used in the SHitCalc1 field.

CHitCalc1 �C Client side equivalent to SHitCalc1.

cHitPar1-3 �C Client side equivalents to sHitPar1-3 columns.

DmgCalc1 �C Calculation used for damage modifications.

dParam1-2 �C Parameters for the damage functions, can be used in DmgCalc1 column.




Velocity settings

Vel �C Base velocity (the speed this missile starts with), this controls the distance in pixels the missile travels each frame. Speeds near the break point (above 240) cause it to wrap around and move backwards.

MaxVel �C Maximum velocity, this column is used if you use positive acceleration as the speed-limit.

VelLev �C Velocity per unit level (missiles are units), in case the missile is fired by a monster its ulvl is the mlvl of the unit. In case it is fired by a skill function its ulvl is the slvl of the skill. NOTE: This column may or may not have any 
effect, in tests Brother Laz didn't notice a difference.

Accel �C A positive number will make this missile accelerate until its velocity will reach the value in the MaxVel column. A negative value will make the missile slow down until it stands still (0 velocity), you can use this column to cause missiles to 
accelerate past the break point (FF) and thus move in a boomerang fashion (go backwards again). NOTE: Missiles slowing to 0 may not damage anything, you should use a collision function like SFIA or Freezing Arrow to release something else that does 
damage.




Range settings

Range �C The number of frames this missile will exists after being created, see as a "self destruction" timer. One may ask why the missiles must vanish, but imagine missiles flying infinitely into the void, not a good way to manage RAM.

LevRange �C Additional range per unit level. This works exactly like VelLev, but unlike that column, this column here has an effect.




Light settings

Light �C Diameter of the missiles light radius in subtiles.

Flicker �C Random alteratring to light radius diameter (in subtiles), use by fire-effects to cause them to flicker (hence the column name) in the existing radius diameter (IE. it doesn't make the radius any larger).

Red, Green, Blue �C These columns control the RGB color values of the light radius, obviously 255,255,255 = White and so on, to get any other color then white you need to run in Direct3D (note: windowed mode = always directdraw).




Animation settings

InitSteps �C Frames before the missile becomes visible (more technically, frames before the missile is created on the client).

Activate �C This column is used for those missiles created from a central point (holybolts unleashed by the fist of heaven, lightning enchanted boss charged bolts, their scarab equivalent etc), it is also used for missiles that will only damage you 
after you touch them for a longer time (the "fingers" of the death maulers for example). Thus, this column is the server side equivalent to InitSteps, this is the delay in frames before the missile can actually do anything besides existing graphically.

LoopAnim �C Boolean, 1=Repeat this animation for the time of existence (range), 0=Play this animation once and then vanish (warning: the missile will only vanish from the client if the animation is shorter then the range).

CelFile �C The name of the DCC file to used for this missile, the files are stored in dataglobalmissiles, can contain subdirectories.

animrate �C As far as I can say it has no function at all, I have set it to 0 and the animations still played at regular speed (16 frames per second as specified in the AnimSpeed column).

AnimLen �C The length (in frames) of this animation (for a single direction). If you have a missile with 64 frames and 8 directions, you would enter 8 in this column for obvious reasons.

AnimSpeed �C Number of frames played by second, this is not modified by animrate. I don't know why Blizzard has two columns that practically do almost the same, but I assume this is simply a result of the absence of missile *.COF (and thus also *.D2) 
files as the animrate column seams to be ignored (it was in my tests, it is probably there only to avoid crashes in the DCC routines).

RandStart �C Causes the animation to start playing at the specified frame. From the name you would think it controls a random starting frame but it does not, it just causes the animation to start at the specified frame.

SubLoop �C Boolean, 1=This missile will repeat a specific sequence as long as enough range is left, 0=This missile will play it's animation normally (as defined in the LoopAnim column).

SubStart �C Starting frame of the SubLoop.

SubStop �C Ending frame of the SubLoop (when it reaches this frame it will either go back to SubStart frame or it will play on until the missile disappears if not enough range is left)




Collision settings A

CollideType �C Controls the which type of collision to check for, 3=Normal collision, 6=Z-collision (a missile "dropping from above"), 1=Used mostly for missiles that lay on the floor, waiting for the character to walk over them (like spidergoo and 
spikes) NOTE: This is not required for trap missiles, 8=Fire collision (fire walls etc), related to softhit or per-frame-damage setups. Obviously, 0=No collision detection mode. There are at least 3 unused ones (2,5,7). For a better explanation of what 
these types of collision detection mean:

Type Wall-tiles Units Floor-tiles
0 false false false
1 false true false
3 true true false
6 true false false
8 true true true


CollideKill �C Boolean, Will this missile get destroyed upon collision. 1=Always destroy this missile upon collision (overrides almost all other settings, Frozen Orb collision function is known to ignore this column), 0=Don't destroy this missile upon 
collision.

CollideFriend �C Boolean, Can this missile collide with allies (such as holybolt), 1=Allow friendly collision, 0=Disallow friendly collision.

LastCollide �C Unknown to both me and Brother Laz, but this boolean seams to be related to some special behavior on missiles that don't vanish upon collision, such as fire effects and some other effects that are client-side only. In short, it is usually 
enabled only for missiles with a "physical collision effect". - In any event, this column can be left 0, it won't effect anything noticeable.

Collision �C Unknown to both me and Brother Laz, but this boolean is related to the previous one, many missiles that have no "physical collision" but still perform a collision event will have this set to 1 (fire effects). - In any event, this column can 
be left 0, it won't effect anything noticeable.

ClientCol �C Unknown to both me and Brother Laz, I assume this name stands for ClientCollision, but what exactly it handles remains a mystery. - In any event, this column can be left 0, it won't effect anything noticeable.

ClientSend �C Boolean, could be related to updating lifeorb display on the player when walking into firestorm or shock field.

NextHit �C Use collision timer after first collision (1=yes, 0=no), the timer is used to avoid excessive damage (and to annoy players).

NextDelay �C Number of frames to deactivate all server-side collision settings for this missile post collision and to make the attacked unit ignore all subsequent missile attacks. For example, a missile with a NextDelay of 25 will be unable to "damage" 
any target for 1 second after each successful server-side collision. Apparently the monster being hit will also become "immune to missiles" for the duration of this timer.




Size / Coordinate settings

xoffset, yoffset, zoffset �C Shift the placement of this missile by # pixels on the x, y or z axis, point 0 is either the top left corner of the DCC or the pivot (I haven't tested enough to be sure).

Size �C Diameter in subtiles. Probably works identical to the size settings in MonStats2.txt from -1 to 3. Basically 1=Fills only 1 subtile, 2=Fills 4 subtiles, 3=Fills 9 subtiles.




Unknown settings

SrcTown - boolean, most likely controls whenever a missile vanishes when the person goes to a town via a TP ("PK trapping preventation), it is enabled only for missiles that can be used to trap a way point for example (fire walls and such effects).

CltSrcTown �C Used together with the above, probably controls some graphical aspects of the vanishing (the number may control a frame, but this is just a wild guess.

CanDestroy �C unknown (boolean).




Collision settings B

ToHit �C Does this missile use Attack Rating ("chance to hit") or does it "always" (it's 95% actually) hit ("guided arrow behaviour"). You can easily make all missiles require Attack Rating by changing this boolean column to true (1). Whenever it uses 
the additional AR given by skills.txt is unknown, Brother Laz noticed that even the regular vanilla elemental arrows may be bugged and ignore their AR bonus (spankyou very much Blizzard).

AlwaysExplode �C Will this missile always call it's Collision Functions when it is destroyed. 1=Yes, 0=No. (For example, Frozen Orb will always explode into a nova, even if it just runs out of range). Some collision functions, such as the Lightning Fury 
collision, will ignore this column and always explode server-side...




Misc. settings and flags (mostly booleans)

Explosion �C Boolean, 1=Is an explosion (meaning that it does not exist on the server, this will override all other settings!), 0=Is not an explosion.

Town �C Boolean, 1=Does not vanish when spawned inside a town, 0=Vanishes when spawned inside a town (such as the trails left by the Druid's vines).

NoUniqueMod �C Boolean, 1=Does not get bonuses from boss modifiers (such as fire damage if the boss spawns as Fire Enchanted), 0=Receives all bonuses applicable.

NoMultiShot �C Boolean, 1=Is not effected by the multishot modifier of bosses, 0=Is effected by the multishot modifier of bosses as usual. Note: Blizzard forgot to enable this on some boss-death events, such as Shenk...

Holy �C Flag, controls which units this missile can hit, 0=All units, 1=Only undead, 2=Only demons, 3=All units. �C I didn't test this extensively, done from memory.

CanSlow �C Boolean, 1=Is effected by skill_handofathena stat (slow missiles), 0=Is not effected by skill_handofathena stat.

ReturnFire �C Boolean, 1=Can trigger "collision events" on the target, 0=Cannot trigger collision events on the target. *Collision events are all those things that happen "upon getting hit" for example. Blizzard erroneously enabled this on the Arctic 
Blast used by the Frozen Horrors and Nihlathak. NOTE: May or may not effect other "on hit" events, such as casting a skill or "thorns".

GetHit �C Boolean, 1=Can knock the target into GH mode ("hit recovery") upon collision, 0=Never knock target into GH mode upon collision.

SoftHit �C Boolean, unknown, used only for Shockfield on Ground and Firestorn, Apparently this setting handles the frequency of the unit being "visually" hurt by the missile (probably the unit's lifebar being updated, which was bugged originally).

KnockBack �C Percentage chance (0-100) to knock target back, the default is 0 obviously, if you enter 100 in here the target will always be knocked back after every single successful collision.

Trans �C Not a boolean, 0=Draw graphic normally, 1=Alpha-blending ("the darker the areas are the more transparent they become"), 2=Special blending mode (usually causes the missile to display black-and-white).

Qty �C Does this missile use up quantity (1=use quantity, 0=don't use quantity). NOTE: This requires a special starting function in skills.txt to work. Also, if you enable this for strafe for example, it will use the number of missiles it actually fires 
rather then a constant 1

Pierce �C Is this missile effected by pierce (1=effected by pierce, 0=not effected by pierce). This refers to the "pierce" modifier and to the Amazon skill Pierce.

SpecialSetup �C Boolean, unknown, enabled only for potions. I am unsure what this controls, the "arc" is not handled by this, there is a special check in code for potion itype. Maybe this has to do with displaying correct missile damage in weapons.txt?





Skill settings

MissileSkill �C Boolean, used to transfer elemental damage from items to the splash radius of the missile and to diss all other damage modifiers (ever wondered why Freezing Arrow has SrcDmg set to 128 in skills.txt, yet the splash radius does no 
physical damage?).

Skill �C If you enter the ID Pointer ("the name") of a skill here this missile will retrieve all of it's damage/hit data from this skill. The columns being read from skills.txt instead of missiles.txt are the following: ResultFlags, HitFlags, HitShift, 
HitClass, SrcDamage (SrcDam in skills.txt!), MinDam, MinLevDam1-5, MaxDam, MaxLevDam1-5, DmgSymPerCalc, EType, EMin, EMinLev1-5, EMax, EMaxLev1-5, EDmgSymPerCalc, ELen, ELenLev1-3, ELenSymPerCalc.





Event flags

ResultFlags �C unknown (to both of us). 4=Used for normal missiles, 5=Used for explosions (all things with HitFlags of 2!), 8=Used for missiles that never damage anything. Most likely behaves similar to CollideType but what it really does...

HitFlags �C unknown, 2=Used for explosions, 5=Used for freezing arrow. This could play a more important role then originally expected. Likely related to "splash damage elemental carry over" mentioned further above (MissileSkill).




Damage settings

HitShift �C this is a "damage divisor", damage, as well as hitpoints, mana and stamina is handled in 256ths. 8=256/256, 7=128/256, 6=64/256, 5=32/256, 4=16/256, 3=8/256, 2=4/256, 1=2/256, 0=1/256. This roughly equals: 100%, 50%, 25%, 12.5%, 6.25%, 3.125%
, 1.5625%, 0.78125% and 0.390625% of the actual damage.

ApplyMastery �C Used only for MeteorFire and VampireMeteorFire. Most likely used to boost the damage of these unlinked missiles via mastery bonuses..

SrcDamage �C "Source Damage", this controls whenever the game should append the source units attack properties to the missile or not. Thi column is using 128ths (128=100%). This does not only reflect damage, but all other modifiers related to attack, 
including lifesteal and manasteal. Set this to -1 (poison clouds) to get rid of SrcDmg from skills.txt.

Half2HSrc �C Boolean, 1=Halven damage when a two handed weapon is used, 0=Keep full damage when a two handed weapon is used.

SrcMissDmg �C Used only for the poison clouds created by the expansion Viper's poison javelin I assume this tells it how much damage it should carry over from the base missile.

MinDamage, MaxDamage �C Basic minimum and maximum physical damage of this missile.

MinLevDam1-5, MaxLevDam1-5 �C Additional physical damage to deal out per missile level (the unit level of the missile, either equal to the attacker's level or to the skill level). The range is: ulvl 2-8, ulvl 9-16, ulvl 17-22, ulvl 23-28 and ulvl 29+

DmgSymPerCalc �C Physical damage synergy, works just like the synergy column in skills.txt, only that it has much fewer functions, AFAIK it only supports getting skill level, not way to obtain stat values etc.

EType �C Elemental damage type. fire, ltng (Lightning), mag (Magic), cold, pois (Poison), life (Life-steal), mana (Mana-steal), stam (Stamina-steal), stun (note, "stun damage" is ignored, stun uses only duration), rand (either lightning, fire, cold or 
poison �C picked at every successful hit), burn (Burning damage, bugged, gives no EXP from kills, otherwise works like poison, you need to have low HitShift to make it work properly!), frze (Freeze, by itself this is handled like cold damage, you need 
to use special server damage functions to actually cause the unit to become frozen solid).

EMin, EMax �C Just like MinDamage and MaxDamage, just for elemental damage (duh).

MinELev1-5, MaxELev1-5 �C I doubt I have to explain this. This is like MinLevDam1-5 and MaxLevDam1-5, just for elemental damage.

EDmgSymPerCalc �C Same as DmgSymPerCalc, just for elemental damage.

ELen �C Duration (used for stun, poison and burning damage), the duration is handled in frames, 25=1 second.

ELevLen1-3 �C Extra duration per missile unit level. (check intervals)




Misc. Settings

HitClass �C Hit classes are a rather "enigmatic" part of D2, but they are technically just client side effects for collisions. For example the Hit class #6 is responsible for the "pierce noise" when a throwing weapon hits something. #10 is probably the 
same just for "smaller piercing missiles" like Arrows. #2 is used for throwing axes, #64 causes the "electric sound" (used for lightning based missiles to make that special sound), #32 is used for fire walls and the like, #176 for liquid attacks (slime-
missiles for example), #80 is used for Poison Nova, #48 for some cold effects. The hitclasses used in other txt files (MonStats2.txt, Skills.txt and possibly others that I forgot) can also be used here.

NumDirections �C Number of directions of the DCC file loaded via the CelFile column. Make sure this matches the DCC to avoid crashes and the like. NOTE: Brother Laz says that this column is of no importance, I personally remember getting crashes in pre 1
.09 days, so ignore this column or fill it, it seams more important that the "Length" column is correct, probably like animrate, which is only there to avoid internal conflicts due to the absence of COF files.

LocalBlood �C Related to skills that cause blood to be spilled around. 0=Can't bleed, 1=Can it bleed, 2=Can it bleed and is it effected by open wounds.

DamageRate �C How does this missile handle magic_damage_reduced stat. An empty column means the effect is applied completely every single frame. Blizzard added this to avoid people from almost nullifying fire wall damage with just 5+ Magic Damage 
reducing items. (Get detailed formula)





Client side settings A: Sounds

TravelSound �C ID Pointer from Sounds.txt to the WAV file the game plays when the missile is created. This is also used for sound effects that should loop for the time of the missiles existence. NOTE: Using looping sounds here can cause crashes (don't 
use long looping sound effects such as Music).

HitSound �C ID Pointer from Sounds.txt to the WAV file the game plays when the missile collides with a target.

ProgSound �C ID Pointer from Sounds.txt to the WAV file the game plays at special events, defined by the client side functions related to collisions.




Client side settings B: Graphics

ProgOverlay �C ID Pointer from Overlays.txt for the DCC file to use as an overlay for special events defined by the client side functions related to collisions.

ExplosionMissile �C The ID pointer from Missiles.txt for the explosion to create upon collision, this is only created if the missile successfully collides with a unit or an obstacle (what it can collide with is controlled by CollideType) or when 
AlwaysExplode is enabled..




Appended missiles

Note: These columns are only accessed if the movement or collision functions use them! Also, all these columns use ID Pointers ("names")

SubMissile1-3 �C Server part of the missiles spawned by the movement function.

HitSubMissile1-3 �C Server part of the missiles spawned by the collision function.

CltSubMissile1-3 �C Client part of SubMissile1-3.

CltHitSubMissile1-3 �C Client part of HitSubMissile1-3.





Line terminator

EOL �C End of Line, must be set to 0 if you use M$ Excel, to prevent it from blowing up the table.

*/

/*
�ļ���������
missile�������������
���ļ���¼����Ϸ�����з��������Ϣ��ÿһ�б�ʾһ�ַ����


�ظ�

    2¥
    2012-01-12 20:55

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2012-01-12 20:55

    �ٱ� |

    �Ұ�Ƥ���
    ����֮ʯ
    10

��֮


�ظ�

    4¥
    2012-01-12 20:55

    �ٱ� |

    zqtjingzi
    С����
    12

Missile������������������

Id������������������

pCltDoFunc���˷�����Ŀͻ����ƶ�������

pCltHitFunc���˷�����Ŀͻ�����ײ������

pSrvDoFunc���˷�����ķ��������ƶ�������

pSrvHitFunc���˷�����ķ���������ײ������

pSrvDmgFunc���˷�����������˺����㺯����

SrvCalc1�����������ƶ���������ļ��㹫ʽ��

Param1-5�����������ƶ���������Ĳ�����

CltCalc1���ͻ����ƶ���������ļ��㹫ʽ��

CltParam1-5���ͻ����ƶ���������Ĳ�����

SHitCalc1������������ײ��������ļ��㹫ʽ��

sHitPar1-3������������ײ��������Ĳ�����

CHitCalc1���ͻ�����ײ��������ļ��㹫ʽ��

cHitPar1-3���ͻ�����ײ��������Ĳ�����

DmgCalc1�������˺����㺯������ļ��㹫ʽ��

dParam1-2�������˺����㺯������Ĳ�����


�ظ�

    5¥
    2012-01-12 20:55

    �ٱ� |

    zqtjingzi
    С����
    12

Vel���˷�����Ļ����ٶȡ�

MaxVel���˷����������ٶȡ�

VelLev���˷�������ȼ����ӵ��ٶȡ����������ƺ�û��Ч����

Accel���˷�����ļ��ٶȡ�����ٶ���MaxVel����С�ٶ�Ϊ0��

Range���˷��������������֡Ϊ��λ��

LevRange���˷�����ÿ���һ�����ӵ�������

Light���˷������������Χ��

Flicker���˷���������˸ʱ���ӵ�������Χ��ʵ����û�в��Գ�Ч����

Red/Green/Blue��������Χ�ڵĹ�����ɫ��

InitSteps���˷������ڿɼ�֮ǰ��׼��������֡����

Activate���˷������ڷ�������֮ǰ��׼��������֡����

LoopAnim������ֵ���Ƿ�����������ǰѭ���ظ������ﶯ����

CelFile���˷���������ͼƬ��

animrate������δ֪��

AnimLen���˷�������ÿ�������ϵĶ���֡����

AnimSpeed�������ٶȣ�ÿ�벥��֡����

RandStart��������ʼ֡�š�

SubLoop������ֵ���Ƿ�����ѭ��������

SubStart����ѭ������ʼ֡�š�

SubStop����ѭ���Ľ�������


�ظ�

    6¥
    2012-01-12 20:56

    �ٱ� |

    zqtjingzi
    С����
    12

CollideType����ײ���͡�������ײЧ�����£�
���ͺ� ǽ ��λ ����
0 �� �� ��
1 �� �� ��
3 �� �� ��
6 �� �� ��
8 �� �� ��

CollideKill������ֵ���˷������Ƿ����Ϊ��ײ��ʧ��

CollideFriend������ֵ���˷������Ƿ����ͬ���߷�����ײ��

LastCollide������δ֪��

Collision������δ֪��

ClientCol������δ֪��

ClientSend������ֵ���Ƿ���Ҫ�����˷�����Ϣ��

NextHit������ֵ���Ƿ���еڶ����ӳ�Ч����

NextDelay���ڶ����ӳ�Ч����֡����

x/y/z offset��x/y/z�����ϵ�ƫ�ơ�

Size���˷�����Ĵ�С��

SrcTown������δ֪

CltSrcTown������δ֪��

CanDestroy������δ֪��

ToHit���˷������Ƿ�ʹ�ù���׼ȷ�����ԡ�

AlwaysExplode������ֵ���˷����ﱻ�ݻ�ʱ�Ƿ��ܻᴥ����ײ������

Explosion������ֵ���Ƿ��Ǳ�ը�����

Town������ֵ���Ƿ����ڳ��ڴ��ڡ�

NoUniqueMod������ֵ���Ƿ񲻱���ֽ�������Ӱ�졣

NoMultiShot������ֵ���Ƿ񲻱������������Ӱ�졣


�ظ�

    7¥
    2012-01-12 20:56

    �ٱ� |

    s420295286
    �ػ���ʹ
    12



�ظ�

    8¥
    2012-01-12 20:56

    �ٱ� |

    zqtjingzi
    С����
    12

Holy���˷��������ʥ���ԡ������������£�
0����������ʥ���ԡ�
1�����Ӳ�������Ŀ��ԡ�
2�����Ӷ�ħ����Ŀ��ԡ�
3�����Ӳ�������Ͷ�ħ����Ŀ��ԡ�

CanSlow������ֵ���Ƿ�ᱻ���ټ����ܼ��١�

ReturnFire������ֵ���Ƿ�ᴥ��Ŀ�����ײ�¼����类�����¼�����

GetHit������ֵ���Ƿ�����Ŀ����д��״̬��

SoftHit������δ֪��

KnockBack������Ŀ��ļ��ʡ�

Trans����ʾ������

Qty������ֵ���˷������Ƿ������������

Pierce������ֵ���˷������Ƿ��ܴ���Ч��Ӱ�졣

SpecialSetup������δ֪��

MissileSkill������ֵ���Ƿ�Ա�ը��Χ�ڵ�Ŀ��ֻ���Ԫ���˺���

Skill���Ƿ�ʹ�ö�Ӧ���ܵ����ԣ����˺����������ͣ���

ResultFlags������δ֪��

HitFlags������δ֪��

HitShift���˺��������ӡ���ȡ��������λ��ʽ���з�����
0 = 1/256
1 = 2/256
2 = 4/256...8 = 256/256
9 = 512/256

ApplyMastery������ֵ���Ƿ�ʹ��Ԫ��֧����˺�����������

SrcDamage����ͨ�����˺����ӱ�������������Ϊ128��

Half2HSrc������ֵ����װ��˫������ʱ�Ƿ��˺����롣

SrcMissDmg���μ��������ϸ��ӳ�ʼ�������˺��ı������޸����о���ȥ��bug�߶��Ƽ����е������˺���


�ظ�

    9¥
    2012-01-12 20:56

    �ٱ� |

    zqtjingzi
    С����
    12

MinDamage����ʼ��С�����˺�ֵ��

MinLevDam1-5��ÿ�����ӵ���С�����˺�ֵ��

MaxDamage����ʼ����˺�ֵ��

MaxLevDam1-5��ÿ�����ӵ�����˺�ֵ��

DmgSymPerCalc�������˺��ӳɼ��㹫ʽ��

EType��Ԫ���˺������ElemTypes.txt������

EMin����ʼԪ���˺���Сֵ��

MinELev1-5��ÿ�����ӵ�Ԫ���˺���Сֵ��

EMax����ʼԪ���˺����ֵ��

MaxELev1-5��ÿ�����ӵ�Ԫ���˺����ֵ��

EDmgSymPerCalc��Ԫ���˺��ӳɼ��㹫ʽ��

ELen��Ԫ���˺�Ч���ĳ���֡����

ELevLen1-3��ÿ�����ӵ�Ԫ���˺�Ч������֡����


�ظ�

    10¥
    2012-01-12 20:57

    �ٱ� |

    zqtjingzi
    С����
    12

HitClass���������

NumDirections�����ܵĳ�������

LocalBlood����Ѫ״̬��

DamageRate�����˺��������Ե���Ӧ��

TravelSound������ʱ��������

HitSound����ײ���������

ProgSound�������¼�ʱ��������

ProgOverlay�������¼�ʱ����ʾЧ����

ExplosionMissile����ײʱ�����Ĵμ������

SubMissile1-3�����������ƶ��������ͷŵĴμ������

HitSubMissile1-4������������ײ�������ͷŵĴμ������

CltSubMissile1-3���ͻ����ƶ��������ͷŵĴμ������

CltHitSubMissile1-4���ͻ�����ײ�������ͷŵĴμ������

EOL����β��־������Ϊ0��

*/

typedef struct
{
    unsigned int vId;

#if 1
    unsigned short vBitCombined;
#else
    unsigned short vMissileSkill : 1;
    unsigned short vHalf2HSrc : 1;
    unsigned short vNoUniqueMod : 1;
    unsigned short vNoMultiShot : 1;
    unsigned short vSrcTown : 1;
    unsigned short vTown : 1;
    unsigned short vReturnFire : 1;
    unsigned short vApplyMastery : 1;
    unsigned short vSoftHit : 1;
    unsigned short vGetHit : 1;
    unsigned short vClientSend : 1;
    unsigned short vCanDestroy : 1;
    unsigned short vCanSlow : 1;
    unsigned short vPierce : 1;
    unsigned short vExplosion: 1;
    unsigned short vLastCollide : 1;
#endif

    unsigned short wPadding;

    unsigned short vpCltDoFunc;
    unsigned short vpCltHitFunc;

    unsigned short vpSrvDoFunc;
    unsigned short vpSrvHitFunc;

    unsigned short vpSrvDmgFunc;
    unsigned short vTravelSound;    //sounds.txt

    unsigned short vHitSound;       //sounds.txt
    unsigned short vExplosionMissile;   //��Ӧ����

    unsigned short vSubMissile1;   //��Ӧ����
    unsigned short vSubMissile2;   //��Ӧ����

    unsigned short vSubMissile3;   //��Ӧ����
    unsigned short vCltSubMissile1;   //��Ӧ����

    unsigned short vCltSubMissile2;   //��Ӧ����
    unsigned short vCltSubMissile3;   //��Ӧ����

    unsigned short vHitSubMissile1;   //��Ӧ����
    unsigned short vHitSubMissile2;   //��Ӧ����

    unsigned short vHitSubMissile3;   //��Ӧ����
    unsigned short vHitSubMissile4;   //��Ӧ����

    unsigned short vCltHitSubMissile1;   //��Ӧ����
    unsigned short vCltHitSubMissile2;   //��Ӧ����

    unsigned short vCltHitSubMissile3;   //��Ӧ����
    unsigned short vCltHitSubMissile4;   //��Ӧ����

    unsigned short vProgSound;      //sounds.txt
    unsigned short vProgOverlay;    //56 bytes����Ӧoverlay.txt

    int vParam1;
    int vParam2;
    int vParam3;
    int vParam4;
    int vParam5;

    int vsHitPar1;
    int vsHitPar2;
    int vsHitPar3;

    int vCltParam1;
    int vCltParam2;
    int vCltParam3;
    int vCltParam4;
    int vCltParam5;

    int vcHitPar1;
    int vcHitPar2;
    int vcHitPar3;

    int vdParam1;
    int vdParam2;  //128 bytes

    unsigned int vSrvCalc1; //misscode
    unsigned int vCltCalc1;
    unsigned int vSHitCalc1;
    unsigned int vCHitCalc1;
    unsigned int vDmgCalc1;

    unsigned short vHitClass;
    unsigned short vRange;

    unsigned short vLevRange;
    unsigned char vVel;
    unsigned char vVelLev;

    unsigned short vMaxVel;
    short vAccel;  //160 bytes

    unsigned short vanimrate;
    short vxoffset;

    short vyoffset;
    short vzoffset;

    unsigned int vHitFlags;

    unsigned short vResultFlags;
    unsigned char vKnockBack;
    char bPadding3; //176 bytes

    unsigned int vMinDamage;
    unsigned int vMaxDamage;
    unsigned int vMinLevDam1;
    unsigned int vMinLevDam2;
    unsigned int vMinLevDam3;
    unsigned int vMinLevDam4;
    unsigned int vMinLevDam5;
    unsigned int vMaxLevDam1;
    unsigned int vMaxLevDam2;
    unsigned int vMaxLevDam3;
    unsigned int vMaxLevDam4;
    unsigned int vMaxLevDam5;

    unsigned int vDmgSymPerCalc;    //misscode

    unsigned int vEType;   //��Ӧelemtypes������

    unsigned int vEMin;
    unsigned int vEmax;
    unsigned int vMinELev1;
    unsigned int vMinELev2;
    unsigned int vMinELev3;
    unsigned int vMinELev4;
    unsigned int vMinELev5;
    unsigned int vMaxELev1;
    unsigned int vMaxELev2;
    unsigned int vMaxELev3;
    unsigned int vMaxELev4;
    unsigned int vMaxELev5; //280 bytes

    unsigned int vEDmgSymPerCalc;   //misscode

    unsigned int vELen;
    unsigned int vELevLen1;
    unsigned int vELevLen2;
    unsigned int vELevLen3;  //300 bytes

    unsigned char vCltSrcTown; 
    unsigned char vSrcDamage;
    unsigned char vSrcMissDmg;
    unsigned char vHoly;

    unsigned char vLight;
    unsigned char vFlicker;
    unsigned char vRed;
    unsigned char vGreen;

    unsigned char vBlue;
    unsigned char vInitSteps;
    unsigned char vActivate;
    unsigned char vLoopAnim;    //312 bytes

    unsigned char vCelFile[64];

    unsigned int vAnimLen;
    unsigned int vRandStart;

    unsigned char vSubLoop;
    unsigned char vSubStart;
    unsigned char vSubStop;
    unsigned char vCollideType;

    unsigned char vCollision;
    unsigned char vClientCol;
    unsigned char vCollideKill;
    unsigned char vCollideFriend;

    unsigned char vNextHit;
    unsigned char vNextDelay;
    unsigned char vSize;
    unsigned char vToHit;

    unsigned char vAlwaysExplode;
    unsigned char vTrans;
    unsigned short vQty;

    unsigned int vSpecialSetup;

    unsigned short vSkill;  //��Ӧskills.txt
    unsigned short vHitShift;

    unsigned int iPadding3;

    unsigned int vDamageRate;

    unsigned char vNumDirections;
    unsigned char vAnimSpeed;   //418 bytes
    unsigned char vLocalBlood;
    unsigned char bUnKnown2;
} ST_LINE_INFO; //420 bytes

typedef struct
{
    unsigned char vMissile[32];
} ST_MISSILES;

static char *m_apcNotUsed[] = 
{
    "*srv calc 1 desc",
    "*param1 desc",
    "*param2 desc",
    "*param3 desc",
    "*param4 desc",
    "*param5 desc",
    "*client calc 1 desc",
    "*client param1 desc",
    "*client param2 desc",
    "*client param3 desc",
    "*client param4 desc",
    "*client param5 desc",
    "*server hit calc 1 desc",
    "*server hit param1 desc",
    "*server hit param2 desc",
    "*server hit param3 desc",
    "*client hit calc1 desc",
    "*client hit param1 desc",
    "*client hit param2 desc",
    "*client hit param3 desc",
    "*damage calc 1",
    "*damage param1 desc",
    "*damage param2 desc",
    NULL,
};

static char *m_apcInternalProcess[] = 
{
    "Missile",
    "EOL",
    NULL,
};

static unsigned int m_iMisslesCount = 0;
static ST_MISSILES *m_astMissiles = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astMissiles, ST_MISSILES);

static int Missiles_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Missile") )
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

        strncpy(m_astMissiles[m_iMisslesCount].vMissile, acOutput, sizeof(m_astMissiles[m_iMisslesCount].vMissile));
        String_Trim(m_astMissiles[m_iMisslesCount].vMissile);
        m_iMisslesCount++;
        return 1;
    }
    else if ( !strcmp(acKey, "EOL") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int Missiles_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Missile") )
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
    else if ( !strcmp(acKey, "EOL") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

char *Missiles_GetMissile(unsigned int id)
{
    if ( id >= m_iMisslesCount )
    {
        return NULL;
    }

    return m_astMissiles[id].vMissile;
}

static int Missiles_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "MissileSkill") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 15)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Half2HSrc") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 14)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "NoUniqueMod") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 13)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "NoMultiShot") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 12)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "SrcTown") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 11)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Town") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 10)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "ReturnFire") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 9)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "ApplyMastery") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 8)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "SoftHit") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "GetHit") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "ClientSend") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "CanDestroy") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "CanSlow") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Pierce") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "Explosion") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "LastCollide") )
    {
        sprintf(acOutput, "%d", ((pstLineInfo->vBitCombined & 1)) != 0);
        result = 1;
    }

    return result;
}

static int Missiles_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "ExplosionMissile") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vExplosionMissile);
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
    else if ( !strcmp(acKey, "SubMissile1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vSubMissile1);
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
    else if ( !strcmp(acKey, "SubMissile2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vSubMissile2);
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
    else if ( !strcmp(acKey, "SubMissile3") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vSubMissile3);
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
    else if ( !strcmp(acKey, "HitSubMissile1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vHitSubMissile1);
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
    else if ( !strcmp(acKey, "HitSubMissile2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vHitSubMissile2);
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
    else if ( !strcmp(acKey, "HitSubMissile3") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vHitSubMissile3);
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
    else if ( !strcmp(acKey, "HitSubMissile4") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vHitSubMissile4);
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
    else if ( !strcmp(acKey, "CltSubMissile1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltSubMissile1);
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
    else if ( !strcmp(acKey, "CltSubMissile2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltSubMissile2);
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
    else if ( !strcmp(acKey, "CltSubMissile3") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltSubMissile3);
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
    else if ( !strcmp(acKey, "CltHitSubMissile1") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltHitSubMissile1);
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
    else if ( !strcmp(acKey, "CltHitSubMissile2") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltHitSubMissile2);
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
    else if ( !strcmp(acKey, "CltHitSubMissile3") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltHitSubMissile3);
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
    else if ( !strcmp(acKey, "CltHitSubMissile4") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vCltHitSubMissile4);
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
    else if ( !strcmp(acKey, "ProgOverlay") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->vProgOverlay);
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
    else if ( !strcmp(acKey, "EType") )
    {
        pcResult = ElemTypes_GetElemStr(pstLineInfo->vEType);
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
    else if ( !strcmp(acKey, "TravelSound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vTravelSound);
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
    else if ( !strcmp(acKey, "HitSound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vHitSound);
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
    else if ( !strcmp(acKey, "ProgSound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vProgSound);
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
    else if ( !strcmp(acKey, "SrcDamage") )
    {
        if ( 0xFF == pstLineInfo->vSrcDamage )
        {
            strcpy(acOutput, "-1");
            result = 1;
        }
    }
    else if ( !strcmp(acKey, "Skill") )
    {
        pcResult = Skills_GetSkillName(pstLineInfo->vSkill);
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
    else if ( !strcmp(acKey, "SrvCalc1") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vSrvCalc1);
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
    else if ( !strcmp(acKey, "CltCalc1") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vCltCalc1);
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
    else if ( !strcmp(acKey, "SHitCalc1") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vSHitCalc1);
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
    else if ( !strcmp(acKey, "CHitCalc1") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vCHitCalc1);
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
    else if ( !strcmp(acKey, "DmgCalc1") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vDmgCalc1);
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
    else if ( !strcmp(acKey, "DmgSymPerCalc") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vDmgSymPerCalc);
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
    else if ( !strcmp(acKey, "EDmgSymPerCalc") )
    {
        pcResult = MissCode_GetExpression(pstLineInfo->vEDmgSymPerCalc);
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

int process_missiles(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UINT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, MissileSkill, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Half2HSrc, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, NoUniqueMod, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, NoMultiShot, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, SrcTown, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Town, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, ReturnFire, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, ApplyMastery, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, SoftHit, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, GetHit, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, ClientSend, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, CanDestroy, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, CanSlow, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Pierce, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, Explosion, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, LastCollide, BitCombined, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pCltDoFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pCltHitFunc, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvDoFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvHitFunc, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pSrvDmgFunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TravelSound, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSound, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExplosionMissile, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile2, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubMissile3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile1, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile3, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitSubMissile4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile1, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSubMissile3, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile2, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltHitSubMissile4, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ProgSound, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ProgOverlay, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Param5, INT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sHitPar3, INT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltParam5, INT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cHitPar3, INT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dParam2, INT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitClass, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Range, USHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevRange, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VelLev, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxVel, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Accel, SHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, animrate, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, xoffset, SHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, yoffset, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, zoffset, SHORT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitFlags, UINT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResultFlags, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KnockBack, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxDamage, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinLevDam5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxLevDam5, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EType, UINT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Emax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MinELev5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxELev5, UINT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ELevLen3, UINT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltSrcTown, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcDamage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrcMissDmg, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Holy, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Light, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Flicker, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InitSteps, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Activate, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LoopAnim, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CelFile, STRING);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimLen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RandStart, UINT);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubLoop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStart, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubStop, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideType, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Collision, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ClientCol, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideKill, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CollideFriend, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextHit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NextDelay, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Size, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHit, UCHAR);
    
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AlwaysExplode, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Trans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Qty, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SpecialSetup, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HitShift, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DamageRate, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumDirections, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LocalBlood, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AnimSpeed, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SrvCalc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CltCalc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SHitCalc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CHitCalc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgCalc1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgSymPerCalc, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EDmgSymPerCalc, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = Missiles_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            m_iMisslesCount = 0;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(elemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);

            if ( 0 == MissCode_ParseBin(acTemplatePath, acBinPath, acTxtPath) )
            {
                return 0;
            }
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = Missiles_FieldProc;
            m_stCallback.pfnConvertValue = Missiles_ConvertValue;
            m_stCallback.pfnBitProc = Missiles_BitProc;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

