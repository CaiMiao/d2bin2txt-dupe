#include "global.h"

#define FILE_PREFIX "levels"
#define BIN_TEMP    "temp_"
#define NAME_PREFIX "lv"

/*
struct D2LevelDefBin
{
   DWORD dwQuestFlag;               //0x00
   DWORD dwQuestFlagEx;            //0x04
   DWORD dwLayer;                  //0x08
   DWORD dwSizeX;                  //0x0C
   DWORD dwSizeX_N;               //0x10
   DWORD dwSizeX_H;               //0x14
   DWORD dwSizeY;                  //0x18
   DWORD dwSizeY_N;               //0x1C
   DWORD dwSizeY_H;               //0x20
   DWORD dwOffsetX;               //0x24
   DWORD dwOffsetY;               //0x28
   DWORD dwDepend;                  //0x2C
   DWORD dwDrlgType;               //0x30
   DWORD dwLevelType;               //0x34
   DWORD dwSubType;               //0x38
   DWORD dwSubTheme;               //0x3C
   DWORD dwSubWaypoint;            //0x40
   DWORD dwSubShrine;               //0x44
   DWORD dwVis0;                  //0x48
   DWORD dwVis1;                  //0x4C
   DWORD dwVis2;                  //0x50
   DWORD dwVis3;                  //0x54
   DWORD dwVis4;                  //0x58
   DWORD dwVis5;                  //0x5C
   DWORD dwVis6;                  //0x60
   DWORD dwVis7;                  //0x64
   DWORD dwWarp0;                  //0x68
   DWORD dwWarp1;                  //0x6C
   DWORD dwWarp2;                  //0x70
   DWORD dwWarp3;                  //0x74
   DWORD dwWarp4;                  //0x78
   DWORD dwWarp5;                  //0x7C
   DWORD dwWarp6;                  //0x80
   DWORD dwWarp7;                  //0x84
   BYTE nIntensity;               //0x88
   BYTE nRed;                     //0x89
   BYTE nGreen;                  //0x8A
   BYTE nBlue;                     //0x8B
   DWORD dwPortal;                  //0x8C
   DWORD dwPosition;               //0x90
   DWORD dwSaveMonsters;            //0x94
   DWORD dwLOSDraw;               //0x98
};
*/

