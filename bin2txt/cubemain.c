#include "global.h"

#define FILE_PREFIX "cubemain"
#define NAME_PREFIX "cm"

/*
Title 	Cubemain.txt File Guide
Description 	by Nefarius & Myhrginoc
Sent by 	
OVERVIEW:

This is the file that controls one of the most interesting aspect in the game that is used by the horadic cube (that you get from second quest in act 2).

RELATED .TXT FILES:

This file is using:

    ItemTypes.txt
    Misc.txt
    Armor.txt
    Weapons.txt
    Setitems.txt
    Uniqueitems.txt
    Properities.txt
    Itemstatscost.txt



COLUMN DESCRIPTIONS :

description 	This column has no function, it only serves as a comment field to make it easier to find specific recipes.
enabled 	Boolean, this controls if a recipe is active in-game, 1 stands for yes and 0 stands for no.
ladder 	Boolean, 1 if only allowed in ladder on realms (TBD) (Note: Also works for single player, tcp/ip)
min diff 	minimum game difficulty to use recipe (0 = all difficulties, 1 = Nightmare and hell, 2 = hell only).
version 	Tells the game if this is a old classic, new classic or expansion recipe, 0=old classic d2, 1=new classic d2 and 100 is expansion recipe. (*I am not sure if 1 is used in this file, but this column works the same way it works in all the other 
item related files so it probably does.)
op 	replaces realtime field, can now select requirement for allowing recipe (See Appendix A for more details)
param 	replaces realtime field, can now select requirement for allowing recipe (for more details see Appendix A).
value 	replaces realtime field, can now select threshold for custom requirement (for more details see Appendix A).
class 	You can use this to make a recipe class specific by using the class codes, aka ama, bar, pal, nec, sor, dru and ass.
numinputs 	Controls the number of items you need to put into the cube for this recipe. If you are using the ��qty�� parameter in any inputs this number must include the sum of quantities.
inputs 1 through 7 	This controls the type of inputs used for the recipe, each cell stands for a different item. Also includes input parameters, please refer to Nefarius' Cubemain Code Reference in the Keep's resource section in order to read about 
these codes.

    input 1 - primary item of recipe, target of outputs for item transform recipes.
output 	Defines the first recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
lvl 	Controls the level of the item that is created in the first output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
plvl 	This column uses a portion of the players level for the output level.
ilvl 	This column uses a portion of the first input's level for the output level.
mod 1 through 5 	Defines additional attributes affixed to the first output item.

    mod # - the property code used to specify an attribute.
    mod # chance - the chance in percent the property will be assigned.
    mod # param - parameter field for properties that use parameters.
    mod # min - minimum field for properties that specify a range of values.
    mod # max - maximum field for properties that specify a range of values.

To make property have a fixed value make mod # min and mod # max the same.
output b 	Defines the second recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
b lvl 	Controls the level of the item that is created in the second output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
b plvl 	This column uses a portion of the players level for the output level.
b ilvl 	This column uses a portion of the (first or second ?TBD) input's level for the output level.
b mod 1 through 5 	Defines additional attributes affixed to the second output item. These fields work the same way as the mod # fields for the first item.
output c 	Defines the third recipe result item. Also includes output parameters, please refer to the Cubemain Code Reference in the keeps resource section to read about these codes.
c lvl 	Controls the level of the item that is created in the third output field, note this value force spawns the item at this specific level. Its also used in the formula for the next two fields.
c plvl 	This column uses a portion of the players level for the output level.
c ilvl 	This column uses a portion of the (first or third ?TBD) input's level for the output level.
c mod 1 through 5 	Defines additional attributes affixed to the third output item. These fields work the same way as the mod # fields for the first item.
*eol 	line terminator, must be filled if using MS Excel or similar spreadsheet that eats trailing tabs.


APPENDIX A by Joel:
Updated by Myhrginoc
Note: stat is using the ID from itemstatscost.txt (ie strength has ID 0)

Op: Param: Value: Effect:
1 x day # Valid recipe if (current day >= value)
2 x d. code Valid recipe if (current day == day code) [0=sunday,etc ...]
3 stat value Valid recipe if (stat.accr >= value)
4 stat value Valid recipe if (stat.accr <= value)
5 stat value Valid recipe if (stat.accr != value)
6 stat value Valid recipe if (stat.accr == value)
7 stat value Valid recipe if (stat.base >= value)
8 stat value Valid recipe if (stat.base <= value)
9 stat value Valid recipe if (stat.base != value)
10 stat value Valid recipe if (stat.base == value)
11 stat value Valid recipe if (stat.accr - stat.base >= value)
12 stat value Valid recipe if (stat.accr - stat.base <= value)
13 stat value Valid recipe if (stat.accr - stat.base != value)
14 stat value Valid recipe if (stat.accr - stat.base == value)
15 stat value Valid recipe if (input1.stat.accr >= value)
16 stat value Valid recipe if (input1.stat.accr <= value)
17 stat value Valid recipe if (input1.stat.accr != value)
18 stat value Valid recipe if (input1.stat.accr == value)
19 stat value Valid recipe if (input1.stat.base >= value)
20 stat value Valid recipe if (input1.stat.base <= value)
21 stat value Valid recipe if (input1.stat.base != value)
22 stat value Valid recipe if (input1.stat.base == value)
23 stat value Valid recipe if (input1.stat.accr - input1.stat.base >= value)
24 stat value Valid recipe if (input1.stat.accr - input1.stat.base <= value)
25 stat value Valid recipe if (input1.stat.accr - input1.stat.base != value)
26 stat value Valid recipe if (input1.stat.accr - input1.stat.base == value)
27 x x pItem->OtherID != value
28 x x pItem->QuestDiff < ptGame->Diff (only checked if Quest and QuestDiffCheck are 1)
29->255 Free op code. 

*/

