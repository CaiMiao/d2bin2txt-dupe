#include "global.h"

#define FILE_PREFIX "itemtypes"

/*
Title 	ItemTypes.txt File Guide (1.2)
Description 	by Nefarius
Sent by 	

ItemTypes.txt File Guide
By Nefarius (1.2 added further notes regarding socket caps and staffmodes brought to my attention by Myhrginoc a (long) while ago)








ItemType �C A comment field that contains the ��internal name�� of this iType, you can basically enter anything you wish here, but since you can add as many comment columns as you wish, there is no reason to use it for another purpose icon_razz.gif.

Code �C The ID pointer of this ItemType, this pointer is used in many txt files (armor.txt, cubemain.txt, misc.txt, skills.txt, treasureclassex.txt, weapons.txt), never use the same ID pointer twice, the game will only use the first instance and ignore 
all other occurrences. ID pointers are case sensitive, 3-4 chars long and can contain numbers, letters and symbols.

Equiv1-2 �C This is used to define the parent iType, note that an iType can have multiple parents (as will be shown in the cladogram �C link below), the only thing you must avoid at all cost is creating infinite loops. I haven't ever tested what happens 
when you create an iType loop, but infinite loops are something you should always avoid.

Fig. 1 - ItemType Diagram by Paul Siramy


Repair �C Boolean, 1=Merchants can repair this item type, 0=Merchants cannot repair this iType (note, this also refers to charges being rechargeable).

Body �C Boolean, 1=The character can wear this iType, 0=This iType can only be carried in the inventory, cube or stash (and belt if it is set as ��beltable�� in the other item related txt files)

BodyLoc1-2 �C If you have set the previous column to 1, you need to specify the inventory slots in which the item has to be equipped. (the codes used by this field are read from BodyLocs.txt)

Shoots �C This column specifies which type of quiver (��ammo&rdquo this iType (in case it is a weapon) requires in order to shoot (you use the ID pointer of the quiver iType here).

Caution: The place it checks which missile to pick (either arrow, bolt, explosive arrow or magic arrow) is buried deep within D2Common.dll, the section can be modified, there is an extensive post discussing this in Code Editing. - Thanks go to Kingpin 
for spotting a silly little mistake in here.

Quiver �C The equivalent to the previous column, in here you specify which weapon this quiver is linked to. Make sure the two columns match. (this also uses the ID pointer of course).

Throwable �C Can this iType be thrown (determines whenever it uses the quantity and throwing damage columns in Weapons.txt for example).

Reload �C Can the this item be re-stacked via drag and drop. 1=Yes, 0=No.

ReEquip �C If the ammo runs out, the game will automatically pick the next item of the same iType to be equipped in it's place. 1=Yes, 0=No. (more clearly, when you use up all the arrows in a quiver, the next quiver, if available, will be equipped in 
its place).

AutoStack �C Are identical stacks automatically combined when you pick the up? 1=Yes, 0=No. (for example, which you pick up throwing potions or normal javelins, they are automatically combined with those you already have)

Magic �C Is this iType always Magic? 1=Yes, 0=No.

Rare �C Can this iType spawn as a rare item? 1=Yes, 0=No. Note: If you want an item that spawns only as magic or rare, you need to set the previous column to 1 as well.

Normal �C Is this iType always Normal? 1=Yes, 0=No.

Charm �C Does this iType function as a charm? 1=Yes, 0=No. Note: This effect is hardcoded, if you need a new charm type, you must use the char iType in one of the equivs.

Gem �C Can this iType be inserted into sockets? 1=Yes, 0=No (Link your item to the sock iType instead to achieve this).

Beltable �C Can this iType be placed in your characters belt slots? 1=Yes, 0=No. (This requires further tweaking in other txt files).

MaxSock1, MaxSock25, MaxSock40 �C Maximum sockets for iLvl 1-25, 26-40 and 40+. The range is hardcoded but the location is known, so you can alter around the range to your liking. On normal, items dropped from monsters are limited to 3, on nightmare to 
4 and on hell to 6 sockets, irregardless of this columns content.

TreasureClass �C Can this iType ID Pointer be used as an auto TC in TreasureClassEx.txt. 1=Yes, 0=No. *Such as armo3-99 and weap3-99 etc.

Rarity �C Dunno what it does, may have to do with the chance that an armor or weapon rack will pick items of this iType. If it works like other rarity fields, the chance is rarity / total_rarity * 100.

StaffMods �C Contains the class code for the character class that should get +skills from this iType (such as wands that can spawn with +Necromancer skills). Note, this only works if the item is not low quality, set or unique. Note, that this uses the 
vanilla min/max skill IDs for each class as the range for the skill pool, so if you add new class skills to the end of the file, you should use automagic.txt instead

CostFormula �C Does the game generate the sell/repair/buy prices of this iType based on its modifiers or does it use only the cost specific in the respective item txt files. 2=Organ (probably higher price based on unit that dropped the organ), 1=Yes, 0=
No. Note: Only applies to items that are not unique or set, for those the price is solely controlled by the base item file and by the bonus to price given in SetItems and UniqueItems txt files. The exact functionality remains unknown, as for example 
charms, have this disabled.

Class �C Contains the class code for the class that should be able to use this iType (for class specific items).

VarInvGfx �C This column contains the sum of randomly picked inventory graphics this iType can have.

InvGfx1-6 �C This column contains the file names of the inventory graphics that are randomly picked for this iType, so if you use columns 1-3, you will set VarInvGfx to 3 (duh).

StorePage �C The page code for the page a vendor should place this iType in when sold, if you enable the magic tab in D2Client.dll, you need to use the proper code here to put items in that tab. Right now the ones used are weap = weapons1 and 2, armo = 
armor and misc = miscellaneous.

*eol �C Always needs to be filled with a value (doesn't have to be 0) in order to prevent M$ Excel and other ��re-format happy�� spreadsheets from messing up the table bounds.

*/

