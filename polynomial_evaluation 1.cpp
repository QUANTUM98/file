#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct node
{
    int coef;
    int power; 
    struct node *link;
}*NODE;
NODE First = NULL;

void Create()
{
    NODE Temp, New, Prev; 
    int coef, power;
    printf("Enter the coef and power terminated by coef 0 \n");
    scanf("%d %d", &coef, &power);
    while(coef != 0)
    {
        New = (NODE)malloc(sizeof(struct node));
        New->coef = coef;
        New->power = power;
        New->link = NULL; 
        if(First == NULL) 
        First = New ;
    
        else 
        {
            if(power > First->power) 
            {
                New->link = First; 
                First = New;
            }
            else
            {
            Temp = First;
            while( (Temp!= NULL) && (power < Temp->power) ) 
            {
                Prev = Temp;
                Temp = Temp->link; 
            }
            if(Temp == NULL)    
            {
                Prev->link = New;
                New->link = Temp;
            }
            else 
            {
                Prev->link = New;
                New->link = Temp;
            }
            }
        }
        scanf("%d %d", &coef, &power);
    }
}

int Evaluate()
{
    NODE Temp;
    int result = 0, x;
    printf("Enter the value of X in the Polynomial  \n");
    scanf("%d", &x);
    Temp = First;
    while(Temp!= NULL)
    {
        result = result + Temp->coef * pow(x, Temp->power);
        Temp = Temp->link;
    }
    return result;
    }

void Display()
{
    NODE Temp;
    if(First == NULL)
    {
        printf("Empty Polynomial \n");
        return;
    }
    Temp = First;
    while(Temp!= NULL) 
    {
        printf("%dx%d + ", Temp->coef, Temp->power);
        Temp = Temp->link;
    }
}

int main()
{
int choice, result;
for(;;)
{
    printf("\n1.Create Polynomial\n2.Evaluate\n3.Display\n4.Exit\n");
    printf("Enter your choice : \n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            Create();
            printf("Polynomial After Creation \n");
            Display();
            break;
        case 2:
            result = Evaluate();
            printf("Result is %d", result);
            break;
        case 3:
            printf("Polynomial is \n");
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option\n\n");
            break;
    }
    }
}