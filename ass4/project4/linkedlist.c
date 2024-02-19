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
	node* head = (node*) malloc(sizeof(node));
	head->prev = NULL;
	head->val = -1;
	node* tail = (node*) malloc(sizeof(node));
	tail->prev = head;
	head->next = tail;
	tail->val = -1;
	tail->next = NULL;
	return head;
}


int Insert(void* head, uint32_t value, uint32_t loc){
	node* cur = (node*) head;
	uint32_t i = 0;
	while (cur->next && i <= loc){ // go until we get to the end of the list or we run into loc
		cur = cur->next;
		i++;
	}
	node* new = (node*) malloc(sizeof(node));
	new->next = cur;
	new->prev = cur->prev;
	new->val = value;
	cur->prev=new;
	new->prev->next=new;
	return i;
}

int Delete(void* head, uint32_t loc){
	node* cur = (node*) head;
	uint32_t i = 0;
	while (cur->next->next && i < loc){
		cur = cur->next;
		i++;
	}
	cur = cur->prev; //go back one
	cur->next = cur->next->next;
	free(cur->next->prev);
	cur->next->prev = cur;
	return 0;
}

void* Find(void* head, uint32_t value){
	node* cur = (node*) head;

	while (cur->next && cur->val != value){
		if (cur->val == value) return cur;
		cur = cur->next;
	}
	return cur;
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
	printf("[");
	if (!cur->next->next){
		printf("]\n");
		return 0;
	}
	while (cur->next->next){
		if (cur->val != -1) printf("%d,", cur->val);
		cur = cur->next;
	}
	printf("%d]\n", cur->val);
	return 0;
}

int Destroy(void* head){
	node* cur = (node*) head;
	while (cur->next){
		cur = cur->next;
		free(cur->prev);
	}
	free(cur);
	return 0;
}
