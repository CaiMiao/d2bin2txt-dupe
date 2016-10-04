#include "global.h"

#define FILE_PREFIX "hireling"

/*
Title 	Hireling.txt File Guide
Description 	by Draco & Ric Faith
Sent by 	
OVERVIEW:

This file handles everything related to hirelings. In here you set what hirelings that is avaible to hire, what items they are able to use, their stats and what skills they are using.

RELATED .TXT FILES:

This file is using:

    ItemTypes.txt
    Skills.txt



COLUMN DESCRIPTIONS :

Hireling 	Description of hireling type, this column has no function, it only serves as a comment field to make it easier.
SubType 	Description of hireling sub-type, this column has no function, it only serves as a comment field to make it easier.
Version 	Classic = 0, Expansion = 100
Id 	ID number to segregate the hirelings and threshold lvls.
Class 	reference to column 'hcIdx' in monstats.txt for monster class.
Act 	Act where merc can be hired.
Difficulty 	Normal = 1, NM = 2, Hell = 3
Level 	rmlvl of the hireling (what level is required to 'upgrade' skills/stats)
Seller 	reference to column 'hcIdx' in monstats.txt for NPC.
NameFirst, NameLast 	Range from which the game looks to get random names for the hirelings.
Gold 	Cost of hireling, compounded by mlvl
Exp/Lvl 	Factor used in the calculation of Exp required between mlvls. The threshold for the next level (L+1) from the current level (L) is (exp/lvl)*L*L*(L+1).
HP 	Life at Base Lvl.
HP/Lvl 	Amount of additional Life given at Lvl up.
Defence 	DR (Defence Rating) at Base Lvl.
Def/Lvl 	Amount of additional DR given at Lvl up.
Str 	Strength at Base Lvl.
Str/Lvl 	Amount (in 8ths) of additional Strength given at Lvl up.
Dex 	Dexterity at Base Lvl.
Dex/Lvl 	Amount (in 8ths) of additional Dexterity given at Lvl up.
AR 	Attack Rating at Base Lvl.
AR/Lvl 	Amount of additional AR given at Lvl up.
Share 	Used to co-relate between threshold lvls between Normal, NM, Hell Hirelings.
Dmg-Min, Dmg-Max 	Range of Damage dealt at Base lvl.
Dmg-Lvl 	Amount (in 8ths) of additional Damage given at Lvl up.
Resist 	All Resistance at Base Lvl.
Resist/Lvl 	Amount (in 8ths) of additional All Resist given at lvl up.
WType1, WType2 	Can't be changed, is the itemtype of the items that can be carried in weapon slots.
HireDesc 	A reference for .tbl files.
Default Chance 	The Chance that Hireling will use weapon and normal attack instead skill.
Skill (1-6) 	Reference to Skill column in skills.txt.
Mode (1-6) 	The Mode to use for the skill:
Generally-
1 -> Auras
4 -> Attack
5 -> Attack (use for Barbs, works the same way as Mode=4)
7 -> Cast
14-> Seq (use for Jab)
Chance (1-6) 	The Chance that hireling will use Skill at Base Lvl:
It is calculated by probability: Using the example for Normal Fire Rogue, 1st Threshold,
Default Chance = 75, Inner Sight = 10, Fire Arrow = 25
So by probability (Chance/TotChance *100%):
Default (Attack) = 75/110 *100% = 68.18%
Inner Sight = 10/110 *100% = 9.09%
Fire Arrow = 25/110 *100% = 22.73%
To move along to the 2nd Threshold:
Default Chance = 75, Inner Sight = 10, Fire Arrow = 69
So: Default (Attack) = 48.70%, Inner Sight = 6.49%, Fire Arrow = 44.81%
So you can see, when you go from one threshold to the next, the values may change depending on your Chance set. Ideally you should push your intended favourite higher so it will occur more often.
ChancePerLevel (1-6) 	Amount of additional Chance given at lvl up, used to improve the chances of certain skills as during leveling .
Level (1-6) 	The sLvl of the Skill at Base lvl.
LvlPerLvl (1-6) 	Factor in improving slvl at lvl up (0=no increment).
Head, Torso, Weapon, Shield 	References to the anims for monster parts. 

*/

