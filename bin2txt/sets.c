#include "global.h"

#define FILE_PREFIX "sets"
#define NAME_PREFIX "se"

/*
Title 	Sets.txt File Guide
Description 	by Alkalund, revised by Myhrginoc
Sent by 	
Refer to the Set Items File Guide for fields that define the attributes of specific items in a set.

index: string key linked to by the set field in SetItems.txt - used to tie all of the set's items to the same set.

name: string key to item's name in a .tbl file.

version: 0 = Available in Classic D2 and LoD Expansion; 100 = available in LoD Expansion only.

level: set level, perhaps intended as a minimum level for partial or full attributes to appear (reference only, not loaded into game).

GOLD ATTRIBUTES

PCode2a,PCode2b to PCode5a,PCode5b: An ID pointer of a property from Properties.txt, these columns control each of the five pairs of different partial set modifiers a set item can grant you at most.

PParam2a,PParam2b to PParam5a,PParam5b: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them, these fields support calculations.

PMin2a,PMin2b to PMin5a,PMin5b: Minimum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guides for Properties.txt and ItemStatCost.
txt for further details.

PMax2a,PMax2b to PMax5a,PMax5b: Maximum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guides for Properties.txt and ItemStatCost.
txt for further details.

FCode1 to FCode8: An ID pointer of a property from Properties.txt, these columns control each of the eight different full set modifiers a set item can grant you at most.

FParam1 to FParam8: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them, these fields support calculations.

FMin1 to FMin8: Minimum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guides for Properties.txt and ItemStatCost.txt for further 
details.

FMax1 to FMax8: Maximum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guides for Properties.txt and ItemStatCost.txt for further 
details.

*eol: terminator field, not used in game, primary purpose is to keep Microsoft Excel from misbehaving.

APPENDIX

Gold attributes will appear depending on how many set items are equipped, both partial set attributes (not all set items equipped) and full set attributes (all set items equipped only). If a set has X number of items, at most there will be X-1 partial 
attributes on any item.

PCode2a,PCode2b -> when any second set item is also equipped.
PCode3a,PCode3b -> when any third set item is also equipped.
PCode4a,PCode4b -> when any fourth set item is also equipped.
PCode5a,PCode5b -> when any fifth set item is also equipped.

*/

/*
index �C��Ʒ����������
name �C��ɫ��װ�����ƣ�
version �C��Ʒ���ֵİ汾��0����ԭ�棬100��������Ƭ��
level �C��װ�ļ���
PCode2a �C��װ����Ʒӵ����������ʱ���ṩ�ĸ��ӵ�һ����ħ�����ԣ�
PParam2a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Բ�������һ���𣩣�
PMin2a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե���Сֵ����һ���𣩣�
PMax2a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե����ֵ����һ���𣩣�
PCode2b -��װ����Ʒӵ����������ʱ���ṩ�ĸ��ӵڶ�����ħ�����ԣ�
PParam2b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Բ������ڶ����𣩣�
PMin2b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե���Сֵ���ڶ����𣩣�
PMax2b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե����ֵ���ڶ����𣩣�
PCode3a -��װ����Ʒӵ����������ʱ���ṩ�ĸ��ӵ�һ����ħ�����ԣ�
PParam3a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Բ�������һ���𣩣�
PMin3a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե���Сֵ����һ���𣩣�
PMax3a -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե����ֵ����һ���𣩣�
PCode3b -��װ����Ʒӵ����������ʱ���ṩ�ĸ��ӵڶ�����ħ�����ԣ�
PParam3b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Բ������ڶ����𣩣�
PMin3b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե���Сֵ���ڶ����𣩣�
PMax3b -��װ����Ʒӵ����������ʱ���ṩ��ħ�����Ե���Сֵ���ڶ����𣩣�

֮�����磺Pcode#a��Pparam#a��Pmin#a��Pmax#a��Pcode#b��Pparam#b��Pmin#b��Pmax#b�Ȳμ������������ɡ�


FCode1 �C ȫ��װ�������ĸ���1��ħ�����ԣ�
FParam1 -ȫ��װ�������ĸ���1��ħ��������
FMin1 -ȫ��װ�������ĸ���1��ħ�����Ե���Сֵ��
FMax1 -ȫ��װ�������ĸ���1��ħ�����Ե����ֵ��

֮�����磺Fcode#��Fparam#��Fmin#��Fmax#�Ȳμ������������ɡ�

*eol �C�ļ�������־�� 

*/

