#include "testList.h"


//�����list������ղ���֮��Ľ����Ϣ���
static void PrintListClear(CTLList *list){
	int result;

	result = CTLListClear(list);
	if (result == NORMAL)
		printf("\t\t ���������ղ����������!\n");
	else
	{
		printf("\t\t ���������ղ�������쳣��ԭ���ǣ�");
		DealResult(result);
	}
}


//�����list�Ƿ�Ϊ�յ���Ϣ���
static void PrintListEmpty(CTLList list){
	if (CTLListIsEmpty(list) == TRUE)
		printf("\t\t ��������ǿյ�\n");
	else
		printf("\t\t ������в��ǿյ�\n");
}


//���list��Ԫ�ظ������
static void PrintListNum(CTLList list){
	printf("\t\t ���������Ԫ�صĸ���Ϊ%d\n", CTLListGetNum(list));
}


//����CTLListGetHead()����������һ���ڵ���������
static void TestListGetHead(CTLList list){
	ListNode *head;

	printf("\t\t����CTLListGetHead()����\n");
	head = CTLListGetHead(list);
	if (head == NULL)
		printf("\t\t��������ǿյ�,û����ν��һ���ڵ�\n");
	else {
		printf("\t\t������еĵ�һ���ڵ��������:");
		PrintType(head->data, list.typeSize);
		putchar(10);
	}
}

//����CTLListGetTail()�����������һ���ڵ���������
static void TestListGetTail(CTLList list){
	ListNode *tail;

	printf("\t\t����CTLListGetTail()����\n");
	tail = CTLListGetTail(list);
	if (tail == NULL)
		printf("\t\t\t��������ǿյ�,û����ν���һ���ڵ�\n");
	else {
		printf("\t\t\t������е����һ���ڵ��������:");
		PrintType(tail->data, list.typeSize);
		putchar(10);
	}
}

//����CTLListPushFront()����;
static void TestListPushFront(CTLList *list){
	int result;
	union ScanVal val;

	printf("\t\t�������ڲ���CTLListPushFront()����;\n");
	printf("\t\t\t֮ǰ��������:\n");
	PrintList(*list);
	printf("\t\t��������Ҫ���������\n");
	ScanType(&val, list->typeSize);
	result = CTLListPushFront(list, (void *)(&val));
	if (result == NORMAL){
		printf("\t\t\t���������������������\n");
		PrintList(*list);
	}
	else
		DealResult(result);
}

//����CTLListPushTail()����;
static void TestListPushTail(CTLList *list){
	int result;
	union ScanVal val;

	printf("\t\t�������ڲ���CTLListPushTail()����;\n");
	printf("\t\t\t֮ǰ��������:\n");
	PrintList(*list);
	printf("\t\t��������Ҫ���������\n");
	ScanType(&val, list->typeSize);
	result = CTLListPushTail(list, (void *)(&val));
	if (result == NORMAL){
		printf("\t\t\t���������������������\n");
		PrintList(*list);
	}
	else
		DealResult(result);
}

//����CTLListPopFront()����
static void TestListPopFront(CTLList *list){
	int result;
	union ScanVal record;

	printf("\t\t���ڲ���CTLListPopFront()����\n"    \
		    "\t\t\t֮ǰ�������ǣ�\n");
	PrintList(*list);
	result = CTLListPopFront(list, (void *)(&record));
	if (result == NORMAL){
		printf("\t\t\t��������������������������");
		PrintType((void *)(&record), list->typeSize);
		putchar(10);
	}
	else
		DealResult(result);

	printf("\t\t��������֮���������:\n");
	PrintList(*list);
}

//����CTLListPopTail()����
static void TestListPopTail(CTLList *list){
	int result;
	union ScanVal record;

	printf("\t\t���ڲ���CTLListPopTail()����\n"    \
		    "\t\t\t֮ǰ�������ǣ�\n");
	PrintList(*list);
	result = CTLListPopTail(list, (void *)(&record));
	if (result == NORMAL){
		printf("\t\t��������������������������");
		PrintType((void *)(&record), list->typeSize);
		putchar(10);
	}
	else
		DealResult(result);

	printf("\t\t��������֮���������:\n");
	PrintList(*list);
}

//����CTLListInsert()����
static void TestListInsert(CTLList *list){
	int insNum, result;
	union ScanVal insVal;

	printf("\t\t���ڲ���CTLListInsert()����\n"       \
		   "\t\t\tԭ���������ǣ�\n");
	PrintList(*list);
	printf("\t\t\t��������������λ��:");
	scanf("%d", &insNum);
	getchar();
	printf("\t\t������������������\n");
	ScanType(&insVal, list->typeSize);

	result = CTLListInsert(list, (void *)(&insVal), insNum);
	DealResult(result);
	printf("\t\t\t������������ǣ�\n");
	PrintList(*list);
}