/*
Title 	Levels.txt File Guide
Description 	by Nefarius & Kingpin
Sent by 	
OVERVIEW:

This is the file that controls how the game link levels, what monsters and object that are spawned that are placed on the level.

RELATED .TXT FILES:

This file is using:

    Lvlmaze.txt
    LvlPrest.txt
    LvlSub.txt
    LvlTypes.txt
    monstats.txt
    AutoMap.txt
    LvlWarp.txt
    objgroup.txt



COLUMN DESCRIPTIONS :

Name 	This column has no function, it only serves as a comment field to make it easier to identify the Level name
Id 	Level ID (used in columns like VIS0-7)
Pal 	Palette (Color Palette loaded for the Level, you can change this but mostly the colors get messed up greatly)
Act 	The Act the Level is located in (internal numbering 0-4)
QuestFlag 	Used in Classic game only, sets a questflag. If this flag is set, a character must have completed the quest associated with the flag to take a town portal to the area in question. A character can always use a portal to get back to town.
QuestFlagEx 	Used in Expansion only, set a questflag. If this flag is set, a character must have completed the quest associated with the flag to take a town portal to the area in question. A character can always use a portal to get back to town.
Layer 	Each layer is an unique ID. This number is used to store each automap individual on a character. This is used by the game to remember what level the automap are for. (You need to use the extended levels plugin to be able to add additional layers)
SizeX 	sizeX in Normal. If this isn't a preset area this sets the X size for the area. Othervise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

SizeY 	sizey in Normal. If this isn't a preset area this sets the Y size for the area. Othervise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

nSizeX(N) 	sizeX in Nightmare. sizeX in Normal. If this isn't a preset area this sets the X size for the area. Otherwise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

SizeY(N) 	sizey in Nightmare. If this isn't a preset area this sets the Y size for the area. Othervise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

SizeX(H) 	sizeX in Hell. sizeX in Normal. If this isn't a preset area this sets the X size for the area. Othervise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

SizeY(H) 	sizeX in Hell. If this isn't a preset area this sets the Y size for the area. Othervise use the same value here that are used in lvlprest.txt to set the size for the .ds1 file.

OffsetX 	This set the the X position in the world space

OffsetY 	This set the Y position in the world space

Depend 	This set what level_id are the Depended level. This is used by as example Monastery to place the entrance always at same location.
Teleport 	Controls if teleport is allowed in that level.

0 = Teleport not allowed
1 = Teleport allowed
2 = Teleport allowed, but not able to use teleport throu walls/objects (maybe for objects this is controlled by IsDoor column in objects.txt)
Rain 	Does it Rain/Snow in this Level (1=yes, 0=no), snow works only in act5.
Mud 	Unused setting (In pre beta D2 blizzard planed Rain to cause Mud which would have slowed your char's speed down, but this never made it into the final game), the field is read by the code but the return value is never utilized.
NoPer 	Setting for 3D Enhanced D2 that disables Perspective Mode for a specific level. (1=disabled, 0=enabled)
LOSDraw 	Allows you to look thru objects and walls even if they are not in a wilderness level. (1=yes, 0=no).
FloorFilter 	Probably has to do with Tiles and their Placement (function currently unknown) (1=yes, 0=no).

BlankScreen 	Probably has to do with Tiles and their Placement (function currently unknown) (1=yes, 0=no).

DrawEdges 	for levels bordered with mountains, walls (act 1 wildernesses for example) (1=yes, 0=no).
IsInside 	Is this level a Outdoor or Indoor area (1=yes, 0=no). Indoor areas are not effected by day-night cycles (they always use the same lighting-settings), this field also controls whenever sounds will echo if you're running the game with a sound 
card capable of it and have enviroment sound effects set to true
DrlgType 	Setting for Level Generation: 1=Random Maze, amount of rooms defined by LVLMAZE.TXT (the total size of all the rooms may not exceed the worldspace allocated to the area however), 2=pre set map (example: catacombs lvl4) and 3=Random Area with 
preset size (wildernesses).

LevelType 	The type of the Level (Id from lvltypes.txt)
Sub Columns 	IDs from LVLSub.txt, LVLSub.txt is used to randomize outdoor areas, such as spawning ponds in the blood moor and more stones in the Stoney Field, this is all changeable, the other subcolumns are explained in this post

SubType 	Setting Regarding Level Type (6=wilderness, 9=desert etc, -1=no subtype).

SubTheme 	Tells what subtheme an wilderness area should use. There are themes between 0-4, -1 use no subetheme.

SubWaypoint 	Setting Regarding Waypoints (does not control waypoint placement).

SubShrine 	Setting Regarding Shrines (does not control what shrines appear).
Vis0-7 	This controls what Level_ID the level are connected to on Server Side. What vis you use depend of what special tile your entrance are using. Normally cave levels are only using vis0-3 and wilderness areas 4-7

Warp0-7 	This controls the visual graphics then you move the mouse pointer over an entrance. To show the graphics you use an ID from lvlwarp.txt and the behavior on the graphics is controlled by lvlwarp.txt. You use same WarpX as you use VisX (ie if you 
use Vis0 for your level then you would use Warp0 to show the graphics).
Intensity 	Light Intensity: 0-255.

Red 	Red Lighting Strength (This works in 2D mode also)

Green 	Green Light Strengh (This works in 2D mode also)

Blue 	Blue Light Strength (This works in 2D mode also)
Portal 	This field is required for some levels, entering those levels when portal field isn't set will often crash the game. This also applies to duplicates of those levels created with both of the extended level plugins.
Position 	This controls if you can re-position a portal in a level or not.

1 = You can re-position the portal (it will use either map entry#76 or Tp Location #79. If both are set in same level it will use Tp Location)

0 = don't use re-position.
SaveMonster 	Does the game save the state of the Monsters for the area (1=yes, 0=no) (towns are set to 0 so that NPCs get respawned and hence get new items when you leave town).
Quest 	What quest is this level related to. This is the quest_id (as example the first quest Den of Evil are set to 1, since its the first quest)
WarpDist 	This sets the minimum distance from a VisX or WarpX location that a monster, object or tile can be spawned at. (also applies to waypoints and some preset portals)
MonLvl1 	Area (Dungeon) Level on Normal (controls the item level of items that drop from chests etc).
MonLvl2 	Area (Dungeon) Level on Nightmare (controls the item level of items that drop from chests etc).
MonLvl3 	Area (Dungeon) Level on Hell (controls the item level of items that drop from chests etc)
MonLvl1Ex 	Area (Dungeon) Level on Normal in D2X (controls the item level of items that drop from chests etc).
MonLvl2Ex 	Area (Dungeon) Level on Nightmare in D2X (controls the item level of items that drop from chests etc). If no ratio is set to 0 (in monstats.txt) the monster level of every monster spawned in this level, except monsters with boss set to 1 will 
be set to this level
MonLvl3Ex 	Area (Dungeon) Level on Hell in D2X (controls the item level of items that drop from chests etc). If no ratio is set to 0 (in monstats.txt) the monster level of every monster spawned in this level, except monsters with boss set to 1 will be 
set to this level
MonDen 	This is a chance in 100000ths that a monster pack will spawn on a tile, the maximum chance the game allows is 10% (aka 10000) in v1.10+
MonDen(N) 	Monster Density Nightmare. This is a chance in 100000ths that a monster pack will spawn on a tile, the maximum chance the game allows is 10% (aka 10000) in v1.10+
MonDen(H) 	Monster Density Hell. This is a chance in 100000ths that a monster pack will spawn on a tile, the maximum chance the game allows is 10% (aka 10000) in v1.10+
MonUMin 	Minimum Unique and Champion Monsters Spawned in this Level. Whenever any spawn at all however is bound to MonDen
MonUMax 	Maximum Unique and Champion Monsters Spawned in this Level. Whenever any spawn at all however is bound to MonDen
MonWndr 	Boolean switch (0/1) that sets whether unactivated monsters are allowed to roam the area (ala Wilderness), or whether they must stand put until activated (ala Den of Evil). 0 = cannot roam, 1 = can roam. Can make things like in Diablo, where 
monsters won't roam until activated.
MonSpcWalk 	This setting is hardcoded to certain level Ids, like the River Of Flame, enabling it in other places can glitch up the game, so leave it alone. It is not known what exactly it does however.
NumMon 	Number of different Monster Types that will be present in this area, the maximum is 13. You can have up to 13 different monster types at a time in Nightmare and Hell difficulties, selected randomly from nmon1-nmon25. In Normal difficulty you can 
have up to 13 normal monster types selected randomly from mon1-mon25, and the same number of champion and unique types selected randomly from umon1-umon25.
mon1-mon25 	Normal only. Spawned species, use ID from MonStats.txt. Only the first ten columns appear in the unmodded file. In 1.10 final, beta 1.10s and v1.11+ you can add the missing mon11-mon25 columns.
rangedspawn 	Give preference to monsters set to ranged=1 in MonStats.txt on Nightmare and Hell difficulties when picking something to spawn. Exact way this is done is unknown though.
nmon1-nmon25 	Nightmare/Hell only. Spawned species, use ID from MonStats.txt. Only the first ten columns appear in the unmodded file. In 1.10 final, beta 1.10s and v1.11+ you can add the missing nmon11-nmon25 columns. Due to what appears to be a bug 
Champion/Unique species uses this column also in nightmare/hell.
umon1-umon25 	Normal only. Champion/Unique species, use ID from MonStats.txt. Only the first ten columns appear in the unmodded file. In 1.10 final, beta 1.10s and v1.11+ you can add the missing umon11-umon25 columns.
cmon11-4 	Critter Species 1-4. Use id from monstats2.txt and only monsters with critter column set to 1 can spawn here. critter column is also found in monstats2.txt. Critters are in reality only present clientside.
cpct1-cpct4 	Controls the %chance a critter is spawned.
camt1-camt4 	(unknown). These columns are bugged, the game overrides the contents of columns 3-4 with the value from column 1 when it compiles the bin files.
Themes 	Which Theme is used for this Area? (unknown function), this field is accessed by the code but it is not exactly known what it does.
SoundEnv 	Referes to a entry in SoundEnviron.txt (for the Levels Music)
Waypoint 	255=No way Point, other #'s Waypoint ID (you can switch waypoint destinations between areas this way, not between acts however so don't even bother to try)
LevelName 	String Code for the Display name of the Level
LevelWarp 	String Code for the Display name of a entrance to this Level
EntryFile 	Which *.DC6 Title Image is loaded when you enter this area, this file MUST exist, otherwise you will crash with an exception when you enter the level (for all levels below the expansion row, the files must be present in the expension folders)
ObjGrp0-7 	Use the ID of the ObjectGroup you want to Spawn in this Area (from ObjGroups.txt).
ObjPrb0-7 	Object Spawn Possibility: the Chance for this object to occur (if you use ObjGrp0 then set ObjPrb0 to a value below 100)
Beta 	Reference Only (can be used for comments)

*/

