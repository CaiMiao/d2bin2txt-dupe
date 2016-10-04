#include "global.h"

static clock_t m_iStartTick = 0;
static clock_t m_iEndTick = 0;
#define START_TICK \
    m_iStartTick = clock()
#define CALC_TICK \
    do {\
        m_iEndTick = clock();\
        printf("duration: %u ms\r\n", m_iEndTick - m_iStartTick);\
    } while (0)

char m_acGlobalBuffer[m_iGlobaBufLength] = {0};
char m_acLineInfoBuf[m_iLineBufLength] = {0};
char m_acValueMapBuf[m_iValueBufLength] = {0};
unsigned int m_iValueMapIndex = 0;

ST_CALLBACK m_stCallback;

static char m_acTempBuffer[m_iGlobaBufLength] = {0};

unsigned int Global_GetValueMapCount()
{
    return m_iValueMapIndex;
}

int File_GetFileSize(char *pcFileName)
{
    int iresult;
    struct _stat buf;

    iresult = _stat(pcFileName, &buf);
    if ( iresult == 0 )
    {
        return buf.st_size;
    }

    return 0;
}

int File_CopyFile(char *pcFromPath, char *pcToPath, char *pcFileName, char *pcSuffix)
{
    memset(m_acTempBuffer, 0, sizeof(m_acTempBuffer));
    sprintf(m_acTempBuffer, "copy /y %s\\%s%s %s\\%s%s", pcFromPath, pcFileName, pcSuffix, pcToPath, pcFileName, pcSuffix);
    system(m_acTempBuffer);

    return 1;
}

unsigned char *String_Trim(unsigned char *pcValue)
{
    int j;

    for ( j = strlen(pcValue) - 1; j >= 0; j-- )
    {
        if ( ' ' != pcValue[j] )
        {
            break;
        }

        pcValue[j] = 0;
    }

    return pcValue;
}

static int TXTBUF_ReplaceSpecialChar(char *key, char *acTempKey)
{
    int i, j;

    for ( i = 0, j = 0; i < (int)strlen(key); i++ )
    {
        if ( ' ' == key[i] )
        {
            strcpy(&acTempKey[j], "mysp");
            j += strlen(&acTempKey[j]);
        }
        else if ( '.' == key[i] )
        {
            strcpy(&acTempKey[j], "mypoint");
            j += strlen(&acTempKey[j]);
        }
        else if ( '-' == key[i] )
        {
            strcpy(&acTempKey[j], "mysub");
            j += strlen(&acTempKey[j]);
        }
        else if ( '/' == key[i] )
        {
            strcpy(&acTempKey[j], "myslash");
            j += strlen(&acTempKey[j]);
        }
        else if ( '(' == key[i] )
        {
            strcpy(&acTempKey[j], "mybr1");
            j += strlen(&acTempKey[j]);
        }
        else if ( ')' == key[i] )
        {
            strcpy(&acTempKey[j], "mybr2");
            j += strlen(&acTempKey[j]);
        }
        else
        {
            acTempKey[j] = key[i];
            j++;
        }
    }
    acTempKey[j] = 0;

    return j;
}

