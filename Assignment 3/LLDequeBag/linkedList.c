/*
Name: Andrew M. Calhoun
Email: calhouna@oregonstate.edu
Date: 10/18/2015
Description: Linked List Deque Implementations
*/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	assert(lst != 0);

	lst->firstLink = (struct DLink *)malloc(sizeof(struct DLink));
	lst->lastLink = (struct DLink *)malloc(sizeof(struct DLink));

	lst->firstLink->prev = 0;
	lst->lastLink->next = 0;
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->size = 0;


}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	// assert(lst = LinkList);
	assert(lst != NULL);
	assert(l != NULL);

	struct DLink *add = malloc(sizeof(struct DLink));

	add->value = v;
	add->next = l;
	add->prev = l->prev;
	l->prev->next = add;
	l->prev = add;

	lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
	assert(lst != NULL);
	_addLinkBefore(lst, lst->firstLink->next, e);

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {

  	assert(lst != NULL);
	_addLinkBefore(lst, lst->lastLink, e);
	/* FIXME: you must write this */
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {

	assert(lst != NULL);
	assert(!isEmptyList(lst));
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return lst->firstLink->next->value;


}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	assert(lst != NULL);
	assert(!isEmptyList(lst));

	return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	assert(lst != NULL);
	assert(l != NULL);
	l->prev->next = l->next;
	l->next->prev = l->prev;

	free(l);
	lst->size--;


	/* FIXME: you must write this */

}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	assert(lst != NULL);
   	assert(!isEmptyList(lst));

   	_removeLink(lst, lst->firstLink->next);

   	/* FIXME: you must write this */

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	assert(lst != NULL);
   	assert(!isEmptyList(lst));
   
   	_removeLink(lst, lst->lastLink->prev);

}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	
 	assert(lst != NULL);
 	if(lst->size == 0)
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}

}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	assert(lst != NULL);

	struct DLink *printList = lst->firstLink->next;
	while(printList != lst->lastLink)
	{
		printf("%d\n", printList->value);
		printList = printList->next;
	}

}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	assert(lst != NULL);

	addBackList(lst, v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(!isEmptyList(lst));

	struct DLink *search = lst->firstLink->next;
	while(!EQ(search, lst->lastLink)
	{
		if(search->value == e)
		{
			return 1;
		}
		search = search->next;
	}

	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(!isEmptyList(lst));

	struct DLink *removal = lst->firstLink;
	while(removal != lst->lastLink)
	{
		if(!EQ(removal->value, e)
		{
			_removeLink(lst, removal);
			break;
		}
		removal = removal->next;
	}
}
