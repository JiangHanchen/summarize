//使用链栈完成对数据的存取
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkStack;

void InitStack(LinkStack *S)
{
    (*S) = (Node *)malloc(sizeof(Node));
    (*S)->next = NULL;
}

void PushStack(LinkStack S, Node *p)
{
    p->next = S->next;
    S->next = p;
}

Node *PopStack(LinkStack S)
{
    Node *r = S->next;
    S->next = S->next->next;
    return r;
}

void InputStack(LinkStack S)
{
    int n;
    Node *p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        PushStack(S, p);
    }
}

void OutputStack(LinkStack S)
{
    while (S->next != NULL)
    {
        printf("%d ", PopStack(S)->data);
    }
}

int main()
{
    LinkStack S;
    InitStack(&S);
    InputStack(S);
    OutputStack(S);
    return 0;
}