/*
�ϲ��ֶ�����:
1���Ա�ͷ���ֶ�������ת�����������ṹ����ֶ������ո�����ֶα���������mysp���
2�����bin�ļ����ж���Ļ�������bin��ߵ�ֵ
3��������ģ���������
4�����ֵ�ֶ�ĩβ�����пո�
*/
static char * TXTBUF_FILL(char *key, ST_VALUE_MAP *map, int count, char *start, char *from, 
    ST_CALLBACK *callback, void *pvLineInfo, int iLineNo, int iFieldNo)
{
    int i;
    static char acTempKey[1024] = {0};
    static char acTempValue[1024] = {0};

    //1���Ա�ͷ���ֶ�������ת�����������ṹ����ֶ������ո�����ֶα���������mysp���
    TXTBUF_ReplaceSpecialChar(key, acTempKey);

    for ( i = 0; i < count; i++ )
    {
        if ( strcmp(acTempKey, map[i].acKeyName) )
        {
            continue;
        }

        //2�����bin�ļ����ж���Ļ�������bin��ߵ�ֵ
        if ( 0 < iFieldNo )
        {
            *start = '\t';
            start++;
        }
        memset(acTempValue, 0, sizeof(acTempValue));

        if ( !callback || !callback->pfnConvertValue || 0 == callback->pfnConvertValue(pvLineInfo, key, from, acTempValue) )
        {
            if ( EN_VALUE_CHAR == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(char *)map[i].pvValue);
            }
            else if ( EN_VALUE_SHORT == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(short *)map[i].pvValue);
            }
            else if ( EN_VALUE_INT == map[i].enValueType )
            {
                sprintf(acTempValue, "%d", *(int *)map[i].pvValue);
            }
            else if ( EN_VALUE_UCHAR == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned char *)map[i].pvValue);
            }
            else if ( EN_VALUE_USHORT == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned short *)map[i].pvValue);
            }
            else if ( EN_VALUE_UINT == map[i].enValueType )
            {
                sprintf(acTempValue, "%u", *(unsigned int *)map[i].pvValue);
            }
            else if ( EN_VALUE_STRING == map[i].enValueType )
            {
                strncpy(acTempValue, map[i].pvValue, map[i].iValueLen);
            }
            else if ( EN_VALUE_BIT == map[i].enValueType && callback && callback->pfnBitProc )
            {
                callback->pfnBitProc(pvLineInfo, key, acTempValue);
            }

            //4�����ֵ�ֶ�ĩβ�����пո�
            if ( 0 != acTempValue[0] && !('0' == acTempValue[0] && 0 == acTempValue[1] && EN_VALUE_STRING != map[i].enValueType) )
            {
                String_Trim(acTempValue);
                strcpy(start, acTempValue);
                start += strlen(start);
            }
        }
        else
        {
            //4�����ֵ�ֶ�ĩβ�����пո�
            if ( 0 != acTempValue[0] )
            {
                String_Trim(acTempValue);
                strcpy(start, acTempValue);
                start += strlen(start);
            }
        }

        break;
    }

    //3��������ģ���������
    if ( i >= count )
    {
        if ( 0 < iFieldNo )
        {
            *start = '\t';
            start++;
        }
        if ( !callback || !callback->pfnFieldProc || 0 == callback->pfnFieldProc(pvLineInfo, key, iLineNo, from, start) )
        {
            strcpy(start, from);
        }
        start += strlen(start);
    }

    return start;
}

static int process_line_x(char *pcHeader, char *pcLineEnd, char *pcLineStart, char *pcTxt, char *acClass, 
    void *pvLineInfo, ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback, int iLineNo)
{
    char *pcAnchor, *pcAnchor2, *pcAnchorTemp;
    char bAnchor, bAnchor2;
    int result = 1;
    int i = 0;

    //���ֶδ���
    do
    {
        //�ҵ���ͷ�ֶ�β��tab���ͻس����У��ȵ�Ϊ׼
        pcAnchor = strchr(pcHeader, '\t');
        pcAnchorTemp = strchr(pcHeader, '\r');
        if ( pcAnchor && pcAnchorTemp )
        {
            if ( pcAnchor < pcAnchorTemp )
            {
                bAnchor = '\t';
            }
            else
            {
                pcAnchor = pcAnchorTemp;
                bAnchor = '\r';
            }
        }
        else if ( pcAnchor && !pcAnchorTemp )
        {
            bAnchor = '\t';
        }
        else if ( !pcAnchor && pcAnchorTemp )
        {
            pcAnchor = pcAnchorTemp;
            bAnchor = '\r';
        }
        else
        {
            my_error("%s fail1 at %s\r\n", acClass, pcHeader);
            result = 0;
            break;
        }

        //�ҵ������е��ֶ�β��tab���ͻس����У��ȵ�Ϊ׼
        pcAnchor2 = strchr(pcLineStart, '\t');
        pcAnchorTemp = strchr(pcLineStart, '\r');
        if ( pcAnchor2 && pcAnchorTemp )
        {
            if ( pcAnchor2 < pcAnchorTemp )
            {
                bAnchor2 = '\t';
            }
            else
            {
                pcAnchor2 = pcAnchorTemp;
                bAnchor2 = '\r';
            }
        }
        else if ( pcAnchor2 && !pcAnchorTemp )
        {
            bAnchor2 = '\t';
        }
        else if ( !pcAnchor2 && pcAnchorTemp )
        {
            pcAnchor2 = pcAnchorTemp;
            bAnchor2 = '\r';
        }
        else
        {
            my_error("%s fail2 at %s\r\n", acClass, pcHeader);
            result = 0;
            break;
        }

        *pcAnchor = 0;
        *pcAnchor2 = 0;

        //�ϲ����ֶε�����
        pcTxt = TXTBUF_FILL(pcHeader, astValueMap, iCount, pcTxt, pcLineStart, pstCallback, pvLineInfo, iLineNo, i);

        *pcAnchor = bAnchor;
        *pcAnchor2 = bAnchor2;
    } while ( (pcHeader = strchr(pcHeader, '\t')) && (pcLineStart = strchr(pcLineStart, '\t'))
            && pcHeader < pcLineEnd && pcHeader++ && pcLineStart++ && ++i );

    //һ�н��������ϻس�����
    *pcTxt = '\r';
    pcTxt++;
    *pcTxt = '\n';
    pcTxt++;

    if ( NULL != pcHeader && pcHeader < pcLineEnd )
    {
        my_error("%s fail1 at lineend\r\n", acClass);
        result = 0;
    }

    return result;
}

