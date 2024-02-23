/*
	Jack Bosco
	Assignment 4
	CSCI-320 with Lu Kefu
	Methods for a doubly linked list
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
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

	pthread_mutex_init(&(head->lock), NULL);
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
	cur = cur->next;
	uint32_t i = 1;
	while (cur->next->next && i < loc){
		cur = cur->next;
		i++;
	}
	cur->prev->next = cur->next; //go back one
	cur->next->prev = cur->prev; //go forward one
	free(cur);
	return i;
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
	int i = 0;
	printf("[");
	if (!cur->next->next){
		printf("]\n");
		return 0;
	}
	while (cur->next->next){
		if (cur->val != -1) printf("%d,", cur->val);
		cur = cur->next;
		i++;
	}
	printf("%d]\n", cur->val);
	return i;
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

//================== Parallel-safe methods================

int SafeInsert(void* head, uint32_t value, uint32_t loc){ //Inserts an item of the value at the index loc. If loc is out-of-bounds, it should insert at the end of the list.
	node* h = (node*) head;
	pthread_mutex_lock(&h->lock);
	int ret = Insert(head, value, loc);
	pthread_mutex_unlock(&h->lock);
	return ret;
}

int SafeDelete(void* head, uint32_t item){//Deletes the item at index loc. If loc is out-of-bounds, it should delete the last item in list.
	node* h = (node*) head;
	pthread_mutex_lock(&(h->lock));
	int ret = Delete(head, item);
	pthread_mutex_unlock(&h->lock);
	return ret;
}

void* SafeFind(void* head, uint32_t value){//Finds whether a given item is in the list and returns a pointer to it!
	node* h = (node*) head;
	pthread_mutex_lock(&h->lock);
	void* ret = Find(head, value);
	pthread_mutex_unlock(&h->lock);
	return ret;
}