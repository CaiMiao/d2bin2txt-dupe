#include "global.h"

#define FILE_PREFIX "RarePrefix"

/*
�ļ���������
Rare��ϡ�еģ��ڰ�����ָ����ġ�
Prefix��ǰ׺�����Ǵ�׺�е�ǰ׺��
Suffix����׺�����Ǵ�׺�еĺ�׺��
�����������ļ��������������𼶴�׺��ǰ׺���׺�������Ϣ��
���ļ��е�ÿһ�б�ʾһ����׺ǰ׺���׺��


�ظ�

    2¥
    2011-09-30 22:15

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-30 22:16

    �ٱ� |

    zqtjingzi
    С����
    12

Name��ǰ׺�����׺������ϡ����Ʒǰ׺���ַ�����ֵ(string key),tbl�ļ���������

version�����õ������Ϸ�汾��'0'-diablo2ԭ��,��1��-�ƻ�֮��

itype1-7���˴�׺�����ڵĵ�1-7��װ�����͡�������Ʒ����(����¼)��

etype1-4���˴�׺�����õĵ�1-4��װ�����ͣ�����etypeӦ��ĳһitype�������͡��ų���Ʒ����(����¼)��

�˴�׺�����ܹ����õ�װ������Ϊsum(itype1-7) - sum(etype1-4)��������itype���ܺ��ٳ�ȥetype�е����͡�

add���۸��������ӡ�����NPCʱ�۸���������(������?)����skills.txt������

divide���۸�Լ�����ӡ�����NPCʱ�ļ۸��������(������?)��

multiply���۸�Ŵ����ӡ��۸���������(������?)����skills.txt������


�ظ�

    4¥
    2011-09-30 22:16

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��1��
֮���԰��������ļ�����һ��˵������Ϊ���������е�����һģһ���ġ�


�ظ�

    5¥
    2011-09-30 22:16

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��2��
�������𼶴�׺��û�����ԣ�ֻ�����ֺ����õ�װ�����͡�Ҳ����˵ĳһ���𼶴�׺�Ƿ����ֻ��װ���ײ������йأ�������ͬ���Ե�װ����׺������ȫ��һ������֮Ҳ�ǣ���ͬ���ֵ�����װ�����Կ�����ȫ��һ����

��¼:itype & etype

itype = Inclusion TYPE(��������) & etype = Exclusion TYPE(�ų�����)

���������һ�������Ĵ�׺������{itype}����������Ʒ�����ϲ����������ܲ�����{etype}����������Ʒ���͡�

���磺itype = {weap,armo} etype = {axe,helm,belt}
�����ʾ�ô�׺���Բ��������е������Ϳ����ϣ������ڸ���,ͷ���������ϲ��ܲ�����

ͨ�����ַ���(�ڡ�itype���͡�etype�������趨��Ʒ����)������Կ���ĳ����Ʒ�Ƿ��ܲ���(����˵����)�ô�׺��������ĳ��(Щ)��׺ֻ���ڽ�(swords)�ϲ��������߲��������ڽ��ϲ�������Ȼ�����������֪������Ʒ�Ĵ��롣

ע�⣺���ϵ�˵��ͬ����Ӧ�������С�itype/etype����.txt�ļ�����automagic,rareprefix/suffix��
*/

typedef struct
{
    unsigned int iPadding0;
    unsigned int iPadding1;
    unsigned int iPadding2;

    unsigned short iPadding3;
    unsigned short vversion;

    unsigned short vitype1;
    unsigned short vitype2;

    unsigned short vitype3;
    unsigned short vitype4;

    unsigned short vitype5;
    unsigned short vitype6;

    unsigned short vitype7;
    unsigned short vetype1;

    unsigned short vetype2;
    unsigned short vetype3;

    unsigned short vetype4;
    unsigned char vname[32];

    unsigned short iPadding17;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "divide",
    "multiply",
    "add",
    NULL,
};

static int RarePrefix_ConverValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( strlen("itype1") == strlen(acKey) && 1 == sscanf(acKey, "itype%d", &id) )
    {
        unsigned short *pwItype = &pstLineInfo->vitype1;
        pcResult = ItemTypes_GetItemCode(pwItype[id - 1]);
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
        unsigned short *pwItype = &pstLineInfo->vetype1;
        pcResult = ItemTypes_GetItemCode(pwItype[id - 1]);
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

int process_rareprefix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = RarePrefix_ConverValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

