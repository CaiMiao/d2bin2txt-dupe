#include "global.h"

#define FILE_PREFIX "inventory"
#define NAME_PREFIX "iv"

/*
class - a comment field used to describe what this line refers to.

invLeft - left edge of the screen (x).
invRight - right edge of the screen (invLeft + DC6_WIDTH).
invTop - top edge of the screen (y).
invBottom - bottom edge of the screen (invTop + DC6_HEIGHT).

gridX - number of columns in the item grid.
gridY - number of rows in the item grid.
gridLeft - left edge of the grid (x).
gridRight - right edge of the grid (gridLeft + gridBoxWidth * gridX) *see note
gridTop - top edge of the grid (y).
gridBottom - bottom edge of the grid (gridTop + gridBoxHeight * gridY) *see note
gridBoxWidth - the width of each grid cell.
gridBoxHeight - the height of each grid cell.

rArmLeft - the left edge of the right weapon slot (x).
rArmRight - the right edge of the right weapon slot (rArmLeft + rArmWidth).
rArmTop - the top edge of the right weapon slot (y).
rArmBottom - the bottom edge of the right weapon slot (rArmTop + rArmHeight).
rArmWidth - width of the right weapon slot.
rArmHeight - height of the right weapon slot.

torsoLeft - the left edge of the body armor slot (x).
torsoRight - the right edge of the body armor slot (torsoLeft + torsoWidth).
torsoTop - the top edge of the body armor slot (y).
torsoBottom - the bottom edge of the body armor slot (torsoTop + torsoHeight).
torsoWidth - width of the body armor slot.
torsoHeight - height of the body armor slot.

lArmLeft - the left edge of the left weapon slot (x).
lArmRight - the right edge of the left weapon slot (lArmLeft + lArmWidth).
lArmTop - the top edge of the left weapon slot (y).
lArmBottom - the bottom edge of the left weapon slot (lArmTop + lArmHeight).
lArmWidth - width of the left weapon slot.
lArmHeight - height of the left weapon slot.

helmLeft - the left edge of the head gear slot (x).
helmRight - the right edge of the head gear slot (helmLeft + helmWidth).
helmTop - the top edge of the head gear slot (y).
helmBottom - the bottom edge of the head gear slot (helmTop + helmHeight).
helmWidth - width of the head gear slot.
helmHeight - height of the head gear slot.

neckLeft - the left edge of the amulet slot (x).
neckRight - the right edge of the amulet slot (neckLeft + neckWidth).
neckTop - the top edge of the amulet slot (y).
neckBottom - the bottom edge of the amulet slot (neckTop + neckHeight).
neckWidth - width of the amulet slot.
neckHeight - height of the amulet slot.

rHandLeft - the left edge of the right ring slot (x).
rHandRight - the right edge of the right ring slot (rHandLeft + rHandWidth).
rHandTop - the top edge of the right ring slot (y).
rHandBottom - the bottom edge of the right ring slot (rHandTop + rHandHeight).
rHandWidth - width of the right ring slot.
rHandHeight - height of the right ring slot.

lHandLeft - the left edge of the left ring slot (x).
lHandRight - the right edge of the left ring slot (lHandLeft + lHandWidth).
lHandTop - the top edge of the left ring slot (y).
lHandBottom - the bottom edge of the left ring slot (lHandTop + lHandHeight).
lHandWidth - width of the left ring slot.
lHandHeight - height of the left ring slot.

beltLeft - the left edge of the belt slot (x).
beltRight - the right edge of the belt slot (beltLeft + beltWidth).
beltTop - the top edge of the belt slot (y).
beltBottom - the bottom edge of the belt slot (beltTop + beltHeight).
beltWidth - width of the belt slot.
beltHeight - height of the belt slot.

feetLeft - the left edge of the boot slot (x).
feetRight - the right edge of the boot slot (feetLeft + feetWidth).
feetTop - the top edge of the boot slot (y).
feetBottom - the bottom edge of the boot slot (feetTop + feetHeight).
feetWidth - width of the boot slot.
feetHeight - height of the boot slot.

gloveLeft - the left edge of the glove slot (x).
gloveRight - the right edge of the glove slot (gloveLeft + gloveWidth).
gloveTop - the top edge of the glove slot (y).
gloveBottom - the bottom edge of the glove slot (gloveTop + gloveHeight).
gloveWidth - width of the glove slot.
gloveHeight - height of the glove slot.

* Blizzard screwed this up a little bit, their values are off by a few pixels.

*/

