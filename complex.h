
#ifndef COMPLEX.H
//#define COMPLEX.H
struct Complex {
    float Re;
    float Im;
};
//struct Complex;
/*
Complex;
*/
struct Complex* input_C();
struct Complex* random_C();
void output_C(struct Complex* c);
struct Complex* Zero_C();
float GetRe(struct Complex c);
float GetIm(struct Complex c);
struct Complex* sum_c(struct Complex* c1, struct Complex* c2);
struct Complex* mult_c(struct Complex* c1, struct Complex* c2);
#endif