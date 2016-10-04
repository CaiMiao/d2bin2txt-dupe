#include "global.h"

#define FILE_PREFIX "states"
#define NAME_PREFIX "st"

/*
state - the id pointer for this state, you would use this value in files such as skills.txt in those fields referring to states, for the state-property always use the id (line #)

id - for reference, this isn't compiled, the internal id corresponds always with the index in the txt file (ignoring the header and expansion lines).

group - you can group certain states together, this has the effect that they cannot stack (like the three cold armors of the sorceress). Beware as not all the code assigning states will care to check for this, if you use something exotic it will most 
likely produce glitches, if you stick to skills for state assignment it will work as intended.

remhit - whenever or not the state is dispelled when the unit takes a hit, due to the way this is coded it only applies to monsters, it wont be dispelled for players that get hit (not extensively tested, but code analysis sez so).

nosend - not yet analysed in detail

transform - whenever this state will transform the appearence of the unit (shape shift and holyshield).

aura - whenever or not this is an aura, aura states will not stack onscreen (ie the game cycles over active aura states), aura states are also dispelled when a monster is effected by conversion.

cureable - whenever or not an heal-enabled npc can remove this state (npcs automatically remove poisoning etc, hence those aren't checked) when you talk to them. (not verified)

curse - curse states cannot stack, the game will remove them when attempting to set a new state, it also controls whenever the duration of this state is reduced by the effects of the Cleansing aura and whenever curse resistance reduces it. Once a new 
curse state is applied the old one is removed.

active - whenever the state has a StateActiveFunc associated with it, StateActiveFuncs are actually the same as CltDoFuncs for skills. The active func is called every frame while the state is active.

immed - not yet analysed in detail.

restrict - whenever or not this state restricts skill usage (druid shapeshifts).

disguise - whenever this state make the game load another sprite for the unit (use in conjunction with transform).

blue - whenever this state applies a color change that overrides all others (such as from items).

attblue, dmgblue, armblue, rfblue, rlblue, rcblue, rpblue - these columns control whenever attack rating, damage, armor class, fire resistance, lightning resistance, cold resistance or poison resistance are displayed in blue color in the character stats 
screen.

stambarblue - whenever the stamina bar color is changed to blue (for stamina shrine). It does not control whenever you have infinite stamina (which you actually don't have, even with the shrine, it just gives you rediculous amounts of regen rate).

attred, dmgred, armred, rfred, rlred, rcred, rpred - these columns control whenever attack rating, damage, armor class, fire resistance, lightning resistance, cold resistance or poison resistance are displayed in red color in the character stats screen.

exp - when a unit effected by this state kills another unit, the summon owner will recieve experience (also when a unit with this state dies the summon owner also recieves experience, but not always due to some strange coding).

plrstaydeath, monstaydeath, bossstaydeath - whenever the state is removed when the unit dies (for players, monsters and special monsters). The last column will prevent bosses from shattering (from what I can tell).

hide - when the unit has died, the corpse and death anims will not be drawn.

shatter - whenever the unit shatters or explodes when it dies, this is heavily hardcoded, it will always use the ice shatter for all states other then STATE_UBERMINION.

udead - whenever this state prevents the corpse from being selected by spells and the ai.

life - when a state with this is active, it cancels out the native life regen of monsters. (using only the mod part instead of accr).

green - whenever this state applies a color change that overrides all others (such as from items). (see blue column, which seams to do the same).

pgsv - whenever this state is associated with progressive spells and will be looked up when the charges are triggered.

nooverlays - related to assigning overlays to the unit, not extensively researched yet.

noclear - like the previous column, also only used on states with the previous column enabled.

bossinv - whenever this state will use the minion owners inventory clientside (this is what makes the decoy always show up with your own equipment, even when you change what you wear after summoning one).

meleeonly - prevents druids that wield a bow or crossbow while shape shifted from firing missiles, and will rather attack in melee.

notondead - not researched yet

overlay1-4 - exact usage depends on the state and how the code accesses it, overlay1 however is the one you should generally be using.

pgoverlay - overlay shown on target of progressive skill when chargeup triggers.

castoverlay - overlay displayed when the state is applied initially (later replaced by overlay1 or whatever applicable by code).

removerlay - like castoverlay, just this one is displayed when the state expires.

stat - primary stat associated with the state, mostly used for display purposes (you should generally use skills.txt for assigning stats to states).

setfunc - clientside callback function invoked when the state is applied initially.

remfunc - clientside callback function invoked when the state expires or is otherwise removed.

missile - the missile that this state will utilize for certain events, how this is used depends entirely on the functions associated with the state.

skill - the skill that will be queried for this state in some sections of code, strangely enough this contradicts the fact states store their assigner skill anyway (via STAT_MODIFIERLIST_SKILL)

itemtype - what item type is effected by this states color change.

itemtrans - the color being applied to this item (only going to have an effect on alternate gfx, inventory gfx isn't effected).

colorpri - the color priority for this states color change, the, this can range from 0 to 255, the state with the highest color priority will always be used should more then one co-exist on the unit. If two states exist with the same priority the one 
with the lowest id is used (IIRC).

colorshift - index for the color shift palette picked from the *.PL2 files (see Paul Siramy's state color tool for info).

light-r, light-g, light-b - change the color of the light radius to what is indicated here, (only has an effect in D3D and glide of course).

onsound - sound played when the state is initially applied.

offsound - sound played when the state expires or is otherwise removed.

gfxtype - what unit type is used for the disguise gfx (1 being monsters, 2 being players, contratey to internal game logic).

gfxclass - the unit class used for disguise gfx, this corresponds with the index from monstats.txt and charstats.txt

cltevent - clientside event callback for this state (likely very inconsistent with the server side events, beware).

clteventfunc - callback function invoked when the client event triggers.

cltactivefunc - cltdofunc called every frame the state is active

srvactivefunc - srvdofunc called every frame the state is active

*/

