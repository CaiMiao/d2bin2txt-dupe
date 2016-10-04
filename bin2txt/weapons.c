#include "global.h"

#define FILE_PREFIX "weapons"

/*
Weapons.txt

This guide is based on Ric Faith 1.09x guide.

9/7 fileguide completed.
9/7. Added my discovery on how component column works.
9/7. Added explanation for alternativegfx column (thanx Paul) and it still works in 1.10

name: Reference only, its a comment field.

type: first base type (code from itemtypes.txt)

type2: second base type (code from itemtypes.txt)

code: is not needed to be added to string table anymore. This is a 3 letter/number code that need to be unique and
not used by other items.

alternategfx: This is the code of the DCC to use for a Player Animation.

For instance, the Gothic Shield (code=gts) has kit in its alternategfx column. That means that if a Barbarian equip himself whith that shield, in his A1 (Attack 1) mode animation his SH (Shield) layer component will use the DCC BASHKITA11HS.DCC, and NOT 
the file BASHGTSA11HS.DCC nor the file BASHBUCA11HS.DCC.

namestr: If namestr code is not added to a string table it will use that name in the field. If you want a string name with space you need to add it to your string table.

version: 0=Classic D2, 100=Expansion (A item set to 100 here cannot be generated in classic d2).

compactsave: 1=use compactsave 0=don't use compactsave. This is used to get a smaller filesize. This will not save
any stats to the item, this means it will not save any quantity, automagic, affixes, damage, armor, durability e.tc.
(This is used by items that don't need any stats stored like Healing potions, gems).

rarity: 0 = Exclude this item from armor rack, 1 and higher sets the rarity for this item to be droped from an armor rack.
(There need to be atleast one armor with rarity 1 othervise the game will crash when you use an armor rack).

spawnable: 1=can be sold by NPCs, 0=can never be sold by NPCs (even if you make them sell it thru the vendor columns)

mindam: Minimum one-handed damage the weapon can cause

maxdam: Maximum one-handed damage the weapon can cause

1or2handed: Boolean (1=yes,0=no) for whether weapon can be carried in 1 or 2 hands by Barbarian

2handed: 1 = this is a two handen weapon, 0 = this is a one handed weapon

2handmindam: Minimum two-handed damage the weapon cause

2handmaxdam: Maximum two-handed damage the weapon cause

minmisdam: Minimum ranged damage the weapon can cause

maxmisdam: Maximum ranged damage the weapon can cause

rangeadder: Adds additional range for melee weapon attacks (bare hand's range = 1)

speed: Possitive value = slower weapon speed, negative value = faster weapon speed. This speed value is of course then further modified by each classes individual weapon proficiencies

StrBonus: %age of Str taken into account for Bonus damage

DexBonus: %age of Dex taken into account for Bonus damage

reqstr: Required Strength 0-65535 (If you set a higher value than 65535 or less than 0 you will have a rollover)

reqdex: Required Dexterity 0-65535 (If you set a higher value than 65535 or less than 0 you will have a rollover)

durability: base durability (255 is maximum, higher value will make a rollover, so if you set Durability to 257 it will set it to durability 1 of 1)

nodurability: 1=indestructible, 0=use durability

level: base item level (aka a monster with a mlvl of 20 cannot drop a lvl30 armor for eg, used by the "armo#" preset TCs)

levelreq: the minimum level you need to have to use that item

cost: base cost

gamble cost: not used, reference only.

magic lvl: additional magic level when finding the item aka: If you gamble at lvl10 you can get lvl20 affixes if this is set to 10 for eg

auto prefix: Group # from automagic.txt (base affixes, like built in hp/resistances)

OpenBetaGfx: no use (reference to what alternategfx it was using in the d2 beta)

normcode: normal item code (it's used by game/cube upgrade code)

ubercode: exceptional item code (it's used by game/cube upgrade code)

ultracode: elite item code (it's used by game/cube upgrade code)

wclass: 1 handed weapon class, determines what style of attack to use (eg. 1hs, 1ht, hth)

2handedwclass: 2 handed weapon class, determines what style of attack to use

component: This tells what layer it should use from composit.txt to show the item on the character. (composit.txt are 16
lines that range from 0 (HD) to 15 (S8) and 16 means "no player animation").

hit class: what type of effects are displayed/heard when enemy is struck with weapon

invwidth: width in inventory cells

invheight: height in inventory cells

stackable: can this item be stacked 1=yes, 0=no

minstack: min ammount of quantity

maxstack: max ammount quantity

spawnstack: when randomly spawned, how many in a stack

flippyfile: flip gfx (dropping gfx)

invfile: inventory gfx

uniqueinvfile: unique inventory gfx

setinvfile: set inventory gfx

hasinv: 1 can be socketed, 0 cannot be socketed (You need to set MaxSock1/25/40 in itemtypes.txt to atleast 1 to have sockets in the item)

gemsockets: maximum number of sockets

gemapplytype: gem effecs 0=weapon, 1=armor/helm, 2=shield (If you add a higher value it wouldn't add the socket)

special: Not used, Comment field.

useable: 0=you cannot rightclick, 1=you can rightclick on this item

dropsound: tells what sound you use when the item is dropped. The name it uses is from Sound column in sounds.txt

dropsfxframe: Number of frames the sound will use.

usesound: tells what sound you use when the item is use. The name it uses is from Sound column in sounds.txt

unique: 1 = always unique, 0 = not always unique (This is used by questitems to have the item as always unique)

transparent: unknown function

transtbl: unknown function (But are always using 5)

quivered: is this item a stack of ammo 1=yes, 0=no

lightradius: Not used.

belt: numberic Id from belts.txt (defines number of potion slots)

quest: for quest items (quest ID)

questdiffcheck: sets in what difficulty this item is a questitem.

missiletype: missile to shoot if you throw this item (id from missiles.txt)

durwarning: the dur warning icon to display when the item is about to break

qntwarning: quantity warning icon to display if you wasted most of the stack

gemoffset: unknown

bitfield1: set to 1 for leather items, to 3 for metal ones.

Vendor Columns: (replace Vendor with the vendor name aka CharsiMin etc)

VendorsMin: minimum amount of items of this type the vendor can sell

VendorsMax: maximum amount of items of this type the vendor can sell

VendorsMagicMin: minimum amount of magic items of this type the vendor can sell

VendorsMagicMax: maximum amount of magic items of this type the vendor can sell

vendorsMagicLvl: Max magic level an item can get from the affixes.

Source Art: unknown

Game Art: unknown

Transform and invTrans : Index telling which colormap .dat to use for this item
(like 1=dataglobalitemspalettegrey.dat, 8=dataglobalitemspaletteinvgreybrown.dat).
This is telling what are the pixels that will change colors
(only transform brown pixels to dark green ? transform all pxiels to dark green ?).
For details, check http://d2mods.xfernet.com/colormaps.php
Transform is for the Animation of the player, while InvTrans is for the Inventory gfx

SkipName: for items like the viper amulet (which dosent say viper amulet two times) (skips the base name)

NightmareUpgrade: item code of the item the vendor will sell instead of this item on NM (xxx=no change)

HellUpgrade: item code of the item the vendor will sell instead of this item on HELL (xxx=no change)

nameable: 1=can be personalized, 0=cannot be personalized

PermStoreItem: Boolean will item always be sold by sellers? Item cannot be depleted


Annex A - Calculation of affixes available for item - by Ruvanal
This is from 1.09x (have no idea if anything here has been changed)

Terms
alvl = affix level. For an item this is the level that is used to compare to the level and max level as found in the prefix and suffix tables. When referring to a prefix/suffix it is the value listed in the level column.

ilvl = internal level (also referred to sometimes as the item level; better yet item creation level). This value is set at the time of an items creation. For monster drops the ilvl=mlvl. (BTW ilvl matches up with the terminology of the 1.07/1.08 cubemain
.txt---'itemlevel pct a')

mlvl = monster level.

clvl = character level.

qlvl = quality level. This value is found in the level column of armor.txt, weapons.txt and misc.txt. This is the value that is used to create the weapXX and armoXX treasure classes.
magic_lvl = magic level bonus on some items. Currently the only ones that have this are wands (normal and exceptional, but not the elite ones), staves, orbs (all with a value of 1) and circlets (circlet=3, Coronet=8, Tiara=13, Diadem=1.

When an item is generated that has affixes the alvl is calculated* from ilvl and qlvl as follows

If (ilvl>99) then {ilvl=99}
if (qlvl>ilvl) then {ilvl=qlvl} ;** see note below
if (magic_lvl>0) then {alvl=ilvl+magic_lvl}
else
{
if (ilvl<(99-qlvl/2))
then {alvl=ilvl-qlvl/2}
else {alvl=2*ilvl-99}
}
If (alvl>99) then {alvl=99}

*all calculations use integers so there are no fractions at any step.
** this new ilvl value is only used for the duration of this calculation. The ilvl value that is stored in the items data file will remain unchanged.

*/

