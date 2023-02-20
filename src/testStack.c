#include "CTLStack.h"
#include "testStack.h"
#include "debug.h"


static void PrintStackClear(struct CTLStack *stack)
{
	printf("\t ��CTLStackClear()�������ؽ�����!\n");
	DealResult( CTLStackClear(stack) );
}

static void PrintStackEmpty(struct CTLStack stack)
{
	if (CTLStackIsEmpty(stack) == TRUE)
		printf("\t \t���ջ�ǿյģ�\n");
	else
		printf("\t \t���ջ���ǿյģ�\n");
}

static void PrintStackFull(struct CTLStack stack)
{
	if (CTLStackIsFull(stack) == TRUE)
		printf("\t \t���ջ������!\n");
	else
		printf("\t \t���ջ��������!\n");
}


static void TestStackInt(){
    int result, num, flag = TRUE;
    char var;

    INIT_CTL_STACK(int, stackInt1, 8);

    printf("�����������Ϊ:\n"
            "c(CTLStackClear),  e(CTLStackIsEmpty),\n"
			"f(CTLStackIsFull), h(CTLStackPush),p(CTLStackPop),\n"
			"g( CTLStackPeek), o(PrintStack), q(quit)\n");

    while (flag == TRUE){
        printf("������������:");
        scanf("%c", &var);
        getchar();   //���ջس�
        switch (var){
            case 'c':
                PrintStackClear(&stackInt1);
                break;
            case 'e':
                PrintStackEmpty(stackInt1);
                break;
            case 'f':
                PrintStackFull(stackInt1);
                break;
            case 'h':
                printf("������������ջ��ֵ:");
                scanf("%d", &num);
                getchar();
                result = CTLStackPush(&stackInt1, (void *)(&num));
                DealResult(result);
                break;
            case 'p':
                result  = CTLStackPop(&stackInt1, (void *)(&num));
                if (result == NORMAL){
                    printf("\t \t��ջ��ֵ�� %d.\n", num);
                }else{
                    DealResult(result);
                }
                break;
            case 'g':
                result = CTLStackPeek( &stackInt1, (void *)(&num));
				if (result == NORMAL)
					printf("\t \tջ����ֵ��%d.\n", num);
				else
					DealResult(result);
				break;
            case 'o':
                PrintStack(stackInt1);
                break;
            case 'q':
                flag = FALSE;
                break;
            default:
                printf("\t \t�������ֵ %c �쳣�����������\n", var);
        }//end of "switch..."
    }//end of " while (flag == TRUE)"
}//end of "TestStackInt"


static void TestStackChar(){
    int result, flag = TRUE;
    char operatorVar;
    char var;

    INIT_CTL_STACK(char, stackChar1, 8);

    printf("�����������Ϊ:\n"
            "c(CTLStackClear),  e(CTLStackIsEmpty),\n"
			"f(CTLStackIsFull), h(CTLStackPush),p(CTLStackPop),\n"
			"g( CTLStackPeek), o(PrintStack), q(quit)\n");

    while (flag == TRUE){
        printf("������������:");
        scanf("%c", &operatorVar);
        getchar();   //���ջس�
        switch (operatorVar){
            case 'c':
                PrintStackClear(&stackChar1);
                break;
            case 'e':
                PrintStackEmpty(stackChar1);
                break;
            case 'f':
                PrintStackFull(stackChar1);
                break;
            case 'h':
                printf("������������ջ��ֵ:");
                scanf("%c", &var);
                getchar();
                result = CTLStackPush(&stackChar1, (void *)(&var));
                DealResult(result);
                break;
            case 'p':
                result  = CTLStackPop(&stackChar1, (void *)(&var));
                if (result == NORMAL){
                    printf("\t \t��ջ��ֵ�� %c.\n", var);
                }else{
                    DealResult(result);
                }
                break;
            case 'g':
                result = CTLStackPeek( &stackChar1, (void *)(&var));
				if (result == NORMAL)
					printf("\t \tջ����ֵ��%c.\n", var);
				else
					DealResult(result);
				break;
            case 'o':
                PrintStack(stackChar1);
                break;
            case 'q':
                flag = FALSE;
                break;
            default:
                printf("\t \t�������ֵ %c �쳣�����������\n", operatorVar);
        }//end of "switch..."
    }//end of " while (flag == TRUE)"
}// end of "TestStackChar()"

