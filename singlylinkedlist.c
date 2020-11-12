/*7. Design, Develop and Implement a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL (Demonstration of stack)
e. Exit .
*/

#include<stdio.h>
#include<stdlib.h>

//NODE for singly linked list
struct node
{
 char usn[20],name[10],branch[5];
 unsigned long long int phno;
 int sem;
 struct node *link; // link for node of type node
};

typedef struct node * NODE;
NODE temp,FIRST=NULL;

// function to create a node
NODE getnode()
{
 NODE x;
 x=(NODE)malloc(sizeof(struct node)); //Dynamic memory allocation for NODE
 x->link=NULL; //by node default link is set to NULL to avoid dangling pointer
return x;
}

//Function to read linked list node information
void read()
{
 temp=getnode();
 printf("Enter USN: ");
 scanf("%s",temp->usn);
 printf("Enter NAME: ");
 scanf("%s",temp->name);
 printf("Enter Branch: ");
 scanf("%s",temp->branch);
 printf("Enter phone Number: ");
 scanf("%llu",&temp->phno);
 printf("Enter Semester: ");
 scanf("%d",&temp->sem);
}

// Create a SLL of N Students Data by using front insertion
void create_SSL()
{
 int n,i;
 printf("Enter the number of students: ");
 scanf("%d",&n);
 for(i=1;i<=n;i++) // read in student details
 {
  printf("\n Enter the details of %d students\n",i);
  read(); // call read() to read student details
  if(FIRST==NULL) // check for empty list
        FIRST=temp; // if true set new node as FIRST node of list
  else{
        temp->link=FIRST; // otherwise link the old node to new node
        FIRST=temp; // make new node as FIRST (INSERT FRONT)
      }
  }
}

//Display the status of SLL and count the number of nodes in it
void display_count()
{
 int count=1;
 temp=FIRST;
 printf("Student details:\n");
 if(FIRST==NULL) // check for empty list
    printf("Student detail is NULL and count is 0\n");
 else
    {
      printf("\nUSN\tNAME\tBRANCH\tPHNO\tSEMESTER\n");
      while(temp->link!=NULL) // iterate nodes of SLL until end node
      {
        count++;
        printf("%s\t%s\t%s\t%llu\t%d\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
        temp=temp->link; // next node
      }
printf("%s\t%s\t%s\t%llu\t%d",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
 printf("\n Student count is %d\n",count);
    }
  return;
}

// Perform Insertion at front of SLL
void insert_front()
{
 printf("Enter the details of student\n");
 read();
 if(FIRST==NULL)
    FIRST=temp;
 else{
      temp->link=FIRST;
      FIRST=temp;
     }
}
// Perform Insertion at End of SLL
NODE insert_end()
{
 NODE last=FIRST;
 printf("Enter the details of student\n");
 read();
 if(FIRST==NULL)
    FIRST=temp;
 else
      {
       while(last->link!=NULL) // find last node iteratively
            last=last->link;
       last->link=temp; // connect new node to last node link
      }
  return FIRST;
}

// Perform Deletion at front of SLL
void delete_front()
{
 temp=FIRST;
 if(FIRST==NULL) // Check for empty list
    printf("List is empty\n");
 else
    {
     printf("deleted element is %s\n",temp->usn);
     FIRST=FIRST->link; //set 2nd node as FIRST node
     free(temp); // delete previous 1st node
    }
 return;
}

// Perform Deletion at End of SLL
void delete_end()
{
 NODE last=NULL;
 temp=FIRST;
 if(FIRST==NULL) // Check for empty list
    printf("List is empty\n");
 else if(FIRST->link==NULL) // // Check for single node in SLL
       {
        printf("Deleted element is %s\n",temp->usn);
        free(FIRST);
        FIRST=NULL;
       }
      else
        {
            while(temp->link!=NULL)
            {
             last=temp;
             temp=temp->link;
            }
           last->link=NULL;
           printf("Deleted element is %s\n",temp->usn);
           free(temp); // delete last node
           }
       return;
}


void main()
{
 int choice;
 while(1)
 {
  printf("\n1. Create SSL\n2.Display SSL\n3.Insert front\n4.Insert end\n5.Delete front\n6.Delete end\n7.EXIT\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:create_SSL();
          break;
   case 2:display_count();
          break;
   case 3:insert_front();
          break;
   case 4:insert_end();
          break;
   case 5:delete_front();
          break;
   case 6:delete_end();
          break;
   case 7:return;
   default:printf("\nInvalid choice\n");
  }
 }
}
