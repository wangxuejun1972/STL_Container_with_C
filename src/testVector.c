#include "testVector.h"


static void TestVectorBegin(CTLVector vector){
	void *ptr = CTLVectorBegin(vector);

	if (ptr == NULL)
		printf("\t\t\t���vectorΪ�գ�û����ν��һ��Ԫ��.\n");
	else{
		printf("\t\t\t���Vector�ĵ�һ��Ԫ����:");
		PrintType(ptr, vector.typeSize);
		putchar(10);
	}
}


static void TestVectorEnd(CTLVector vector){
	void *ptr = CTLVectorEnd(vector);

	if (ptr == NULL)
		printf("\t\t\t���vectorΪ�գ�û����ν���һ��Ԫ��.\n");
	else{
		printf("\t\t\t���Vector�����һ��Ԫ����:");
		PrintType(ptr, vector.typeSize);
		putchar(10);
	}
}

static void TestVectorEmpty(CTLVector vector){
	if (CTLVectorEmpty(vector) == TRUE)
		printf("\t\t\t���vectorΪ�ա�\n");
	else
		printf("\t\t\t���vector���ǿյ�.\n");
}


static void TestVectorSize(CTLVector vector){
	printf("\t\t\t���vector��Ԫ�ظ�����%d\n", CTLVectorSize(vector));
}


static void TestVectoGetAt(CTLVector *vector){
	int num, result;
	union ScanVal val;
	void *record = (void *)(&val);

	printf("\t����������õ����ݵ�λ��:");
	scanf("%d", &num);
	getchar();
	result = CTLVectorGetAt(vector, record, num);
	if (result == NORMAL){
		printf("\t\tvector��%d�������ǣ�", num);
		if (record == NULL)   //������Eraseλ��
			printf("*");
		else
			PrintType(record, vector->typeSize);
		printf("\n");
	}
	else
		DealResult(result);
}

static void TestVectorSetAt(CTLVector *vector){
	int num, result;
	void *record;
	union ScanVal val;

	printf("\t����֮ǰ��vector������:\n");
	PrintVector(*vector);
	printf("\t�����������������ݵ�λ��:");
	scanf("%d", &num);
	getchar();
	printf("\t����������Ҫ���õ�����.\n");
	ScanType(&val, vector->typeSize);
	record = (void *)(&val);

	result = CTLVectorSetAt(vector, record, num);
	if (result == NORMAL){
		printf("\t\tvector��%d�������ǣ�", num);
		if (record == NULL)   //������Eraseλ��
			printf("*");
		else
			PrintType(record, vector->typeSize);
		printf("\n");
	}
	else
		DealResult(result);
	printf("\t\t����֮���vector��������:\n");
	PrintVector(*vector);
}



static void TestVectorInsert(CTLVector *vector){
	int num, result;
	union ScanVal val;

	printf("\t����֮ǰ��vector������:\n");
	PrintVector(*vector);
	printf("\t����������������ݵ�λ��:");
	scanf("%d", &num);
	getchar();
	printf("\t��������Ҫ���������.\n");
	ScanType(&val, vector->typeSize);

	result = CTLVectorInsert(vector, (void *)(&val), num);
	DealResult(result);
	printf("\t\t����֮���vector��������:\n");
	PrintVector(*vector);
}

static void TestVectorSetSize(CTLVector *vector){
	int len;

	printf("\t���ó���֮ǰ��vector��:\n");
	PrintVector(*vector);
	printf("\t�������������õ��³���:");
	scanf("%d", &len);
	getchar();
	DealResult(CTLVectorSetSize(vector, len));
	printf("\t���ó���֮���vector��:\n");
	PrintVector(*vector);
}


static void TestVectorErase(CTLVector *vector){
	int pos;

	printf("\t\t��������֮ǰ��vector�ǣ�\n");
	PrintVector(*vector);
	printf("\t\t���������������λ�ã�");
	scanf("%d", &pos);
	getchar();
	DealResult(CTLVectorErase(vector, pos));
	printf("\t\t��������֮���vector�ǣ�\n");
	PrintVector(*vector);
}

static void TestVectorDelete(CTLVector *vector){
	int pos;

	printf("\t\tɾ������֮ǰ��vector�ǣ�\n");
	PrintVector(*vector);
	printf("\t\t����������ɾ����λ�ã�");
	scanf("%d", &pos);
	getchar();
	DealResult(CTLVectorDelete(vector, pos));
	printf("\t\tɾ������֮���vector�ǣ�\n");
	PrintVector(*vector);
}

static void TestVectorClear(CTLVector *vector){
	printf("\t\t�������֮ǰ��vector�ǣ�\n");
	PrintVector(*vector);
	CTLVectorClear(vector);
	printf("\t\t�������֮���vector�ǣ�\n");
	PrintVector(*vector);
}

