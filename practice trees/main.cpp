//
//  main.cpp
//  practice trees
//
//  Created by Dheeraj Reddy on 15/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct node {
    node *left, *right;
    int value;
};

typedef struct node node;

node* create_node(node *current_node, int value) {
    node *n1;
    n1 = new node;
    n1->left = n1->right = NULL;
    n1->value = value;
    return n1;
}

node* insert(node *current_node, int value) {
    if(current_node == NULL)
        return create_node(current_node, value);
    else
        if(current_node->value >= value)
            current_node->left = insert(current_node->left, value);
        else
            current_node->right = insert(current_node->right, value);
    return current_node;
}

void print_tree(node *current_node) {
    if(current_node != NULL) {
        cout << current_node->value <<endl;
        print_tree(current_node->left);
        print_tree(current_node->right);
    }
}

int main(int argc, const char * argv[]) {
    node *root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 4);
    insert(root, 1);
    insert(root, 5);
    insert(root, 15);
    print_tree(root);
    return 0;
}
