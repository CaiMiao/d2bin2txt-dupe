#include "global.h"

#define FILE_PREFIX "monumod"
#define NAME_PREFIX "mu"

/*
Title 	MonUMod.txt File Guide
Description 	by 54x & Red Havoc
Sent by 	

OVERVIEW :

MonUMod.txt controls general and special abilites of :

    Champions
    Random Unique monsters
    SuperUnique monsters

as well as all their respective minions.

 

Warning : this file is tricky, as it contain 1 table of parameters inside. The 2 last columns of datas are in fact to be considered as a complete another file, they have no relations between the columns / lines of the rest of MonUMod.txt.

In case you wonder, this is ugly and not a logical way to proceed, don't do that at home when you're making your own databases; instead make 2 separate tables.

RELATED .TXT FILES :
     	

This file is using:

    MonType.txt

	

This file is used by :

    SuperUniques.txt

COLUMN DESCRIPTIONS :
uniquemod 	This column is just for reference and not used in another file. It holds short keywords that describe the modifier of each line, so you know what youre messing with.

For a precise description see the SuperUniques.txt file guide, columns Mod1, Mod2 and Mod3.
 
id 	This column is used for the internal Id of the modifier.

These Id numbers are entered into the Mod1, Mod2 and Mod3 columns in SuperUniques.txt to give bosses their special skills.
 
enabled 	

Is the modifier usable or not ?

    1 = enabled and can be used
    0 = not enabled and wont work in the game
     

version 	

Modifier for Classic D2 and / or LoD ?

    0 = can be used in both D2 Classic and LoD
    100 = can only be used in the LoD Expansion
     

xfer 	

Display "Minions" under the life bar ?

For instance SuperUniques has up to 3 Mods. If at least 1 of them has the column xfer set to 1, then the Minions of this Boss will have "Minions" displayed under their life bar.
 
champion 	

Champion-only ?

    1 = the modifier is for Champions only
    0 = can be used by SuperUniques, Champions ...
     

fPick 	Maybe means forbidden pick and restricts the spawning of several modifiers on one boss, e.g. "Lightning Enchanted" bosses dont get "Multiple Shots" as well.

How it's working exactly is not known tough.
 
exclude1
exclude2 	

Monster Type exclusion.

These two columns can be used to exclude peculiar monster types from spawning with a certain boss modifier. If the type value from MonTypes.txt is entered here, no randomly spawned boss monster of this category (and its sub-categories) will ever have 
this modifier.

For instance, Sandleapers will never spawn with the Lightning Enchanted property.
 
cpick
cpick (N)
cpick (H) 	Is it available for Champions on this Difficulty ?

These columns restrict the range of modifiers that will spawn on champions in different diffculties. An empty cell in one of the columns means, the modifier will not appear on champions in the corresponding difficulty.

Note, that you may add (boss-only) modifiers to champions if you also set their Champion column to 1 and enter a value in their cpick columns.

By entering higher numbers you can increase the frequency in which the modifier is used : if you set, for example, cpick for the fanatic modifier to 7 and the value for the possessed to 1, fanatic champions will occur like seven times more often in 
normal difficulty than possessed champions.
 
upick
upick (N)
upick (H) 	These columns work exactly like the cpick columns and control which modifiers will spawn on random Uniques bosses in the three difficulties. An higher value means the modifier will spawn more often.
 
fInit 	Not read by the game. You can use it as a comment field.
 

 

 

The next two columns are composing a parameter table. The column *constant desc is a description of the parameter, while the column constants is the value of that parameter.
constants 	

This column includes the values that will set up general properties of champions, bosses and their minions. The values are described in the column to the right, *constant desc.

Some parameters have different values per difficulty, while others are global for the 3 difficulties.

Here's the content of that table, in a more handy form :

Global Parameter
	
      Value
champion chance
	
20
champion +tohit%
	
75
champion +dmg%
	
100
minion +tohit%
	
50
unique +tohit%
	
100
minion +dmg% (strong)
	
75
unique +dmg% (strong)  
	
150

 
Parameter per Difficulty
	
    Normal
	
  Nightmare
	
        Hell
minion +hp%
	
200
	
200
	
175
champion +hp%
	
300
	
250
	
200
unique +hp%
	
700
	
550
	
325
minion +elem min dmg%
	
0
	
33
	
33
minion +elem max dmg%
	
0
	
50
	
50
champion +elem min dmg%  
	
33
	
33
	
33
champion +elem max dmg
	
50
	
50
	
50
unique +elem min dmg%
	
66
	
66
	
66
unique +elem max dmg%
	
100
	
100
	
100


 
*constant desc   	This column tells what the values in the constants column do affect.
 
*eol 	End Of Line.

Do not remove this column ! Its purpose is to ensure the last column of the tabulated text files are always filled. Be sure that all rows of this column are filled with a value.

*/