//����CTLListDelete()����
static void TestListDelete(CTLList *list){
	int delNum, result;
	union ScanVal val;

	printf("\t\t���ڲ��Ե���CTLListDelete()����\n"   \
		    "\t\t\t����֮ǰ��������:\n");
	PrintList(*list);
	printf("\t\t����������ɾ����λ��:");
	scanf("%d", &delNum);
	getchar();
	result = CTLListDelete(list, (void *)(&val), delNum);
	if (result == NORMAL){
		printf("\t\t\t����������ɾ���������ǣ�");
		PrintType((void *)(&val), list->typeSize);
		putchar(10);
		printf("\t\t\t�������������:\n");
		PrintList(*list);
	}
	else
		DealResult(result);
}

//����CTLListRead()����
static void TestListRead(CTLList *list){
	int readNum, result;
	union ScanVal val;

	printf("\t\t���ڲ��Ե���CTLListRead()����\n");
	printf("\t\t\t�����������ȡ��λ��:");
	scanf("%d", &readNum);
	getchar();
	result = CTLListRead(list, (void *)(&val), readNum);
	if (result == NORMAL){
		printf("\t\t\t��ȡ������������ȡ�������ǣ�");
		PrintType((void *)(&val), list->typeSize);
		putchar(10);
	}
	else
		DealResult(result);
}


//����CTLListSet()����
static void TestListSet(CTLList *list){
	int setNum, result;
	union ScanVal setVal;

	printf("\t\t���ڲ���CTLListSet()����\n"       \
		   "\t\t\tԭ���������ǣ�\n");
	PrintList(*list);
	printf("\t\t\t�������������õ�λ��:");
	scanf("%d", &setNum);
	getchar();
	printf("\t\t\t�������������õ�����\n");
	ScanType(&setVal, list->typeSize);

	result = CTLListSet(list, (void *)(&setVal), setNum);
	if (result == NORMAL)
	{
		printf("\t\t\t���ò�������,���ú������Ϊ\n");
		PrintList(*list);
	}
	else
		DealResult(result);
}

//����CTLListRemoveAll()����
static void TestListRemoveAll(CTLList *list){
	int result;
	union ScanVal val;

	printf("\t\t���ڲ��Ե���CTLListRemoveAll()����\n"   \
		    "\t\t\t����֮ǰ��������:\n");
	PrintList(*list);
	printf("\t\t����������ɾ��������:\n");
	ScanType(&val, list->typeSize);
	result = CTLListRemoveAll(list, (void *)(&val));
	printf("\t\t\t��������, ��ɾ����%d�����ݣ�\n", result);
	printf("\t\t\t�������������:\n");
	PrintList(*list);
}



//����CTLListLocate()����
static void TestListLocate(CTLList *list){
	int result;
	union ScanVal val;
	ListNode *pos, *ptr;

	printf("\t\t�������ڲ���CTLListLocate()����\n"   \
		   "\t\t�������������:\n");
	PrintList(*list);
	printf("\t\t\t�������붨λ����ֵ:\n");
	ScanType(&val, list->typeSize);
	result = CTLListLocate(list, &pos, (void *)(&val));
	if (result != NORMAL)
		DealResult(result);
	else{
		if (pos == NULL)
			printf("\t\t\t�����в����ڰ������ֵ�Ľ��\n");
		else {
			printf("\t\t\t�������ֵ��:");
			PrintType(pos->data, list->typeSize);
			putchar(10);

			ptr = pos->next;
			if(ptr != NULL){
				printf("\t\t\t���������һ������������:");
				PrintType(ptr->data, list->typeSize);
				putchar(10);
			}
			else
				printf("\t\t\t�������Ѿ������һ�������\n");
		}
	}
}