typedef struct
{
    //ItemType��bin�ļ���û������
    unsigned char vCode[4]; //���ʹ��룬����������ڸ�txt�ļ��ж���Ʒ���ͽ���������Ӧ��ʹ�ô��е�ֵ��

    //Equiv1��2����Ҫ���ڶ��ִ�����Ϊ����������������ֶ�
    unsigned short vEquiv1;
    unsigned short vEquiv2;

    unsigned char vRepair;  //�Ƿ�ɱ�����0�������ԣ�1������ԡ�ֻ�д�����е�������Ʒ��������ʱ����������������
    unsigned char vBody;    //�Ƿ��Ǵ������ϵ�װ����0�����ǣ�1�����ǡ�
    unsigned char vBodyLoc1;    //װ����λ��1�������¼���λ�ã�rarm���֡�larm���֡�tors���ɡ�rrin�ҽ�ָ��lrin���ָ��neck���ӡ�feet�š�belt������headͷ����glov���ס�
    unsigned char vBodyLoc2;    //װ����λ��2�������¼���λ�ã�rarm���֡�larm���֡�tors���ɡ�rrin�ҽ�ָ��lrin���ָ��neck���ӡ�feet�š�belt������headͷ����glov���ס�

    //Shoots��Quiver����Ҫ���ڶ��ִ�����Ϊ����������������ֶ�
    unsigned short vShoots;
    unsigned short vQuiver;

    unsigned char vThrowable;   //�Ƿ�ΪͶ������Ʒ��0��ʾ���ǣ�1��ʾ�ǡ��罣����Ϊ0����ǹ����Ϊ1��
    unsigned char vReload;  //�Ƿ�����Զ����䡣0��ʾ�����ԣ�1��ʾ���ԡ����ʸ����һͲ����Զ����µ�һͲ�����������У���������Ϊ����Ϊ1��
    unsigned char vReEquip; //����ʹ�������Ʒ�Ƿ���ʧ��0��ʾ�ǣ�1��ʾ���ǡ����ǹ����Ϊ1����ô��ʹ�����ù��˱�ǹҲ���ڡ�����ʸ����Ϊ0������һ�����������˴˼�������ʧ�ˡ�
    unsigned char vAutoStack;   //�Ƿ��Զ����ӡ�0�����ǣ�1�����ǡ�������ԭ����������һ������������һ���µļ���֮���ɴ��о����Ƿ��Զ���ԭ�еļ����ϲ���

    unsigned char vMagic;   //�Ƿ�һ����ħ����Ʒ�������ϼ��𣩡�0�����ǣ�1�����ǡ����ָ����о�Ϊ1����ʾ�����а�ɫ�Ľ�ָ��
    unsigned char vRare;    //�Ƿ�����ϡ�м������Ʒ��0�����ܣ�1�����ܡ��绤�������Ϊ0����ʾ�����ܳ���ϡ�У����𣩵Ļ������
    unsigned char vNormal;  //�Ƿ�ֻ������ͨ����ɫ����Ʒ��0�����ǣ�1�����ǡ���سǾ������Ϊ1����������Ϊ0��
    unsigned char vCharm;   //�Ƿ��ǻ������0�����ǣ�1�����ǡ�

    unsigned char vGem; //�Ƿ��Ǳ�ʯ��0�����ǣ�1�����ǡ�
    unsigned char vBeltable;    //�Ƿ��ܷ��������ռ��С�0�����ǣ�1�����ǡ�
    unsigned char vMaxSock1;    //��Ʒ�ȼ���1-23֮��ʱ����������
    unsigned char vMaxSock25;   //��Ʒ�ȼ���25-39֮��ʱ����������

    unsigned char vMaxSock40;   //��Ʒ�ȼ�����40��ʱ����������
    unsigned char vTreasureClass;   //�Ʊ����ͣ�TC�����Ƿ��ܵ�����Ϊһ���Ʊ����ͣ�TC����ʵ����ֻ��5�ֿ��ԡ���������ս������װ�ס���������ѷ����
    unsigned char vRarity;  //ϡ�жȡ���ͬһTC�г��ֵĸ��ʣ�ֵԽ�����ĸ���Խ����ο���Ʒ����ԭ��
    unsigned char vStaffMods;   //�������Դ��ļӵ�һ�������ԡ����編ʦ���Ȼ�ӷ�ʦ�ļ��ܣ�������Ϊ������sor���ֵ������playerclass.txt

    unsigned char vCostFormula; //��Ʒ�۸���㷽������ʵ�Ҳ�̫�������еĺ��壩��
    unsigned char vClass;   //ְҵ���ơ��編������е�ֵΪsor����ʾֻ�з�ʦ���÷��򡣹���playerclass.txt
    unsigned char vStorePage;   //������¾�����Ʒ����Ϣ�洢���ĸ��ļ������˵����������ĸ����ࡣֻ��3�����࣬����armo������weap������misc��
    unsigned char vVarInvGfx;   //����Ʒ���п��ܳ��ֵ�������ࡣ���ָ�����ֵΪ5������ָ����5����ۡ�

    unsigned char vInvGfx1[32];   //���ͼƬָ�롣
    unsigned char vInvGfx2[32];   //���ͼƬָ�롣
    unsigned char vInvGfx3[32];   //���ͼƬָ�롣
    unsigned char vInvGfx4[32];   //���ͼƬָ�롣
    unsigned char vInvGfx5[32];   //���ͼƬָ�롣
    unsigned char vInvGfx6[32];   //���ͼƬָ�롣
} ST_LINE_INFO;

