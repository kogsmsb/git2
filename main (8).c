#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N;//数组宽度，可变，最大500000
int test1[500001];//随机数据的顺序
int test2[500001];//随机数组的乱序
int test3[500001];//随机数据（0~90000）

void swap(int *x,int *y)//交换函数
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}
//非递归
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
    return low;//par基准
}
void Quick_Sort1(int *arr, int len)
{
    //1.申请一块内存当栈 //2.进行一次快速排序，找到基准 //3.把左边 右边的数对进行入栈 //4.取出数据进行一趟快速排序 //5.top>0
    int *stack = (int *)malloc(sizeof(int) * len);//定义栈的大小
    int top = 0;
    int low = 0;
    int high = len - 1;
    int par = Partion(arr, low, high);
    if (par>low + 1)//左边有两个数据以上数时 入栈
    {
        stack[top] = low;
        top++;
        stack[top] = par - 1;
        top++;
    }
    if (par<high - 1)//右边左边有两个数据以上数时 入栈
    {
        stack[top] = par + 1;
        top++;
        stack[top] = high;
        top++;
    }
    while (top>0)//出栈 栈不空，需要取两个数据出来排序
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