/*
Levels.txt�ļ������� 

Name: �ڲ����ƣ��޸���Ч��

Id: ��ͼ��ID���룻

Pal: ��ǰ��ͼ�����õ���ɫ�壻

Act: ��ͼ���ڵ�λ�ã�0��4Ϊ��Ч��ֵ����

QuestFlag:��������ԭ��İ����У���Ҫ��������ض������������õ�SETװ����������������ָ������

QuestFlagEx:������������Ƭ��LOD������Ҫ��������ض������������õ�SETװ����������������ָ������

Layer: ��Ϸ�ڲ��ġ��㡱�趨���������ý�ɫ��С��ͼ�ϵ���ʾλ�ã�

SizeX: �ڡ���ͨ���Ѷ��µ�ͼ��X�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

SizeY: �ڡ���ͨ���Ѷ��µ�ͼ��Y�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

SizeX(N): �ڡ����Ρ��Ѷ��µ�ͼ��X�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

SizeY(N): �ڡ����Ρ��Ѷ��µ�ͼ��Y�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

SizeX(H): �ڡ��������Ѷ��µ�ͼ��X�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

SizeY(H): �ڡ����Ρ��Ѷ��µ�ͼ��Y�᳤�ȣ�ע�������ֵͬlvlprest.txt�ļ��Ĺ�������

OffsetX: ��ͼX����ò�����

OffsetY: ��ͼY����ò�����

Depend: ����һЩ����Ҫ������ɵĵ�ͼʹ���������������˵��ACT4�ĳ��򣩣�

Teleport: ���ò�����˵������ȷ��һ��˵���޸�����û��ʲô���壻

Rain: �����ͼ�����Ƿ�����/��ѩ��1=������Ӱ�죬0=��Ӱ�죩��˵������ѩֻ��ACT5���֣� 

Mud: ���ò�����˵������ʵ��D2����ƽ׶�������������������У��������������Ч������һֱ��δʵʩ��

NoPer: �˵�ͼ�Ƿ�ǿ��ʹ��3D��ʾ��1=ǿ�ƣ�0=��ǿ�ƣ���

LOSDraw: �Ƿ�ֱ�ӿ��Կ������ݵ��ڲ�������Ҫ���루1=����0=�������� 

FloorFilter: �Ƿ���˷��ݡ������⾰��1=�ǣ�0=�񣩣�˵������Ҫ�����DT1�ļ��� 

BlankScreen: �⾰������1=�ǣ�0=�񣩣�

DrawEdges: �Ƿ���ʾǽ����Ʒ�ı�Ե��1=�ǣ�0=�񣩣�

IsInside: �˵�ͼ��λ�ڲ��ɼ���λ�ã�����£�1=�ǣ�0=�񣩣�

DrlgType: ��ͼ�����ɷ�ʽ��1=��������ɣ��������Ʒ��������LVLMAZE.TXT�ļ����壬2=�̶���ͼ���磺ACT1�Ĺصף���3=������ɣ�����ͼ��С�����ı䣻

LevelType: ��ͼ�����ͣ�ͬlvltypes.txt�ļ���������

Sub Columns: ͬLVLSub.txt������й�����

SubType: ��ͼ����ۼ��𣬱���˵��6=Ұ�⣬9=ɳĮ���ȵȣ�-1=�������ͣ� 

SubTheme: ��ͼ��������⣬һ�����0-4����ֵ��-1��ʾ��ʹ��������⣻ 

SubWaypoint: �趨·��Ĳ�����������������·���λ�ã���

SubShrine: �趨�漴���ֵ���̳��������ʵ�ʲ�����������

Vis0: ��ͼ1�ŵ����/���ڣ�

Vis1: ��ͼ2�ŵ����/���ڣ�

Vis2: ��ͼ3�ŵ����/���ڣ�

Vis3: ��ͼ4�ŵ����/���ڣ�

Vis4: ��ͼ5�ŵ����/���ڣ�

Vis5: ��ͼ6�ŵ����/���ڣ�

Vis6: ��ͼ7�ŵ����/���ڣ�

Vis7: ��ͼ8�ŵ����/���ڣ�

Warp #: ͬlvlwarp.txt������

Intensity: ���ȵ�����ֵ��0-255����

Red: ��������ֵ��

Green: �̹������ֵ��

Blue: ���������ֵ��

Portal: ���ò�����˵����������������˵����Ϊ��Ч���������ұ�����Ϊ��һ�����ڵ��������ŵ����ͣ����Ż������ţ�ylycloakע����

Position: ��ͼ�����ֵ�λ�ã�

SaveMonster: �Ƿ��¼�µ�ͼ�Ϲ����״̬����1=�ǣ�0=��һ������н�����ֵ����Ϊ0����Ϊ��Ҫ������ɫ���Ǻ����ʱ���н��׵���Ʒ���ࣩ��

Quest: �������������

WarpDist: ��������ͬ��ͼ�ϸ���Ԫ�صľ��룻

MonLvl1: ����ͨ����������Ʒ�������е���ļ���ԭ�棩��

MonLvl2: �����Ρ���������Ʒ�������е���ļ���ԭ�棩��

MonLvl3: ����������������Ʒ�������е���ļ���ԭ�棩��

MonLvl1Ex: ����ͨ����������Ʒ�������е���ļ�������Ƭ����

MonLvl2Ex: �����Ρ���������Ʒ�������е���ļ�������Ƭ����

MonLvl3Ex: ����������������Ʒ�������е���ļ�������Ƭ����

MonDen: ����ͨ�������£���ǰ��ͼ�й�����ܶȣ�˵����������ֵ�ܹ�����10000�������鲻Ҫ����3000���������ֵ�ᵹ����Ϸ�����ٶȵĽ��ͣ�

MonDen(N): �����Ρ������£���ǰ��ͼ�й�����ܶȣ�˵����������ֵ�ܹ�����10000�������鲻Ҫ����3000���������ֵ�ᵹ����Ϸ�����ٶȵĽ��ͣ� 

MonDen(H): �������������£���ǰ��ͼ�й�����ܶȣ�˵����������ֵ�ܹ�����10000�������鲻Ҫ����3000���������ֵ�ᵹ����Ϸ�����ٶȵĽ��ͣ�

MonUMin: ��ǰ��ͼ�ж��й���ͳ����������С������

MonUMax: ��ǰ��ͼ�ж��й���ͳ�����������������

MonWndr: �������͵Ĳ���������ȷ���Ƿ������Ҫ�ض����������ܹ������ض��Ĺ������˵DIABLO��Ҫ�����ӡ�������

MonSpcWalk: ���ò�����

NumMon: ��ǰ��ͼ����������ڵĹ������ࣻ

Mon1-Mon10: ͬmonstats.txt�ļ��е�ID�ж�Ӧ����ʾ�ڡ���ͨ�������µ�ǰ��ͼ�г��ֵĹ�������ͣ�������չ��Mon25��

rangedspawn: ���ò�����

nmon1-10: ͬmonstats.txt�ļ��е�ID�ж�Ӧ����ʾ�ڡ����Ρ��͡������������µ�ǰ��ͼ�г��ֵĹ�������ͣ�������չ��Mon25��

umon1-10: ͬmonstats.txt�ļ��е�ID�ж�Ӧ����ʾ�ڡ���ͨ�������µ�ǰ��ͼ�г����ض�����ͳ�����������ͣ�������չ��Mon25��

cmon1-4: ��������ã�ͬmonstats.txt��monstats2.txt�ļ���������

cpct1-cpct4: ͬcmon1-4�й���������˵�����cmon1�е���ֵΪ1����ôcpct1����Ӧ�ľ�Ӧ��Ϊ30��

camt1-camt4: ���ò�����

Themes: ��ǰ��ͼ�����õ����⣬��Ŀǰ����û��ʲô�ã�ylycloakע����

SoundEnv: ���뵱ǰ��ͼʱ�����õı������֣�

Waypoint: ·���λ�ã�255=û��·�㣬������ֵ����·���ID�����ǣ���ֱ�ӽ���ţ�أ��ǣ�������ɣ���

LevelName: ��ͼ���ƣ��ڲ����룩��

LevelWarp: �����뵱ǰ��ͼʱ����ʾ�����ƣ��ڲ����룩��

EntryFile: ��ǰ��ͼ��Ҫ������Щ�����ļ���*.Dc6��ʽ����

ObjGrp0-7: ��ǰ��ͼ�����õ�����飨ͬObjectGroups.txt��������

ObjPrb0-7: �������������ֵĻ��ʣ�����˵���������ʹ��ObjGrp0����ô��ͱ����ObjPrb0����ֵ����Ϊ������100����

Beta: ע�͡�
*/