typedef struct
{
    char vCode[5];
} ST_ITEM_TYPES;

static char *m_apcInternalProcess[] =
{
    "ItemType",
    "*eol",
    NULL,
};

static unsigned int m_iItemTypesCount = 0;
static ST_ITEM_TYPES *m_astItemTypes = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astItemTypes, ST_ITEM_TYPES);

char *ItemTypes_GetItemCode(unsigned int id)
{
    if ( id >= m_iItemTypesCount )
    {
        return NULL;
    }

    return m_astItemTypes[id].vCode;
}

static int ItemTypes_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "BodyLoc1") )
    {
        pcResult = BodyLocs_GetLocStr(pstLineInfo->vBodyLoc1);
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
    else if ( !strcmp(acKey, "BodyLoc2") )
    {
        pcResult = BodyLocs_GetLocStr(pstLineInfo->vBodyLoc2);
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
    else if ( !strcmp(acKey, "StaffMods") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vStaffMods);
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
    else if ( !strcmp(acKey, "Class") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vClass);
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
    else if ( !strcmp(acKey, "StorePage") )
    {
        pcResult = StorePage_GetCode(pstLineInfo->vStorePage);
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
    else if ( !strcmp(acKey, "Equiv1") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vEquiv1);
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
    else if ( !strcmp(acKey, "Equiv2") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vEquiv2);
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
    else if ( !strcmp(acKey, "Shoots") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vShoots);
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
    else if ( !strcmp(acKey, "Quiver") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vQuiver);
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

static int ItemTypes_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "ItemType") )
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

        strncpy(m_astItemTypes[m_iItemTypesCount].vCode, pstLineInfo->vCode, sizeof(pstLineInfo->vCode));
        String_Trim(m_astItemTypes[m_iItemTypesCount].vCode);
        m_iItemTypesCount++;
        return 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int ItemTypes_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "ItemType") )
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
        return 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static char *ItemTypes_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vCode);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

int process_itemtypes(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Code, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv1, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Equiv2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Repair, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Body, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, BodyLoc2, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Shoots, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Quiver, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Throwable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Reload, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ReEquip, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AutoStack, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Magic, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Normal, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Charm, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Gem, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Beltable, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock1, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock25, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, MaxSock40, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TreasureClass, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Rarity, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StaffMods, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, CostFormula, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Class, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, StorePage, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, VarInvGfx, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx1, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx2, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx3, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx4, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx5, STRING);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, InvGfx6, STRING);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_iItemTypesCount = 0;

            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnFieldProc = ItemTypes_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(bodylocs, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(storepage, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            //m_stCallback.pfnGetKey = ItemTypes_GetKey;
            m_stCallback.pfnConvertValue = ItemTypes_ConvertValue;
            m_stCallback.pfnFieldProc = ItemTypes_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

