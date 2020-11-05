#include <stdio.h>
#include <stdlib.h>
#define max 2000

typedef struct{
    int key;
    char letter;
}record;//用于存储每个记录的关键字以及相关信息
typedef struct celltype{
    record data;
    struct celltype *lchild,*rchild;
}BSTNode;//二叉查找树结构
typedef BSTNode *BST;
typedef struct{
    int key;
    char letter;
}LX;//定义查找表基本结构
typedef LX  List[max];//定义查找表
List F;//用于用户自己创建的查找表
List T;//用于测试的查找表
int last;//标记查找表表尾
double success,fail;//记录查找成功和失败时查找次数
BST create();//建立二叉查找树的函数
void insert(record R,BST *F);//在二叉查找树中插入元素的函数
BST search(BST root,int key);//根据关键字查找元素的函数
void inorder(BST root);//中序遍历二叉查找树即以关键字为序输出
void deletex(int key,BST *F);//删除元素函数
record deletemin(BST *F);//删除的辅助函数
void createlist();//创建折半查找查找表
void test();//测试函数主函数
void BST1();//测试函数1
void BST2();//测试函数2
void LIST();//测试函数3
BST search1(BST root,int key);//改进的二叉查找函数
int searchlist(int key);//折半查找函数
int searchlist1(int key);//改进的折半查找函数
int main()
{
    int choice = 1,key,find=-1;
    record R;
    BST root,result;
    while(choice!=0)
    {
        printf("1.创建二叉查找树\n");
        printf("2.在二叉查找树中插入元素\n");
        printf("3.在二叉树中以关键字进行查找\n");
        printf("4.以关键字删除元素\n");
        printf("5.以关键字对元素进行排序\n");
        printf("6.建立折半查找的查找表\n");
        printf("7.以关键字进行折半查找\n");
        printf("8.进入测试函数\n");
        printf("0.退出系统\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: root = create();                                                                break;
            case 2: printf("请输入要插入元素的关键字\n");
                    scanf("%d",&R.key);
                    printf("请输入要插入的元素\n");
                    scanf(" %c",&R.letter);
                    insert(R,&root);
                                                                                                    break;
            case 3: printf("请输入要查找元素的关键字\n");
                    scanf("%d",&key);
                    result = search(root,key);
                    if(result == NULL)
                        printf("无匹配元素\n");
                    else
                        printf("查找结果为[%d]  %c\n",result->data.key,result->data.letter);        break;
            case 4: printf("请输入要删除元素的关键字\n");
                    scanf("%d",&R.key);
                    deletex(R.key,&root);                                                           break;
            case 5: inorder(root);                                                                  break;
            case 6: createlist();                                                                   break;
            case 7: printf("请输入要查找元素的关键字\n");
                    scanf("%d",&key);
                    find = searchlist(key);
                    if(find == -1)
                        printf("无匹配元素\n");
                    else
                        printf("查找结果为[%d]  %c\n",F[find].key,F[find].letter);
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
    printf("请输入关键字(0表示结束)\n");
    scanf("%d",&R.key);
    if(R.key!=0)
    {
        printf("请输入对应元素\n");
        scanf(" %c",&R.letter);
    }
    while(R.key)
    {
        insert(R,&F);
        printf("请输入关键字(0表示结束)\n");
        scanf("%d",&R.key);
        if(R.key!=0)
        {
            printf("请输入对应元素\n");
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
    printf("请输入关键字(0表示结束，增序输入)\n");
    scanf("%d",&key);
    if(key!=0)
    {
        printf("请输入对应元素\n");
        scanf(" %c",&letter);
    }
    while(key)
    {
        F[i].key = key;
        F[i].letter = letter;
        i++;
        last++;
        printf("请输入关键字(0表示结束，增序输入)\n");
        scanf("%d",&key);
        if(key!=0)
        {
            printf("请输入对应元素\n");
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
        printf("1.以1~1024为关键字顺序输入建立BST并计算查找性能\n");
        printf("2.以1~1024为关键字随机输入建立BST并计算查找性能\n");
        printf("3.以1~1024为关键字顺序输入建立二分查找表并计算查找性能\n");
        printf("0.退出系统\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:BST1();  break;
            case 2:BST2();  break;
            case 3:LIST();  break;
            case 0:printf("退出系统\n"); break;
            default:printf("选择有误\n");
        }
    }
}
void BST1()
{
    int i;
    success = 0;
    BST X1 = NULL;
    record R;
    for(i=1;i<=2047;i=i+2)//建立初始测试数据
    {
        R.key = i;
        R.letter = i%58 + 65;
        insert(R,&X1);
    }
    for(i=1;i<=2047;i=i+2)
    {
       search1(X1,i);
    }
    printf("查找成功时ASL为%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        search1(X1,i);
    }
    printf("查找失败时ASL为%f\n",fail/1025);
}
BST search1(BST root,int key)
{
    success++;//调用一次次数++
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
    for(j=0;j<1024;j++)//建立初始测试数据
    {
        cord[j] = i;
        i = i + 2;
    }
    for(i=0;i<2048;i++)//将测试数据随机打乱
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
    printf("查找成功时ASL为%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        search1(X2,i);
    }
    printf("查找失败时ASL为%f\n",fail/1024);
}
void LIST()
{
    int i=0,j=1,key;
    last=0;
    for(i=0;i<=1023;i++)//建立初始测试数据
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
    printf("查找成功时ASL为%f\n",success/1024);
    fail = 0;
    for(i=0;i<=2048;i=i+2)
    {
        searchlist1(i);
    }
    printf("查找失败时ASL为%f\n",fail/1025);
}
int searchlist1(int key)
{
    int low = 0,up = last-1,mid;
    while(low <= up)
    {
        success++;//循环一次次数++
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
