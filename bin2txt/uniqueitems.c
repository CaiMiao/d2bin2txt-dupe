#include "global.h"

#define FILE_PREFIX "uniqueitems"

/*
Title 	UniqueItems.txt
Description 	by Nefarius (written from scratch)
Sent by 	
Index: The ID pointer that is referenced by the game in TreasureClassEx.txt and CubeMain.txt, this also controls the string that will be used to display the item's name in-game.

Version: What game version was this unique item added in, 0 referes to real classic Diablo II (1.00-1.06), 1 refers to new classic Diablo II (1.07-1.11) and 100 refers to the Expansion Set, items with 100 will be unable to drop in Classic Diablo II.

Ladder: Is this item available only in Ladder and Single Player games? (boolean, 0 = available in all game types, 1 = available only in single player and ladder gaes).

Rarity: Chance to pick this unique item if more then one unique item of the same base item exist, this uses the common rarity/total_rarity formula, so if you have two unique rings, one with a rarity of 100 the other with a rarity of 1, then the first 
will drop 100/101 percent of the time (99%) and the other will drop 1/101 percent of the time (1%), rarity can be anything between 1 and 255 (rarity of less then 1 will be set to 1 by the code).

NoLimit: Can this item drop more then once per game? (boolean, 0 = can drop only once per game, 1 = can drop more then once per game). Basically when the game drops a unique item it sets a check mark in a table it holds in memory of what unique items 
were dropped, when, should you be lucky enough to get the same item again, it will check whenever this item has been dropped already, and if NoLimit is false, it will drop a rare item with enhanced durability instead.

Lvl: The quality level of this unique item, monsters, cube recipes, vendors, objects and the like most be at least this level or higher to be able to drop this item, otherwise they would drop a rare item with enhanced durability.

Lvl Req: The character level required to use this unique item.

Code: The code of the base form of this unique item, this is an ID pointer from Weapons.txt, Armor.txt or Misc.txt.

Carry1: Is the player only permitted to hold a single copy of this item at a time? (in reality this just prevents the player from picking up the item when it is dropped on the floor and it prevents the player from putting this item in the trading window)
. (boolean, 0 = allow the player to hold as many of this item as he wants, 1 = allow the player to hold a single copy only).

Cost Mult: The base item's price is multiplied by this value when sold, repaired or bought from a vendor.

Cost Add: After the price has been multiplied, this amount of gold is added to the price on top.

ChrTransform: Palette shift to apply to the the DCC component-file and the DC6 flippy-file (whenever or not the color shift will apply is determined by Weapons.txt, Armor.txt or Misc.txt). This is an ID pointer from Colors.txt.

InvTransform: Palette shift to apply to the the DC6 inventory-file (whenever or not the color shift will apply is determined by Weapons.txt, Armor.txt or Misc.txt). This is an ID pointer from Colors.txt.

FlippyFile: Overrides the flippyfile specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains the file name of the DC6 flippy animation.

InvFile: Overrides the invfile and uniqueinvfile specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains the file name of the DC6 inventory graphic.

DropSound: Overrides the dropsound (the sound played when the item hits the ground) specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains an ID pointer from Sounds.txt.

DropSfxFrame: How many frames after the flippy animation starts playing will the associated drop sound start to play. This overrides the values in Weapons.txt, Armor.txt or Misc.txt.

UseSound: Overrides the usesound (the sound played when the item is consumed by the player) specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains an ID pointer from Sounds.txt.

Prop1-12: An ID pointer of a property from Properties.txt, these columns control each of the 12 different modifiers a unique item can grant you at most. (In a-lay-mens-terms: "the stat that can spawn on the unique item.")

Par1-12: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them, these fields support calculations.

Min1-12: Minimum value to assign to the associated property. (In a-lay-mans-term's: "minimum value of the stat.")

Max1-12: Maximum value to assign to the associated property. (In a-lay-man's-terms: "maximum value of the stat.")

*EoL, *Type and *Uber are of course not loaded.

*/

