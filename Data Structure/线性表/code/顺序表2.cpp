//使用顺序表完成快速排序
#include <bits/stdc++.h>
#define ElemType int
#define MAXSIZE 105
using namespace std;

typedef struct
{
    ElemType data[MAXSIZE]; //数据
    int tail;               //最后一个数据所在的下标，标示线性表长度
} SqList;

void InitList(SqList *L)
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

void QuickSort(SqList *L, int a, int b)
{
    if (a < b && a >= 0 && a <= L->tail && b >= 0 && b <= L->tail)
    {
        int t = L->data[a];
        int low = a, high = b;
        while (true)
        {
            while (L->data[high] >= t && high > low)
                high--;
            if (low == high)
                break;
            if (L->data[high] < t)
            {
                L->data[low] = L->data[high];
                low++;
            }
            if (low == high)
                break;

            while (L->data[low] < t && low < high)
                low++;
            if (low == high)
                break;
            if (L->data[low] >= t)
            {
                L->data[high] = L->data[low];
                high--;
            }
            if (low == high)
                break;
        }
        L->data[high] = t;
        QuickSort(L, a, high - 1);
        QuickSort(L, high + 1, b);
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
    InitList(&L);
    InputData(&L);
    QuickSort(&L, 0, L.tail);
    OutputData(L);
    return 0;
}