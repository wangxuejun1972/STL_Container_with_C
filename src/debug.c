#include "debug.h"




//���� typeSize �ĳ��ȣ����ֵ��
// ���� ������������ĸ�������.
void PrintValue(void *ptr, int typeSize){
    switch (typeSize){
         case TYPE_CHAR:
            printf("%c  ", *((char *)ptr));
            break;
        case TYPE_INT:
              printf("%d  ", *((int *)ptr));
            break;
        case TYPE_DOUBLE:
            printf("%f  ", *((double *)ptr));
            break;
        default:
            printf("printValue() -> ����δ֪��ֵ�� typeSize=" + typeSize);

    }
}

// ��console���result�����ڹ۲�
void DealResult(int result){
    switch(result){
        case NORMAL:
            printf("\t \t \t result is normal\n");
            break;
        case CTL_OUT_OF_RANGE:
            printf("\t \t \t ctl is out of range!\n");
            break;
        case CTL_PTR_IS_NULL:
			printf("\t \t \t ctl ptr is null!\n");
			break;
		case CTL_NO_VALUE:
			printf("\t \t \t ctl no value\n");
			break;
		case CTL_TYPESIZE_NO_MATCH:
			printf("\t \t \t ctl typeSize no match!\n");
			break;
		case RECORD_PTR_IS_NULL:
			printf("\t \t \t record ptr is null\n");
			break;
		case MALLOC_FAIL:
			printf("\t \t \t malloc fail\n");
			break;
		case NUM_IS_WRONG:
			printf("\t \t \t num is wrong\n");
			break;
		case NUM_WRONG_BUT_DO_SOMETHING:
			printf("\t \t \t num wrong but do something\n");
			break;
		default:
			printf("\t \t \t debug.cpp�ļ���DealResult()��������δ����ֵ��\n");
			break;
    }
}// end of "DealResult"


// -------------   queue���Դ��� start  ---------------------//


// ���stack�е����ݵ����ϡ�
void PrintStack(struct CTLStack stack){

    void *ptr;

    char *str = "";
    switch(stack.typeSize){
        case TYPE_CHAR:
            str = "Stack ����������Ϊ char ����\n";
            break;
        case TYPE_INT:
            str = "Stack ����������Ϊ int ����\n";
            break;
        case TYPE_DOUBLE:
            str = "Stack ����������Ϊ double ����\n";
            break;
        default:
            str = "PrintStack ����δ�����typeSize = " + stack.typeSize;

    }
    printf(str);
	printf("stack��typeSize=%d, \t topָ��λ��=%d, \t length=%d\n", stack.typeSize, stack.top, stack.length);

	printf("stack�е�Ԫ�شӵײ�������������:\n");
	for (int i=0; i<=stack.top; i++){
        if (i%10 == 0)
            printf("\n");
        ptr = stack.data;
        ptr = (char *)ptr + i*stack.typeSize;
        PrintValue(ptr, stack.typeSize);
	}
	putchar(10);
}

// �������queue�е����ݣ������ݵ�λ�����*�Ŵ���(��Ϊ���ǰ� length���ȵ����ݶ����)
void PrintQueue(struct CTLQueue queue, int typeSize){
	int i;
	//double *pVar;
	void *pVoid;

	printf("���queue����Ϣ����:\n");
    char *str = "";
    switch(queue.typeSize){
        case TYPE_CHAR:
            str = "\t\tQueue ����������Ϊ char ����\n";
            break;
        case TYPE_INT:
            str = "\t\tQueue ����������Ϊ int ����\n";
            break;
        case TYPE_DOUBLE:
            str = "\t\tQueue ����������Ϊ double ����\n";
            break;
        default:
            str = "\t\tPrintQueue ����δ�����typeSize = " + queue.typeSize;

    }
    printf(str);

    printf("\t\ttypeSize=%d, front=%d, rear=%d, length=%d\n", queue.typeSize, queue.front, queue.rear, queue.length-1);
	printf("\t\t���queue�й���%d��Ԫ��,���������ǣ�\n", CTLQueueGetNum(queue));


	for (i=0; i<queue.length-1; i++){
        if (i%10 == 0)
            printf("\n");

        if ((i<queue.front) || (i>=queue.rear))
            printf("*  ");
        else{
            pVoid = queue.data;
            pVoid = (char *)pVoid + i * queue.typeSize;
            PrintValue(pVoid, typeSize);
        }
    }
    printf("\n");
}//end of "PrintQueue(..."

// -------------   List ���Դ��� start  ---------------------//


//�������list�е������Լ��������ϣ���������������Ϊint���ͣ�
static void PrintListInt(CTLList list){
	int i;
	int *pInt;
	ListNode *ptr = list.root;

	printf("\t ���list��Ԫ��������ռ�ֽ�����%d, ��Ԫ�ظ���Ϊ%d\n", list.typeSize, list.num);
	printf("\t ��Щ���ݶ���int���ͣ����������ǣ�");
	for (i=0; i<list.num; i++){
		if (i%10 == 0)
			printf("\n");

		pInt = (int *)(ptr->data);
		printf("%d  ", *pInt);
		ptr = ptr->next;
	}
	putchar(10);
}

