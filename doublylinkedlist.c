/*8. Design, Develop and Implement a menu driven Program in C for the following operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit.  */

#include<stdio.h>
struct node // structure to store employee details
{
	char ssn[12],name[20],dept[25],desig[20];
	unsigned long long int phno;
	float sal;
	struct node *prev;
	struct node *next;
};
typedef struct node *NODE; // renaming node as NODE

NODE temp, FIRST=NULL,END=NULL;

NODE getnode() // Create node
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
    x->prev=NULL;
	x->next=NULL;
	return x;
}


void read() // read details of employee
{
	temp=getnode();
	printf("Enter SSN:");
	scanf("%s",temp->ssn);
	printf("Enter Name:");
	scanf("%s",temp->name);
	printf("Enter Dept:");
	scanf("%s",temp->dept);
	printf("Enter Designation:");
    scanf("%s",temp->desig);
	printf("Enter Phno:");
	scanf("%llu",&temp->phno);
	printf("Enter Salary:");
	scanf("%f",&temp->sal);
	return;
}

void Create_DLL() // Create a DLL of N Employees Data by using end insertion.
{
	int n,i=1;
	printf("Enter the number of Employees \n");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("Enter the details of the %d employee\n", i++);
		read();
		if(FIRST==NULL) // if empty list new node will be the first node
		{
			FIRST=temp;
			END=temp;
		}
		else //otherwise find the last node and insert the new node
		{
			END->next=temp;
			temp->prev=END;
			END=temp;
		}
	} //e nd of while
} // end of create()


void display_count() //Display the status of DLL and count the number of nodes in it
{
	temp=FIRST;
	int count=0;

	if(FIRST==NULL) // check for empty list
		printf("the Employee detail is NULL and count is %d\n", count);
    else
	{
		printf("Employee details:\n");
		printf("SSN \t EMPLOYEE NAME \t DEPARTMENT \t DESIGNATION \t PHONE NUMBER \t SALARY");
		while(temp!=NULL) // display all nodes in the list
		{
			count++;
			printf("\n%s\t%s\t%s\t%s\t%llu\t%0.2f",temp->ssn, temp->name, temp->dept,temp->desig,temp->phno,temp->sal);
			temp=temp->next;
		 }
        printf("\n Employee count is %d\n",count);
	} // end of else
return;
} // end of display()

void  Insertionfront() //Perform Insertion at front of DLL
{
	printf("Enter the details of the employee\n");
	read();
	if(FIRST==NULL) // if empty list new node will be the first node
		{
			FIRST=temp;
			END=temp;
		}
	else // otherwise insert the new node at front
	{
		temp->next=FIRST;
		FIRST->prev=temp;
		FIRST=temp;
	}
} // end of insert front

void Insertionend() //Perform Insertion at End of DLL
{
	printf("Enter the details of the new employee\n");
	read();
	if(FIRST==NULL) // check for empty list
	{
		FIRST=temp;
		END=temp;
	}
	else // otherwise find the last node and insert the new node
	{
		END->next=temp;
		temp->prev=END;
		END=temp;
	}
	return ;
} // end of insert end

void Deletionfront() //Delete node from front of DLL
{
	temp=FIRST;
	if(FIRST==NULL) // check for empty list
			printf("List is empty\n");
	else if(FIRST==END) // otherwise check for single node in list
	{
		printf("deleted element is %s\n", temp->ssn);
		FIRST=NULL;
		END=NULL;
		free(temp);
	}
    else // otherwise delete node from front of DLL
	{
		printf("deleted element is %s\n", temp->ssn);
		FIRST =FIRST->next;
		FIRST->prev=NULL;
		free(temp);
	}
	return;
} // end of deletefront

void Deletionend() // delete node at end of DLL
{
	temp = END;
	if(FIRST==NULL) // check for empty list
        printf("List is empty\n");
	else if(FIRST==END) // otherwise check for single node in list
	{
		printf("deleted element is %s\n", temp->ssn);
		FIRST=NULL;
		END=NULL;
		free(temp);
	}
	else // otherwise delete end node from DLL
	{
		printf("deleted element is %s\n", temp->ssn);
		END=END->prev;
		END->next=NULL;
		free(temp);
	}
	return ;
} // end of deletionend

void main()
{
	int choice;
	while(1)
	{
		printf(" \n 1 - Create DLL of N Employees \n 2 - Display DLL \n 3 - Insertion at front \n 4 - Insertion at end");
		printf("\n 5 - Deletion at front \n 6 - Deletion  at end \n 7 - Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
		 switch(choice)
		 {
			 case 1 : Create_DLL();
                    break;
			 case 2 : display_count();
                    break;
			 case 3 : Insertionfront();
                    break;
			 case 4 : Insertionend();
                    break;
			 case 5 : Deletionfront();
                    break;
			 case 6 : Deletionend();
                    break;
			 case 7 : return;
			 default: printf("Invalid Choice\n");
		 } //end of switch
	} // end of while
} // end of main
