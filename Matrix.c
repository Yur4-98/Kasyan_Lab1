#include <stdio.h>

#include "complex.h"

enum M_type
{
    F,
    C
};

struct Matrix {
    int lines;
    int columns;
    void ***start;
    enum M_type type;
    int size;
};



void* sum(void *x, void *y,enum M_type type) {
    void* res = NULL;
    switch (type)
    {
    case F:
        (float*)res = (void*)malloc(sizeof(float));
        *(float*)res = ((*(float*)x + *(float*)y));
        break;
    case C:
        (struct Complex*)res = sum_c((struct Complex*)x, (struct Complex*)y);
        break;
    default:
        /*может приготится для ошибок*/
        break;
    }

    return (void*)res;
}

void* mult(void *x, void* y, enum M_type type) {
    void* res = NULL;
    switch (type)
    {
    case F:
        res = (void*)malloc(sizeof(float));
        *(float*)res = ((*(float*)x * *(float*)y));
        break;
    case C:
        //res = (struct Complex*)malloc(sizeof(struct Complex));
        (struct Complex*)res = mult_c((struct Complex*)x, (struct Complex*)y);
        break;
    default:
        /*может приготится для ошибок*/
        break;
    }

    return (void*)res;
}

void* Zero(enum M_type type) {
    void* zero = NULL;
    switch (type)
    {
    case F:
        (float*)zero = malloc(sizeof(float));
        *(float*)zero = 0;
        break;
    case C:
        
        (struct Complex*)zero = Zero_C();
        break;
    default:
        break;
    }
    return (void*)zero;
}

struct Matrix* Zero_M(int zero_lines, int zero_columns, int zero_size, enum M_type zero_type) {
     struct Matrix *zero = malloc(sizeof(struct Matrix));

     zero->lines = zero_lines;
     zero->columns = zero_columns;
     zero->size = zero_size;
     zero->start = malloc(zero_lines * sizeof(void*));
     zero->type = zero_type;
     for (int i = 0; i < zero_lines; i++)
     {
         (zero->start[i]) = malloc(zero_columns * sizeof(void*));
     }
     for (int i = 0; i < zero_lines; i++)
     {
         for (int j = 0; j < zero_columns; j++)
         {
             zero->start[i][j] = Zero(zero->type);
         }
     }
     return zero;
}

void* input_el( enum M_type type)
{
    void* res = NULL;
    switch (type)
    {
    case F:
        (float*)res = malloc(sizeof(float));
        scanf("%f", (float*)res);

        break;
    case C:
        (struct Complex*)res = input_C();//

        break;
    default:
        break;
    }
    return (void*)res;
}

struct Matrix* input_M() {
    int lines = 0, columns = 0, size = 0;

    printf("Enter number of lines\n");
    scanf("%d",&lines);

    printf("Enter number of columns\n");
    scanf("%d",&columns);

    int ntype = 0;
    printf("Enter type of element:\n1 - float\n2 - complex\n");
    scanf("%d", &ntype);
    enum M_type type = F;
    switch (ntype)
    {
    case 1:
        type = F;
        size = sizeof(float);
        break;
    case 2:
        type = C;
        size = sizeof(struct Complex);
        break;
    default:
        break;
    }

    struct Matrix* res = Zero_M(lines, columns, size, type);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            free(res->start[i][j]);
            res->start[i][j] = input_el(res->type);
        }
    }

    return res;
}

void output_el(void *element, enum M_type type) {
    switch (type)
    {
    case F:
        printf("%f",*(float*)element);
        break;
    case C:
        output_C((struct Complex*)element);
        break;
    default:
        break;
    }
}

void output_M(struct Matrix *M) {
    if (!M) {
        printf("No matrix\n");
        return;
    }
    for (int i = 0; i < M->lines; i++)
    {
        for (int j = 0; j < M->columns; j++)
        {
            output_el(M->start[i][j],M->type);
            printf(" ");
        }
        printf("\n");
    }
}



void free_M(struct Matrix* M){
    if (!M) {
        return;
    }
    for (int i = 0; i < M->lines; i++)
    {
        for (int j = 0; j < M->columns; j++)
        {
            free(M->start[i][j], M->type);
        }
        free(M->start[i]);
    }
    free(M->start);
    free(M);
}



struct Matrix* sum_m(struct Matrix *M1, struct Matrix *M2) {
 //   struct Matrix* res = malloc(sizeof(struct Matrix));

    if (!M1 || !M2 || M1->lines != M2->lines || M1->columns != M2->columns || M1->type != M2->type)
    {
        printf("Error of sum_m");
        return M1;// доделать обработку ошибок
    }
    struct Matrix* res = Zero_M(M1->lines, M1->columns, M1->size, M1->type);


    for (int i = 0; i < res->lines; i++)
    {
        for (int j = 0; j < res->columns; j++)
        {
            free(res->start[i][j]);
            res->start[i][j] = sum(M1->start[i][j], M2->start[i][j], M1->type);
        }

    }

    return res;
}

struct Matrix* mult_m(struct Matrix* M1, struct Matrix* M2) {

    
    if (!M1 || !M2 || M1->columns != M2->lines || M1->type != M2->type)
    {
        printf("Error of mult_m");
        return M1;
    }
    struct Matrix* res = Zero_M(M1->lines, M2->columns, M1->size, M1->type);
    void* tmp_m = NULL, *tmp_s = NULL;

    for (int i = 0; i < res->lines; i++)
    {
        for (int j = 0; j < res->columns; j++)
        {
            for (int k = 0; k < M1->columns; k++)
            {
                
                tmp_m = mult(M1->start[i][k], M2->start[k][j], res->type);
                tmp_s = sum(res->start[i][j], tmp_m,res->type);
                free(tmp_m);
                free(res->start[i][j]);
                res->start[i][j] = tmp_s;
            }
        }
    }
    return res;
}

struct Matrix* transposition(struct Matrix* M)
{
    if (!M) {
        printf("Error of transposition");
        return M;
    }
    struct Matrix *res = Zero_M(M->columns, M->lines, M->size, M->type);  
    for (int i = 0; i < M->lines; i++)
    {
        for (int j = 0; j < M->columns; j++)
        {
            for (int k = 0; k < M->size; k++) {
                *((char*)(res->start[j][i]) + k) = *((char*)(M->start[i][j]) + k);
            }
        }
    }

    return res;
}