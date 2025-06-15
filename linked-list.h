// Written by: Christopher Gholmieh
// Guards:
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// Headers:
#include <stdlib.h>
#include <stdio.h>

// Structures:
struct linked_list_node {
    /* Pointer: */
    void* pointer;
    
    /* Next: */
    struct linked_list_node* next;
};

typedef struct {
    /* Head: */
    struct linked_list_node* head;
} linked_list_t;

// Functions:
struct linked_list_node* linked_list_node_initialize(void* pointer, struct linked_list_node* next);
linked_list_t* linked_list_initialize(struct linked_list_node* head);

void linked_list_append(linked_list_t* linked_list, struct linked_list_node* node);
struct linked_list_node* linked_list_pop(linked_list_t* linked_list);

void linked_list_print(linked_list_t* linked_list);
void linked_list_destroy(linked_list_t* linked_list);

// Functions:
struct linked_list_node* linked_list_node_initialize(void* pointer, struct linked_list_node* next) {
    // Variables (Assignment):
    // Node:
    struct linked_list_node* node = (struct linked_list_node*) malloc(sizeof(struct linked_list_node));

    if (node == NULL) {
        fprintf(stderr, "[!] Unable to allocate memory for node.\n");

        return NULL;
    }

    // Pointer:
    node->pointer = pointer;

    // Next:
    node->next = next;

    // Logic:
    return node;
}

linked_list_t* linked_list_initialize(struct linked_list_node* head) {
    // Variables (Assignment):
    // List:
    linked_list_t* linked_list = (linked_list_t*) malloc(sizeof(linked_list_t));

    if (linked_list == NULL) {
        fprintf(stderr, "[!] Unable to allocate memory for linked list.\n");

        return NULL;
    }

    // Head:
    linked_list->head = head;

    // Logic:
    return linked_list;
}

void linked_list_append(linked_list_t* linked_list, struct linked_list_node* node) {
    // Validation:
    if (linked_list == NULL) {
        fprintf(stderr, "[!] Unable to perform append operation on NULL linked list.\n");

        return;
    }

    if (linked_list->head == NULL) {
        linked_list->head = node;

        return;
    }

    // Variables (Assignment):
    // Current:
    struct linked_list_node* current_node = linked_list->head;

    // Logic:
    while (current_node->next) {
        current_node = current_node->next;
    }

    current_node->next = node;
}

struct linked_list_node* linked_list_pop(linked_list_t* linked_list) {
    // Validation:
    if (linked_list == NULL) {
        fprintf(stderr, "[!] Can't pop a NULL linked list.\n");

        return NULL;
    }

    if (linked_list->head == NULL) {
        fprintf(stderr, "[!] Unable to perform pop operation on empty linked list.\n");

        return NULL;
    }

    // Variables (Assignment):
    // Head:
    struct linked_list_node* head = linked_list->head;

    if (linked_list->head->next == NULL) {
        linked_list->head = NULL;

        return head;
    }

    // Variables (Assignment):
    // Current:
    struct linked_list_node* current_node = head;

    // Logic:
    while (current_node->next->next) {
        current_node = current_node->next;
    }

    // Last:
    struct linked_list_node* last_node = current_node->next;

    // Logic:
    current_node->next = NULL;

    return current_node->next;
}

void linked_list_print(linked_list_t* linked_list) {
    // Validation:
    if (linked_list == NULL) {
        fprintf(stderr, "[!] Can't print a NULL linked list.\n");

        return;
    }

    if (linked_list->head == NULL) {
        printf("[*] Nothing to print.\n");

        return;
    }

    // Variables (Assignment):
    // Current:
    struct linked_list_node* current_node = linked_list->head;

    // Logic:
    while (current_node->next) {
        printf("%p -> ", current_node->pointer);

        current_node = current_node->next;
    }

    printf("%p\n", current_node->pointer);
}

void linked_list_destroy(linked_list_t *linked_list) {
    // Validation:
    if (linked_list == NULL) {
        printf("[*] Can't destroy a NULL linked list.\n");

        return;
    }

    if (linked_list->head == NULL) {
        printf("[*] Can't destroy an empty linked list.\n");

        return;
    }

    // Variables (Assignment):
    // Current:
    struct linked_list_node* current_node = linked_list->head;

    // Next:
    struct linked_list_node* next_node;

    // Logic:
    while (current_node->next) {
        next_node = current_node->next;

        free(current_node->pointer);
        free(current_node);

        current_node = next_node;
    }

    free(current_node->pointer);
    free(current_node);

    free(linked_list);
}

// Guard:
#endif /** __LINKED_LIST_H__ */
