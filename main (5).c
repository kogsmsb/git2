#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

double A[MAX][MAX];
double b[MAX];
double X[MAX];
int NUM;

void Input_Matrix()//�������
{
    int i,j;
    printf("ϵ������A�Ľ���:\n");
    scanf("%d",&NUM);
    for(i=1; i<=NUM; i++)
    {
        printf("ϵ������A�ĵ�%d��Ԫ��:\n",i);
        for(j=1; j<=NUM; j++)
            scanf("%lf",&A[i-1][j-1]);
    }
    printf("�Ҷ���b:\n");
    for(i=1; i<=NUM; i++)
    {
        scanf("%lf",&b[i-1]);
    }
    printf("�����ϵ������A:\n");
    for(i=0; i<NUM; i++)
    {
        for(j=0; j<NUM; j++)
            printf("%lf\t",A[i][j]);
        printf("\n");
    }
    printf("������Ҷ���b:\n");
    printf("�������[A,b]:\n");
    for(i=0; i<NUM; i++)
    {
        for(j=0; j<NUM; j++)
            printf("%.4lf\t",A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
}

void Gauss()
{
    int i,j,k,column;
    double max,A_temp,b_temp,mik,sum;
    for(k=0; k<NUM-1; k++)
    {
        column=k;
        max=0;
        for(i=k; i<NUM; i++)
        {
            if(fabs(A[i][k])>max)
            {
                max=fabs(A[i][k]);
                column=i;
            }
        }
        for(j=k; j<NUM; j++)
        {
            A_temp = A[k][j];
            A[k][j] = A[column][j];
            A[column][j] = A_temp;
        }
        b_temp = b[k];
        b[k] = b[column];
        b[column] = b_temp;
        for(i=k+1; i<NUM; i++)//��Ԫ����
        {
            mik = A[i][k]/A[k][k];
            for(j=k; j<NUM; j++)
                A[i][j]-=mik*A[k][j];
            b[i]-= mik*b[k];
        }

    }
    printf("��Ԫ��ľ���:\n");
    for(i=0; i<NUM; i++)
    {
        for(j=0; j<NUM; j++)
            printf("%lf\t",A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
    X[NUM-1]=b[NUM-1]/A[NUM-1][NUM-1];
    for(i=NUM-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1; j<NUM; j++)
            sum+=A[i][j]*X[j];
        X[i]=(b[i]-sum)/A[i][i];
    }
    printf("���X:\n");
    for(i=0; i<NUM; i++)
    {
        printf("%lf\n",X[i]);
    }
}

int main()
{
    Input_Matrix();
    Gauss();
    return 0;
}
