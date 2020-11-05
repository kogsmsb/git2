#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int N;
int test1[150001];
int test2[150001];
int test3[150001];

void swap(int *x,int *y)
{
    int tem;
    tem = *x;
    *x = *y;
    *y = tem;
}

int FindPivot(int i,int j,int A[])
{
    int firstkey = A[i];
    int k;
    for(k=i+1; k<=j; k++)
        if(A[k]>firstkey)
            return k;
        else if(A[k]<firstkey)
            return i;
    return 0;

}

int Partition(int i,int j,int pivot,int A[])
{
    int l,r;
    l=i;
    r=j;
    do
    {
        while(A[l]<pivot)
            l++;
        while(A[r]>=pivot)
            r--;
        if(l<r)
            swap(&(A[l]),&(A[r]));
    }
    while(l<=r);
    return l;
}

void QuickSort(int i,int j,int A[])
{
    int pivot;
    int k;
    int pivotindex;
    pivotindex = FindPivot(i,j,A);
    if(pivotindex!=0)
    {
        pivot=A[pivotindex];
        k=Partition(i,j,pivot,A);
        QuickSort(i,k-1,A);
        QuickSort(k,j,A);

    }
}

void bubblesort(int A[])
{
    int i,j,flag;
    for(i=N-1; i>=0; i--)
    {
        flag = 0;
        for(j=0; j<i; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&(A[j]),&(A[j+1]));
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void test()
{
    srand((unsigned int)time(NULL));
    int i;
    for(i=0; i<N; i++)
    {
        test3[i]=(rand())%90001;
    }
    for(i=0; i<N; i++)
    {
        test1[i]=test3[i];
    }
    QuickSort(1,N,test1);
    for(i=0; i<N; i++)
    {
        test2[i]=test1[N-1-i];
    }
}

int main()
{
    int i;
    double start,end;
    for(i=0; i<=150000; i=i+30000)
    {
        if(i==0)
            N=10000;
        else
            N=i;
        printf("Êý×é¿í¶È£º%d\n",N);
      test();
        start=clock();
        QuickSort(1,N,test3);
        end=clock();
        printf("¿ìÅÅÂÒÐò");
        printf("time=%f\n",(double)(end-start)/CLK_TCK);

        start=clock();
        QuickSort(1,N,test2);
        end=clock();
        printf("¿ìÅÅµ¹Ðò");
        printf("time=%f\n",(double)(end-start)/CLK_TCK);

        start=clock();
        QuickSort(1,N,test1);
        end=clock();
        printf("¿ìÅÅË³Ðò");
        printf("time=%f\n",((double)(end-start))/CLK_TCK);

        test();
        start=clock();
        bubblesort(test3);
        end=clock();
        printf("Ã°ÅÝÂÒÐò");
        printf("time=%f\n",(double)(end-start)/CLK_TCK);

        start=clock();
        bubblesort(test2);
        end=clock();
        printf("Ã°ÅÝµ¹Ðò");
        printf("time=%f\n",(double)(end-start)/CLK_TCK);

        start=clock();
        bubblesort(test1);
        end=clock();
        printf("Ã°ÅÝË³Ðò");
        printf("time=%f\n",(double)(end-start)/CLK_TCK);
        printf("\n");
    }
    return 0;
}
