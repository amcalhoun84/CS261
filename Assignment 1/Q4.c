/* CS261- Assignment 1 - Q.4*/
/* Name: Andrew M. Calhoun
 * Date: 10/2/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};


/******************************************************************************
 ** Function:         void sort(int* number, int n)
 ** Description:      A function which uses a sort to re-arrange students in order of test scores.
 ** Parameters:       int* number, int n.
 ** Pre-Conditions:   A student array is pointed to and n are both initialized.
 ** Post-Conditions:  Sets an ordered array into memory.
 *****************************************************************************/
void sort(struct student* students, int n){

    int i, j;
    struct student swap;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(students[j+1].score < students[j].score)
            {
                swap = students[j];
                students[j] = students[j+1];
                students[j+1] = swap;
            }
        }
    }

}

int main(){
    /*Declare an integer n and assign it a value.*/
    unsigned int n = 10, i;
    srand(time(NULL));

    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    for(i = 0; i < n; i++)
    {
        students[i].id = ((rand() % n) + 1);    // Will be repeats, but assume all are unique.
    }

    for(i = 0; i < n; i++)
    {
        students[i].score = ((rand () % 100) + 1);
    }

    /*Print the contents of the array of n students.*/
    printf("Students and Score: \n\n");
    for(i = 0; i < n; i++)
    {
        printf("Student ID: %d\n", students[i].id);
        printf("Student Score: %d\n", students[i].score);

    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    printf("Students and Scores: (Ascending Order)\n\n");
    for(i = 0; i < n; i++)
    {
        printf("Student ID: %d\n", students[i].id);
        printf("Student Score: %d\n", students[i].score);

    }

    return 0;
}