static  void TestStackDouble(){
    int result, flag = TRUE;
    char operatorVar;
    double var;

    INIT_CTL_STACK(double, stackDouble1, 8);

    printf("�����������Ϊ:\n"
            "c(CTLStackClear),  e(CTLStackIsEmpty),\n"
			"f(CTLStackIsFull), h(CTLStackPush),p(CTLStackPop),\n"
			"g( CTLStackPeek), o(PrintStack), q(quit)\n");

    while (flag == TRUE){
        printf("������������:");
        scanf("%c", &operatorVar);
        getchar();   //���ջس�
        switch (operatorVar){
            case 'c':
                PrintStackClear(&stackDouble1);
                break;
            case 'e':
                PrintStackEmpty(stackDouble1);
                break;
            case 'f':
                PrintStackFull(stackDouble1);
                break;
            case 'h':
                printf("������������ջ��ֵ:");
                scanf("%lf", &var);
                getchar();
                result = CTLStackPush(&stackDouble1, (void *)(&var));
                DealResult(result);
                break;
            case 'p':
                result  = CTLStackPop(&stackDouble1, (void *)(&var));
                if (result == NORMAL){
                    printf("\t \t��ջ��ֵ�� %f.\n", var);
                }else{
                    DealResult(result);
                }
                break;
            case 'g':
                result = CTLStackPeek( &stackDouble1, (void *)(&var));
				if (result == NORMAL)
					printf("\t \tջ����ֵ��%f.\n", var);
				else
					DealResult(result);
				break;
            case 'o':
                PrintStack(stackDouble1);
                break;
            case 'q':
                flag = FALSE;
                break;
            default:
                printf("\t \t�������ֵ %c �쳣�����������\n", operatorVar);
        }//end of "switch..."
    }//end of " while (flag == TRUE)"
}// end of "TestStackDouble()"



//����CTLStackCopy���������Ĳ���
static void TestCTLStackCopy()
{
	int result1, result2;
	int i, num, pushInt;

	INIT_CTL_STACK(int, stackInt1, 7);
	INIT_CTL_STACK(int, stackInt2, 9);
	INIT_CTL_STACK(int, stackInt3, 11);

	INIT_CTL_STACK(char, stackChar1, 6);
	while (1)
	{
		CTLStackClear(&stackInt2);

		printf("��������Ҫ��stackInt2ѹջѹ��ֵ�ĸ���(���9��):");
		scanf("%d", &num);
		getchar();
		for (i=0; i<num; i++)
		{
			printf("��������Ҫѹ��ĵ�%d��ֵ��", i+1);
			scanf("%d", &pushInt);
			getchar();
			CTLStackPush(&stackInt2, (void *)(&pushInt));
		}
		PrintStack(stackInt2);

		printf("������stackInt1�����\n");
		result1 = CTLStackCopy(&stackInt1, &stackInt2);
		DealResult(result1);
		PrintStack(stackInt1);

		printf("������stackInt3�����\n");
		result2 = CTLStackCopy(&stackInt3, &stackInt2);
		DealResult(result2);
		PrintStack(stackInt3);

		printf("�������Ͳ��������\n");
		result1 = CTLStackCopy(&stackChar1, &stackInt2);
		DealResult(result1);
	}
}

void TestCTLStack(){
    printf("����CTLStack�Ĳ��ԣ�\n");

    printf("��������Ҫ���Ե����ͣ�int��char��double����, ��������copy���п����Ĳ���\n");
    char testType[11];
    char *typePtr;

    typePtr = fgets(testType, 10, stdin);

    if (testType[strlen(typePtr) - 1] == '\n'){
        testType[strlen(typePtr) - 1] = '\0';
    }

    if (strcmp(typePtr, "int") == 0){
        TestStackInt();
    }else if (strcmp(typePtr, "char") == 0){
        TestStackChar();
    }else  if (strcmp(typePtr, "double") == 0){
        TestStackDouble();
    }else if (strcmp(typePtr, "copy") == 0){
        TestCTLStackCopy();
    }else {
        printf("�������ֵ����, %s\n", typePtr);
    }

    printf("���Խ���!!!!");
}
