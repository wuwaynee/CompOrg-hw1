// description: matrix muliply with two-level for loop

#include<stdio.h>

int main()
{ 
    int f,i=0;
    int h[9]={0}, x[3]={0}, y[3]={0}; 
    FILE *input = fopen("../input/3.txt","r");

    for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);

    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
 
    for (i = 0 ; i < 3; i++)
    { 
 
        p_x = &x[0] ; 

        for (f = 0 ; f < 3; f++) {
    /*  for debug:
        printf("x %p %d\n", p_x, *p_x);
		printf("h %p %d\n", p_h, *p_h);
		printf("y %p %d\n", p_y, *p_y);     */

            asm volatile(
            // temp = *p_h * *p_x;
                "mul t0, %[d], %[e]\n\t"

            // *p_y = *p_y + temp;
                "add %[a], %[a], t0\n\t"

            // p_h++;
                "addi %[b], %[b], 4\n\t"

            // p_x++;
                "addi %[c], %[c], 4\n\t"
                
                :[a] "+r"(*(y+i)), [b] "+r"(p_h), [c] "+r"(p_x)
                :[d] "r"(*p_h), [e] "r"(*p_x)
            );
    /*  for debug:  printf("y %p %d\n",p_y, *p_y);    */
		
	    }
    }

    p_y = &y[0];
    for(i = 0; i<3; i++)
        printf("%d \n", *p_y++);


    return(0) ; 

 
}
