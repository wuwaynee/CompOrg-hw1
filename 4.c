// description: matrix muliply without for loop

#include<stdio.h>

int main()
{ 
    int i=0;
    int h[9]={0}, x[3]={0}, y[3]={0}; 
    FILE *input = fopen("../input/4.txt","r");

    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);

    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;

    asm volatile(
        "mul %[p], %[d], %[e]\n\t"
        "add %[a], %[a], %[p]\n\t"
        "mul %[p], %[f], %[g]\n\t"
        "add %[a], %[a], %[p]\n\t"
        "mul %[p], %[h], %[i]\n\t"
        "add %[a], %[a], %[p]\n\t"

        "mul %[p], %[j], %[e]\n\t"
        "add %[b], %[b], %[p]\n\t"
        "mul %[p], %[k], %[g]\n\t"
        "add %[b], %[b], %[p]\n\t"
        "mul %[p], %[l], %[i]\n\t"
        "add %[b], %[b], %[p]\n\t"

        "mul %[p], %[m], %[e]\n\t"
        "add %[c], %[c], %[p]\n\t"
        "mul %[p], %[n], %[g]\n\t"
        "add %[c], %[c], %[p]\n\t"
        "mul %[p], %[o], %[i]\n\t"
        "add %[c], %[c], %[p]\n\t"
        :[a]"+r"(*y), [b]"+r"(*(y+1)), [c]"+r"(*(y+2)), [p]"+r"(i)
        :[d]"r"(*h), [e]"r"(*x), [f]"r"(*(h+1)), [g]"r"(*(x+1)), [h]"r"(*(h+2)), [i]"r"(*(x+2)), [j]"r"(*(h+3)), [k]"r"(*(h+4)), [l]"r"(*(h+5)), [m]"r"(*(h+6)), [n]"r"(*(h+7)), [o]"r"(*(h+8))
    );


    p_y = &y[0];
    for(i = 0; i<3; i++)
        printf("%d \n", *p_y++);


    return(0) ; 
 
}