#include "global.h"

#define FILE_PREFIX "DifficultyLevels"
#define NAME_PREFIX "dl"

/*
Title 	Difficultylevels.txt File Guide
Description 	by Nefarius, Joel Falcou, Jarulf & Foxbat
Sent by 	

OVERVIEW :

This file is used for setting some global game parameters that depend on the difficulty levels of the game.

RELATED .TXT FILES :

This file has no link with any other .txt, this is just a simple table of parameters.

COLUMN DESCRIPTIONS :
Name
	Difficulty name. Don't even think to add one.
 
ResistPenalty
	The value removed from the player resistances within this difficulty.
 
DeathExpPenalty
	The percentage of experience you loose at death on this difficulty.
 
UberCodeOddsNormal
	

Not used.

Pre 1.07 this was the percentage of low quality / normal / superior exceptional items dropped on this specific difficulty.
 
UberCodeOddsGood
	

Not used.

Pre 1.07 this was the percentage of magic / rare / set / unique exceptional items dropped on this specific difficulty.
 
UltraCodeOddsNormal
UltraCodeOddsGood
 
	

Not used, and didn't exist pre 1.07.
 
MonsterSkillBonus
	Additional skill points added to monster skills specified in MonStats.txt for this difficulty. It has nothing to do with missile damage bonus.
 
MonsterFreezeDivisor
MonsterColdDivisor
 
	

Divisor values applyed to monsters for their Freezing Length and Cold Length duration for this difficulty.

Don't set this value to zero.
 
AiCurseDivisor
LifeStealDivisor
ManaStealDivisor
 
	Divisor values for AI altering states (Dim Vision, Terror etc), and not other curses, Life Leech and Mana Leech for this difficulty.

Don't set this value to zero if you're modding versions older then v1.10, in v1.10 a value of zero will disable the nerf completely.
 
UniqueDamageBonus
ChampionDamageBonus
 
	Effective percentage of damage and attack rating added to Extra Strong Unique/Minion and Champion monsters.
The bonus equals BonusFromMonUMod/100*ThisField
 
HireableBossDamagePercent  
	This is a percentage of how much damage your Mercenaries do to an Act Boss.

In Hell, since the value is 25, they're doing only 1/4 of their normal damage against a Boss.
 
MonsterCEDamagePercent
	Monster Corpse Explosion damages percent limit.

Monsters HP increase with number of players in the game, and therefore the Corpse Explosion damages increase as well, but these damages are limited per difficulty as what this column indicates.
 
StaticFieldMin
	Minimum percentage of Hit Points left on monsters hit by Static Field.

Setting this column for the 3 Difficulties to 0 will make Static Field work the same way it did in Classic Diablo II.
 
GambleRare
GambleSet
GambleUnique
GambleUber
GambleUltra
 
	Parameters in hardcoded functions that are used when gambling Rare, Set, Unique, Exceptional and Elite items in this Difficulty.

See that link for knowing how the columns works.
 */

