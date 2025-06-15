// Written by: Christopher Gholmieh
// Headers:

// Library:
#include "linked-list.h"


// Main:
int main(void) {
    // Variables (Assignment):
    // List:
    linked_list_t* linked_list = linked_list_initialize(
        linked_list_node_initialize(malloc(4),
            linked_list_node_initialize(malloc(4),
                linked_list_node_initialize(malloc(1), NULL)
            )
        )
    );

    // Logic:
    linked_list_print(linked_list);
    linked_list_pop(linked_list);

    linked_list_print(linked_list);

    linked_list_append(linked_list, linked_list_node_initialize(malloc(4), NULL));
    linked_list_print(linked_list);

    linked_list_destroy(linked_list);

    return 0;
}
