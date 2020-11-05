#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double functionA(double x);
double dfunctionA(double x);
double functionB(double x);
double dfunctionB(double x);
void questionA(double e1,double e2,double x,int N);
void questionB(double e1,double e2,double x,int N);

int main()
{
    printf("question1 \n");
    questionA(0.000001,0.0001,0.785398163,10);
    printf("question2 \n");
    questionB(0.000001,0.0001,0.6,10);
    return 0;
}

void questionA(double e1,double e2,double x,int N)
{
    int i;
    double F,DF;
    double x0=x;
    int count=1;
    for (i=1;i<=N;i++)
    {
        F=functionA(x0);
        DF=dfunctionA(x0);
        if (fabs(F)<e1)
        {
            printf("answer is %f\n",x0);
            break;
        }
        if (fabs(DF)<e2)
        {
            printf("false to solve\n");
            break;
        }
        double x1=x0-F/DF;
        double tol=fabs(x1-x0);
        if (fabs(tol-e1)<0)
        {
            printf("answer is %f\n",x1);
            break;
        }
        x0=x1;
        if (count<5)
        {
            printf("%d:%f\t",i,tol);
            count++;
        }
        else
        {
            printf("%d:%f\n",i,tol);
            count=0;
        }
    }
    printf("\nbeyond max times,false to solve\n\n");
}

void questionB(double e1,double e2,double x,int N)
{
    int i;
    double F,DF;
    double x0=x;
    int count=1;
    for (i=1;i<=N;i++)
    {
        F=functionB(x0);
        DF=dfunctionB(x0);
        if (fabs(F)<e1)
        {
            printf("answer is %f\n",x0);
            break;
        }
        if (fabs(DF)<e2)
        {
            printf("false to solve\n");
            break;
        }
        double x1=x0-F/DF;
        double tol=fabs(x1-x0);
        if (fabs(tol-e1)<0)
        {
            printf("answer is %f\n",x1);
            break;
        }
        x0=x1;
        if (count<5)
        {
            printf("%d:%f\t",i,tol);
            count++;
        }
        else
        {
            printf("%d:%f\n",i,tol);
            count=0;
        }
    }
    printf("\nbeyond max times,false to solve\n\n");
}

double functionA(double x)
{
    double fx=1-x-(1/2)*x*x+(1/24)*x*x*x*x-(1/720)*x*x*x*x*x*x;
    return fx;
}

double dfunctionA(double x)
{
    double fx=-1-x+(1/6)*x*x*x-(1/120)*x*x*x*x*x;
    return fx;
}

double functionB(double x)
{
    double fx=1-2*x+(1/2)*x*x+(1/24)*x*x*x*x-(1/60)*x*x*x*x*x+(1/720)*x*x*x*x*x*x;
    return fx;
}

double dfunctionB(double x)
{
    double fx=-2+x+(1/6)*x*x*x-(1/12)*x*x*x*x+(1/120)*x*x*x*x*x;
    return fx;
}
