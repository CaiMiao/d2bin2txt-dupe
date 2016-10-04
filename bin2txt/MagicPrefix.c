#include "global.h"

#define FILE_PREFIX "MagicPrefix"

/*
Name - This field controls what string will be displayed in-game for this affix (in the case of AutoMagic.txt this field is unused).

Version - This field controls whenever or not this affix can appear in classic games.


    0 - pre v08 affixes (needed so characters from those versions can be imported to current ones).

    1 - post v08 affixes (affixes available in classic and LoD).

    100 - LoD-only affixes (affixes available only in LoD).



Spawnable - A boolean that controls whenever or not this affix can be picked by the randomizer that assigns affixes to magic and rare items. 0 = cannot be picked, 1 = can be picked. Untested: You should be able to use unspawnable affixes via cube 
recipes however, similar to the way the game handles unspawnable items.

Rare - A boolean that controls whenever or not this affix can be picked by the randomizer when assigning affixes to a rare item. 0 = cannot appear on rare items (magic only), 1 = can appear on rare and magic items.

Level - The quality level (qLvl) of this affix, for this affix to be available on an item, that item must have an item level (iLvl) of at least this amount. The iLvl is equal to the level of the monster that drops the item, or the generation level (for 
vendors). The iLvl of an item is further influenced by the magic lvl field in WEAPONS.txt and ARMOR.txt (and MISC.txt).

MaxLevel - An extremely powerful but badly underused field. This controls the point at which this affix will no longer appear on items. Say we have a Level of 10 and a MaxLevel of 15, then the affix will only appear on items with a iLvl of 10-15, 
whereas it will never appear on items with iLvls 1-9 and 16-99. This is the easiest way to get those crappy low-level affixes of higher level drops to ensure that those are useful.

LevelReq - The general level requirement that your character must meet before he can use an item that has this affix.

ClassSpecific - This does not work the way RicFaith suggested in his 1.09 guides. As you can see, it appears on +skilltab items, and we all know that you can find skiller grand charms for every class irregardless of what class you are. I assume that 
this is a bug fix to the problem that appeared during the early expansion beta, there +skilltab items effected all classes that used the item and not only the class that they were supposed to effect.

Class - This field controls the character class for whom the class specific level requirement appears.

ClassLevelReq - The level requirement your character must meet before he can use an item with this affix if his class is the class specified in the Class column. So lets say Class is Ama and normal LevelReq is 20 while ClassLevelReq is 25. Then an 
Amazon will be able to use this item at cLvl 20 while all other classes would need to be cLvl 25.

Frequency - This works the same way rarity works in all other files. It controls the probability of this affix being picked by the randomizer within this affix group. In classic days, the game simply rolled a random on all available affixes, ever since 
v08 they are using this field (badly), which leads to the crappy rare items we see today. Lets say we have 5 affixes inside a group with Frequencies of 1, 5, 10, 50 and 100, then the chance for each of these to appear in case the game selects an affix 
from this group is: 1/166, 5/166, 10/166, 50/166 and 100/166 (~1%, 3%, 6%, 30% and 60%). In short, the chance for an affix to appear is frequency/total_frequency. This field can hold values from 0 to 255. 0 will effectivelt make the affix never appear (
unless accessed by a cube recipe, but see under Spawnable).

Group - The group an affix is assigned to. The game cannot pick more then one affix from each group, this is used to prevent an item from spawning say with Ferocious and Cruel at the same time. (be aware that you can put affixes in MagicSuffix, 
MagicPrefix and AutoMagic in the same group, thus having prefix A never spawn together with suffix B). A blank field obviously puts the affix in group 0, this is not a bug.

Mod1Code to Mod3Code - The modifier(s) granted by this affix. This is an ID pointer from PROPERTIES.txt.

Mod1Param to Mod3Param - The parameter passed to the associated modifier. Whenever a modifier uses the parameter or not depends on the modifier, see PROPERTIES.txt.

Mod1Min to Mod3Min - The minimum value passed to the associated modifier. Whenever, and if so how, the modifier uses this value depends on the modifier, see PROPERTIES.txt.

Mod1Max to Mod3Max - The maximum value passed to the associated modifier. Whenever, and if so how, the modifier uses this value depends on the modifier, see PROPERTIES.txt.

Transform - A boolean that controls whenever or not this affix will alter the color of the item it appears on. 0 = do not change color, 1 = change color.

TransformColor - An ID pointer from COLORS.txt, this determines what color the modifier will give this item when the Transform boolean is true.

iType1 to iType7 - These fields are ID pointers to ItemTypes.txt that control what item types this affix can appear on. The affix can appear on all item types that inherit the item type in this field. So putting 'armo' in here will make it appear on all 
armor (etc).

eType1 to eType5 - These fields are ID pointers to ItemTypes.txt that control what item types this affix will never appear on. The affix will not appear on any item type that inherits this item type. So putting 'armo' here would prevent it from showing 
up on all armor (etc).

Divide - This does not work the way the name suggests (the fields are all filled with 0), if it works at all that is, it doesn't appear to work in ItemStatCost so it probably doesn't here either. But if it did work like that other column is supposed to 
work, this controls the percentage the price is reduced by in 1024th. Where 1024 equals 100%.

Multiply - The price of the item is multiplied by this value when this affix is present on it (keep away from this field unless you want to make something extremely expensive without editing ItemStatCost or the base prices). In 1024ths.

Add - The hard amount that is added to the price of this item when this affix is present on it.

*/

