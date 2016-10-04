#include "global.h"

#define FILE_PREFIX "monlvl"
#define NAME_PREFIX "mv"

/*
Title 	MonLvl.txt File Guide
Description 	by Kingpin
Sent by 	
I didn't see that this is mentioned here. In MonLvl.txt all L-XX columns is used for ladder/single player and tcp-ip. So here is a fileguide for this file.

MonLvl.txt

AC: Armor Class (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) / 100},
Closed battle.net only

AC(N): Armor Class (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) / 100}, Closed battle.net only

AC(H): Armor Class (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) / 100},
Closed battle.net only

L-AC: Armor Class (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) / 100}, Ladder/Single player/tcp-ip

L-AC(N): Armor Class (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) /
100}, Ladder/Single player/tcp-ip

L-AC(H): Armor Class (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt Ac * Monstats.txt AC) / 100}, Ladder/Single player/tcp-ip

TH: To Hit (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and MonLvl.txt TH * Monstats.txt A2TH) / 100}, Closed battle.net only

TH(N): To Hit (Nightmare) , is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and
MonLvl.txt TH * Monstats.txt A2TH) / 100}, Closed battle.net only

TH(H): To Hit (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and MonLvl.txt TH * Monstats.txt A2TH) / 100}, Closed battle.net only

L-TH: To Hit (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and MonLvl.txt TH * Monstats.txt A2TH) / 100}, Ladder/Single player/tcp-ip

L-TH(N): To Hit (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and
MonLvl.txt TH * Monstats.txt A2TH) / 100}, Ladder/Single player/tcp-ip

L-TH(H): To Hit (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt TH * Monstats.txt A1TH and MonLvl.txt TH * Monstats.txt A2TH) / 100}, Ladder/Single player/tcp-ip
HP: Hitpoints (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and
MonLvl.txt HP * Monstats.txt maxHP) / 100}, Closed battle.net only

HP(N): Hitpoints (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and MonLvl.txt HP * Monstats.txt maxHP) / 100}, Closed battle.net only

HP(H): Hitpoints (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and
MonLvl.txt HP * Monstats.txt maxHP) / 100)}, Closed battle.net only

L-HP: Hitpoints (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and MonLvl.txt HP * Monstats.txt maxHP) / 100)}, Ladder/Single player/tcp-ip

L-HP(N): Hitpoints (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and MonLvl.txt HP * Monstats.txt maxHP) / 100) / 100}, Ladder/Single player/tcp-ip

L-HP(H): Hitpoints (Hell), is calculated together with monstats.txt column(s) {(MonLvl.txt HP * Monstats.txt minHP) / 100 and MonLvl.txt HP * Monstats.txt maxHP) / 100)}, Ladder/Single player/tcp-ip

DM: Damage (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and
MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) / 100}, Closed battle.net only

DM(N): Damage (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt 
A2MaxD) / 100}, Closed battle.net only

DM: Damage (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and
MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) / 100}, Closed battle.net only

DM(H): Damage (Hell), is calculated together with monstats.txt column(s) {DM: Damage (Normal) is calculated together with monstats.txt ac column {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt 
DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) / 100}, Closed battle.net only

L-DM: Damage (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) 
/ 100}, Closed battle.net only

DM: Damage (Normal) , is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) 
/ 100}, Ladder/Single player/tcp-ip

L-DM(N): Damage (Nightmare), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt 
A2MaxD) / 100}, Ladder/Single player/tcp-ip

DM: Damage (Normal), is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and
MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) / 100}, Ladder/Single player/tcp-ip

L-DM(H): Damage (Hell) , is calculated together with monstats.txt column(s) {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD
) / 100}, Ladder/Single player/tcp-ip

DM: Damage (Normal) is calculated together with monstats.txt ac column {(MonLvl.txt DM * Monstats.txt A1MinD) / 100 and
MonLvl.txt DM * Monstats.txt A1MaxD) / 100 and MonLvl.txt DM * Monstats.txt A2MinD) / 100 and MonLvl.txt DM * Monstats.txt A2MaxD) / 100}, Ladder/Single player/tcp-ip

XP: Experience Points (Normal) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp
) / 100 }, Closed battle.net only

XP(N): Experience Points (Nightmare) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp) / 100 }, Closed battle.net only

XP(H): Experience Points (Hell) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp
) / 100 }, Closed battle.net only

L-XP: Experience Points (Normal) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp
) / 100 }, Ladder/Single player/tcp-ip

L-XP(N): Experience Points (Nightmare) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp) / 100 }, Ladder/Single player/tcp-ip

L-XP(H): Experience Points (Hell) , is calculated together with monstats.txt column(s) {(MonLvl.txt XP * Monstats.txt Exp
) / 100 }, Ladder/Single player/tcp-ip

*/