/*
���Դ��ļ��������������Ҫ�ļ���Ҳ���������ϳɹ�ʽ���ļ���
���ļ��е�ÿһ�б�ʾһ���ϳɹ�ʽ��

description��ע�ͣ������������ʹ˹�ʽ�ģ������д��

Enabled���˹�ʽ�Ƿ������Ϸ��ʹ�á�0������ʹ�ã�1�������ʹ�á�

Ladder���Ƿ�ֻ��������ģʽ��ʹ�á�0�����ǣ�1�����ǡ������治�ܴ���Ӱ�죬���Կɲ��

min diff��ʹ�ô˹�ʽ����Ҫ�������Ϸ�Ѷȡ�0������ͨ��1������Σ�2���������

version��ʹ�ô˹�ʽ����Ҫ�������Ϸ�汾��0 ����ԭ�汾�� 1 �����°汾��100 ������չ���񣨼�������֮��������

op��ʹ�ô˹�ʽ������Ч����������������28��ʾʹ�ô˹�ʽʱ��ʾ�ϳɹ�â��

param��op�еĲ�����

value��op�еĲ�����

class��ʹ�ô˹�ʽ�Ľ�ɫְҵ���ơ�

numinputs������˹�ʽ�ϳɵ�������Ʒ������

input1���˹�ʽ�������ϡ�����Ʒ����ʱһ��Ҫ����������Ʒ��Ϊ��Ҫ���ϣ���input1���С���������ԭ��

input2-7���˹�ʽ�ĸ������ϡ�

output���˺ϳɹ�ʽ�ĵ�һ���ϳɽ����

lvl����һ���ϳɽ������Ʒ�ȼ�����������ʹ�ý�����qlvl��ilvl�����ϳɽ������Ʒ�ȼ�����������ֵ��qlvl��ilvl����Ч��

qlvl����ɫ�ȼ��Ժϳɽ����Ʒ�ȼ���Ӱ�����ӡ�

ilvl���˹�ʽ�������ϵ���Ʒ�ȼ��Ժϳɽ����Ʒ�ȼ���Ӱ�����ӡ�
��lvl��Ϊ�գ���ϳɽ������Ʒ�ȼ�Ϊ [ [��ɫ�ȼ� * qlvl / 100] + [��������Ʒ�ȼ� * ilvl / 100] ]����ʽ���еķ����ű�ʾ����ȡ����
���Զ��ڳ�ɫ��Ʒ�ĺϳ���˵��qlvl=ilvl=50������һ��99���Ľ�ɫʹ��99����װ����Ϊ�����ϣ��ϳɳ��ĳ�ɫ��Ʒ�ĵȼ�Ϊ 2 * [99 * 50 / 100] = 2 * [49.5] = 2 * 49 = 98��

mod 1-5����һ������ĵ�1-5�����ԡ���Properties.txt������

mod 1-5 chance�����ֵ�1-5�����Եĸ��ʡ�

mod 1-5 param����1-5�����ԵĲ�����

mod 1-5 min����1-5�����Ե���Сֵ������

mod 1-5 max����1-5�����Ե����ֵ������

output b���˺ϳɹ�ʽ�ĵڶ����ϳɽ����

�Ժ�28�еĺ��嶼�ǶԺϳɹ�ʽ�ĵڶ����ϳɽ������������ο���һ���ϳɽ���Ľ��͡�

output c���˺ϳɹ�ʽ�ĵ������ϳɽ����

�Ժ�28�еĺ��嶼�ǶԺϳɹ�ʽ�ĵ������ϳɽ������������ο���һ���ϳɽ���Ľ��͡�

*eol����β��־��������0��

����˵��1���ϳ�ʱ��Ϸֻ���¼����ϳɵ������ϵ���Ϣ����װ�����͡�Ʒ�ʡ���Ʒ�ȼ�֮��ģ��Լ���д�µĹ�ʽʱһ��Ҫע����㡣

����˵��2�����ϳɽ����ռ�Ŀռ䳬�����鱾��Ĵ�Сʱ������ɿռ䳬���ĺϳɽ������ʧ��

����˵��3��
op�е�ֵ�����param��Value��ʹ��˵����
op Param Value ʵ��Ч��
1 x day ��ǰ����(ʱ�䣿)���ڸ�������ʱCube�䷽��Ч
2 x ���� ��ǰ���ڵ��ڸ�������ʱ�䷽��Ч(0=������ �ȵ� ...)
3 stat value ��ǰ״̬���ڵ��ڸ�������ʱ�䷽��Ч
4 stat value ��ǰ״̬С�ڵ��ڸ�������ʱ�䷽��Ч
5 stat value ��ǰ״̬�����ڸ�������ʱ�䷽��Ч
6 stat value ��ǰ״̬���ڸ�������ʱ�䷽��Ч
7 stat value ����״̬С�ڵ��ڸ�������ʱ�䷽��Ч
8 stat value ����״̬���ڵ��ڸ�������ʱ�䷽��Ч
9 stat value ����״̬�����ڸ�������ʱ�䷽��Ч
10 stat value ����״̬���ڸ�������ʱ�䷽��Ч
11 ? ? ?
12 ? ? ?
13 ? ? ?
14 ? ? ?
15 stat value input1��ǰ״̬С�ڵ��ڸ�������ʱ�䷽��Ч
16 stat value input1��ǰ״̬���ڵ��ڸ�������ʱ�䷽��Ч
17 stat value input1��ǰ״̬�����ڸ�������ʱ�䷽��Ч
18 stat value input1��ǰ״̬���ڸ�������ʱ�䷽��Ч
19->27 ����Op.
28 x x ��ʾ�ϳ�ʱ��Ĺ�â.
29->255 ����Op.

�˲���ժ¼��Sloovy�ķ��ԣ�����û�н�����֤��

�������˵��һ�£��������벻ʧȥ����ϳ��õ�ԭʼ��Ʒ�����Խ� output b�����ޱ����ԭʼ��Ʒ��
����˵��1����֮��+1�س�ħ����=������ţ�أ��������������ţ�غ����ӵ�лس�ħ���飬������output b������tbk�����Ҳ����κε����Լ��������������ɡ�


���е���ʱ 5%���� ʩչ �ȼ�5 �˺�����
�������ô�
gethit-skill���⼼�ܵĴ��룡Amplefy Damage���˺����
5�����ӣ�������

gethit�Ǳ�����ʱ��hit-skill�ǻ��е���ʱ��
code��prop) = hit-skill
param = Amplify Damage �� 66
min = 5
max = 5
��Ӧ����Properties.txt�ļ��������ᵽ��
*/

