//递归方法解决汉诺塔问题
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct Stack
{
    ElemType data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack *S)
{
    S->top = -1; //空栈
}

void PushStack(Stack *S, ElemType e)
{
    S->top++;
    S->data[S->top] = e;
}

ElemType PopStack(Stack *S)
{
    ElemType r = S->data[S->top];
    S->top--;
    return r;
}

void InputStack(Stack *S, int n)
{
    for (int i = n; i >= 1; i--)
    {
        PushStack(S, i);
    }
}

void Move(Stack *Init, Stack *Target)
{
    int r = PopStack(Init);
    PushStack(Target, r);
}

void Hanoi(int n, Stack *Init, Stack *Target, Stack *Support)
{
    if (n == 1)
    {
        Move(Init, Target);
    }
    else
    {
        Hanoi(n - 1, Init, Support, Target);
        Move(Init, Target);
        Hanoi(n - 1, Support, Target, Init);
    }
}

void PrintStack(Stack *S)
{
    while (S->top >= 0)
    {
        printf("%d ", S->data[S->top]);
        S->top--;
    }
}

int main()
{
    Stack X, Y, Z;
    InitStack(&X);
    InitStack(&Y);
    InitStack(&Z);
    int n;
    scanf("%d", &n);
    InputStack(&X, n);
    Hanoi(n, &X, &Z, &Y); //从X移动到Z,Y作辅助塔
    PrintStack(&Z);
}