#ifndef __TODOLIST_H
#define __TODOLIST_H

#include "dynamicArray.h"

#define TASK_DESC_SIZE 128

struct Task {
	char description[TASK_DESC_SIZE];  	/* description of the task */
	int priority;			  			/* task priority */
};

typedef  struct Task* TaskP;


TaskP createTask (int priority, char *desc);

void saveList(DynArr *heap, FILE *filePtr);

void loadList(DynArr *heap, FILE *filePtr);

void printList(DynArr *heap);

int compare (TYPE left, TYPE right);

void print_type(TYPE value);

#endif