/*
�ļ���1��MagicPrefix.txt
�ļ���2��MagicSuffix.txt
�ļ�·�������������ļ���/data/global/excel/


()
����

    �ظ�

    1¥
    2011-09-16 23:28

    �ٱ� |

���ɾ�Ʒ
�������ԡ�Buildһ������Mana�Ķ���SOR
�����������ߵ�2��BoxTool�������
[���һˮ]DOS��Ϸ���ɴ��ͼ..
���¾��䣺׷�䡶�����ƻ���1��
���ɾ�Ʒ
�����ʳ�Ʒ����������ȤMOD����~
ʮ��֮���㻹�᲻��򿪰���2�������ڴ��Ŀ�ʼMFô
�����벩������MOD��---------�������ƻ���---����桿
��������solo���ܻ�ʥ��

    zqtjingzi
    С����
    12

�ļ���������
Magic��ħ����������ָħ�����ԡ�
Prefix��ǰ׺������ħ����׺�е�ǰ׺��
Suffix����׺������ħ����׺�еĺ�׺��
�����������ļ�����������ħ����׺ǰ׺���׺�������Ϣ��
���ļ��е�ÿһ�б�ʾһ����׺ǰ׺���׺��


�ظ�

    2¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

����˵����֮���԰��������ļ�����һ��˵������Ϊ���������е��м�����һģһ���ġ�


�ظ�

    3¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    4¥
    2011-09-16 23:29

    �ٱ� |

    zqtjingzi
    С����
    12

Name��ǰ׺�����׺����

version�����õ������Ϸ�汾����0��-diabloԭ��;��100��-�ƻ�֮����

spawnable���Ƿ������Ϸ�����ɡ�1=�ǣ�0=��

rare���˴�׺�Ƿ�����ϡ�У�������Ʒ�ϳ��֡���+3��ϵ���ܵĴ�׺����Ϊ0���������������Բ��ܳ�����ϡ�У�������Ʒ�ϡ�1=�ǣ�0=��

level����׺�ȼ���ֻ�е���Ʒ�ȼ����ڴ˴�׺�Ĵ�׺�ȼ�ʱ���˴�׺�ſ��ܳ�������һ��Ʒ�ϡ�������ǰ׺������Ĺ��Ｖ��(������A)��

maxLevel����׺�ȼ����ޡ���������ֵʱ���˴�׺ֻ���������Ʒ�ȼ�С�ڴ˵ȼ�����Ʒ�ϡ���ǰ׺�ܲ�������󼶱��糬�������ٲ���(������A)��

levelreq��ʹ�ô��д˴�׺��Ʒ�Ľ�ɫ�ȼ����󡣣������������ӻ�������

classSpecfic���Ƿ�Ϊĳһְҵר�á�����Ϊ�ض���ɫ���ܲ�����ǰ׺(ama,sor,nec,pal,bar,dru,ass)��

class���Ƿ��ĳһְҵ�������ʹ�õȼ��������еĻ������е���дְҵ���롣�紫�;�����׺���Գ���ʦ�������ְҵʹ�õȼ�����Ϊ24��������ʦ18���͹��ˡ�

classLevelreq��������һ�У��ض�ְҵ������

frequency����ͬһ���׺�д˴�׺���ֵ�Ƶ�ʡ�

group����׺�����Ĵ�׺�顣��ÿһ����Ʒ���ԣ�����ͬһ��׺��Ĵ�׺ֻ�ܳ���һ����
�����Ƶ�����ǰ׺��ϣ��������伸��(������A)��
M-X.(�ο������)

mod1Code���˴�׺�ĵ�1�����ԡ�

mod1Param���˴�׺�ĵ�1�����ԵĲ�����

mod1Min���˴�׺�ĵ�1�����Ե���Сֵ������

mod1Max���˴�׺�ĵ�1�����Ե����ֵ������

���µ�mod2Code��mod3Max��8�зֱ��ʾ�˴�׺�ĵ�2��3�����ԣ����庬��ο���1�����ԵĽ��͡�



�ظ�

    5¥
    2011-09-16 23:30

    �ٱ� |

    zqtjingzi
    С����
    12

transform���˴�׺�Ƿ��ʹ��Ʒ��ɫ��1�����ɫ��0������ɫ��

transformColor�����˴�׺��ʹ��Ʒ��ɫʱ������Ʒ����ɵ���ɫ����Colors.txt������

itype1-7���˴�׺�����ڵĵ�1-7��װ�����͡�

etype1-3(5)���˴�׺�����õĵ�1-3(5)��װ�����ͣ�����etypeӦ��ĳһitype�������͡�

˵������MagicPrefix.txt��etype����5�У���MagicSuffix.txt��etype����3�С�
�˴�׺�����ܹ����õ�װ������Ϊsum(itype1-7) - sum(etype1-3(5))��������itype���ܺ��ٳ�ȥetype�е����͡�

divide���۸�����1������NPCʱ�ļ۸��������

multiply���۸�����2��

add���۸�����3��

*eol����β��־������Ϊ0��

����A -- �飬Ƶ�ʺ�ǰ׺�ľ����� 

#���ɸ����Ƶ�ǰ׺(һ��Ϊͬһ����,��Ȼ�����Ƿǵ����,)ͨ��һ�����ֱ�־���һ��Ⱥ�飬��121-152��32��ǰ׺������ͬһ��(101)������㶮һ��e�ĵĻ�����ᷢ�����Ƕ������ơ���ʥ��,ʥ��ġ�����˼(�确holy��,��saintly��)
������Ϸ��Ѱ��һ�������õ�ǰ׺ʱ��ͬһ���е�ǰ׺��ֻ��ѡ��һ�����������Է�ֹǰ׺���ظ�(overlapping)������������+1 light radius��(��1������Χ)���������ʣ����Ƿǳ��˷ѵġ�

#����Щǰ׺�ǿɻ�õġ���ͨ������ķ�ʽ����ó� ---- ��Ruvanal�ṩ

�Ƚ��ܼ������
alvl = ǰ׺�ȼ�����һ����Ʒ���ԣ����������롮level���͡�maxlevel����ֵ���бȽ�(��level���͡�maxlevel��˵������,��Щ������ǰ׺�ͺ�׺���в鵽!)������ο�ĳ����ǰ׺/��׺��ʱ������ֵ���ڡ�level������
ilvl = ���еȼ�(һ��ο���Ʒ�ȼ�(item level),��Ȼ�������Ʒ�Ĳ����ȼ�(item creation level)�Ļ������һЩ)����һ����Ʒ����(����˵������)ʱ�����ֵҲ��ͬʱ���趨�ˡ�
mlvl = ����ȼ���
clvl = ��ɫ�ȼ���
qlvl = �����ȼ������ֵ������armor.txt,weapon.txt��misc.txt��level���鵽�����ֵ��������������(weapXX)�Ϳ���(armoXX)�ĲƸ�����(treasure classes)��
magic_lvl = ĳЩ��Ʒ�ϵ�ħ���ȼ���������ĿǰΪֹ,ֻ��������Щ��Ʒ�����ֽ�����Ȩ��(��wands��,ֻ�ǡ���ͨ����չ����,��������),��(staves),����(��orbs��,ȡֵ1)��Ȧ��(��circlets��,circlet(ͷȦ)=3,Coronet(����)=8,Tiara(���ع�)=13,Diadem(����)=1.)��

��һ����ǰ׺����Ʒ����ʱ����alvl��ֵͨ������ķ����ӡ�ilvl���͡�qlvl��ֵ����õ�*��
If (ilvl>99) then {ilvl=99} 
if (qlvl>ilvl) then {ilvl=qlvl} ;**
if (magic_lvl>0) then {alvl=ilvl+magic_lvl} 
else 
{ 
if (ilvl<(99-qlvl/2)) 
then {alvl=ilvl-qlvl/2} 
else {alvl=2*ilvl-99} 
} 
If (alvl>99) then {alvl=99} 
*ע�����еļ�����(����ÿһ��)��ȡ������
**ע������µġ�ilvl��ֵֻ�ڼ��������ʹ�á���������Ʒ�����ļ�(items data file)�еġ�ilvl��ֵ���ֲ��䡣 

#����Ϸ�Ѿ�֪����Щ��׺��������������ʱ������Ҫ֪����δӸ������ж���ѡ���ǰ׺����ѡ����ʵ�ǰ׺������������ɡ�frequency��(Ƶ��)������ɡ�

��Frequency��(Ƶ��)�����˸�ǰ׺��ѡ�еļ��ʣ�Ƶ��ֵԽ�߲�������Խ��
�ٸ�����˵����
���裺Mod1freq=5,Mod2freq=3,Mod3freq=2,Mod4freq=1
���ֻ�ܲ���'Mod1'��'Mod2',��������ǵĸ������£�
'Mod1' = 5/(5+3)=5/8=62.5%
'Mod2' = 3/(5+3)=5/8=37.5%
����ĸ����ξ��ܲ���,����Ӧ�ĸ������£�
'Mod1' = 5/(5+3+2+1) = 5/11=45.5%
'Mod2' = 3/(5+3+2+1) = 3/11=27.3%
'Mod3' = 2/(5+3+2+1) = 2/11=18.2%
'Mod4' = 1/(5+3+2+1) = 1/11=9.1%

��������Կ������������һ�����ߵĵȼ�(higher level)��ͨ��'maxlevel'������Щ������(lower quality)��ǰ׺�˵���ͨ���趨'maxlevel��ֵʹ����һ���������������ʹ��Щ���͵�ǰ׺�����еļ���(all levels)�϶����Ի�ã��Ӷ���Ч�ı�����Щǿ���(powerful)ǰ׺�ܾۼ�(
pool)��һ��
-------------------------------------------------------------------------------------
����B -- itype & etype

itype = Inclusion TYPE(��������) & etype = Exclusion TYPE(�ų�����)

���������һ�������Ĵ�׺������{itype}����������Ʒ�����ϲ����������ܲ�����{etype}����������Ʒ���͡�

���磺itype = {weap,armo} etype = {axe,helm,belt}
�����ʾ�ô�׺���Բ��������е������Ϳ����ϣ������ڸ���,ͷ���������ϲ��ܲ�����

ͨ�����ַ���(�ڡ�itype���͡�etype�������趨��Ʒ����)������Կ���ĳ����Ʒ�Ƿ��ܲ���(����˵����)�ô�׺��������ĳ��(Щ)��׺ֻ���ڽ�(swords)�ϲ��������߲��������ڽ��ϲ�������Ȼ�����������֪������Ʒ�Ĵ��롣

ע�⣺���ϵ�˵��ͬ����Ӧ�������С�itype/etype����.txt�ļ�����automagic,rareprefix/suffix��

*/

