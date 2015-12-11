/* CS261- Assignment 1 - Q.3*/
/* Name: Andrew M. Calhoun
 * Date: 10/2/2015
 * Solution description: Uses pointers to allocate memory for a randomized array, then
 	the array in ascending order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************************************************************
 ** Function:         void sort(int* number, int n)
 ** Description:      A function which uses a sort to re-arrange numbers in their proper order.
 ** Parameters:       int* number, int n.
 ** Pre-Conditions:   A number array is pointed to and n are both initialized.
 ** Post-Conditions:  Sets an ordered array into memory.
 *****************************************************************************/
void sort(int* number, int n){

     int i, j, swap;

     if(n == 0) return;

     for(i = 0; i < n; i++)
     {
     	for(j = 0; j < n; j++)
     	{
     		if(number[j] > number[j+1])
     		{
     			swap = number[j];
     			number[j] = number[j+1];
     			number[j+1] = swap;
     		}
     	}
     }
}

/******************************************************************************
 ** Function:         int main()
 ** Description:      The main function, generates the array and passes it to the program sort() function.
 ** Parameters:       None
 ** Pre-Conditions:   None
 ** Post-Conditions:  None
 *****************************************************************************/
int main(){

	srand(time(NULL));

    /*Declare an integer n and assign it a value of 20.*/
    unsigned int n = 20, i;

    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i < n; i++)
    {
    	array[i] = ((rand() % 100) + 1);
    }

    /*Print the contents of the array.*/
    printf("Array of Numbers: \n\n");

    for(i = 0; i < n; i++)
    {
    	printf("%d\n", array[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the contents of the array.*/

    printf("Sorted Array: \n\n");

    for(i = 0; i < n; i++)
    {
    	printf("%d\n", array[i]);
    }

    return 0;
}
