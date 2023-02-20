/**
 * ���ļ���ΪCTL��Ŀ�Ĺ���ͷ�ļ������� һ������궨�壬�������ͱ�ŵĺ궨��
 */

#ifndef _CTL_STANDARD_H
#define _CTL_STANDARD_H


 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>

 #define NULL 0
 #define FALSE 0
 #define TRUE 1
 #define NORMAL 2

 #define TYPE_CHAR      1
 #define TYPE_INT       4
 #define TYPE_DOUBLE    8

 //�����ʶ
 #define CTL_OUT_OF_RANGE           1000     //������Ĭ�ϵ�cTL���ȷ�Χ
 #define CTL_PTR_IS_NULL            1001     //��Ϊ�βε�ָ��ctl��ָ���ǿյ�
 #define CTL_NO_VALUE               1002     //CTL����Ϊ0,���� û��Ҫ���ֵ
 #define CTL_TYPESIZE_NO_MATCH      1003     //����copy�����У����ߵ�Ԫ�������ֽ�����ƥ��


 #define RECORD_PTR_IS_NULL         1004     //��Ϊ�βε�ָ��record��ָ��Ϊ��

 #define MALLOC_FAIL                1005     //ʹ��malloc���������ڴ�ʧ�ܣ�����õ��ǿյ�ַ
 #define NUM_IS_WRONG               1006     //����ɾ����λ����Ϣ�Ǵ����
 #define NUM_WRONG_BUT_DO_SOMETHING 1007     //����ɾ����λ����Ϣ�Ǵ���ģ�����������Ӧ�Ĵ���

 //Todo ����û��������ξ�������

#endif // _CTL_STANDARD_H