/*
��һ�в��� �� ����˵��
Amazon �� ����ѷ��Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Sorceress �� ��ʦ��Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Necromancer �� ���鷨ʦ��Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Paladin �� ʥ��ʿ��Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Barbarian �� Ұ������Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Monster �� ���������Ի�������Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Trade Page 1 �� ������Ϸ��Ʒ��������������ÿռ䣨640��480 ���طֱ��ʣ�
Trade Page 2 �� ������Ϸ��Ʒ��������������ÿռ䣨640��480 ���طֱ��ʣ�
Bank Page 1 �� ������ռ䣨640��480 ���طֱ��ʣ�[��Ӧԭ��]
Transmogrify Box Page 1 �� Horadric Cube ���ÿռ䣨640��480 ���طֱ��ʣ�
Guild Vault Page 1 �� δʹ�õĹ������ÿռ䣨640��480 ���طֱ��ʣ�
Trophy Case Page 1 �� δʹ�õĽ������ÿռ䣨640��480 ���طֱ��ʣ�
Expansion �� Expansion
Big Bank Page 1 �� ������ռ䣨640��480 ���طֱ��ʣ�[��Ӧ����Ƭ]
Hireling �� ��Ӷ����Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Druid �� ��³����Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Assassin �� �̿���Ʒ���ÿռ䣨640��480 ���طֱ��ʣ�
Amazon2 �� ����ѷ��Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Sorceress2 �� ��ʦ��Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Necromancer2 �� ���鷨ʦ��Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Paladin2 �� ʥ��ʿ��Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Barbarian2 �� Ұ������Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Monster2 �� ���������Ի�������Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Trade Page 1-2 �� ������Ϸ��Ʒ��������������ÿռ䣨800��600 ���طֱ��ʣ�
Trade Page 2-2 �� ������Ϸ��Ʒ��������������ÿռ䣨800��600 ���طֱ��ʣ�
Bank Page2 �� ������ռ䣨800��600 ���طֱ��ʣ�[��Ӧԭ��]
Transmogrify Box2 �� Horadric Cube ���ÿռ䣨800��600 ���طֱ��ʣ�
Guild Vault Page2 �� δʹ�õĹ������ÿռ䣨800��600 ���طֱ��ʣ�
Trophy Case Page2 �� δʹ�õĽ������ÿռ䣨800��600 ���طֱ��ʣ�
Big Bank Page2 �� ������ռ䣨800��600 ���طֱ��ʣ�[��Ӧ����Ƭ]
Hireling2 �� ��Ӷ����Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Druid2 �� ��³����Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�
Assassin2 �� �̿���Ʒ���ÿռ䣨800��600 ���طֱ��ʣ�

��һ�в��� �� ����˵��
Class �� ����ռ䴦�����ݣ�ֻ���ο���־��
InvLeft �� �����������ꡪ��ʾͼ����߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
InvRight �� �����������ꡪ��ʾͼ���ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
InvTop �� �����������ꡪ��ʾͼ���ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
InvBottom �� �����������ꡪ��ʾͼ��ײ��߽������������Ļ�ϵ���Զ�λ����ֵ

����ռ�����趨��
GridX �� ����ռ�ÿ�еĸ���
GridY �� ����ռ�ÿ�еĸ���
GridLeft �� �����������ꡪ��ʾ����ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
GridRight �� �����������ꡪ��ʾ����ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
GridTop �� �����������ꡪ��ʾ����ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
GridBottom �� �����������ꡪ��ʾ����ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
GridBoxWidth �� ÿ�����˵Ŀ�ȣ�����ֵ�����a��ÿ��ߴ���29��29�����ͨ��ȡֵ��29��
GridBoxHeight �� ÿ�����˵ĸ߶ȣ�����ֵ�����a��ÿ��ߴ���29��29�����ͨ��ȡֵ��29��

������Ʒװ���ռ�����趨��
rArmLeft �� �����������ꡪ��ʾ�ұۣ�������ܣ�װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
rArmRight �� �����������ꡪ��ʾ�ұۣ�������ܣ�װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
rArmTop �� �����������ꡪ��ʾ�ұۣ�������ܣ�װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
rArmBottom �� �����������ꡪ��ʾ�ұۣ�������ܣ�װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
rArmWidth �� �ұۣ�������ܣ�װ���ռ�Ŀ�ȣ�����ֵ��
rArmHeight �� �ұۣ�������ܣ�װ���ռ�ĸ߶ȣ�����ֵ��

TorsoLeft �� �����������ꡪ��ʾ���ɣ�װ�ף�װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
TorsoRight �� �����������ꡪ��ʾ���ɣ�װ�ף�װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
TorsoTop �� �����������ꡪ��ʾ���ɣ�װ�ף�װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
TorsoBottom �� �����������ꡪ��ʾ���ɣ�װ�ף�װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
TorsoWidth �� ���ɣ�װ�ף�װ���ռ�Ŀ�ȣ�����ֵ��
TorsoHeight �� ���ɣ�װ�ף�װ���ռ�ĸ߶ȣ�����ֵ��

lArmLeft �� �����������ꡪ��ʾ��ۣ�������ܣ�װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
lArmRight �� �����������ꡪ��ʾ�ұۣ�������ܣ�װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
lArmTop �� �����������ꡪ��ʾ��ۣ�������ܣ�װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
lArmBottom �� �����������ꡪ��ʾ��ۣ�������ܣ�װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
lArmWidth �� ��ۣ�������ܣ�װ���ռ�Ŀ�ȣ�����ֵ��
lArmHeight �� ��ۣ�������ܣ�װ���ռ�ĸ߶ȣ�����ֵ��

HeadLeft �� �����������ꡪ��ʾͷ����ͷ����װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
HeadRight �� �����������ꡪ��ʾͷ����ͷ����װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
HeadTop �� �����������ꡪ��ʾͷ����ͷ����װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
HeadBottom �� �����������ꡪ��ʾͷ����ͷ����װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
HeadWidth �� ͷ����ͷ����װ���ռ�Ŀ�ȣ�����ֵ��
HeadHeight �� ͷ����ͷ����װ���ռ�ĸ߶ȣ�����ֵ��

NeckLeft �� �����������ꡪ��ʾ�������������װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
NeckRight �� �����������ꡪ��ʾ�������������װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
NeckTop �� �����������ꡪ��ʾ�������������װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
NeckBottom �� �����������ꡪ��ʾ�������������װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
NeckWidth �� �������������װ���ռ�Ŀ�ȣ�����ֵ��
NeckHeight �� �������������װ���ռ�ĸ߶ȣ�����ֵ��

rHandLeft �� �����������ꡪ��ʾ���֣���ָ��װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
rHandRight �� �����������ꡪ��ʾ���֣���ָ��װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
rHandTop �� �����������ꡪ��ʾ���֣���ָ��װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
rHandBottom �� �����������ꡪ��ʾ���֣���ָ��װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
rHandWidth �� ���֣���ָ��װ���ռ�Ŀ�ȣ�����ֵ��
rHandHeight �� ���֣���ָ��װ���ռ�ĸ߶ȣ�����ֵ��

lHandLeft �� �����������ꡪ��ʾ���֣���ָ��װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
lHandRight �� �����������ꡪ��ʾ���֣���ָ��װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
lHandTop �� �����������ꡪ��ʾ���֣���ָ��װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
lHandBottom �� �����������ꡪ��ʾ���֣���ָ��װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
lHandWidth �� ���֣���ָ��װ���ռ�Ŀ�ȣ�����ֵ��
lHandHeight �� ���֣���ָ��װ���ռ�ĸ߶ȣ�����ֵ��

BeltLeft �� �����������ꡪ��ʾ����װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
BeltRight �� �����������ꡪ��ʾ����װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
BeltTop �� �����������ꡪ��ʾ����װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
BeltBottom �� �����������ꡪ��ʾ����װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
BeltWidth �� ����װ���ռ�Ŀ�ȣ�����ֵ��
BeltHeight �� ����װ���ռ�ĸ߶ȣ�����ֵ��

FeetLeft �� �����������ꡪ��ʾѥ��װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
FeetRight �� �����������ꡪ��ʾѥ��װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
FeetTop �� �����������ꡪ��ʾѥ��װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
FeetBottom �� �����������ꡪ��ʾѥ��װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
FeetWidth �� ѥ��װ���ռ�Ŀ�ȣ�����ֵ��
FeetHeight �� ѥ��װ���ռ�ĸ߶ȣ�����ֵ��

GlovesLeft �� �����������ꡪ��ʾ����װ���ռ���߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
GlovesRight �� �����������ꡪ��ʾ����װ���ռ��ұ߽߱�ĺ���������Ļ�ϵ���Զ�λ����ֵ
GlovesTop �� �����������ꡪ��ʾ����װ���ռ��ϲ��߽������������Ļ�ϵ���Զ�λ����ֵ
GlovesBottom �� �����������ꡪ��ʾ����װ���ռ�ײ��߽������������Ļ�ϵ���Զ�λ����ֵ
GlovesWidth �� ����װ���ռ�Ŀ�ȣ�����ֵ��
GlovesHeight �� ����װ���ռ�ĸ߶ȣ�����ֵ��

��Ʒ����ռ����ɶ����С��һ��С���񲢽���ɵĶ�ά�ռ䣬���������Ͽ�ͨ��ԭʼ��Inventory.txt�ļ���ã���ÿ����ɫ��ԭʼ����ռ�Ϊ10��4�����ǿ���ͨ����GridX���͡�GridY��������������Ӧ��ֵ��10���͡�4�����˽����Ϣ������GridBoxWidth���͡�GridBoxHeight���� 
����������Ӧ��ֵͬΪ29�������֪ÿ�����Ÿ�ĳߴ�Ϊ29��29����һ���ڷֱ���Ϊ800��600������ѷ����ռ�����ϣ�
Class ��GridX��GridY��GridLeft��GridRight��GridTop��GridBottom��GridBoxWidth��GridBoxHeight
Amazon2�� 10�� 4�� 419�� 706�� 315�� 428�� 29�� 29
������û�Ѹ���ѧ��ƽ����ѧ����һ�ɶ����Ļ��������������������Ͼ�������ó���GridTop�������ŵ�λ����ʲô��������GridTop���ڷ�Χ�Ǵ�0��600����ͼ�δ����������£�

��0
��
��
��
��
��
��315����������������
�� ��
�� ��
�� ����������ռ䡪��
�� ��
�� ��
��428����������������
��
��
��
��
��
��600

�������ͼ�ɼ�����ռ�������귶Χ��315��428���������Ϊ113��������ռ���4�У����113��4��28.25������롰GridBoxHeight������29���Ӧ�ˡ��˽�������������п��ܸ�����Ԥ�ڵ��趨����������޸ġ�����֮�⣬�㻹Ҫ��invchar6.dc6
��ͼ�ļ�����������ʹ֮�����޸ĵĲ����ﵽһ�µ�Ч����

��GridLeft���͡�GridRight������������Ҳ�ǲ�࣬��ֻ����ͬ���ѣ�

������������������������������������������������
400 419����������������������706 800
��������������ռ䡪������
�� ��

����֮����400��ʼԭ����һ����������ʾ��ɫ״̬������״̬���ϳ���Ʒ�ȵȡ����ϲ�ͼ���������ó���ʲô�����ˣ��Ͳ��˶�������ˡ�

���Ҫ˵���ǣ����ϵ���ֵ������������Ϊ������λ��Ҳ�������Ϊ�㣬�ڶ�Inventory.txt
�����޸�����ʱ��Ϊ�˴ﵽ��������ʾЧ�����ͱ������Ӧ����ͼ�ļ�����������ʵ��֤������һ�е��޸ģ���ʼ����ͼ�ļ����޸ģ�һ���޸�һ�߼�¼������ͼ�ε�ԭʼ������λ�����꣬��֮���Inventory.txt
�ļ��޸�ʱ��������˺���ȷ�ĵ�һ�����ϣ��ӼӼ����ܿ�Ϳ�����޸ģ����ڼ�����Ψһ���ܾ��������ѧ�����������޸�ͼ�����õ�������ر��Ŀ�����Dc6 Creator���������ľ͸��������ˣ��Ϻõ�Ӧ����Fireworks�ˣ��򵥿�ݣ���Դռ�õ͡�
*/

