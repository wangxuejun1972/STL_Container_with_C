#include <stdio.h>
#include <stdlib.h>
#include "testStack.h"
#include "testQueue.h"
#include "testList.h"
#include "testVector.h"

int main(){
    //TestCTLStack();
    	int var;

	printf("1(CTLStack), 2(CTLQueue), 3(CTLList), 4(CTLVecotr)\n"    \
		   "������1��2��3��4��ѡ����Ҫ���Ե����ݽṹ:");
	scanf("%d", &var);

	switch (var){
		case 1:
			TestCTLStack();
			break;
		case 2:
			TestQueue();
			break;
		case 3:
			TestList();
			break;
		case 4:
			TestVector();
			break;
		default:
			printf("�������ֵ����\n");
			break;
	}


    system("pause");
    return 0;
}
