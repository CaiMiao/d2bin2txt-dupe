#include "global.h"

#define FILE_PREFIX "setitems"

/*
Title 	SetItems.txt File Guide
Description 	by Alkalund & Char, revised by Myhrginoc
Sent by 	
index: string key to item's name in a .tbl file

set: string key to the index field in Sets.txt - the set the item is a part of.

item: base item code of this set item (matches code field in Weapons.txt, Armor.txt or Misc.txt files).

*item: name of the base item of this set item (reference only, not loaded into game).

Rarity: Chance to pick this set item if more then one set item of the same base item exist, this uses the common rarity/total_rarity formula, so if you have two set rings, one with a rarity of 100 the other with a rarity of 1, then the first will drop 
100/101 percent of the time (99%) and the other will drop 1/101 percent of the time (1%), rarity can be anything between 0 and 255.

lvl: The quality level of this set item, monsters, cube recipes, vendors, objects and the like most be at least this level or higher to be able to drop this item, otherwise they would drop a magical item with twice normal durability.

lvl req: The character level required to use this set item.

chrtransform: Palette shift to apply to the the DCC component-file and the DC6 flippy-file (whenever or not the color shift will apply is determined by Weapons.txt, Armor.txt or Misc.txt). This is an ID pointer from Colors.txt.

invtransform: Palette shift to apply to the the DC6 inventory-file (whenever or not the color shift will apply is determined by Weapons.txt, Armor.txt or Misc.txt). This is an ID pointer from Colors.txt.

invfile: Overrides the invfile and setinvfile specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains the file name of the DC6 inventory graphic (without the .dc6 extension).

flippyfile: Overrides the flippyfile specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains the file name of the DC6 flippy animation (without the .dc6 extension).

dropsound: Overrides the dropsound (the sound played when the item hits the ground) specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains an ID pointer from Sounds.txt.

dropsfxframe: How many frames after the flippy animation starts playing will the associated drop sound start to play. This overrides the values in Weapons.txt, Armor.txt or Misc.txt.

usesound: Overrides the usesound (the sound played when the item is consumed by the player) specified in Weapons.txt, Armor.txt or Misc.txt for the base item. This field contains an ID pointer from Sounds.txt.

cost mult: The base item's price is multiplied by this value when sold, repaired or bought from a vendor.

cost add: After the price has been multiplied, this amount of gold is added to the price on top.

add func: a property mode field that controls how the variable attributes will appear and be functional on a set item. See the appendix for further details about this field's effects.
0 -> no green properties on item (apropxx will appear as a blue attribute on the list instead).
1 -> green properties (apropxx) depend on which other items from the set are equipped.
2 -> green properties (apropxx) depend on how many other items from the set are equipped.

BLUE ATTRIBUTES

prop1 to prop9: An ID pointer of a property from Properties.txt, these columns control each of the nine different fixed (blue) modifiers a set item can grant you at most.

par1 to par9: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them, these fields support calculations.

min1 to min9: Minimum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guide for Properties.txt and ItemStatCost.txt for further 
details.

max1 to max9: Maximum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guide for Properties.txt and ItemStatCost.txt for further 
details.

GREEN ATTRIBUTES

aprop1a,aprop1b to aprop5a,aprop5b: An ID pointer of a property from Properties.txt, these columns control each of the five pairs of different variable (green) modifiers a set item can grant you at most.

apar1a,apar1b to apar5a,apar5b: The parameter passed on to the associated property, this is used to pass skill IDs, state IDs, monster IDs, montype IDs and the like on to the properties that require them, these fields support calculations.

amin1a,amin1b to amin5a,amin5b: Minimum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guide for Properties.txt and ItemStatCost.
txt for further details.

amax1a,amax1b to amax5a,amax5b: Maximum value to assign to the associated property. Certain properties have special interpretations based on stat encoding (e.g. chance-to-cast and charged skills). See the File Guide for Properties.txt and ItemStatCost.
txt for further details.

*eol: terminator field, not used in game, primary purpose is to keep Microsoft Excel from misbehaving.

APPENDIX

Green attributes will appear depending on how many set items are equipped, if the add func field is either 1 or 2. If the add func field is 1, in addition to how many items, the green attributes are controlled by which other items you have equipped as 
well. If a set has X number of items, at most there will be X-1 green attributes on any item.

If add func = 2, these properties will appear as below. Many of the "classic" sets in the unmodded game have this configuration.
aprop1a, aprop1b -> when any second set item is also equipped.
aprop2a, aprop2b -> when any third set item is also equipped.
aprop3a, aprop3b -> when any fourth set item is also equipped.
aprop4a, aprop4b -> when any fifth set item is also equipped.
aprop5a, aprop5b -> when any sixth set item is also equipped.

The fun really begins when add func = 1. Different properties can emerge as different items are equipped in combination from the same set. The attributes appear for specific item pairs regardless of whether or how many other items from the set are also 
equipped. Civerb's Ward (shield) is the one and only example of this configuration in the unmodded game.

If the first item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the second item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the third item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the fourth item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fifth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the sixth item listed in the set definition is also equipped.

If the second item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the first item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the third item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the fourth item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fifth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the sixth item listed in the set definition is also equipped.

If the third item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the first item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the second item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the fourth item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fifth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the sixth item listed in the set definition is also equipped.

If the fourth item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the first item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the second item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the third item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fifth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the sixth item listed in the set definition is also equipped.

If the fifth item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the first item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the second item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the third item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fourth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the sixth item listed in the set definition is also equipped.

If the sixth item listed in the set definition is equipped, it will get the green property:
aprop1a, aprop1b -> when the first item listed in the set definition is also equipped.
aprop2a, aprop2b -> when the second item listed in the set definition is also equipped.
aprop3a, aprop3b -> when the third item listed in the set definition is also equipped.
aprop4a, aprop4b -> when the fourth item listed in the set definition is also equipped.
aprop5a, aprop5b -> when the fifth item listed in the set definition is also equipped.

*/

