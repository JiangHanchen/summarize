//在无重复元素的循环链表中依次访问三个指定元素
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
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateList(LinkList L)
{
    int n;
    Node *p, *pre = L;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    p->next = L->next; //最后一个结点指向第一个结点
}

void FindElem(LinkList L, int *a)
{
    Node *p = L->next;
    int cnt = 0;
    while (true)
    {
        if (cnt == 3)
            break;
        if (p->data == a[cnt])
        {
            printf("%d ", p->data);
            cnt++;
            continue;
        }
        else
        {
            p = p->next;
        }
    }
}

int main()
{
    LinkList L;
    InitList(&L);
    CreateList(L);
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    FindElem(L, a);
    return 0;
}