#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node *left, *right;
    int data;
};


struct Node* root = NULL;

struct Node* newNode(int key)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node)); 
    
    if(!new)
    {
        return;
    }

    new -> data = key;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}

void insert(int key)
{
    struct Node* new = newNode(key);
    struct Node* temp = root;
    struct Node* prev = temp;

    //overflow
    if(!new)
    {
        return;
    }

    // first insert
    if(!root)
    {
        root = new;
        return;
    }

    // general case
    while(temp)
    {
        prev = temp;

        if(temp -> data < key)
        {
            temp = temp -> right;
        }
        else
        {
            temp = temp -> left;
        }
    }
    if(key > prev -> data)
    {
        prev -> right = new;
    }
    else
    {
        prev -> left = new;
    }
}

void search(struct Node* temp, int key)
{
    if(temp)
    {
        if(temp -> data == key)
        {
            printf("%d found",temp -> data);
        }
        else if(temp -> data < key)
        {
            return search(temp -> right, key);
        }
        else if(temp -> data > key)
        {
            return search(temp -> left, key);
        }
    }
    else
    {
        printf("%d not found\n", key);
    }
}

void inorder(struct Node* temp)
{
    if(temp)
    {
        inorder(temp -> left);          //left
        printf("%d\n",temp -> data);    //root
        inorder(temp -> right);         //right
    }
}

void preorder(struct Node* temp)
{
    if(temp)
    {
        printf("%d\n",temp -> data);
        preorder(temp -> left);
        preorder(temp -> right);
    }
}

void postorder(struct Node* temp)
{
    if(temp)
    {
        postorder(temp -> left);
        postorder(temp -> right);
        printf("%d\n",temp -> data);
    }
}

void delete(struct Node* root, int key)
{
    
}

void main()
{
    insert(60);
    insert(80);
    insert(30);
    insert(90);
    insert(70);
    insert(40);
    printf("Inorder: \n");
    inorder(root);
    search(root, 20);
    search(root, 40);
    printf("\nPre-order:\n");
    preorder(root);
    printf("\nPost-order:\n");
    postorder(root);
}

/*      
        60
    /       \
   30        80
    \       /   \
    40     70   90
*/