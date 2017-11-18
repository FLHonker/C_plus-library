/***************************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*filename: linkedlist.c
*description: linked-list writen by c,define some functions
*
*@Version£ºV1.0
*@author£ºFrank Liu
*@time£º20171117
*@platform: GNU C, gcc, on Ubuntu16.04
*
*Change record 1: // Change history record, including modification date, version number, modification person and modification contents
*change-time      version          change-author         change-content

* 20171117         V1.0              Frank                  create
*******************************************************************************/

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//create a linked list
LinkedList* create_list()
{
	LinkedList *list = malloc(sizeof(LinkedList) + sizeof(LNode));
	if (list)
	{
        list->length = 0;
        list->header = (LNode*)(list + 1);
        list->header->next = NULL;
        return list;
    }
    else
		return NULL;
}

//add a new node at the end of the list
int push_list(LinkedList* list, void* value)
{
	if(insert_list(list, list->length, value))
		return list->length;
	else
		return 0;
}

//remove the node at last,and return it's data
// 2 steps
void* pop_list(LinkedList* list)
{
	void* value = getElement_list(list, list->length - 1);   //get the data of the last node
	delete_list(list, list->length - 1);            //delete the last node
	
	return value;        //return the data
}

//insert into the list a new node at the index defined by you
int insert_list(LinkedList* list, int index, void* value)
{
	if (list == NULL || index < 0 || index > list->length)
        return 0;

    LNode *currentNode = list->header;
    for (int i = 0; i < index; i++)
	{
        currentNode = currentNode->next;
    }

    LNode *newNode = malloc(sizeof(LNode));    //apply memory
    if (newNode == NULL)     //if allocate memory for newNode failure, return
		return 0;
	// insert handle
    newNode->next = currentNode->next;
    newNode->data = value;
    currentNode->next = newNode;
    list->length ++;

    return list->length;
}

//delete the list node at index
int delete_list(LinkedList* list, int index)
{
	//if list is empty or the index is invalid, return 0 directly
	if (list == NULL || index < 0 || index >= list->length)   
        return 0;

    LNode *currentNode = list->header;    //record the header of the list
    for (int i = 0; i < index; i++)       //visit go through the list to the front one of index
	{
        currentNode = currentNode->next;  //move node's pointer
    }

    LNode *removeNode = currentNode->next;  //record the node to be removed
    currentNode->next = removeNode->next;   //next to next next
    free(removeNode);
    list->length --;     //change length
    
    return 1;
}

//vist go through the list and print all datas
void foreach_list(LinkedList* list)
{
	 if (list == NULL)
        return;
        
    printf("list {\n");
    printf("\tlength = %d;\n", list->length);   //print the length of the list
    printf("\tvalue = [");
    // get the header of the list
    LNode *currentNode = list->header;
    for (int i = 0; i < list->length; i++)   //visit go throuh the list
	{
        currentNode = currentNode->next;   //move the pointer
        printf("%s",currentNode->data);    //print the data of the node
        if (i < list->length - 1)
            printf(",");
    }
    printf("];\n\t}\n\n");
}

//get the data at index
void* getElement_list(LinkedList* list, int index)
{
	//if list is empty or the index is invalid, return 0 directly
	if (list == NULL || index < 0 || index >= list->length)
        return 0;

    LNode *currentNode = list->header;
    for (int i = 0; i <= index; i++)
	{
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

//find node by value
int search_list(LinkedList* list, void* value)
{
	if (list == NULL)
        return -1;    //find failure!

	int index = 0;
    LNode *currentNode = list->header;
	while(currentNode->data != value)   //find value
	{
		currentNode = currentNode->next;
		++index;
		if(index == list->length)
			break;
	}
	//free(currentNode);   //after used, free pointer
	if(index < list->length)   //can find
		return index;
	else          //can not find
		return -1;   //find failure!
}

//get the length of the list
int getLength_list(LinkedList* list)
{
	if (list == NULL)
		return 0;
	else
    	return list->length;
}

//clear the list, remove all the nodes
void clear_list(LinkedList* list)
{
	if (list == NULL)
		return;

    LNode *headerNode = list->header;
    while (headerNode)  //visit go through the list
	{
        LNode *removeNode = headerNode->next;
        if (removeNode == NULL)
			break;
        headerNode->next = removeNode->next;
        free(removeNode);
        removeNode = NULL;
    }

    list->length = 0;    //set length = 0
}

//clear the list, and free the memory of the list
void free_list(LinkedList* list)
{
	if (list == NULL)
		return;

    clear_list(list);    //firstly,clear list
    free(list);      //free pointer
}