/*
index �C ��Ʒ���ƣ�
set �C ��ǰ��Ʒ������װ���ƣ�
item �C ��ǰ��Ʒ�Ļ������룻
*item �C ��װ�е�ǰ��Ʒ�����ƣ�ע���ã���
rarity �C ��Ʒ��ϡ�м���
lvl �C ��Ʒ�ļ���
lvl req �C ʹ����Ʒ����Ҫ�Ľ�ɫ����
chrtransform �C ����ɫӵ�е�ǰ��Ʒʱ����ɫ�ı仯��
invtransform �C ��Ʒ���д���Ʒ����ɫ�仯��
invfile �C ����Ʒ�����õ�ͼ������չ����*.Dc6�ļ�����
flippyfile - ����Ʒװ��ʱ�����õ�ͼ������չ������
dropsound �C ����Ʒ����ʱ��������
dropsfxframe -����Ʒ����ʱ����������������������
usesound �C ����Ʒ�ڲ�����״̬�������õ�������
cost mult �C ��Ʒ�۸���������
cost add �C ��Ʒ�۸���������
add func �C ��������ԣ�
prop1 �C ����Ʒ�ĵ�һ���������ԣ�
par1 - ����Ʒ�ĵ�һ�������������ͣ�
min1 �C ����Ʒ�ĵ�һ���������Ե���Сֵ��
max1 - ����Ʒ�ĵ�һ���������Ե����ֵ��
prop2 �C ����Ʒ�ĵڶ����������ԣ�
par2 - ����Ʒ�ĵڶ��������������ͣ�
min2 - ����Ʒ�ĵڶ����������Ե���Сֵ��
max2 �C ����Ʒ�ĵڶ����������Ե����ֵ��
prop3 �C ����Ʒ�ĵ������������ԣ�
par3 �C ����Ʒ�ĵ����������������ͣ�
min3 - ����Ʒ�ĵ������������Ե���Сֵ��
max3 �C ����Ʒ�ĵ������������Ե����ֵ��

�˺�����prop#��par#��min#��max#�Ȳο����Ͻ��ͣ�

aprop1a �C ����Ʒ��1�Ŷ����һ�������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar1a -����Ʒ��1�Ŷ����һ�������ԵĲ�����
amin1a -����Ʒ��1�Ŷ����һ����������Сֵ��
amax1a -����Ʒ��1�Ŷ����һ�����������ֵ��
aprop1b -����Ʒ��1�Ŷ���ڶ��������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar1b -����Ʒ��1�Ŷ���ڶ��������ԵĲ�����
amin1b - -����Ʒ��1�Ŷ���ڶ�����������Сֵ��
amax1b -����Ʒ��1�Ŷ���ڶ������������ֵ��
aprop2a -����Ʒ��2�Ŷ����һ�������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar2a -����Ʒ��2�Ŷ����һ�������ԵĲ�����
amin2a -����Ʒ��2�Ŷ����һ����������Сֵ��
amax2a -����Ʒ��2�Ŷ����һ�����������ֵ��
aprop2b -����Ʒ��2�Ŷ���ڶ��������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar2b -����Ʒ��2�Ŷ���ڶ��������ԵĲ�����
amin2b -����Ʒ��2�Ŷ���ڶ�����������Сֵ��
amax2b -����Ʒ��2�Ŷ���ڶ������������ֵ��
aprop3a -����Ʒ��3�Ŷ����һ�������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar3a -����Ʒ��3�Ŷ����һ�������ԵĲ�����
amin3a -����Ʒ��3�Ŷ����һ����������Сֵ��
amax3a -����Ʒ��3�Ŷ����һ�����������ֵ��
aprop3b -����Ʒ��3�Ŷ���ڶ��������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar3b -����Ʒ��3�Ŷ���ڶ��������ԵĲ�����
amin3b -����Ʒ��3�Ŷ���ڶ�����������Сֵ��
amax3b -����Ʒ��3�Ŷ���ڶ������������ֵ��
aprop4a -����Ʒ��4�Ŷ����һ�������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar4a -����Ʒ��4�Ŷ����һ�������ԵĲ�����
amin4a -����Ʒ��4�Ŷ����һ����������Сֵ��
amax4a -����Ʒ��4�Ŷ����һ�����������ֵ��
aprop4b -����Ʒ��4�Ŷ���ڶ��������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar4b -����Ʒ��4�Ŷ���ڶ��������ԵĲ�����
amin4b -����Ʒ��4�Ŷ���ڶ�����������Сֵ��
amax4b -����Ʒ��4�Ŷ���ڶ������������ֵ��
aprop5a -����Ʒ��5�Ŷ����һ�������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar5a -����Ʒ��5�Ŷ����һ�������ԵĲ�����
amin5a -����Ʒ��5�Ŷ����һ�������Ե���Сֵ��
amax5a -����Ʒ��5�Ŷ����һ�������Ե����ֵ��
aprop5b -����Ʒ��5�Ŷ���ڶ��������ԣ���ɫ���ԣ���������Ʒ�ﵽ��������ʱ���ṩ�ĸ������ԣ���
apar5b -����Ʒ��5�Ŷ���ڶ��������ԵĲ�����
amin5b -����Ʒ��5�Ŷ���ڶ��������Ե���Сֵ��
amax5b -����Ʒ��5�Ŷ���ڶ��������Ե����ֵ��
*eol �C �ļ�������־��
*/

