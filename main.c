#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * Basic node that stores the value/index of node
*/
struct node{
    int value;
    struct node *next;
};

/**
 * Initialization
*/
void Initialize(struct node** head_ptr){
    (*head_ptr) = NULL;
}

/**
 * Insert element at the front/beginning of linked list
*/
void Insert_Front(struct node** head_ptr, int value){
    // Initial new node
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    // Assign value to new node
    temp->value = value;
    // Point new node to old head./
    temp->next = (*head_ptr);
    // Make the new node as head
    (*head_ptr) = temp;

}

/**
 * Insert element at the end of linked list
*/
void Insert_End(struct node** head_ptr, int value){

    // Initial new node
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    // Assign value to new node
    temp->value = value;
    // Point new node to NULL
    temp->next = NULL;

    // If linked list is empty, make new node as head
    if((*head_ptr) == NULL){
        (*head_ptr) = temp;
        return;
    }

    // Traverse to the end of linked list
    struct node *last = (*head_ptr);
    while(last->next != NULL){
        last = last->next;
    }

    // Point last node to new node, i.e. make new node as last node which is NULL
    last->next = temp;
    return;
}

/**
 * Insert element at the given index of linked list
*/
void Insert_After(struct node* prev_node, int value){

    // Check if previous node is NULL
    if(prev_node == NULL){
        printf("Previous node cannot be NULL\n");
        return;
    }

    // Initial new node
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    // Assign value to new node
    temp->value = value;
    // Point new node to next node of previous node
    temp->next = prev_node->next;
    // Point previous node to new node
    prev_node->next = temp;
}

/**
 * Calculate the length of linked list using iterative method
*/
uint32_t List_Length(struct node* head){
    uint32_t length = 0;
    struct node *current = head;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

/**
 * Print the linked list
*/
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Reverse Linked List
*/
void Reverse_List(struct node** head_ptr){
    struct node *prev = NULL;
    struct node *current = (*head_ptr);
    struct node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    (*head_ptr) = prev;
}

/**
 * Delete an element from beginning of linked list
*/
void Delete_Front(struct node** head_ptr){
    // Check if linked list is empty
    if((*head_ptr) == NULL){
        printf("Linked list is empty\n");
        return;
    }

    // Store the head node
    struct node *temp = (*head_ptr);
    // Point head to next node
    (*head_ptr) = (*head_ptr)->next;

    // Free the memory of previous head node
    free(temp);
}

/**
 * Delete an element from end of linked list
*/
void Delete_End(struct node** head_ptr){
    // Check if linked list is empty
    if((*head_ptr) == NULL){
        printf("Linked list is empty\n");
        return;
    }

    // Store the head node
    struct node *temp = (*head_ptr);
    // Traverse to the end of linked list
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    // Free the memory of last node
    free(temp->next);
    // Point last node to NULL
    temp->next = NULL;
}

/**
 * Delete an element from given index of linked list
*/
void Delete_Index(struct node** head_ptr, uint32_t index){
    // Check if linked list is empty
    if((*head_ptr) == NULL){
        printf("Linked list is empty\n");
        return;
    }

    // Store the head node
    struct node *temp = (*head_ptr);
    // Traverse to the given index of linked list
    for(uint32_t i = 0; i < index-1; i++){
        temp = temp->next;
    }
    // Store the node to be deleted
    struct node *temp2 = temp->next;
    // Point previous node to next node of node to be deleted
    temp->next = temp->next->next;
    // Free the memory of node to be deleted
    free(temp2);
}

/**
 * Delete an element from given value of linked list
*/
void Delete_Value(struct node** head_ptr, int value){
    // Check if linked list is empty
    if((*head_ptr) == NULL){
        printf("Linked list is empty\n");
        return;
    }

    // Store the head node
    struct node *temp = (*head_ptr);
    // Traverse to the given value of linked list
    while(temp->next->value != value){
        temp = temp->next;
    }
    // Store the node to be deleted
    struct node *temp2 = temp->next;
    // Point previous node to next node of node to be deleted
    temp->next = temp->next->next;
    // Free the memory of node to be deleted
    free(temp2);
}

/**
 * Delete the entire linked list
*/
void Delete_List(struct node** head_ptr){
    // Store the head node
    struct node *temp = (*head_ptr);
    // Traverse to the end of linked list
    while(temp != NULL){
        // Store the next node
        struct node *temp2 = temp->next;
        // Free the memory of current node
        free(temp);
        // Point current node to next node
        temp = temp2;
    }
    // Point head to NULL
    (*head_ptr) = NULL;
}

/** 
 * Get index of given value
*/
uint32_t Get_Index(struct node* head, int value){
    uint32_t index = 0;
    struct node *temp = head;
    while(temp->value != value){
        index++;
        temp = temp->next;
    }
    return index;
}

int main(){

    struct node *head;
    Initialize(&head);

    head = (struct node *) malloc(sizeof(struct node));
    head->value = 1;
    head->next = NULL;

    Insert_Front(&head, 2);
    Insert_Front(&head, 3);
    Insert_After(head, 5);
    Insert_End(&head, 4);



    Delete_List(&head);
    Delete_Index(&head, 2);

    return 0;
}