/*
Index����Ʒ���ƣ�ͨ��Ϊ�̶����ַ��ؼ��֣�

Version����Ʒ�����ֵİ汾��0����ԭ�棬1����ԭ�油����100��������Ƭ��

Enabled����Ʒ�Ƿ���������䡱���ԣ�0����Ӳ����䣬1������䣻

Ladder����Ʒ�Ƿ�����ڡ����ݡ�ģʽ�£�

Rarity����Ʒ��ϡ�г̶ȣ�

Nolimit�����ò�����

Lvl���������Ʒ����ļ���

Lvl req��ʹ�ø���Ʒ��ɫ�ĵȼ���

Code����Ʒ���룬ͨ�������ڡ�Weapon.txt��armor.txt��misc.txt�������ļ��У�

Type����Ʒ����˵���������ο�����

Uber���Ƿ�ΪUber��Ʒ����ĿǰΪֹ�����а汾��δʹ�ã���

Carry1���Ƿ�ֻ����Я��һ�ױ���Ʒ��1�����ǡ���0�����񡱣���

Cost mult����Ʒ�۸���������

Cost add����Ʒ�۸���������

Chrtransform����ɫʹ�ø���Ʒ�����ɫ��

Invtransform����Ʒ���и���Ʒ����ɫ��

Flippy file����Ʒ���������ѡ�õ�ͼ��

Invfile������Ʒ����Ʒ���������õ�ͼ��

Dropsound����Ʒ����ʱ�����õ�������

Dropsfxframe����Ʒ����ʱ�����ӳ�ʱ�䣻

Usesound����Ʒװ��ʱ��ʹ�õ�������

Prop1������Ʒ�ĵ�һ��ħ�����ԣ�

Par1����һ��ħ�����Բ������磺�䶳ʱ������䶳���ˣ�

Min1��ȷ��ħ�����Ե���Сֵ��

Max1��ȷ��ħ�����Ե����ֵ��

˵����֮�����硰Prop2��Par2��Min2��Max2�����ȵȾ���������4����ͼ��ɡ�


Eol���ļ�������־��


*/