static int Is_StringInList(char **ppcList, char *pcLookup)
{
    int i = 0;

    if ( !ppcList || !pcLookup )
    {
        return 0;
    }

    while ( NULL != ppcList[i] )
    {
        if ( !strcmp("all over in", ppcList[i]) )
        {
            return 1;
        }

        if ( !strcmp(pcLookup, ppcList[i]) )
        {
            return 1;
        }

        i++;
    }

    return 0;
}

//�����Щ�ֶ���bin�ļ���û�ж�ȡ������
static int check_missing(char *pcHeader, char *pcLineEnd, ST_VALUE_MAP *astValueMap, int iCount, char *pcFileName, ST_CALLBACK *pstCallback)
{
    char *pcAnchor, *pcAnchorTemp;
    char bAnchor;
    int result = 1;
    int i;
    char acTempKey[256] = {0};

    //���ֶδ���
    do
    {
        //�ҵ���ͷ�ֶ�β��tab���ͻس����У��ȵ�Ϊ׼
        pcAnchor = strchr(pcHeader, '\t');
        pcAnchorTemp = strchr(pcHeader, '\r');
        if ( pcAnchor && pcAnchorTemp )
        {
            if ( pcAnchor < pcAnchorTemp )
            {
                bAnchor = '\t';
            }
            else
            {
                pcAnchor = pcAnchorTemp;
                bAnchor = '\r';
            }
        }
        else if ( pcAnchor && !pcAnchorTemp )
        {
            bAnchor = '\t';
        }
        else if ( !pcAnchor && pcAnchorTemp )
        {
            pcAnchor = pcAnchorTemp;
            bAnchor = '\r';
        }
        else
        {
            my_error("invalid head at %s\r\n", pcHeader);
            result = 0;
            break;
        }

        *pcAnchor = 0;

        //����ֶ��Ƿ����
        TXTBUF_ReplaceSpecialChar(pcHeader, acTempKey);
        for ( i = 0; i < iCount; i++ )
        {
            if ( !strcmp(acTempKey, astValueMap[i].acKeyName) )
            {
                break;
            }
        }
        if ( i >= iCount )
        {
            if ( pstCallback && Is_StringInList(pstCallback->ppcKeyInternalProcess, pcHeader) )
            {
                //�ѱ��ڲ�����
            }
            else if ( pstCallback && Is_StringInList(pstCallback->ppcKeyNotUsed, pcHeader) )
            {
                my_printf("Not Used Field: %s\r\n", pcHeader);
            }
            else if ( pstCallback && Is_StringInList(pstCallback->ppcKeyNotParsed, pcHeader) )
            {
                my_printf("Not Parsed Field: %s\r\n", pcHeader);
            }
            else
            {
                my_printf("Unknown Field: %s\r\n", pcHeader);
            }
        }

        *pcAnchor = bAnchor;
    } while ( (pcHeader = strchr(pcHeader, '\t')) && pcHeader < pcLineEnd && pcHeader++ );

    return result;
}

