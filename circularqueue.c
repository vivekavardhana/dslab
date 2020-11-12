/* 6. Design, Develop and Implement a menu driven Program in C for the following operations
on Circular QUEUE of Characters (Array Implementation of Queue with maximum size
MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations */

#include<stdio.h>
#define MAX 6
int front=0,rear=0;
char q[MAX];

//a. Insert an Element on to Circular QUEUE
void insert()
{
    char item;
    if(front==(rear+1)%MAX) // Check for overflow
     {
          printf("\n  Circular Queue Overflow\n");
          return;
     }
    rear=(rear+1)%MAX;
    printf("\n Enter the character to be inserted: ");
    fflush(stdin);
    scanf("%c",&item);
    q[rear]=item;
} // end of insert

//b. Delete an Element from Circular QUEUE
void delete()
{
    if(front==rear) // check for Underflow
     {
          printf("\n  Circular Queue Underflow\n");
          return;
     }
    front=(front+1)%MAX;
    printf("\n Deleted character is: %c ",q[front]);
} // end of delete

// d. Display the status of Circular QUEUE
void display()
{
    int i;
        if(front==rear)
         {
              printf("\nCircular Queue is Empty\n");
              return;
         }
    printf("\n Contents of Queue is:\n");
    for(i=(front+1)%MAX;    i!=rear;    i=(i+1)%MAX)
            printf("%c\t",q[i]);
    printf("%c\t",q[i]);
} // end of display

void main()
{
     int choice;
     while(1)
      {
           printf("\n CIRCULAR QUEUE OPERATIONS");
           printf("\n Enter the choice");
           printf("\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
            scanf("%d",&choice);
           switch(choice)
           {
                case 1:
                       insert();
                       break;
                case 2:delete();
                       break;
                case 3:display();
                       break;
                case 4:return;
                default : printf("\n Invalid Choice \n");
            }// end of switch
       } // end of menu loop
} //end of main
