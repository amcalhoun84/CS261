/* Andrew M. Calhoun, calhouna@oregonstate.edu
   Date: 11/5/2015
   HW 4 - Extra Credit
 File: animal.c
 Implementation of the animal game, includes BST modifications for the game.

 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"


struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
    assert(tree != NULL);
	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
    assert(tree != NULL);
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
    assert(tree != NULL);
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree)
{
    assert(tree != NULL);
    return (tree->cnt == 0);

}

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree)

{
    assert(tree != NULL);
    return tree->cnt;

}

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)
{
	assert(val != NULL);

    if(cur == NULL)
    {
        struct Node *treeNode = (struct Node *)malloc(sizeof(struct Node));
        assert(treeNode != NULL);
        treeNode->val = val;
        treeNode->left = NULL;
        treeNode->right = NULL;
        return treeNode;
    }
    if(compare(cur->val, val) <= 0) cur->right = _addNode(cur->right, val);
    else cur->left = _addNode(cur->left, val);

    return cur;


}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
    assert(tree != NULL);
    assert(val != NULL);

	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)
{
	assert(tree != NULL);
	assert(val != NULL);
	struct Node *treeNode = tree->root;

	while(treeNode != NULL)
    {
        if(compare(val, treeNode->val) == 0)
        {
            return 1;
        }
        else if(compare(val, treeNode->val) < 0)
        {
            treeNode = treeNode->left;
        }
        else
         {
            treeNode = treeNode->right;
         }
    }
		return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	assert(cur != NULL);

	while(cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
    assert(cur != NULL);

    if(cur->left != NULL)
    {
            cur->left = _removeLeftMost(cur->left);
            return cur;
    }
    else
    {
        struct Node *removeNode = cur->right;
        free(cur->val);
        free(cur);
        return removeNode;
    }
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)
{
	assert(cur != 0);
	assert(val != NULL);


	struct Node *treeNode;
	if(compare(val, cur->val) == 0)
    {

        if(cur->right == 0)
        {
            treeNode = cur->left;
            free(cur);
            return treeNode;
        }

        cur->val = _leftMost(cur->right);
        cur->right = _removeLeftMost(cur->right);
    }
    else if(compare(val,cur->val) < 0)
    {
        cur->left = _removeNode(cur->left, val);
    }
    else
    {
        cur->right = _removeNode(cur->right, val);
    }

    return cur;
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
    assert(val != NULL);
    assert(tree != NULL);

	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/

/* The following is used only for debugging, set to "#if 0" when used
  in other applications */
#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur) {
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree) {
	 if (tree == 0) return;
	 printNode(tree->root);
}
/*----------------------------------------------------------------------------*/

#endif

struct BSTree *animalTree(struct BSTree *animals) {

    char animalName[200];
    int number;

    FILE *dataFile = fopen("animal.txt","r");

    if(dataFile == NULL)
    {
        printf("ERROR: Data file 'animal.txt' not found...");
        exit(1);
    }
    while(fscanf(dataFile, "%199[^,], %d", animalName, &number) == 2)
    {

        struct data *animalData = malloc(sizeof(struct data));
        animalData->number = number;
        animalData->name = strdup(animalName);
        addBSTree(animals, animalData);
    }

    fclose(dataFile);
    return animals;

}


void startScreen()
{

    printf("****************************************\n");
    printf("*                                      *\n");
    printf("* Welcome to Andrew's Animal Guessing  *\n");
    printf("*                 Game!                *\n");
    printf("*                                      *\n");
    printf("****************************************\n");

}

void instructions()
{
    printf("\n\nThis is a simple animal guessing game, making use of the binary search tree data structure.\n");
    printf("Answer Y/N or Q to any question asked by the game, and if you can stump the program, it'll ask\n");
    printf("you to add a new animal to the mix!");
    printf("\n\nHave fun!");

}

void game(struct BSTree *animals)
{
    assert(animals != NULL);

    struct Node *cur = animals->root;
    char userAnswer;
    int currentNode, previousNode;

    while(cur != NULL)
    {
        previousNode = currentNode;
        currentNode = nodeHeight(cur->val);

        animal_type(cur->val);
        printf("Y for Yes / N for No / Q for Quit\n");
        printf(" >> ");
        scanf("%c", &userAnswer);
        getchar() != '\n';
        printf("\n");

        if(userAnswer == 'N' || userAnswer == 'n')
        {
            cur = cur->right;
        }
        else if(userAnswer == 'Q' || userAnswer == 'q')
        {
            printf("Sorry to see you go!\n\n");
            exit(1);
        }
        else if(userAnswer == 'Y' || userAnswer == 'n')
        {
            cur = cur->left;

        }
        else
        {
            printf("Invalid answer. Please try again.\n\n");
        }
    }


    if(userAnswer == 'N' || userAnswer == 'n')
    {
        char newQuestion[200] = {'\0'};
        char newAnimal[200] = {'\0'};
        int newHeight = 0; // new node height;

        if(previousNode > currentNode)
        {
            newHeight = previousNode+(currentNode-previousNode)/2;
        }
        else
        {

            newHeight = currentNode-(previousNode-currentNode)/2;
        }

        printf("You stumped me! I couldn't guess the animal.\nPlease give me a question to help me figure out your animal.\n>> ");
        getchar() != '\n';
        scanf("%199[^\n]", newQuestion);
        printf("What is the animal you are thinking of? \n>> ");
        getchar() != '\n';
        scanf("%199[^\n]", newAnimal);
        FILE *writeData;
        writeData = fopen("animal.txt", "a");
        fprintf(writeData, "%s,%d\n", &newQuestion, newHeight);         // I cannot figure out the bug here which doesn't include the first letter of the character string. It's very odd, but the program other wise works fine.
        fprintf(writeData, "Is it a %s?,%d", &newAnimal, newHeight+(currentNode - newHeight)/2);
        fclose(writeData);

        printf("Your question and animal have been added.\n\n");
        printf("See you later! Let's play again soon. :-)\n\n");

    }

    if(userAnswer == 'Y' || userAnswer == 'y')
    {
        printf("I guessed your animal! \n");
        printf("See you later! Let's play again soon. :-)\n\n");
    }

}

int main(int argc, char *argv[])
{
    struct BSTree *animals = newBSTree();

    startScreen();
    animalTree(animals);
    game(animals);
	return 0;
}
