#include <stdio.h>
#include <stdlib.h>
#define max 2000

typedef struct{
    int key;
    char letter;
}record;//���ڴ洢ÿ����¼�Ĺؼ����Լ������Ϣ
typedef struct celltype{
    record data;
    struct celltype *lchild,*rchild;
}BSTNode;//����������ṹ
typedef BSTNode *BST;
typedef struct{
    int key;
    char letter;
}LX;//������ұ�����ṹ
typedef LX  List[max];//������ұ�
List F;//�����û��Լ������Ĳ��ұ�
List T;//���ڲ��ԵĲ��ұ�
int last;//��ǲ��ұ��β
double success,fail;//��¼���ҳɹ���ʧ��ʱ���Ҵ���
BST create();//��������������ĺ���
void insert(record R,BST *F);//�ڶ���������в���Ԫ�صĺ���
BST search(BST root,int key);//���ݹؼ��ֲ���Ԫ�صĺ���
void inorder(BST root);//�������������������Թؼ���Ϊ�����
void deletex(int key,BST *F);//ɾ��Ԫ�غ���
record deletemin(BST *F);//ɾ���ĸ�������
void createlist();//�����۰���Ҳ��ұ�
void test();//���Ժ���������
void BST1();//���Ժ���1
void BST2();//���Ժ���2
void LIST();//���Ժ���3
BST search1(BST root,int key);//�Ľ��Ķ�����Һ���
int searchlist(int key);//�۰���Һ���
int searchlist1(int key);//�Ľ����۰���Һ���
int main()
{
    int choice = 1,key,find=-1;
    record R;
    BST root,result;
    while(choice!=0)
    {
        printf("1.�������������\n");
        printf("2.�ڶ���������в���Ԫ��\n");
        printf("3.�ڶ��������Թؼ��ֽ��в���\n");
        printf("4.�Թؼ���ɾ��Ԫ��\n");
        printf("5.�Թؼ��ֶ�Ԫ�ؽ�������\n");
        printf("6.�����۰���ҵĲ��ұ�\n");
        printf("7.�Թؼ��ֽ����۰����\n");
        printf("8.������Ժ���\n");
        printf("0.�˳�ϵͳ\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: root = create();                                                                break;
            case 2: printf("������Ҫ����Ԫ�صĹؼ���\n");
                    scanf("%d",&R.key);
                    printf("������Ҫ�����Ԫ��\n");
                    scanf(" %c",&R.letter);
                    insert(R,&root);
                                                                                                    break;
            case 3: printf("������Ҫ����Ԫ�صĹؼ���\n");
                    scanf("%d",&key);
                    result = search(root,key);
                    if(result == NULL)
                        printf("��ƥ��Ԫ��\n");
                    else
                        printf("���ҽ��Ϊ[%d]  %c\n",result->data.key,result->data.letter);        break;
            case 4: printf("������Ҫɾ��Ԫ�صĹؼ���\n");
                    scanf("%d",&R.key);
                    deletex(R.key,&root);                                                           break;
            case 5: inorder(root);                                                                  break;
            case 6: createlist();                                                                   break;
            case 7: printf("������Ҫ����Ԫ�صĹؼ���\n");
                    scanf("%d",&key);
                    find = searchlist(key);
                    if(find == -1)
                        printf("��ƥ��Ԫ��\n");
                    else
                        printf("���ҽ��Ϊ[%d]  %c\n",F[find].key,F[find].letter);
                                                                                                    break;
            case 8:test();      break;
            case 0:             break;
            default:            break;
        }
    }
    return 0;
}
BST create()
{
    BST F = NULL;
    record R;
    printf("������ؼ���(0��ʾ����)\n");
    scanf("%d",&R.key);
    if(R.key!=0)
    {
        printf("�������ӦԪ��\n");
        scanf(" %c",&R.letter);
    }
    while(R.key)
    {
        insert(R,&F);
        printf("������ؼ���(0��ʾ����)\n");
        scanf("%d",&R.key);
        if(R.key!=0)
        {
            printf("�������ӦԪ��\n");
            scanf(" %c",&R.letter);
        }
    }
    return F;
}
void insert(record R,BST *F)
{
    if((*F) == NULL)
    {
        (*F) = (BST)malloc(sizeof(BSTNode));
        (*F)->data = R;
        (*F)->lchild = NULL;
        (*F)->rchild = NULL;
    }
    else if(R.key < (*F)->data.key)
        insert(R,&(*F)->lchild);
    else if(R.key > (*F)->data.key)
        insert(R,&(*F)->rchild);
}
BST search(BST root,int key)
{
    BST p = root;
    if(p == NULL||key == p->data.key)
        return p;
    if(key < p->data.key)
        return(search(p->lchild,key));
    else
        return(search(p->rchild,key));
}
void inorder(BST root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("[%d]  %c\n",root->data.key,root->data.letter);
        inorder(root->rchild);
    }
}
void deletex(int key,BST *F)
{
    if((*F)!=NULL)
        if(key < (*F)->data.key)
            deletex(key,&(*F)->lchild);
        else if(key > (*F)->data.key)
            deletex(key,&(*F)->rchild);
        else
        {
            if((*F)->rchild==NULL)
                (*F) = (*F)->lchild;
            else if((*F)->lchild==NULL)
                (*F) = (*F)->rchild;
            else
                (*F)->data = deletemin(&(*F)->rchild);
        }
}
record deletemin(BST *F)
{
    record tmp;
    BST p;
    if((*F)->lchild==NULL)
    {
        p = *F;
        tmp = (*F)->data;
        (*F) = (*F)->rchild;
        free(p);
        return tmp;
    }
    else
        return (deletemin((&(*F)->lchild)));
}
void createlist()
{
    int i=0,key;
    last=0;
    char letter;
    printf("������ؼ���(0��ʾ��������������)\n");
    scanf("%d",&key);
    if(key!=0)
    {
        printf("�������ӦԪ��\n");
        scanf(" %c",&letter);
    }
    while(key)
    {
        F[i].key = key;
        F[i].letter = letter;
        i++;
        last++;
        printf("������ؼ���(0��ʾ��������������)\n");
        scanf("%d",&key);
        if(key!=0)
        {
            printf("�������ӦԪ��\n");
            scanf(" %c",&letter);
        }
    }
}
int searchlist(int key)
{
    int low = 0,up = last-1,mid;
    while(low <= up)
    {
        mid = (low+up)/2;
        if(F[mid].key == key)
            return mid;
        else if(F[mid].key > key)
            up = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
void test()
{
    int choice = 1;
    while(choice!=0)
    {
        printf("1.��1~1024Ϊ�ؼ���˳�����뽨��BST�������������\n");
        printf("2.��1~1024Ϊ�ؼ���������뽨��BST�������������\n");
        printf("3.��1~1024Ϊ�ؼ���˳�����뽨�����ֲ��ұ������������\n");
        printf("0.�˳�ϵͳ\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:BST1();  break;
            case 2:BST2();  break;
            case 3:LIST();  break;
            case 0:printf("�˳�ϵͳ\n"); break;
            default:printf("ѡ������\n");
        }
    }
}
void BST1()
{
    int i;
    success = 0;
    BST X1 = NULL;
    record R;
    for(i=1;i<=2047;i=i+2)//������ʼ��������
    {
        R.key = i;
        R.letter = i%58 + 65;
        insert(R,&X1);
    }
    for(i=1;i<=2047;i=i+2)
    {
       search1(X1,i);
    }
    printf("���ҳɹ�ʱASLΪ%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        search1(X1,i);
    }
    printf("����ʧ��ʱASLΪ%f\n",fail/1025);
}
BST search1(BST root,int key)
{
    success++;//����һ�δ���++
    fail++;
    BST p = root;
    if(p == NULL||key == p->data.key)
        return p;
    if(key < p->data.key)
        return(search1(p->lchild,key));
    else
        return(search1(p->rchild,key));
}
void BST2()
{
    int i=1,j,cord[1024],tmp,r1,r2;
    success = 0;
    BST X2 = NULL;
    record R;
    for(j=0;j<1024;j++)//������ʼ��������
    {
        cord[j] = i;
        i = i + 2;
    }
    for(i=0;i<2048;i++)//�����������������
    {
        r1 = rand()%1024;
        r2 = rand()%1024;
        tmp = cord[r1];
        cord[r1] = cord[r2];
        cord[r2] = tmp;
    }
    for(i=0;i<1024;i++)
    {
        R.key = cord[i];
        insert(R,&X2);
    }
    for(i=1;i<=2047;i=i+2)
    {
       search1(X2,i);
    }
    printf("���ҳɹ�ʱASLΪ%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        search1(X2,i);
    }
    printf("����ʧ��ʱASLΪ%f\n",fail/1024);
}
void LIST()
{
    int i=0,j=1,key;
    last=0;
    for(i=0;i<=1023;i++)//������ʼ��������
    {
        T[i].key = j;
        T[i].letter =  j%58 + 65;
        j = j + 2;
        last++;
    }
    success = 0;
    for(i=1;i<=2047;i=i+2)
    {
       searchlist1(i);
    }
    printf("���ҳɹ�ʱASLΪ%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        searchlist1(i);
    }
    printf("����ʧ��ʱASLΪ%f\n",fail/1025);
}
int searchlist1(int key)
{
    int low = 0,up = last-1,mid;
    while(low <= up)
    {
        success++;//ѭ��һ�δ���++
        fail++;
        mid = (low+up)/2;
        if(T[mid].key == key)
            return mid;
        else if(T[mid].key > key)
            up = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
