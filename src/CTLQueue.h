#ifndef _CTL_QUEUE_H
#define _CTL_QUEUE_H

#include "ctl.h"

struct CTLQueue{
    void *data;       //ָ����������
    size_t typeSize;  //queue�д��Ԫ��������ռ���ֽ���
    int front;        //��ͷλ��
    int rear;         //��βλ��
    int length;       //queue���������ɵ�Ԫ�ص�������
};

#define INIT_CTL_QUEUE(type, name, len)  \
        type ctl_queue_array_##name[sizeof(type)*(len+1)] = {0};  \
        struct CTLQueue name = {   \
        ctl_queue_array_##name, sizeof(type), 0, 0, len+1}



// �ж϶����Ƿ�Ϊ��
// @return ���queueΪ�գ��򷵻�TURE�����򷵻�FALSE
extern int CTLQueueIsEmpty(struct CTLQueue queue);

// �ж϶����Ƿ�Ϊ��
// @return ���queueΪ�����򷵻�TURE�����򷵻�FALSE
extern int CTLQueueIsFull(struct CTLQueue queue);

// ���Ӳ������ڶ���queue�Ķ�β����Ԫ��record
// @return ������ӳɹ����򷵻�NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLQueueEnter(struct CTLQueue *queue, void *record);

// ȡ��ͷԪ�ز�����������queue�Ķ�ͷԪ����record����������ɾ��
// @return ���ӳɹ�������NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLQueueGetHead(struct CTLQueue *queue, void *record);

// ���Ӳ�����������queue�Ķ�ͷԪ��ɾ��������record����
// @return ���ӳɹ�������NORMAL�����򷵻���Ӧ�Ĵ�����
extern int CTLQueueDelete(struct CTLQueue *queue, void *record);

// ������queue��Ϊ�ն���
// @return ����������򷵻�NORMAL�����򷵻���Ӧ������
extern int CTLQueueClear(struct CTLQueue *queue);

//���ض�����Ԫ�صĸ���
extern int CTLQueueGetNum(struct CTLQueue queue);

//������src���Ƹ�����dst
// ��ע����������������Խṹ���е�data������и��ƣ�������front֮��δ��.
//   Todo δ���пգ�����������Ĺ�����Ƶĸ���ϸ������ϸ
//@return ��������������򷵻�NORMAL�����򷵻���Ӧ������
extern int CTLQueueCopy(struct CTLQueue *dst, struct CTLQueue *src);


#endif // _CTL_QUEUE_H
