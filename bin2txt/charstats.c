#include "global.h"

#define FILE_PREFIX "charstats"

/*
Title 	CharStats.txt
Description 	by Nefarius
Sent by 	
class: The character class this line refers to (this is just a reference field, you can't actually change this).

str: The amount of strength this character class will start with.

dex: The amount of dexterity this character class will start with.

int: The amount of energy and mana this character class will start with.

vit: The amount of vitality and a portion of life this character class will start with.

tot: This field is not used by the game, and never served any purpose, it's only there as reference (it contains the sum of str, dex, int and hp).

stamina: The amount of stamina this character class will start with.

hpadd: The amount of life added to the amount of life granted by the vit column.

PercentStr: Unused (but loaded by code and repurposeable).

PercentDex: Unused (but loaded by code and repurposeable).

PercentInt: Unused (but loaded by code and repurposeable).

PercentVit: Unused (but loaded by code and repurposeable).

ManaRegen: The number of seconds that need to elapse until mana is completely regenerated, thus lower values make mana regenerate faster, higher values slow the process down.

ToHitFactor: This value is added to the basic attack rating of this character class (not that this really makes a difference later on). WARNING: Unless you alter the attack rating calculation in the games code, large negative values here will give the 
characters negative attack rating early on.

WalkVelocity: The speed of this character class when walking (used to be 7 prior to LoD).

RunVelocity: The speed of this character class when running (used to be 11 prior to LoD).

RunDrain: Rate at which this character class burns stamina when running, the lower the value the slower the loss of stamina.

Comment: I really wonder what this could be!?

LifePerLevel: Amount of life earned for each level up. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

StaminaPerLevel: Amount of stamina earned for each level up. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

ManaPerLevel: Amount of mana earned for each level up. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

LifePerVitality: Amount of life earned for each point invested in vitality. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

StaminaPerVitality: Amount of stamina earned for each point invested in vitality. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

ManaPerMagic: Amount of mana earned for each point invested in energy. This value is in fourths, thus the lowest bonus possible is 64/256 (on quarter of one on-screen point, the fractional value is used by the game however).

StatPerLevel: Amount of stat points earned at each level up.

#walk: Reference field, contains the length of the WL animation in frames.

#run: Reference field, contains the length of the RN animation in frames.

#swing: Reference field, contains the length of the A1 animation (when wielding a melee weapon) in frames.

#spell: Reference field, contains the length of the SC animation in frames.

#gethit: Reference field, contains the length of the GH animation in frames.

#bow: Reference field, contains the length of the A1 animation (when wielding a bow) in frames.

BlockFactor: The amount of blocking that is added to the base shield blocking from Armor.txt for display and calculation purposes.

StartSkill: An ID pointer from Skills.txt, this controls what skill bonus will spawn on the characters starting weapon.

Skill 1 to Skill 10: The skills that this character class starts with (these skills will always be available from cLvl 1 onwards), obviously these are ID pointers from Skills.txt too.

StrAllSkills: This field tells the game what string to display for the bonus to all class skills (ex: +1 to all Amazon skills).

StrSkillTab1: This field tells the game what string to display for the bonus to all skills of the first skill tab (ex: +1 to all Bow and Crossbow skills).

StrSkillTab2: This field tells the game what string to display for the bonus to all skills of the second skill tab (ex: +1 to all Passive and Magic skills).

StrSkillTab3: This field tells the game what string to display for the bonus to all skills of the third skill tab (ex: +1 to all Javelin and Spear skills).

StrClassOnly: This field tells the game what string to display for class specific items (and class specific skill boni) (ex: Amazon Only).

baseWClass: What weapon class will the game default to when no weapon is equipped (by default this is 'hth', which makes the game load the DCC files associated with that animation, and thus the player appears unarmed, for example you could change this 
to '1hs' and the player will appear as if wielding an invisible 1-handed slashing weapon.

item1 to item10: This field is an ID pointer from Weapons.txt, Armor.txt and Misc.txt, it controls what item this character will start with (aka the newbie equipment). To make a character start with the horadric cube for example you would set this to '
box' (without the quotes of course).

item1loc to item10loc: The location in which the associated item will be placed, this is an ID pointer from BodyLocs.txt, to make the item appear in the inventory leave this field blank, if the item can be placed in the belt it will be created there (as 
long as there are belt slots left).

item1count to item10count: The amount of items of the associated item type to create, thus if you want to make your character start with 8 rather then 4 health potions you'd set the value to 8 rather then 4.

*/

