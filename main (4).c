#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Gauss(int n,double **A,double B[]);
void ExplicitGauss(int n,double **A,double B[]);
void ImplicitGauss(int n,double **A,double B[]);
void questionone();
void questiontwo();

void question()
{
    double A1[2][2]={{1.00001,1},{0.00000001,1}};
    double B1[2]={2,0.0001};
    double *AP1[2];
    for (int i=0;i<2;i++)
    {
        AP1[i]=A1[i];
    }
    printf("\n1\n");
    Gauss(2,AP1,B1);
    printf("\n2\n");
    ExplicitGauss(2,AP1,B1);
    printf("\n3\n");
    ImplicitGauss(2,AP1,B1);
}

int main()
{
    question();
    /*printf("first question:\n");
    questionone();
    printf("\n\nsecond question:\n");
    questiontwo();*/
    return 0;
}

void questionone()
{
    double A1[4][4]={{0.4096,0.1234,0.3678,0.2943},{0.2246,0.3872,0.4015,0.1129},{0.3645,0.1920,0.3781,0.0643},{0.1784,0.4002,0.2786,0.3927}};
    double B1[4]={1.2951,1.1262,0.9989,1.2499};
    double *AP1[4];
    for (int i=0;i<4;i++)
    {
        AP1[i]=A1[i];
    }
    double A2[4][4]={{136.01,90.860,0,0},{90.860,98.810,-67.590,0},{0,-67.590,132.01,46.260},{0,0,46.260,177.17}};
    double B2[4]={226.87,122.08,110.68,223.43};
    double *AP2[4];
    for (int i=0;i<4;i++)
    {
        AP2[i]=A2[i];
    }
    double A3[4][4]={{1.0,(1.0/2),(1.0/3),(1.0/4)},{(1.0/2),(1.0/3),(1.0/4),(1.0/5)},{(1.0/3),(1.0/4),(1.0/5),(1.0/6)},{(1.0/4),(1.0/5),(1.0/6),(1.0/7)}};
    double B3[4]={(25.0/12),(77.0/60),(57.0/60),(319.0/420)};
    double *AP3[4];
    for (int i=0;i<4;i++)
    {
        AP3[i]=A3[i];
    }
    double A4[4][4]={{10,7,8,7},{7,5,6,5},{8,6,10,9},{7,5,9,10}};
    double B4[4]={32,23,33,31};
    double *AP4[4];
    for (int i=0;i<4;i++)
    {
        AP4[i]=A4[i];
    }
    printf("\n使用高斯列主元消去法:\n");
    Gauss(4,AP1,B1);
    Gauss(4,AP2,B2);
    Gauss(4,AP3,B3);
    Gauss(4,AP4,B4);
    printf("\n");
    printf("\n使用显式相对高斯消去法:\n");
    ExplicitGauss(4,AP1,B1);
    ExplicitGauss(4,AP2,B2);
    ExplicitGauss(4,AP3,B3);
    ExplicitGauss(4,AP4,B4);
    printf("\n");
    printf("使用隐式相对高斯消去法:\n");
    ImplicitGauss(4,AP1,B1);
    ImplicitGauss(4,AP2,B2);
    ImplicitGauss(4,AP3,B3);
    ImplicitGauss(4,AP4,B4);
}

void questiontwo()
{
    double A1[4][4]={{197,305,-206,-804},{46.8,71.3,-47.4,52.0},{88.6,76.4,-10.8,802},{1.45,5.90,6.13,36.5}};
    double B1[4]={136,11.7,25.1,6.60};
    double *AP1[4];
    for (int i=0;i<4;i++)
    {
        AP1[i]=A1[i];
    }
    double A2[4][4]={{0.5398,0.7161,-0.5554,-0.2982},{0.5257,0.6924,0.3565,-0.6255},{0.6465,-0.8187,-0.1872,0.1291},{0.5814,0.9400,-0.7779,-0.4042}};
    double B2[4]={0.2058,-0.0503,0.1070,0.1859};
    double *AP2[4];
    for (int i=0;i<4;i++)
    {
        AP2[i]=A2[i];
    }
    double A3[3][3]={{10,1,2},{1,10,2},{1,1,5}};
    double B3[3]={13,13,7};
    double *AP3[3];
    for (int i=0;i<3;i++)
    {
        AP3[i]=A3[i];
    }
    double A4[3][3]={{4,-2,-4},{-2,17,10},{-4,10,9}};
    double B4[3]={-2,25,15};
    double *AP4[3];
    for (int i=0;i<3;i++)
    {
        AP4[i]=A4[i];
    }
    printf("\n");
    printf("使用高斯列主元消去法:\n");
    Gauss(4,AP1,B1);
    Gauss(4,AP2,B2);
    Gauss(3,AP3,B3);
    Gauss(3,AP4,B4);
    printf("\n");
    printf("使用显式相对高斯消去法:\n");
    ExplicitGauss(4,AP1,B1);
    ExplicitGauss(4,AP2,B2);
    ExplicitGauss(3,AP3,B3);
    ExplicitGauss(3,AP4,B4);
    printf("\n");
    printf("使用隐式相对高斯消去法:\n");
    ImplicitGauss(4,AP1,B1);
    ImplicitGauss(4,AP2,B2);
    ImplicitGauss(3,AP3,B3);
    ImplicitGauss(3,AP4,B4);
}
void Gauss(int n,double **A,double B[])
{
    int i,j,k;
    int p;
    double temp,m;
    double a[n][n];
    double b[n];
    double x[n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            a[i][j]=A[i][j];
        }
        b[i]=B[i];
    }
    for (k=0;k<n-1;k++)
    {
        p=k;
        temp=fabs(a[k][k]);
        for (i=k;i<n;i++)
        {
            if (fabs(a[i][k])>temp)
            {
                p=i;
                temp=fabs(a[i][k]);
            }
        }
        if (temp==0)
        {
            printf("\nThe matrix is Singular matrix.\n");
            return;
        }
        if (p!=k)
        {
            for (j=0;j<n;j++)
            {
                temp=a[k][j];
                a[k][j]=a[p][j];
                a[p][j]=temp;
            }
            temp=b[k];
            b[k]=b[p];
            b[p]=temp;
        }
        for (i=k+1;i<n;i++)
        {
            m=a[i][k]/a[k][k];
            for (j=k;j<n;j++)
            {
                a[i][j]=a[i][j]-m*a[k][j];
            }
            b[i]=b[i]-b[k]*m;
        }
    }
    if (a[n-1][n-1]==0)
    {
        printf("\nThe matrix is Singular matrix.\n");
        return;
    }
    x[n-1]=b[n-1]/a[n-1][n-1];
    for (k=n-2;k>=0;k--)
    {
        x[k]=b[k];
        for (j=k+1;j<n;j++)
        {
            x[k]=x[k]-a[k][j]*x[j];
        }
        x[k]=x[k]/a[k][k];
    }
    printf("\nx = \n");
    for (i=0;i<n;i++)
    {
        printf(" %f \n",x[i]);
    }
}