typedef struct
{//total 328 bytes
    unsigned char venabled;
    unsigned char vladder;
    unsigned char vminmyspdiff;
    unsigned char vclass;   //playerclass

    unsigned int vop;
    unsigned int vparam;
    unsigned int vvalue;

    unsigned short vnuminputs;
    unsigned short vversion;

    unsigned char vinputmysp1[8];

    unsigned char vinputmysp2[8];

    unsigned char vinputmysp3[8];

    unsigned char vinputmysp4[8];

    unsigned char vinputmysp5[8];

    unsigned char vinputmysp6[8];

    unsigned char vinputmysp7[8];

    unsigned char voutput[20];  //lvl��plvl��ilvl��������20��byte��

    unsigned int iPadding24;

    unsigned int vmodmysp1;   //properties

    unsigned short vmodmysp1myspparam;
    short vmodmysp1myspmin;

    short vmodmysp1myspmax;
    unsigned short vmodmysp1myspchance;

    unsigned int vmodmysp2;   //properties

    unsigned short vmodmysp2myspparam;
    short vmodmysp2myspmin;

    short vmodmysp2myspmax;
    unsigned short vmodmysp2myspchance;

    unsigned int vmodmysp3;   //properties

    unsigned short vmodmysp3myspparam;
    short vmodmysp3myspmin;

    short vmodmysp3myspmax;
    unsigned short vmodmysp3myspchance;

    unsigned int vmodmysp4;   //properties

    unsigned short vmodmysp4myspparam;
    short vmodmysp4myspmin;

    short vmodmysp4myspmax;
    unsigned short vmodmysp4myspchance;

    unsigned int vmodmysp5;   //properties

    unsigned short vmodmysp5myspparam;
    short vmodmysp5myspmin;

    short vmodmysp5myspmax;
    unsigned short vmodmysp5myspchance;

    unsigned char voutputmyspb[20];  //lvl��plvl��ilvl��������20��byte��

    unsigned int iPadding45;

    unsigned int vbmyspmodmysp1;   //properties

    unsigned short vbmyspmodmysp1myspparam;
    short vbmyspmodmysp1myspmin;

    short vbmyspmodmysp1myspmax;
    unsigned short vbmyspmodmysp1myspchance;

    unsigned int vbmyspmodmysp2;   //properties

    unsigned short vbmyspmodmysp2myspparam;
    short vbmyspmodmysp2myspmin;

    short vbmyspmodmysp2myspmax;
    unsigned short vbmyspmodmysp2myspchance;

    unsigned int vbmyspmodmysp3;   //properties

    unsigned short vbmyspmodmysp3myspparam;
    short vbmyspmodmysp3myspmin;

    short vbmyspmodmysp3myspmax;
    unsigned short vbmyspmodmysp3myspchance;

    unsigned int vbmyspmodmysp4;   //properties

    unsigned short vbmyspmodmysp4myspparam;
    short vbmyspmodmysp4myspmin;

    short vbmyspmodmysp4myspmax;
    unsigned short vbmyspmodmysp4myspchance;

    unsigned int vbmyspmodmysp5;   //properties

    unsigned short vbmyspmodmysp5myspparam;
    short vbmyspmodmysp5myspmin;

    short vbmyspmodmysp5myspmax;
    unsigned short vbmyspmodmysp5myspchance;

    unsigned char voutputmyspc[20];  //lvl��plvl��ilvl��������20��byte��

    unsigned int iPadding66;

    unsigned int vcmyspmodmysp1;   //properties

    unsigned short vcmyspmodmysp1myspparam;
    short vcmyspmodmysp1myspmin;

    short vcmyspmodmysp1myspmax;
    unsigned short vcmyspmodmysp1myspchance;

    unsigned int vcmyspmodmysp2;   //properties

    unsigned short vcmyspmodmysp2myspparam;
    short vcmyspmodmysp2myspmin;

    short vcmyspmodmysp2myspmax;
    unsigned short vcmyspmodmysp2myspchance;

    unsigned int vcmyspmodmysp3;   //properties

    unsigned short vcmyspmodmysp3myspparam;
    short vcmyspmodmysp3myspmin;

    short vcmyspmodmysp3myspmax;
    unsigned short vcmyspmodmysp3myspchance;

    unsigned int vcmyspmodmysp4;   //properties

    unsigned short vcmyspmodmysp4myspparam;
    short vcmyspmodmysp4myspmin;

    short vcmyspmodmysp4myspmax;
    unsigned short vcmyspmodmysp4myspchance;

    unsigned int vcmyspmodmysp5;   //properties

    unsigned short vcmyspmodmysp5myspparam;
    short vcmyspmodmysp5myspmin;

    short vcmyspmodmysp5myspmax;
    unsigned short vcmyspmodmysp5myspchance;
} ST_LINE_INFO;

