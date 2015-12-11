/* CS261- Assignment 1 - Q.5*/
/* Name: Andrew M. Calhoun
 * Date: 10/3/2015
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for toupper and tolower

/*converts ch to upper case, assuming it is in lower case currently*/

/******************************************************************************
 ** Function:         char toUpperCase(char ch)
 ** Description:      Makes lower case letters upper case.
 ** Parameters:       char ch
 ** Pre-Conditions:   Even indices are hit.
 ** Post-Conditions:  If a character is of a proper index, it makes it upper case if it is not already.
 *****************************************************************************/

char toUpperCase(char ch){
     if(ch >= 'A' && ch <= 'Z')
        return ch;
    else
        return ch+'A'-'a';
}

/*converts ch to lower case, assuming it is in upper case currently*/
/******************************************************************************
 ** Function:         char toLowerCase(char ch)
 ** Description:      Makes upper case characters lower case.
 ** Parameters:       char ch
 ** Pre-Conditions:   Odd indices are hit.
 ** Post-Conditions:  If a character is of a proper index, it makes it lower case if it is not already.
 *****************************************************************************/

char toLowerCase(char ch){
     if(ch >= 'a')
        return ch;
     else
        return ch-'A'+'a';
}


/******************************************************************************
 ** Function:         void sticky(char* word)
 ** Description:      Searches through an entered word, and compares the index of the array, to determine
                        if a letter needs to be converted to upper or lower case.
 ** Parameters:       char* word - character pointer to word array.
 ** Pre-Conditions:   User inputs a word in main()
 ** Post-Conditions:  Word is converted to sTiCkY caps.
 *****************************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
     int i;

     for(i = 0; i < 34; i++)
     {
         if(word[i] == '\0')    // Null-terminator. End the loop here and return.
         {
             return;
         }
         if(i%2)
            word[i] = toLowerCase(word[i]);
         //   word[i] = tolower(word[i]);
         else
            word[i] = toUpperCase(word[i]);
         //   word[i] = toupper(word[i]);

     }
}

/******************************************************************************
 ** Function:         int main()
 ** Description:      The main function
 ** Parameters:       char* word - character pointer to word array.
 ** Pre-Conditions:   User inputs a word in main()
 ** Post-Conditions:  Word is converted to sTiCkY caps.
 *****************************************************************************/

int main(){


    /*Read word from the keyboard using scanf*/
    char word[34]; // max word length is 34. This is the length of the longest coined word is 34, from Mary Poppins.

    printf("Please input your word (limit 34 letters): ");
    scanf("%s", word);
    printf("\nYour entered word is: %s\n", word);

    /*Call sticky*/
    sticky(word);
    /*Print the new word*/
    printf("Fixed Word: %s\n\n", word);

    return 0;
}
