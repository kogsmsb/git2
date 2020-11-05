#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N;//�����ȣ��ɱ䣬���500000
int test1[500001];//������ݵ�˳��
int test2[500001];//������������
int test3[500001];//������ݣ�0~90000��

void swap(int *x,int *y)//��������
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}
//�ǵݹ�
int  Partion(int *arr, int low, int high)
{
    int tmp = arr[low];
    while (low<high)
    {
        while (low < high && arr[high] >= tmp)
        {
            high--;
        }
        if (low >= high)
        {
            break;
        }
        else
        {
            arr[low] = arr[high];
        }
        while (low<high && arr[low] <= tmp)
        {
            low++;
        }
        if (low >= high)
        {
            break;
        }
        else
        {
            arr[high] = arr[low];
        }
    }
    arr[low] = tmp;
    return low;//par��׼
}
void Quick_Sort1(int *arr, int len)
{
    //1.����һ���ڴ浱ջ //2.����һ�ο��������ҵ���׼ //3.����� �ұߵ����Խ�����ջ //4.ȡ�����ݽ���һ�˿������� //5.top>0
    int *stack = (int *)malloc(sizeof(int) * len);//����ջ�Ĵ�С
    int top = 0;
    int low = 0;
    int high = len - 1;
    int par = Partion(arr, low, high);
    if (par>low + 1)//�������������������ʱ ��ջ
    {
        stack[top] = low;
        top++;
        stack[top] = par - 1;
        top++;
    }
    if (par<high - 1)//�ұ��������������������ʱ ��ջ
    {
        stack[top] = par + 1;
        top++;
        stack[top] = high;
        top++;
    }
    while (top>0)//��ջ ջ���գ���Ҫȡ�������ݳ�������
    {
        top--;
        high = stack[top];
        top--;
        low = stack[top];
        par = Partion(arr, low, high);
        if (par>low + 1)
        {
            stack[top] = low;
            top++;
            stack[top] = par - 1;
            top++;
        }
        if (par<high - 1)
        {
            stack[top] = par + 1;
            top++;
            stack[top] = high;
            top++;
        }
    }
    free(stack);
    stack = NULL;
}
