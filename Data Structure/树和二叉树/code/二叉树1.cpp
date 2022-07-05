//先序建立二叉树，并先序、中序、后序遍历二叉树
#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *LChild, *RChild;
} Node, *BiTree;

void CreateTreeByDLR(BiTree *Root) //先序建立二叉树，顺序输入二叉树结点数据，无结点输入-1
{
    int d;
    scanf("%d", &d);
    if (d != -1)
    {
        (*Root) = (Node *)malloc(sizeof(Node));
        (*Root)->data = d;
        (*Root)->LChild = NULL;
        (*Root)->RChild = NULL;
        CreateTreeByDLR(&(*Root)->LChild);
        CreateTreeByDLR(&(*Root)->RChild);
    }
}

void VisitNode(Node *p)
{
    printf("%d ", p->data);
}

void VisitTreeByDLR(BiTree Root)
{
    if (Root != NULL)
    {
        VisitNode(Root);
        VisitTreeByDLR(Root->LChild);
        VisitTreeByDLR(Root->RChild);
    }
    else
    {
        printf("%d ", -1);
    }
}

void VisitTreeByLDR(BiTree Root)
{
    if (Root != NULL)
    {
        VisitTreeByLDR(Root->LChild);
        VisitNode(Root);
        VisitTreeByLDR(Root->RChild);
    }
    else
    {
        printf("%d ", -1);
    }
}

void VisitTreeByLRD(BiTree Root)
{
    if (Root != NULL)
    {
        VisitTreeByLRD(Root->LChild);
        VisitTreeByLRD(Root->RChild);
        VisitNode(Root);
    }
    else
    {
        printf("%d ", -1);
    }
}

int main()
{
    BiTree T;
    T = NULL;
    CreateTreeByDLR(&T);
    printf("\n");
    VisitTreeByDLR(T);
    printf("\n");
    VisitTreeByLDR(T);
    printf("\n");
    VisitTreeByLRD(T);
    return 0;
}