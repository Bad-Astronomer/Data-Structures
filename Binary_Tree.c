#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* head_root = NULL;


struct Node* newNode(int key)
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    if(!new)
    {
        printf("Overflow\n");
        return;
    }

    new -> left = NULL;
    new -> right = NULL;
    new -> data = key;
    return new;
}


void insert(int key)
{       
    struct Node* new = newNode(key);
    struct Node* temp, * prev;
    temp = head_root;
    prev = temp;

    //first insertion
    if(!head_root)
    {
        head_root = new;
        return;
    }

    //general case
    while(temp)
    {
        prev = temp;
        if(temp -> data > new -> data)
        {   
            temp = temp -> left;
            printf("%d Left\n",key);
        }
        else
        {
            temp = temp -> right;
            printf("%d Right\n",key);
        }
    }
    if(prev -> data > new -> data)
    {
        prev -> left = new;
    }
    else
    {
        prev -> right = new;
    }
}

void inorder(struct Node* root)
{
    if(root)
    {
        inorder(root -> left);
        printf("%d\n", root -> data);
        inorder(root -> right);
    }
}

void preorder(struct Node* root)
{
    if(root)
    {
        printf("%d\n", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder  (struct Node* root)
{
    if(root)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d\n", root -> data);
    }
}

void main()
{
    insert(5);
    insert(6);
    insert(7);
    insert(3);
    insert(2);
    insert(4);

    inorder(head_root);
    printf("\n\n");
    preorder(head_root);
    printf("\n\n");
    postorder(head_root);
}
