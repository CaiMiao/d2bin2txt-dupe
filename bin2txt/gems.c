#include "global.h"

#define FILE_PREFIX "gems"

/*
Title 	Gems.txt
Description 	by Nefarius
Sent by 	
name: This is a reference field, so that you know what gem or tune this line refers to.

letter: This field controls what string the game will use for the rune-letter displayed when the rune has been socketed into an item.

transform: This field controls what color the item the gem or rune has been socketed into is going to shift to, a list of colors can be found in Colors.txt (count starting from 0).

code: What item will these modifiers be appended to, this is what actually appends the stats to a gem, prior to 1.07 this was hardcoded and thus it was impossible to add new gems without editing the dlls.

nummods: This is another reference field, to make it easier to see how many different modifiers the gem or rune will have.

weaponMod1 to weaponMod3: An ID pointer to a property in Properties.txt, these columns control each of the three modifiers a gem will give to items using GemApplyType 0 (by default this is used by weapons).

weaponMod1Param to weaponMod3Param: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them. WARNING: You should not use properties that 
require parameters in this text file, since the parameters will stack when more then one gem of this type is socketed into the item, producing many undesired effects.

weaponMod1Min to weaponMod3Min: Minimum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

weaponMod1Max to weaponMod3Max: Maximum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

helmMod1 to helmMod3: An ID pointer to a property in Properties.txt, these columns control each of the three modifiers a gem will give to items using GemApplyType 1 (by default this is used by body armors and helmets).

helmMod1Param to helmMod3Param: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them. WARNING: You should not use properties that 
require parameters in this text file, since the parameters will stack when more then one gem of this type is socketed into the item, producing many undesired effects.

helmMod1Min to helmMod3Min: Minimum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

helmMod1Max to helmMod3Max: Maximum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

shieldMod1 to shieldMod3: An ID pointer to a property in Properties.txt, these columns control each of the three modifiers a gem will give to items using GemApplyType 2 (by default this is used by shields).

shieldMod1Param to shieldMod3Param: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them. WARNING: You should not use properties that 
require parameters in this text file, since the parameters will stack when more then one gem of this type is socketed into the item, producing many undesired effects.

shieldMod1Min to shieldMod3Min: Minimum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

shieldMod1Max to shieldMod3Max: Maximum value to assign to the associated property. WARNING: Gem stats are not saved, thus having minimum and maximum assign different values will cause the gem stats to re-randomize every frame, until the gem is socketed 
into an item.

*/

/*
�ļ���������
Gem(s)����ʯ��������ָ���鱦���������Ƕ�
���Դ��ļ������������鱦��������Ƕ�Ҳ����Ƕ�뵽��ͬ����װ�����в�ͬ���Ե���Ƕ��ĵط���
���ļ��е�ÿһ�б�ʾһ�ֱ�ʯ����ġ�

name������Ƕ������֡�

letter����������

transform��������Ƕ�ﱻ����ĳװ��ʱ����װ����ɫ�ĸı䡣��Colors.txt������

code������Ƕ��Ĵ��롣

nummods��û��������ʲô��˼����ָ�̡�

WeaponMod1Code�����������ϵ�����1��

WeaponMod1Param�����������ϵ�����1�Ĳ�����

WeaponMod1Min�����������ϵ�����1����Сֵ������

WeaponMod1Max�����������ϵ�����1�����ֵ������

WeaponMod2-3XXX��ͬ�����������ϵ����ԣ�����ο�����4�С�

HelmMod1-3XXX������ͷ���ϵ����ԣ�����ο�ǰ��Ľ��͡�

ShieldMod1-3XXX�����ڶ����ϵ����ԣ�����ο�ǰ��Ľ��͡�

*eol����β��־������Ϊ0��

����˵�����·���ͷ����Զ��һ�������ԣ������ڴ˲�û�е���˵����
*/

typedef struct
{
    unsigned char vname[32];
    unsigned char vletter[8];

    unsigned int vcode;

    unsigned short iPadding11;
    unsigned char vnummods;
    unsigned char vtransform;

    unsigned int vweaponMod1Code;   //
    unsigned int vweaponMod1Param;
    int vweaponMod1Min;
    int vweaponMod1Max;

    unsigned int vweaponMod2Code;   //
    unsigned int vweaponMod2Param;
    int vweaponMod2Min;
    int vweaponMod2Max;

    unsigned int vweaponMod3Code;   //
    unsigned int vweaponMod3Param;
    int vweaponMod3Min;
    int vweaponMod3Max;

    unsigned int vhelmMod1Code; //
    unsigned int vhelmMod1Param;
    int vhelmMod1Min;
    int vhelmMod1Max;

    unsigned int vhelmMod2Code; //
    unsigned int vhelmMod2Param;
    int vhelmMod2Min;
    int vhelmMod2Max;

    unsigned int vhelmMod3Code; //
    unsigned int vhelmMod3Param;
    int vhelmMod3Min;
    int vhelmMod3Max;

    unsigned int vshieldMod1Code; //
    unsigned int vshieldMod1Param;
    int vshieldMod1Min;
    int vshieldMod1Max;

    unsigned int vshieldMod2Code; //
    unsigned int vshieldMod2Param;
    int vshieldMod2Min;
    int vshieldMod2Max;

    unsigned int vshieldMod3Code; //
    unsigned int vshieldMod3Param;
    int vshieldMod3Min;
    int vshieldMod3Max;
} ST_LINE_INFO;

static int Gems_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "code") )
    {
        pcResult = Misc_GetItemUniqueCode(pstLineInfo->vcode);
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
    else if ( !strcmp(acKey, "weaponMod1Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vweaponMod1Code);
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
    else if ( !strcmp(acKey, "weaponMod2Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vweaponMod2Code);
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
    else if ( !strcmp(acKey, "weaponMod3Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vweaponMod3Code);
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
    else if ( !strcmp(acKey, "helmMod1Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vhelmMod1Code);
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
    else if ( !strcmp(acKey, "helmMod2Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vhelmMod2Code);
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
    else if ( !strcmp(acKey, "helmMod3Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vhelmMod3Code);
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
    else if ( !strcmp(acKey, "shieldMod1Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vshieldMod1Code);
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
    else if ( !strcmp(acKey, "shieldMod2Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vshieldMod2Code);
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
    else if ( !strcmp(acKey, "shieldMod3Code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vshieldMod3Code);
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

int process_gems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, name, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, letter, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, nummods, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transform, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Code, UINT);   //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Code, UINT);   //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Code, UINT);   //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, weaponMod3Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, helmMod3Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod1Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod2Max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Code, UINT); //
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, shieldMod3Max, INT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Gems_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