static int process_line_withkey(char *acTplBuf, char *acTxtBuf, void *pvLineInfo, int iLineLength, 
    char *acClass, int iKeyLen, ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback, int iLineNo)
{
    char acKey[256] = {0};
    char *pcHeader;
    char *pcLineStart;
    char *pcLineEnd;
    char *pcTxt;
    int result = 1;

    //�ҵ�txt�ļ�β
    pcTxt = acTxtBuf + strlen(acTxtBuf);

    //�ҵ�ģ���ļ��ĵ�һ�У�����ͷ
    pcHeader = acTplBuf;
    pcLineEnd = strchr(pcHeader, '\r');
    if ( !pcLineEnd )
    {
        my_error("%s fail at lineend\r\n", acClass);
        return 0;
    }

    //�ҵ�key���ڵ���һ��ģ��
    sprintf(acKey, "\n%s\t", acClass);
    pcLineStart = strstr(acTplBuf, acKey);
    if ( !pcLineStart )
    {
        sprintf(acKey, "\n%s\r", acClass);
        pcLineStart = strstr(acTplBuf, acKey);
#if 0
        //��ʱֻ��֧�ֶ�ͷ��key
        if ( !pcLineStart )
        {
            sprintf(acKey, "\t%s\t", acClass);
            pcLineStart = strstr(acTplBuf, acKey);
            if ( !pcLineStart )
            {
                sprintf(acKey, "\t%s\r", acClass);
                pcLineStart = strstr(acTplBuf, acKey);
            }
        }
#endif
    }

    if ( !pcLineStart )
    {
        int i = 0;

        //���û�и�key����˵����bin�ļ���ģ���ļ�����������ݣ�����һ�п�ģ���б��ں�������
        memset(m_acTempBuffer, 0, sizeof(m_acTempBuffer));
        pcLineStart = pcHeader;

        while ( pcLineStart != pcLineEnd )
        {
            if ( '\t' == *pcLineStart )
            {
                m_acTempBuffer[i] = *pcLineStart;
                i++;
            }

            pcLineStart++;
        }
        m_acTempBuffer[i] = '\r';
        i++;
        m_acTempBuffer[i] = '\n';
        pcLineStart = m_acTempBuffer;
    }
    else
    {
        //����'\r'
        while ( '\n' != *pcLineStart )
        {
            pcLineStart--;
        }
        pcLineStart++;
    }

    return process_line_x(pcHeader, pcLineEnd, pcLineStart, pcTxt, acClass, pvLineInfo, astValueMap, iCount, pstCallback, iLineNo);
}

static int process_line_withoutkey(char *acTplBuf, char *acTxtBuf, void *pvLineInfo, int iLineLength, int iLineNo, 
    ST_VALUE_MAP *astValueMap, int iCount, ST_CALLBACK *pstCallback,
    char *pcFilename, char **ppcIterator)
{
    char acClass[256] = {0};
    char *pcHeader;
    char *pcLineStart;
    char *pcLineEnd;
    char *pcTxt;
    char *pcAnchor;
    int result = 1;

    sprintf(acClass, "%d", iLineNo);

    //�ҵ�txt�ļ�β
    pcTxt = acTxtBuf + strlen(acTxtBuf);

    //�ҵ�ģ���ļ��ĵ�һ�У�����ͷ
    pcHeader = acTplBuf;
    pcLineEnd = strchr(pcHeader, '\r');
    if ( !pcLineEnd )
    {
        my_error("%s fail find lineend\r\n", acClass);
        return 0;
    }

    //�ҵ��кŶ�Ӧ����
    if ( NULL == *ppcIterator )
    {
        pcLineStart = acTplBuf;
    }
    else
    {
        pcLineStart = *ppcIterator;
    }

loop:
    pcAnchor = strstr(pcLineStart, "\r\n");
    if ( !pcAnchor || strlen("\r\n") == strlen(pcAnchor) )
    {
        int j = 0;

        //���û����һ���ˣ���˵����bin�ļ���ģ���ļ�����������ݣ�����һ�п�ģ���б��ں�������
        memset(m_acTempBuffer, 0, sizeof(m_acTempBuffer));
        pcLineStart = pcHeader;

        while ( pcLineStart != pcLineEnd )
        {
            if ( '\t' == *pcLineStart )
            {
                m_acTempBuffer[j] = *pcLineStart;
                j++;
            }

            pcLineStart++;
        }
        m_acTempBuffer[j] = '\r';
        j++;
        m_acTempBuffer[j] = '\n';
        pcLineStart = m_acTempBuffer;
    }
    else
    {
        pcLineStart = pcAnchor + 2;
        *ppcIterator = pcLineStart;
    }

    if ( pcLineStart == strstr(pcLineStart, "Expansion") )
    {
        goto loop;
    }

    return process_line_x(pcHeader, pcLineEnd, pcLineStart, pcTxt, acClass, pvLineInfo, astValueMap, iCount, pstCallback, iLineNo);
}