/*
(A). state��״̬���ƣ�
(B). id��ID��ţ�����չ��
(C). group��״̬�顣����ͬһ��ļ���״̬�޷���ͬʱ���
(D). remhit������������Cloak of ShadowsΪ1(�����ʺܽӽ���InnerSightȴҲ�ǿ�)��
(E). nosend�������ڷ������˺Ϳͻ��˴�������ʱ�����á������Ϊ1���Ǳ������ܣ�����Bar������ϵȴ�ǿգ�
(F). transform���Ƿ��Ǳ��ε�״̬��
(G). aura��״̬�Ƿ���������ʽ���ã�
(H). curable����״̬�Ƿ���Ա����ƣ�
(I). curse��״̬�Ƿ������䷽ʽ���ã�
(J). active��״̬�Ƿ��и�����Ч��(?)��
(K). immed��״̬�Ƿ����������ã�
(L). restrict������״̬���Ƿ�����ʹ�ü��ܣ�
(M). disguise��״̬�Ƿ��ı�ͼ��Ч���������Ǻ�transformһ����ֵģ�����HolyShield��
(N). blue����״̬�Ƿ�ʹ�������߱����ɫ���������Ч����
(O). attblue����״̬�����������Ƿ���ʾΪ��ɫ��
(P). damblue����״̬���˺������Ƿ���ʾΪ��ɫ��
(Q). armblue����״̬�·��������Ƿ���ʾΪ��ɫ��
(R). rfblue����״̬�»��������Ƿ���ʾΪ��ɫ��
(S). rlblue����״̬�µ翹�������Ƿ���ʾΪ��ɫ��
(T). rcblue����״̬�±����������Ƿ���ʾΪ��ɫ��
(U). stambarblue����״̬���������Ƿ���ʾΪ��ɫ��
(V). rpblue����״̬�¶����������Ƿ���ʾΪ��ɫ��
(W). attred����״̬�����������Ƿ���ʾΪ��ɫ��
(X). damred����״̬���˺������Ƿ���ʾΪ��ɫ��
(Y). armred����״̬�·��������Ƿ���ʾΪ��ɫ��
(Z). rfred����״̬�»��������Ƿ���ʾΪ��ɫ��
(AA). rlred����״̬�µ翹�������Ƿ���ʾΪ��ɫ��
(AB). rcred����״̬�±����������Ƿ���ʾΪ��ɫ��
(AC). rpred����״̬�¶����������Ƿ���ʾΪ��ɫ��
(AD). exp����ת��ϵ���������á�����Ϊ1��ʱ�򣬱�ת���ĵ�λҲ��Ϊ��׬����ֵ��
(AE). plrstaydeath����ʬ���йء�Ҳ���ǵ���ɫ����ʱ�Կ��������õ�״̬��ʶ?
(AF). monstaydeath����ʬ���йء�Ҳ���Ƕ������Ĺ���/��ɫ�����õ�״̬��ʶ?
(AG). bossstaydeath����ʬ���йء�
(AH). hide��������������ͼ��? ����Decoy��ShadowWarrior/Master�⣬����"����"ʬ���Ч����
(AI). shatter����״̬�Ƿ�ʹ��������������ʱ�����飻
(AJ). udead����״̬�Ƿ�ȥ���������ߵ�ʬ��(�����޷�ѡ��������ʬ��?)��
(AK). life����״̬�Ƿ�Ӱ������ֵ(����Ӱ������ֵ���Զ��ָ�?)��
(AL). green�����·����������Ƿ�����ɫ��
(AM). pgsv����״̬�Ƿ��������õ�(������ʲô��˼)��
(AN). nooverlays��û��Overlays?
(AO). noclear������Bone Armor��Cyclone ArmorΪ1��
(AP). bossinv������DecoyΪ1��
(AQ). meleeonly����״̬����ʱ����ʹ�ý�������
(AR). notondead����ʬ���й�?
(AS��AV). overlay1��4����Overlay.txt�еĶ�Ӧ����ID��
(AW). pgsvoverlay����״̬��������ʱ��Ķ���ID��
(AX). castoverlay��������״̬ʱ��Ķ���ID��
(AY). removerlay��״̬����ʱ��Ķ���ID��
(AZ). stat���Ƿ�Ӱ���ɫ״̬��
(BA). setfunc��״̬����ʱ���õĺ�����
(BB). remfunc��״̬����ʱ���õĺ�����
(BC). missile��״̬����ʱ������Missile��
(BD). skill������״̬ʱʹ�õļ��ܣ�
(BE). itemtype����״̬����Ӱ�����Ʒ���ͣ�
(BF). itemtrans����״̬�������Ʒ��ɫ�仯��
(BG). colorpri����״̬�������Ʒ��ɫ�仯ǿ��(ɫ������ǰٷֱ�)��
(BH). colorshift����ɫ�仯�������ɫ(?)��
(BI). light-r��״̬�����Դ�仯�ĺ�ⲿ��(���߽����Ǻ�ɫ?)��
(BJ). light-g��״̬�����Դ�仯���̹ⲿ��(���߽�������ɫ?)��
(BK). light-b��״̬�����Դ�仯�����ⲿ��(���߽�������ɫ?)��
(BL). onsound��״̬��ʼʱ���ŵ�������
(BM). offsound��״̬����ʱ���ŵ�������
(BN). gfxtype������״̬��transform/disguise��Ϊ1��ʱ��(���ε�״̬)��ͨ������ָ��ʹ������ͼ�Σ�2��7����Ϸ��ɫ��1������(��������/��Ӷ��/NPC/��������ȵ�)��
(BO). gfxclass�����gfxtype=1����ô����ָ������ID(��monstats.txt���hcidx)�����gfxtype=2��ͨ������ָ����ɫID��
0 = Amazon ����ѷŮսʿ
1 = Sorceress Ů��ʦ
2 = Necromancer ������ʦ
3 = Paladin ʥ��ʿ
4 = Barbarian Ұ����
5 = Druid ��³��
6 = Assassin �̿�
(BP). cltevent���ڿͻ��˴���״̬���¼���
(BQ). clteventfunc���ͻ��˵��õĺ�����
(BR). cltactivefunc��״̬����ʱ�ͻ��˵��õĺ�����
(BS). srvactivefunc��״̬����ʱ�������˵��õĺ�����
(BT). eol���н�����־��0��
*/