/*
�ļ���������
Set(s)����װ��
���Դ��ļ���¼����Ϸ��������װ��
�ļ��е�ÿһ�д���һ����װ��


�ظ�

    2¥
    2011-09-08 21:08

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-08 21:08

    �ٱ� |

    zqtjingzi
    С����
    12

Index����Ʒ������Ҳ�Ǵ���װ����Ϸ�еĴ��롣

Name�����֣�����װ����Ϸ�е����֡�

Version����Ʒ���ܳ��ֵ���Ͱ汾��

Level������װ����װ�ȼ���Ҳ���Ǵ���װ��ÿ��װ������Ʒ�ȼ���

PCode2a������2a�Ĵ��롣��ν2a������ָ����������װ���õĵ�һ�����ԡ�ͬ��2b��ָ����������װ���õĵڶ������ԡ�3a��ָ����������װ���õĵ�һ�����ԡ�

PParam2a������2a�Ĳ�����

PMin2a������2a����Сֵ������

PMax2a������2a�����ֵ������

����2b��3a��3b��4a��4b��5a��5b��4�У��������ơ�

FCode1-8������ȫ����װ��ĵ�1-8�����ԵĴ��롣

FParam1-8������ȫ����װ��ĵ�1-8�����ԵĲ�����

FMin1-8������ȫ����װ��ĵ�1-8�����Ե���Сֵ������

FMax1-8������ȫ����װ��ĵ�1-8�����Ե����ֵ������

Eol���н�����־��������0��
*/

typedef struct
{
    unsigned short wSetId;
    unsigned short vname;   //strings

    unsigned int vversion;

    unsigned int iPadding2;
    unsigned int dwSetItems;

    int vPCode2a;   //properties
    int vPParam2a;  //skills
    int vPMin2a;
    int vPMax2a;

    int vPCode2b;   //properties
    int vPParam2b;  //skills
    int vPMin2b;
    int vPMax2b;

    int vPCode3a;   //properties
    int vPParam3a;  //skills
    int vPMin3a;
    int vPMax3a;

    int vPCode3b;   //properties
    int vPParam3b;  //skills
    int vPMin3b;
    int vPMax3b;

    int vPCode4a;   //properties
    int vPParam4a;  //skills
    int vPMin4a;
    int vPMax4a;

    int vPCode4b;   //properties
    int vPParam4b;  //skills
    int vPMin4b;
    int vPMax4b;

    int vPCode5a;   //properties
    int vPParam5a;  //skills
    int vPMin5a;
    int vPMax5a;

    int vPCode5b;   //properties
    int vPParam5b;  //skills
    int vPMin5b;
    int vPMax5b;

    int vFCode1;    //properties
    int vFParam1;
    int vFMin1;
    int vFMax1;

    int vFCode2;    //properties
    int vFParam2;
    int vFMin2;
    int vFMax2;

    int vFCode3;    //properties
    int vFParam3;
    int vFMin3;
    int vFMax3;

    int vFCode4;    //properties
    int vFParam4;
    int vFMin4;
    int vFMax4;

    int vFCode5;    //properties
    int vFParam5;
    int vFMin5;
    int vFMax5;

    int vFCode6;    //properties
    int vFParam6;
    int vFMin6;
    int vFMax6;

    int vFCode7;    //properties
    int vFParam7;
    int vFMin7;
    int vFMax7;

    int vFCode8;    //properties
    int vFParam8;
    int vFMin8;
    int vFMax8;

    unsigned int iPadding68;    //D2SetItemsTxt* pSetItem1
    unsigned int iPadding69;

    unsigned int iPadding70;
    unsigned int iPadding71;
    unsigned int iPadding72;
    unsigned int iPadding73;
} ST_LINE_INFO;

typedef struct
{
    int vPCode2a;   //properties
    int vPParam2a;  //skills
    int vPMin2a;
    int vPMax2a;
} ST_SET_CODE;

static char *m_apcInternalProcess[] =
{
    "index",
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "level",
    NULL,
};

typedef struct
{
    unsigned char vindex[32];
} ST_SET_INDEX;

static unsigned int m_iSetCount = 0;
static ST_SET_INDEX *m_astSets = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astSets, ST_SET_INDEX);

char *Sets_GetSetName(unsigned int id)
{
    if ( id < m_iSetCount )
    {
        return m_astSets[id].vindex;
    }

    return NULL;
}

static int Sets_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
#ifdef USE_NAME_TOBE_ID
    char *pcResult;
