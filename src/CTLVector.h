#ifndef _CTL_VECTOR_H
#define _CTL_VECTOR_H

#include "ctl.h"

 struct CTLVector
{
	void *data;         //��������
	size_t typeSize;    //������Ԫ����ռ�ڴ���
	int length;         //��������ĳ���
	int quan;           //Ԫ�ص�����
};

 typedef struct CTLVector CTLVector;


  //��ʼ��vector
#define INIT_CTL_VECTOR(type, name, len)  \
		void *ctl_vector_##name = (void *)malloc(sizeof(type)*len);      \
		CTLVector name = {ctl_vector_##name, sizeof(type), len, 0}

//����vector���ͷ�����ռ�ռ�
#define FREE_CTL_VECTOR(name)   CTLVectorClear(&name)


//����ָ��vector�ĵ�һ��Ԫ�ص�ָ��,�������򷵻�NULL
extern void *CTLVectorBegin(CTLVector vector);


//����ָ��vector�����һ��Ԫ�ص�ָ�룬 �������򷵻�NULL
extern void *CTLVectorEnd(CTLVector vector);

//���vectorΪ�գ��򷵻�TRUE�����򷵻�FALSE
extern int CTLVectorEmpty(CTLVector vector);


//����vector�е�ǰԪ�صĸ���
extern int CTLVectorSize(CTLVector vector);


//��vector�е�num(��1��ʼ����)��Ԫ��ֵ��*record����
//@return  ��������NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLVectorGetAt(const CTLVector *vector, void *record, int num);


//��vector�ĵ�num����1��ʼ��������Ԫ�ص�ֵ����Ϊ*record
//@return ����������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLVectorSetAt(const CTLVector *vector, const void *record, int num);

//1����vector�ĵ�num��λ�ô���������*record
// 2��num��1��ʼ���������num����vector���ȣ�������뵽vector���һ��Ԫ�صĺ���
//@return �����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLVectorInsert(CTLVector *vector, const void *record, int num);


//��vector�ĳ�������Ϊlen��֮ǰ�����ݱ��棨������ȱ�С������ܱ���һ���֣�
//@return ��������NORMAL���쳣����·�����Ӧ���
extern int CTLVectorSetSize(CTLVector *vector, int len);


//��src�����ݸ��Ƶ�dst��
//@return ��������NORMAL���쳣������Ӧ���
extern int CTLVectorCopy(CTLVector *dst, const CTLVector *src);


//��vector��num(��1��ʼ)λ�ô����������㣬�����������仯
//@return ��������£�����NORMAL���쳣����·�����Ӧ���
extern int CTLVectorErase(const CTLVector *vector, int num);


//��vector��num(��1��ʼ)λ�ô�������ɾ����֮���������ǰ��
//@return ��������£�����NORMAL���쳣����·�����Ӧ���
extern int CTLVectorDelete(CTLVector *vector, int num);


//�������Ԫ�أ��ͷſռ�
extern void CTLVectorClear(CTLVector *vector);

#endif // _CTL_VECTOR_H
