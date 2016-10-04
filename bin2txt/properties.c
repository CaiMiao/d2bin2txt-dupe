#include "global.h"

#define FILE_PREFIX "properties"
#define NAME_PREFIX "pr"

/*
Title 	Properties.txt File Guide
Description 	by Joel Falcou (revised by Myhrginoc)
Sent by 	
This file depends on ItemStatCost.txt. A stat must be defined there in order to use its ID in the stat1-7 fields.

The bulk of the file consists of seven finction blocks. Each block has a function index (FuncX) and three parameters (SetX, ValX, StatX). Parameters are only useful if the underlying function is written to interpret them.

A "*" in the field name means it is a comment field not loaded into the game.

code: property identifier to use in other txt files anywhere a property is applied (e.g. MagicPrefix, MagicSuffix, Automagic, MonProp, Gems, Runes, Sets, SetItems, UniqueItems, Cubemain).

*done: 1 if the property is active (boolean).

set1 to set7: parameter to the property function, if the function can use it (see Color property)

val1 to val7: parameter to the property function, if the function can use it (see class skills properties).

func1 to func7: Function used to assign a value to a property (see list below)

stat1 to stat7: Stat applied by the property (see ItemStatCost.txt), if the function uses it.

*desc: Description of the property

*param: Description of the param value

*min: Description of the min value

*max: Description of the max value

*notes: Additional comments

*eol: terminator field, not used in game, primary purpose is to keep Microsoft Excel from misbehaving.


APPENDIX: Functions of Properties.txt

Here are some functions used by the properties.txt to link param/min/max value to the actual bonus of the properties.

1 - Applies a value to a stat, can use SetX parameter.
2 - defensive function only, similar to 1 ???
3 - Apply the same min-max range as used in the previous function block (see res-all).
4 - not used ???
5 - Dmg-min related ???
6 - Dmg-max related ???
7 - Dmg% related ???
8 - ??? use for speed properties (ias, fcr, etc ...)
9 - Apply the same param and value in min-max range, as used in the previous function block.
10 - skilltab skill group ???
11 - event-based skills ???
12 - random selection of parameters for parameter-based stat ???
13 - durability-related ???
14 - inventory positions on item ??? (related to socket)
15 - use min field only
16 - use max field only
17 - use param field only
18 - Related to /time properties.
19 - Related to charged item.
20 - Simple boolean stuff. Use by indestruct.
21 - Add to group of skills, group determined by stat ID, uses ValX parameter.
22 - Individual skill, using param for skill ID, random between min-max.
23 - ethereal
24 - property applied to character or target monster ???
25--32 can be used in custom code. Check plugin documentation for syntax.

*/

/*
ע�⣺����*���ŵ�����Ϸ��������ģ�

code - ����Ĵ�������ǰ����׺���������װ����ļ�����Ʒ�����
*done - 1Ϊ����ɣ�ʵ����û�ã���
set1-7 - ����ɫ������Ϊ1������Ϊ�������ͣ�
val1-7 - һЩ�����й̶���ֵ��������+����ѷ���ܣ���
func1-7 - ����ֵ�ļ��㹫ʽ�������棩��
stat1-7 - ����������Ա仯(����itemstatcost.txt) ��
*desc - �Ը����Ե�������
*param - �����Բ�����������
*min - ��������Сֵ��������
*max - ���������ֵ��������
*notes - ������
*eol - �н�����

func1-7:
ͨ�����º�����param/min/max����ʵ�ʵĽ�����
1 - ʹ��STAT��ֵ��
2 - ���ò�����
3 - ��������������ͬ��ֵ (��������п���)��������Ļ���Func1 Ӧ��Ϊ1��
5 - �й�Dmg-min��
6 - �й�Dmg-max��
7 - �й�Dmg%��
8 - ���ٶ��йص�����ʹ��(ias,fcr ��...)��
10 - δ֪�����ò�����
11 - δ֪�����ò�����
12 - δ֪�����ò�����
13 - δ֪�����ò�����
14 - �밼���йصĲ�����
15 - ʹ��min��ֵ��
16 - ʹ��MAX��ֵ��
17 - ʹ��PARAM��ֵ��
18 - ��ʱ���йص����ԣ�
19 - ����������ܵ���Ʒ�йأ�
20 - �޷��ƻ���
21 - ��ְҵר�õĶ����йأ�ǰ���VALUE������ְҵID��0��6����
22 - ������ְҵ���ض����ܵ�(����Ұ�����Ǹ����ǵ�ñ��)��
23 - δ֪�����ò�����
24 - δ֪�����ò�����
*/