typedef struct
{
    unsigned char vName[32];

    unsigned short iPadding8;
    unsigned short vversion;

    unsigned int vmod1code; //properties
    int vmod1param;
    int vmod1min;
    int vmod1max;

    unsigned int vmod2code; //properties
    int vmod2param;
    int vmod2min;
    int vmod2max;

    unsigned int vmod3code; //properties
    int vmod3param;
    int vmod3min;
    int vmod3max;

    unsigned short vspawnable;
    unsigned short vtransformcolor; //colors

    unsigned short vlevel;
    unsigned short iPadding22;

    unsigned int vgroup;

    unsigned int vmaxlevel;

    unsigned char vrare;
    unsigned char vlevelreq;
    unsigned char vclassspecific; //playerclass
    unsigned char vclass; //playerclass

    unsigned short vclasslevelreq;
    unsigned short vitype1; //itemtypes

    unsigned short vitype2;
    unsigned short vitype3;

    unsigned short vitype4;
    unsigned short vitype5;

    unsigned short vitype6;
    unsigned short vitype7;

    unsigned short vetype1; //itemtypes
    unsigned short vetype2;

    unsigned short vetype3;
    unsigned short vetype4;

    unsigned short vetype5;
    unsigned short vfrequency;

    unsigned int vdivide;
    unsigned int vmultiply;
    unsigned int vadd;
} ST_LINE_INFO;

