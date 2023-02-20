#include "CTLVector.h"
#include "debug.h"

/**
 * Vector�Ƕ�̬���飬���������ǵĴ����У�����̶������ˡ�
 * ����Ҳ����ͨ�� CTLVectorSetSize() ���� ��̬���ݡ�
 * �������Զ�����������õġ�
 * δ����ʱ�������޸İɡ�
 */


//����ָ��vector�ĵ�һ��Ԫ�ص�ָ��,�������򷵻�NULL
void *CTLVectorBegin(CTLVector vector){
	if (vector.quan != 0)
		return vector.data;
	else
		return NULL;
}


//����ָ��vector�����һ��Ԫ�ص�ָ�룬 �������򷵻�NULL
void *CTLVectorEnd(CTLVector vector){
	void *ptr;

	if (vector.quan == 0)
		return NULL;
	else {
		ptr = vector.data;
		ptr = (char *)ptr + vector.typeSize*(vector.quan-1);
		return ptr;
	}
}


//���vectorΪ�գ��򷵻�TRUE�����򷵻�FALSE
int CTLVectorEmpty(CTLVector vector){
	if (vector.quan == 0)
		return TRUE;
	else
		return FALSE;
}

//����vector�е�ǰԪ�صĸ���
int CTLVectorSize(CTLVector vector){
	return vector.quan;
}


//��vector�е�num(��1��ʼ����)��Ԫ��ֵ��*record����
//@return  ��������NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLVectorGetAt(const CTLVector *vector, void *record, int num){
	void *ptr;

	if (vector == NULL)
		return CTL_PTR_IS_NULL;
	if (num<=0 || num>vector->quan)
		return NUM_IS_WRONG;

	ptr = vector->data;
	ptr = (char *)ptr + vector->typeSize*(num-1);
	memcpy(record, ptr, vector->typeSize);
	return NORMAL;
}


//��vector�ĵ�num����1��ʼ��������Ԫ�ص�ֵ����Ϊ*record
//@return ����������򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLVectorSetAt(const CTLVector *vector, const void *record, int num){
	void *ptr;

	if (vector == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;
	if (num<=0 || num>vector->quan)
		return NUM_IS_WRONG;

	ptr = vector->data;
	ptr = (char *)ptr + vector->typeSize*(num-1);
	memcpy(ptr, record, vector->typeSize);
	return NORMAL;
}


//1����vector�ĵ�num��λ�ô���������*record
// 2��num��1��ʼ���������num����vector���ȣ�������뵽vector���һ��Ԫ�صĺ���
//@return �����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLVectorInsert(CTLVector *vector, const void *record, int num){
	union ScanVal val;
	void *tmp = (void *)(&val);
	int i, result = NORMAL;

	if (vector == NULL)
		return CTL_PTR_IS_NULL;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;
	if (num <= 0)
		return NUM_IS_WRONG;
	if (num > vector->quan+1){
		num = vector->quan + 1;
		result = NUM_WRONG_BUT_DO_SOMETHING;
	}
	if (num > vector->length)
		return CTL_OUT_OF_RANGE;

	vector->quan++;
	for (i=vector->quan; i>num; i--){
		CTLVectorGetAt(vector, tmp, i-1);
		CTLVectorSetAt(vector, tmp, i);
	}
	CTLVectorSetAt(vector, record, num);
	return result;
}

//��vector�ĳ�������Ϊlen��֮ǰ�����ݱ��棨������ȱ�С������ܱ���һ���֣�
//@return ��������NORMAL���쳣����·�����Ӧ���
int CTLVectorSetSize(CTLVector *vector, int len){
	void *ptr;
	int tmp;

	if (vector == NULL)
		return CTL_PTR_IS_NULL;
	if (len <= 0)
		return NUM_IS_WRONG;

	ptr = (void *)malloc(vector->typeSize * len);
	tmp = (len>vector->quan) ? vector->quan : len;
	memcpy(ptr, vector->data, tmp*vector->typeSize);
	free(vector->data);
	vector->data = ptr;
	vector->length = len;
	vector->quan = tmp;
	return NORMAL;
}


//��src�����ݸ��Ƶ�dst��
//@return ��������NORMAL���쳣������Ӧ���
int CTLVectorCopy(CTLVector *dst, const CTLVector *src){
	int size;

	if (dst->typeSize != src->typeSize)
		return CTL_TYPESIZE_NO_MATCH;

	memset(dst->data, NULL, dst->length*dst->typeSize);
	if (dst->length > src->quan)
		size = src->quan;
	else
		size = dst->length;
	memcpy(dst->data, src->data, dst->typeSize*size);
	dst->quan = size;
	return NORMAL;
}

//��vector��num(��1��ʼ)λ�ô����������㣬�����������仯
//@return ��������NORMAL���쳣����·�����Ӧ���
int CTLVectorErase(const CTLVector *vector, int num){
	void *ptr;

	if (num<=0 || num>vector->quan)
		return NUM_IS_WRONG;

	ptr = vector->data;
	ptr = (char *)ptr + vector->typeSize*(num-1);
	memset(ptr, 0, vector->typeSize);
	return NORMAL;
}


//��vector��num(��1��ʼ)λ�ô�������ɾ����֮���������ǰ��
//@return ��������£�����NORMAL���쳣����·�����Ӧ���
int CTLVectorDelete(CTLVector *vector, int num){
	int i;
	union ScanVal val;
	void *record = (void *)(&val);

	if (num<=0 || num>vector->quan)
		return NUM_IS_WRONG;

	for (i=num; i<vector->quan+1; i++){
		CTLVectorGetAt(vector, record, i+1);
		CTLVectorSetAt(vector, record, i);
	}
	vector->quan--;
	return NORMAL;
}


//�������Ԫ�أ��ͷſռ�
void CTLVectorClear(CTLVector *vector){
	free(vector->data);
	vector->quan = 0;
	vector->data = NULL;
}