static void TestVectorCopy(){
	int i, result, var;

	INIT_CTL_VECTOR(int, vecInt1, 3);
	INIT_CTL_VECTOR(int, vecInt2, 5);
	INIT_CTL_VECTOR(int, vecInt3, 7);
	INIT_CTL_VECTOR(char, vecChar, 5);

	printf("\t���ڲ���CTLVectorCopy()����\n");
	for (i=0; i<vecInt2.length-1; i++){
		printf("\t\t���������vecInt2�ĵ�%d������:", i+1);
		scanf("%d", &var);
		getchar();
		result = CTLVectorInsert(&vecInt2, (void *)(&var), i+1);
		if (result != NORMAL)
			printf("\t\t����vecInt2���ݹ����г����쳣\n");
	}

	printf("\t\t\tvecInt2��������:\n");
	PrintVector(vecInt2);

	printf("��vecInt2Ϊsrc����vecInt1Ϊdst����Copy����.\n");
	result = CTLVectorCopy(&vecInt1, &vecInt2);
	DealResult(result);
	printf("\t\t���ƺ��vecInt1��������:\n");
	PrintVector(vecInt1);

	printf("\t��vecInt2Ϊsrc����vecInt3Ϊdst����Copy����.\n");
	result = CTLVectorCopy(&vecInt3, &vecInt2);
	DealResult(result);
	printf("\t���ƺ��vecInt3��������:\n");
	PrintVector(vecInt3);

	printf("\t��vecInt2Ϊsrc����vecCharΪdst����Copy����.\n");
	result = CTLVectorCopy(&vecChar, &vecInt2);
	DealResult(result);
	printf("\t���ƺ��vecChar��������:\n");
	PrintVector(vecChar);

	FREE_CTL_VECTOR(vecInt1);
	FREE_CTL_VECTOR(vecInt2);
	FREE_CTL_VECTOR(vecInt3);
	FREE_CTL_VECTOR(vecChar);
}


void TestVector(){
	int type, flg, quit;
	char choice;
	CTLVector *vec;

	INIT_CTL_VECTOR(int, vecInt, 8);
	INIT_CTL_VECTOR(char, vecChar, 8);
	INIT_CTL_VECTOR(double, vecDou, 8);

	quit = 1;
	while (quit){
		printf("\t\t1(int), 2(char), 3(double),��������Ҫ���Ե�����;");
		scanf("%d", &type);
		getchar();
		switch (type){
			case 1:
				vec = &vecInt;
				break;
			case 2:
				vec = &vecChar;
				break;
			case 3:
				vec = &vecDou;
				break;
			default:
				printf("�������˴����ֵ,\n");
				break;
		}  //switch (type) is over

		printf("�������Ϊ��\n"   \
			    "b(begin), n(end), e(empty), l(size)\n"  \
				 "g(GetAt), s(SetAt), i(insert), a(SetSize)\n"   \
				 "r(Erase), d(Delete), c(Clear), \n"    \
				 "p(Print), y(Copy), q(quit)\n");
		flg = TRUE;
		while (flg == TRUE){
			printf("\t��������ѡ��Ĳ������:");
			scanf("%c", &choice);
			getchar();

			switch (choice){
				case 'b':
					TestVectorBegin(*vec);
					break;
				case 'n':
					TestVectorEnd(*vec);
					break;
				case 'e':
					TestVectorEmpty(*vec);
					break;
				case 'l':
					TestVectorSize(*vec);
					break;
				case 'g':
					TestVectoGetAt(vec);
					break;
				case 's':
					TestVectorSetAt(vec);
					break;
				case 'i':
					TestVectorInsert(vec);
					break;
				case 'a':
					TestVectorSetSize(vec);

					break;
				case 'r':
					TestVectorErase(vec);
					break;
				case 'd':
					TestVectorDelete(vec);
					break;
				case 'c':
					TestVectorClear(vec);
					break;
				case 'p':
					PrintVector(*vec);
					break;
				case 'y':
					TestVectorCopy();
					break;
				case 'q':
					flg = FALSE;
					break;
				default:
					printf("������Ĳ�����Ų���\n");
					break;
			}  //switch (choice) is over

			printf("\n\n");
		}  //while (flg == TURE) is over

		printf("\t����0�������ԣ��������ֵ�����������:");
		scanf("%d", &quit);
		getchar();
	}  //while (quit) is over

	FREE_CTL_VECTOR(vecInt);
	FREE_CTL_VECTOR(vecChar);
	FREE_CTL_VECTOR(vecDou);
}

