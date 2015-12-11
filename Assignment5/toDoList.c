/*	toDoList.c: To Do List implementation. */
/* Andrew M. Calhoun (calhouna)
 * EMAIL: calhouna@oregonstate.edu
 * Date: 11/20/2015
 * Filename: toDoList.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"



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

  struct Task * leftTask = left;
  struct Task * rightTask = right;

   if(leftTask->priority < rightTask->priority)
   {
      return -1;
   }
   else if(leftTask->priority > rightTask->priority)
   {
      return 1;
   }
   else
   {
    return 0;
   }


}

/***************************************************************
Print type function defined by user to print their specific type
****************************************************************/


void print_type(TYPE val)
{
  struct Task *v = (struct Task*) val;

  printf("Task: %s  Priority: %d\n", v->description, v->priority);
}




/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TaskP createTask (int priority, char *desc)
{
  /*FIXME: Write this */
  struct Task* newTask = malloc(sizeof(struct Task));

  strcpy(newTask->description, desc);
  newTask->priority = priority;

  return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the
			task priority, followed by a tab character (\t), and
			the task description.

			The tasks are not necessarily stored in the file in
			priority order.

*/
void saveList(DynArr *heap, FILE *filePtr)
{
  assert(sizeDynArr(heap) > 0);

  int i;
	TaskP task;
	assert(sizeDynArr(heap) > 0);
	for(i = 0; i < sizeDynArr(heap); i++)
	{
	  task = getDynArr(heap, i);
	  fprintf(filePtr, "%d\t%s\n", task->priority, task->description);
	}
}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file
*/
void loadList(DynArr *heap, FILE *filePtr)
{
  TaskP task;
  char line[100];  /* Assume lines < 100 */
  char desc[TASK_DESC_SIZE];
  int priority;

  /* Read the priority first, then the description.
   * fgets() is used to read string with spaces
   */

  while(fgets(line, sizeof(line), filePtr) != 0)
    {
      sscanf(line, "%d\t%[^\n]", &priority, desc);
      task = createTask(priority, desc);
      addHeap(heap, task, compare);
    } /* should use feof to make sure it found eof and not error*/

}

/*  Print the list in priority order.  This requires that either we sort it...or make a copy and pull
off the smallest element one at a time.  That's what we've done here.

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{

  assert(sizeDynArr > 0);
  DynArr *temp;
  TaskP task;
  assert(sizeDynArr(heap) > 0);

  temp = createDynArr(sizeDynArr(heap));
  /* copy the main list to a temp list
   * so that tasks can be printed out and removed.
   */
  copyDynArr(heap, temp);
  while(sizeDynArr(temp) > 0)
    {
      /* get the task */
      task = getMinHeap(temp);

      /* print the task */
      printf("%d:  %s\n\n", task->priority, task->description);
      /* remove the task , but let's not free up the memory it's pointing to since old Arr is using it!*/
      removeMinHeap(temp, compare);
    }
  /* free the temp list */
  deleteDynArr(temp);
}
