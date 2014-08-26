#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node* root, int data);
node* newNode(int data);
bool search(node* root, int data);
int findHeight(node* root);
int findDiameter(node* root);
bool delete(node* root, int data);
node* findMin(node* root);


int main(){

    int value = 0;
    
    node* root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 34);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 9);
    root = insert(root, 20);
    
    
    printf("Enter a number to search for:\n");
    scanf("%d", &value);
    
    bool found = search(root, value);
    
    if (found){
        printf("Number found!\n");
    }
    else{
        printf("Number not found!\n");
    }
    
    int height = findHeight(root);

    printf("Height of tree is: %d\n\n", height);
    
    int diameter = findDiameter(root);
    
    printf("Diamter of tree is: %d\n\n", diameter);

    printf("Enter a number to delete:\n");
    scanf("%d", &value);
    
    bool deleted = delete(root, value);
    
    if (deleted){
        printf("%d has been deleted!\n\n", value);
    }
    else{
        printf("Sorry %d couldn't be deleted\n\n", value);
    }
        
}

node* newNode(int data)
{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

node* insert(node* root, int data){

    if (root == NULL){
    root = newNode(data);
    }
     
    else if (data <= root->data){
    root->left = insert(root->left, data);
    }

    else if (data > root->data){
    root->right = insert(root->right, data);
    }

    return root;

}

bool search(node* root, int data){
    
    if (root == NULL){
        return false;
    }
    if (data == root->data){
        return true;
    }
    else if (data < root->data){

        return search(root->left, data);
    }
    else if (data > root->data){

        return search(root->right, data);
    }
    
    return false;

}

int findHeight(node* root){
    
    if (root == NULL){
        return -1;
    }    
   
    return fmax(findHeight(root->left), findHeight(root->right)) + 1;
    
}

int findDiameter(node* root){

    if (root == NULL){
        return -1;
    }
    
    int leftMax = findDiameter(root->left) + 1;
    int rightMax = findDiameter(root->right) + 1;
    
    int diameter = leftMax + rightMax;
    
    return diameter;
    
}

bool delete(node* root, int data){
    
    if (root == NULL){
        return false;
    }
    
    if (data == root->data){
        if (root->left == NULL && root->right == NULL){
            root = NULL;
            return true;
        }
        else if (root->left == NULL && root->right != NULL){
            root = root->right;
            return true;
        }
        else if (root->left != NULL && root->right == NULL){
            root = root->left;
            return true;
        }
        else if (root->left != NULL && root->right != NULL){
            root = findMin(root->right);
        }      
        
    }
    else if (data >= root->data){
        return delete(root->right, data);
    }
    else if (data <= root->data){
        return delete(root->left, data);
    }
    
    return false;
    
}

node* findMin(node* root){
    
    if (root->left == NULL){
        return root;
    }
    else{
        return findMin(root->left);
    }
    
}