/*
�ļ���������
Inventory����棬�����������ָ�洢�ռ䡣
���ļ�������������Ʒ���Լ��ֿ����Ϣ��
���ļ��е�ÿһ�б�ʾһ�ִ洢�ռ䡣

ÿ�еĺ������£�


�ظ�

    3¥
    2011-09-28 00:00

    �ٱ� |

    zqtjingzi
    С����
    12

class��������ע�ͣ�ָ���������������ִ洢�ռ䡣


�ظ�

    4¥
    2011-09-28 00:00

    �ٱ� |

    zqtjingzi
    С����
    12

��ǰ˵����
XXXLeft����ʾXXX����߽��λ�á�
XXXRight����ʾXXX���ұ߽��λ�á�
XXXTop����ʾXXX���ϱ߽��λ�á�
XXXBottom����ʾXXX���±߽��λ�á�
XXXWidth����ʾXXX�Ŀ�ȣ�һ����ڣ��±߽� - �ϱ߽磩
XXXHeight����ʾXXX�ĸ߶ȣ�һ����ڣ��ұ߽� - ��߽磩


�ظ�

    5¥
    2011-09-28 00:00

    �ٱ� |

    zqtjingzi
    С����
    12

invLeft��
invRight��
invTop��
invBottom��
��ɫ�������壨����װ��������Ʒ�����Ĵ�С��ʵ���ϰ���B�����򿪱������ռ��ȫ���Ұ�ߵ���Ļ���������ļ����Կ���ʵ�ʵı�����СҪС�ڰ����Ļ��ʣ�ಿ�־����ɻ��л��Ƶı߿��Զ���䡣

gridX����Ʒ���ж����С�
gridY����Ʒ���ж����С�

gridLeft��
gridRight��
gridTop��
gridBottom��
��Ʒ���Ĵ�С��
gridBoxWidth��
gridBoxHeight��
��Ʒ����ÿ�����ӵĴ�С��


�ظ�

    6¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

rArmLeft��
rArmRight��
rArmTop��
rArmBottom��
rArmWidth��
rArmHeight��
�����������Ĵ�С��

torsoLeft��
torsoRight��
torsoTop��
torsoBottom��
torsoWidth��
torsoHeight��
�����·����Ĵ�С��

lArmLeft��
lArmRight��
lArmTop��
lArmBottom��
lArmWidth��
lArmHeight��
�����������Ĵ�С��


�ظ�

    7¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

headLeft��
headRight��
headTop��
headBottom��
headWidth��
headHeight��
ͷ�����Ĵ�С��

neckLeft��
neckRight��
neckTop��
neckBottom��
neckWidth��
neckHeight��
�����������Ĵ�С��


�ظ�

    8¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

rhandLeft��
rhandRight��
rhandTop��
rhandBottom��
rhandWidth��
rhandHeight��
���ֽ�ָ���Ĵ�С��

lHandLeft��
lHandRight��
lHandTop��
lHandBottom��
lHandWidth��
lHandHeight��
���ֽ�ָ���Ĵ�С��

beltLeft��
beltRight��
beltTop��
beltBottom��
beltWidth��
beltHeight��
�������Ĵ�С��


�ظ�

    9¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

feetLeft��
feetRight��
feetTop��
feetBottom��
feetWidth��
feetHeight��
Ь�����Ĵ�С��

gloveLeft��
gloveRight��
gloveTop��
gloveBottom��
gloveWidth��
gloveHeight��
�������Ĵ�С��


�ظ�

    10¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

����˵����
��Ļ���Ͻ�Ϊԭ�㣬����0��0���㡣���д�С��ֵ��λΪ���ء�


�ظ�

    11¥
    2011-09-28 00:01

    �ٱ� |

    zqtjingzi
    С����
    12

����˵����
����ʵ�ִ󱳰��������ʱ���ı���ļ�ʱ��Ϊ����ʾЧ����ʵ�ʴ�С��һ���ԣ�һ��Ҫͬʱ�޸Ķ�Ӧ��dc6�ļ���
*/

