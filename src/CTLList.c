#include "CTLList.h"

//��list��գ��ͷŸ����ڵ�Ŀռ�
// @return ��������NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListClear(CTLList *list){
	ListNode *prevP, *nextP;

	if (list == NULL)
		return CTL_PTR_IS_NULL;

	for (prevP=list->root; prevP!=NULL; prevP=nextP){
		nextP = prevP->next;
		free(prevP->data);
		free(prevP);
	}
	list->root = NULL;
	list->num = 0;
	return NORMAL;
}


//listΪ�գ��򷵻�TURE�����򷵻�FALSE
int CTLListIsEmpty(CTLList list){
	if (list.num == 0)
		return TRUE;
	else
		return FALSE;
}


//����List������Ԫ�صĸ���
int CTLListGetNum(CTLList list){
	return list.num;
}

//����ָ�������е�һ���ڵ��ָ�룻����һ���ڵ�Ϊ�գ��򷵻�NULL
ListNode *CTLListGetHead(CTLList list){
	return list.root;
}


//����ָ��������β�ڵ��ָ�룻������Ϊ�գ��򷵻�NULL
ListNode *CTLListGetTail(CTLList list){
	ListNode *prevP, *nextP;

	for (nextP=prevP=list.root; nextP!=NULL; ){
		prevP = nextP;
		nextP = prevP->next;
	}

	return prevP;
}


//��listͷ���������record
//@return  ����������NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListPushFront(CTLList *list, void *record){
	ListNode *node;

	if (list == NULL)
		return CTL_PTR_IS_NULL;

	node = (ListNode *)malloc(NODE_SIZE);
	node->data = (void *)malloc(list->typeSize);
	if ((node==NULL) || (node->data==NULL))
		return MALLOC_FAIL;

	memcpy(node->data, record, list->typeSize);
	node->next  = list->root;
	list->root = node;
	list->num++;
	return NORMAL;
}


//��listβ���������record
//@return �����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListPushTail(CTLList *list, void *record){
	ListNode *node, *ptr;

	if (list == NULL)
		return CTL_PTR_IS_NULL;

	node = (ListNode *)malloc(NODE_SIZE);
	node->data = (void *)malloc(list->typeSize);
	if ((node==NULL) || (node->data==NULL))
		return MALLOC_FAIL;

	memcpy(node->data, record, list->typeSize);
	node->next = NULL;
	ptr = CTLListGetTail(*list);
	if (ptr != NULL)
		ptr->next = node;
	else
		list->root = node;

	list->num++;
	return NORMAL;
}



//����ͷ�����ݡ���listͷ����������record������Ȼ��ɾ������ڵ�
//@return ɾ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListPopFront(CTLList *list, void *record){
	ListNode *ptr;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (list->root == NULL)
		return CTL_NO_VALUE;

	ptr = list->root;
	memcpy(record, ptr->data, list->typeSize);
	list->root = ptr->next;
	list->num--;
	free(ptr->data);
	free(ptr);
	return NORMAL;
}


//����β�����ݡ���listβ����������record������Ȼ��ɾ������ڵ�
//@return ɾ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListPopTail(CTLList *list, void *record){
	ListNode *prevP, *nextP;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (list->root == NULL)
		return CTL_NO_VALUE;

	if (list->root ->next == NULL){   //����ֻ��һ���ڵ�
		prevP = list->root;
		list->root = NULL;
		memcpy(record, prevP->data, list->typeSize);
		free(prevP->data);
		free(prevP);
	} else {
		for (prevP=nextP=list->root; nextP->next!=NULL; ){
			prevP = nextP;
			nextP = prevP->next;
		}

		prevP->next = NULL;
		memcpy(record, nextP->data, list->typeSize);
		free(nextP->data);
		free(nextP);
	}

	list->num--;
	return NORMAL;
}


//1��������list�ĵ�numλ�ô���������record
//2�����λ��num(��СֵΪ1)���������Ԫ�������������ݲ��뵽��β
//@return һ�������򷵻�NORMAL�����򷵻���Ӧ������
int CTLListInsert(CTLList *list, void *record, int num){
	int i;
	ListNode *prevP, *node;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (num <= 0)
		return NUM_IS_WRONG;
	if (num > list->num+1) {       //��record���뵽β��
		CTLListPushTail(list, record);
		return NUM_WRONG_BUT_DO_SOMETHING;
	}

	node = (ListNode *)malloc(NODE_SIZE);
	node->data = (void *)malloc(list->typeSize);
	if ((node==NULL) || (node->data==NULL))
		return MALLOC_FAIL;
	memcpy(node->data, record, list->typeSize);
	if (num == 1){
		node->next = list->root;
		list->root = node;
	} else {
		num--;
		prevP = list->root;
		for (i=num; i>1; i--)
			prevP=prevP->next;

		node->next = prevP->next;
		prevP->next = node;
	}

	list->num++;
	return NORMAL;
}

