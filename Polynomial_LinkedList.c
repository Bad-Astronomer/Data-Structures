#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* next;
    int coef, exp;
};

struct Node* start1 = NULL;
struct Node* start2 = NULL;
struct Node* start3 = NULL;


void insert1()
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    printf("Coefficient (Polynomial 1): ");
    scanf("%d",&new -> coef);
    printf("Exponent (Polynomial 1): ");
    scanf("%d",&new -> exp);
    new -> next = NULL;

    if(start1 == NULL)
    {
        start1 = new;
    }
    else
    {
        struct Node* temp = start1;
        struct Node* prev = start1;
        while(temp -> next != NULL && temp -> exp > new -> exp)
        {
            prev = temp;
            temp = temp -> next;
        }
        if(temp -> exp < new -> exp)
        {
            if(temp == prev)
            {
                new -> next = start1;
                start1 = new;
            }
            else
            {
                new -> next = temp;
                prev -> next = new;
            }
        }
        else if(temp -> exp == new -> exp)
        {
            temp -> coef += new -> coef;
        }
        else
        {
            temp -> next = new;
        }
    }
}

void insert2()
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    printf("Coefficient (Polynomial 2): ");
    scanf("%d",&new -> coef);
    printf("Exponent (Polynomial 2): ");
    scanf("%d",&new -> exp);
    new -> next = NULL;

    if(start2 == NULL)
    {
        start2 = new;
    }
    else
    {
        struct Node* temp = start2;
        struct Node* prev = start2;
        while(temp -> next != NULL && temp -> exp > new -> exp)
        {
            prev = temp;
            temp = temp -> next;
        }
        if(temp -> exp < new -> exp)
        {
            if(temp == prev)
            {
                new -> next = start2;
                start2 = new;
            }
            else
            {
                new -> next = temp;
                prev -> next = new;
            }
        }
        else if(temp -> exp == new -> exp)
        {
            temp -> coef += new -> coef;
        }
        else
        {
            temp -> next = new;
        }
    }
}

void insert3()
{
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> next = start3;
    new -> coef = 0;
    new -> exp = 0;
    start3 = new;
}

void del1()
{
    struct Node* temp = start1;
    struct Node* prev = start1;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> next;
        prev -> next = NULL;
        free(prev);
    }
    start1 = NULL;
}

void del2()
{
    struct Node* temp = start2;
    struct Node* prev = start2;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> next;
        prev -> next = NULL;
        free(prev);
    }
    start2 = NULL;
}

void del3()
{
    struct Node* temp = start3;
    struct Node* prev = start3;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> next;
        prev -> next = NULL;
        free(prev);
    }
    start3 = NULL;
}

void display(struct Node* start)
{
    struct Node* temp = start;
    if(start == NULL)
    {
        printf("Underflow\n");
        return;
    }
    while(temp != NULL)
    {
        if(temp -> coef == 0)
        {
            temp = temp -> next;
            continue;
        }
        printf("%d x^%d\n",temp -> coef, temp -> exp);
        temp = temp -> next;
    }
}

void op(int opt)
{
    del3(); //reset result
    struct Node* temp1 = start1;
    struct Node* temp2 = start2;
    struct Node* temp3 = start3;

    while(temp1 != NULL && temp2 != NULL){

        insert3();
        temp3 = start3;

        if(temp1 -> exp > temp2 -> exp)
        {
            temp3 -> exp = temp1 -> exp;
            temp3 -> coef = temp1 -> coef;
            temp1 = temp1 -> next;
        }
        else if(temp2 -> exp > temp1 -> exp)
        {
            temp3 -> exp = temp2 -> exp;
            temp3 -> coef = temp2 -> coef;
            temp2 = temp2 -> next;
        }
        else if(temp1 -> exp == temp2 -> exp)
        {
            temp3 -> exp = temp1 -> exp;
            if(opt == 1) //ADD
            {
                temp3 -> coef = temp1 -> coef + temp2 -> coef;
            }
            else if(opt == 2) //SUB
            {
                temp3 -> coef = temp1 -> coef - temp2 -> coef;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }

    if(temp1 == NULL)
    {
        while(temp2 != NULL)
        {
            
            insert3();
            temp3 = start3;
            
            temp3 -> coef = temp2 -> coef;
            temp3 -> exp = temp2 -> exp;
            temp2 = temp2 -> next;
        }
    }
    else if(temp2 == NULL)
    {
        while(temp1 != NULL)
        {
            
            insert3();
            temp3 = start3;
            
            temp3 -> coef = temp1 -> coef;
            temp3 -> exp = temp1 -> exp;
            temp1 = temp1 -> next;
        }
    }

    printf("\nResult:\n");
    display(start3);
    del3();
}


void main()
{
    int option, n;
    while(1)
    {
        printf("\nEnter the operation to be performed:\n");
        printf("1. Enter polynomial 1\n2. Enter polynomial 2\n3. Add\n4. Subtract\n5. Extra Options\n6. Exit \n\n>> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("\nEnter the number of terms to be added to polynomial 1: ");
                scanf("%d",&n);

                for(int i = 0; i< n; i++)
                {
                    printf("Enter term %d:\n",i+1);
                    insert1();
                }
                printf("\nTerms Entered:\n");
                display(start1);
                break;

            case 2:
                printf("\nEnter the number of terms to be added to polynomial 2: ");
                scanf("%d",&n);

                for(int i = 0; i< n; i++)
                {
                    printf("Enter term %d:\n",i+1);
                    insert2();
                }
                printf("\nTerms Entered:\n");
                display(start2);
                break;

            case 3:
                op(1);
                break;

            case 4:
                op(2);
                break;

            case 5:
                printf("\nExtra Options:\n1. Display polynomial 1\n2. Display polynomial 2\n3. Clear polynomial 1\n4. Clear polynomial 2\n5. Back\n\n>> ");
                scanf("%d",&n);
                switch(n)
                {
                    case 1:
                        printf("\nPolynomial 1:\n") ;
                        display(start1);
                        break;
                    case 2:
                        printf("\nPolynomial 2:\n") ;
                        display(start1);
                        break;
                    case 3:
                        del1();
                        printf("Polynomial 1 Cleared\n");
                        break;
                    case 4:
                        del2();
                        printf("Polynomial 2 Cleared\n");
                        break;
                    case 5:
                        break;
                    default: 
                        printf("Invalid option\n");
                        break;
                }
                break;
            
            case 6:
                return;
            
            default:
                printf("Invalid Option\n");
        }
    }
}