/*
AC: ����(AC ����) (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt Ac*Monstats.txt AC)/100},���ʽս����

AC:(N)����(AC ����) (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt Ac*Monstats.txt AC)/100},���ʽս����

AC:(H) ����(AC ����) (����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt Ac*Monstats.txt AC)/100},���ʽս����

L-AC:����(AC ����) (��ͨ),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt Ac*Monstats.txt AC)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-AC:(N) ����(AC ����) (����),��ͬ monstats.txt �� (s) һ������ {/( MonLvl.txt Ac*Monstats.txt AC)/100}, Ladderģʽ/ ������Ϸ/ tcp- ip��

L-AC:(H)����(AC ����) (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt Ac*Monstats.txt AC)/100},Ladderģʽ/������Ϸ/tcp- ip��

TH:to hit(Ӧ��ָ�����ȼ�) (��ͨ),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt TH*Monstats.txt A1TH �� MonLvl.txt TH*Monstats.txt A2TH)/100},���ʽս����

TH:(N) to hit(Ӧ��ָ�����ȼ�) (����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt TH* Monstats.txt A1TH �� MonLvl.txt TH*Monstats.txt A2TH)/100}, ���ʽս����

TH:(H)to hit(Ӧ��ָ�����ȼ�)(Ӧ��ָ�����ȼ�) (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt TH*Monstats.txt A1TH �� MonLvl.txt TH*Monstats.txt A2TH)/100},���ʽս����

L-TH:to hit(Ӧ��ָ�����ȼ�) (��ͨ),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt TH*Monstats.txt A1TH �� MonLvl.txt TH*Monstats.txt A2TH)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-TH:(N) to hit(Ӧ��ָ�����ȼ�) (����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt TH* Monstats.txt A1TH ��MonLvl.txt TH*Monstats.txt A2TH)/100}, Ladderģʽ/ ������Ϸ/ tcp- ip��

L-TH:(H)to hit(Ӧ��ָ�����ȼ�) (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt TH*Monstats.txt A1TH �� MonLvl.txt TH*Monstats.txt A2TH)/100},Ladderģʽ/������Ϸ/tcp- ip��

HP: ����ֵ(��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt HP*Monstats.txt minHP)/100 ��
MonLvl.txt HP*Monstats.txt maxHP)/100}, ���ʽս����

HP:(N)����ֵ(����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt HP*Monstats.txt minHP)/100 �� MonLvl.txt HP*Monstats.txt maxHP)/100},���ʽս����

HP:(H) ����ֵ(����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt HP*Monstats.txt minHP)/100 ��MonLvl.txt HP*Monstats.txt maxHP)/100)}, ���ʽս����

L-HP: ����ֵ(��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt HP*Monstats.txt minHP)/100 �� MonLvl.txt HP*Monstats.txt maxHP)/100)}, Ladderģʽ/ ������Ϸ/ tcp- ip��

L-HP:(N)����ֵ(����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt HP*Monstats.txt minHP)/100 �� MonLvl.txt HP*Monstats.txt maxHP)/100)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-HP:(H) ����ֵ(����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt HP*Monstats.txt minHP)/100 �� MonLvl.txt HP*Monstats.txt maxHP)/100)}, Ladderģʽ/ ������Ϸ/ tcp- ip��

DM: �� (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt DM*Monstats.txt A1MinD)/100 ��
MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100}, ���ʽս����

DM:(N)�� (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},���ʽս����

DM: �� (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt DM*Monstats.txt A1MinD)/100 ��
MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100}, ���ʽս����

DM:(H) �� (����),��ͬ monstats.txt �� (s) һ������ {DM:�� (��ͨ) ��ͬ monstats.txt ac ��һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.
txt A2MaxD)/100},ֻ���ʽս����

L-DM:�� ( ��ͨ),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},ֻ���ʽս����

DM:�� (��ͨ),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-DM:(N)�� (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},Ladderģʽ/������Ϸ/tcp- ip��

DM: �� (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt DM*Monstats.txt A1MinD)/100 ��
MonLvl.txt DM* Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-DM:(H)�� (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt DM*Monstats.txt A1MinD)/100 �� MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},Ladderģʽ/������Ϸ/tcp- ip��

DM: �� (��ͨ) ��ͬ monstats.txt ac ��һ������ {( MonLvl.txt DM*Monstats.txt A1MinD)/100 ��
MonLvl.txt DM*Monstats.txt A1MaxD)/100 �� MonLvl.txt DM*Monstats.txt A2MinD)/100 �� MonLvl.txt DM*Monstats.txt A2MaxD)/100},Ladderģʽ/������Ϸ/tcp- ip��

XP: ����� (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt XP* Monstats.txt Exp
)/100}, ���ʽս����

XP:(N)����� (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt XP*Monstats.txt Exp)/100},ֻ���ʽս����

XP:(H) ����� (����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt XP* Monstats.txt Exp
)/100}, ���ʽս����

L-XP: ����� (��ͨ),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt XP* Monstats.txt Exp
)/100}, Ladderģʽ/ ������Ϸ/ tcp- ip��

L-XP:(N)����� (����),��ͬ monstats.txt �� (s) һ������{(MonLvl.txt XP*Monstats.txt Exp)/100},Ladderģʽ/������Ϸ/tcp- ip��

L-XP:(H) ����� (����),��ͬ monstats.txt �� (s) һ������ {( MonLvl.txt XP* Monstats.txt Exp
)/100},Ladderģʽ/������Ϸ/tcp-ip��
*/