typedef struct
{
    unsigned int vmodmysp1;   //properties

    unsigned short vmodmysp1myspparam;
    short vmodmysp1myspmin;

    short vmodmysp1myspmax;
    unsigned short vmodmysp1myspchance;
} ST_CUBE_MOD;

static char *m_apcInternalProcess[] =
{
    "description",
    "lvl",
    "b lvl",
    "c lvl",
    "plvl",
    "b plvl",
    "c plvl",
    "ilvl",
    "b ilvl",
    "c ilvl",
    "*eol",
    NULL,
};

static unsigned char m_iCubeLvl = 0;
static unsigned char m_iCubepLvl = 0;
static unsigned char m_iCubeiLvl = 0;

static char *Cubemain_GenerateInputProp(char *acOutput, unsigned char bType, unsigned char bPrefix,
    unsigned short wIndex, unsigned char bPostFix, unsigned char bQty)
{
    if ( 0 != (1 & bPrefix ) )
    {
        strcpy(acOutput, ",bas");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (2 & bPrefix ) )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (4 & bPrefix ) )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( 1 == bPostFix )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( 2 == bPostFix )
    {
        strcpy(acOutput, ",nor");
        acOutput += strlen(acOutput);
    }

    if ( 3 == bPostFix )
    {
        strcpy(acOutput, ",hiq");
        acOutput += strlen(acOutput);
    }

    if ( 4 == bPostFix )
    {
        strcpy(acOutput, ",mag");
        acOutput += strlen(acOutput);
    }

    if ( 5 == bPostFix )
    {
        strcpy(acOutput, ",set");
        acOutput += strlen(acOutput);
    }

    if ( 6 == bPostFix )
    {
        strcpy(acOutput, ",rar");
        acOutput += strlen(acOutput);
    }

    if ( 7 == bPostFix )
    {
        strcpy(acOutput, ",uni");
        acOutput += strlen(acOutput);
    }

    if ( 8 == bPostFix )
    {
        strcpy(acOutput, ",crf");
        acOutput += strlen(acOutput);
    }

    if ( 9 == bPostFix )
    {
        strcpy(acOutput, ",tmp");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (8 & bType) )
    {
        strcpy(acOutput, ",sock");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (4 & bType) )
    {
        strcpy(acOutput, ",nos");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x10 & bType) )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x20 & bType) )
    {
        strcpy(acOutput, ",noe");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x80 & bType) )
    {
        strcpy(acOutput, ",upg");
        acOutput += strlen(acOutput);
    }

    if ( 0 < bQty )
    {
        sprintf(acOutput, ",qty=%d", bQty);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}

static char *Cubemain_GenerateOutputProp(char *acOutput, unsigned char bType, unsigned char bPrefix1, unsigned char bPrefix2,
    unsigned short wIndex, unsigned char bPostFix, unsigned char bQty, unsigned short wPre, unsigned short wSur)
{
    if ( 0 != (0x04 & bPrefix1 ) )
    {
        strcpy(acOutput, ",eth");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x02 & bPrefix1 ) )
    {
        sprintf(acOutput, ",sock=%d", bQty);
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x01 & bPrefix1 ) )
    {
        strcpy(acOutput, ",mod");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x80 & bPrefix1 ) )
    {
        strcpy(acOutput, ",exc");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x10 & bPrefix1 ) )
    {
        strcpy(acOutput, ",uns");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x20 & bPrefix1 ) )
    {
        strcpy(acOutput, ",rem");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x01 & bPrefix2 ) )
    {
        strcpy(acOutput, ",eli");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x02 & bPrefix2 ) )
    {
        strcpy(acOutput, ",rep");
        acOutput += strlen(acOutput);
    }

    if ( 0 != (0x04 & bPrefix2 ) )
    {
        strcpy(acOutput, ",rch");
        acOutput += strlen(acOutput);
    }

    if ( 1 == bPostFix )
    {
        strcpy(acOutput, ",low");
        acOutput += strlen(acOutput);
    }

    if ( 2 == bPostFix )
    {
        strcpy(acOutput, ",nor");
        acOutput += strlen(acOutput);
    }

    if ( 3 == bPostFix )
    {
        strcpy(acOutput, ",hiq");
        acOutput += strlen(acOutput);
    }

    if ( 4 == bPostFix )
    {
        strcpy(acOutput, ",mag");
        acOutput += strlen(acOutput);
    }

    if ( 5 == bPostFix )
    {
        strcpy(acOutput, ",set");
        acOutput += strlen(acOutput);
    }

    if ( 6 == bPostFix )
    {
        strcpy(acOutput, ",rar");
        acOutput += strlen(acOutput);
    }

    if ( 7 == bPostFix )
    {
        strcpy(acOutput, ",uni");
        acOutput += strlen(acOutput);
    }

    if ( 8 == bPostFix )
    {
        strcpy(acOutput, ",crf");
        acOutput += strlen(acOutput);
    }

    if ( 9 == bPostFix )
    {
        strcpy(acOutput, ",tmp");
        acOutput += strlen(acOutput);
    }

    if ( 0 < wPre )
    {
        sprintf(acOutput, ",pre=%d", wPre);
        acOutput += strlen(acOutput);
    }

    if ( 0 < wSur )
    {
        sprintf(acOutput, ",suf=%d", wSur);
        acOutput += strlen(acOutput);
    }

    if ( 0 == (0x02 & bPrefix1 ) && 0 < bQty )
    {
        sprintf(acOutput, ",qty=%d", bQty);
        acOutput += strlen(acOutput);
    }

    return acOutput;
}

