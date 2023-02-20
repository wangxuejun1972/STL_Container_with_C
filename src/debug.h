/**
 *  1. ���ļ��������ĺ������ڶ�CTL���в����������Ҫ�ǽ���Щ�ṹ����������ڹ۲�
 *  2. ���ǽ��в���ʱ��Ĭ��ֻ���� char��int��double���ͣ����� �ڽ����������ʱ��ֱ�Ӹ��� typeSize ����������
 */


 #ifndef _CTL_DEBUG_H
 #define _CTL_DEBUG_H

 #include "CTLStack.h"
 #include "CTLQueue.h"
 #include "CTLList.h"
 #include "CTLVector.h"

 union ScanVal
{
	int i;
	char ch;
	double dou;
};

 extern void PrintStack(struct CTLStack stack);
 extern void DealResult(int result);
 extern void PrintQueue(struct CTLQueue queue, int typeSize);
 extern void PrintList(CTLList list);


 //�������ܣ�����size��С��ͬ�����������ʱ����int ,double,����char����
extern void PrintType(void *record, int size);

//�������ܣ�����size��ͬ���������������val����һ����Ա
extern void ScanType(union ScanVal *val, int size);

extern void PrintVector(struct CTLVector vector);


 #endif // _CTL_DEBUG_H
