#include "global.h"

#define FILE_PREFIX "colors"

typedef struct
{
    char vCode[4];
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_COLORS;

static char *m_apcInternalProcess[] =
{
    "Transform Color",
    NULL,
};

static unsigned int m_iColorCount = 0;
static ST_COLORS *m_astColors = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astColors, ST_COLORS);

static int Colors_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "Transform Color") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            strncpy(acOutput, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        }

        strncpy(m_astColors[m_iColorCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astColors[m_iColorCount].vCode);
        m_iColorCount++;
        return 1;
    }

    return 0;
}

static char *Colors_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strncpy(pcKey, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

static int process_colors_x(char *acTemplatePath, char *acBinPath, char *acTxtPath)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    m_iColorCount = 0;

    //m_stCallback.pfnGetKey = Colors_GetKey;
    m_stCallback.pfnFieldProc = Colors_FieldProc;
    m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
    m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
    m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

    return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
        pstValueMap, Global_GetValueMapCount(), &m_stCallback);
}

int process_colors(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            return process_colors_x(acTemplatePath, acBinPath, acTxtPath);
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

char *Colors_GetColorCode(unsigned int id)
{
    if ( id >= m_iColorCount )
    {
        return NULL;
    }

    return m_astColors[id].vCode;
}