//ɾ������list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ㣬�����ýڵ㴦��dataֵ��record����
//@return ���ɾ���������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListDelete(CTLList *list, void *record, int num){
	int i;
	ListNode *prevP, *nextP;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;
	if ((num<=0) || (num>list->num))
		return NUM_IS_WRONG;

	nextP = list->root;
	if (num == 1){
		list->root = nextP->next;
	} else {
		num--;
		for (i=num; i>0; i--)
		{
			prevP = nextP;
			nextP = prevP->next;
		}
		prevP->next = nextP->next;
	}

	memcpy(record, nextP->data, list->typeSize);
	free(nextP->data);
	free(nextP);
	list->num--;
	return NORMAL;
}


//��ȡ����list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ������ֵ����ɾ������������record����
//@return  �����ȡ�������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListRead(CTLList *list, void *record, int num){
	int i;
	ListNode *prevP, *nextP;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;
	if ((num<=0) || (num>list->num))
		return NUM_IS_WRONG;

	nextP = list->root;
	num--;
	for (i=num; i>0; i--){
		prevP = nextP;
		nextP = prevP->next;
	}
	memcpy(record, nextP->data, list->typeSize);
	return NORMAL;
}


//������list�ĵ�num(��СֵΪ1)λ�ô��Ľڵ��dataֵ����Ϊ*recordֵ
//@return ��������������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLListSet(CTLList *list, void *record, int num){
	int i;
	ListNode *prevP, *nextP;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;
	if ((num<=0) || (num>list->num))
		return NUM_IS_WRONG;

	nextP = list->root;
	num--;
	for (i=num; i>0; i--){
		prevP = nextP;
		nextP = prevP->next;
	}
	memcpy(nextP->data, record, list->typeSize);
	return NORMAL;
}

//��tail��ָ����������ӵ�front��ָ�������β����������ӳ� front������
//@return  ���������򷵻�NORMAL�����򷵻���Ӧ������
int CTLListConnect(CTLList *front, CTLList *tail){
	ListNode *frontTail;

	if (front->typeSize != tail->typeSize)
		return CTL_TYPESIZE_NO_MATCH;
	if ((front==NULL) || (tail==NULL))
		return CTL_PTR_IS_NULL;

	frontTail = CTLListGetTail(*front);
	if (frontTail == NULL)
		front->root = tail->root;
	else
		frontTail->next = tail->root;

	front->num = front->num + tail->num;
	return NORMAL;
}



//��list��data����record�����нڵ㶼ɾ��
//@return  ��������·���ɾ���Ľڵ�ĸ������쳣����·�����Ӧ�Ĵ�����
int CTLListRemoveAll(CTLList *list, const void *record){
	int result = list->num;
	ListNode *pM, *pN, *temp;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;

	pN = list->root;
	while (pN != NULL){
		if (memcmp(pN->data, record, list->typeSize) == 0){
			if (pN == list->root)
				list->root = pN->next;
			else
				pM->next = pN->next;

			temp = pN->next;
			free(pN->data);
			free(pN);
			list->num--;
			pN = temp;
			continue;
		}
		pM = pN;
		pN = pN->next;
	}

	result -= list->num;
	return result;
}

//1�����list�д�������Ԫ��record����ptrָ��ָ������ڵ㡣
//2���������Ľڵ��ж������ptrָ����ǵ�һ����
//3����������������Ľڵ㣬��ptrָ��NULL
//@return ������ڴ����򷵻���Ӧ�Ĵ����ţ����򷵻�NORMAL
int CTLListLocate(CTLList *list, ListNode **ptr, void *record){
	ListNode *p;

	if (list == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;

	*ptr = NULL;
	p = list->root;
	while (p != NULL){
		if (memcmp(p->data, record, list->typeSize) == 0)
		{
			*ptr = p;
			break;
		}
		p = p->next;
	}

	return NORMAL;
}


