#ifndef MATRIX.H
//#define MATRIX.H

//struct Matrix;
enum M_type
{
    F,
    C
};

struct Matrix {
    int lines;
    int columns;
    void*** start;
    enum M_type type;
    int size;
};

//void* sum(void* x, void* y, enum M_type type);
//void* mult(void* x, void* y, enum M_type type);
//void* Zero(enum M_type type);
struct Matrix* Zero_M(int zero_lines, int zero_columns, int zero_size, enum M_type zero_type);
//void* input_el( enum M_type type);
struct Matrix* input_M();
//void output_el(void* element, enum M_type type);
void output_M(struct Matrix* M);
void free_M(struct Matrix* M);
struct Matrix* sum_m(struct Matrix* M1, struct Matrix* M2);
struct Matrix* mult_m(struct Matrix* M1, struct Matrix* M2);
struct Matrix* transposition(struct Matrix* M);


#endif