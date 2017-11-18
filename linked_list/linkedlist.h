/***************************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*filename: linkedlist.h
*description: linked-list writen by c,state some functions and data structures.
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
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef void* LNodeValue;

typedef struct node
{
	void *data;          //the data's pointer stored in the node, all type
	struct node *next;   //next node's pointer
}LNode;

typedef struct linkedlist
{
	LNode *header;   //header of the list
	int length;     //lenght of the list
}LinkedList;

LinkedList* create_list();   //create a linked list
int push_list(LinkedList* list, void* value);    //add a new node at the end of the list
void* pop_list(LinkedList* list);    //remove the node at last,and return it's data
int insert_list(LinkedList* list, int index, void* value);  //insert into the list a new node at the index defined by you
int delete_list(LinkedList* list, int index);       //delete the list node at index
void foreach_list(LinkedList* list);            //vist go through the list and print all datas
void* getElement_list(LinkedList* list, int index);     //get the data at index
int search_list(LinkedList* list, void* value);    //find node by value
int getLength_list(LinkedList* list);       //get the length of the list
void clear_list(LinkedList* list);          //clear the list, remove all the nodes
void free_list(LinkedList* list);           //clear the list, and free the memory of the list

#endif  //!__LINKEDLIST_H__