/*
�ļ���������
Unique��Ωһ�ģ���������İ������
Item(s)�����ߣ���װ����
���Դ��ļ���¼����Ϸ�����а���װ����
�ļ��е�ÿһ�д���һ������װ��


�ظ�

    2¥
    2011-09-04 00:03

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�



�ظ�

    3¥
    2011-09-04 00:03

    �ٱ� |

    zqtjingzi
    С����
    12

Index����Ʒ���ƣ�Ҳ�Ǵ˰�����Ʒ����Ϸ�еĴ��루����Ʒ���Ʒ���ļ�ֵ��ϳɹ�ʽ�еĴ��룩�����ǵ�֮ʯ�ڴ��е�ֵ����The Stone of Jordan���������Լ��¼ӵ��з��򲻽����޸Ĵ��С�


�ظ�

    4¥
    2011-09-04 00:04

    �ٱ� |

    zqtjingzi
    С����
    12

Version����Ʒ���ܳ��ֵ���Ͱ汾��0����ԭ�棬1����ԭ�油����100��������Ƭ�����ǵ�֮ʯ�ڴ��е�ֵΪ0��������ڴ��е�ֵΪ100�����������ԭ����Ҳ������Ƭ�İ���װ������������ͻ���С�����ͽ����Ǵ��е�ֵ��Ϊ0���ɡ�

Enabled����Ʒ�Ƿ������Ϸ�г��֣�0�����ܳ��֣�1������Գ��֡����ǵ�֮ʯ�ڴ��е�ֵΪ1����������ָ�ڴ��е�ֵΪ0��������Ӧ��û�м��������ָ�������Ķ����ļ��Ĺ����У���ᷢ����һЩ�д��е�ֵΪ0
��Ҳ����˵��Щд�õİ���װ������������Ϸ�г��֣�����Խ����Ǹ�Ϊ1Ȼ���ٵ���Ϸ������һ�¡���������������¼ӵ�װ����һ��Ҫ��������Ϊ1��

Ladder����Ʒ�Ƿ�����ڡ����ݡ�ģʽ�¡�������Ϸ����û���������Բ��ܴ���Ӱ�졣

Rarity����Ʒ��ϡ�г̶ȡ������Դ�������ͬ���͵ĵײ��д˰���װ������ĸ��ʴ�С�����ǵ�֮ʯ����Ϊ1�����ø��Ľ�ָ����Ϊ15����������Ʒ�ȼ��㹻��������ǵ�֮ʯ�ĵ������ø���ʮ���֮һ��

Nolimit�����ò�����


�ظ�

    5¥
    2011-09-04 00:04

    �ٱ� |

    zqtjingzi
    С����
    12

Lvl���������Ʒ����ļ��𡣴����Եĺ���ɲο���Ʒ����ԭ��һ������ž���˵ֻ�е�����ȼ��������е�ֵ��ʱ��ſ��ܵ���˰���װ�����������������Ƥ������࣬������Ĵ��м�С��86���¼��ɡ�

Lvl req��ʹ�ô�װ������Ľ�ɫ�ĵȼ���������ö�����˰ɣ�����������Ϊ67��

Code���˰���װ���ײĵĴ��룬ͨ�������ڡ�Weapon.txt��armor.txt��misc.txt�������ļ��С����ǵ�֮ʯ���е�ֵΪrin�����ǽ�ָ�Ĵ��롣���еײĵĴ������http://tieba.baidu.com/f?kz=1193058424��

Type���˰���װ���ײĵ�˵�������ǵ�֮ʯ���е�ֵΪring������ָ��Ӣ�ĵ��ʡ�

Uber���Ƿ�ΪUber��Ʒ��δʹ�����ԡ�

Carry1���Ƿ�ֻ����Я��һ������Ʒ��1�����ǡ���0�����񡱡������С�����е�ֵΪ1��

Cost mult����Ʒ����NPCʱ�ļ۸���������

Cost add����Ʒ����NPCʱ�ļ۸���������


�ظ�

    6¥
    2011-09-04 00:05

    �ٱ� |

    zqtjingzi
    С����
    12

Chrtransform����ɫװ������Ʒ����������������ʾ����ɫ�������˼״���Ϊdblu������ɫ����ʥ����ʿ��������С���˼ף�����Ϊcgrn������ɫ��

Invtransform����Ʒ���и���Ʒ����ɫ��һ����˵����һ����һ����

Flippy file����ɫװ������Ʒ����������������ʾʱ��ʹ�õ�ͼ���������Ϊ���¼ӵİ���װ���ĸ����ӣ�����Ҫ�Լ�ָ��ͼƬ������ʹ��Ĭ�ϵĲ�����м��ɡ�

Invfile������Ʒ����Ʒ������ʹ�õ�ͼ�񡣿��Լ�ָ��ͼƬ������ʹ��Ĭ�ϵĲ�����м��ɡ�

Dropsound����Ʒ����ʱ����������������һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ����ͬ����������

Dropsfxframe����Ʒ����ʱ�����ӳ�ʱ�䡣����һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ��ͬ���������ӳ���

Usesound����Ʒװ��ʱ��ʹ�õ�����������һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ��ͬ����ʹ��������



�ظ�

    7¥
    2011-09-04 00:05

    �ٱ� |

    zqtjingzi
    С����
    12

Prop1������Ʒ�ĵ�һ�����ԡ����п���������Properties.txtд�������ǵ�֮ʯ����Ϊmana�����Ǽӷ������Ǹ����ԡ�

Par1����һ�����ԵĲ��������ǵ�֮ʯ����Ϊ�ա���Ϊmana��ʹ���������

Min1����һ�����Ե���Сֵ�����ǵ�֮ʯ����Ϊ20����ʾ���ټ�20������

Max1����һ�����Ե����ֵ�����ǵ�֮ʯ����Ϊ20����ʾ����20������

��������֮��Ĳ�ͬ�ԣ���ÿ��������3���������������������par��min��max��
ÿ������ʹ���ĸ����ļ������������Properties.txt�е�func1�С�
��str/lvl����ֻʹ��par��������par=8�������ÿ������1��������
����str���Բ�ʹ��par����ʹ��min��max����������ΪminΪ5��maxΪ10��������װ�����ӵ�������5��10֮ǰ�仯������˵�ı�����
����㽫���ļ�������min��ֵ����Ϊ��Ӧmax��ֵ����ô�����´���İ���װ���Ͷ���ɼ�Ʒ�����ˣ�Ч���ɲο�JPXXX��

˵����֮�����硰Prop2��Par2��Min2��Max2�����ȵȾ���������4����ͣ�ÿ������װ��������12�����ԣ���prop12,par12,min12,max12��
*/