/*
ÿ�еĺ������£�

class��ְҵ���ơ�

str��ÿ��ְҵ�ĳ�ʼ����ֵ��

dex��ÿ��ְҵ�ĳ�ʼ����ֵ��

int��ÿ��ְҵ�ĳ�ʼ����ֵ��

vit��ÿ��ְҵ�ĳ�ʼ����ֵ��

tot��ÿ��ְҵ�ĳ�ʼ����ֵ���ܺ͡�ʵ����û���ô�������ɾ����

stamina��ÿ��ְҵ�ĳ�ʼ����ֵ��

Hpadd��ÿ��ְҵ�ĳ�ʼ����ֵ���������������������������ʱ������ֵ���ܻ�õ����������ֵ��

��ɫ�����ճ�ʼ����ֵΪhpadd + vit��

PercentStr�����ò�����

PercentDex�����ò�����

PercentInt�����ò�����

PercentVit�����ò�����

ManaRegen��ÿ��ְҵ�ĳ�ʼħ��ֵ�ظ��ٶȣ�����Ϊ��ħ��ֵΪ0���ظ�����Ҫ�����롣���Դ��е�ֵԽСħ���ظ��ٶ�Խ�졣

ToHitFactor��ÿ��ְҵ�ĳ�ʼ����׼ȷ�ʻ�����

WalkVelocity��ÿ��ְҵ�ĳ�ʼ��·�ٶȡ�

RunVelocity��ÿ��ְҵ�ĳ�ʼ�ܲ��ٶȡ�

RunDrain��ÿ��ְҵ�ܲ�ʱ�������½��ٶȡ���ֵԽС��ʾ�ܲ�ʱ�������ٵ�Խ����

Comment�����ò���������ɾ����

LifePerLevel��ÿ��ְҵ����ʱ���ӵ�����ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵ�����ֵ��

StaminaPerLevel��ÿ��ְҵ����ʱ���ӵ�����ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵ�����ֵ��

ManaPerLevel��ÿ��ְҵ����ʱ���ӵķ���ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵķ���ֵ��

LifePerVitality��ÿ��ְҵÿ��һ���������ӵ�����ֵ���ӣ�����4��Ϊÿ������ʵ�����ӵ�����ֵ��

StaminaPerVitality��ÿ��ְҵÿ��һ������ֵ���ӵ�����ֵ���ӣ�����4��Ϊÿ������ʵ�����ӵ�����ֵ��

ManaPerMagic��ÿ��ְҵÿ��һ�㾫�����ӵķ���ֵ���ӣ�����4��Ϊÿ�㾫��ֵʵ�����ӵķ���ֵ��

#walk��ÿ��ְҵ��·ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

#run��ÿ��ְҵ�ܲ�ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

#swing��ÿ��ְҵ�ý�ս��������ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

#spell��ÿ��ְҵʹ�÷���ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

#gethit��ÿ��ְҵ������ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

#bow��ÿ��ְҵ�ù�����ʱ�Ķ����ĳ��ȣ���֡Ϊ��λ��

BlockFactor��ÿ��ְҵʹ�ö���ʱ�Ļ����񵲸��ʡ���ֵ��ӵ����Ƹ��ʵ���ʾ�С�

StartSkill��ÿ��ְҵ�ĳ�ʼ�����������ӵļ��ܡ���Skills.txt������

Skill 1-10��ÿ��ְҵ�Ļ������ܣ�����Ͷ�����߻����سǡ���ʶ������ٻ��ȡ�

StrAllSkills���Ӵ�ְҵ���ܵ����Ե���ʾ�ַ������硰+3 ��ʦ���ܵȼ�����

StrSkillTab1-3���Ӵ�ְҵ��1-3������ϵ�����Ե���ʾ�ַ������硰+3 ����ϵ���ܡ���

StrClassOnly���޴�ְҵʹ�õ����Ե���ʾ�ַ������硰��Ұ����ʹ�á���

baseWClass������ʱĬ��ʹ�õ��������͡���Ĭ��Ϊ�������ͣ���Ҳ����һ���������ͣ�����WeaponClass.txt������

item 1-10��ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�

item 1-10 loc��ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�

item 1-10 count��ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������

*/

