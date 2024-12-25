// description: cn = an * bn

#include <stdio.h>

int main ()
{
    int a[10] = {0}, b[10]= {0}, c[10] = {0}; 
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt","r");
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);

    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];

    /* Original C code segment
    for (int i = 0; i < arr_size; i++){
        *p_c++ = *p_a++ * *p_b++;
    }
    */
    for (int i = 0; i < arr_size; i++)
        asm volatile(
            "mul %[a], %[e], %[f]\n\t"
            "add %[b], %[b], 4\n\t"
            "add %[c], %[c], 4\n\t"
            "add %[d], %[d], 4\n\t"
            :[a] "=r"(*p_c), [b] "+r"(p_a), [c] "+r"(p_b), [d] "+r"(p_c)
            :[e] "r"(*p_a), [f] "r"(*p_b)
        );


    p_c = &c[0];
    for (int i = 0; i < arr_size; i++)
        printf("%d ", *p_c++);

    return 0;
}