static int Cubemain_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
/*
struct D2CubeInputItem
{
   BYTE nInputFlags;               //0x00
   BYTE nItemType;                  //0x01
   WORD wItem;                     //0x02
   WORD wItemID;                  //0x04
   BYTE nQuality;                  //0x06
   BYTE nQuantity;                  //0x07
};


struct D2CubeOutputItem
{
   BYTE nItemFlags;               //0x00
   BYTE nItemType;                  //0x01
   WORD wItem;                     //0x02
   WORD wItemID;                  //0x04
   BYTE nQuality;                  //0x06
   BYTE nQuantity;                  //0x07
   BYTE nType;                     //0x08
   BYTE nLvl;                     //0x09
   BYTE nPLvl;                     //0x0A
   BYTE nILvl;                     //0x0B
   WORD wPrefixId;                  //0x0C
   WORD unk0x0E;                  //0x0E
   WORD unk0x10;                  //0x10
   WORD wSuffixId;                  //0x12
   DWORD unk0x14;                  //0x14
   struct 
   {               
      DWORD   dwMod;         //0x00
      WORD   wModParam;      //0x04
      WORD   wModMin;      //0x06
      WORD   wModMax;      //0x08
      WORD   wModChance;      //0x0A
   } sMods[5];                   //0x18   
};
*/
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    char *pcOutput = acOutput;
    int id;
    int result = 0;

    if ( !strcmp(acKey, "class") )
    {
        pcResult = PlayerClass_GetClass(pstLineInfo->vclass);
        if ( pcResult )
        {
            strcpy(pcOutput, pcResult);
        }
        else
        {
            pcOutput[0] = 0;
        }
        result = 1;
    }
    else if ( strlen("mod 1") == strlen(acKey) && 1 == sscanf(acKey, "mod %d", &id) )
    {
        ST_CUBE_MOD *psSkill = (ST_CUBE_MOD *)&pstLineInfo->vmodmysp1;
        pcResult = Properties_GetProperty(psSkill[id-1].vmodmysp1);
        if ( pcResult )
        {
            strcpy(pcOutput, pcResult);
        }
        else
        {
            pcOutput[0] = 0;
        }
        result = 1;
    }
    else if ( strlen("b mod 1") == strlen(acKey) && 1 == sscanf(acKey, "b mod %d", &id) )
    {
        ST_CUBE_MOD *psSkill = (ST_CUBE_MOD *)&pstLineInfo->vbmyspmodmysp1;
        pcResult = Properties_GetProperty(psSkill[id-1].vmodmysp1);
        if ( pcResult )
        {
            strcpy(pcOutput, pcResult);
        }
        else
        {
            pcOutput[0] = 0;
        }
        result = 1;
    }
    else if ( strlen("c mod 1") == strlen(acKey) && 1 == sscanf(acKey, "c mod %d", &id) )
    {
        ST_CUBE_MOD *psSkill = (ST_CUBE_MOD *)&pstLineInfo->vcmyspmodmysp1;
        pcResult = Properties_GetProperty(psSkill[id-1].vmodmysp1);
        if ( pcResult )
        {
            strcpy(pcOutput, pcResult);
        }
        else
        {
            pcOutput[0] = 0;
        }
        result = 1;
    }
    else if ( 1 == sscanf(acKey, "input %d", &id) )
    {
        unsigned char *pcInput = pstLineInfo->vinputmysp1 + (id - 1) * sizeof(pstLineInfo->vinputmysp1);
        unsigned char bType = pcInput[0];
        unsigned char bPrefix = pcInput[1];
        unsigned short wIndex = *(unsigned short *)(&pcInput[2]);
        unsigned char bPostFix = pcInput[6];
        unsigned char bQty = pcInput[7];

        if ( 0 != (1 & bType) )
        {
            //weapon��armor��misc
#if 0
            if ( 0x41 == bType && (pcResult = Misc_GetItemUniqueCode(wIndex)) && !strcmp("rin", pcResult)
                && 7 == bPostFix && 0x7B == pcInput[4] )
            {
                strcpy(pcOutput, "The Stone of Jordan");
                result = 1;
            }
#else
            if ( 0 != (0x40 & bType) )
            {
                if ( 7 == bPostFix )
                {
                    pcResult = UniqueItems_GetItemUniqueCode(*(unsigned short *)(&pcInput[4]));
                }
                else if ( 5 == bPostFix )
                {
                    pcResult = SetItems_GetItemUniqueCode(*(unsigned short *)(&pcInput[4]));
                }
                if ( pcResult )
                {
                    strcpy(pcOutput, pcResult);
                }
                result = 1;
            }
#endif
            else if ( 1 == bType && 0 == bPrefix && 0 == bPostFix && 0== bQty )
            {
                if ( 0xFFFF == wIndex )
                {
                    strcpy(pcOutput, "any");
                }
                else
                {
                    pcResult = Misc_GetItemUniqueCode(wIndex);
                    if ( pcResult )
                    {
                        strcpy(pcOutput, pcResult);
                    }
                }
                result = 1;
            }
            else
            {
                pcOutput[0] = '"';
                pcOutput++;

                if ( 0xFFFF == wIndex )
                {
                    strcpy(pcOutput, "any");
                    pcOutput += strlen(pcOutput);
                    pcOutput = Cubemain_GenerateInputProp(pcOutput, bType, bPrefix, wIndex, bPostFix, bQty);
                }
                else
                {
                    pcResult = Misc_GetItemUniqueCode(wIndex);
                    if ( pcResult )
                    {
                        strcpy(pcOutput, pcResult);
                        pcOutput += strlen(pcOutput);
                        pcOutput = Cubemain_GenerateInputProp(pcOutput, bType, bPrefix, wIndex, bPostFix, bQty);
                    }
                }

                pcOutput[0] = '"';
                pcOutput++;

                result = 1;
            }
        }
        else if ( 0 != (2 & bType) )
        {
            //itemtypes
            if ( 2 == bType && 0 == bPrefix && 0 == bPostFix && 0== bQty )
            {
                if ( 0xFFFF == wIndex )
                {
                    strcpy(pcOutput, "any");
                }
                else
                {
                    pcResult = ItemTypes_GetItemCode(wIndex);
                    if ( pcResult )
                    {
                        strcpy(pcOutput, pcResult);
                    }
                }
                result = 1;
            }
            else
            {
                pcOutput[0] = '"';
                pcOutput++;

                if ( 0xFFFF == wIndex )
                {
                    strcpy(pcOutput, "any");
                    pcOutput += strlen(pcOutput);
                    pcOutput = Cubemain_GenerateInputProp(pcOutput, bType, bPrefix, wIndex, bPostFix, bQty);
                }
                else
                {
                    pcResult = ItemTypes_GetItemCode(wIndex);
                    if ( pcResult )
                    {
                        strcpy(pcOutput, pcResult);
                        pcOutput += strlen(pcOutput);
                        pcOutput = Cubemain_GenerateInputProp(pcOutput, bType, bPrefix, wIndex, bPostFix, bQty);
                    }
                }

                pcOutput[0] = '"';
                pcOutput++;

                result = 1;
            }
        }

        if ( 0 == result )
        {
            result = 1;
        }
    }
    else if ( !strncmp(acKey, "output", strlen("output")) )
    {
        unsigned char *pcInput;
        unsigned char bPrefix1;
        unsigned char bPrefix2;
        unsigned short wIndex;
        unsigned char bPostFix;
        unsigned char bQty;
        unsigned char bType; 
        unsigned short wPre ;
        unsigned short wSur ;

        if ( !strcmp("output b", acKey) )
        {
            pcInput = pstLineInfo->voutputmyspb;
        }
        else if ( !strcmp("output c", acKey) )
        {
            pcInput = pstLineInfo->voutputmyspc;
        }
        else
        {
            pcInput = pstLineInfo->voutput;
        }

        bPrefix1 = pcInput[0];
        bPrefix2 = pcInput[1];
        wIndex = *(unsigned short *)(&pcInput[2]);
        bPostFix = pcInput[6];
        bQty = pcInput[7];
        bType = pcInput[8];
        wPre = *(unsigned short *)(&pcInput[12]);
        wSur = *(unsigned short *)(&pcInput[18]);

        m_iCubeLvl = pcInput[9];
        m_iCubepLvl = pcInput[10];
        m_iCubeiLvl = pcInput[11];

#if 0
        if ( 0x08 == bPrefix1 && 0 == bPrefix2 && (pcResult = Misc_GetItemUniqueCode(wIndex)) && !strcmp("rin", pcResult)
            && 7 == bPostFix && 0x7B == pcInput[4] )
        {
            strcpy(pcOutput, "The Stone of Jordan");
            result = 1;
        }
#else
        if ( 0x08 == bPrefix1 && 0 == bPrefix2 )
        {
            if ( 7 == bPostFix )
            {
                pcResult = UniqueItems_GetItemUniqueCode(*(unsigned short *)(&pcInput[4]));
            }
            else if ( 5 == bPostFix )
            {
                pcResult = SetItems_GetItemUniqueCode(*(unsigned short *)(&pcInput[4]));
            }
            if ( pcResult )
            {
                strcpy(pcOutput, pcResult);
            }
            result = 1;
        }
#endif
        else if ( 0 == bPrefix1 && 0 == bPrefix2 && 0 == bPostFix && 0== bQty && 0 == wPre && 0 == wSur )
        {
            if ( 0xFF == bType )
            {
                strcpy(pcOutput, "usetype");
            }
            else if ( 0xFE == bType )
            {
                strcpy(pcOutput, "useitem");
            }
            else if ( 1 == bType )
            {
                strcpy(pcOutput, "Cow Portal");
            }
            else if ( 2 == bType )
            {
                strcpy(pcOutput, "Pandemonium Portal");
            }
            else if ( 3 == bType )
            {
                strcpy(pcOutput, "Pandemonium Finale Portal");
            }
            else if ( 0xFD == bType )
            {
                pcResult = ItemTypes_GetItemCode(wIndex);
                if ( pcResult )
                {
                    strcpy(pcOutput, pcResult);
                }
            }
            else if ( 0xFC == bType )
            {
                pcResult = Misc_GetItemUniqueCode(wIndex);
                if ( pcResult )
                {
                    strcpy(pcOutput, pcResult);
                }
            }
            result = 1;
        }
        else
        {
            pcOutput[0] = '"';
            pcOutput++;
        
            if ( 0xFF == bType )
            {
                strcpy(pcOutput, "usetype");
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateOutputProp(pcOutput, bType, bPrefix1, bPrefix2, wIndex, bPostFix, bQty, wPre, wSur);
            }
            else if ( 0xFE == bType )
            {
                strcpy(pcOutput, "useitem");
                pcOutput += strlen(pcOutput);
                pcOutput = Cubemain_GenerateOutputProp(pcOutput, bType, bPrefix1, bPrefix2, wIndex, bPostFix, bQty, wPre, wSur);
            }
            else if ( 1 == bType )
            {
                strcpy(pcOutput, "Cow Portal");
            }
            else if ( 2 == bType )
            {
                strcpy(pcOutput, "Pandemonium Portal");
            }
            else if ( 3 == bType )
            {
                strcpy(pcOutput, "Pandemonium Finale Portal");
            }
            else if ( 0xFD == bType )
            {
                pcResult = ItemTypes_GetItemCode(wIndex);
                if ( pcResult )
                {
                    strcpy(pcOutput, pcResult);
                    pcOutput += strlen(pcOutput);
                    pcOutput = Cubemain_GenerateOutputProp(pcOutput, bType, bPrefix1, bPrefix2, wIndex, bPostFix, bQty, wPre, wSur);
                }
            }
            else if ( 0xFC == bType )
            {
                pcResult = Misc_GetItemUniqueCode(wIndex);
                if ( pcResult )
                {
                    strcpy(pcOutput, pcResult);
                    pcOutput += strlen(pcOutput);
                    pcOutput = Cubemain_GenerateOutputProp(pcOutput, bType, bPrefix1, bPrefix2, wIndex, bPostFix, bQty, wPre, wSur);
                }
            }

            pcOutput[0] = '"';
            pcOutput++;

            result = 1;
        }

        if ( !strcmp(acKey, "output") && (0 == strlen(acOutput) || !strcmp(acOutput, "\"\"")) )
        {
            strcpy(acOutput, "void");
        }

        if ( 0 == result )
        {
            result = 1;
        }
    }

    return result;
}