/*
�ļ���������
Hireling����Ӷ����
���Դ��ļ������������й�Ӷ������Ϣ��
���ļ��е�ÿһ�б�ʾһ����Ӷ����Ϣ��

ÿ�еĺ������£�

Hireling��Ӷ�������ƣ�����Ϊע�͡�

SubType��Ӷ�������ͣ�����Ϊע�͡�

Version��Ӷ�����ֵİ汾��0Ϊ������Ƭ��100Ϊ����Ƭ��

Id��Ӷ���ı�ţ���ͬ���ƻ���ͬ���Ʋ�ͬ���͵�Ӷ����Ų�����ͬ��

Class��Ӷ���Ĺ������ͣ���MonStats.txt������

Act����Ӷ���Ĺ�Ӷ�ص㡣

Difficulty����Ӷ��Ӷ�����Ѷȼ���1������ͨ��2������Σ�3���������

Level��Ӷ���Ľ��׼���ÿ��Ӷ������ĳһ���׼���ʱ��������ݴ��к�����д�Ĳ����ı�Ӷ���ĳɳ������ָı�һ�����Ϊ�ɳ����ӣ���ÿ��һ�����������������ӣ������ҽ����֮Ϊ���׼���

Seller��Ӷ�������˵ı�ţ�����˵��Ӷ���ĳ����ߡ���Monstats.txt������

NameFirst���ַ�����ţ���Ӷ��������أ��������˵����

NameLast���ַ�����ţ���Ӷ��������أ��������˵����

Ӷ���������Ǵ���Ϸ�ڲ��������б������ѡȡ�ģ����б���ÿ�����ֶ���һ����š�����Ӷ�����ֵ��ַ�����ű��봦��NameFirst��NameLast֮�䣬���߽硣

Gold��Ӷ���ļ۸������ע�⣺����۸����Ӷ����ħ���������ͬ

Exp/Lvl��Ӷ��ÿ��һ������Ҫ�ľ���ֵ������

HP��Ӷ���ڳ�ʼ���������ֵ��

Hp/Lvl��ÿ��һ�������ӵ�����ֵ����˥�����ӣ������е�ֵ�Ƕ�����ÿ��һ���Ӷ���������

Defense��Ӷ���ڽ��׼���ʱ�Ļ�������ֵ��Ӷ���ڲ���װ������µķ���ֵΪ��������ֵ + ����/4��

Def/Lvl��ÿ��һ�������ӵĻ�������ֵ����˥�����ӣ������е�ֵ�Ƕ�����ÿ��һ���Ӷ��ٷ�����

Str��Ӷ���ڽ��׼���ʱ��������

Str/Lvl��ÿ��һ�������ӵ�������˥������Ϊ8���������е�ֵ��8����ÿ��һ����8/8=1��������

Dex��Ӷ���ڽ��׼���ʱ�����ݡ�

Dex/Lvl��ÿ��һ�������ӵ����ݣ�˥������Ϊ8���������е�ֵ��8����ÿ��һ����8/8=1�����ݡ�

AR��Ӷ���ڽ��׼���ʱ�Ļ�������׼ȷ�ʡ�

AR/Lvl��ÿ��һ�������ӵĻ�������׼ȷ�ʡ���˥�����ӡ�

Share����֪��ʲô��˼�Ĳ��������������Ӷ���Ľ�λ��

Dmg-Min��Ӷ���ڽ��׼���ʱ�Ļ�����С�˺�ֵ��Ӷ���ڲ���װ������µ���С�˺�ֵΪ��������С�˺�ֵ * (1 + ����/100)��

Dmg-Max��Ӷ���ڽ��׼���ʱ�Ļ�������˺�ֵ��Ӷ���ڲ���װ������µ�����˺�ֵΪ�����������˺�ֵ * (1 + ����/100)��

Dmg/Lvl��ÿ��һ�������ӵĻ����˺�ֵ��˥������Ϊ8����С�˺�ֵ������˺�ֵ����˲�����

Resist��Ӷ���ڽ��׼���ʱ�Ŀ��ԡ�

Resist/Lvl��ÿ��һ�������ӵĿ��ԣ�˥������Ϊ4��

WType1����ʹ�õĵ�һ�����������ƣ����͡�

WType2����ʹ�õĵڶ������������ƣ����͡�

HireDesc���ڹ���Ӷ��ʱ��ʾ��Ӷ��˵��������ص�*.tbl�ļ���������

Default Chance��Ӷ��ʹ����ͨ������Ƶ�ʡ�

Skill1��Ӷ���ĵ�1�����ܡ�

Mode1��Ӷ����1�����ܵ�MOD��ʹ�÷�ʽ����
Ӷ�����ܵ�ģʽ: 
һ������£�
1 -> �⡢�綯����
4 -> ����������
5 -> ��������(��Ҫ����Ұ����Ӷ������Mode=4����)�� 
7 -> Ͷ����
14-> Jab����ר�ã�

Chance1��Ӷ��ʹ�õ�1�����ܵ�Ƶ�ʡ�

ChancePerLevel1��ÿ��һ�������ӵ�ʹ�õ�1������Ƶ�ʡ�

Level��Ӷ���ڽ��׼���ʱ�ĵ�1�����ܵļ��ܵȼ���

LvlPerLvl1��ÿ��һ���������ӵĵ�1�����ܵļ��ܵȼ���˥������Ϊ32��

����Skill2��Mode2��������LvlPerLvl6�Ƕ�Ӷ������ӵ�еĵ�2��6�����ܵ�����������ο���1�����ܵĽ��͡�

Head�����ò�����ɾ֮Ҳ�ɡ�

Torso�����ò�����ɾ֮Ҳ�ɡ�

Weapon�����ò�����ɾ֮Ҳ�ɡ�

Shield�����ò�����ɾ֮Ҳ�ɡ�

*eol����β��־������Ϊ0��

����˵��1�����ĳһ��Ӷ���ڴ��ļ��ж�Ӧ�˲�ֹһ�ж��������������ôһ�����в�ͬ���׼����ԭ��

����˵��2���ж�����׼����Ӷ���ڹ�Ӷ�˵���ֻ����ʾ������ͽ׵ĳɳ����������״̬���������Ӷ�������ȼ��ﵽ��2�׻���߽׵ļ�����ô�����Ի��Զ����������������ڽ�λ�ĳɳ���������ԾͿ��ܻ�����ڹ�Ӷ�˵�����ʾ��Ӷ��ֻ��1000Ѫ�������Ӷ������1500
Ѫ�������

*/

