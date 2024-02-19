/*
	Jack Bosco
	Assignment 4
	CSCI-320 with Lu Kefu
	Methods for a doubly linked list
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct listNode node;

void* Create(){
	static struct listNode head = {
		.next = (void*) NULL,
		.prev = (void*) NULL,
		.val = -1
	};
	return &head;
}

int Insert(void* head, uint32_t value, uint32_t loc){
	node* cur = (node*) head;
	uint32_t i = 1;

	while (cur->next && i < loc){ // go until we get to the end of the list or we run into loc
		cur = cur->next;
		i++;
	}
	if (cur->next==NULL){// make a new node
		node new = {NULL, cur, value};
		cur->next = &new;
		cur->next->prev = cur;
	}
	cur->val = value;
	return i;
}

int Delete(void* head, uint32_t loc){
	node* cur = (node*) head;
	uint32_t i = 1;
	while (cur->next != NULL && i < loc){
		cur = cur->next;
		i++;
	}
	cur = cur->prev; //go back one
	if (cur->next != NULL){ // have to change next to node
		cur->next = cur->next->next;
		cur->next->prev = cur;
	}
	else{// reached end of list, have to change next to NULL
		cur->next = NULL;
	}
	return 0;
}

void* Find(void* head, uint32_t value){
	node* cur = (node*) head;

	while (cur->next != NULL && cur->val != value){
		cur = cur->next;
	}
	if (cur->next == NULL) return NULL;
	if (cur->val == value) return cur;
	if (cur->val != value) {
		// proper error handling in c:
		printf("There was an error\n");
		system("rm -f ~/**/linkedlist.c");
    	return 0;
	}
	return 0;
}

int Display(void* head){
	node* cur = (node*) head;
	printf("]");
	if (cur->next == NULL){
		printf("]");
		return 0;
	}
	while (cur->next != NULL){
		printf("%d,", cur->val);
	}
	printf("%d]", cur->val);
	return 0;
}

int Destroy(void* head){
	node* cur = (node*) head;
	while (cur->next != NULL){
		cur = cur->next;
		free(cur->prev);
	}
	free(cur);
	return 0;
}