static int Cubemain_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    int result = 0;

    if ( !strcmp("description", acKey) )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, iLineNo);
        }

        result = 1;
    }
    else if ( !strcmp("lvl", acKey) || !strcmp("b lvl", acKey) || !strcmp("c lvl", acKey) )
    {
        if ( 0 == m_iCubeLvl )
        {
            acOutput[0] = 0;
        }
        else
        {
            sprintf(acOutput, "%d", m_iCubeLvl);
        }
        result = 1;
    }
    else if ( !strcmp("plvl", acKey) || !strcmp("b plvl", acKey) || !strcmp("c plvl", acKey) )
    {
        if ( 0 == m_iCubepLvl )
        {
            acOutput[0] = 0;
        }
        else
        {
            sprintf(acOutput, "%d", m_iCubepLvl);
        }
        result = 1;
    }
    else if ( !strcmp("ilvl", acKey) || !strcmp("b ilvl", acKey) || !strcmp("c ilvl", acKey) )
    {
        if ( 0 == m_iCubeiLvl )
        {
            acOutput[0] = 0;
        }
        else
        {
            sprintf(acOutput, "%d", m_iCubeiLvl);
        }
        result = 1;
    }
    else if ( !strcmp(acKey, "*eol") )
    {
        acOutput[0] = '0';
        acOutput[1] = 0;

        return 1;
    }

    return result;
}

