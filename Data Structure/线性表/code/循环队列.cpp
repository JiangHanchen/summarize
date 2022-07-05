//用循环队列打印杨辉三角形
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct Queue
{
    ElemType data[MAXSIZE];
    int front, rear; //队头和队尾，即第一个和最后一个元素所在下标
} Queue;

void InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = MAXSIZE - 1;
}

void PushQueue(Queue *Q, ElemType e)
{
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->data[Q->rear] = e;
}

ElemType PopQueue(Queue *Q)
{
    ElemType r = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    printf("%d ", r);
    return r;
}

ElemType VisitQueue(Queue *Q)
{
    return Q->data[Q->front];
}

bool IsEmpty(Queue *Q)
{
    return Q->front == (Q->rear + 1) % MAXSIZE ? true : false;
}

int layer = 1;

void PrintTriangle(Queue *Q, int n)
{
    if (layer == 1)
    {
        printf("%d\n", 1);
        if (layer == n)
        {
            return;
        }
        layer++;
        PrintTriangle(Q, n);
    }
    else
    {
        PushQueue(Q, 1);
        for (int i = 1; i <= layer - 1; i++)
        {
            PushQueue(Q, PopQueue(Q) + VisitQueue(Q));
        }
        PopQueue(Q);
        PushQueue(Q, 1);
        printf("\n");
        if (layer == n)
        {
            return;
        }
        layer++;
        PrintTriangle(Q, n);
    }
}

int main()
{
    Queue Q;
    InitQueue(&Q);
    int n;
    scanf("%d", &n);
    PushQueue(&Q, 1);
    PushQueue(&Q, 1);
    PrintTriangle(&Q, n);
}