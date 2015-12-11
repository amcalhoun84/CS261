/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *stud = malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return stud;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    for(unsigned int i=0; i < 10; i++)
    {
        students[i].id = i;
        students[i].score = ((rand () % 100) + 1);
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

     for(unsigned int i = 0; i < 10; i++)
     {
         printf("ID: %d\n", students[i].id);
         printf("Score: %d\n", students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/

    /*call deallocate*/

    return 0;
}
