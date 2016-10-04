#include "global.h"

#define FILE_PREFIX "qualityitems"

/*
Qualityitems.txt - v1.10 (and presumably 1.11x)
Composed by Quatl with help from Nefarius, and Myhrginoc

OVERVIEW

Controls properties for superior quality items.
Each row holds settings for both armor and weapons.
I assume the probibility of each row is the same.
New rows may be added, and are functional. I have no clue as to limits.

RELATED .TXT FILES
This file is useing
* Properties.txt
* Itemtypes.txt (only indirectly see below)


COLUMN DESCRIPTIONS :
______________________________________________________________________________

nummods: 1 or 2
How many mods appear on items the game makes superior useing this row

______________________________________________________________________________

mod1code: String Code from properties.txt
%ac, or red-mag, for example. 1st property for items of this quality, seems to allow any property
mod1param, mod1min, mod1max: Numeric Value
Same as any other property setting field. See properties.txt for details.

______________________________________________________________________________

mod2code: String Code from properties.txt
2nd property for armors of this quality (when nummods = 2)
mod2param, mod2min, mod2max: Numeric Value
Same as any other property setting field. See properties.txt for details.

______________________________________________________________________________

ToHitMin -> Dur%Max: Numeric Value
Out dated. You can safely use these for your own comments or whatever.
Not loaded by the game
(Thanks Myhrginoc)

______________________________________________________________________________

effect1, effect2: String_Key
String Key from a tbl file. I'm not sure if this has to be a valid key.
Loaded, but not displayed by the game.
(Thanks Myhrginoc)

______________________________________________________________________________

armor -> belt: Boolean Value
Filter items allowing this row's mods
1 = allow, 0 = dissalow
Note: These types are the original hardcoded item types
(Thanks Nefarius.) Helm for instance is not an option. I asume that
itemtypes.txt types that inherit from one of these types will cascade
properly.
Item type Cascades:
(From Nefarius; not fully confirmed)
armor -> tors, helm
weapon -> mele (except thro, rod, orb)
shield -> shld
throw -> thro
scepter -> scep
wand -> wand
staff -> staf
bow -> miss (xbow/bow)
boots -> boot
gloves -> glov
belt -> belt
(type comb ? could be either throw or weapon or both, not checked)

______________________________________________________________________________

level: Numeric Value
Level requirement push

______________________________________________________________________________

multiply: Numeric Value
Item's cost multiplied by this value.

______________________________________________________________________________

add: Numeric Value
Item's cost increased by this value.

______________________________________________________________________________

I realize this is a simple file , but I think it has potential for some interesting things, and I couldn't find much on it. Hopefuly someone will find it handy. Note this file is not included in the standard txt extract package, so you'll have to milk 
it from d2exp by hand.

-Quatl

*/

/*
�ļ���������
Quality����Ʒ�ʵģ�����ǿ�ġ�
Items�����ߣ���װ����
���ļ����������г�ǿ���͵�װ������Ϣ��
���ļ��е�ÿһ�б�ʾһ�ֳ�ǿ���͡�


�ظ�

    2¥
    2011-09-26 23:59

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-26 23:59

    �ٱ� |

    zqtjingzi
    С����
    12

nummods���˳�ǿ�����м����������ԡ�ֻ��Ϊ1����2��

mod1code����1���������Ե�����������Properties.txt������

mod1param����1���������ԵĲ�����

mod1min����1���������Ե���Сֵ������

mod1max����1���������Ե����ֵ������

mod2code��mod2param��mod2min��mod2max����ο�mod1��

ToHitMin��������ע�͡�

ToHitMax��������ע�͡�

Dam%Min��������ע�͡�

Dam%Max��������ע�͡�

AC%Min��������ע�͡�

AC%Max��������ע�͡�

Dur%Min��������ע�͡�

Dur%Max��������ע�͡�

effect1�����ò�����������Ϸ���롣

effect2�����ò�����������Ϸ���롣

armor���˳�ǿ�����ܷ�����ڷ����ϡ�

weapon���˳�ǿ�����ܷ�����������ϡ�

shield���˳�ǿ�����ܷ�����ڶ����ϡ�

thrown���˳�ǿ�����ܷ������Ͷ�������ϡ�

scepter���˳�ǿ�����ܷ������Ȩ�ȣ�pal�ȣ��ϡ�

wand���˳�ǿ�����ܷ�����ڷ��ȣ�nec�ȣ��ϡ�

staff���˳�ǿ�����ܷ���������ȣ�sor�ȣ��ϡ�

bow���˳�ǿ�����ܷ�����ڹ��ϡ�

boots���˳�ǿ�����ܷ������Ь�ϡ�

gloves���˳�ǿ�����ܷ�����������ϡ�

belt���˳�ǿ�����ܷ�����������ϡ�

level���˳�ǿ���Ͷ���Ʒ�ȼ���Ҫ��

multiply���۸�Ŵ����ӡ�

add���۸��������ӡ�
*/

typedef struct
{
    unsigned char varmor;
    unsigned char vweapon;
    unsigned char vshield;
    unsigned char vscepter;

    unsigned char vwand;
    unsigned char vstaff;
    unsigned char vbow;
    unsigned char vboots;

    unsigned char vgloves;
    unsigned char vbelt;
    unsigned char vnummods;
    unsigned char iPadding2;

    unsigned int vmod1code; //properties
    unsigned int vmod1param;
    unsigned int vmod1min;
    unsigned int vmod1max;

    unsigned int vmod2code; //properties
    unsigned int vmod2param;
    unsigned int vmod2min;
    unsigned int vmod2max;

    unsigned char veffect1[32];
    unsigned char veffect2[32];

    unsigned int iPadding27;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "ToHitMin",
    "ToHitMax",
    "Dam%Min",
    "Dam%Max",
    "AC%Min",
    "AC%Max",
    "Dur%Min",
    "Dur%Max",
    "thrown",
    "level",
    "multiply",
    "add",
    NULL,
};

static int QualityItems_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "mod1code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod1code);
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
    else if ( !strcmp(acKey, "mod2code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod2code);
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

int process_qualityitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, armor, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weapon, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shield, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, scepter, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, wand, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, staff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bow, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, boots, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gloves, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, belt, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nummods, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, effect1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, effect2, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = QualityItems_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

