#include <stdio.h>

#include <stdlib.h>

#include "matrix.h"
#include "complex.h"

// проверка утечек памяти
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
//

void test_float()
{
    printf("float\n");
    struct Matrix* m1 = NULL, * m2 = NULL, * m3 = NULL, *m4 = NULL;
    m1 = Zero_M(2,3,sizeof(float),F);
    for (int i = 0; i < m1->lines; i++)
    {
        for (int j = 0; j < m1->columns; j++)
        {
            *(float*)(m1->start[i][j]) = 2;
        }
    }
    m2 = Zero_M(2,3,sizeof(float), F);
    for (int i = 0; i < m2->lines; i++)
    {
        for (int j = 0; j < m2->columns; j++)
        {
            *(float*)(m2->start[i][j]) = 5;
        }
    }
    printf("matrix1\n");
    output_M(m1);
    printf("matrix2\n");
    output_M(m2);
    
    printf("sum\n");

    m3 = Zero_M(2, 3, sizeof(float), F);
    for (int i = 0; i < m3->lines; i++)
    {
        for (int j = 0; j < m3->columns; j++)
        {
            *(float*)(m3->start[i][j]) = 5;
        }
    }
    printf("expected result of sum\n");
    output_M(m3);
    free_M(m3);
    printf("received result of sum\n");
    m3 = sum_m(m1, m2);
    output_M(m3);
    free_M(m3);
    
    printf("transposition m2->m4\n");

    m4 = Zero_M(3, 2, sizeof(float), F);
    for (int i = 0; i < m4->lines; i++)
    {
        for (int j = 0; j < m4->columns; j++)
        {
            *(float*)(m4->start[i][j]) = 7;
        }
    }
    printf("expected result of transposition\n");
    output_M(m4);
    free_M(m4);
    printf("received result of transposition\n");
    m4 = transposition(m2);
    output_M(m4);
    free_M(m4);
    
    printf("mult m1 * transp(m2)\n");

    m4 = transposition(m2);
    m3 = Zero_M(2, 2, sizeof(float), F);
    for (int i = 0; i < m3->lines; i++)
    {
        for (int j = 0; j < m3->columns; j++)
        {
            *(float*)(m3->start[i][j]) = 30;
        }
    }
    printf("expected result of mult\n");
    output_M(m3);
    free_M(m3);
    
    printf("received result of mult\n");
    m3 = mult_m(m1, m4);
    output_M(m3);
    free_M(m3);
    
    free_M(m4);
    
    free_M(m1);
    free_M(m2);
}


void test_complex()
{
    printf("complex\n");
    struct Matrix* m1 = NULL, * m2 = NULL, * m3 = NULL, * m4 = NULL;
    m1 = Zero_M(2, 3, sizeof(struct Complex), C);
    for (int i = 0; i < m1->lines; i++)
    {
        for (int j = 0; j < m1->columns; j++)
        {
            ((struct Complex*)(m1->start[i][j]))->Re = 2;
            ((struct Complex*)(m1->start[i][j]))->Im = 2;
        }
    }
    m2 = Zero_M(2, 3, sizeof(struct Complex), C);
    for (int i = 0; i < m2->lines; i++)
    {
        for (int j = 0; j < m2->columns; j++)
        {
            ((struct Complex*)(m2->start[i][j]))->Re = 2;
            ((struct Complex*)(m2->start[i][j]))->Im = 2;
        }
    }
    printf("matrix1\n");
    output_M(m1);
    printf("matrix2\n");
    output_M(m2);

    printf("sum\n");

    m3 = Zero_M(2, 3, sizeof(struct Complex), C);
    for (int i = 0; i < m3->lines; i++)
    {
        for (int j = 0; j < m3->columns; j++)
        {
            ((struct Complex*)(m3->start[i][j]))->Re = 4;
            ((struct Complex*)(m3->start[i][j]))->Im = 4;
        }
    }
    printf("expected result of sum\n");
    output_M(m3);
    free_M(m3);
    printf("received result of sum\n");
    m3 = sum_m(m1, m2);
    output_M(m3);
    free_M(m3);

    printf("transposition m2->m4\n");
    
    m4 = Zero_M(3, 2, sizeof(struct Complex), C);
    for (int i = 0; i < m4->lines; i++)
    {
        for (int j = 0; j < m4->columns; j++)
        {
            ((struct Complex*)(m4->start[i][j]))->Re = 2;
            ((struct Complex*)(m4->start[i][j]))->Im = 2;
        }
    }
    printf("expected result of transposition\n");
    output_M(m4);
    free_M(m4);
    
    printf("received result of transposition\n");
    m4 = transposition(m2);
    output_M(m4);
    free_M(m4);
    
    printf("mult m1 * transp(m2)\n");
    
    m4 = transposition(m2);
    m3 = Zero_M(2, 2, sizeof(struct Complex), C);
    for (int i = 0; i < m3->lines; i++)
    {
        for (int j = 0; j < m3->columns; j++)
        {
            ((struct Complex*)(m3->start[i][j]))->Re = 0;
            ((struct Complex*)(m3->start[i][j]))->Im = 24;
        }
    }
    printf("expected result of mult\n");
    output_M(m3);
    free_M(m3);
    
    printf("received result of mult\n");
    m3 = mult_m(m1, m4);
    output_M(m3);
    free_M(m3);
    
    free_M(m4);
    
    free_M(m1);
    free_M(m2);
}
