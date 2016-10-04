#include "global.h"

#define FILE_PREFIX "monequip"

/*
Title 	MonEquip.txt File Guide (v 1.0)
Description 	by Nefarius
Sent by 	
MonEquip.txt File Guide
By Nefarius


Note: Before you can do anything in here, you must set the "inventory" column in MonStats.txt to true (1).
this tells the game to look for equipment data inside MonEquip.txt
NOTE: Never set that column to true if you don't have the appropriate entries in MonEquip.txt, you will get an unhandled exception.
Furthermore, you should leave the last line intact, if you add new lines add them infront of the last line.



monster - This column contains the ID pointer to MonStats.txt, make sure this is accurate (otherwise you will crash for the same reasons as above).

oninit - Boolean, 0 = monster is created by skill, 1 = monster is created by level.

item1-3 - The 3-4 letter code of the item from weapons, armor or misc.txt

loc1-3 - The slot to equip the item in. (see BodyLocs.txt for more details)

mod1-3 - Item quality of the equipped item. (see table below)

eol - End of Line.




Item Quality:

1 - low quality
2 - normal
3 - superior
4 - magic
5 - set
6 - rare
7 - unique
8 - crafted
9 - tempered

*/

/*
�ļ���������
Mon��Monster�������
Equip��װ����
���Ա��ļ�������ĳЩ�����װ������ʵ����Ѫ�񡢷��е��䵶��Ů����Ӱ��սʿ��Ӱ�Ӵ�ʦ��װ����
���ļ��е�ÿһ�б�ʾһ���ض��ȼ��Ĺ��


�ظ�

    2¥
    2011-09-23 22:34

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-23 22:34

    �ٱ� |

    zqtjingzi
    С����
    12

monster������������Monstats.txt������

oninit���˹����Ƿ��ڵ�ͼ��ʼ��ʱ�����ɣ����˹����Ƿ����ɼ����ٻ������ġ�0�������ɼ����ٻ������ġ�

level������ĵȼ���������ĵȼ�����ĳ�д��е�ֵʱ�����ܻ�ô��е�װ�����Ҵ���ֵԽ������ȼ�Խ�ߡ�

item1-3�������������ӵĵ�1-3��װ����

loc1-3����1-3��װ����λ�á���BodyLocs.txt������

mod1-3����1-3��װ����Ʒ�ʡ�Ʒ��˵�������档

eol����β��־������Ϊ0��


�ظ�

    4¥
    2011-09-23 22:34

    �ٱ� |

    zqtjingzi
    С����
    12

����˵����
mod�е�ֵ��װ����Ʒ�ʹ�ϵ��
mod = 1 ���� ��Ʒ�ʣ�������ġ��𻵵�֮�ࡣ
mod = 2 ���� ��ͨ�ģ�����ɫװ����
mod = 3 ���� ��ǿ�ġ�
mod = 4 ���� ħ���ģ�����ɫװ����
mod = 5 ���� ��װ��
mod = 6 ���� ϡ�еģ�����ɫװ����
mod = 7 ���� Ψһ�ģ�������װ����
mod = 8 ���� �ֹ��ģ�����ɫװ������ʵ����Ϸ��Ӧ���޷����ֳ�ɫװ����


�ظ�

    5¥
    2011-09-23 22:34

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��1��
�ڴ��ļ��г��ֵĹ����Monstats.txt����Ӧ�е�inventory��һ��ҪΪ1��������Monstats.txt��inventory��Ϊ1�Ĺ���һ��Ҫ�ڴ��ļ���������һ��������������Ϸ�����


�ظ�

    6¥
    2011-09-23 22:34

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��2��
���ļ��е����һ��һ��Ҫ�������������Ϊ���й������װ���������µ��еĻ���һ��Ҫ�����һ��֮ǰ��ӡ�

*/

typedef struct
{
    unsigned short vmonster;   //MonStats
    unsigned short vlevel;

    unsigned int voninit;

    unsigned char vitem1[4];
    unsigned char vitem2[4];
    unsigned char vitem3[4];

    unsigned char vloc1; //bodylocs
    unsigned char vloc2; //bodylocs
    unsigned char vloc3; //bodylocs
    unsigned char vmod1;

    unsigned char vmod2;
    unsigned char vmod3;
    unsigned short iPadding6;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] = 
{
    "eol",
    NULL,
};

static int MonEquip_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int MonEquip_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "monster") )
    {
        if ( 0xFFFF == pstLineInfo->vmonster )
        {
            strcpy(acOutput, "*end*  do not remove");
        }
        else
        {
            pcResult = MonStats_GetStatsName(pstLineInfo->vmonster);
            if ( pcResult )
            {
                strcpy(acOutput, pcResult);
            }
            else
            {
                acOutput[0] = 0;
            }
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "loc1") )
    {
        pcResult = BodyLocs_GetLocStr(pstLineInfo->vloc1);
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
    else if ( !strcmp(acKey, "loc2") )
    {
        pcResult = BodyLocs_GetLocStr(pstLineInfo->vloc2);
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
    else if ( !strcmp(acKey, "loc3") )
    {
        pcResult = BodyLocs_GetLocStr(pstLineInfo->vloc3);
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

int process_monequip(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, monster, USHORT);   //MonStats
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, oninit, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc1, UCHAR); //bodylocs
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc2, UCHAR); //bodylocs
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, loc3, UCHAR); //bodylocs
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3, UCHAR);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = MonEquip_ConvertValue;
            m_stCallback.pfnFieldProc = MonEquip_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

