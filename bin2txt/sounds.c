#include "global.h"

#define FILE_PREFIX "sounds"
#define NAME_PREFIX "so"

/*
A.sound = �������ֶΡ�
B.index = ��¼ID,ʹ��������txt�ļ�����Levels.txt,SoundEnviron.txt��
C.filename = ���������������ļ���mpq�ļ�������ļ�����ע��Act1-4��·��Ϊdata\global\music\act*\***.wav,��d2music.mpq��;Act5��·��Ϊdata\global\music\act5\***.wav,��d2xmusic.wav�ڡ��滻�����������ļ�ʱע��·�������⣬�ı��ļ�����Ч��(����¼)
D.volume = ���������������ƣ�ȡֵ0-255���Ƿ�������ȡ����music vol��ֵ�����¡�
E.group size = �������ļ��ж��ʱ(һ��),������š��е������������ͼ����һ��ֻ��һ��ʱ,ֵΪ0,�������ڸ���ĵ�һ���ļ��ĸ��������ļ�����,����ȡֵΪ0��Ҳ����˵ֻ��һ��������ĵ�һ���ļ�\ֵ��Ϊ0��(�Һ�����!)
F.loop = �Ƿ�ѭ�����š�1=ѭ�����ţ�0=����һ�Ρ�
G/H.fade in/fade out = ���ֵ���򵭳���������ʱ�䣬����������ʧ��ָ����������Ҫ��ʱ�䡣
I.defer inst = δ֪
J.stop inst = δ֪
K.duration = ����ʱ�䡣���岻���,�ƺ����˼����йذ�������ϵĵ�������,��Act2��Act3(��IDΪ171��189�������ļ�����),������ȡֵ0��
L.compound = ����ͬʱ���ŵ���������??�������
M.reverb = 0/1�����Ƿ����ӻ���Ч����������
N.falloff = ȡֵ0-4�������������������Ŀ�����
O.cache = 0/1�����Ƿ񾭳��ڻ����в��š�
P.async only = 0/1�����Ƿ��������Ų���Ҫ���������װ�ز���ʱ��
Q.priority = ȡֵ0-255�����������ı����������ͬʱ�ж�����ֲ��š����仰˵���ǿ��Ʋ��ŵ����ȼ���
R.stream = 0/1���������Ƿ��װ�ر߲��ţ�������װ���ٲ���;ֻ�������ļ���Ч��
S.stereo = ����ֵ��������������ֻ�������ļ���Ч��ע��:16bits(λ)wav��ʽ��������22,050Hz��
T.tracking = 0/1���������Ƿ������������������ƶ�,�����������ļ���>=2��ȡֵ1��
U.solo = 0/1���Ƹ������ļ��Ƿ񵥶����š�
V.music vol = 0/1�����Ƿ�ʹ��volume��������ֵ��
W.block 1 = ѭ�������������ļ��е�ƫ������
X.block 2 = ͬ�ϡ�
Y.block 3 = ͬ�ϡ�
*/

typedef struct
{
    unsigned short vIndex;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Sound",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "FileName",
    "Volume",
    "Group Size",
    "Loop",
    "Fade In",
    "Fade Out",
    "Defer Inst",
    "Stop Inst",
    "Duration",
    "Compound",
    "Reverb",
    "Falloff",
    "Cache",
    "Async Only",
    "Priority",
    "Stream",
    "Stereo",
    "Tracking",
    "Solo",
    "Music Vol",
    "Block 1",
    "Block 2",
    "Block 3",
    NULL,
};

typedef struct
{
    char vSound[64];
} ST_ITEM_SOUNDS;

static unsigned int m_iItemSoundsCount = 0;
static ST_ITEM_SOUNDS *m_astItemSounds = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astItemSounds, ST_ITEM_SOUNDS);

static int Sounds_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Sound") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else if ( 0 < iLineNo )
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }
        else
        {
            acOutput[0] = 0;
        }
#else
        sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
#endif

        strncpy(m_astItemSounds[pstLineInfo->vIndex].vSound, acOutput, sizeof(m_astItemSounds[pstLineInfo->vIndex].vSound));
        m_iItemSoundsCount++;
        return 1;
    }

    return 0;
}

static char *Sounds_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    memset(pcKey, 0, sizeof(pcKey));
    sprintf(pcKey, "%u", pstLineInfo->vIndex);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

static int process_sounds_x(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Index, USHORT);

    m_iItemSoundsCount = 0;

    //m_stCallback.pfnGetKey = Sounds_GetKey;
    m_stCallback.pfnFieldProc = Sounds_FieldProc;
    m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
    m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;
    m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

    File_CopyFile(acTemplatePath, acTxtPath, "SoundEnviron", ".txt");

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_sounds(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            return process_sounds_x(acTemplatePath, acBinPath, acTxtPath);
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

char *Sounds_GetSoundName(unsigned int id)
{
    if ( id >= m_iItemSoundsCount )
    {
        return NULL;
    }

    return m_astItemSounds[id].vSound;
}