/*
�ļ���������
Level(s)������������ָ��ͼ��
���ļ���������Ϸ�����е�ͼ���ļ���
���ļ��е�ÿһ�б�ʾһ�ŵ�ͼ��

ÿ�еĺ������£�

Name����ǰ��ͼ�Ĵ��롣

Id����ǰ��ͼ�ı�š�

Pal����ǰ��ͼ�����õ���ɫ�塣

Act����ͼ���ڵ�λ�ã����ڵڼ�Ļ��0��4�ֱ��ʾ��1��5Ļ��

QuestFlag����ǰ��ͼ�Ƿ��Ӧ��ĳ�������ڷ�����Ƭ��

QuestFlagEx����ǰ��ͼ�Ƿ��Ӧ��ĳ������������Ƭ��

Layer����Ϸ�ڲ��ġ��㡱�趨��

SizeX����ǰ��ͼ����ͨ�Ѷ��µĿ�ȣ���LvlPrest.txt������

SizeY����ǰ��ͼ����ͨ�Ѷ��µĸ߶ȣ���LvlPrest.txt������

SizeX(N)����ǰ��ͼ�ڶ����Ѷ��µĿ�ȣ���LvlPrest.txt������

SizeY(N)����ǰ��ͼ�ڶ����Ѷ��µĸ߶ȣ���LvlPrest.txt������

SizeX(H)����ǰ��ͼ�ڵ����Ѷ��µĿ�ȣ���LvlPrest.txt������

SizeY(H)����ǰ��ͼ�ڵ����Ѷ��µĸ߶ȣ���LvlPrest.txt������

OffsetX����ǰ��ͼ�Ŀ��ƫ������

OffsetY����ǰ��ͼ�ĸ߶�ƫ������

Depend����ǰ��ͼ�Ƿ�������������ͼ��

Teleport���ڵ�ǰ��ͼ˲���Ƿ���Ч����

Rain����ǰ��ͼ�Ƿ���������ѩ��

Mud�����ò������ഫ��Ϊ��������Ч��������

NoPer����ǰ��ͼ�Ƿ�ʹ��3Dģʽ��ʾ��1��ʾʼ��ʹ�á�

LOSDraw���ڵ�ǰ��ͼ�Ƿ������ĳ������ֱ�ӿ��������ڲ��Ķ�����1��ʾ���ԡ�

FloorFilter����ǰ��ͼ�Ƿ���˷��ݡ������⾰��1�����ǡ�

BlankScreen����ǰ��ͼ�Ƿ����⾰��1�����ǡ�

DrawEdges����ǰ��ͼ�Ƿ���ʾ��Ե��1�����ǡ�

IsInside����ǰ��ͼ�Ƿ����ⲿ���ɼ���1�����ǡ�

DrlgType����ǰ��ͼ�����ɷ�ʽ��1=��������ɣ��������Ʒ��������LVLMAZE.TXT�ļ����壬2=�̶���ͼ���磺ACT1�Ĺصף���3=������ɣ�����ͼ��С�����ı䡣

LevelType����ǰ��ͼ�����ͣ�ͬlvltypes.txt�ļ���������

Sub Columns��ͬLVLSub.txt������й�����

SubType����ͼ����ۼ��𣬱���˵��6=Ұ�⣬9=ɳĮ���ȵȣ�-1=�������͡�

SubTheme����ͼ��������⣬һ�����0-4����ֵ��-1��ʾ��ʹ��������⡣

SubWaypoint���趨·��Ĳ�����������������·���λ�ã���

SubShrine���趨�漴���ֵ���̳��������ʵ�ʲ�����������

 Vis0-7����ͼ0-7�ŵ����/���ڡ�

Warp1-7��ͬlvlwarp.txt������

Intensity�����ȵ�����ֵ��0-255����

Red����������ֵ��

Green���̹������ֵ��

Blue�����������ֵ��

Portal�����ò�����

Position����ͼ�����ֵ�λ�á�

SaveMonster���Ƿ��¼�µ�ͼ�Ϲ����״̬����1=�ǣ�0=��һ������н�����ֵ����Ϊ0����Ϊ��Ҫ������ɫ���Ǻ����ʱ���н��׵���Ʒ���ࣩ��

Quest���������������

WarpDist����������ͬ��ͼ�ϸ���Ԫ�صľ��롣

MonLvl1����ͨ�Ѷ��´˵�ͼ�ļ��𣨷�����Ƭ����

MonLvl2�������Ѷ��´˵�ͼ�ļ��𣨷�����Ƭ����

MonLvl3�������Ѷ��´˵�ͼ�ļ��𣨷�����Ƭ����

MonLvl1Ex����ͨ�Ѷ��´˵�ͼ�ļ�������Ƭ����

MonLvl2Ex�������Ѷ��´˵�ͼ�ļ�������Ƭ����

MonLvl3Ex�������Ѷ��´˵�ͼ�ļ�������Ƭ����

MonDen����ͨ�Ѷ��µ�ǰ��ͼ�еĹ����ܶȡ�

MonDen(N)�������Ѷ��µ�ǰ��ͼ�еĹ����ܶȡ�

MonDen(H)�������Ѷ��µ�ǰ��ͼ�еĹ����ܶȡ�

MonUMin����ͨ�Ѷ��µ�ǰ��ͼ�н�ֵ���С��Ŀ��

MonUMax����ͨ�Ѷ��µ�ǰ��ͼ�н�ֵ������Ŀ��

MonUMin(N)�������Ѷ��µ�ǰ��ͼ�н�ֵ���С��Ŀ��

MonUMax(N)�������Ѷ��µ�ǰ��ͼ�н�ֵ������Ŀ��

MonUMin(H)�������Ѷ��µ�ǰ��ͼ�н�ֵ���С��Ŀ��

MonUMax(H)�������Ѷ��µ�ǰ��ͼ�н�ֵ������Ŀ��

MonWndr����ǰ��ͼ�еĹ����Ƿ���ε���

MonSpcWalk�����ò�����

NumMon����ǰ��ͼ����������ڵĹ������ࡣ

Mon1-Mon25����ͨ�Ѷ��µ�ǰ��ͼ�г��ֵĹ������͡���monstats.txt������

rangedspawn�����ò�����

nmon1-nmon25�������Ѷ��µ�ǰ��ͼ�г��ֵĹ������͡���monstats.txt������

umon1-umon25�������Ѷ��µ�ǰ��ͼ�г��ֵĹ������͡���monstats.txt������

cmon1-4����ͼ�ϵ�����缦������֮�ࣩ����ͬmonstats.txt��monstats2.txt�ļ�������

cpct1-cpct4��cmon1-4���ܶȡ�

camt1-camt4�����ò�����

Themes�����ò�����

SoundEnv�����뵱ǰ��ͼʱ�����õı������֡�

Waypoint������Сվ��Сվ�б��е�λ�á�255��ʾ����Сվ�б��С�

LevelName����ͼ���ơ�

LevelWarp�������뵱ǰ��ͼʱ����ʾ�����ơ�

EntryFile����ǰ��ͼ��Ҫ������Щ�����ļ���

ObjGrp0-7����ǰ��ͼ�����õ�����顣��ObjectGroups.txt������

ObjPrb0-7���������������ֵĻ��ʡ�

Beta�����ò�����

����˵�������ļ�������������ϷСվ�й��ڴ��ļ���˵������лylycloak��ǰ�������Ĺ�����
*/

