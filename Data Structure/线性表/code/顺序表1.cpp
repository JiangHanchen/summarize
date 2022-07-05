//使用顺序表完成冒泡排序
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct
{
    ElemType data[MAXSIZE]; //数据
    int tail;               //最后一个数据所在的下标，标示线性表长度
} SqList;

void InitSqList(SqList *L)
{
    L->tail = -1;
}

void InputData(SqList *L)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        L->tail++;
        scanf("%d", &L->data[L->tail]);
    }
}

void BubbleSort(SqList *L)
{
    bool IsChanged = 1; //剪枝。如果发现已经没有可以交换的，说明已经提前完成了排序
    for (int i = 0; i < L->tail && IsChanged == 1; i++)
    {
        IsChanged = 0;
        for (int j = 0; j < L->tail - i; j++)
        {
            if (L->data[j] > L->data[j + 1])
            {
                int t = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = t;
                IsChanged = 1;
            }
        }
    }
}

void OutputData(SqList L)
{
    for (int i = 0; i <= L.tail; i++)
    {
        printf("%d ", L.data[i]);
    }
}

int main()
{
    SqList L;
    InitSqList(&L);
    InputData(&L);
    BubbleSort(&L);
    OutputData(L);
    return 0;
}