/*
�ļ���������
Set����װ��
Item(s)�����ߣ���װ����
���Դ��ļ���¼����Ϸ�����������װ��װ����
�ļ��е�ÿһ�д���һ��ĳ��װ�е�װ����


�ظ�

    2¥
    2011-09-08 21:10

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�

Index����Ʒ������Ҳ�Ǵ���װ�����Ʒ����Ϸ�еĴ�������ơ�

Set����װ��������һ����װ����Sets.txt������

Item��װ���ײĴ��롣��Armor.txt��Weapons.txt��Misc.txt������

*Item��װ���ײ�ע�͡�

Rarity����Ʒ��ϡ�г̶ȡ������Դ�������ͬ���͵ĵײ��д���װװ������ĸ��ʴ�С���������ĵ���������Ϊ1����ϣ��������������Ϊ7����������Ʒ�ȼ��㹻������������ĵ������ĵ�����ϣ�������߷�֮һ��

Lvl������װ��Ʒ����Ʒ����Ӧ��Sets.txt�ж�Ӧ��װ��Level����һ�¡�

Lvl req��ʹ�ô�װ������Ľ�ɫ�ĵȼ���

Chrtransform����ɫװ������Ʒ����������������ʾ����ɫ��

Invtransform����Ʒ���и���Ʒ����ɫ��һ����˵����һ����һ����

Invfile������Ʒ����Ʒ������ʹ�õ�ͼ�񡣿��Լ�ָ��ͼƬ������ʹ��Ĭ�ϵĲ�����м��ɡ�

Flippy file����ɫװ������Ʒ����������������ʾʱ��ʹ�õ�ͼ��

Dropsound����Ʒ����ʱ����������������һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ����ͬ����������

Dropsfxframe����Ʒ����ʱ�����ӳ�ʱ�䡣����һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ��ͬ���������ӳ���

Usesound����Ʒװ��ʱ��ʹ�õ�����������һ��Ϊ�գ���ʾʹ��Ĭ��ֵ������˰���װ���ĵײĵ���ʱ��ͬ����ʹ��������

Cost mult����Ʒ����NPCʱ�ļ۸���������

Cost add����Ʒ����NPCʱ�ļ۸���������

Add Func���Ƿ��и������ԣ���ɳ�֮Ϊ��װ�������ԣ���װ������������ɫ������ʾ��0����û�У�1��2�����С���û����1��2��ʲô����

Prop1-9������Ʒ�ĵ�һ�����ԡ����п���������Properties.txtд����

Par1-9����һ�����ԵĲ�����

Min1-9����һ�����Ե���Сֵ������

Max1-9����һ�����Ե����ֵ������

�ɴ˿�֪����װװ���ڲ�������װ���Ե�ǰ���£�ÿ�����ֻ����9�����ԣ�������װ�������12����

aProp1a������1a�Ĵ��롣��ν1a������ָ���˼�װ��֮�⣬�ٶ���װ��һ��ͬ��װ���󸽼ӵĵ�һ�����ԡ�ͬ��1bָ�����ٶ���װ��һ��ͬ��װ���󸽼ӵĵڶ������ԣ�2aָ�����ٶ���װ������ͬ��װ���󸽼ӵĵڶ������ԡ�

aPar1a������1a�Ĳ�����

aMin1a������1a����Сֵ������

aMax1a������1a�����ֵ������

����1b��2a��2b��3a��3b��4a��4b��5a��5b��4�У��������ơ�

�ɴ˿�֪��ÿ����⴩һ����װ��ÿ����װ���װ���������2�����ԡ�
���ԴӸ��˶��ƵĽǶȣ���װ�Ŀ�����ҪԶ���ڰ���װ���������Ƕ����װ��
*/