typedef struct
{
    unsigned short vId;
    unsigned char vPal;
    unsigned char vAct;

    unsigned char vTeleport;
    unsigned char vRain;
    unsigned char vMud;
    unsigned char vNoPer;

    unsigned char vIsInside;
    unsigned char vDrawEdges;
    unsigned short iPadding2;

    unsigned int vWarpDist;

    unsigned short vMonLvl1;
    unsigned short vMonLvl2;

    unsigned short vMonLvl3;
    unsigned short vMonLvl1Ex;

    unsigned short vMonLvl2Ex;
    unsigned short vMonLvl3Ex;

    unsigned int vMonDen;
    unsigned int vMonDenmybr1Nmybr2;
    unsigned int vMonDenmybr1Hmybr2;

    unsigned char vMonUMin;
    unsigned char vMonUMinmybr1Nmybr2;
    unsigned char vMonUMinmybr1Hmybr2;
    unsigned char vMonUMax;

    unsigned char vMonUMaxmybr1Nmybr2;
    unsigned char vMonUMaxmybr1Hmybr2;
    unsigned char vMonWndr;
    unsigned char vMonSpcWalk;

    unsigned char vQuest;
    unsigned char vrangedspawn;
    unsigned short vNumMon;

    unsigned short iPadding13;
    unsigned short vmon1;   //MonStats

    unsigned short vmon2;
    unsigned short vmon3;

    unsigned short vmon4;
    unsigned short vmon5;

    unsigned short vmon6;
    unsigned short vmon7;

    unsigned short vmon8;
    unsigned short vmon9;

    unsigned short vmon10;
    unsigned short vmon11;

    unsigned short vmon12;
    unsigned short vmon13;

    unsigned short vmon14;
    unsigned short vmon15;

    unsigned short vmon16;
    unsigned short vmon17;

    unsigned short vmon18;
    unsigned short vmon19;

    unsigned short vmon20;
    unsigned short vmon21;

    unsigned short vmon22;
    unsigned short vmon23;

    unsigned short vmon24;
    unsigned short vmon25;

    unsigned short vnmon1;   //MonStats
    unsigned short vnmon2;

    unsigned short vnmon3;
    unsigned short vnmon4;

    unsigned short vnmon5;
    unsigned short vnmon6;

    unsigned short vnmon7;
    unsigned short vnmon8;

    unsigned short vnmon9;
    unsigned short vnmon10;

    unsigned short vnmon11;
    unsigned short vnmon12;

    unsigned short vnmon13;
    unsigned short vnmon14;

    unsigned short vnmon15;
    unsigned short vnmon16;

    unsigned short vnmon17;
    unsigned short vnmon18;

    unsigned short vnmon19;
    unsigned short vnmon20;

    unsigned short vnmon21;
    unsigned short vnmon22;

    unsigned short vnmon23;
    unsigned short vnmon24;

    unsigned short vnmon25;
    unsigned short vumon1;  //monstats

    unsigned short vumon2;
    unsigned short vumon3;

    unsigned short vumon4;  //40
    unsigned short vumon5;

    unsigned short vumon6;
    unsigned short vumon7;

    unsigned short vumon8;
    unsigned short vumon9;

    unsigned short vumon10;
    unsigned short vumon11;

    unsigned short vumon12;
    unsigned short vumon13;

    unsigned short vumon14;
    unsigned short vumon15;

    unsigned short vumon16;
    unsigned short vumon17;

    unsigned short vumon18;
    unsigned short vumon19;

    unsigned short vumon20;
    unsigned short vumon21;

    unsigned short vumon22;
    unsigned short vumon23;

    unsigned short vumon24;
    unsigned short vumon25;

    unsigned short vcmon1;  //monstats
    unsigned short vcmon2;

    unsigned short vcmon3;
    unsigned short vcmon4;

    unsigned short vcpct1;
    unsigned short vcpct2;

    unsigned short vcpct3;
    unsigned short vcpct4;

    unsigned short vcamt4;
    unsigned short iPadding55;
    unsigned int iPadding56;

    unsigned char vWaypoint;
    unsigned char vObjGrp0;
    unsigned char vObjGrp1;
    unsigned char vObjGrp2;

    unsigned char vObjGrp3;
    unsigned char vObjGrp4;
    unsigned char vObjGrp5;
    unsigned char vObjGrp6;

    unsigned char vObjGrp7;
    unsigned char vObjPrb0;
    unsigned char vObjPrb1;
    unsigned char vObjPrb2;

    unsigned char vObjPrb3;
    unsigned char vObjPrb4;
    unsigned char vObjPrb5;
    unsigned char vObjPrb6;

    unsigned char vObjPrb7;
    unsigned char vLevelName[40];

    unsigned char vLevelWarp[40];

    unsigned char vEntryFile[39];

    unsigned int iPadding91;
    unsigned int iPadding92;
    unsigned int iPadding93;
    unsigned int iPadding94;
    unsigned int iPadding95;
    unsigned int iPadding96;
    unsigned int iPadding97;
    unsigned int iPadding98;
    unsigned int iPadding99;

    unsigned int iPadding100;
    unsigned int iPadding101;
    unsigned int iPadding102;
    unsigned int iPadding103;
    unsigned int iPadding104;
    unsigned int iPadding105;
    unsigned int iPadding106;
    unsigned int iPadding107;
    unsigned int iPadding108;
    unsigned int iPadding109;

    unsigned int iPadding110;
    unsigned int iPadding111;
    unsigned int iPadding112;
    unsigned int iPadding113;
    unsigned int iPadding114;
    unsigned int iPadding115;
    unsigned int iPadding116;
    unsigned int iPadding117;
    unsigned int iPadding118;
    unsigned int iPadding119;

    unsigned int iPadding120;
    unsigned int iPadding121;
    unsigned int iPadding122;
    unsigned int iPadding123;
    unsigned int iPadding124;
    unsigned int iPadding125;
    unsigned int iPadding126;
    unsigned int iPadding127;
    unsigned int iPadding128;
    unsigned int iPadding129;

    unsigned int iPadding130;
    unsigned int iPadding131;
    unsigned int vThemes;
    unsigned int vFloorFilter;
    unsigned int vBlankScreen;
    unsigned int vSoundEnv;

    int vQuestFlag;
    int vQuestFlagEx;
    int vLayer;
    int vSizeX;
    int vSizeXmybr1Nmybr2;
    int vSizeXmybr1Hmybr2;
    int vSizeY;
    int vSizeYmybr1Nmybr2;
    int vSizeYmybr1Hmybr2;
    int vOffsetX;

    int vOffsetY;
    int vDepend;

    int vDrlgType;
    int vLevelType;
    int vSubType;

    int vSubTheme;
    int vSubWaypoint;
    int vSubShrine;
    int vVis0;
    int vVis1;

    int vVis2;
    int vVis3;
    int vVis4;
    int vVis5;
    int vVis6;
    int vVis7;
    int vWarp0;
    int vWarp1; //163
    int vWarp2;
    int vWarp3;

    int vWarp4;
    int vWarp5;
    int vWarp6;
    int vWarp7;

    unsigned char vIntensity;
    unsigned char vRed;
    unsigned char vGreen;
    unsigned char vBlue;

    int vPortal;
    int vPosition;

    unsigned char vSaveMonsters;
    char iPadding173[3];

    int vLOSDraw;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "camt1",
    "camt2",
    "camt3",
    "Beta",
    NULL,
};