typedef struct
{
    char vitem[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitemloc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitemcount;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding[2];  //����ֽڣ�������
} ST_ITEM_INFO;

typedef struct
{
    char acHead[32];    //����ֽڣ�������

    char vclass[16];   //ְҵ���ơ�

    unsigned char vstr;          //ÿ��ְҵ�ĳ�ʼ����ֵ��
    unsigned char vdex;          //ÿ��ְҵ�ĳ�ʼ����ֵ��
    unsigned char vint;          //ÿ��ְҵ�ĳ�ʼ����ֵ��
    unsigned char vvit;          //ÿ��ְҵ�ĳ�ʼ����ֵ��

    //tot��ÿ��ְҵ�ĳ�ʼ����ֵ���ܺ͡�ʵ����û���ô�������ɾ����
    unsigned char vstamina;      //ÿ��ְҵ�ĳ�ʼ����ֵ��
    unsigned char vhpadd;        //ÿ��ְҵ�ĳ�ʼ����ֵ������
    //��ɫ�����ճ�ʼ����ֵΪhpadd + vit��
    unsigned char vPercentStr;   //���ò�����
    unsigned char vPercentInt;   //���ò�����

    unsigned char vPercentDex;   //���ò�����
    unsigned char vPercentVit;   //���ò�����
    unsigned char vManaRegen;   //ÿ��ְҵ�ĳ�ʼħ��ֵ�ظ��ٶȣ�����Ϊ��ħ��ֵΪ0���ظ�����Ҫ�����롣���Դ��е�ֵԽСħ���ظ��ٶ�Խ�졣
    unsigned char bUnknown;

    int vToHitFactor;   //ÿ��ְҵ�ĳ�ʼ����׼ȷ�ʻ�����

    unsigned char vWalkVelocity; //ÿ��ְҵ�ĳ�ʼ��·�ٶȡ�
    unsigned char vRunVelocity;  //ÿ��ְҵ�ĳ�ʼ�ܲ��ٶȡ�
    unsigned char vRunDrain;     //ÿ��ְҵ�ܲ�ʱ�������½��ٶȡ���ֵԽС��ʾ�ܲ�ʱ�������ٵ�Խ����
    unsigned char vLifePerLevel; //ÿ��ְҵ����ʱ���ӵ�����ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵ�����ֵ��

    unsigned char vStaminaPerLevel;  //ÿ��ְҵ����ʱ���ӵ�����ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵ�����ֵ��
    unsigned char vManaPerLevel; //ÿ��ְҵ����ʱ���ӵķ���ֵ���ӣ�����4��Ϊÿ��ʵ�����ӵķ���ֵ��
    unsigned char vLifePerVitality;  //ÿ��ְҵÿ��һ���������ӵ�����ֵ���ӣ�����4��Ϊÿ������ʵ�����ӵ�����ֵ��
    unsigned char vStaminaPerVitality;   //ÿ��ְҵÿ��һ������ֵ���ӵ�����ֵ���ӣ�����4��Ϊÿ������ʵ�����ӵ�����ֵ��

    unsigned char vManaPerMagic; //ÿ��ְҵÿ��һ�㾫�����ӵķ���ֵ���ӣ�����4��Ϊÿ�㾫��ֵʵ�����ӵķ���ֵ��
    unsigned char vBlockFactor;  //ÿ��ְҵʹ�ö���ʱ�Ļ����񵲸��ʡ���ֵ��ӵ����Ƹ��ʵ���ʾ�С�
    char acPadding[2];  //����ֽڣ�������

    char vbaseWClass[4];   //����ʱĬ��ʹ�õ��������͡���Ĭ��Ϊ�������ͣ���Ҳ����һ���������ͣ�����WeaponClass.txt������

    unsigned char vStatPerLevel; //
    unsigned char iPadding1;
    unsigned short vStrAllSkills;

    unsigned short vStrSkillTab1;
    unsigned short vStrSkillTab2;

    unsigned short vStrSkillTab3;
    unsigned short vStrClassOnly;

    char vitem1[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem1loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem1count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding3[2];  //����ֽڣ�������

    char vitem2[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem2loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem2count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding4[2];  //����ֽڣ�������

    char vitem3[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem3loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem3count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding5[2];  //����ֽڣ�������

    char vitem4[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem4loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem4count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding6[2];  //����ֽڣ�������

    char vitem5[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem5loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem5count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding7[2];  //����ֽڣ�������

    char vitem6[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem6loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem6count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding8[2];  //����ֽڣ�������

    char vitem7[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem7loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem7count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding9[2];  //����ֽڣ�������

    char vitem8[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem8loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem8count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding10[2];  //����ֽڣ�������

    char vitem9[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem9loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem9count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding11[2];  //����ֽڣ�������

    char vitem10[4]; //ÿ��ְҵ�ĵ�1-10����ʼ���ߡ�
    unsigned char vitem10loc;      //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�λ�á�index����Ӧbodylocs.txt
    unsigned char vitem10count;    //ÿ��ְҵ�ĵ�1-10����ʼ���ߵ�������
    char acPadding12[2];  //����ֽڣ�������

    unsigned short vStartSkill;  //ÿ��ְҵ�ĳ�ʼ�����������ӵļ��ܡ���Skills.txt������index FF��Ч����Ӧskills.txt
    unsigned short vSkillmysp1;  //ÿ��ְҵ�Ļ������ܣ�����Ͷ�����߻����سǡ���ʶ������ٻ��ȡ�index FF��Ч����Ӧskills.txt
    unsigned short vSkillmysp2;
    unsigned short vSkillmysp3;
    unsigned short vSkillmysp4;
    unsigned short vSkillmysp5;
    unsigned short vSkillmysp6;
    unsigned short vSkillmysp7;
    unsigned short vSkillmysp8;
    unsigned short vSkillmysp9;
    unsigned short vSkillmysp10;

    char acTail[2];     //����ֽڣ�������
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "tot",
    "Comment",
    "#walk",
    "#run",
    "#swing",
    "#spell",
    "#gethit",
    "#bow",
    NULL,
};

static char *CharStats_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vclass, sizeof(pstLineInfo->vclass));
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

static int CharStats_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int id;
    char *pcResult;
    int result = 0;

    if ( strstr(acKey, "loc") && 1 == sscanf(acKey, "item%dloc", &id) )
    {
        ST_ITEM_INFO *pstItemInfo = (ST_ITEM_INFO *)pstLineInfo->vitem1;
        pcResult = BodyLocs_GetLocStr(pstItemInfo[id - 1].vitemloc);
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
    else if ( !strcmp(acKey, "StartSkill") )
    {
        pcResult = Skills_GetSkillName(pstLineInfo->vStartSkill);
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
    else if ( 1 == sscanf(acKey, "Skill %d", &id) )
    {
        unsigned short *psSkill = (short *)&pstLineInfo->vSkillmysp1;
        pcResult = Skills_GetSkillName(psSkill[id-1]);
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
    else if ( !strcmp(acKey, "StrAllSkills") )
    {
        pcResult = String_FindString(pstLineInfo->vStrAllSkills, NULL);
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
    else if ( !strcmp(acKey, "StrSkillTab1") )
    {
        pcResult = String_FindString(pstLineInfo->vStrSkillTab1, NULL);
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
    else if ( !strcmp(acKey, "StrSkillTab2") )
    {
        pcResult = String_FindString(pstLineInfo->vStrSkillTab2, NULL);
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
    else if ( !strcmp(acKey, "StrSkillTab3") )
    {
        pcResult = String_FindString(pstLineInfo->vStrSkillTab3, NULL);
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
    else if ( !strcmp(acKey, "StrClassOnly") )
    {
        pcResult = String_FindString(pstLineInfo->vStrClassOnly, NULL);
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

int process_charstats(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, str, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, int, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, vit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stamina, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, hpadd, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentStr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentInt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentDex, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PercentVit, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaRegen, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ToHitFactor, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, WalkVelocity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunVelocity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, RunDrain, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifePerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaminaPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifePerVitality, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaminaPerVitality, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaPerMagic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BlockFactor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseWClass, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StatPerLevel, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrAllSkills, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrSkillTab3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrClassOnly, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item4count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item5count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item6count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item7count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item8count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item9count, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10loc, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item10count, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StartSkill, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp7, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp8, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp9, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skillmysp10, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnGetKey = CharStats_GetKey;
            m_stCallback.pfnConvertValue = CharStats_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

