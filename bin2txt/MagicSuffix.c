#include "global.h"

#define FILE_PREFIX "MagicSuffix"

/*
�ļ���1��MagicSuffix.txt
�ļ���2��MagicSuffix.txt
�ļ�·�������������ļ���/data/global/excel/


()
����

    �ظ�

    1¥
    2011-09-16 23:28

    �ٱ� |

���ɾ�Ʒ
�������ԡ�Buildһ������Mana�Ķ���SOR
�����������ߵ�2��BoxTool�������
[���һˮ]DOS��Ϸ���ɴ��ͼ..
���¾��䣺׷�䡶�����ƻ���1��
���ɾ�Ʒ
�����ʳ�Ʒ����������ȤMOD����~
ʮ��֮���㻹�᲻��򿪰���2�������ڴ��Ŀ�ʼMFô
�����벩������MOD��---------�������ƻ���---����桿
��������solo���ܻ�ʥ��

    zqtjingzi
    С����
    12

�ļ���������
Magic��ħ����������ָħ�����ԡ�
Suffix��ǰ׺������ħ����׺�е�ǰ׺��
Suffix����׺������ħ����׺�еĺ�׺��
�����������ļ�����������ħ����׺ǰ׺���׺�������Ϣ��
���ļ��е�ÿһ�б�ʾһ����׺ǰ׺���׺��


�ظ�

    2¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

����˵����֮���԰��������ļ�����һ��˵������Ϊ���������е��м�����һģһ���ġ�


�ظ�

    3¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    4¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

Name��ǰ׺�����׺����

version�����õ������Ϸ�汾��

spawnable���Ƿ������Ϸ�����ɡ�

rare���˴�׺�Ƿ�����ϡ�У�������Ʒ�ϳ��֡���+3��ϵ���ܵĴ�׺����Ϊ0���������������Բ��ܳ�����ϡ�У�������Ʒ�ϡ�

level����׺�ȼ���ֻ�е���Ʒ�ȼ����ڴ˴�׺�Ĵ�׺�ȼ�ʱ���˴�׺�ſ��ܳ�������һ��Ʒ�ϡ�

maxLevel����׺�ȼ����ޡ���������ֵʱ���˴�׺ֻ���������Ʒ�ȼ�С�ڴ˵ȼ�����Ʒ�ϡ�

levelreq��ʹ�ô��д˴�׺��Ʒ�Ľ�ɫ�ȼ�����

classSpecfic���Ƿ�Ϊĳһְҵר�á�

class���Ƿ��ĳһְҵ�������ʹ�õȼ��������еĻ������е���дְҵ���롣�紫�;�����׺���Գ���ʦ�������ְҵʹ�õȼ�����Ϊ24��������ʦ18���͹��ˡ�

classLevelreq��������һ�У��ض�ְҵ������

frequency����ͬһ���׺�д˴�׺���ֵ�Ƶ�ʡ�

group����׺�����Ĵ�׺�顣��ÿһ����Ʒ���ԣ�����ͬһ��׺��Ĵ�׺ֻ�ܳ���һ����

mod1Code���˴�׺�ĵ�1�����ԡ�

mod1Param���˴�׺�ĵ�1�����ԵĲ�����

mod1Min���˴�׺�ĵ�1�����Ե���Сֵ������

mod1Max���˴�׺�ĵ�1�����Ե����ֵ������

���µ�mod2Code��mod3Max��8�зֱ��ʾ�˴�׺�ĵ�2��3�����ԣ����庬��ο���1�����ԵĽ��͡�



�ظ�

    5¥
    2011-09-16 23:30

    �ٱ� |

    zqtjingzi
    С����
    12

transform���˴�׺�Ƿ��ʹ��Ʒ��ɫ��1�����ɫ��0������ɫ��

transformColor�����˴�׺��ʹ��Ʒ��ɫʱ������Ʒ����ɵ���ɫ����Colors.txt������

itype1-7���˴�׺�����ڵĵ�1-7��װ�����͡�

etype1-3(5)���˴�׺�����õĵ�1-3(5)��װ�����ͣ�����etypeӦ��ĳһitype�������͡�

˵������MagicSuffix.txt��etype����5�У���MagicSuffix.txt��etype����3�С�
�˴�׺�����ܹ����õ�װ������Ϊsum(itype1-7) - sum(etype1-3(5))��������itype���ܺ��ٳ�ȥetype�е����͡�

divide���۸�����1��

multiply���۸�����2��

add���۸�����3��

*eol����β��־������Ϊ0��
*/

typedef struct
{
    unsigned char vName[32];

    unsigned short iPadding8;
    unsigned short vversion;

    unsigned int vmod1code; //properties
    int vmod1param;
    int vmod1min;
    int vmod1max;

    unsigned int vmod2code; //properties
    int vmod2param;
    int vmod2min;
    int vmod2max;

    unsigned int vmod3code; //properties
    int vmod3param;
    int vmod3min;
    int vmod3max;

    unsigned short vspawnable;
    unsigned short vtransformcolor; //colors

    unsigned short vlevel;
    unsigned short iPadding22;

    unsigned int vgroup;

    unsigned int vmaxlevel;

    unsigned char vrare;
    unsigned char vlevelreq;
    unsigned char vclassspecific; //playerclass
    unsigned char vclass; //playerclass

    unsigned short vclasslevelreq;
    unsigned short vitype1; //itemtypes

    unsigned short vitype2;
    unsigned short vitype3;

    unsigned short vitype4;
    unsigned short vitype5;

    unsigned short vitype6;
    unsigned short vitype7;

    unsigned short vetype1; //itemtypes
    unsigned short vetype2;

    unsigned short vetype3;
    unsigned short vetype4;

    unsigned short vetype5;
    unsigned short vfrequency;

    unsigned int vdivide;
    unsigned int vmultiply;
    unsigned int vadd;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*comment",
    "transform",
    NULL,
};

static int MagicSuffix_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
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
    else if ( !strcmp(acKey, "mod3code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod3code);
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
    else if ( !strcmp(acKey, "transformcolor") )
    {
        pcResult = Colors_GetColorCode(pstLineInfo->vtransformcolor);
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
    else if ( !strcmp(acKey, "classspecific") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vclassspecific);
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
    else if ( !strcmp(acKey, "class") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vclass);
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
    else if ( strlen("itype1") == strlen(acKey) && 1 == sscanf(acKey, "itype%d", &id) )
    {
        unsigned short *pwIType = &pstLineInfo->vitype1;
        pcResult = ItemTypes_GetItemCode(pwIType[id - 1]);
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
    else if ( strlen("etype1") == strlen(acKey) && 1 == sscanf(acKey, "etype%d", &id) )
    {
        unsigned short *pwIType = &pstLineInfo->vetype1;
        pcResult = ItemTypes_GetItemCode(pwIType[id - 1]);
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


static char *MagicSuffix_GetKey(void *pvLineInfo, char *pcKey, int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vName);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

int process_magicsuffix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, USHORT); //colors

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classspecific, UCHAR); //playerclass
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, UCHAR); //playerclass

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classlevelreq, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, USHORT); //itemtypes

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, USHORT); //itemtypes
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, frequency, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multiply, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, add, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            //m_stCallback.pfnGetKey = MagicSuffix_GetKey;
            m_stCallback.pfnConvertValue = MagicSuffix_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