static char *m_apcInternalProcess[] = 
{
    "Name",
     NULL,
};

static int Levels_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Name") )
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

    return 0;
}

static int Levels_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( 1 == sscanf(acKey, "mon%d", &id) )
    {
        unsigned short *pwMon = &pstLineInfo->vmon1;
        pcResult = MonStats_GetStatsName(pwMon[id - 1]);
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
    else if ( 1 == sscanf(acKey, "nmon%d", &id) )
    {
        unsigned short *pwMon = &pstLineInfo->vnmon1;
        pcResult = MonStats_GetStatsName(pwMon[id - 1]);
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
    else if ( 1 == sscanf(acKey, "umon%d", &id) )
    {
        unsigned short *pwMon = &pstLineInfo->vumon1;
        pcResult = MonStats_GetStatsName(pwMon[id - 1]);
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
    else if ( 1 == sscanf(acKey, "cmon%d", &id) )
    {
        unsigned short *pwMon = &pstLineInfo->vcmon1;
        pcResult = MonStats_GetStatsName(pwMon[id - 1]);
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

static int Levels_CombineBin(char *acBinPath)
{
    int result = 1;
    unsigned int iLineCount;
    FILE *pfBinHandle = NULL;
    FILE *pfBin2Handle = NULL;
    FILE *pfOutputHandle = NULL;
    char *pcTemp;

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);
    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, "levels");
    pfBinHandle = fopen(m_acGlobalBuffer, "rb");

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);
    sprintf(m_acGlobalBuffer, "%s\\%s.bin", acBinPath, "leveldefs");
    pfBin2Handle = fopen(m_acGlobalBuffer, "rb");

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);
    sprintf(m_acGlobalBuffer, "%s\\%s%s.bin", acBinPath, BIN_TEMP, FILE_PREFIX);
    pfOutputHandle = fopen(m_acGlobalBuffer, "wb");

    if ( NULL == pfBinHandle || NULL == pfBin2Handle || NULL == pfOutputHandle )
    {
        my_printf("failed to read bin\r\n");
        goto error;
    }

    memset(m_acGlobalBuffer, 0, m_iGlobaBufLength);

    //��ȡbin�ļ����ļ�ͷ
    fread(&iLineCount, 1, sizeof(iLineCount), pfBinHandle);
    fread(m_acGlobalBuffer, 1, sizeof(iLineCount), pfBin2Handle);

    pcTemp = &m_acGlobalBuffer[sizeof(iLineCount)];
    while ( 0 < iLineCount )
    {
        fread(pcTemp, 1, 544, pfBinHandle);
        pcTemp += 544;

        fread(pcTemp, 1, 156, pfBin2Handle);
        pcTemp += 156;

        iLineCount--;
    }

    //д��bin�ļ�
    fwrite(m_acGlobalBuffer, 1, pcTemp - m_acGlobalBuffer, pfOutputHandle);

    goto out;

error:
    result = 0;

out:
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
        pfBinHandle = NULL;
    }
    if ( NULL != pfBin2Handle )
    {
        fclose(pfBin2Handle);
        pfBin2Handle = NULL;
    }
    if ( NULL != pfOutputHandle )
    {
        fclose(pfOutputHandle);
        pfOutputHandle = NULL;
    }

    return result;
}