/*
�ļ���������
Mon��monster������ļ�ơ�
Lvl��level���ȼ����ļ�д��
���Ա��ļ������˹���ȼ���ص�һЩ���ԡ�
���ļ��е�ÿһ�б�ʾһ���ȼ���


�ظ�

    2¥
    2011-09-19 23:21

    �ٱ� |

    zqtjingzi
    С����
    12

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-19 23:21

    �ٱ� |

    zqtjingzi
    С����
    12

Level���ȼ���������ָ����ĵȼ���

L-AC����ͨ�Ѷ��µĹ����ڴ˵ȼ�ʱ�ķ���ֵ��

L-AC(N)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�ķ���ֵ��

L-AC(H)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�ķ���ֵ��

L-TH����ͨ�Ѷ��µĹ����ڴ˵ȼ�ʱ�Ĺ���׼ȷ�ʡ�

L-TH(N)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�Ĺ���׼ȷ�ʡ�

L-TH(H)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�Ĺ���׼ȷ�ʡ�

L-HP����ͨ�Ѷ��µĹ����ڴ˵ȼ�ʱ������ֵ��

L-HP(N)�������Ѷ��µĹ����ڴ˵ȼ�ʱ������ֵ��

L-HP(H)�������Ѷ��µĹ����ڴ˵ȼ�ʱ������ֵ��

L-DM����ͨ�Ѷ��µĹ����ڴ˵ȼ�ʱ���˺�ֵ��

L-DM(N)�������Ѷ��µĹ����ڴ˵ȼ�ʱ���˺�ֵ��

L-DM(H)�������Ѷ��µĹ����ڴ˵ȼ�ʱ���˺�ֵ��

L-XP����ͨ�Ѷ��µĹ����ڴ˵ȼ�ʱ�ľ���ֵ��

L-XP(N)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�ľ���ֵ��

L-XP(H)�������Ѷ��µĹ����ڴ˵ȼ�ʱ�ľ���ֵ��


�ظ�

    4¥
    2011-09-19 23:21

    �ٱ� |

    zqtjingzi
    С����
    12

����˵�������ļ������еĹ�������ֵ��������ʵ����Ϸ�й��������ֵ������Ҫ������monstats.txt��ÿ�ֹ���������������Ӳ�������������ֵ����ʵ��ĳ�ֹ���ķ���ֵӦΪ L-AC * level * AC������AC���Ǵ˹�����monstats.txt��AC�е�ֵ��

*/

typedef struct
{
    unsigned int vAC;
    unsigned int vACmybr1Nmybr2;
    unsigned int vACmybr1Hmybr2;

    unsigned int vLmysubAC;
    unsigned int vLmysubACmybr1Nmybr2;
    unsigned int vLmysubACmybr1Hmybr2;

    unsigned int vTH;
    unsigned int vTHmybr1Nmybr2;
    unsigned int vTHmybr1Hmybr2;

    unsigned int vLmysubTH;
    unsigned int vLmysubTHmybr1Nmybr2;
    unsigned int vLmysubTHmybr1Hmybr2;

    unsigned int vHP;
    unsigned int vHPmybr1Nmybr2;
    unsigned int vHPmybr1Hmybr2;

    unsigned int vLmysubHP;
    unsigned int vLmysubHPmybr1Nmybr2;
    unsigned int vLmysubHPmybr1Hmybr2;

    unsigned int vDM;
    unsigned int vDMmybr1Nmybr2;
    unsigned int vDMmybr1Hmybr2;

    unsigned int vLmysubDM;
    unsigned int vLmysubDMmybr1Nmybr2;
    unsigned int vLmysubDMmybr1Hmybr2;

    unsigned int vXP;
    unsigned int vXPmybr1Nmybr2;
    unsigned int vXPmybr1Hmybr2;

    unsigned int vLmysubXP;
    unsigned int vLmysubXPmybr1Nmybr2;
    unsigned int vLmysubXPmybr1Hmybr2;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "Level",
    NULL,
};

static unsigned int m_iMonLvlCount = 0;

static int MonLvl_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "Level") )
    {
#ifdef USE_TEMPLATE
        if ( 0 != pcTemplate[0] )
        {
            strcpy(acOutput, pcTemplate);
        }
        else
#endif
        {
            sprintf(acOutput, "%s%u", NAME_PREFIX, m_iMonLvlCount);
        }

        m_iMonLvlCount++;

        return 1;
    }

    return 0;
}

int process_monlvl(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, AC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, ACmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubAC, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubACmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubACmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, TH, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, THmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, THmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTH, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTHmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubTHmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, HPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubHPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DM, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DMmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, DMmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDM, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDMmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubDMmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, XPmybr1Hmybr2, UINT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXP, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXPmybr1Nmybr2, UINT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, LmysubXPmybr1Hmybr2, UINT);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = MonLvl_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
        case EN_MODULE_RESERVED_1:
        case EN_MODULE_RESERVED_2:
            break;

        case EN_MODULE_INIT:
            break;

        default:
            break;
    }

    return 1;
}

