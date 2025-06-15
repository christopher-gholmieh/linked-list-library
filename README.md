# Hashmap:
This is a simple, modern, and barebones linked-list library written in C with the goal of simplicity.

## Documentation
Available methods:
```c
// NOTE: All values stored must be casted to (void*) pointers to be stored.

struct linked_list_node* linked_list_node_initialize(void* pointer, struct linked_list_node* next);
linked_list_t* linked_list_initialize(struct linked_list_node* head);

void linked_list_append(linked_list_t* linked_list, struct linked_list_node* node);
struct linked_list_node* linked_list_pop(linked_list_t* linked_list);

void linked_list_print(linked_list_t* linked_list);
void linked_list_destroy(linked_list_t* linked_list);
```

## Inclusion:
To include the library, simply utilize the linked-list.h file in your project.

## Test:
You can build the test file using **make**.
