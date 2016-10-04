#include "global.h"

#define FILE_PREFIX "npc"

/*
NPC.TXT File Guide

By Nefarius (in part based on Phrozen Heart & Mordini's guide)

The old guide is not very accurate when it comes to how the various columns interact, I hope this one will clear the shroud.




npc: an ID pointer to that NPCs row in monstats.txt, do not change this name, otherwise you will recieve an assertion error as soon as you open that vendors inventory.


buy mult: percentage of the items base price to use when it is bought by the NPC. This does not refer to the prices listed in armor, weapons or misc, it refers to the actual base price, that is, after all stat related boosts have been applied. This 
column holds a fraction of 1024, thus 512/1024 would be equal to 50%, lets say we have Cleglaw's Tooth, its actual price is 4027 gold, if we set this column to 1024 that is what we will recieve for selling it to an NPC, if we set this column to 512 we 
will recieve floor(price/1024*value) aka 2013 gold.


sell mult: this follows the same principle as the above, however this controls the price when you buy something from an NPC.


rep mult: this column controls the base price used as the basis of the item repair calculation, it follows the same principle as the two other columns above. But this does not control the actual repair price. How does the game do it then? First of all 
the base repair price is established using the same formula as for the other columns, namely floor(price/1024*value), now lets take Cleglaw's Tooth again for our example, if you set this column to 1024 then a full repair (when the item has 0 durability 
left), will cost 4027 gold, the full price of the item. Should it have 22/44 durability, you rather pay 2013 gold. Thus the whole repair calculation is basically: cost*(1-current_dur/maximum_dur). The recharge cost is added on top of the durability 
repair calculation. Note that the recharge cost is not controlled by this field, the parameters for this calc are spread throughout the games code and skills.txt.


questflag A, B and C: this controls the quest flag that must be checked in order for the following price alterations to take place.


questbuymult A, B and C: this controls the percentage the percentage indicated in the buy mult column is modified, lets say buy mult contains 512, if we put 1024 in questbuymult A the item will _not_ be sold at any different price, since we tell the 
game to use 100% of 50%, which quite clearly is 50%. Thus the Cleglaw's Tooth will be bought for 2013 gold, irregardless of the quest, but what if we set this column to 2048? Well, then we will recieve 4027 gold when we sell it to the npc, since we are 
telling the game to use 200% of 50%, which is 100%. Finally, if we set this column to 512 then we will recieve an item that costs 1006 gold, since we are now using 50% of 50%, which is 25%. The subsequent columns, questbuymult B and questbuymult C stack 
with this one, they do not replace it. So, to clear up the mess I just wrote:

base price = GLD
buy mult = BM
questbuymult = QBM1
questbuymult = QBM2
questbuymult = QBM3

floor( GLD / 1024 * BM / 1024 * QGM1 / 1024 * QGM2 / 1024 * QMG3 ) = actual price

So if we again use the example item from above, GLD=4027. Lets say BM=512 and QBM1-3 are all 2048, then we get: 16108 gold.



questsellmult A, B and C: the same as the above, only that this applies when you buy something from an NPC.


questrepmult A, B and C: again as the above, however this controls the alteration of the base repair price.


max buy, (N) and (H): the maximum amount of gold this NPC will ever pay you for an item you sell on the respective difficulty, the maximum is 2147483647.





Other facts

NPCs will never use values below 1 gold, thus an item that is worth 0 gold will still be bought for 1 gold and sold for 1 gold. This does not apply to gambling, where prices above the maximum result in free gambles. Prices above 2147483647 either as 
result of stats, base price in a file or the NPC calculation itself will be treated as 1.

The buy-price of some items will be off the sell-price by about 10% irregardless of NPC.txt, I haven't quite understood why this happens yet.

Selling price is not influenced by the amount of durability, it used to be like that early on.

*/

/*
Npc.txt�ļ�������

npc : NPC�����֣�

buy mult : NPC��������й�����Ʒ�ļ۸������

sell mult : NPC����ҳ�����Ʒ�ļ۸������

rep mult : NPC�޸������Ʒ�ļ۸������

questflag A : ���������NPC��ָ���������ʹ��NPC�ļ۸������������������˵����9�������ֵ�ͱ�ʾ�����ACT2��Q1��NPC����۸���������˵�����

questbuymult A : ����ض������NPC��������й�����Ʒ�ļ۸������

questsellmult A : ����ض������NPC����ҳ�����Ʒ�ļ۸������

questreplmult A : ����ض������NPC�޸������Ʒ�ļ۸������

questflag B : ���������NPC��ָ�������񣨵ڶ������񣩶�ʹ��NPC�ļ۸��������������

questbuymult B : ����ض����񣨵ڶ������񣩺�NPC��������й�����Ʒ�ļ۸������

questsellmult B : ����ض����񣨵ڶ������񣩺�NPC����ҳ�����Ʒ�ļ۸������

questreplmult B : ����ض����񣨵ڶ������񣩺�NPC�޸������Ʒ�ļ۸������

questflag C : ���������NPC��ָ�������񣨵��������񣩶�ʹ��NPC�ļ۸��������������

questbuymult C : ����ض����񣨵��������񣩺�NPC��������й�����Ʒ�ļ۸������

questsellmult C : ����ض����񣨵��������񣩺�NPC����ҳ�����Ʒ�ļ۸������

questreplmult C : ����ض����񣨵��������񣩺�NPC�޸������Ʒ�ļ۸������

max buy : NPC�ڡ���ͨ�������¹��������Ʒ�ļ۸����ޣ�

max buy (N) : NPC�ڡ����Ρ������¹��������Ʒ�ļ۸����ޣ�

max buy (H) : NPC�ڡ������������¹��������Ʒ�ļ۸����ޡ�
*/

