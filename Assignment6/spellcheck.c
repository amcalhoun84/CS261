#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.

 when there are no more words in the input file this function will return NULL.

 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht);
void correctWords(struct hashMap *hashTable, char* word);
void casefix(char* word);

int main (int argc, const char * argv[]) {
  clock_t timer;
  struct hashMap* hashTable;
  int tableSize = 100000;
  timer = clock();
  hashTable = createMap(tableSize);

  FILE* dictionary;
  dictionary = fopen("dictionary.txt", "r");
  assert(dictionary != NULL);

  loadDictionary(dictionary,hashTable);
  timer = clock() - timer;
	printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);

  char* word = (char*)malloc(256*sizeof(char));
  int quit=0;
  while(!quit){
    printf("Enter a word: ");
    scanf("%s",word);
    casefix(word);

    if(containsKey(hashTable, word))
        printf("Word: %s is spelled correctly.\n", word);
    else
    {
      printf("Word: %s is not spelled correctly.\n", word);
      //  correctWords(hashTable, word);
    }

    /* Don't remove this. It is used for grading*/
    if(strcmp(word,"quit")==0)
      quit=!quit;
  }
 //  free(word);
  fclose(dictionary);
  return 0;
}

void casefix(char* word)
{
    if(word == NULL)
    {
        return;
    }

    if(word == 0)
    {
        return;
    }

    int i = 0;
    while(word[i] != '\0')
    {
        word[i] = tolower(word[i]);
        i++;
    }
}

//void correctWords(struct hashMap *hashTable, char* word)
//{
//
//    int i, j;
//    printf("==== WORDS CLOSE TO YOUR SPELLING '%s' BELOW ===\n\n", word);
//    char *temp1, *temp2;
//
//    // First, we have to swap words to find the proper placement.
//
//    for(i = 0; word[i+1] = '\0'; i++)
//    {
//        char* testWord = strlwr(word);
//        temp1 = testWord[i];
//        temp2 = testWord[i+1];
//        testWord[i] = temp2;
//        testWord[i+1] = temp1;
//        if(containsKey(hashTable, testWord)) printf("Match Found: %s \n", testWord);
//
//    }
//
//    for(i = 0; word[i] != '\0'; i++)
//    {
//        char *testWord;
//        testWord = strlwr(word);
//        for(j = 97; j < 123; j++)  // find the values
//        {
//            testWord[i] = j;
//            if(containsKey(hashTable, testWord))
//                printf("Match Found: %s \n", testWord);
//        }
//    }
//    printf("\n");
//
//}

void loadDictionary(FILE* file, struct hashMap* ht)
{
  char *word;

  while((word = getWord(file)))
  {
      if(word) insertMap(ht, word, 0);
  }

  fclose(file);

}
void printValue(ValueType v) {
	printf("Value:%d",(int *)v);
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   (character == 39)) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}

	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
