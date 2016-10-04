#include "global.h"

#define FILE_PREFIX "pettype"
#define NAME_PREFIX "pt"

/*
PetType.txt

pet type = name of the pet type, the "pettype" in skills.txt refers to this

idx = id number of the pet type

group = what group the pet belongs to, you can only have one pet type from each group i.e. Druid spiritwolf/fenris/grizzly

basemax = not absolutely sure. might be that if there's a 1 here the max number of this pet that you can have is always one. A 0 would mean the skills can change this.

warp = does the pet teleport with you, i.e. townportals, waypoints, cave entrances... 1=yes

ranged = if the pet uses ranged attacks, 1=yes

partysend = is the pet's icon displayed in the upper left corner, 1=yes

unsummon = can the pet be unsummoned with the "unsummon" skill, 1=yes

automap = is the pet displayed on the map, 1=yes

name = string file for the text under the pet's icon

drawhp = is the pet's life displayed under its icon, 1=yes

icontype = the type of the pet icon, I believe this determines in what order the icons are displayed in the upper left corner, 1= left 2= middle, 3= right

baseicon = the .dc6 file for the pet's icon, located in dataglobaluihireables

mclass1-4 = the alternative (of the same type) pets' hcldx numbers (ie golems)

micon1-4 = the alternative pet's .dc6 icons.

eol = end of line.

*/

/*
PetType.txt �������ٻ�ϵ����pet->����->�ٻ�ϵ��
A.pet type = �ٻ�ϵ������������golem-ʯħ��skeleton-���ã���skills.txt�еġ�pettype���вο���ֵ��
B.idx = �ٻ�ϵ������ID
C.group = �ٻ�ϵ�����ĸ��飬ÿһ��������ֻ����һ�����͵��ٻ�ϵ����druid��spiritwolf/fenris/grizzly����ʵ�ϣ�����pettype.txt��Ҳ�ͽ���һ�顣
D.basemax = �в���ȷ�������������1=һ��ӵ�еĸ��ٻ��������ĿΪ1����0=��ͨ�����ܸı䡣
E.warp = �ٻ�ϵ�Ƿ�������һ���͡����·�㣬��Ѩ��ڣ�townportals��1=���ԣ�0=��
F.range = ���ٻ�ϵ�Ƿ�ʹ�÷�Χ������1=�ǣ�0=��
G.partysend = �ٻ�ϵͼ���Ƿ������Ͻ���ʾ��1=�ǣ�0=��
H.unsummon = ���ٻ�ϵ�Ƿ���ͨ�����ܡ�unsummon����ɢ��������ٻ���1=���ԣ�0=��
I,automap = ���ٻ�ϵ�Ƿ���ʾ�ڵ�ͼ�ϡ�1=�ǣ�0=��
J.name = ��ʾ���ٻ�ϵͼ���·����ַ����ļ���
K.drawhp = �ٻ�ϵ������ֵ�Ƿ���ͼ���·���ʾ��1=�ǣ�0=��
L.icontype = ���ٻ�ϵ��ͼ�����͡����ܾ�����ͼ������Ļ���Ϸ�������˳��1=��ߣ�2=�м䣬3=�ұߡ�
M.baseicon = ���ٻ�ϵͼ���ʹ�õ�dc6�ļ���λ�ڡ�data\global\ui\hireables\ ����
N/P/R/T.mclass1-4 = ��ѡ��ģ�ͬ���ͣ��ٻ�ϵ��hcldx���֣���ʯħ��
O/Q/S/U.micon1-4 = ��ѡ����ٻ�ϵͼ�꣬dc6��ʽ��
v.eol = �н�������0��
*/

typedef struct
{
    unsigned int vidx;

#if 1
    unsigned char vCombinedBit;
#else
    unsigned char iPadding1 : 2;
    unsigned char vdrawhp : 1;
    unsigned char vautomap : 1;

    unsigned char vunsummon : 1;
    unsigned char vpartysend : 1;
    unsigned char vrange : 1;
    unsigned char vwarp : 1;
#endif

    unsigned char iPadding1[3];

    unsigned short vgroup;
    unsigned short vbasemax;

    unsigned short vname;   //string
    unsigned char vicontype;
    unsigned char vbaseicon[32];
    unsigned char vmicon1[32];
    unsigned char vmicon2[32];
    unsigned char vmicon3[32];
    unsigned char vmicon4[32];
    unsigned char iPadding43;

    unsigned short iPadding44;
    unsigned short vmclass1;

    unsigned short vmclass2;
    unsigned short vmclass3;

    unsigned short vmclass4;
    unsigned short iPadding46;

    unsigned int iPadding47;
    unsigned int iPadding48;
    unsigned int iPadding49;

    unsigned int iPadding50;
    unsigned int iPadding51;
    unsigned int iPadding52;
    unsigned int iPadding53;
    unsigned int iPadding54;
    unsigned int iPadding55;
} ST_LINE_INFO;

typedef struct
{
    unsigned char vpetmysptype[32];
} ST_PETTYPE;

static char *m_apcInternalProcess[] =
{
    "pet type",
    "eol",
    NULL,
};

static unsigned int m_iPetTypeCount = 0;
static ST_PETTYPE *m_astPetTypes = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astPetTypes, ST_PETTYPE);

char *Pettype_GetPetType(unsigned int id)
{
    if ( id >= m_iPetTypeCount )
    {
        return NULL;
    }

    return m_astPetTypes[id].vpetmysptype;
}

static int PetType_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "pet type") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vidx);
        }

        strncpy(m_astPetTypes[pstLineInfo->vidx].vpetmysptype, acOutput, sizeof(m_astPetTypes[pstLineInfo->vidx].vpetmysptype));
        String_Trim(m_astPetTypes[pstLineInfo->vidx].vpetmysptype);
        m_iPetTypeCount++;

        return 1;
    }
    else if ( !strcmp(acKey, "eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int PetType_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "pet type") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, pstLineInfo->vidx);
        }

        return 1;
    }

    return 0;
}

static int PetType_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp("name", acKey) )
    {
        pcResult = String_FindString(pstLineInfo->vname, "dummy");
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

static char *PetType_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    sprintf(pcKey, "%u", pstLineInfo->vidx);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

static int PetType_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "drawhp") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "automap") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "unsummon") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "partysend") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "range") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "warp") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBit & 1) != 0);
        result = 1;
    }

    return result;
}

int process_pettype(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, idx, UINT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, drawhp, CombinedBit, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, automap, CombinedBit, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, unsummon, CombinedBit, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, partysend, CombinedBit, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, range, CombinedBit, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, warp, CombinedBit, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, basemax, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, icontype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, baseicon, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, micon4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mclass4, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_iPetTypeCount = 0;

            m_stCallback.pfnFieldProc = PetType_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            //m_stCallback.pfnGetKey = PetType_GetKey;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(string, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = PetType_FieldProc;
            //m_stCallback.pfnGetKey = PetType_GetKey;
            m_stCallback.pfnBitProc = PetType_BitProc;
            m_stCallback.pfnConvertValue = PetType_ConvertValue;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