//�������ܣ�����CTLListConnect()����
static void TestListConnect(){
	int i, val, result;
	char ch;

	INIT_CTL_LIST(int ,listInt1);
	INIT_CTL_LIST(int, listInt2);
	INIT_CTL_LIST(char, listChar);

	printf("\t\tΪ�˷��������ÿ��list����ĸ�����\n");
	for (i=0; i<4; i++){
		printf("\t����listInt1�ĵ�%d������:", i+1);
		scanf("%d", &val);
		getchar();
		if (CTLListPushTail(&listInt1, (void *)(&val)) != NORMAL)
			printf("\t�������ݳ����쳣");
	}
	for (i=0; i<4; i++){
		printf("\t����listInt2�ĵ�%d������:", i+1);
		scanf("%d", &val);
		getchar();
		if (CTLListPushTail(&listInt2, (void *)(&val)) != NORMAL)
			printf("\t�������ݳ����쳣");
	}
	for (i=0; i<4; i++){
		printf("\t����listChar�ĵ�%d������:", i+1);
		scanf("%c", &ch);
		getchar();
		if (CTLListPushTail(&listChar, (void *)(&ch)) != NORMAL)
			printf("\t�������ݳ����쳣");
	}

	printf("\t\t\t listInt1������ǣ�\n");
	PrintList(listInt1);
	printf("\t\t\t listInt2�������:\n");
	PrintList(listInt2);
	printf("\t\t\t listChar������ǣ�\n");
	PrintList(listChar);

	printf("\t\tlistInt1��ͷ��listInt2��β��������\n");
	result = CTLListConnect(&listInt1, &listInt2);
	if (result != NORMAL)
		DealResult(result);
	printf("\t\t\t���Ӻ��listInt1����ǣ�\n");
	PrintList(listInt1);

	printf("\t\t��listInt2Ϊͷ�����Ӻ��listInt1��β����������\n");
	result = CTLListConnect(&listInt2, &listInt1);
	if (result != NORMAL)
		DealResult(result);
	printf("\t\t\t���Ӻ��listInt2����ǣ�\n");
	PrintList(listInt2);

	printf("\t\t\t��listInt1��ͷ��listChar��β����������\n");
	result = CTLListConnect(&listInt1, &listChar);
	if (result != NORMAL)
		DealResult(result);

	FREE_CTL_LIST(listInt1);
	FREE_CTL_LIST(listInt2);
	FREE_CTL_LIST(listChar);
}



//����list���Ե��ܺ��������ⲿ�Ľӿں���
void TestList(){
	int flag, type, quit;
	char choice;
	CTLList *list;

	INIT_CTL_LIST(int, listInt);
	INIT_CTL_LIST(char, listChar);
	INIT_CTL_LIST(double, listDou);

	quit = 1;
	while (quit){
		printf("������������Ե�����\n"   \
			   "1(int), 2(char), 3(double) :");
		scanf("%d", &type);
		getchar();
		flag = TRUE;
		switch (type){
			case 1:
				list = &listInt;
				break;
			case 2:
				list = &listChar;
				break;
			case 3:
				list = &listDou;
				break;
			default:
				flag = FALSE;
				break;
		} //switch (type) is over

		printf("��������ǣ�\n"   \
			   "c(Clear), e(IsEmpty), n(GetNum), h(GetHead)\n"   \
			    "t(GetTail), a(PushFront), b(PushTail), \n"      \
				"x(PopFront), y(PopTail), i(Insert) \n"    \
				"d(Delete), r(Read), s(Set), z(Connect)\n"   \
				"m(RemoveAll), l(locate), p(PrintList), q(quit)\n");
		while (flag == TRUE){
			printf("\t\t��������ѡ��Ĳ������:");
			scanf("%c", &choice);
			getchar();

			switch (choice){
				case 'c':
					PrintListClear(list);
					break;
				case 'e':
					PrintListEmpty(*list);
					break;
				case 'n':
					PrintListNum(*list);
					break;
				case 'h':
					TestListGetHead(*list);
					break;
				case 't':
					TestListGetTail(*list);
					break;
				case 'a':
					TestListPushFront(list);
					break;
				case 'b':
					TestListPushTail(list);
					break;
				case 'x':
					TestListPopFront(list);
					break;
				case 'y':
					TestListPopTail(list);
					break;
				case 'i':
					TestListInsert(list);
					break;
				case 'd':
					TestListDelete(list);
					break;
				case 'r':
					TestListRead(list);
					break;
				case 's':
					TestListSet(list);
					break;
				case 'z':
					 TestListConnect();
					 break;
				case 'm':
					TestListRemoveAll(list);
					break;
				case 'l':
					TestListLocate(list);
					break;
				case 'p':
					PrintList(*list);
					break;
				case 'q':
					flag = FALSE;
					break;
				default:
					printf("�������ֵ����\n");
					break;
			} //switch (choice) is over
			printf("\n\n");
		}  //while (flg == TURE) is over

		printf("\t\t����0�������ԣ��������ֵ�����������:");
		scanf("%d", &quit);
		getchar();
	}//while (quit) is over

	FREE_CTL_LIST(listInt);
	FREE_CTL_LIST(listChar);
	FREE_CTL_LIST(listDou);

}





