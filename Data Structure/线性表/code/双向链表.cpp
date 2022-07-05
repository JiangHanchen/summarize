//创建一个双向链表并逆向输出
#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *pre, *next;
} Node, *LinkList;

void InitList(LinkList *L)
{
    (*L) = (Node *)malloc(sizeof(Node));
    (*L)->pre = NULL;
    (*L)->next = NULL;
}

void CreateList(LinkList L)
{
    int n;
    Node *p, *prior = L;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        p->pre = prior;
        prior->next = p;
        prior = p;
    }
}

void OutputList(LinkList L)
{
    Node *p = L;
    while (p->next != NULL)
        p = p->next;
    while (p != L)
    {
        printf("%d ", p->data);
        p = p->pre;
    }
}

int main()
{
    LinkList L;
    InitList(&L);
    CreateList(L);
    OutputList(L);
    return 0;
}