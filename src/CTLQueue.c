#include "CTLQueue.h"



//�ж϶����Ƿ�Ϊ��
//@return TRUE or FLASE
int CTLQueueIsEmpty(struct CTLQueue queue){
	if (queue.front == queue.rear)
		return TRUE;
	else
		return FALSE;
}

//�ж϶����Ƿ�Ϊ��
//@return TRUE or FLASE
int CTLQueueIsFull(struct CTLQueue queue){
	if ((queue.rear+1)%queue.length == queue.front)
		return TRUE;
	else
		return FALSE;
}



//��������ڶ���queue�Ķ�β����Ԫ��record
//@return  ������ӳɹ����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLQueueEnter(struct CTLQueue *queue, void *record){
	void *ptr;

	if (queue == NULL)
		return CTL_PTR_IS_NULL;
	if ((queue->rear!=0) && (queue->rear+1)%queue->length == queue->front)
		return CTL_OUT_OF_RANGE;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;

	ptr = queue->data;
	ptr = (char *)ptr + queue->rear * queue->typeSize;
	memcpy(ptr, record, queue->typeSize);
	queue->rear = (queue->rear+1) % queue->length;
	return NORMAL;
}


//ȡ��ͷԪ�أ�������queue�Ķ�ͷԪ����record����������ɾ��
//@return  ���ӳɹ�������NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLQueueGetHead(struct CTLQueue *queue, void *record){
	void *ptr;

	if (queue == NULL)
		return CTL_PTR_IS_NULL;
	if (queue->rear == queue->front)
		return CTL_NO_VALUE;
	if (record == NULL)
		return RECORD_PTR_IS_NULL;

	ptr = queue->data;
	ptr = (char *)ptr + queue->front * queue->typeSize;
	memcpy(record, ptr, queue->typeSize);
	return NORMAL;
}


//���Ӳ�����������queue�Ķ�ͷԪ��ɾ��������record����
//@return  ���ӳɹ�������NORMAL�����򷵻���Ӧ�Ĵ�����
int CTLQueueDelete(struct CTLQueue *queue, void *record){
	int result;

	result = CTLQueueGetHead(queue, record);
	//if (result == NORMAL)
		//queue->front = (queue->front+1) % queue->length;

    if (result == NORMAL){
        memcpy(queue->data,
                (char *)(queue->data + queue->typeSize),
                 ((queue->rear-1)*queue->typeSize));
        queue->rear--;
    }

	return result;
}


//������queue��Ϊ�ն���
//@return ����������򷵻�NORMAL�����򷵻���Ӧ������
int CTLQueueClear(struct CTLQueue *queue){
	if (queue == NULL)
		return CTL_PTR_IS_NULL;

	memset(queue->data, NULL, queue->length * queue->typeSize);
	queue->front = queue->rear = 0;
	return NORMAL;
}

//���ض�����Ԫ�صĸ���
int CTLQueueGetNum(struct CTLQueue queue){
	int result;

	if (queue.rear >= queue.front)
		result = queue.rear - queue.front;
	else
		result = queue.rear + queue.length - queue.front;

	return result;
}


//������src���Ƹ�����dst
// ��ע����������������Խṹ���е�data������и��ƣ�������front֮��δ��.
//   Todo δ���пգ�����������Ĺ�����Ƶĸ���ϸ������ϸ
//@return ��������������򷵻�NORMAL�����򷵻���Ӧ������
int CTLQueueCopy(struct CTLQueue *dst, struct CTLQueue *src){
	int len, result;

	if (dst->typeSize != src->typeSize)
		return CTL_TYPESIZE_NO_MATCH;

	memset(dst->data, NULL, dst->length * dst->typeSize);

	if (dst->length == src->length)
	{
		len = dst->length;
		result = NORMAL;
	} else {
		if (dst->length > src->length)
			len = src->length;
		else
			len = dst->length;

		result = CTL_OUT_OF_RANGE;
	}

	memcpy(dst, src, len*src->typeSize);

	return result;
}