typedef struct
{
    unsigned short wSetItemId;
    unsigned char vindex[32];

    unsigned short iPadding8;

    unsigned int dwTblIndex;

    unsigned char vitem[4];

    unsigned int vset;  //sets.txt

    unsigned short vlvl;
    unsigned short vlvlmyspreq;

    unsigned int vrarity;

    unsigned int vcostmyspmult;
    unsigned int vcostmyspadd;

    unsigned char vchrtransform;    //color
    unsigned char vinvtransform;    //color
    unsigned char vflippyfile[32];

    unsigned char vinvfile[32];

    unsigned short vdropsound;  //sounds

    unsigned short vusesound;   //sounds
    unsigned char vdropsfxframe;
    unsigned char vaddmyspfunc;

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

    int vaprop1a;   //properties
    int vapar1a;
    int vamin1a;
    int vamax1a;
    int vaprop1b;   //properties
    int vapar1b;
    int vamin1b;
    int vamax1b;

    int vaprop2a;   //properties
    int vapar2a;
    int vamin2a;
    int vamax2a;
    int vaprop2b;   //properties
    int vapar2b;
    int vamin2b;
    int vamax2b;

    int vaprop3a;   //properties
    int vapar3a;
    int vamin3a;
    int vamax3a;
    int vaprop3b;   //properties
    int vapar3b;
    int vamin3b;
    int vamax3b;

    int vaprop4a;   //properties
    int vapar4a;
    int vamin4a;
    int vamax4a;
    int vaprop4b;   //properties
    int vapar4b;
    int vamin4b;
    int vamax4b;

    int vaprop5a;   //properties
    int vapar5a;
    int vamin5a;
    int vamax5a;
    int vaprop5b;   //properties
    int vapar5b;
    int vamin5b;
    int vamax5b;
} ST_LINE_INFO;

typedef struct
{
    int vprop1;    //properties
    int vpar1;
    int vmin1;
    int vmax1;
} ST_SETITEM;

typedef struct
{
    unsigned char vindex[32];
} ST_SETITEMS;

static char *m_apcInternalProcess[] =
{
    "*eol",
    NULL,
};

