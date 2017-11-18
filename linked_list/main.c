/***************************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*filename: main.c
*description: teat linked-list, give a example of linked-list
*
*@Version：V1.0
*@author：Frank Liu
*@time：20171117
*@platform: GNU C, gcc, on Ubuntu16.04
*
*Change record 1: // Change history record, including modification date, version number, modification person and modification contents
*change-time      version          change-author         change-content

* 20171117         V1.0              Frank                  create
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// show interactive UI
void display()
{
	printf("\n\t***************linked-list operation**************\n");
	printf("\t**    1 Create list\n");
	printf("\t**    2 Push list\n");
	printf("\t**    3 Pop list\n");
	printf("\t**    4 Insert data\n");
	printf("\t**    5 Delete data\n");
	printf("\t**    6 Visit go through list\n");
	printf("\t**    7 Search in list\n");
	printf("\t**    8 Clear list\n");
	printf("\t**    9 Free list\n");
	printf("\t**    0 Exit \n");
	printf("\t**************************************************\n");
	printf("\tPlease input your select number:");
}

int main(int argc, char *argv[])
{
	int select = -1, index = -1;
	char *pvalue, *pop_value;
	char value[20];
	LinkedList* list;
	
	while(select)
	{
		select = -1;
		index = -1;
		pvalue = calloc(1, 20);
		display();
		scanf("%d", &select);
		switch(select)
		{
			case 1:
				list = create_list();
				printf("\tlist created successfully!\n");
				break;
			case 2:
				if(list == NULL)
				{
					printf("\tPlease create a list firstly!\n");
					break;
				}
				printf("\tPlease input data:");
				scanf("%s",&value);
				memcpy(pvalue, value, 20);
				push_list(list, pvalue);
				printf("\tPush \'%s\' OK!\n", value);
				break;
			case 3:
				pop_value = (char*)pop_list(list);
				printf("\tPop \'%s\' OK!\n", pop_value);
				break;
			case 4:
				printf("\tPlease input index:");
				scanf("%d", &index);
				printf("\tPlease input data:");
				scanf("%s", &value);
				memcpy(pvalue, value, 20);
				insert_list(list, index, pvalue);
				printf("\tInsert \'%s\' into list at %d\n", value, index);
				break;
			case 5:
				printf("\tPlease input index:");
				scanf("%d", &index);
				delete_list(list, index);
				printf("\tDelete data at %d\n", index);
				break;
			case 6:
				foreach_list(list);
				break;
			case 7:
				printf("\tPlease input data:");
				scanf("%s", &value);
				index = search_list(list, value);
				if(index >= 0)
					printf("\t\'%s\' is at %d index.\n", value, index);
				else
					printf("\tNot found \'%s\'! \n", value);
				break;
			case 8:
				clear_list(list);
				printf("\tClear the list OK!\n");
				break;
			case 9:
				free_list(list);
				printf("\tFree the list OK!\n");
				break;
			case 0:
				return 0;
			default:
				printf("\tInvalid number!\n");
				break;
		}
	}
	
    return 0;
}
