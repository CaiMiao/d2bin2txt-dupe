#include "global.h"

#define FILE_PREFIX "events"
#define NAME_PREFIX "ev"

/*
�����е�TXT�ļ��У���һ����ΪEvents.txt��TXT�ļ���ֻ��14��2�У���С��С�������ò��ɵ͹�����Events���򵥷�
�͹����͡��¼���֮�⣬Events.txt�ļ��м�¼��13����Events���¼�����������һ�¶���ʲô�¼���������Ϸ�С�

�¼����� �� �¼�����

hitbymissile �� ����������������(��������)��

damagedinmelee �� ʹ��ս��Χ�ڵĵ����ܵ��˺�(������������)��

damagedbymissile �� ʹ�����ܵ��������˺�(��������)��

attackedinmelee �� �Ի�ս��Χ�ڵĵ��˽��й���(������������)��

doactive �� �����״̬��

domeleedamage �� ʹ�����ܵ����˺����ظ��Է�(��������)��

domissiledamage �� ʹ�����ܵ������﹥���˺�(��������)��

domeleeattack �� �Խ�����˹���(��������)��

domissileattack �� �Ը������˽��з����﹥��(��������)��

kill �� ɱ�����˺�õ����ƣ�

killed �� ��ɱ����

absorbdamage �� �����˺�(��������)��

levelup �� �ȼ����ӡ�

����Events.txt���е��¼����ϣ�֪���������ļ�����������֪������һ���£����ǡ�Event Functions����ֱ�;��ǡ��¼�����������������¼������������������Ǹ����������ֱ��ǡ�1��31����31�����¼�������������������һ�¾������ݡ�

�¼����� �� ��������

1 �� ��װ���ϼ��ϱ����������

2 �� ��װ���ϼ��϶��ᱨ�����

3 �� ��װ���ϼ���˪���������

4 �� ʹ������ɵ��˺������ڱ���

5 �� ʹ���˱�����ʱ�������򹥻���

6 �� ʹ�������ܵ������˺�

7 �� ����

8 �� �ø����Ĺ�����־������

9 �� ʹ����Ŀä

10 �� �������ܵ������˺�

11 �� �������ܵ������˺�

12 �� �������ܵ������˺�

13 �� ��ʧ����

14 �� ����Ŀ��

15 �� ˺���˿�

16 �� ѹ����

17 �� ���ӷ���

18 �� ��������

19 �� ��������

20 �� �ڹ���ʱ�ͷż���

21 �� �ڱ�����ʱ�ͷż���

22 �� ���������˺�

23 �� ����Ѫʯħ�ܵ�������ʧ��ͬʱʯħ��������Ҳͬ����ʧ����

24 �� ���������˺������˺������˺������˺��е�һ�ֻ����

25 �� ���ջ𡢵硢������Ԫ���˺�

26 �� ����Ѫʯħȡ��������ͬʱʯħ��������Ҳͬ��ȡ������

27 �� ���������ʯħ���˻��ǵ������ˣ���ʹ�����ٶȼ�����

28 �� ��������

29 �� ����ȥ���˵����������������ħ��

30 �� ������������ʱ�ͷż���

31 �� ����

���ϱ���ȫ���ġ��¼��������͹��ܼ�顣


*/

typedef struct
{
    unsigned short vevent;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*desc",
    NULL,
};

typedef struct
{
    char vevent[64];
} ST_EVENTS;

static unsigned int m_iEventsCount = 0;
static ST_EVENTS *m_astEvents = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astEvents, ST_EVENTS);

static int Events_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "event") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vevent);
        }

        strncpy(m_astEvents[m_iEventsCount].vevent, acOutput, sizeof(m_astEvents[m_iEventsCount].vevent));
        String_Trim(m_astEvents[m_iEventsCount].vevent);
        m_iEventsCount++;
        return 1;
    }

    return 0;
}

static int process_events_x(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, event, USHORT);

    m_iEventsCount = 0;

    m_stCallback.pfnConvertValue = Events_ConvertValue;
    m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
    m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
    m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_events(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            return process_events_x(acTemplatePath, acBinPath, acTxtPath);
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

char *Events_GetEventName(unsigned int id)
{
    if ( id >= m_iEventsCount )
    {
        return NULL;
    }

    return m_astEvents[id].vevent;
}

