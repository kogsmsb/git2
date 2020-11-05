#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stPoint
{
    double x;
    double y;
} Point;

void questionA();
void questionB();
void Lagrangefunction(Point points[],double x,int number);

int main()
{
    printf("first question:\n");
    /*printf("%.2f:%f\n",0.75,1.0/(1+(0.75*0.75)));
    printf("%.2f:%f\n",1.75,1.0/(1+(1.75*1.75)));
    printf("%.2f:%f\n",2.75,1.0/(1+(2.75*2.75)));
    printf("%.2f:%f\n",3.75,1.0/(1+(3.75*3.75)));
    printf("%.2f:%f\n",4.75,1.0/(1+(4.75*4.75)));*/
    questionA();
   /* printf("second question:\n");
    printf("%.2f:%f\n",-0.95,exp(-0.95));
    printf("%.2f:%f\n",-0.05,exp(-0.05));
    printf("%.2f:%f\n",0.05,exp(0.05));
    printf("%.2f:%f\n",0.95,exp(0.95));*/
    questionB();
}

void questionA()
{
    double x0=-5.0;
    double h1=2.0;
    double h2=1.0;
    double h3=0.5;
    Point p1[6];
    Point p2[11];
    Point p3[21];
    for (int i=0;i<6;i++)
    {
        p1[i].x=x0+(double)(i*h1);
        p1[i].y=(double)(1/(1+p1[i].x*p1[i].x));
    }
    for (int i=0;i<11;i++)
    {
        p2[i].x=x0+(double)(i*h2);
        p2[i].y=(double)(1/(1+p2[i].x*p2[i].x));
    }
    for (int i=0;i<21;i++)
    {
        p3[i].x=x0+(double)(i*h3);
        p3[i].y=(double)(1/(1+p3[i].x*p3[i].x));
    }
    printf("\nn=5\n");
    Lagrangefunction(p1,0.75,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,1.75,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,2.75,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,3.75,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,4.75,(int)(sizeof(p1)/(2*sizeof(double))));
    printf("\nn=10\n");
    Lagrangefunction(p2,0.75,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,1.75,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,2.75,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,3.75,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,4.75,(int)(sizeof(p2)/(2*sizeof(double))));
    printf("\nn=20\n");
    Lagrangefunction(p3,0.75,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,1.75,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,2.75,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,3.75,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,4.75,(int)(sizeof(p3)/(2*sizeof(double))));
}

void questionB()
{
    double x0=-1.0;
    double h1=0.4;
    double h2=0.2;
    double h3=0.1;
    Point p1[6];
    Point p2[11];
    Point p3[21];
    for (int i=0;i<6;i++)
    {
        p1[i].x=x0+(double)(i*h1);
        p1[i].y=(double)(exp(p1[i].x));
    }
    for (int i=0;i<11;i++)
    {
        p2[i].x=x0+(double)(i*h2);
        p2[i].y=(double)(exp(p2[i].x));
    }
    for (int i=0;i<21;i++)
    {
        p3[i].x=x0+(double)(i*h3);
        p3[i].y=(double)(exp(p3[i].x));
    }
    printf("\nn=5\n");
    Lagrangefunction(p1,-0.95,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,-0.05,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,0.05,(int)(sizeof(p1)/(2*sizeof(double))));
    Lagrangefunction(p1,0.95,(int)(sizeof(p1)/(2*sizeof(double))));
    printf("\nn=10\n");
    Lagrangefunction(p2,-0.95,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,-0.05,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,0.05,(int)(sizeof(p2)/(2*sizeof(double))));
    Lagrangefunction(p2,0.95,(int)(sizeof(p2)/(2*sizeof(double))));
    printf("\nn=20\n");
    Lagrangefunction(p3,-0.95,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,-0.05,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,0.05,(int)(sizeof(p3)/(2*sizeof(double))));
    Lagrangefunction(p3,0.95,(int)(sizeof(p3)/(2*sizeof(double))));
}

void Lagrangefunction(Point points[],double x,int number)
{
    int n=number-1;
    int i,j;
    double tmp;
    double lagrange=0;
    for(i=0;i<=n;i++)
    {
        tmp=1;
        for(j=0;j<=n;j++)
        {
            if(j==i)
            {
                continue;
            }
            tmp=tmp*(x-points[j].x)/(points[i].x-points[j].x);
        }
        lagrange=lagrange+tmp*points[i].y;
    }
    printf("\n拉格朗日函数f(%f)=%f\n",x,lagrange);
}
