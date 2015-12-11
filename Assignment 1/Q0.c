/* CS261- Assignment 1 - Q. 0*/
/* Name: Andrew M. Calhoun
 * Date: 10/1/2015
 * Solution description: A quickie review of pointers and addresses. We are given a basic function with a pointer as its argument,
    and are tasked with creating a simple int variable, outputting it's address, comparing it within foo, and then returning the pertinent
    information requested in the comments below.
 */

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 ** Function:         fooA(int* iptr)
 ** Description:      Tells the user the value of an integer, the address pointed to in memory, and the address of the ptr.
 ** Parameters:       int* iptr.
 ** Pre-Conditions:   A integer is initialized and defined.
 ** Post-Conditions:  Outputs the address of an integer, pointer, and pointed to address.
 *****************************************************************************/

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("Value of integer pointed at by iptr: %d\n\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr is: %p\n\n", iptr);

     /*Print the address of iptr itself*/
     printf("Address of iptr is: %p\n\n", &iptr);

}

/******************************************************************************
 ** Function:         main()
 ** Description:      The main function, calls the program functions.
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  None
 *****************************************************************************/

int main(){

    /*declare an integer x*/
    int x = 42;

    /*print the address of x*/
    printf("Address of x is: %p\n\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of X is: %d\n", x);

    return 0;
}
