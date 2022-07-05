//使用多栈共享技术将左栈中的元素顺序不变放入右栈
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct Stack
{
    ElemType data[MAXSIZE];
    int LTop, RTop;
} Stack;

void InitStack(Stack *S)
{
    S->LTop = -1;
    S->RTop = MAXSIZE;
}

void PushLeftStack(Stack *S, ElemType e)
{
    S->LTop++;
    S->data[S->LTop] = e;
}

void InputLeftStack(Stack *S)
{
    int n;
    ElemType t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        PushLeftStack(S, t);
    }
}

ElemType PopLeftStack(Stack *S)
{
    S->LTop--;
    return S->data[S->LTop + 1];
}

void PushRightStack(Stack *S, ElemType e)
{
    S->RTop--;
    S->data[S->RTop] = e;
}

void MoveToRightStack(Stack *S)
{
    ElemType t;
    while (S->LTop >= 0)
    {
        t = PopLeftStack(S);
        PushRightStack(S, t);
    }
}

void OutputRightStack(Stack *S)
{
    while (S->RTop != MAXSIZE)
    {
        printf("%d ", S->data[S->RTop]);
        S->RTop++;
    }
}

int main()
{
    Stack S;
    InitStack(&S);
    InputLeftStack(&S);
    MoveToRightStack(&S);
    OutputRightStack(&S);
    return 0;
}