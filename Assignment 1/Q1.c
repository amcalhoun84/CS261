/* CS261- Assignment 1 - Q.1*/
/* Name: Andrew M. Calhoun (calhouna)
 * Date: 10/1/2015
 * Solution description: Use of pointers to create a basic, randomized student id and score roster. It also uses for loops to populate
    the arrays and keep the members referenced to by the pointer. After the memory is allocated via a malloc, it is then passed on to be populated
    by a randomized array, which is then summed up, the min and max scores found, and an average is given. From there
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<time.h>

struct student{
	int id;
	int score;
};

/******************************************************************************
 ** Function:         struct student* allocate()
 ** Description:      Allocates memory for an array of struct student
 ** Parameters:       None.
 ** Pre-Conditions:   None.
 ** Post-Conditions:  Returns pointer to array and memory is allocated through malloc().
 *****************************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *stud = (struct student *) malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return stud;
}

/******************************************************************************
 ** Function:         void generate(struct student* students)
 ** Description:      Generates scores and IDs for students
 ** Parameters:       Pointer to students
 ** Pre-Conditions:   students are initialized.
 ** Post-Conditions:  arrays for students are populated with IDs and values for each student.
 *****************************************************************************/

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    unsigned int i, j;
    unsigned int unq = 0; // Unique ID Boolean

    students[0].id = rand () % 10 + 1; // Randomize the Student IDs as well. Create quickie algorithm to check uniqueness.
    students[0].score = ((rand () % 100) + 1);

    for(i=1; i < 10; i++)
    {

        while(unq == 0)
        {
            students[i].id = (rand() % 10) + 1; // Randomize the Student IDs as well. Create quickie algorithm to check uniqueness.

            for(j = 0; j < i; j++)
            {
                if(students[i].id == students[j].id)
                {
                    unq = 0;
                    break;
                }
                else
                {
                    unq = 1;
                }

            }
        }

        unq = 0;
        students[i].score = ((rand () % 100) + 1);
    }
}

/******************************************************************************
 ** Function:         void output(struct student* students)
 ** Description:      Produces outputs for student ids and scores.
 ** Parameters:       Pointer to students.
 ** Pre-Conditions:   Students are initialized and populated.
 ** Post-Conditions:  Prints out the list of students and their scores.
 *****************************************************************************/

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     unsigned int i;
     for(i = 0; i < 10; i++)
     {
         printf("ID: %d\n", students[i].id);
         printf("Score: %d\n", students[i].score);
     }

}

/******************************************************************************
 ** Function:         void summary(struct student* students)
 ** Description:      Summarizes the highest, lowest, and average score in the class.
 ** Parameters:       Pointer to students.
 ** Pre-Conditions:   Students are initialized and populated.
 ** Post-Conditions:  Returns the requested information, such as the average, min, and max scores.
 *****************************************************************************/

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

     int i, sum =0, min, max;
     float avg;

    for (i = 0; i < 10; i++)
    {

        sum += students[i].score;
    }

    avg = (sum/10);

    min = students[0].score;
    max = students[0].score;

    for (i=0; i<10; i++)
    {
        if(students[i].score < min)
        {
            min = students[i].score;
        }
    }

    for (i=0; i<10; i++)
    {
        if(students[i].score > max)
        {
            max = students[i].score;
        }

    }

    printf("The minimum score is: %d\n", min);
    printf("The maximum score is: %d\n", max);
    printf("The average score is: %g\n", avg);
}

/******************************************************************************
 ** Function:         void deallocate(struct student* students)
 ** Description:      Frees the memory from pointer students
 ** Parameters:       Pointer stud
 ** Pre-Conditions:   Students are initialized.
 ** Post-Conditions:  Memory from stud/students is freed.
 *****************************************************************************/

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

    assert(stud != NULL);   // Break off program if null, so we don't get a segmentation fault in freeing the memory.
    free(stud);
}

/******************************************************************************
 ** Function:         int main()
 ** Description:      The main function, runs through the program functions.
 ** Parameters:       None.
 ** Pre-Conditions:   N/A
 ** Post-Conditions:  N/A
 *****************************************************************************/

int main(){
    srand(time(NULL));  // Caused a warning, included <time.h> -- resolved issue on flip.
    //  struct student* stud = NULL;
    struct student* st = 0; // Instructions stated to use that.

    /*call allocate*/
    st = allocate();
    /*call generate*/
    generate(st);
    /*call output*/
    output(st);
    /*call summary*/
    summary(st);
    /*call deallocate*/
    deallocate(st);

    return 0;
}