/*
�ļ���������
Difficulty Levels���Ѷȼ��𣬼���Ϸ�е���ͨ�����Ρ����������Ѷȡ�
���Դ��ļ�����������Ϸ�������Ѷ��е�һЩ������Ϣ���翹�Գͷ���
���ļ��е�ÿһ�б�ʾһ���Ѷȣ���ʵ�ܹ�Ҳ��3�С�

Name���Ѷȵ����ơ�

ResistPenalty���ڴ��Ѷ��µĿ��Գͷ���

DeathExpPenalty���ڴ��Ѷ���������ʧ�ľ���ֵ��

UberCodeOddsNormal�����ò�����

UberCodeOddsGood�����ò�����

UltraCodeOddsNormal�����ò�����

UltraCodeOddsGood�����ò�����

MonsterSkillBonus���ڴ��Ѷ��¹���ļ��ܵȼ�������
ÿ���Ѷ�����Թ�����⸽�ӵļ��ܵ�������ӦMonStats.txt�жԹ��＼�ܵ��������������ڡ�����ϵħ����Ч��

MonsterFreezeDivisor���ڴ��Ѷ��¹���Ķ���״̬����ʱ���˥�����ӡ�
ÿ���Ѷ��¹������ħ���ĳ�������Ȼ�ǳ������Ͳ���Ϊ0���� 

MonsterColdDivisor���ڴ��Ѷ��¹���ı���״̬����ʱ���˥�����ӡ�

AiCurseDivisor���ڴ��Ѷ��¹���ı�����״̬����ʱ���˥�����ӡ�

LifeStealDivisor���ڴ��Ѷ��»��й�����͵ȡ������ֵ��˥�����ӡ�
ÿ���Ѷ��¹�����䡱����͵Ѫ������͵ħ�������ܵĳ�����ͬ������Ϊ0��

ManaStealDivisor���ڴ��Ѷ��»��й�����͵ȡ������ֵ��˥�����ӡ�

UniqueDamageBonus���ڴ��Ѷ��½���˺��Ķ��������ٷֱȡ�

ChampionDamageBonus���ڴ��Ѷ���ͷĿ���˺��Ķ��������ٷֱȡ�

HireableBossDamagePercent���ڴ��Ѷ��¹�Ӷ����BOSS�˺���˥���ٷֱȡ�
���ÿһ���е�BOSS���������Ӷ�����������˰ٷֱȣ����磺�ڡ��������Ѷ��µ���ֵΪ25����˼���Ƕ���BOSS����Ĺ���ֻ��1/4���˺���

MonsterCEDamagePercent���ڴ��Ѷ��¹��ﱩʬ�˺���˥���ٷֱȡ�
�����ʬ"���ܵİٷֱ����ƣ�˵��һ�£�ͨ���ġ���ʬ���˺��ʶ��Ǹ�����Ϸ�н�ɫ�����������ģ�������ֵ����˼�������ƹ���ı�ʬ���˺��ʡ� 

StaticFieldMin���ڴ��Ѷ��¾�̬�������ܵ�ɱ��������������Ѷȴ���Ϊ50��Ҳ����˵��������ʣ����������50%ʱ����̬��������Ч��0����ʹ��Ĭ��ֵ��
��̬�������ڹ������С�˺�ֵ����������Ѷ��¾��趨Ϊ0�Ļ������Է�����Ƭ��Ĭ��ֵΪ׼��

GambleRare���Ĳ���ϡ�У�������Ʒ��Ƶ�ʡ�

GambleSet���Ĳ�����װ����ɫ����Ʒ��Ƶ�ʡ�

GambleUnique���Ĳ���Ψһ��������Ʒ��Ƶ�ʡ�

GambleUber�����ò�����

GambleUltra�����ò�����

*eol����β��־������Ϊ0��

����GambleUber��GambleUltra���е�˵���������޸����£�

GambleUber���Ĳ�����չ����Ʒ�ĸ��ʡ� 1 + (ilvl - excep qlvl) * GambleUber / 100

GambleUltra���Ĳ�����Ӣ����Ʒ�ĸ��ʡ�1 + (ilvl - elite qlvl) * GambleUltra / 100

����������˵�����Ĳ���ɫ�жϵ�˳����Ӧ�������£�
��ɫ = 100 - ((GambleRare + GambleSet + GambleUnique) / 1000)
���� = (GambleRare - GambleSet - GambleUnique) / 1000
��ɫ = (GambleSet + GambleUnique) / 1000
���� = (GambleUnique) / 1000
*/

typedef struct
{
    int vResistPenalty;
    unsigned int vDeathExpPenalty;
    unsigned int vUberCodeOddsNormal;
    unsigned int vUberCodeOddsGood;

    unsigned int vMonsterSkillBonus;
    unsigned int vMonsterFreezeDivisor;
    unsigned int vMonsterColdDivisor;
    unsigned int vAiCurseDivisor;
    unsigned int vUltraCodeOddsNormal;
    unsigned int vUltraCodeOddsGood;

    unsigned int vLifeStealDivisor;
    unsigned int vManaStealDivisor;
    unsigned int vUniqueDamageBonus;
    unsigned int vChampionDamageBonus;
    unsigned int vHireableBossDamagePercent;
    unsigned int vMonsterCEDamagePercent;

    unsigned int vStaticFieldMin;
    unsigned int vGambleRare;
    unsigned int vGambleSet;
    unsigned int vGambleUnique;

    unsigned int vGambleUber;
    unsigned int vGambleUltra;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static int DifficultyLevels_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Name") )
    {
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }
        return 1;
    }

    return 0;
}

int process_difficultylevels(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ResistPenalty, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DeathExpPenalty, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UberCodeOddsNormal, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UberCodeOddsGood, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterSkillBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterFreezeDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterColdDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AiCurseDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UltraCodeOddsNormal, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UltraCodeOddsGood, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LifeStealDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ManaStealDivisor, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, UniqueDamageBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ChampionDamageBonus, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HireableBossDamagePercent, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MonsterCEDamagePercent, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaticFieldMin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GambleRare, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GambleSet, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GambleUnique, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GambleUber, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, GambleUltra, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            File_CopyFile(acTemplatePath, acTxtPath, "cubemod", ".txt");
            File_CopyFile(acTemplatePath, acTxtPath, "cubetype", ".txt");

            m_stCallback.pfnFieldProc = DifficultyLevels_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            break;

        default:
            break;
    }

    return 1;
}

