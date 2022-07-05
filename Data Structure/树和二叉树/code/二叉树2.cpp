//层次遍历二叉树
#include <bits/stdc++.h>
#define ElemType int
#define ElemTypeQueue Node *
#define MAXSIZE 105
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *LChild, *RChild;
} Node, *BiTree;

typedef struct Queue
{
    ElemTypeQueue data[MAXSIZE];
    int front, rear; //队头和队尾，即第一个和最后一个元素所在下标
} Queue;

void InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = MAXSIZE - 1;
}

void PushQueue(Queue *Q, ElemTypeQueue e)
{
    Q->rear = (Q->rear + 1) % MAXSIZE; //循环队列在入队和出队的过程中需要防止越界，体现“循环”
    Q->data[Q->rear] = e;
}

ElemTypeQueue PopQueue(Queue *Q)
{
    ElemTypeQueue r = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE; //同上
    return r;
}

ElemTypeQueue VisitQueue(Queue *Q)
{
    return Q->data[Q->front];
}

bool IsEmpty(Queue *Q)
{
    return Q->front == (Q->rear + 1) % MAXSIZE ? true : false;
}

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

void VisitTreeByLayer(BiTree Root, Queue *Q)
{
    PushQueue(Q, Root);
    while (!IsEmpty(Q))
    {
        Node *p = PopQueue(Q);
        printf("%d ", p->data);
        if (p->LChild)
            PushQueue(Q, p->LChild);
        if (p->RChild)
            PushQueue(Q, p->RChild);
    }
}

int main()
{
    Queue Q;
    InitQueue(&Q);
    BiTree T;
    T = NULL;
    CreateTreeByDLR(&T);
    printf("\n");
    VisitTreeByLayer(T, &Q);
    return 0;
}