/*
�ļ���������Property(ies)�������Ե���˼��
���ļ��е�ÿһ�б�ʾ���ܳ�����װ���ϵ�һ�����ԡ�


�ظ�

    2¥
    2011-09-04 11:26

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�ע�⣺����*���ŵ�����Ϸ�ǲ�����ģ�Ҳ����˵��Щ���൱��ע�͡�


�ظ�

    3¥
    2011-09-04 11:26

    �ٱ� |

    zqtjingzi
    С����
    12

code�����ԵĴ��룬����ħ��ǰ����׺������װ���ļ�����Ʒ���Դ�ʹ�á�
���������װ�����һ��ȫ���ܵ����ԣ���ô���Ҫ�ҵ�ȫ���ܵĴ��룬Ӧ������106�У�����Ϊallskills�������������ӵ�װ����prob�У��ټ���һ������Ĳ�������װ������+ȫ���ܵ������ˡ�

*done�������Եı༭�Ƿ�����ɣ�0Ϊδ��ɣ�1Ϊ����ɣ���ʵ����Ϸ�д��в������á�

set1-7�����������ɫ�йص��У�����Ϊ�������ͣ���Ҳû̫Ū���������ʲô���壬������Color�������������Զ�û��ʹ����Щ�С�


�ظ�

    4¥
    2011-09-04 11:27

    �ٱ� |

    zqtjingzi
    С����
    12

val1-7����ĳְҵ����ר�õ��У���Ϊְҵ����ʹ�á�ְҵ��������档

func1-7�������ԵĲ������㷽�����������ϸ˵����

stat1-7�������Զ������Ӱ�죬(����ItemStatCost.txt) ��

*desc���Ը����Ե�������
*param���Ը��������ʹ��paramֵ��������
*min���Ը��������minֵ��������
*max���Ը��������maxֵ��������
*notes��������һЩע�͡�*eol���н�����־��������0��


�ظ�

    5¥
    2011-09-04 11:27

    �ٱ� |

    zqtjingzi
    С����
    12

func1-7:ͨ�����·�ʽʹ��param/min/max��ֵ���������Ե���ֵx��
1��min <= x <= max��ֻȡ���������ȷֲ���
2���롰1��һ����Ӧ���������𣬵�����û���֣���
3��ֻ���ܳ�����func2-7�⼸���У���ʾʹ����func1ͬ���ķ�ʽ�����ڼ����п������������ԡ����Ҵ�ʱfunc1Ӧ��Ϊ1��
4��û����
5��ȡֵ��ʽ�롰1��һ������ֻ����dmg-min����ʹ�ã���������ʹ�ô˺��������Զ�����Ϊdmg-min����������С�˺�ֵ��
6��ȡֵ��ʽ�롰1��һ������ֻ����dmg-max����ʹ�ã���������ʹ�ô˺��������Զ�����Ϊdmg-max������������˺�ֵ��
7��ȡֵ��ʽ�롰1��һ������ֻ����dmg%����ʹ�ã���������ʹ�ô˺��������Զ�����Ϊdmg%�������Ӱٷֱ��˺�ֵ��
8��ȡֵ��ʽ�롰1��һ���������ٶ��йص�����(ias,fcr,frw)��ʹ��������������˳��ԣ��á�1��Ҳ���ԡ�
9��û������
10����ĳһϵ����ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ����ϵ���룬ʹ��min��max��ֵ��Ϊ������Χ��ϵ��������档
11����������ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ���ܴ��룬ʹ��min��ֵ��Ϊ�������ʣ�ʹ��max��ֵ��Ϊ���ܵȼ���
12���������������ר�ã������˹���ۣ���ʹ��param��ֵ��Ϊ���ܵȼ�����min��max���޶��������ȡֵ��Χ�����������Ϊ���ܴ���ʹ�á�
13��ȡֵ��ʽ�롰1��һ������ʹ�ô˺�����װ��������ʱ�;ö�Ϊ��ֵ��
14��ȡֵ��ʽ�롰1��һ������ֻ����sock����ʹ�ã���������ʹ�ô˺��������Զ�����Ϊsock�������Ӱ��ۡ�
15��ʹ��min��ֵ��
16��ʹ��max��ֵ��
17��ʹ��param��ֵ��
18����ʱ��仯����ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ�������ʱ��ʱ��Σ�0=���죬1=�ƻ裬2=ҹ��3=����������ʱ������ֵΪmax�������ڶ���ʱ��Σ���������ҹ��ʱʹ��min��Ϊ����ֵ�������м�����ʱ���ʹ��min��max��ƽ��ֵ��
19��������������ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ���ܴ��룬ʹ��min��ֵ��Ϊ��������ʹ��max��ֵ��Ϊ���ܵȼ���
20���޷��ƻ�����ר�á���ʹ��������������������ʹ�ô˺��������Զ�����Ϊ�޷��ƻ����ԡ�
21��ȡֵ��ʽ�롰1��һ������Ҫ�����ǰ���val�б�����ֵ����ʹ�ô�ֵ��Ϊְҵ������������Ե�ְҵ���ơ�
22����ĳһ�������ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ���ܴ��룬ʹ��min��max��ֵ��Ϊ���Ӽ��ܵȼ��ķ�Χ��
23����������ר�á���ʹ��������������������ʹ�ô˺��������Զ�����Ϊ�������ԡ�
24��state����ר�á�����ʹ�÷�ʽ���£�ʹ��param��ֵ��Ϊ״̬��������min��max��ֵ���޶���״̬�Ƿ���Ч��
36���������ļ����һ��ְҵ�������ר�á�ʹ�ô���ǰ��val����Ϊ���ܵȼ�����min��max���޶�������ķ�Χ�����������Ϊְҵ����ʹ�á�



�ظ�

    6¥
    2011-09-04 11:29

    �ٱ� |

    zqtjingzi
    С����
    12

ְҵ�������£�
0 = ����ѷ
1 = ��ʦ
2 = ����
3 = ʥ��
4 = Ұ����
5 = ��³��
6 = �̿�




�ظ�

    7¥
    2011-09-04 11:29

    �ٱ� |

    zqtjingzi
    С����
    12

ϵ���룺
0 = ama��
1 = ama����
2 = ama��ǹ
3 = sor����
4 = sor����
5 = sor��
6 = nec����
7 = nec�Ƕ�
8 = nec�ٻ�
9 = palս��
10= pal����
11= pal����
12= barս��
13= bal֧��
14= barս��
15= dru�ٻ�
16= dru����
17= druԪ��
18= asn����
19= asnӰ��
20= asn��ѧ


�ظ�

    8¥
    2011-09-04 11:30

    �ٱ� |

    zqtjingzi
    С����
    12

��ϡ�
����д�����ָ����
ף��λ��Ϸ��졣



��ԭ��ȷʵ˵�Ĳ���ȫ�棬�����ڷ�ȭ�Ļ��漼��������ô���ģ����漼��������ְҵ�����編ʦ����ʹ����ͬ����val=1��func=21���������������ʹ���˲�ͬ��stat�����漼������item_elemskill���stat������ʦ����ʹ����item_addclassskills��һstat���˶�����Ϊfunc
��ͬ������ѡ������ķ�ʽ����ͬ�ģ�����������ں�ѡ**��һ����ְҵ�����е�valָ������ְҵ�б��е�ĳ��ְҵ�������漼�ܣ��ϸ�˵��Ӧ�ý�Ԫ�ؼ��ܣ�ָ������Ԫ�����ͣ���Ӧ����ָ��Elemtypes.txt��ָ�롣����㽫���漼�ܵ�val1�ĳ�2
����ͻᷢ�����ӳɵļ��ܱ�������缼�ܣ���Elemtypes.txt�еĵڶ��У�����֤������

������ڻ��漼�ܵĽ綨����skills.txt��д���ģ�����EType�е�ֵ��fire�Ķ��ǻ��漼�ܣ�����ʦ�ⲻ����ʬ����������ѷ�ı��Ѽ���ʥ���ʥ�����Ի��漼�ܣ������ܹ�����ȭ��߼��ܵȼ��ġ�

*/

