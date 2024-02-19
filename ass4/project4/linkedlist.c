/*
	Jack Bosco
	Assignment 4
	CSCI-320 with Lu Kefu
	Methods for a doubly linked list
*/

#include 'linkedlist.h'

void* Create(){
	node head = {
		.next = NULL,
		.prev = NULL,
		.val = NULL
	};
	return head;
}

int Insert(void* head, uint32_t value, uint32_t loc){
	node cur = (node) head;
	uint32_t i = 0;
	if (cur->val == NULL){ // check if the head is empty, if so just put the value in HEAD
		cur->val = value;
		cur->next = (node) Create();
		cur->next->prev = cur;
		return 0;
	}
	while (cur->next != NULL; && i < loc){ // go until we get to the end of the list or we run into loc
		cur = cur->next;
		i++;
	}
	if (cur->next==NULL){// make a new node
		cur->next = Create(); 
		cur->next->prev = cur;
	}
	cur->val = value;
	return i;
}