typedef struct
{
    int vinvLeft;
    int vinvRight;
    int vinvTop;
    int vinvBottom;

    char vgridX;
    char vgridY;
    unsigned short iPadding4;

    int vgridLeft;
    int vgridRight;
    int vgridTop;
    int vgridBottom;

    char vgridBoxWidth;
    char vgridBoxHeight;
    unsigned short iPadding9;

    int vrArmLeft;
    int vrArmRight;
    int vrArmTop;
    int vrArmBottom;

    char vrArmWidth;
    char vrArmHeight;
    unsigned short iPadding14;

    int vtorsoLeft;
    int vtorsoRight;
    int vtorsoTop;
    int vtorsoBottom;

    char vtorsoWidth;
    char vtorsoHeight;
    unsigned short iPadding19;

    int vlArmLeft;
    int vlArmRight;
    int vlArmTop;
    int vlArmBottom;

    char vlArmWidth;
    char vlArmHeight;
    unsigned short iPadding24;

    int vheadLeft;
    int vheadRight;
    int vheadTop;
    int vheadBottom;

    char vheadWidth;
    char vheadHeight;
    unsigned short iPadding29;

    int vneckLeft;
    int vneckRight;
    int vneckTop;
    int vneckBottom;

    char vneckWidth;
    char vneckHeight;
    unsigned short iPadding34;

    int vrHandLeft;
    int vrHandRight;
    int vrHandTop;
    int vrHandBottom;

    char vrHandWidth;
    char vrHandHeight;
    unsigned short iPadding39;

    int vlHandLeft;
    int vlHandRight;
    int vlHandTop; 
    int vlHandBottom;

    char vlHandWidth;
    char vlHandHeight;
    unsigned short iPadding44;

    int vbeltLeft;
    int vbeltRight;
    int vbeltTop;
    int vbeltBottom;

    char vbeltWidth;
    char vbeltHeight;
    unsigned short iPadding49;

    int vfeetLeft;
    int vfeetRight;
    int vfeetTop;
    int vfeetBottom;

    char vfeetWidth;
    char vfeetHeight;
    unsigned short iPadding54;

    int vglovesLeft;
    int vglovesRight;
    int vglovesTop;
    int vglovesBottom;

    char vglovesWidth;
    char vglovesHeight;
    unsigned short iPadding59;
} ST_LINE_INFO;