static char *m_apcNotUsed[] =
{
    "*comment",
    "transform",
    NULL,
};

static int MagicPrefix_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int id;
    int result = 0;

    if ( !strcmp(acKey, "mod1code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod1code);
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
    else if ( !strcmp(acKey, "mod2code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod2code);
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
    else if ( !strcmp(acKey, "mod3code") )
    {
        pcResult = Properties_GetProperty(pstLineInfo->vmod3code);
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
    else if ( !strcmp(acKey, "transformcolor") )
    {
        pcResult = Colors_GetColorCode(pstLineInfo->vtransformcolor);
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
    else if ( !strcmp(acKey, "classspecific") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vclassspecific);
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
    else if ( !strcmp(acKey, "class") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vclass);
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
    else if ( strlen("itype1") == strlen(acKey) && 1 == sscanf(acKey, "itype%d", &id) )
    {
        unsigned short *pwIType = &pstLineInfo->vitype1;
        pcResult = ItemTypes_GetItemCode(pwIType[id - 1]);
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
    else if ( strlen("etype1") == strlen(acKey) && 1 == sscanf(acKey, "etype%d", &id) )
    {
        unsigned short *pwIType = &pstLineInfo->vetype1;
        pcResult = ItemTypes_GetItemCode(pwIType[id - 1]);
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

static char *MagicPrefix_GetKey(void *pvLineInfo, char *pcKey, unsigned int *iKeyLen)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;

    strcpy(pcKey, pstLineInfo->vName);
    *iKeyLen = strlen(pcKey);

    return pcKey;
}

int process_magicprefix(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, Name, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod1max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod2max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3code, UINT); //properties
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3param, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3min, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, mod3max, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, spawnable, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, transformcolor, USHORT); //colors

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, level, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxlevel, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rare, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, levelreq, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classspecific, UCHAR); //playerclass
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, UCHAR); //playerclass

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, classlevelreq, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype1, USHORT); //itemtypes

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype5, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype6, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itype7, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype1, USHORT); //itemtypes
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype2, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype3, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype4, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, etype5, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, frequency, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, divide, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, multiply, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, add, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            //m_stCallback.pfnGetKey = MagicPrefix_GetKey;
            m_stCallback.pfnConvertValue = MagicPrefix_ConvertValue;
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

