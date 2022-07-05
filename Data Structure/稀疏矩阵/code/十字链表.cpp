//使用十字链表创建矩阵
#include <bits/stdc++.h>
#define MAXSIZE 300
#define ElemType int
using namespace std;

typedef struct Node
{
    int x, y;
    ElemType e;
    struct Node *right, *down;
} Node, *LinkNode;

typedef struct Matrix
{
    int r, c, t;
    LinkNode *r_head, *c_head;
} Matrix;

void InsertNode(Matrix *M, Node *p)
{
    //插入行中正确位置
    if (M->r_head[p->x] == NULL) //该行还没有元素
    {
        M->r_head[p->x] = p;
    }
    else //比较已有元素的列号，找到正确位置并插入
    {
        Node *q = M->r_head[p->x];
        while (q->right != NULL && q->right->y < p->y)
            q = q->right;
        p->right = q->right;
        q->right = p;
    }
    //插入列中正确位置
    if (M->c_head[p->y] == NULL) //该行还没有元素
    {
        M->c_head[p->y] = p;
    }
    else //比较已有元素的列号，找到正确位置并插入
    {
        Node *q = M->c_head[p->y];
        while (q->down != NULL && q->down->x < p->x)
            q = q->down;
        p->down = q->down;
        q->down = p;
    }
}

void CreateMatrix(Matrix *M)
{
    M->r_head = (LinkNode *)malloc((M->r + 1) * sizeof(LinkNode));
    M->c_head = (LinkNode *)malloc((M->c + 1) * sizeof(LinkNode));
    for (int i = 1; i <= M->r; i++)
        M->r_head[i] = NULL;
    for (int i = 1; i <= M->c; i++)
        M->c_head[i] = NULL;
    for (int i = 1; i <= M->t; i++)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        scanf("%d%d%d", &p->x, &p->y, &p->e);
        InsertNode(M, p);
    }
}

int main()
{
    Matrix A, B;
    CreateMatrix(&A);
    return 0;
}