/*	main.c: Dynamic Array implementation. */
/* Andrew M. Calhoun (calhouna)
 * EMAIL: calhouna@oregonstate.edu
 * Date: 11/20/2015
 * Filename: main.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{

  struct Task *newTask;
  struct Task *firstTask;
  char cmd = ' ';
  char desc[TASK_DESC_SIZE], filename[50], *nullptr;
  DynArr* mainList = createDynArr(10);
  FILE *filePointer;
  int priority; //priority

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      switch(cmd)
      {

        case 'l': /* Loads the List */
            printf("Please enter the filename: ");
            if(fgets(filename, sizeof(filename), stdin) != NULL)
            {
              nullptr = strchr(filename, '\n');
              if(nullptr) *nullptr = '\0';
            }

            filePointer = fopen(filename, "r");
            if(filePointer == NULL)
            {
              printf("Cannot open %s\n", filename);
              break;
            }

            loadList(mainList, filePointer); // load the list from the file
            printf("The list has been loaded from file successfully.\n\n");

            fclose(filePointer); // close the file to prevent accidental overwrite
            break;


        case 's': /* Saves the list */
          if(sizeDynArr(mainList) > 0)
          {
              printf("Please enter the filename: ");
              if(fgets(filename, sizeof(filename), stdin) != NULL)
              {
                nullptr = strchr(filename, '\n');
                if(nullptr) *nullptr = '\0';
              }

          filePointer = fopen(filename, "w");
          if(filePointer == NULL)
          {
            printf("Cannot open %s\n", filename);
            break;

          }

          saveList(mainList, filePointer);
          printf("The list has been saved into the file successfully.\n\n");
          fclose(filePointer);

         }

          else
          {
            printf("Your to-do list is empty!\n\n");
          }
        break;

        case 'a': /* Adds a new task */
          printf("Please enter the task description: ");
          if(fgets(desc, sizeof(desc), stdin) != NULL);
          {
            nullptr = strchr(desc, '\n');
            if(nullptr) *nullptr = '\0';

          }
          do {
              printf("Please enter task priority (0-999): ");
              scanf("%d", &priority);


          } while(!(priority >= 0 && priority <= 999));

            while(getchar() != '\n');
            newTask = createTask(priority, desc);
            addHeap(mainList, newTask, compare);
            printf("The task '%s' has been added to your to-do list.\n\n", desc);
            break;

        case 'g':
          if(sizeDynArr(mainList) > 0)
          {
            firstTask = (TaskP)getMinHeap(mainList);
            printf("Your first task is %s\n\n", firstTask->description);
          }
          else
            printf("Your to-do list is empty.\n");

          break;

        case 'r': /* remove task */

          if(sizeDynArr(mainList) > 0)
          {
            firstTask = (TaskP)getMinHeap(mainList);
            removeMinHeap(mainList, compare);
            printf("Your task '%s' has been removed from the list.\n\n", firstTask->description);
            free(firstTask);
          }

          else
            printf("Your list is empty.\n");

          break;

        case 'p':

          if(sizeDynArr(mainList) > 0)
          {
              printList(mainList);
          }

          else
          {
            printf("Your to-do list is empty.\n");
          }
          break;

        case 'e':
        {
          printf("Bye!\n\n");
          break;
        }

        default:
        {
          printf("That's not a valid command.\n");
        }


      }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