int process_cubemain(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, enabled, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ladder, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, minmyspdiff, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, class, UCHAR);   //playerclass

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, op, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, param, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, value, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, numinputs, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, version, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp1, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp2, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp3, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp4, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp5, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp6, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, inputmysp7, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, output, STRING);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, modmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspb, STRING);  //lvl��plvl��ilvl��������20��byte��

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, bmyspmodmysp5myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, outputmyspc, STRING);  //lvl��plvl��ilvl��������20��byte��

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp1myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp2myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp3myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp4myspchance, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5, UINT);   //properties

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspparam, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmin, SHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspmax, SHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cmyspmodmysp5myspchance, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(playerclass, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(properties, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(misc, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(uniqueitems, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(setitems, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = Cubemain_ConvertValue;
            m_stCallback.pfnFieldProc = Cubemain_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

/*
Title Cubemain.txt Code Reference (v1.09x) 
Description by Nefarius 
Sent by  

--------------------------------------------------------------------------------
 
This resource originally appeared as a thread in the Phrozen Forums and we would also like to thank Sir_General, Myhrginoc and Ruvanal for their contributions to the list. 
item quality params
nor=normal
hiq=superior
eth=ethereal
rar=rare
mag=magic
uni=unique
set=set
crf=crafted
low=low quality
any=any item


others
noe=not ethereal
nos=no socket (for input)
sock=#sockets (eg: sock=4)
pre=prefix (row # -2 from magicprefix)
suf=suffix (row # -2 from magicsuffix)
usetype=uses base type of input1 for output
useitem=uses item from input 1
qty=amount of same item (eg: hpot,qty=3 means 3 hp potions)
upg=upgrades item normal>exceptional>elite 

For additional information, an abbreviated replica of the aforementioned thread has been provided below: 





--------------------------------------------------------------------------------

NefariusDX:
item quality params:
nor=normal
hiq=superior
eth=ethereal
rar=rare
mag=magic
uni=unique
set=set
crf=crafted
low=low quality
any=any item
others
noe=not ethereal
nos=no socket (for input)
sock=#sockets (eg: sock=4)
pre=prefix (row # -2 from magicprefix)
suf=suffix (row # -2 from magicsuffix)
usetype=uses base type of input1 for output
useitem=uses item from input 1
qty=amount of same item (eg: hpot,qty=3 means 3 hp potions)
upg=upgrades item normal>exceptional>elite 

Defeater:
dont forget to add "'s when you use params 

NefariusDX:
params are used like this no ' its ,
eg. uar,set,eth,sock=1 would create a set sacred armor which is ethereal and had one socket 

dectgap:
Would you really be able to create a ethereal set item, or was it just an example? I have never got the ethereal part working anyway...


NefariusDX:
the order is important (how ever sets can never spawn as ethereal) blizzard did this since if u would have 1 ethereal set item u would need to have all the other parts of that set as ethereal to in order to complete it how ever try it this way xh9,uni,
eth,sock=1 will create a ethereal socket vamp gaze (make the level for the stuff match!) now xh9,sock=1,eth,uni would not work to my knowledge the code must be ORDERED 

ShadowTalon:
what i would like to know is all the output formulas for cubemain such as the formulas that Sir_General uses on his rune mod i know you can add prefixes to items ,but i want to know if you can add the properties of the rune or gem in my case without 
typing up a **** load of new prefixes and suffixes so they would work the way i wanted them to 

NefariusDX:
i didnt understand ur q, if u mean having them "built in" to a item u just make a crafted item 

Sir_General:
If you type "useitem" in the output column and then put some stuff 
in the mod1, mod2, etc. columns you'll get the same item you put in, 
only with the added attributes in the mod1, mod2, etc. columns. 

ShadowTalon:
thx Sir_General, thats exactly what i wanted to hear 

Myhrginoc:
One more output code for your list, "hiq" to make an item superior. And it gets the random affixes that go with superior grade. If "hiq" doesn't work by itself, use "nor,hiq". 

NefariusDX:
thx Myhrginoc, if there is a hiq code then maybe there is a nor,low or loq 

Ruvanal:
Yes, there is 'low' quality mod. edit: Do not use with the 'nor' mod because you would be trying to apply 2 different quality levels to an item. I can't rember for sure but I think there is a 'noe' mod for 'not ethereal'. I need to try checking a lot of 
scattered notes to see if there are any other odd ones out there. 

NefariusDX:
tell me when your sure these are correct ill add em for now 

Ruvanal:
Double-checked the lists that I have. The 'noe' is for 'not ethereal' and is normally used on the input tests. I only see 2 other that you did not have in your list 'any' and 'upg'. From the various reports that I have heard from other I cannot 
recommend using the 'any' modifier as it usually causes more problems than it will help with. The 'upg' is for 'upgrade' and is used on the inputs to allow the upgrade forms of a specific item to be used also (e.g. an input of mbt,mag,upg would allow 
the mag Chain boots, mag Mesh boots or mag Boneweave boots to be used as valid inputs). Also a note on the outputs. If you don't specify a quality type (low, nor, hiq, mag, rar, crf, set, uni) then the game will spawn the item similar to an item drop 
and you can get an unplanned magical quality level. I do not know if the magic find you are equipped with will effect this type of drop or not. I ran into this when I was trying to test something and neglected to put a 'nor' quality in the output line 
and ended up with an ethereal magical version of what I was trying to test (I did not want either attribute and had to start the test run over again). Also a note on the 'sock=#' output code for those that are not aware of it. When this is used in the 
output column, you will be limited in the number of sockets as specified by the item, the ilvl (using the MaxSockX columns from itemtypes.txt) and the max sockets based on the magical quality of the item (magic MaxSock=3; set, rare, crafted and unique 
will get a MaxSock=1). If you need to exceed this amount you will need to put the socket value in one of the sets on mod columns instead (you still will not be able to exceed the values for the item and the itemtype limits). If your output code 
specifies a condition that is not possible for then the formula will not work in that case. Example: input code weap with an out put code of usetype,nor,sock=6, using a sword would work, but if you used a javelin then the formula would be non-functional 
(assuming you have not enabled sockets on this type of item). This type of problem is probably what has caused a lot of difficulties when modders are trying to use 'any' code. 

NefariusDX:
i didnt add any due to that reason
i didnt know about the other 1 though for upgrade

nor ��ͨ��Ʒ(��ɫ)
hiq ��ǿ��Ʒ
low ������Ʒ
mag ��ɫ��Ʒ
rar ��ɫ��Ʒ
uni ������Ʒ
set ��ɫ��Ʒ
tmp ������Ʒ
crf ��ɫ��Ʒ
bas ������Ʒ
exc ��չ��Ʒ
eli ������Ʒ
pre ��Ʒǰ׺��һ���Ӧafj sheet�򿪵�ǰ���Ǹ�����2��
suf ��Ʒ��׺��һ���Ӧafj sheet�򿪵�ǰ���Ǹ�����2��
sock ��
qty ��Ʒ����
nos �޿�
uns ������Ƕ��
rem ��Ƕ��
usetype ͬ������Ʒ
useitem ԭ��Ʒ

���루Input����
any item any
magic mag (rin,mag)
rare rar
unique unq
crafted crf 
normal nor
no socket nos
item nums qty=? (r01,qty=3)
baseitem bas 
exceptionalitem exc 
socket sock=?
���⻹��upg,low,hiq,tmp�ȣ�upgֻ���ֹ���Ʒ��ʽ�г��֡�tmp��1.10���³��ֵ���Ʒ���ͣ�δ���ţ�����һ�ְ���ɫ�Ĵ�rar��Ʒǰ��׺�����ͣ���Ŀǰ�ϳ��������κ����ԡ�

3���ϳ���Output����
usetype ��Ʒ���rar/mag/uni/crf/set/tmp/nor�ȣ�
useitem ������Ʒ�������Ͳ����������sock=?/uns/mod/exc/eli/bas�ȡ���Ӧ���������õ��ˣ������ڲ��ı���Ʒ�������Ե��������������ԣ������ף���useitem,sock=6��
������Щ��Ʒ���ض���ֵ�޶�����suf=162��Щ��ʹ�õĻ����С���ɲ��ÿ��ǡ�
��Ҫע����ǣ�������Ʒ�ķ�Χ�趨Խ�󣬹�ʽ�������Խ����������������п��ܾ���һ��С�������һ��Ҫ�����顣���������� (any,mag)֮���д����


*/