/*
name: ��Ʒ��ָ�����֣�ע���ã�

type:itemtypes.txt��Ĵ��룻

type2: itemtypes.txt��Ĵ��룻

code: ��Ʒ���룬�����ظ���3����ĸ�����֣�

alternategfx: װ���Ϻ󣬽�ɫ�Ķ��������磬��¶�����һ����KIT��Ұ���ˣ�BA��װ�������ֶ���
��SH������ͨ����������A1������BASHKITA11HS.DCC�����3����ĸ��WCLASS�У�

namestr: �ַ���������

version: �汾��

compactsave: �浵�Ƿ�ѹ������������Ʒ������ֻ��һ�֣��Ͳ��ü�¼���������ˣ���

rarity: 0 = ��װ�������޳�������Ʒ���κ���Ϣ��1���߸�������ֿ��Ե���������Ʒ�ĵ����ʡ�˵����������Ӧ��ӵ��1�����ϵĴ�����ֵ��Ϊ���װ����������Ϸ�ͻ������޷��������У�

spawnable: �Ƿ��ܹ���NPC���ۡ�˵�����������ܷ񱻳��۵Ĺؼ��趨������������λ�ã����TXT�ļ������趨��1=�ܹ���NPC���ۣ�0=�޷����ۣ�

mindam: ������С�˺���

maxdam: ��������˺���

1or2handed: ����Ұ�����ܷ�������һ��˫��������

2handed: �Ƿ�˫��������

2handmindam: ˫����С�˺���

2handmaxdam: ˫������˺���

minmisdam: Զ����С�˺���

maxmisdam: Զ������˺���

rangeadder: ��ս�����Ĺ�����Χ��������1����

speed: Ӱ���ɫ�����ٶȣ�ԽС���ܵ�Խ�죻

StrBonus: ������������ʱ��ÿ100��������StrBonus%���������Ĺ�������

DexBonus: ������������ʱ��ÿ100�����ݼ�DexBonus%���������Ĺ�������

reqstr: ������Ҫ��0-65535������65535����ȥһ��65535����

reqdex: ������Ҫ��0-65535������65535����ȥһ��65535����

durability: �;ã�0-255�������Ĳ���ͬ�ϣ���

nodurability: Ϊ1ʱ�������𻵣�

level: �ȼ���

levelreq: �ȼ���Ҫ��

cost:�۸�

gamble cost:���ò���������Ϊ�ο���

magic lvl: ��Ʒħ��������Ҫ�ļ���

auto prefix: �����ħ��ǰ��׺��ͬautomagic.txt�ļ�������

OpenBetaGfx: ���ò�����

normcode/ubercode/ultracode: ��Ʒ��Ӧ����ͨ����չ��������Ʒ���룬����/����ʱʹ�ã�

wclass/2handedwclass: ����������������DCC�ļ��������3����ĸ��

component: ��ɫʹ�ô���Ʒʱ��������һ�㣨Layer����ͬcomposit.txt�ļ�������

hit class: ���˱�����ʱ������Ч����

invwidth: ��

invheight: �ߣ�

stackable: �Ƿ�Ϊһ�����壨����˵������������1=�ǣ�0=���ǣ�

minstack:��Ϊ�������С��Ŀ��

maxstack: ��Ϊ����������Ŀ��

spawnstack: �������ʱ����Ŀ��

flippyfile: ����ʱ�Ķ�����

invfile: ����Ʒ�������õ�ͼ��

uniqueinvfile: ������Ʒ����Ʒ�������õ�ͼ��

setinvfile: ��װ��Ʒ����Ʒ�������õ�ͼ��

hasinv: �ܷ��ף�

gemsockets: �׵������Ŀ��

gemapplytype: ��ʯ��Ч����0������1���к�ñ�ӣ�2���ƣ�

special: ���ã�

useable: �ܷ��Ҽ�ʹ�ã�

dropsound: ����ʱ����Ч��

dropsfxframe: ��Ч��֡����

usesound: ʹ��ʱ����Ч��

unique: �Ƿ����ǰ���������Ʒר�ã�

transparent: δ֪��

transtbl: δ֪��

quivered: �Ƿ�ҩ��

lightradius: ���ã�

belt:ͬbelts.txt�е�����ID������ҩˮ�ķ�����������

quest: ����ID��������Ʒ�ã�

questdiffcheck: �Ƿ�������Ʒ��

missiletype: Ͷ��ʱ�õ�Ͷ����(missiles.txt���ID) ��

durwarning: Ͷ��ʱ��ʣ�¶���ʱ���棻

qntwarning: Ͷ��ʱ��ʣ�¶���ʱ���棻

gemoffset: δ֪��

bitfield1: 1��Ƥ���ƣ�3�������ƣ�

VendorsMin: NPC���������Ʒʱ����С������

VendorsMax: NPC���������Ʒʱ�����������

VendorsMagicMin: NPC���������Ʒʱ�����ܰ�����ħ�����Ե������

VendorsMagicMax: NPC���������Ʒʱ�����ܰ�����ħ�����Ե�����

vendorsMagicLvl: ħ������Ʒ�ڳ���ʱ���ܰ���������ħ��ǰ��׺����˵����ͬMagicPrefix.txt��MagicSuffix��AutoMagic�����ļ�������

Source Art: ���ò�����

Game Art: ���ò�����

Transform and invTrans: ���������߳���ʹ����һ�����嶯����

SkipName: �Ƿ�������������ƣ�����˵��viper amulet��

NightmareUpgrade: �ڡ����Ρ��Ѷ��£�������Ʒ�ĳ��۴��루xxx=�ޱ仯����

HellUpgrade: �ڡ��������Ѷ��£�������Ʒ�ĳ��۴��루xxx=�ޱ仯����

nameable: �Ƿ��ܹ�������������ACT5�е�Q3����1=����0=������

PermStoreItem: ��Ʒ�Ƿ����г��ۡ�
*/