static char *m_apcNotUsed[] =
{
    "*item",
    NULL,
};

static unsigned int m_uiSetItemCount = 0;
static ST_SETITEMS *m_astSetItems = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astSetItems, ST_SETITEMS);

char *SetItems_GetItemUniqueCode(unsigned int id)
{
    if ( id - 1 < m_uiSetItemCount )
    {
        return m_astSetItems[id - 1].vindex;
    }

    return NULL;
}

static int SetItems_ConvertValue_Pre(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "index") )
    {
        strncpy(m_astSetItems[m_uiSetItemCount].vindex, pstLineInfo->vindex, sizeof(m_astSetItems[m_uiSetItemCount].vindex));
        String_Trim(m_astSetItems[m_uiSetItemCount].vindex);
        m_uiSetItemCount++;
    }

    return result;
}

static int SetItems_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return 0;
}

static int SetItems_ConverValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( !strcmp("set", acKey) )
    {
        pcResult = Sets_GetSetName(pstLineInfo->vset);
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
    else if ( !strcmp("chrtransform", acKey) )
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
    else if ( !strcmp("invtransform", acKey) )
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
    else if ( !strcmp("dropsound", acKey) )
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
    else if ( !strcmp("usesound", acKey) )
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
    else if ( strlen("prop1") == strlen(acKey) && 1 == sscanf(acKey, "prop%d", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vprop1;
        pcResult = Properties_GetProperty(pstSetItem[id - 1].vprop1);
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
    else if ( strlen("par1") == strlen(acKey) && 1 == sscanf(acKey, "par%d", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vprop1;
        pcResult = Properties_GetProperty(pstSetItem[id - 1].vprop1);
        if ( pcResult )
        {
            if ( !strcmp("skill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[id - 1].vpar1);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[id - 1].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[id - 1].vpar1);
            }
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "aprop%da", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1a;
        pcResult = Properties_GetProperty(pstSetItem[(id - 1) * 2].vprop1);
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
    else if ( 'a' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "apar%da", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1a;
        pcResult = Properties_GetProperty(pstSetItem[(id - 1) * 2].vprop1);
        if ( pcResult )
        {
            if ( !strcmp("skill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[(id - 1) * 2].vpar1);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
            }
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "aprop%db", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1b;
        pcResult = Properties_GetProperty(pstSetItem[(id - 1) * 2].vprop1);
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
    else if ( 'b' == acKey[strlen(acKey) - 1] && 1 == sscanf(acKey, "apar%db", &id) )
    {
        ST_SETITEM *pstSetItem = (ST_SETITEM *)&pstLineInfo->vaprop1b;
        pcResult = Properties_GetProperty(pstSetItem[(id - 1) * 2].vprop1);
        if ( pcResult )
        {
            if ( !strcmp("skill", pcResult) )
            {
                pcResult = Skills_GetSkillName(pstSetItem[(id - 1) * 2].vpar1);
                if ( pcResult )
                {
                    strcpy(acOutput, pcResult);
                }
                else
                {
                    sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
                }
            }
            else
            {
                sprintf(acOutput, "%d", pstSetItem[(id - 1) * 2].vpar1);
            }
        }
        else
        {
            acOutput[0] = 0;
        }
        result = 1;
    }

    return result;
}

int process_setitems(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, index, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, item, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, set, INT);  //sets.txt

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvl, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lvlmyspreq, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rarity, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspmult, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, costmyspadd, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, chrtransform, UCHAR);    //color
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invtransform, UCHAR);    //color
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, flippyfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invfile, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsound, USHORT);  //sounds

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, usesound, USHORT);   //sounds
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, dropsfxframe, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, addmyspfunc, UCHAR);

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

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop1a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar1a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin1a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax1a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop1b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar1b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin1b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax1b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop2a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax2a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop2b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin2b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax2b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop3a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax3a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop3b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin3b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax3b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop4a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax4a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop4b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin4b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax4b, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop5a, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax5a, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, aprop5b, INT);   //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, apar5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amin5b, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, amax5b, INT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_uiSetItemCount = 0;

            m_stCallback.pfnConvertValue = SetItems_ConvertValue_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(sets, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = SetItems_ConverValue;
            m_stCallback.pfnFieldProc = SetItems_FieldProc;
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

