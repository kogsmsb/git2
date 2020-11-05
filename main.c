#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct bstree *lchild;
    struct bstree *rchild;
}bstree;
typedef bstree *BST;
BST Find (int x,BST T)
{
    while (T)
    {
        if (x>T->data)
            T=T->rchild;
        else if (x<T->data)
            T=T->lchild;
        else
            return T;
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
    if (T)
    {
        while (T->rchild)
            T=T->rchild;
    }
    return T;
}

BST Insert (int x,BST T)
{
    if (!T)
    {
        T=malloc(sizeof(struct bstree));
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

int main()
{
    BST T=NULL;
    T=Insert(5,T);
    while (T)
    {
        printf("%d",T->data);
        T=T->lchild;
    }
}