/*
�ļ���������
Npc������Ϸ��Ӧ�ö�֪������ʵ���˼�����ﵥָ���Գ��۶�����NPC��
���ļ����������Կ��Գ��۶�����NPC�����顣
���ļ��е�ÿһ�б�ʾһ��NPC��


�ظ�

    2¥
    2011-09-24 21:20

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-24 21:20

    �ٱ� |

    zqtjingzi
    С����
    12

npc����NPC�����֣�Ҳmonstats.txt������

buy mult���ڴ�NPC��������Ʒʱ�ļ۸����������b0��

sell mult���ڴ�NPC��������Ʒʱ�ļ۸����������c0��

rep mult���ڴ�NPC��������Ʒʱ�ļ۸����������r0��

questflag A���ĸ������Ӱ���NPC�ļ۸��������������A��

questbuymult A���������A���ڴ�NPC��������Ʒʱ�Ķ���۸����������bA��

questsellmult A���������A���ڴ�NPC��������Ʒʱ�Ķ���۸����������sA��

questreplmult A���������A���ڴ�NPC��������Ʒʱ�Ķ���۸����������rA��

questflag B�������ĸ������Ӱ���NPC�ļ۸��������������B��

questbuymult B���������B���ڴ�NPC��������Ʒʱ�Ķ���۸����������bB��

questsellmult B���������B���ڴ�NPC��������Ʒʱ�Ķ���۸����������sB��

questreplmult B���������B���ڴ�NPC��������Ʒʱ�Ķ���۸����������rB��

questflag C�������ĸ������Ӱ���NPC�ļ۸��������������C��

questbuymult C���������C���ڴ�NPC��������Ʒʱ�Ķ���۸����������bC��

questsellmult C���������C���ڴ�NPC��������Ʒʱ�Ķ���۸����������sC��

questreplmult C���������C���ڴ�NPC��������Ʒʱ�Ķ���۸����������rC��

max buy����ͨ�Ѷ����ڴ�NPC��������Ʒʱ����߼۸�

max buy (N)�������Ѷ����ڴ�NPC��������Ʒʱ����߼۸�

max buy (H)�������Ѷ����ڴ�NPC��������Ʒʱ����߼۸�


�ظ�

    4¥
    2011-09-24 21:21

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��1��
���ռ۸�ļ��㣺
����A��B��C����Ϊ0����
���ۼ۸� = ԭ��Ʒ�۸� * (b0 / 1024) * (bA / 1024) * (bB / 1024) * (bC / 1024) //����ʱ�����;ö�Ӱ�졣
����۸� = ԭ��Ʒ�۸� * (s0 / 1024) * (sA / 1024) * (sB / 1024) * (sC / 1024) //����ʱ�;öȶ�Ϊ��ֵ��
����۸� = ԭ��Ʒ�۸� * (��ȱʧ���;ö� / ���;ö�) * (r0 / 1024) * (rA / 1024) * (rB / 1024) * (rC / 1024)

���ۡ�������������ﶼΪ��ҡ�

ԭ��Ʒ�۸�����������ɣ�(1) ��Weapons.txt��Armor.txt��Misc.txt�����ĵײļ۸�(2) ��ItemStatCost.txt���������Լ۸�


�ظ�

    5¥
    2011-09-24 21:21

    �ٱ� |

    zqtjingzi
    С����
    12

����˵��2��
��NPC�������Ĳ����һ�м۸�����Ϊ1����������ѵ���Ʒ��

*/

typedef struct
{
    unsigned int vnpc;  //monstats

    unsigned int vsellmyspmult;
    unsigned int vbuymyspmult;
    unsigned int vrepmyspmult;

    unsigned int vquestflagmyspA;
    unsigned int vquestflagmyspB;
    unsigned int vquestflagmyspC;

    unsigned int vquestsellmultmyspA;
    unsigned int vquestsellmultmyspB;
    unsigned int vquestsellmultmyspC;

    unsigned int vquestbuymultmyspA;
    unsigned int vquestbuymultmyspB;
    unsigned int vquestbuymultmyspC;

    unsigned int vquestrepmultmyspA;
    unsigned int vquestrepmultmyspB;
    unsigned int vquestrepmultmyspC;

    unsigned int vmaxmyspbuy;
    unsigned int vmaxmyspbuymyspmybr1Nmybr2;
    unsigned int vmaxmyspbuymyspmybr1Hmybr2;
} ST_LINE_INFO;

static int NPC_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "npc") )
    {
        pcResult = MonStats_GetStatsName(pstLineInfo->vnpc);
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

int process_npc(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, npc, UINT);  //monstats

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, buymyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, sellmyspmult, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, repmyspmult, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questflagmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questsellmultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questbuymultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspA, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspB, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, questrepmultmyspC, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuy, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuymyspmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, maxmyspbuymyspmybr1Hmybr2, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(monstats, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnConvertValue = NPC_ConvertValue;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        default:
            break;
    }

    return 1;
}