typedef struct
{
    unsigned short vcode;
    unsigned char vset1;
    unsigned char vset2;

    unsigned char vset3;
    unsigned char vset4;
    unsigned char vset5;
    unsigned char vset6;

    unsigned char vset7;
    unsigned char iPadding2;
    unsigned short vval1;

    unsigned short vval2;
    unsigned short vval3;

    unsigned short vval4;
    unsigned short vval5;

    unsigned short vval6;
    unsigned short vval7;

    unsigned char vfunc1;
    unsigned char vfunc2;
    unsigned char vfunc3;
    unsigned char vfunc4;

    unsigned char vfunc5;
    unsigned char vfunc6;
    unsigned char vfunc7;
    unsigned char iPadding7;

    unsigned short vstat1;
    unsigned short vstat2;

    unsigned short vstat3;
    unsigned short vstat4;

    unsigned short vstat5;
    unsigned short vstat6;

    unsigned short vstat7;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vcode[32];
} ST_PROPERTY;

static char *m_apcInternalProcess[] =
{
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "*done",
    "*desc",
    "*param",
    "*min",
    "*max",
    "*notes",
    NULL,
};

static unsigned int m_iPropertyCount = 0;
static ST_PROPERTY *m_astProperty = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astProperty, ST_PROPERTY);

static int Properties_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

char *Properties_GetProperty(unsigned int id)
{
    if ( id >= m_iPropertyCount )
    {
        return NULL;
    }

    return m_astProperty[id].vcode;
}

static int Properties_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp("code", acKey) )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vcode);
        }

        strncpy(m_astProperty[pstLineInfo->vcode].vcode, acOutput, sizeof(m_astProperty[pstLineInfo->vcode].vcode));
        String_Trim(m_astProperty[pstLineInfo->vcode].vcode);
        m_iPropertyCount++;
        result = 1;
    }

    return result;
}

static int Properties_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;
    int id;

    if ( !strcmp("code", acKey) )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vcode);
        }

        result = 1;
    }
    else if ( strstr(acKey, "stat") && 1 == sscanf(acKey, "stat%d", &id) )
    {
        unsigned short *psSkill = (short *)&pstLineInfo->vstat1;
        pcResult = ItemStatCost_GetStateName(psSkill[id-1]);
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

int process_properties(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set4, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set6, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set7, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, val7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func2, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func3, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func4, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func5, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func6, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, func7, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat6, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat7, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_iPropertyCount = 0;

            m_stCallback.pfnConvertValue = Properties_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Properties_ConvertValue;
            m_stCallback.pfnFieldProc = Properties_FieldProc;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

