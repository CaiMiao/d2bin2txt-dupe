#include "global.h"

#define FILE_PREFIX "Experience"

/*
�ļ���������
Experience�����顣
���Դ��ļ�����������ɫ���ȼ��Լ�ÿһ����������ľ��顣

Level������

Amazon������ѷ����һ������ľ��顣

Sorceress����ʦ����һ������ľ��顣

Necromancer�����鷨ʦ����һ������ľ��顣

Paladin��ʥ��ʿ����һ������ľ��顣

Barbarian��Ұ��������һ������ľ��顣

Druid����³������һ������ľ��顣

Assassin���̿�����һ������ľ��顣

��ʵ��ÿ����ɫ����ͬ����ʱ����һ������ľ��鶼����ͬ�ģ�����ôд�����������Լ���MOD�ṩ�˺ܷ����ǰ�ᡣ

ExpRatio��ÿһ��ʱ�ľ���˥�����ӡ�ÿһ��ʱ��������õľ���Ϊ��ԭ���飩* ExpRation / 1024��
����ֵ�ĳ�����һ��Ϊ2�ı������������׳����޷���������������

MaxLvl - ��ɫ������������߼�����Ҫ��Ӧ�ľ���ֵ����


���ļ�ԭ������102�С�
��1����������
��2����MaxLevel����ÿ����ɫ���ܴﵽ����󼶱�
��3-102��Ϊ��0����ʼ��������һ������ľ��飬�Լ���ɫ�ڴ˵ȼ�ʱ�ľ���˥�������

������Ҫ���ĵȼ�������200��ֻ�轫��2�У���MaxLevel�е�ֵ����Ϊ200�����һ�в��øġ�Ȼ�����ļ�ĩβ����101�У��ֱ��ʾ��100����ʼ������һ������ľ��飬Ȼ����д����Ӧ�ľ���Ҫ�󼴿ɡ���Ҫ˵�����ǣ�����ֵ����ܳ���2^32 -1 = 4,294,967,295��һ����������0
���¿�ʼ�ۻ����������ڴ洢��ʽ��λ�������ġ�

chunqiang666: ��ã��Ҽ��㷢������90�༶��ʱ�����������ǰ��հٷ�֮9.01�����ģ������Ļ���101��ʱ�������辭�����4560454391�ˣ��Ѿ��������ֵ�ˣ����Ӧ����ô���أ������Լ��趨��������ĵ����ٷֱ�ô��лл��
2013-3-15 17:53�ظ�
zqtjingzi: �ظ� chunqiang666 :ԭ����Ϸ��ֻ������99��֮ǰ����������֮�����չ�Ƿǳ����ɵġ��������������99��֮��ÿ100�㾭�����һ��
2013-3-15 18:44�ظ�
chunqiang666: �ظ� zqtjingzi :Ŷ��лл�ˣ��Ұ���1.0000901�������ģ��������㻹�Ƿ������ɴ��ɵĻ�Ա����
2013-3-15 19:55�ظ�
chunqiang666: �ظ� zqtjingzi :֮ǰ����һ��������д�ȼ��趨��ò�Ҫ����127��˵�ǳ���127����Ҫ��ʲô�������У���������ô��лл��
2013-3-17 20:58�ظ�

��Ҳ˵һ��
*/

typedef struct
{
    unsigned int vAmazon;
    unsigned int vSorceress;
    unsigned int vNecromancer;
    unsigned int vPaladin;

    unsigned int vBarbarian;
    unsigned int vDruid;
    unsigned int vAssassin;
    unsigned int vExpRatio;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Level",
    NULL,
};

static int Experience_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Level") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%u", iLineNo - 1);
        }
        return 1;
    }

    return 0;
}

int process_experience(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Amazon, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Sorceress, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Necromancer, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Paladin, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Barbarian, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Druid, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Assassin, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ExpRatio, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = Experience_FieldProc;
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