static int process_file_x(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback, char *pcBinSplitter)
{
    static char acTemplateFile[256] = {0};
    static char acBinFile[256] = {0};
    static char acTxtFile[256] = {0};
    static char acTplBuf[MAX_FILE_SIZE] = {0};
    static char acTxtBuf[MAX_FILE_SIZE] = {0};

    FILE *pfTplHandle = NULL;
    FILE *pfBinHandle = NULL;
    FILE *pfTxtHandle = NULL;

    ST_FILE_HEADER stFileHeader;
    unsigned int i, iSuccess, iFailed;
    char *pcKey;
    char *pcIterator = NULL;
    int result = 1;

    char *pcExpansion = NULL;
    char *pcAnchor = NULL;
    int iExpansionLine = 0;

    memset(acTemplateFile, 0, sizeof(acTemplateFile));
    memset(acBinFile, 0, sizeof(acBinFile));
    memset(acTxtFile, 0, sizeof(acTxtFile));
    memset(acTplBuf, 0, sizeof(acTplBuf));
    memset(acTxtBuf, 0, sizeof(acTxtBuf));
    memset(m_acGlobalBuffer, 0, sizeof(m_acGlobalBuffer));

    sprintf(acTemplateFile, "%s\\%s.txt", acTemplatePath, pcFilename);
    if ( pcBinSplitter )
    {
        sprintf(acBinFile, "%s%s%s.bin", acBinPath, pcBinSplitter, pcFilename);
    }
    else
    {
        sprintf(acBinFile, "%s%s.bin", acBinPath, pcFilename);
    }
    sprintf(acTxtFile, "%s\\%s.txt", acTxtPath, pcFilename);

    pfTplHandle = fopen(acTemplateFile, "rb");
    if ( NULL == pfTplHandle )
    {
        my_error("open template file fail\r\n");
        goto error;
    }

    pfBinHandle = fopen(acBinFile, "rb");
    if ( NULL == pfBinHandle )
    {
        my_error("open bin file fail\r\n");
        goto error;
    }

    pfTxtHandle = fopen(acTxtFile, "wb");
    if ( NULL == pfTxtHandle )
    {
        my_error("create txt file fail\r\n");
        goto error;
    }

    //�Ȱ�����ģ���ļ������ڴ�
    if ( 0 >= fread(acTplBuf, 1, sizeof(acTplBuf), pfTplHandle) )
    {
        my_error("read template file fail\r\n");
        goto error;
    }

    //�ҵ�Expansion�У�bin�ļ��ﲻ���ڣ�ֱ��д��txt
    pcExpansion = strstr(acTplBuf, "\r\nExpansion");
    if ( NULL != pcExpansion )
    {
        pcExpansion += strlen("\r\n");
        pcAnchor = acTplBuf;
        while ( (pcAnchor = strchr(pcAnchor, '\r')) )
        {
            if ( strncmp(pcAnchor + 2, "Expansion\t", strlen("Expansion\t")) )
            {
                iExpansionLine++;
                pcAnchor++;
            }
            else
            {
                break;
            }
        }

        pcAnchor = strchr(pcExpansion, '\r');
    }

    //��ȡģ���ļ��ı�ͷ������txt
    fseek(pfTplHandle, 0, SEEK_SET);
    fgets(acTxtBuf, sizeof(acTxtBuf), pfTplHandle);

    //�������Щ�ֶ�û�д���
    if ( 0 == check_missing(acTxtBuf, strchr(acTxtBuf, '\r'), pstValueMap, iValueCount, pcFilename, pstCallback) )
    {
        goto error;
    }

    //��ȡbin�ļ����ļ�ͷ
    if ( sizeof(stFileHeader) != fread(&stFileHeader, 1, sizeof(stFileHeader), pfBinHandle) )
    {
        my_error("read bin file head fail\r\n");
        goto error;
    }

    //֪ͨ��ģ�飬bin�ļ������������ڷ����ڴ�
    if ( pstCallback && pstCallback->pfnSetLines )
    {
        pstCallback->pfnSetLines(stFileHeader.iLines);
    }

    //��ѯbin�ļ���ÿһ������
    iSuccess = 0;
    iFailed = 0;
    for ( i = 0; i < stFileHeader.iLines; i++ )
    {
        if ( NULL != pcExpansion && NULL != pcAnchor && 0 < iExpansionLine && i == iExpansionLine )
        {
            iExpansionLine = 0;
            i--;

            *pcAnchor = 0;
            sprintf(&acTxtBuf[strlen(acTxtBuf)], "%s\r\n", pcExpansion);
            *pcAnchor = '\r';

            continue;
        }

        if ( 0 == i )
        {
            my_printf("%05d / %05d", i + 1, stFileHeader.iLines);
        }
        if ( 0 == (i % 10) )
        {
            my_printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
            my_printf("%05d / %05d", i + 1, stFileHeader.iLines);
        }

        //��bin�ļ����ζ�ȡһ������
        if ( iLineLength != fread(pvLineInfo, 1, iLineLength, pfBinHandle) )
        {
            my_error("read bin file line %d fail\r\n", i);
            break;
        }

        if ( pstCallback && pstCallback->pfnGetKey )
        {
            int iKeyLen = 0;

            //�����getkey�������ͱ�ʾ���ļ�����key�ģ�bin�ļ�����һ�����ݣ�ֱ����ģ���ļ����ÿһ�н���keyƥ�䣬ƥ���Ͼͺϲ�
            pcKey = pstCallback->pfnGetKey(pvLineInfo, acBinFile, &iKeyLen);
            String_Trim(pcKey);
            if ( 1 != process_line_withkey(acTplBuf, acTxtBuf, pvLineInfo, iLineLength, pcKey, iKeyLen, 
                pstValueMap, iValueCount, pstCallback, i) )
            {
                my_error("fail at line %s\r\n", pcKey);
                iFailed++;
            }
            else
            {
                iSuccess++;
            }
        }
        else
        {
            //û��getkey�������ͱ�ʾ���ļ�û��key��bin�ļ���ģ���ļ�ֻ�����кϲ�
            if ( 1 != process_line_withoutkey(acTplBuf, acTxtBuf, pvLineInfo, iLineLength, i, pstValueMap, iValueCount, 
                pstCallback, pcFilename, &pcIterator) )
            {
                my_error("process %s fail\r\n", pcFilename);
                iFailed++;
            }
            else
            {
                iSuccess++;
            }
        }
    }

    my_printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
    my_printf("%05d / %05d", i, stFileHeader.iLines);

    //д��txt�ļ�
    fwrite(acTxtBuf, 1, strlen(acTxtBuf), pfTxtHandle);

    if ( 0 < iFailed )
    {
        my_error("\r\nfinished������total %d������success %d������failed %d!\r\n", 
            stFileHeader.iLines, iSuccess, iFailed);
    }
    else
    {
        my_printf("\r\nfinished������total %d������success %d!\r\n", 
            stFileHeader.iLines, iSuccess);
    }

    goto out;

error:
    result = 0;

out:
    if ( NULL != pfTplHandle )
    {
        fclose(pfTplHandle);
        pfTplHandle = NULL;
    }
    if ( NULL != pfBinHandle )
    {
        fclose(pfBinHandle);
        pfBinHandle = NULL;
    }
    if ( NULL != pfTxtHandle )
    {
        fclose(pfTxtHandle);
        pfTxtHandle = NULL;
    }

    //֪ͨ��ģ���ͷ��ڴ�
#if 0
    //��ʱ�����ͷţ���Ϊ����ģ�黹��Ҫ��ѯ
    if ( pstCallback && pstCallback->pfnFinished )
    {
        pstCallback->pfnFinished();
    }
#endif

    return result;
}

int process_file(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback)
{
    return process_file_x(acTemplatePath, acBinPath, acTxtPath, pcFilename, pvLineInfo, 
        iLineLength, pstValueMap, iValueCount, pstCallback, "\\");
}

//bin�ļ���ֱ��ָ��
int process_file_special_bin(char *acTemplatePath, char *acBinPath, char *acTxtPath, char *pcFilename,
    void *pvLineInfo, int iLineLength, ST_VALUE_MAP *pstValueMap, int iValueCount,
    ST_CALLBACK *pstCallback)
{
    return process_file_x(acTemplatePath, acBinPath, acTxtPath, pcFilename, pvLineInfo, 
        iLineLength, pstValueMap, iValueCount, pstCallback, NULL);
}