typedef struct
{
    unsigned short iPadding0;
    unsigned char vindex[32];

    unsigned short iPadding8;
    unsigned int vversion;

    unsigned char vcode[4];

#if 1
    unsigned char vBitCombined;
#else
    //01
    unsigned char iPadding11 : 4;

    unsigned char vladder : 1;
    unsigned char vcarry1 : 1;
    unsigned char vnolimit : 1;
    unsigned char venabled : 1;
#endif

    unsigned char iPadding11[3];

    unsigned int vrarity;

    unsigned short vlvl;
    unsigned short vlvlmyspreq;

    unsigned char vchrtransform;    //colors
    unsigned char vinvtransform;    //colors
    unsigned char vflippyfile[32];

    unsigned char vinvfile[32];

    unsigned short iPadding30;

    unsigned int vcostmyspmult;

    unsigned int vcostmyspadd;

    unsigned short vdropsound;  //sounds
    unsigned short vusesound;   //sounds

    unsigned int vdropsfxframe;

    int vprop1;    //properties
    int vpar1;
    int vmin1;
    int vmax1;

    int vprop2;    //properties
    int vpar2;
    int vmin2;
    int vmax2;

    int vprop3;    //properties
    int vpar3;
    int vmin3;
    int vmax3;

    int vprop4;    //properties
    int vpar4;
    int vmin4;
    int vmax4;

    int vprop5;    //properties
    int vpar5;
    int vmin5;
    int vmax5;

    int vprop6;    //properties
    int vpar6;
    int vmin6;
    int vmax6;

    int vprop7;    //properties
    int vpar7;
    int vmin7;
    int vmax7;

    int vprop8;    //properties
    int vpar8;
    int vmin8;
    int vmax8;

    int vprop9;    //properties
    int vpar9;
    int vmin9;
    int vmax9;

    int vprop10;    //properties
    int vpar10;
    int vmin10;
    int vmax10;

    int vprop11;    //properties
    int vpar11;
    int vmin11;
    int vmax11;

    int vprop12;    //properties
    int vpar12;
    int vmin12;
    int vmax12;
} ST_LINE_INFO;

typedef struct
{
    int vprop1;    //properties
    int vpar1;
    int vmin1;
    int vmax1;
} ST_UNIQUEITEM;

typedef struct
{
    unsigned char vindex[32];
} ST_SEARCHITEMS;

static char *m_apcNotUsed[] =
{
    "*type",
    "*uber",
    NULL,
};

static char *m_apcInternalProcess[] =
{
    "*eol",
    NULL,
};

static unsigned int m_uiUniqueItemCount = 0;
static ST_SEARCHITEMS *m_astUniqueItems = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astUniqueItems, ST_SEARCHITEMS);

char *UniqueItems_GetItemUniqueCode(unsigned int id)
{
    if ( id - 1 < m_uiUniqueItemCount )
    {
        return m_astUniqueItems[id - 1].vindex;
    }

    return NULL;
}

static int UniqueItems_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "index") )
    {
        strncpy(m_astUniqueItems[m_uiUniqueItemCount].vindex, pstLineInfo->vindex, sizeof(m_astUniqueItems[m_uiUniqueItemCount].vindex));
        String_Trim(m_astUniqueItems[m_uiUniqueItemCount].vindex);
        m_uiUniqueItemCount++;
    }

    return result;
}

static int UniqueItems_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int UniqueItems_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "ladder") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "carry1") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "nolimit") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vBitCombined & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "enabled") )
    {
        sprintf(acOutput, "%d", ((pstLineInfo->vBitCombined & 1)) != 0);
        result = 1;
    }

    return result;
}

static int UniqueItems_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( !strcmp(acKey, "chrtransform") )
    {
        pcResult = Colors_GetColorCode(pstLineInfo->vchrtransform);
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
    else if ( !strcmp(acKey, "invtransform") )
    {
        pcResult = Colors_GetColorCode(pstLineInfo->vinvtransform);
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
    else if ( !strcmp(acKey, "dropsound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vdropsound);
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
    else if ( !strcmp(acKey, "usesound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vusesound);
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
    else if ( 1 == sscanf(acKey, "prop%d", &id) )
    {
        ST_UNIQUEITEM *pstUniqueItem = (ST_UNIQUEITEM *)&pstLineInfo->vprop1;
        pcResult = Properties_GetProperty(pstUniqueItem[id - 1].vprop1);
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

int process_uniqueitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, index, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, code, STRING);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, ladder, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, carry1, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, nolimit, BitCombined, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, enabled, BitCombined, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmyspreq, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chrtransform, UCHAR);    //colors
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invtransform, UCHAR);    //colors
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, USHORT);  //sounds
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, USHORT);   //sounds

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop1, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min1, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max1, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop2, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min2, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max2, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop3, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min3, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max3, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop4, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min4, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max4, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop5, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min5, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max5, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop6, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min6, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max6, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop7, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min7, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max7, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop8, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min8, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max8, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop9, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min9, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max9, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop10, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par10, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min10, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max10, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop11, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par11, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min11, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max11, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, prop12, INT);    //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, par12, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, min12, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, max12, INT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_uiUniqueItemCount = 0;

            m_stCallback.pfnConvertValue = UniqueItems_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = UniqueItems_ConvertValue;
            m_stCallback.pfnBitProc = UniqueItems_BitProc;
            m_stCallback.pfnFieldProc = UniqueItems_FieldProc;
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