typedef struct
{
    unsigned short vid;
    unsigned short voverlay1;   //overlay

    unsigned short voverlay2;   //overlay
    unsigned short voverlay3;   //overlay

    unsigned short voverlay4;   //overlay
    unsigned short vcastoverlay;   //overlay

    unsigned short vremoverlay;   //overlay
    unsigned short vpgsvoverlay;   //overlay

#if 1
    unsigned char vCombinedBits1;
    unsigned char vCombinedBits2;
    unsigned char vCombinedBits3;
    unsigned char vCombinedBits4;
    unsigned char vCombinedBits5;
#else
    unsigned char vdamblue : 1;
    unsigned char vremhit : 1;
    unsigned char vactive : 1;
    unsigned char vpgsv : 1;

    unsigned char vtransform : 1;
    unsigned char vhide : 1;
    unsigned char vaura : 1;
    unsigned char vnosend : 1;

    unsigned char vbossstaydeath : 1;
    unsigned char vmonstaydeath : 1;
    unsigned char vplrstaydeath : 1;
    unsigned char vcurable : 1;

    unsigned char vcurse : 1;
    unsigned char vattred : 1;
    unsigned char vattblue : 1;
    unsigned char vdamred : 1;

    unsigned char vrpblue : 1;
    unsigned char vrlblue : 1;
    unsigned char vrcblue : 1;
    unsigned char vrfblue : 1;

    unsigned char varmblue : 1;
    unsigned char vblue : 1;
    unsigned char vrestrict : 1;
    unsigned char vdisguise : 1;

    unsigned char vshatter : 1;
    unsigned char vexp : 1;
    unsigned char vrpred : 1;
    unsigned char vrlred : 1;

    unsigned char vrcred : 1;
    unsigned char vrfred : 1;
    unsigned char varmred : 1;
    unsigned char vstambarblue : 1;

    unsigned char vnotondead : 1;
    unsigned char vmeleeonly : 1;
    unsigned char vbossinv : 1;
    unsigned char vnoclear : 1;

    unsigned char vnooverlays : 1;
    unsigned char vgreen : 1;
    unsigned char vudead : 1;
    unsigned char vlife : 1;
#endif

    unsigned char iPadding5[3];

    unsigned short vstat;       //ItemStatCost
    unsigned short vsetfunc;

    unsigned short vremfunc;
    unsigned short vgroup;

    unsigned char vcolorpri;
    unsigned char vcolorshift;
    unsigned char vlightmysubr;
    unsigned char vlightmysubg;

    unsigned char vlightmysubb;
    unsigned char iPadding9;
    unsigned short vonsound;    //sounds

    unsigned short voffsound;   //sounds
    unsigned short vitemtype;   //itemtypes

    unsigned char vitemtrans;  //colors
    unsigned char vgfxtype;
    unsigned short vgfxclass;

    unsigned short vcltevent;   //events
    unsigned short vclteventfunc;
    unsigned short vcltactivefunc;
    unsigned short vsrvactivefunc;

    unsigned short vskill;      //skill
    unsigned short vmissile;    //missile
} ST_LINE_INFO;