/*
mindam��������С�˺���

maxdam����������˺���

1or2handed������Ұ������˵�ܷ��õ����������˫��������0��ʾ���ܣ�1��ʾ�ܡ�

2handed���Ƿ���˫��������0��ʾ���ǣ�1��ʾ�ǡ�

2handmindam��˫����С�˺���

2handmaxdam��˫������˺���

minmisdam��Զ�̹���ʱ����С�˺���

maxmisdam��Զ�̹���ʱ������˺���

rangeadder����ս�����Ĺ�����Χ��������1����

reqdex��װ���������ݡ�

wclass�����ֹ���ʱ�Ķ�������WeaponClass.txt�ļ�������

2handedwclass��˫�ֹ���ʱ�Ķ�������WeaponClass.txt�ļ�������

hitclass��������

questDiffCheck�������Ѷȼ�顣����ͨ�ļ��ñ�����������ɵ���������

*/

struct D2WeaponClassTxt
{
   union
   {
      unsigned int dwCode;               //0x00
      char szCode[4];               //0x00
   };
};

typedef struct
{
    unsigned char vflippyfile[32];

    unsigned char vinvfile[32];

    unsigned char vuniqueinvfile[32];

    unsigned char vsetinvfile[32];

    unsigned char vcode[4];

    unsigned char vnormcode[4];

    unsigned char vubercode[4];

    unsigned char vultracode[4];

    unsigned char valternateGfx[4];

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

    unsigned char vwclass[4];

    unsigned char v2handedwclass[4];

    unsigned int iPadding50;
    unsigned int iPadding51;
    unsigned int iPadding52;

    unsigned int vgamblemyspcost;

    short vspeed;
    unsigned char iPadding54[2];

    unsigned char vbitfield1;
    unsigned char iPadding55[3];

    unsigned int vcost;

    unsigned int vminstack;
    unsigned int vmaxstack;
    unsigned int vspawnstack;

    unsigned char vgemoffset;
    unsigned char iPadding60[3];

    unsigned short vnamestr;    //string
    unsigned short vversion;

    unsigned short vautomyspprefix;
    unsigned short vmissiletype;

    unsigned char vrarity;
    unsigned char vlevel;
    unsigned char vmindam;
    unsigned char vmaxdam;

    unsigned char vminmisdam;
    unsigned char vmaxmisdam;
    unsigned char v2handmindam;
    unsigned char v2handmaxdam;

    unsigned short vrangeadder;
    unsigned short vStrBonus;

    unsigned short vDexBonus;
    unsigned short vreqstr;

    unsigned short vreqdex;
    unsigned char iPadding67;
    unsigned char vinvwidth;

    unsigned char vinvheight;
    unsigned char iPadding68;
    unsigned char vdurability;
    unsigned char vnodurability;

    unsigned char iPadding69;
    unsigned char vcomponent;
    unsigned char iPadding69_1[2];

    unsigned int iPadding70;

    unsigned char v2handed;
    unsigned char vuseable;
    unsigned short vtype;   //itemtypes

    unsigned short vtype2;   //itemtypes
    unsigned short iPadding72;

    unsigned short vdropsound;
    unsigned short vusesound;

    unsigned char vdropsfxframe;
    unsigned char vunique;
    unsigned char vquest;
    unsigned char vquestdiffcheck;

    unsigned char vtransparent;
    unsigned char vtranstbl;
    unsigned char iPadding75;
    unsigned char vlightradius;

    unsigned char vbelt;
    unsigned char iPadding76;
    unsigned char vstackable;
    unsigned char vspawnable;

    unsigned char iPadding77;
    unsigned char vdurwarning;
    unsigned char vqntwarning;
    unsigned char vhasinv;

    unsigned char vgemsockets;
    unsigned char iPadding78[3];

    unsigned char vhitmyspclass;  //hitclass
    unsigned char v1or2handed;
    unsigned char vgemapplytype;
    unsigned char vlevelreq;

    unsigned char vmagicmysplvl;
    unsigned char vTransform;
    unsigned char vInvTrans;
    unsigned char vcompactsave;

    unsigned char vSkipName;
    unsigned char vNameable;
    unsigned char vAkaraMin;
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
    unsigned char vAkaraMax;

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

    unsigned char vAkaraMagicMin;
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
    unsigned char vAkaraMagicMax;
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
    unsigned char vAkaraMagicLvl;
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
    unsigned char iPadding102;

    unsigned char vNightmareUpgrade[4];

    unsigned char vHellUpgrade[4];

    unsigned int vPermStoreItem;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vcode[5];
} ST_WEAPON;

