#include <time.h>
#include <stdlib.h>
struct Complex {
    float Re;
    float Im;
};



struct Complex *Zero_C() {
    struct Complex* the_zero = malloc(sizeof(struct Complex));
    the_zero->Re = 0;
    the_zero->Im = 0;
    return the_zero;
}


struct Complex *input_C() {
    struct Complex* res = malloc(sizeof(struct Complex));
    printf("");
    scanf("%f",&(res->Re));
    scanf("%f",&(res->Im));
    return res;
}

struct Complex* random_C() {
    struct Complex* res = malloc(sizeof(struct Complex));
    srand((unsigned int)time(NULL));
    res->Re = ((float)rand() / (float)(10.0));
    res->Im = ((float)rand() / (float)(10.0));
    return res;
}

void output_C(struct Complex *c) {
    printf("%f + i*%f", c->Re, c->Im);
}

float GetRe(struct Complex c) {
    return c.Re;
}

float GetIm(struct Complex c) {
    return c.Im;
}


struct Complex *sum_c(struct Complex *c1, struct Complex *c2) {
    struct Complex *res = malloc(sizeof(struct Complex));

    res->Re = c1->Re + c2->Re;
    res->Im = c1->Im + c2->Im;
    return res;
}

struct Complex *mult_c(struct Complex *c1, struct Complex *c2) {
    struct Complex* res = malloc(sizeof(struct Complex));
    res->Re = c1->Re * c2->Re - c1->Im * c2->Im;
    res->Im = c1->Re * c2->Im + c1->Im * c2->Re;
    return res;
}
