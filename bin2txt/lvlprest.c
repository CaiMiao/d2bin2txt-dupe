#include "global.h"

#define FILE_PREFIX "lvlprest"
#define NAME_PREFIX "lp"

/*
Title 	LvlPrest.txt File Guide (v. 2)
Description 	by Xenast
Sent by 	
Lvlprest.txt

Name: Name of the level
*Reference only

Def: Related to Automap, must be a consecutive value

Levelid: The ID of the level from levels.txt
*Leave at 0 if the ds1 is not a preset level

Populate: 1 yes/0 no
If set to no monsters will not be able to spawn on the ds1, used for special maze rooms such as stairs leading up/down
*Causes Unhandled Exception if you add other monster objects when column is set to 0

Logicals: 1 yes/0 no
Setting to 1 allows walls to fade

Outdoors: 1 yes/0 no
Set to 1 for outdoor ds1's, 0 for indoor ds1's

Animate: 1 yes/0 no
Controls wether or not animated tiles will animate in the level

KillEdge: 1 yes/0 no
Removes the tiles bordering the east and south edge of the ds1 in game

FillBlanks: 1 yes/0 no
Setting to yes makes all blank tilespaces unwalkable

SizeX: Tells the x size of the map,
*Leave at 0 for preset areas since preset area size is defined in levels.txt

SizeY: Tells the y size of the map
*Leave at 0 for preset areas since preset area size is defined in levels.txt

Automap: 1 yes/0 no
Reveals full automap for level
*Only works for preset maps

Scan: 1 yes/0 no
Setting to yes allows warps to be selected

Pops: see below

PopPad: see below

Files: The amount of versions the map has, based on entries in File 1 to File 6 columns

File 1 to File 6: The location of the ds1 versions, leave at 0 for files that don't exist

Dt1mask: Number telling the game which tiles to use from lvltypes.txt

Beta:1 for beta, 0 not beta
*Reference only

Expansion:1 for expansion, 0 for non-expansion
*Reference Only


Pops and PopPad:

Pops are the special tiles with the Style (main-index) of 8 - 29. These remove the target style set from the map, revealing tiles in another layer.

    The Sequence number determines which Style set will be removed. These may be walls, floors or roof tiles.

    To operate, two "Pop tiles" are placed to form a square around the area of tiles to remove.

    The PopPad column in lvlprest.txt determines the line of the "trigger pad". It determines the number of sub-tile units south & west the trigger line is offset.

    You can only have one set of each style of pop. If you have 2 sets neither will operate properly, even if they have different target styles. So to have multiple pops in a level, you must use a different Style (main index) on each pair of pop tiles.



Note: When setting pops and poppad its best to reference an existing ds1 that contains the dt1's requiring these columns to help determine what value to use


Credits:
~SVR for Pop and PopPad explanation
~Go][um for the Logicals discovery

*/

/*
�ļ���������
Lvl��level������������ָ��ͼ��
Prest��preset��Ԥ�衣
���ļ����������е�ͼ��Ԥ����Ϣ��


�ظ�

    2¥
    2011-09-28 23:55

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-28 23:55

    �ٱ� |

    zqtjingzi
    С����
    12

Name����ͼ����������ע�͡�

Def���ڱ��ļ��е�λ�á���0��ʼ������������

LevelId����ͼ��š���Levels.txt������Ϊ0�ı�ʾ����Ԥ���ͼ��

Populate���˵�ͼ���Ƿ��й������NPC����

Logicals��ǽ���Ƿ��ͨ����

Outdoors���˵�ͼ�Ƿ��ڻ��⡣

Animate���˵�ͼ�Ƿ��ж�����

KillEdge���˵�ͼ�����·���ı߽��Ƿ�ɾ����

FillBlanks����ͼ�հ״��Ƿ�ɵ��

SizeX����ͼ�ĺ����ꡣ

SizeY����ͼ�������ꡣ

Automap���Ƿ��Զ����ɵ�ͼ����AutoMap.txt������

Scan����ͼ�Ƿ�ɾ�����

Pops����֪��ʲô���塣

PopPad����֪��ʲô���塣

Files���˵�ͼ�İ汾����

File1-6���˵�ͼ�����汾��Ӧ���ļ���

Dt1mask��ָ��LvlTypes.txt�����֡�

Beta�����ò���������ע�͡�

Expansion���Ƿ�������Ƭ���С�
*/

typedef struct
{
    int vDef;
    int vLevelId;
    int vPopulate;
    int vLogicals;
    int vOutdoors;
    int vAnimate;
    int vKillEdge;
    int vFillBlanks;
    int vExpansion;
    int iPadding9;

    int vSizeX;
    int vSizeY;
    int vAutoMap;
    int vScan;
    int vPops;
    int vPopPad;
    int vFiles;

    unsigned char vFile1[60];

    unsigned char vFile2[60];

    unsigned char vFile3[60];

    unsigned char vFile4[60];

    unsigned char vFile5[60];

    unsigned char vFile6[60];

    int vDt1Mask;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Name",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "Beta",
    NULL,
};

static int LvlPrest_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Name") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        return 1;
    }

    return 0;
}

int process_lvlprest(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Def, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LevelId, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Populate, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Logicals, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Outdoors, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Animate, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, KillEdge, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, FillBlanks, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Dt1Mask, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeX, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, SizeY, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoMap, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Scan, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Pops, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, PopPad, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Files, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File1, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File2, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File5, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, File6, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Expansion, INT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = LvlPrest_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
        case EN_MODULE_INIT:
        default:
            break;
    }

    return 1;
}