static char *m_apcInternalProcess[] =
{
    "class",
    NULL,
};

static int Inventory_FieldProc(void *pvLineInfo, char *acKey, unsigned int iLineNo, char *pcTemplate, char *acOutput)
{
    if ( !strcmp(acKey, "class") )
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

    return 0;
}

int process_inventory(char *acTemplatePath, char *acBinPath, char *acTxtPath, ENUM_MODULE_PHASE enPhase)
{
    ST_LINE_INFO *pstLineInfo = (ST_LINE_INFO *)m_acLineInfoBuf;

    ST_VALUE_MAP *pstValueMap = (ST_VALUE_MAP *)m_acValueMapBuf;

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, invBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridX, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridY, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBoxWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, gridBoxHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rArmHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, torsoHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lArmHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, headHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, neckHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, rHandHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandTop, INT); 
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, lHandHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, beltHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, feetHeight, CHAR);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesLeft, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesRight, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesTop, INT);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesBottom, INT);

    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesWidth, CHAR);
    VALUE_MAP_DEFINE(pstValueMap, pstLineInfo, glovesHeight, CHAR);

    switch ( enPhase )
    {
        case EN_MODULE_SELF_DEPEND:
            m_stCallback.pfnFieldProc = Inventory_FieldProc;
            m_stCallback.ppcKeyInternalProcess = m_apcInternalProcess;

            return process_file(acTemplatePath, acBinPath, acTxtPath, FILE_PREFIX, pstLineInfo, sizeof(*pstLineInfo), 
                pstValueMap, Global_GetValueMapCount(), &m_stCallback);
            break;

        case EN_MODULE_OTHER_DEPEND:
            break;

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

