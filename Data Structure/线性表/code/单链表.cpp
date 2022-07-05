//创建并合并两个有序单链表，并删除重复元素
#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList *L)
{
    (*L) = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
    (*L)->data = -1000;
}

void CreateList(LinkList L)
{
    int n;
    scanf("%d", &n);
    Node *p, *pre;
    pre = L;
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
}

void MergeList(LinkList *A, LinkList *B)
{
    Node *posA, *posB, *pre = (*A), *t;
    posA = (*A)->next;
    posB = (*B)->next;
    while (1)
    {
        if (posB == NULL)
        {
            break;
        }
        if (posA == NULL)
        {
            pre->next = posB;
            break;
        }
        if (posA->data < posB->data)
        {
            pre = posA;
            posA = posA->next;
            continue;
        }
        if (posA->data >= posB->data)
        {
            t = posB->next;
            pre->next = posB;
            posB->next = posA;
            posB = t;
            pre = pre->next;
            continue;
        }
    }
}

void DeleteSame(LinkList *L)
{
    Node *pos = (*L)->next->next, *pre = (*L)->next;
    while (pos != NULL)
    {
        if (pos->data == pre->data)
        {
            pre->next = pos->next;
            pos = pre->next;
        }
        else
        {
            pre = pre->next;
            pos = pos->next;
        }
    }
}

void OutputList(LinkList L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LinkList A, B;
    InitList(&A);
    InitList(&B);
    CreateList(A);
    CreateList(B);
    MergeList(&A, &B);
    DeleteSame(&A);
    OutputList(A);
    return 0;
}