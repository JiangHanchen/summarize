//使用三元组完成对矩阵的转置
#include <bits/stdc++.h>
#define MAXSIZE 300
#define ElemType int
using namespace std;

typedef struct triple
{
    int x, y;
    ElemType e;
}triple;

typedef struct Matrix
{
    triple data[MAXSIZE];
    int r, c, t;//矩阵行数，列数，非零元素个数
}Matrix;

void InitMatrix(Matrix *M)
{
    M->t = 0;
}

void CreateMatrix(Matrix *M)
{
    scanf("%d%d%d", &M->r, &M->c, &M->t);
    for(int i = 1; i <= M->t; i++)
    {
        scanf("%d%d%d", &M->data[i].x, &M->data[i].y, &M->data[i].e);
    }
}

void TransposeMatrix(Matrix *M, Matrix *N)
{
    for(int i = 1; i <= M->c; i++)
    {
        for(int j = 1; j <= M->t; j++)
        {
            if(M->data[j].y == i)
            {
                N->t++;
                N->data[N->t].x = M->data[j].y;
                N->data[N->t].y = M->data[j].x;
                N->data[N->t].e = M->data[j].e;
            }
        }
    }
}

void PrintMatrix(Matrix *M)
{
    for(int i = 1; i <= M->t; i++)
    {
        printf("%d %d %d\n", M->data[i].x, M->data[i].y, M->data[i].e);
    }
}

int main()
{
    Matrix M;
    InitMatrix(&M);
    CreateMatrix(&M);
    Matrix N;
    N.c = M.r;
    N.r = M.c;
    N.t = 0;
    TransposeMatrix(&M, &N);
    PrintMatrix(&N);
    return 0;
}