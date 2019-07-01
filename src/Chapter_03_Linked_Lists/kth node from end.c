/*Copyright (c) 2008 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com 
#Creation Date     : 2008-01-10 06:15:46 
#Created by        : Narasimha Karumanchi 
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any 
#                    warranty; without even the implied warranty of 
#                    merchantability or fitness for a particular purpose.*/

#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list ListNode */
struct ListNode {
  int data;
  struct ListNode *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a ListNode in pTemp of a singly linked list. 
*/
void insert(int data) {
    /* Create a new Linked List ListNode */
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data  = data;
    /* Next pointer of new ListNode will point to head ListNode of linked list  */
    newNode->next = head;
    /* make new ListNode as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", data);
}
 
int getLength(struct ListNode *head){
    /* Input Validation */
    if (head == NULL) { 
       printf("Error : Invalid ListNode pointer !!!\n");       
       return 0;  
    }
      
    int length =0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}
 
struct ListNode* kthNodeFromEnd(struct ListNode* head, int n){
    struct ListNode *pTemp, *kthNode;
    int i;
    pTemp = kthNode = head;
    /* N should be less than length of Linked List */
    if(n > getLength(head)){
        printf("Error : n is greater than length of Linked List\n");
        return NULL;
    }
    /* Move pTemp pointer k-1 ListNodes. This will create 
    a difference of k-1 ListNodes between pTemp and kthNode */
    for(i = 0; i < n-1; i++){
        pTemp = pTemp->next;
    }
    /* Now, move both pointers together till pTemp reaches 
    last ListNode of linked list. when pTemp reaches last ListNode 
    kthNode pointer will be pointing to Nth last ListNode*/
    while(pTemp->next != NULL){
        pTemp = pTemp->next;
        kthNode = kthNode->next;
    }
     
    return kthNode;
}
/*
Prints a linked list from head ListNode till tail ListNode 
*/
void printLinkedList(struct ListNode *ListNodePtr) {
  while (ListNodePtr != NULL) {
     printf("%d", ListNodePtr->data);
     ListNodePtr = ListNodePtr->next;
     if(ListNodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    struct ListNode *kthNode;
    initialize();
    /* Creating a linked List*/
    insert(3);  
    insert(8); 
    insert(12); 
    insert(0);
    insert(35);
    insert(6);
     
    printf("\nLinked List\n");
    printLinkedList(head);
    kthNode = kthNodeFromEnd(head, 3);
    printf("kth node from end in the linked list is %d", kthNode->data);
    return 0;
}