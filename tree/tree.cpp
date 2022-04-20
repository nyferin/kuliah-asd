#include <stdio.h>
#include <stdlib.h>

void clear() //clear terminal or cmd
{
    #ifdef _WIN32 //if windows
    system("cls");
    #elif defined(__linux__) //if linux
    system("clear");
    #endif
}

void pause() {
    getchar();
    getchar();
}

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void add(struct node **root, int d) {
    if((*root) == NULL) {
        struct node *newNode;
        newNode = new node;
        newNode->data = d;
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        (*root)->left = NULL;
        (*root)->right = NULL;
        printf("DATA ADDED");
        pause();
    } else if(d < (*root)->data){
        add(&(*root)->left, d);
    } else if(d > (*root)->data){
        add(&(*root)->right, d);
    } else if(d == (*root)->data){
        printf("DETECTED DUPLICATED DATA!");
        pause();
    }
}

void input(void) {
    int data;
    struct node *tree;
    tree = NULL;
    clear();

    printf("INPUT DATA\n\n");

    printf("Input data: ");
    scanf("%d", &data);
    add(&tree, data);
}

void preOrder(struct node *root) {
    if(root != NULL) {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    pause();
}

void inOrder(struct node *root) {
    if(root != NULL) {
        preOrder(root->left);
        printf("%d", root->data);
        preOrder(root->right);
    }
    pause();
}

void postOrder(struct node *root) {
    if(root != NULL) {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d", root->data);
    }
    pause();
}

int main(void) {
    int choice;
    struct node *tree;
    tree = NULL;

    do {
    clear();
    printf("TREE\n\n");
    
    printf("[1] Input data\n");
    printf("[2] Pre-order\n");
    printf("[3] In-order\n");
    printf("[4] Post-order\n");
    printf("[9] EXIT\n");
    printf("[*] Input choice: ");
    scanf("%d", &choice);

    switch(choice) {
    case 1:
        input();
        break;
    
    case 2:
        preOrder(tree);
        break;

    case 3:
        inOrder(tree);
        break;

    case 4:
        postOrder(tree);
        break;

    default:
        break;
    }
    } while (choice != 9);
    

    return 0;
}