static char *m_apcInternalProcess[] =
{
    "name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "OpenBetaGfx",
    "special",
    "quivered",
    "Source Art",
    "Game Art",
    NULL,
};

static unsigned int m_iWeaponCount = 0;
static ST_WEAPON *m_astWeapon = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astWeapon, ST_WEAPON);

char *Weapons_GetWeaponCode(unsigned int id)
{
    if ( id >= m_iWeaponCount )
    {
        return NULL;
    }

    return m_astWeapon[id].vcode;
}

unsigned int Weapons_GetWeaponCount()
{
    return m_iWeaponCount;
}

static char *Weapons_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vcode);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

static int Weapons_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

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
            strncpy(acOutput, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        }

        return 1;
    }

    return 0;
}

static int Weapons_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "code") )
    {
        strncpy(m_astWeapon[m_iWeaponCount].vcode, pstLineInfo->vcode, sizeof(pstLineInfo->vcode));
        String_Trim(m_astWeapon[m_iWeaponCount].vcode);
        m_iWeaponCount++;
    }

    return result;
}

static int Weapons_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "dropsound") )
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
    else if ( !strcmp(acKey, "namestr") )
    {
        pcResult = String_FindString(pstLineInfo->vnamestr, "dummy");
        if ( pcResult )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            //acOutput[0] = 0;
            strcpy(acOutput, pstLineInfo->vcode);
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "type") )
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
    else if ( !strcmp(acKey, "hit class") )
    {
        pcResult = HitClass_GetClassStr(pstLineInfo->vhitmyspclass);
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

int process_weapons(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, uniqueinvfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setinvfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, normcode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ubercode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ultracode, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, alternateGfx, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, wclass, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handedwclass, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gamblemyspcost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, speed, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bitfield1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cost, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxstack, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnstack, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemoffset, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, namestr, USHORT);    //string
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, automyspprefix, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missiletype, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mindam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxdam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmisdam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmisdam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handmindam, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handmaxdam, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rangeadder, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrBonus, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DexBonus, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqstr, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, reqdex, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invwidth, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invheight, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durability, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nodurability, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, component, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 2handed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, useable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type, USHORT);   //itemtypes

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, type2, USHORT);   //itemtypes

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, unique, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, quest, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questdiffcheck, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transparent, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transtbl, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemsockets, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightradius, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, belt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stackable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, durwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, qntwarning, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hasinv, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemsockets, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hitmyspclass, UCHAR);  //hitclass
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, 1or2handed, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gemapplytype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, magicmysplvl, UCHAR);
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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PermStoreItem, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_iWeaponCount = 0;

            m_stCallback.pfnConvertValue = Weapons_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(hitclass, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            File_CopyFile(acTemplatePath, acTxtPath, "weaponclass", ".txt");

            //m_stCallback.pfnGetKey = Weapons_GetKey;
            m_stCallback.pfnConvertValue = Weapons_ConvertValue;
            m_stCallback.pfnFieldProc = Weapons_FieldProc;
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