typedef struct
{
    unsigned int vVersion;
    unsigned int vId;
    unsigned int vClass;
    unsigned int vAct;
    unsigned int vDifficulty;
    unsigned int vSeller;
    unsigned int vGold;
    unsigned int vLevel;
    unsigned int vExpmyslashLvl;
    unsigned int vHP;

    unsigned int vHPmyslashLvl;
    unsigned int vDefense;
    unsigned int vDefmyslashLvl;
    unsigned int vStr;
    unsigned int vStrmyslashLvl;
    unsigned int vDex;
    unsigned int vDexmyslashLvl;
    unsigned int vAR;
    unsigned int vARmyslashLvl;
    unsigned int vShare;

    unsigned int vDmgmysubMin;
    unsigned int vDmgmysubMax;
    unsigned int vDmgmyslashLvl;
    unsigned int vResist;
    unsigned int vResistmyslashLvl;
    unsigned int vDefaultChance;

    unsigned int vHead;
    unsigned int vTorso;
    unsigned int vWeapon;
    unsigned int vShield;

    unsigned int vSkill1;   //skills
    unsigned int vSkill2;
    unsigned int vSkill3;
    unsigned int vSkill4;
    unsigned int vSkill5;
    unsigned int vSkill6;

    unsigned int vChance1;
    unsigned int vChance2;
    unsigned int vChance3;
    unsigned int vChance4;
    unsigned int vChance5;
    unsigned int vChance6;

    unsigned int vChancePerLvl1;
    unsigned int vChancePerLvl2;
    unsigned int vChancePerLvl3;
    unsigned int vChancePerLvl4;
    unsigned int vChancePerLvl5;
    unsigned int vChancePerLvl6;

    unsigned char vMode1;
    unsigned char vMode2;
    unsigned char vMode3;
    unsigned char vMode4;

    unsigned char vMode5;
    unsigned char vMode6;
    unsigned char vLevel1;
    unsigned char vLevel2;

    unsigned char vLevel3;
    unsigned char vLevel4;
    unsigned char vLevel5;
    unsigned char vLevel6;

    unsigned char vLvlPerLvl1;
    unsigned char vLvlPerLvl2;
    unsigned char vLvlPerLvl3;
    unsigned char vLvlPerLvl4;

    unsigned char vLvlPerLvl5;
    unsigned char vLvlPerLvl6;
    unsigned char vHireDesc; //hiredesc
    unsigned char vNameFirst[32];

    unsigned char vNameLast[37];
} ST_LINE_INFO;


static char *m_apcNotUsed[] =
{
    "Hireling",
    "SubType",
    "WType1",
    "WType2",
    NULL,
};

static int Hireling_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( strlen("Skill1") == strlen(acKey) && 1 == sscanf(acKey, "Skill%d", &id) )
    {
        unsigned int *psSkill = &pstLineInfo->vSkill1;

        pcResult = Skills_GetSkillName(psSkill[id - 1]);
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
    else if ( !strcmp(acKey, "HireDesc") )
    {
        pcResult = HireDesc_GetDesc(pstLineInfo->vHireDesc);
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

int process_hireling(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Version, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Id, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Act, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Difficulty, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Seller, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gold, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExpmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HP, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Defense, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DefmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Str, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StrmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dex, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DexmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AR, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ARmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Share, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmysubMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmysubMax, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DmgmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Resist, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResistmyslashLvl, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DefaultChance, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Head, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Torso, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Weapon, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shield, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill1, UINT);   //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Skill6, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Chance6, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl1, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl3, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl4, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl5, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChancePerLvl6, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Mode6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Level6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LvlPerLvl6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HireDesc, UCHAR); //hiredesc
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameFirst, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, NameLast, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(hiredesc, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Hireling_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