typedef struct
{
    char vstate[64];
} ST_ITEM_STATES;

static char *m_apcNotUsed[] = 
{
    "immed",
    NULL,
};

static char *m_apcInternalProcess[] = 
{
    "state",
    "eol",
    NULL,
};

static unsigned int m_iItemStatesCount = 0;
static ST_ITEM_STATES *m_astItemStates = NULL;

MODULE_SETLINES_FUNC(FILE_PREFIX, m_astItemStates, ST_ITEM_STATES);

static int States_FieldProc_Pre(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "state") )
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

        strncpy(m_astItemStates[m_iItemStatesCount].vstate, acOutput, sizeof(m_astItemStates[m_iItemStatesCount].vstate));
        String_Trim(m_astItemStates[m_iItemStatesCount].vstate);
        m_iItemStatesCount++;
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

static int States_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "state") )
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

static int States_ConvertValue(void *pvLineInfo, char *acKey, char *pcTemplate, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    char *pcResult;
    int result = 0;

    if ( !strcmp(acKey, "overlay1") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->voverlay1);
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
    else if ( !strcmp(acKey, "overlay2") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->voverlay2);
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
    else if ( !strcmp(acKey, "overlay3") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->voverlay3);
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
    else if ( !strcmp(acKey, "overlay4") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->voverlay4);
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
    else if ( !strcmp(acKey, "castoverlay") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->vcastoverlay);
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
    else if ( !strcmp(acKey, "removerlay") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->vremoverlay);
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
    else if ( !strcmp(acKey, "pgsvoverlay") )
    {
        pcResult = Overlay_GetOverlay(pstLineInfo->vpgsvoverlay);
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
    else if ( !strcmp(acKey, "stat") )
    {
        pcResult = ItemStatCost_GetStateName(pstLineInfo->vstat);
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
    else if ( !strcmp(acKey, "onsound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->vonsound);
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
    else if ( !strcmp(acKey, "offsound") )
    {
        pcResult = Sounds_GetSoundName(pstLineInfo->voffsound);
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
    else if ( !strcmp(acKey, "itemtype") )
    {
        pcResult = ItemTypes_GetItemCode(pstLineInfo->vitemtype);
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
    else if ( !strcmp(acKey, "cltevent") )
    {
        pcResult = Events_GetEventName(pstLineInfo->vcltevent);
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
    else if ( !strcmp(acKey, "skill") )
    {
        pcResult = Skills_GetSkillName(pstLineInfo->vskill);
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
    else if ( !strcmp(acKey, "missile") )
    {
        pcResult = Missiles_GetMissile(pstLineInfo->vmissile);
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
    else if ( !strcmp(acKey, "itemtrans") )
    {
        pcResult = Colors_GetColorCode(pstLineInfo->vitemtrans);
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

static int States_BitProc(void *pvLineInfo, char *acKey, char *acOutput)
{
    ST_LINE_INFO *pstLineInfo = pvLineInfo;
    int result = 0;

    if ( !strcmp(acKey, "damblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "remhit") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "active") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "pgsv") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "transform") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "hide") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "aura") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "nosend") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits1 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "bossstaydeath") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "monstaydeath") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "plrstaydeath") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "curable") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "curse") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "attred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "attblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "damred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits2 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rpblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rlblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rcblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rfblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "armblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "blue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "restrict") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "disguise") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits3 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "shatter") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "exp") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rpred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rlred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rcred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "rfred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "armred") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "stambarblue") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits4 & 1) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "notondead") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 7)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "meleeonly") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 6)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "bossinv") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 5)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "noclear") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 4)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "nooverlays") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 3)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "green") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 2)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "udead") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & (1 << 1)) != 0);
        result = 1;
    }
    else if ( !strcmp(acKey, "life") )
    {
        sprintf(acOutput, "%d", (pstLineInfo->vCombinedBits5 & 1) != 0);
        result = 1;
    }

    return result;
}

int process_states(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, id, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay1, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay2, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay3, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, overlay4, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, castoverlay, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, removerlay, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, pgsvoverlay, USHORT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, damblue, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, remhit, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, active, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, pgsv, CombinedBits1, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, transform, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, hide, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, aura, CombinedBits1, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, nosend, CombinedBits1, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, bossstaydeath, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, monstaydeath, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, plrstaydeath, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, curable, CombinedBits2, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, curse, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, attred, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, attblue, CombinedBits2, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, damred, CombinedBits2, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rpblue, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rlblue, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rcblue, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rfblue, CombinedBits3, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, armblue, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, blue, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, restrict, CombinedBits3, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, disguise, CombinedBits3, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, shatter, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, exp, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rpred, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rlred, CombinedBits4, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rcred, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, rfred, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, armred, CombinedBits4, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, stambarblue, CombinedBits4, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, notondead, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, meleeonly, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, bossinv, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, noclear, CombinedBits5, BIT);

    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, nooverlays, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, green, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, udead, CombinedBits5, BIT);
    VALUE_MAP_DEFINE_2(pstValueMap, pstLineInfo, life, CombinedBits5, BIT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, stat, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, setfunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, remfunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, group, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, colorpri, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, colorshift, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubr, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubg, UCHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lightmysubb, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, onsound, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, offsound, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemtype, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, itemtrans, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gfxtype, UCHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gfxclass, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltevent, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, clteventfunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, cltactivefunc, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, srvactivefunc, USHORT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, skill, USHORT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, missile, USHORT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = States_FieldProc_Pre;
            m_stCallback.pfnSetLines = SETLINES_FUNC_NAME(FILE_PREFIX);
            m_stCallback.pfnFinished = FINISHED_FUNC_NAME(FILE_PREFIX);
            m_stCallback.ppcKeyNotUsed = m_apcNotUsed;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            m_iItemStatesCount = 0;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo),
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            MODULE_DEPEND_CALL(overlay, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemstatcost, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(sounds, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(itemtypes, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(events, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(skills, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(missiles, acTemplatePath, acBinPath, acTxtPath);
            MODULE_DEPEND_CALL(colors, acTemplatePath, acBinPath, acTxtPath);
            break;

        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            m_stCallback.pfnFieldProc = States_FieldProc;
            m_stCallback.pfnConvertValue = States_ConvertValue;
            m_stCallback.pfnBitProc = States_BitProc;
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

char *States_GetStateName(unsigned int id)
{
    if ( id >= m_iItemStatesCount )
    {
        return NULL;
    }

    return m_astItemStates[id].vstate;
}

