#include "testQueue.h"

//��queue�Ƿ�Ϊ�ն��е�״̬���
static void PrintQueueEmpty(struct CTLQueue queue){
	if (CTLQueueIsEmpty(queue) == TRUE)
		printf("\t ��������ǿյ�\n");
	else
		printf("\t ��������Ƿǿյ�\n");
}

//����������Ƿ�Ϊ����״̬���
static void PrintQueueFull(struct CTLQueue queue){
	if (CTLQueueIsFull(queue) == TRUE)
		printf("\t �������������\n");
	else
		printf("\t ������в�������\n");
}


//�����������Ԫ�ص��������
static void PrintQueueQuan(struct CTLQueue queue){
	printf("\t ���������Ԫ�ص������� %d.\n", CTLQueueGetNum(queue));
}

//����CTLQueueClear������������������״̬���
static void PrintQueueClear(struct CTLQueue *queue){
	int result = CTLQueueClear(queue);

	if (result == NORMAL)
		printf("\t ��������Ѿ��������\n");
	else
	{
		printf("\t ����������ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}

//����CTLQueueEnter()��������queue��β����һ��int������
static void TestEnterInt(struct CTLQueue *queue){
	int var, result;

	printf("��������������int������:");
	scanf("%d", &var);
	getchar();

	result = CTLQueueEnter(queue, &var);
	if (result == NORMAL)
		printf("\t ���ӳɹ�\n");
	else
	{
		printf("\t ����ʧ��,ԭ����:");
		DealResult(result);
	}
}



//����CTLQueueEnter()��������queue��β����һ��double������
static void TestEnterDouble(struct CTLQueue *queue){
	double var;
	int result;

	printf("��������������double������:");
	scanf("%lf", &var);
	getchar();

	result = CTLQueueEnter(queue, &var);
	if (result == NORMAL)
		printf("\t ���ӳɹ�\n");
	else
	{
		printf("\t ����ʧ��,ԭ����:");
		DealResult(result);
	}
}


//����CTLQueueEnter()��������queue��β����һ��char������
static void TestEnterChar(struct CTLQueue *queue){
	char var;
	int result;

	printf("��������������char������:");
	scanf("%c", &var);
	getchar();

	result = CTLQueueEnter(queue, &var);
	if (result == NORMAL)
		printf("\t ���ӳɹ�\n");
	else
	{
		printf("\t ����ʧ��,ԭ����:");
		DealResult(result);
	}
}


//����CTLQueueDelete()��������queue�Ķ�ͷ��Ԫ��ɾ��(Ԫ������Ϊint)
static void TestDeleteInt(struct CTLQueue *queue)
{
	int var, result;

	result = CTLQueueDelete(queue, &var);
	if (result == NORMAL){
		printf("\t ���Ӳ����ɹ�����ͷԪ����%d\n", var);
	} else {
		printf("\t ���Ӳ���ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}

//����CTLQueueDelete()��������queue�Ķ�ͷ��Ԫ��ɾ��(Ԫ������Ϊdouble)
static void TestDeleteDouble(struct CTLQueue *queue){
	double var;
	int result;

	result = CTLQueueDelete(queue, &var);
	if (result == NORMAL)
		printf("\t ���Ӳ����ɹ�����ͷԪ����%f\n", var);
	else
	{
		printf("\t ���Ӳ���ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}

//����CTLQueueDelete()��������queue�Ķ�ͷ��Ԫ��ɾ��(Ԫ������Ϊchar)
static void TestDeleteChar(struct CTLQueue *queue){
	char var;
	int result;

	result = CTLQueueDelete(queue, &var);
	if (result == NORMAL)
		printf("\t ���Ӳ����ɹ�����ͷԪ����%c\n", var);
	else
	{
		printf("\t ���Ӳ���ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}


//����CTLQueueGetHead()������ȡ��ͷԪ�أ�Ԫ������Ϊint��
static void TestGetHeadInt(struct CTLQueue *queue){
	int var, result;

	result = CTLQueueGetHead(queue, &var);
	if (result == NORMAL)
		printf("\t ȡ��ͷ�����ɹ�����ͷԪ����%d\n", var);
	else
	{
		printf("\t ȡ��ͷ����ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}

//�������ܣ�����CTLQueueGetHead()������ȡ��ͷԪ�أ�Ԫ������Ϊdouble��
static void TestGetHeadDouble(struct CTLQueue *queue){
	double var;
	int result;

	result = CTLQueueGetHead(queue, &var);
	if (result == NORMAL)
		printf("\t ȡ��ͷ�����ɹ�����ͷԪ����%f\n", var);
	else
	{
		printf("\t ȡ��ͷ����ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}

//����CTLQueueGetHead()������ȡ��ͷԪ�أ�Ԫ������Ϊchar��
static void TestGetHeadChar(struct CTLQueue *queue){
	char var;
	int result;

	result = CTLQueueGetHead(queue, &var);
	if (result == NORMAL)
		printf("\t ȡ��ͷ�����ɹ�����ͷԪ����%c\n", var);
	else
	{
		printf("\t ȡ��ͷ����ʧ�ܣ�ԭ����");
		DealResult(result);
	}
}


//����queue���������Ĳ��ԣ���������Ϊint���ͣ�
static void TestQueueInt(){
	char choice;
	int flg = TRUE;

	INIT_CTL_QUEUE(int, queue, 7);

	printf("�������������\n"
		"e(CTLQueueIsEmpty), f(CTLQueueIsFull), t(CTLQueueEnter)\n"
		"g(CTLQueueGetHead), d(CTLQueueDelete), c(CTLQueueClear)\n"
		"a(CTLQueueGetNum), p(PrintQueue), q(�˳���β���)\n");

	while (flg == TRUE){
		printf("��������ѡ��Ĳ������:");
		scanf("%c", &choice);
		getchar();

		switch (choice){
			case 'e':
				PrintQueueEmpty(queue);
				break;
			case 'f':
				PrintQueueFull(queue);
				break;
			case 't':
				TestEnterInt(&queue);
				break;
			case 'g':
				TestGetHeadInt(&queue);
				break;
			case 'd':
				TestDeleteInt(&queue);
				break;
			case 'c':
				PrintQueueClear(&queue);
				break;
			case 'a':
				PrintQueueQuan(queue);
				break;
			case 'p':
				PrintQueue(queue, queue.typeSize);
				break;
			case 'q':
				flg = FALSE;
				break;
			default:
				printf("������Ĳ���ѡ���Ǵ����\n");
				break;
		}//end of "switch"
	}  //end of "while (flg == TRUE){"
}//end of "static void TestQueueInt()"




//����queue���������Ĳ��ԣ���������Ϊdouble���ͣ�
static void TestQueueDouble(){
	char choice;
	int flg = TRUE;

	INIT_CTL_QUEUE(double, queue, 6);

	printf("�������������\n"
		"e(CTLQueueIsEmpty), f(CTLQueueIsFull), t(CTLQueueEnter)\n"
		"g(CTLQueueGetHead), d(CTLQueueDelete), c(CTLQueueClear)\n"
		"a(CTLQueueGetQuan), p(PrintQueue), q(�˳���β���)\n");

	while (flg == TRUE){
		printf("��������ѡ��Ĳ������:");
		scanf("%c", &choice);
		getchar();

		switch (choice){
			case 'e':
				PrintQueueEmpty(queue);
				break;
			case 'f':
				PrintQueueFull(queue);
				break;
			case 't':
				TestEnterDouble(&queue);
				break;
			case 'g':
				TestGetHeadDouble(&queue);
				break;
			case 'd':
				TestDeleteDouble(&queue);
				break;
			case 'c':
				PrintQueueClear(&queue);
				break;
			case 'a':
				PrintQueueQuan(queue);
				break;
			case 'p':
				PrintQueue(queue, queue.typeSize);
				break;
			case 'q':
				flg = FALSE;
				break;
			default:
				printf("������Ĳ���ѡ���Ǵ����\n");
				break;
		}
	}//end of "while (flg == TRUE)"
}



//����queue���������Ĳ��ԣ���������Ϊchar���ͣ�
static void TestQueueChar(){
	char choice;
	int flg = TRUE;

	//INIT_CTL_QUEUE(char ,queue, 5);

	INIT_CTL_QUEUE(char, queue, 5);

	printf("�������������\n"
		"e(CTLQueueIsEmpty), f(CTLQueueIsFull), t(CTLQueueEnter)\n"
		"g(CTLQueueGetHead), d(CTLQueueDelete), c(CTLQueueClear)\n"
		"a(CTLQueueGetNum), p(PrintQueue), q(�˳���β���)\n");

	while (flg == TRUE){
		printf("��������ѡ��Ĳ������:");
		scanf("%c", &choice);
		getchar();

		switch (choice){
			case 'e':
				PrintQueueEmpty(queue);
				break;
			case 'f':
				PrintQueueFull(queue);
				break;
			case 't':
				TestEnterChar(&queue);
				break;
			case 'g':
				TestGetHeadChar(&queue);
				break;
			case 'd':
				TestDeleteChar(&queue);
				break;
			case 'c':
				PrintQueueClear(&queue);
				break;
			case 'a':
				PrintQueueQuan(queue);
				break;
			case 'p':
				PrintQueue(queue, queue.typeSize);
				break;
			case 'q':
				flg = FALSE;
				break;
			default:
				printf("������Ĳ���ѡ���Ǵ����\n");
				break;
		}
	}//end of "while (flg == TRUE)"
}


//�������ܣ�ר�Ž���CTLQueueCopy()���Եĺ�������int��Ϊ��
static void TestQueueCopy(){
	char choice;
	int flg = TRUE;

	INIT_CTL_QUEUE(int, queInt1, 5);
	INIT_CTL_QUEUE(int, queInt2, 6);
	INIT_CTL_QUEUE(int, queInt3, 7);
	INIT_CTL_QUEUE(double, queDouble, 6);

	printf("����queue�ĸ��ƣ��ȳ�ʼ��һ��ջ");

	printf("�������������\n"
		"t(CTLQueueEnter), d(CTLQueueDelete)\n"
		"p(PrintQueue), q(�˳���β���)\n");

	while (flg == TRUE){
		printf("��������ѡ��Ĳ������:");
		scanf("%c", &choice);
		getchar();

		switch (choice){
			case 't':
				TestEnterInt(&queInt2);
				break;
			case 'd':
				TestDeleteInt(&queInt2);
				break;
			case 'p':
				PrintQueue(queInt2, queInt2.typeSize);
				break;
			case 'q':
				flg = FALSE;
				break;
			default:
				printf("\t ������Ĳ���ѡ���Ǵ����\n");
				break;
		}
	}

	printf("  ������queInt2��queInt1����\n");
	DealResult( CTLQueueCopy(&queInt1, &queInt2) );
	printf("\t queInt1����Ϣ�ǣ�\n");
	PrintQueue(queInt1, queInt1.typeSize);
	printf("\t queInt2����Ϣ�ǣ�\n");
	PrintQueue(queInt2, queInt2.typeSize);

	printf("\n\n");
	printf("  ������queInt2��queInt3����\n");
	DealResult( CTLQueueCopy(&queInt3, &queInt2) );
	printf("\t queInt3����Ϣ�ǣ�\n");
	PrintQueue(queInt3, queInt3.typeSize);
	printf("\t queInt2����Ϣ�ǣ�\n");
	PrintQueue(queInt2, queInt2.typeSize);

	printf("\n\n");
	printf("  ������queInt2��queDouble����\n");
	DealResult( CTLQueueCopy(&queDouble, &queInt2) );
	printf("\t queDouble����Ϣ�ǣ�\n");
	PrintQueue(queDouble, queDouble.typeSize);
	printf("\t queInt2����Ϣ�ǣ�\n");
	PrintQueue(queInt2, queInt2.typeSize);
}


//����queue���Ե����ⲿ�Ľӿں���
void TestQueue()
{
	int var = 1;

	printf("��������Ҫ���Ե����ͣ� 1:queue��int���ͣ� 2:double���ͣ�  "
        "3:char����,  4:����queue�ĸ���,  0:�˳�����\n");

    scanf("%d", &var);
    getchar();

    while (var != 0){
        switch (var){
            case 1:
                TestQueueInt();
                break;
            case 2:
                TestQueueDouble();
                break;
            case 3:
                TestQueueChar();
                break;
            case 4:
                TestQueueCopy();
                break;
            case 0:
                var = 0;
                break;
            default:
                printf("��������δ�����ֵ %d\n", var);
        }

        printf("��������Ҫ���Ե����ͣ� 1:queue��int���ͣ� 2:double���ͣ�  "
        "3:char����,  4:����queue�ĸ���,  0:�˳�����:\n");

        scanf("%d", &var);
        getchar();
    }


}