//�������list�е������Լ��������ϣ���������������Ϊdouble���ͣ�
static void PrintListDouble(CTLList list) {
	int i;
	double *pDou;
	ListNode *ptr = list.root;

	printf("\t ���list��Ԫ��������ռ�ֽ�����%d, ��Ԫ�ظ���Ϊ%d\n", list.typeSize, list.num);
	printf("\t ��Щ���ݶ���double���ͣ����������ǣ�");
	for (i=0; i<list.num; i++){
		if (i%10 == 0)
			printf("\n");

		pDou = (double *)(ptr->data);
		printf("%f  ", *pDou);
		ptr = ptr->next;
	}
	putchar(10);
}

//�������list�е������Լ��������ϣ���������������Ϊchar���ͣ�
static void PrintListChar(CTLList list){
	int i;
	char *pChar;
	ListNode *ptr = list.root;

	printf("\t ���list��Ԫ��������ռ�ֽ�����%d, ��Ԫ�ظ���Ϊ%d\n", list.typeSize, list.num);
	printf("\t ��Щ���ݶ���char���ͣ����������ǣ�");
	for (i=0; i<list.num; i++){
		if (i%10 == 0)
			printf("\n");

		pChar = (char *)(ptr->data);
		printf("%c  ", *pChar);
		ptr = ptr->next;
	}
	putchar(10);
}

//�������list�������Լ�������ϣ�������typeSize��С���Զ��������ͣ�
void PrintList(CTLList list){
	switch (list.typeSize){
		case 1:
			PrintListChar(list);
			break;
		case 4:
			PrintListInt(list);
			break;
		case 8:
			PrintListDouble(list);
			break;
		default:
			printf("debug,cpp��PrintList()����typeSize����δ����ֵ\n");
			break;
	}
}



//����size��С��ͬ�����������ʱ����int ,double,����char����
void PrintType(void *record, int size){
	assert(record);

	switch(size){
		case 1:
			printf("%c", *((char *)record));
			break;
		case 4:
			printf("%d", *((int *)record));
			break;
		case 8:
			printf("%f", *((double *)record));
			break;
		default:
			printf("debug.cpp�ļ���PrintListType()�β�size����δ����ֵ\n");
			break;
	}
}


//����size��ͬ���������������val����һ����Ա
void ScanType(union ScanVal *val, int size){
	switch(size){
		case 1:
			printf("������char��������.");
			scanf("%c", &val->ch);
			getchar();
			break;
		case 4:
			printf("������int��������.");
			scanf("%d", &val->i);
			getchar();
			break;
		case 8:
			printf("������double��������.");
			scanf("%lf", &val->dou);
			getchar();
			break;
		default:
			printf("debug.cpp�ļ���ScanfType()�β�size����δ����ֵ\n");
			break;
	}
}


//�������vrector��������ϣ��Լ���������(����������Ϊint)
static void PrintVectorInt(CTLVector vector){
	int i, *pInt;
	void *ptr;

	printf("\t vector�����������:\n"       \
		   "\t typeSize=%d, length=%d, quan=%d\n", vector.typeSize, vector.length, vector.quan);
	printf("vector������������:");
	for (i=0; i<vector.quan; i++){
		if (i%10 == 0)
			putchar(10);
		ptr = vector.data;
		ptr = (char *)ptr + i*vector.typeSize;
		pInt = (int *)ptr;
		printf("%d  ", *pInt);

	}
	printf("\n");
}

//�������vrector��������ϣ��Լ���������(����������Ϊdouble)
static void PrintVectorDouble(CTLVector vector){
	int i;
	double *pDou;
	void *ptr;

	printf("\t vector�����������:\n"       \
		   "\t typeSize=%d, length=%d, quan=%d\n", vector.typeSize, vector.length, vector.quan);
	printf("vector������������:");
	for (i=0; i<vector.quan; i++){
		if (i%10 == 0)
			putchar(10);
		ptr = vector.data;
		ptr = (char *)ptr + i*vector.typeSize;
		pDou = (double *)ptr;
		printf("%f  ", *pDou);

	}
	printf("\n");
}

//�������vrector��������ϣ��Լ���������(����������Ϊchar)
static void PrintVectorChar(CTLVector vector){
	int i;
	char *pChar;
	void *ptr;

	printf("\t vector�����������:\n"       \
		   "\t typeSize=%d, length=%d, quan=%d\n", vector.typeSize, vector.length, vector.quan);
	printf("vector������������:");
	for (i=0; i<vector.quan; i++){
		if (i%10 == 0)
			putchar(10);
		ptr = vector.data;
		ptr = (char *)ptr + i*vector.typeSize;
		pChar = (char *)ptr;
		printf("%c  ", *pChar);

	}
	printf("\n");
}

//�������ܣ�1���������vrector��������ϣ��Լ���������(����typeSize��С���Զ�ѡ������)
void PrintVector(struct CTLVector vector){
	switch (vector.typeSize){
		case 1:
			PrintVectorChar(vector);
			break;
		case 4:
			PrintVectorInt(vector);
			break;
		case 8:
			PrintVectorDouble(vector);
			break;
		default:
			printf("debug.cpp�ļ���PrintVector()����typeSize����δ����ֵ\n");
			break;
	}
}



