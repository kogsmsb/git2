#include <stdio.h>
#include <stdlib.h>

#define max 2000

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Bstree;
typedef Bstree *BST;

int list[max];
int count=0;
int last=0;
float success,failed;

BST Find (int x,BST T)
{
    BST F=T;
    while (F!=NULL)
    {
        if (x>F->data)
            F=F->rchild;
        else if (x<F->data)
            F=F->lchild;
        else
            return F;
    }
    return NULL;
}

BST FindMin (BST T)
{
    if (!T)
        return NULL;
    else if (!T->lchild)
        return T;
    else
        return FindMin(T->lchild);
}

BST FindMax (BST T)
{
    BST F=T;
    if (F)
    {
        while (F->rchild)
            T=F->rchild;
    }
    return F;
}

BST Insert (int x,BST T)
{
    if (!T)
    {
        T=(BST)malloc(sizeof(struct node));
        T->data=x;
        T->lchild=T->rchild=NULL;
    }
    else
    {
        if (x<T->data)
        {
            T->lchild=Insert(x,T->lchild);
        }
        else if (x>T->data)
        {
            T->rchild=Insert(x,T->rchild);
        }
    }
    return T;
}
BST Delete(int x,BST T)
{
    BST temp;
    if (!T)
    {
        printf("Ҫɾ����Ԫ��δ�ҵ�\n");
    }
    else if (x<T->data)
        T->lchild=Delete(x,T->lchild);
    else if (x>T->data)
        T->rchild=Delete(x,T->rchild);
    else
    {
        if (T->lchild!=NULL &&T->rchild!=NULL)
        {
            temp=FindMin(T->rchild);
            T->data=temp->data;
            T->rchild=Delete(x,T->rchild);
        }
        else
        {
            temp=T;
            if (T->lchild==NULL)
            {
                T=T->rchild;
            }
            else if (T->rchild==NULL)
            {
                T=T->lchild;
            }
            free(temp);
        }
    }
    return T;
}

void InOrder(BST T)
{
    if (T==NULL)
        return;
    else
    {
        InOrder(T->lchild);
        printf("%d ",T->data);
        list[count]=T->data;
        count++;
        last=count;
        InOrder(T->rchild);
    }
}

int FindHALF(int k)
{
    int low,up,mid;
    low=0;
    up=last;
    while(low<=up)
    {
        mid=(low+up)/2;
        if(list[mid]==k)
            return mid;
        else if(list[mid]<k)
            low=mid+1;
        else
            up=mid-1;
    }
    return -1;
}
int SearchHALF(int k)
{
    int low,up,mid;
    low=0;
    up=1023;
    while(low<=up)
    {
        mid=(low+up)/2;
        success++;
        failed++;
        if(list[mid]==k)
            return mid;
        else if(list[mid]<k)
            low=mid+1;
        else
            up=mid-1;
    }
    return -1;
}
void TestHALF( )
{
    int i,j;
    j=1;
    for (i=0; i<1024; i++)
    {
        list[i]=j;
        j=j+2;
    }
    success=0;
    for (i=1; i<=2047; i=i+2)
    {
        SearchHALF(i);
    }
    printf("���ҳɹ�ʱASLΪ%f\n",success/1024);
    failed=0;
    for (i=0; i<=2048; i=i+2)
    {
        SearchHALF(i);
    }
    printf("����ʧ��ʱASLΪ%f\n",failed/1025);
}
BST SearchTest (int x,BST T)//ʵ������searchbst
{
    BST F=T;
    while (F!=NULL)
    {
        success++;
        failed++;
        if (x>F->data)
            F=F->rchild;
        else if (x<F->data)
            F=F->lchild;
        else
            return F;
    }
    return NULL;
}
void TestBST()
{
    int i;
    int j=1;
    int tem;
    BST X1=NULL;
    BST X2=NULL;
    BST P;
    int test1[1024];
    int test2[1024];
    int flag[1024];
    int sea;
    for (i=0; i<1024; i++)
    {
        test1[i]=j;
        flag[i]=0;
        j=j+2;
    }
    i=0;
    while(i<1024)
    {
        tem=rand()%1024;
        if(flag[tem]==0)
        {
            test2[i]=test1[tem];
            flag[tem]=1;
            i++;
        }
    }
    for (i=0; i<1024; i++)
    {
        X1=Insert(test1[i],X1);
    }
    for (i=0; i<1024; i++)
    {
        X2=Insert(test2[i],X2);
    }
    success=0;
    for (i=1; i<2048; i=i+2)
    {
        sea=test2[i];
        P=SearchTest(sea,X1);
    }
    printf("����1���ҳɹ�ʱASLΪ%f\n",success/1024);
    failed=0;
    for (i=0; i<=2048; i=i+2)
    {
        P=SearchTest(i,X1);
    }
    printf("����1����ʧ��ʱASLΪ%f\n",failed/1025);
    success=0;
    for (i=1; i<2048; i=i+2)
    {
        sea=test1[i];
        P=SearchTest(sea,X2);
    }
    printf("����2���ҳɹ�ʱASLΪ%f\n",success/1024);
    failed=0;
    for (i=0; i<=2048; i=i+2)
    {
        P=SearchTest(i,X2);
    }
    printf("����2����ʧ��ʱASLΪ%f\n",failed/1025);

}
int main()
{
    BST T=NULL;
    int choice=1;
    int flag=0;
    int ins,del,fin;
    int rei;
    BST res;
    while (choice)
    {
        printf("1.���һ�������\n2.�㷨����\n0.�˳�\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("1.����(����)BST\n2.ɾ���ڵ�\n3.���ҽڵ�\n4.��������\n5.�۰����\n0.�˳�\n");
            scanf("%d",&flag);
            switch (flag)
            {
            case 1:
                printf("����ڵ�:\n");
                scanf("%d",&ins);
                T=Insert(ins,T);
                printf("�������\n");
                break;
            case 2:
                printf("����ڵ�:\n");
                scanf("%d",&del);
                T=Delete(del,T);
                printf("ɾ�����\n");
                break;
            case 3:
                printf("����ڵ�:\n");
                scanf("%d",&fin);
                res=Find(fin,T);
                if(res==NULL)
                    printf("����ʧ��\n");
                else
                    printf("���ҵĽ��Ϊ:%d\n",res->data);
                break;
            case 4:
                printf("������Ϊ:\n");
                InOrder(T);
                printf("\n");
                last=count;
                count=0;
                break;
            case 5:
                printf("����ڵ�:\n");
                scanf("%d",&fin);
                rei=FindHALF(fin);
                if(rei==-1)
                    printf("����ʧ��\n");
                else
                    printf("���ҵĽ��Ϊ:%d\n",list[rei]);
                break;
            case 0:
                break;
            }
            break;
        case 2:
            printf("�ȽϽ��:\n(��һ��Ϊ0,2,4������˳��,�ڶ���Ϊ������)\n");
            printf("BST����:\n");
            TestBST();
            printf("�۰����:\n");
            TestHALF();
            break;
        case 0:
            printf("�������\n");
            break;
        }
    }
}

/*for (i=0;i<64;i++)
{
    for (j=0;j<16;j++)
    {
        ptintf("%d\t",test2[i*16+j]);
    }
    printf("\n");
}*/