#endif

    if ( !strcmp(acKey, "index") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
#ifdef USE_NAME_TOBE_ID
            pcResult = String_FindString(pstLineInfo->vname, NULL);
            if ( pcResult && strcmp("dummy", pcResult) )
            {
                strcpy(acOutput, pcResult);
            }
            else
#endif
            {
                sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->wSetId);
            }
        }

        strncpy(m_astSets[m_iSetCount].vindex, acOutput, sizeof(m_astSets[m_iSetCount].vindex));
        String_Trim(m_astSets[m_iSetCount].vindex);
        m_iSetCount++;

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

static int Sets_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
#ifdef USE_NAME_TOBE_ID
    char *pcResult;
#endif

    if ( !strcmp(acKey, "index") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
#ifdef USE_NAME_TOBE_ID
            pcResult = String_FindString(pstLineInfo->vname, NULL);
            if ( pcResult && strcmp("dummy", pcResult) )
            {
                strcpy(acOutput, pcResult);
            }
            else
#endif
            {
                sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->wSetId);
            }
        }

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

static int Sets_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( !strcmp("name", acKey) )
    {
        pcResult = String_FindString(pstLineInfo->vname, NULL);
        if ( pcResult && strcmp("dummy", pcResult) )
        {
            strcpy(acOutput, pcResult);
        }
        else
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->wSetId);
        }
        result = 1;
    }
    else if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PCode%da", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2a;
        pcResult = Properties_GetProperty(pstSetItem[(id - 2) * 2].vPCode2a);
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
    else if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PParam%da", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2a;
        pcResult = Properties_GetProperty(pstSetItem[(id - 2) * 2].vPCode2a);
        if ( pcResult )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[(id - 2) * 2].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                pcResult = States_GetStateName(pstSetItem[(id - 2) * 2].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
            }
        }
        else
        {
            acOutput[0] = 0;
        }

        result = 1;
    }
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PCode%db", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2b;
        pcResult = Properties_GetProperty(pstSetItem[(id - 2) * 2].vPCode2a);
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
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "PParam%db", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vPCode2b;
        pcResult = Properties_GetProperty(pstSetItem[(id - 2) * 2].vPCode2a);
        if ( pcResult )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[(id - 2) * 2].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                pcResult = States_GetStateName(pstSetItem[(id - 2) * 2].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 2) * 2].vPParam2a);
            }
        }
        else
        {
            acOutput[0] = 0;
        }

        result = 1;
    }
    else if ( strlen("FCode1") == strlen(acKey) && 1 == sscanf(acKey, "FCode%d", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vFCode1;
        pcResult = Properties_GetProperty(pstSetItem[id - 1].vPCode2a);
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
    else if ( strlen("FParam1") == strlen(acKey) && 1 == sscanf(acKey, "FParam%d", &id) )
    {
        ST_SET_CODE *pstSetItem = (ST_SET_CODE *)&pstLineInfo->vFCode1;
        pcResult = Properties_GetProperty(pstSetItem[id - 1].vPCode2a);
        if ( pcResult )
        {
            if ( !strcmp("oskill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[id - 1].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
                }
            }
            else if ( !strcmp("state", pcResult) )
            {
                pcResult = States_GetStateName(pstSetItem[id - 1].vPParam2a);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[id - 1].vPParam2a);
            }
        }
        else
        {
            acOutput[0] = 0;
        }

        result = 1;
    }

    return result;
}

static void Sets_InitValueMap(ST_VALUE_MAP *pstValueMap, ST_LINE_INFO *pstLineInfo)
{
    INIT_VALUE_BUFFER;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, USHORT);   //strings

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode2a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam2a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax2a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode2b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam2b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax2b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode3a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam3a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax3a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode3b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam3b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax3b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode4a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam4a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax4a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode4b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam4b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax4b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode5a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam5a, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax5a, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PCode5b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PParam5b, INT);  //skills
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMin5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PMax5b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode1, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode2, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode3, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode4, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode5, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode6, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode7, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FCode8, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FParam8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMin8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FMax8, INT);
}

int process_sets(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);

            Sets_InitValueMap(pstValueMap, pstLineInfo);

            m_iSetCount = 0;

            m_stCallback.pfnFieldProc = Sets_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(states, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            Sets_InitValueMap(pstValueMap, pstLineInfo);

            m_stCallback.pfnConvertValue = Sets_ConvertValue;
            m_stCallback.pfnFieldProc = Sets_FieldProc;
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

