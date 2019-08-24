#ifndef __MATRIX__
#define __MATRIX__
#include <stdio.h>

#ifdef ARRAUSIZE
#define ARRAYSIZE(a, b) ((int) (sizeof(a) / sizeof(b)))
#endif

int matrix1[2][3] = {{2, 4, 6}, {3, 6, 9}};
int matrix2[3][1] = {{1}, {3}, {5}};
int iResult[2] = {0};


// 2 x 3 * 3 x 1
void Multiply(int iResult[2], int iMatrix1[2][3], int iMatrix2[3][1], int iMatrixCols1, int iMatrixRows1, int iMatrixCols2, int iMatrixRows2);
// 2 x 3 * 3 x 2
void MULTIPLY(int iResult[2][2], int iMatrix1[2][3], int iMatrix2[3][2], int iMatrixCols1, int iMatrixRows1, int iMatrixCols2, int iMatrixRows2);

// column：列; row：行
void Multiply(int iResult[2], int iMatrix1[][3], int iMatrix2[3][1], int iMatrixCols1, int iMatrixRows1, int iMatrixCols2, int iMatrixRows2)
{
    int itpResult = 0;
    if (iMatrixCols1 != iMatrixRows2)
    {
        printf(" 第一个矩阵的列必须与第二个矩阵的行相同!");
        return;
    }
    if (iMatrixCols2 != 1)
    {
        printf("第二个矩阵不能是两列");
        return;
    }

    for (int rows = 0; rows < iMatrixRows1; rows++)
    {
        for (int cols = 0; cols < iMatrixCols1; cols++)
        {
            itpResult += iMatrix1[rows][cols] * iMatrix2[cols][0]; 
        }
        iResult[rows] = itpResult;
        itpResult = 0;
    }

    for (int rows1 = 0; rows1 < iMatrixRows1; rows1++)
    {
        for (int rows2 = 0; rows2 < iMatrixRows2; rows2++)
        {
            for (int cols1 = 0; cols1 < iMatrixCols1; cols1++)
            {
                itpResult += iMatrix1[rows1][cols1] * iMatrix2[cols1][rows2]; 
            }
            iResult[rows1] = itpResult;
            itpResult = 0;
        }        
    }
}

void MULTIPLY(int iResult[2][2], int iMatrix1[][3], int iMatrix2[3][2], int iMatrixCols1, int iMatrixRows1, int iMatrixCols2, int iMatrixRows2)
{
    int itpResult = 0;
    if (iMatrixCols1 != iMatrixRows2)
    {
        printf(" 第一个矩阵的列必须与第二个矩阵的行相同!");
        return;
    }
    for (int rows1 = 0; rows1 < iMatrixRows1; rows1++)
    {
        for (int rows2 = 0; rows2 < iMatrixRows2; rows2++)
        {
            for (int cols1 = 0; cols1 < iMatrixCols1; cols1++)
            {
                itpResult += iMatrix1[rows1][cols1] * iMatrix2[cols1][rows2]; 
            }
            iResult[rows1][rows2] = itpResult;
            itpResult = 0;    
        }
        itpResult = 0;
    }
}
#endif