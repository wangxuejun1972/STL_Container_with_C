#include "CTLStack.h"

/**
 * ��stack��ָ���ջ���
 * @return �������� NORMAL, �쳣������Ӧ�Ĵ����ʶ
 */
int CTLStackClear(struct CTLStack *stack) {
    if (stack == NULL)
        return CTL_PTR_IS_NULL;

    memset(stack->data, 0, stack->length * stack->typeSize);
    stack->top= -1;
    return NORMAL;
}

/**
 * ���ջΪ�գ��򷵻� TRUE;���򷵻� FALSE
 */
int CTLStackIsEmpty(struct CTLStack stack){
    if (stack.top == -1){
        return TRUE;
    }else {
        return FALSE;
    }
}

/**
 * ���ջ�����򷵻� TRUE, ���򷵻� FALSE
 */
int CTLStackIsFull(struct CTLStack stack){
    if (stack.top == stack.length - 1){
        return TRUE;
    }else {
        return FALSE;
    }
}


/**
 * ��stack��ջ��ѹ��һ��record ��ָ�������
 * @return ��������NORMAL, ���򷵻���Ӧ������
 */
int CTLStackPush(struct CTLStack *stack, void *record){

    if ((stack == NULL) || (record==NULL)){
        return CTL_PTR_IS_NULL;
    }

    if (stack->top == stack->length-1){
        return CTL_OUT_OF_RANGE;
    }

    void *ptr;

    stack->top++;
    ptr = (char *)(stack->data) + stack->top*stack->typeSize;
    memcpy(ptr, record, stack->typeSize);
    return NORMAL;
}

/**
 * ����ջ��ֵ��ͨ��recordָ��������
 * @return ��������NORMAL, �쳣���ش�����
 */
int CTLStackPop(struct CTLStack *stack, void *record){

    //��peek����д�ں��������£��ᱨ����
    int resultVar = CTLStackPeek(stack, record);
    if (resultVar == NORMAL){
        stack->top--;
    }
    return resultVar;
}


/**
 * ��ȡջ����ֵ����ͨ��recordָ��������
 * @return ��������NORMAL, �쳣���ش�����
 */
int CTLStackPeek(struct CTLStack *stack, void *record){
     if ((stack == NULL) || (record==NULL)){
        return CTL_PTR_IS_NULL;
    }
    if (stack->top == -1){
        return CTL_NO_VALUE;
    }

    void *ptr;
    ptr = (char *)(stack->data) + stack->top*stack->typeSize;
    memcpy(record, ptr, stack->typeSize);
    return NORMAL;
}

/**
 * ����һ��ջ�� (��sourջ���Ƶ� destջ)
 * @return ��������NORMAL, �쳣���ش�����
 */
int CTLStackCopy(struct CTLStack *dest, struct CTLStack *sour){
    if ((dest==NULL) || (sour==NULL)){
        return CTL_PTR_IS_NULL;
    }
    if (dest->typeSize != sour->typeSize){
        return CTL_TYPESIZE_NO_MATCH;
    }

    int len, result = NORMAL;

    memset(dest->data, 0, dest->length*dest->typeSize);

    if (dest->length < sour->length){
        len = dest->length;
        result = CTL_OUT_OF_RANGE;
    }else{
        len = sour->length;
    }

    memcpy(dest->data, sour->data, len*dest->typeSize);
    if (sour->top > len-1){
        dest->top = len-1;
    }else{
        dest->top = sour->top;
    }

    return result;
}