/*
�ļ���������
Mon��Monster�������
U��Unique��Ψһ�ģ�����ġ�
Mod��Modifier�����Σ����������ԡ�
���Ա��ļ������������п����ڽ�֣�����ͷĿ�֣����ϳ��ֵ��������ԣ����ر���ٵȡ�
���ļ��е�ÿһ�б�ʾһ���������ԡ�


�ظ�

    2¥
    2011-09-22 22:41

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-22 22:41

    �ٱ� |

    jayhorusosiris
    ������ͽ
    11

������������������


�ظ�

    4¥
    2011-09-22 22:41

    �ٱ� |

    zqtjingzi
    С����
    12

UniqueMod������������ԣ��Ժ���UMod�������֣�������Ϊע��ʹ�á�

ID����UMod�ı�ţ��������ļ�ʹ�á�

Enabled����UMod�Ƿ���á�

Version����UMod���õ���Ͱ汾��

xfer���д�UMod�Ľ����ߵ�С���������Ƿ���ʾ��ආ������ۡ�

Champion����UMod�Ƿ�ΪͷĿ�ֶ��С�

fPick��������ֵ��UMod����Ϊͬһ��ֹ��С�

exclude1����UMod���ܳ��ֵĹ�������1��

exclude2����UMod���ܳ��ֵĹ�������2��

cpick������ͨ�Ѷ��µ�ͷĿ���ܷ��д�UMod��

cpick(N)���ڶ����Ѷ��µ�ͷĿ���ܷ��д�UMod��

cpick(H)���ڵ����Ѷ��µ�ͷĿ���ܷ��д�UMod��

upick������ͨ�Ѷ��µ��������ܷ��д�UMod������ֵԽ���UMod���ֵ�Ƶ��Խ��

upick(N)���ڶ����Ѷ��µ��������ܷ��д�UMod������ֵԽ���UMod���ֵ�Ƶ��Խ��

upick(H)���ڵ����Ѷ��µ��������ܷ��д�UMod������ֵԽ���UMod���ֵ�Ƶ��Խ��

fInit�������У�ɾ��Ҳ�ɡ�

constants����ּ���ආ�����������ֵ���������������������ĸ�UMod���޹أ���Ҫ�����������*constant desc�С�

*constant desc����ּ���ආ��������������������������ĸ�UMod���޹ء�

*eol����β��־������Ϊ0��


�ظ�

    5¥
    2011-09-22 22:41

    �ٱ� |

    zqtjingzi
    С����
    12

��ϡ�
����д�����ָ����
ף��λ��Ϸ��졣

����˵����
constants�����������֡�ͷĿ�ּ���ආ�����������ֵ��1.13�汾��

ͷĿ�ֳ��ֵĸ��ʣ�20%����ͷĿ�����ֵı���ԼΪ1��4

��ͨ����ආ��� ���� +100% ����׼ȷ�� + 50% �˺� + 75% Ԫ���˺� + 0% - 0%
���Ρ���ආ��� ���� + 75% ����׼ȷ�� + 50% �˺� + 75% Ԫ���˺� + 33% - 50%
��������ආ��� ���� + 50% ����׼ȷ�� + 50% �˺� + 75% Ԫ���˺� + 33% - 50%
��ͨ����ͷĿ�� ���� +200% ����׼ȷ�� + 75% �˺� +100% Ԫ���˺� + 33% - 50%
���Ρ���ͷĿ�� ���� +150% ����׼ȷ�� + 75% �˺� +100% Ԫ���˺� + 33% - 50%
��������ͷĿ�� ���� +100% ����׼ȷ�� + 75% �˺� +100% Ԫ���˺� + 33% - 50%
��ͨ������֣� ���� +300% ����׼ȷ�� +100% �˺� +150% Ԫ���˺� + 66% -100%
���Ρ�����֣� ���� +200% ����׼ȷ�� +100% �˺� +150% Ԫ���˺� + 66% -100%
����������֣� ���� +100% ����׼ȷ�� +100% �˺� +150% Ԫ���˺� + 66% -100% 
*/

typedef struct
{
    unsigned int vid;

    unsigned short vversion;
    unsigned char venabled;
    unsigned char vxfer;

    unsigned char vchampion;
    unsigned char vfPick;
    unsigned short vexclude1;   //MonType

    unsigned short vexclude2;   //MonType
    unsigned short vcpick;

    unsigned short vcpickmyspmybr1Nmybr2;
    unsigned short vcpickmyspmybr1Hmybr2;

    unsigned short vupick;
    unsigned short vupickmyspmybr1Nmybr2;

    unsigned short vupickmyspmybr1Hmybr2;
    unsigned short iPadding6;

    unsigned int vconstants;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "uniquemod",
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "fInit",
    "*constant desc",
    NULL,
};

static int MonUMOD_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "uniquemod") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else if ( 0 < iLineNo )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vid);
        }
        else
        {
            acOutput[0] = 0;
        }
#else
        sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vid);
#endif

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

static int MonUMod_ConverValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "exclude1") )
    {
        pcResult = MonType_GetType(pstLineInfo->vexclude1);
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
    else if ( !strcmp(acKey, "exclude2") )
    {
        pcResult = MonType_GetType(pstLineInfo->vexclude2);
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

int process_monumod(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, id, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, xfer, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, champion, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, fPick, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, exclude1, USHORT);   //MonType

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, exclude2, USHORT);   //MonType
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpick, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpickmyspmybr1Nmybr2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cpickmyspmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upick, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upickmyspmybr1Nmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, upickmyspmybr1Hmybr2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, constants, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(montype, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = MonUMod_ConverValue;
            m_stCallback.pfnFieldProc = MonUMOD_FieldProc;
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

