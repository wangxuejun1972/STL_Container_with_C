/**
 * 1.���ļ�����CTLStack�Ľṹ�壬����CTLStack�ĺ궨�壬���в����ĸ�������������
 * 2.����Ŀ����ʹ�õ�stack�ṹΪ��򵥵�ʹ�ù̶����������ʾ��˳��ջ
 */


#ifndef _CTL_STACK_H
#define _CTL_STACK_H

 #include "ctl.h"

 struct CTLStack{
    void *data;        //ָ��������
    size_t typeSize;   //ջ�е�Ԫ��������ռ���ֽ���
    int top;           //ջ��ָ���λ��
    size_t  length;    //ջ���������ɵ�(������)Ԫ�ص����ĸ���
 };


 /**
  * @params type: ������ջ�е�Ԫ�ص�����
  * @params name: ջ������(���Ǳ���������)
  * @params len:  ջ���������ɵ�Ԫ�ص�������
  */
 #define INIT_CTL_STACK(type, name, len) \
    type ctl_stack_array_##name[len*sizeof(type)] = {0};  \
    struct CTLStack name = {ctl_stack_array_##name, sizeof(type), -1, len}

 #include "ctl.h"

 extern int CTLStackClear(struct CTLStack *stack);
 extern int CTLStackIsEmpty(struct CTLStack stack);
 extern int CTLStackIsFull(struct CTLStack stack);
 extern int CTLStackPush(struct CTLStack *stack, void *record);
 extern int CTLStackPop(struct CTLStack *stack, void *record);
 extern int CTLStackPeek(struct CTLStack *stack, void *record);
 extern int CTLStackCopy(struct CTLStack *dest, struct CTLStack *sour);

#endif // _CTL_STACK_H




