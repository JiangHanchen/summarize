//建立中序线索树，并查找给定结点的前驱和后继
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *LChild, *RChild;
    bool Ltag, Rtag; //标志位为0时，Child指向孩子结点；标志位为1时，Child指向前驱和后继
} Node, *BiTree;

void CreateTreeByDLR(BiTree *Root) //先序建立二叉树，顺序输入二叉树结点数据，无结点输入-1
{
    int d;
    scanf("%d", &d);
    if (d != -1)
    {
        (*Root) = (Node *)malloc(sizeof(Node));
        (*Root)->data = d;
        (*Root)->Ltag = 0;
        (*Root)->Rtag = 0;
        (*Root)->LChild = NULL;
        (*Root)->RChild = NULL;
        CreateTreeByDLR(&(*Root)->LChild);
        CreateTreeByDLR(&(*Root)->RChild);
    }
}

Node *pre = NULL;

void Inthread(BiTree Root) //线索化
{
    if (Root != NULL)
    {
        Inthread(Root->LChild);
        if (Root->LChild == NULL)
        {
            Root->Ltag = 1;
            Root->LChild = pre;
        }
        if (pre != NULL && pre->RChild == NULL)
        {
            pre->Rtag = 1;
            pre->RChild = Root;
        }
        pre = Root;
        Inthread(Root->RChild);
    }
}

void FindPre(Node *p)
{
    if (p->Ltag == 1)
    {
        if (p->LChild)
            printf("%d ", p->LChild->data);
        else
            printf("None! ");
    }
    else
    {
        Node *q;
        for (q = p->LChild; q && q->Rtag == 0; q = q->RChild)
            ; //寻找p左子树中最右下的结点
        if (q)
            printf("%d ", q->data);
        else
            printf("None! ");
    }
}

void FindNext(Node *p)
{
    //寻找p右子树中最左下结点
    if (p->Rtag == 1)
    {
        if (p->RChild)
            printf("%d ", p->RChild->data);
        else
            printf("None! ");
    }
    else
    {
        Node *q;
        for (q = p->RChild; q && q->Ltag == 0; q = q->LChild)
            ;
        if (q)
            printf("%d ", q->data);
        else
            printf("None! ");
    }
}

int main()
{
    BiTree T;
    T = NULL;
    CreateTreeByDLR(&T);
    Inthread(T);
    Node *p = T->LChild; //找两个结点的前驱和后继
    FindPre(p);
    FindNext(p);
    p = T->RChild;
    FindPre(p);
    FindNext(p);
    return 0;
}