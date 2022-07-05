//使用三元组完成对矩阵的一次定位快速转置
//思路：找到待转置矩阵A中每一列第一个非零元素在转置后矩阵B中的位置.
//方法:定义pos[]记录位置，定义num[]记录每一个A列号含有的非零元素个数
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

void InitMatrixA(Matrix *A)
{
    scanf("%d%d%d", &A->r, &A->c, &A->t);
}   

void InitMatrixB(Matrix *A, Matrix *B)
{
    B->r = A->c;
    B->c = A->r;
    B->t = A->t;
}

void CreateMatrix(Matrix *A)
{
    for(int i = 1; i <= A->t; i++)
    {
        scanf("%d%d%d", &A->data[i].x, &A->data[i].y, &A->data[i].e);
    }
}

void PreProcess(Matrix *A, int* pos, int* num)
{
    for(int i = 1; i <= A->t; i++)
    {
        num[A->data[i].y]++;
    }
    pos[1] = 1;
    for(int i = 2; i <= A->c; i++)
    {
        pos[i] = pos[i - 1] + num[i - 1];
    }
}

void TransposeMatrix(Matrix *A, Matrix *B, int* pos)
{
    for(int i = 1; i <= A->t; i++)
    {
        B->data[pos[A->data[i].y]].x = A->data[i].y;
        B->data[pos[A->data[i].y]].y = A->data[i].x;
        B->data[pos[A->data[i].y]].e = A->data[i].e;
        pos[A->data[i].y]++;
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
    Matrix A, B;
    InitMatrixA(&A);
    InitMatrixB(&A, &B);
    CreateMatrix(&A);
    int pos[MAXSIZE] = {0}, num[MAXSIZE] = {0};
    PreProcess(&A, pos, num);
    TransposeMatrix(&A, &B, pos);
    PrintMatrix(&B);
    return 0;
}