/* CS261- Assignment 1 - Q.2*/
/* Name: Andrew M. Calhoun
 * Date: 10/1/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 ** Function:         int foo(int* a, int* b, int c)
 ** Description:      Takes the pointer value of a and b and performs arithmetic on them.
                        Returns the added sum of *a and *b via c.
 ** Parameters:       int* a, int* b, int c.
 ** Pre-Conditions:   a, b, and c are initialized and defined.
 ** Post-Conditions:  Returns c, which remains 7 as there is no pointer
 *****************************************************************************/

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;

}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5,
        y = 6,
        z = 7;

    /*Print the values of x, y and z*/
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);
    printf("The value of z is: %d\n", z);


    /*Call foo() appropriately, passing x,y,z as parameters*/
    int output = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("Value returned by foo(): %d\n", output);

    /*Print the values of x, y and z again*/
    printf("The value of x is now: %d\n", x);
    printf("The value of y is now: %d\n", y);
    printf("The value of z is now: %d\n", z);

    /*Is the return value different than the value of z?  Why?*/
    /* Yes, because it takes the combined sum of the dereferenced pointer of a and b, which then is saved into memory as the results seen in
    the output. So, after the calling of foo, x = 10, y = 3, and z remains 7, because we do not call it by its address or use a pointer for it,
    so its original assignment does not change in memory, even though the output gives us the sum of the altered numbers and z remains the same
    as it does not become a pointer in foo(). */

    return 0;
}


