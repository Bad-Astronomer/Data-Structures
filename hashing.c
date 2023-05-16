//linear probing        i
//quadratic probing     i^2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TableSize 50

int linear_data[TableSize], quadratic_data[TableSize];

int i = 0;

int hash(int data)
{
    int key = data;
    key = data ^ 0x10121096;
    return key%TableSize;
}

void linear_hash(int data, int index)
{
    if(linear_data[index])
    {
        linear_hash(data, (index+1)%TableSize);  //index + i
        return;
    }
    printf("%d inserted at key %d\n",data, index);
    linear_data[index] = data;
}

void quadratic_hash(int data, int index)
{
    int quadratic_index = (index+(i*i))%TableSize;
    if(quadratic_data[quadratic_index]) //index + i^2
    {
        i++;
        quadratic_hash(data, index);
        return;
    }
    printf("%d inserted at key %d (i.e. %d + %d^2)\n",data, quadratic_index, index, i);
    quadratic_data[quadratic_index] = data;
    i = 0;
}

void display()
{
    printf("\n\nLinear Hash:\n");
    for(int j = 0; j < TableSize; j++)
    {
        printf("%d: %d\n", j+1, linear_data[j]);
    }
    printf("\n\nQuadratic Hash:\n");
    for(int j = 0; j < TableSize; j++)
    {
        printf("%d: %d\n", j+1, quadratic_data[j]);
    }
}

void main()
{
    int data, opt;

    while(1)
    {
        printf("\n1. Linear Hash\n2. Quadratic Hash\n3. Display & Exit\n>> ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                printf("\nEnter value to be inserted:");
                scanf("%d",&data);
                linear_hash(data, hash(data));
                break;
            case 2:
                printf("\nEnter value to be inserted:");
                scanf("%d",&data);
                quadratic_hash(data, hash(data));
                break;
            case 3:
                display();
                exit(0);
            default:
                printf("Invalid Input!\n");
                break;
        }
    }    
}