int process_levels(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    char acBinTempFile[256] = {0};

    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    if ( 1 != Levels_CombineBin(acBinPath) )
    {
        return 0;
    }

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Teleport, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mud, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NoPer, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, IsInside, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrawEdges, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WarpDist, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl1Ex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl2Ex, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonLvl3Ex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDenmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonDenmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMin, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMinmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMinmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMax, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMaxmybr1Nmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonUMaxmybr1Hmybr2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonWndr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonSpcWalk, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rangedspawn, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NumMon, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon1, USHORT);   //MonStats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon9, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon10, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon11, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon12, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon13, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon14, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon15, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon16, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon17, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon18, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon19, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon20, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon21, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon22, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon23, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon24, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mon25, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon1, USHORT);   //MonStats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon6, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon7, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon8, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon9, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon10, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon11, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon12, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon13, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon14, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon15, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon16, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon17, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon18, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon19, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon20, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon21, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon22, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon23, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon24, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nmon25, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon1, USHORT);  //monstats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon9, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon10, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon11, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon12, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon13, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon14, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon15, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon16, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon17, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon18, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon19, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon20, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon21, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon22, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon23, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon24, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, umon25, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon1, USHORT);  //monstats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmon4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpct4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, camt4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Waypoint, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjGrp7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb0, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ObjPrb7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelName, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelWarp, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, EntryFile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Themes, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FloorFilter, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlankScreen, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SoundEnv, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QuestFlag, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, QuestFlagEx, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Layer, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeXmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeXmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeYmybr1Nmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeYmybr1Hmybr2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OffsetX, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, OffsetY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Depend, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DrlgType, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelType, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubType, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubTheme, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubWaypoint, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SubShrine, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis0, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Vis7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp0, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Warp7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Intensity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Red, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Green, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Blue, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Portal, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SaveMonsters, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Position, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LOSDraw, INT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Levels_ConvertValue;
            m_stCallback.pfnFieldProc = Levels_FieldProc;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            sprintf(acBinTempFile, "%s\\%s", acBinPath, BIN_TEMP);

            return process_file_special_bin(acTemplatePath, acBinTempFile, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

