#include "binaryTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Entendi nada deste dever */

int main() {
    Node *n1 = create_node(10);
    Node *n2 = create_node(20);
    Node *n3 = create_node(30);
    Node *n4 = create_node(40);
    Node *n5 = create_node(50);

    insert_node_tree(n1, n2);
    insert_node_tree(n2, n3);
    insert_node_tree(n2, n4);
    insert_node_tree(n4, n5);

    print_tree(n1);

    // printf("\nEncontrado? %d\n", search(n1, 20));

    // destroy_tree(n1);
}