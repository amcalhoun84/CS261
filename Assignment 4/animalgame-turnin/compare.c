/*/* Andrew M. Calhoun, calhouna@oregonstate.edu
   Date: 11/5/2015
 File: compare.c
 Implementation of the binary search tree data comparison
 */


#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    struct data *lVal = (struct data *) left;
    struct data *rVal = (struct data *) right;

    if(lVal->number <  rVal->number)
    {
        return -1;
    }
    else if(lVal->number > rVal->number)
    {
        return 1;
    }

	else
    {
        return 0;
    }


}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
   struct data *temp = (struct data *) curval;

   printf("%d", temp->number);

}

void animal_type(TYPE curval)
{
    struct data *animName = (struct data *) curval;
    printf("%s\n", animName->name);

}

// Find the height of a node.
int nodeHeight(TYPE curval)
{
    struct data *height = (struct data*)curval;
    return height->number;

}


