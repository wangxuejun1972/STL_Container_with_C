#ifndef _CTL_LIST_H
#define _CTL_LIST_H


/**
 * ��Ϊ��List���У�����ʹ��malloc�������ڴ�ռ䣬������Ҫ�ر�ע������ڴ�й©
 */


#include "ctl.h"

typedef struct LIST_NODE {
    void *data;      //ָ��ýڵ����������
    struct LIST_NODE *next;   //ָ����һ���ڵ�
}ListNode;

typedef struct CTL_LIST{
    ListNode *root;    //ָ��������ͷָ��
    size_t typeSize;  //�����и�����Ԫ����ռ���ֽ���
    int num;          // Ԫ�صĸ���
}CTLList;


#define NODE_SIZE  sizeof(ListNode)

//��ʼ��list
#define INIT_CTL_LIST(type, name) \
		CTLList name = {NULL, sizeof(type), 0}

//����list���ͷ������ÿռ�
#define FREE_CTL_LIST(name)  CTLListClear(&name)



//��list��գ��ͷŸ����ڵ�Ŀռ�
// @return ��������NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListClear(CTLList *list);

//listΪ�գ��򷵻�TURE�����򷵻�FALSE
extern int CTLListIsEmpty(CTLList list);

//����List������Ԫ�صĸ���
extern int CTLListGetNum(CTLList list);

//����ָ�������е�һ���ڵ��ָ�룻����һ���ڵ�Ϊ�գ��򷵻�NULL
extern ListNode *CTLListGetHead(CTLList list);


//����ָ��������β�ڵ��ָ�룻������Ϊ�գ��򷵻�NULL
extern ListNode *CTLListGetTail(CTLList list);

//��listͷ���������record
//@return  ����������NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListPushFront(CTLList *list, void *record);

//��listβ���������record
//@return �����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListPushTail(CTLList *list, void *record);

//����ͷ�����ݡ���listͷ����������record������Ȼ��ɾ������ڵ�
//@return ɾ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListPopFront(CTLList *list, void *record);

//����β�����ݡ���listβ����������record������Ȼ��ɾ������ڵ�
//@return ɾ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListPopTail(CTLList *list, void *record);


//1��������list�ĵ�numλ�ô���������record
//2�����λ��num(��СֵΪ1)���������Ԫ�������������ݲ��뵽��β
//@return һ�������򷵻�NORMAL�����򷵻���Ӧ������
extern int CTLListInsert(CTLList *list, void *record, int num);


//ɾ������list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ㣬�����ýڵ㴦��dataֵ��record����
//@return ���ɾ���������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListDelete(CTLList *list, void *record, int num);

//��ȡ����list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ������ֵ����ɾ������������record����
//@return  �����ȡ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListRead(CTLList *list, void *record, int num);


//������list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ��dataֵ����Ϊ*recordֵ
//@return ��������������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLListSet(CTLList *list, void *record, int num);

//��tail��ָ����������ӵ�front��ָ�������β����������ӳ� front������
//@return  ���������򷵻�NORMAL�����򷵻���Ӧ������
extern int CTLListConnect(CTLList *front, CTLList *tail);



//��list��data����record�����нڵ㶼ɾ��
//@return  ��������·���ɾ���Ľڵ�ĸ������쳣����·�����Ӧ�Ĵ�����
extern int CTLListRemoveAll(CTLList *list, const void *record);


//1�����list�д�������Ԫ��record����ptrָ��ָ������ڵ㡣
//2���������Ľڵ��ж������ptrָ����ǵ�һ����
//3����������������Ľڵ㣬��ptrָ��NULL
//@return ������ڴ����򷵻���Ӧ�Ĵ����ţ����򷵻�NORMAL
extern int CTLListLocate(CTLList *list, ListNode **ptr, void *record);

#endif // _CTL_LIST_H