void ExplicitGauss(int n,double **A,double B[])
{
    int i,j,k;
    int p;
    double temp,m;
    double a[n][n];
    double b[n];
    double s[n];
    double x[n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            a[i][j]=A[i][j];
        }
        b[i]=B[i];
    }
    for (k=0;k<n-1;k++)
    {
        for (i=k;i<n;i++)
        {
            s[i]=fabs(a[i][k]);
            for (j=k;j<n;j++)
            {
                if (fabs(a[i][j])>s[i])
                {
                    s[i]=fabs(a[i][j]);
                }
            }
            if (s[i]==0)
            {
                printf("\nThe matrix is Singular matrix.\n");
                return;
            }
            for (j=k;j<n;j++)
            {
                a[i][j]=a[i][j]/s[i];
            }
            b[i]=b[i]/s[i];
        }
        p=k;
        temp=fabs(a[k][k]);
        for (i=k;i<n;i++)
        {
            if (fabs(a[i][k])>temp)
            {
                p=i;
                temp=fabs(a[i][k]);
            }
        }
        if (temp==0)
        {
            printf("\n②The matrix is Singular matrix.\n");
            return;
        }
        if (p!=k)
        {
            for (j=0;j<n;j++)
            {
                temp=a[k][j];
                a[k][j]=a[p][j];
                a[p][j]=temp;
            }
            temp=b[k];
            b[k]=b[p];
            b[p]=temp;
        }
        for (i=k+1;i<n;i++)
        {
            m=a[i][k]/a[k][k];
            for (j=k;j<n;j++)
            {
                a[i][j]=a[i][j]-m*a[k][j];
            }
            b[i]=b[i]-b[k]*m;
        }
    }
    if (a[n-1][n-1]==0)
    {
        printf("\n③The matrix is Singular matrix.\n");
        return;
    }
    x[n-1]=b[n-1]/a[n-1][n-1];
    for (k=n-2;k>=0;k--)
    {
        x[k]=b[k];
        for (j=k+1;j<n;j++)
        {
            x[k]=x[k]-a[k][j]*x[j];
        }
        x[k]=x[k]/a[k][k];
    }
    printf("\nx = \n");
    for (i=0;i<n;i++)
    {
        printf(" %f \n",x[i]);
    }
}

void ImplicitGauss(int n,double **A,double B[])
{
    int i,j,k;
    int p;
    double temp,m;
    double s[n];
    double a[n][n];
    double b[n];
    double x[n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            a[i][j]=A[i][j];
        }
        b[i]=B[i];
    }
    for (k=0;k<n-1;k++)
    {
        for (i=k;i<n;i++)
        {
            s[i]=fabs(a[i][k]);
            for (j=k;j<n;j++)
            {
                if (fabs(a[j][k])>s[i])
                {
                    s[i]=fabs(a[j][k]);
                }
            }
            if (s[i]==0)
            {
                printf("\nThe matrix is Singular matrix.\n");
                return;
            }
        }
        p=k;
        temp=fabs(a[p][k])/s[p];
        for (i=k;i<n;i++)
        {
            if ((fabs(a[i][k])/s[i])>temp)
            {
                p=i;
                temp=fabs(a[i][k])/s[i];
            }
        }
        if (temp==0)
        {
            printf("\nThe matrix is Singular matrix.\n");
            return;
        }
        if (p!=k)
        {
            for (j=0;j<n;j++)
            {
                temp=a[k][j];
                a[k][j]=a[p][j];
                a[p][j]=temp;
            }
            temp=b[k];
            b[k]=b[p];
            b[p]=temp;
        }
        for (i=k+1;i<n;i++)
        {
            m=a[i][k]/a[k][k];
            for (j=k;j<n;j++)
            {
                a[i][j]=a[i][j]-m*a[k][j];
            }
            b[i]=b[i]-b[k]*m;
        }
    }
    if (a[n-1][n-1]==0)
    {
        printf("\nThe matrix is Singular matrix.\n");
        return;
    }
    x[n-1]=b[n-1]/a[n-1][n-1];
    for (k=n-2;k>=0;k--)
    {
        x[k]=b[k];
        for (j=k+1;j<n;j++)
        {
            x[k]=x[k]-a[k][j]*x[j];
        }
        x[k]=x[k]/a[k][k];
    }
    printf("\nx = \n");
    for (i=0;i<n;i++)
    {
        printf(" %f \n",x[i]);
    }
}
