/*1Q. Design, Develop and Implement a menu driven Program in C for the following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.
Support the program with functions for each of the above operations. */


//Required Header files
#include<stdio.h>

// Global Declaration
int a[20];
int n,elem,i,pos;

// Function declaration or Prototype
void create();
void display();
void insert();
void delete();

// main function to drive to program
void main()
{
 int choice;
 while(1) // infinite loop
     {
       // menu options
       printf("\n MENU \n");
       printf("1.CREATE\n");
       printf("2.DISPLAY\n");
       printf("3.INSERT\n");
       printf("4.DELETE\n");
       printf("5.EXIT\n");

        // read choice
       printf("Enter your choice\n");
       scanf("%d",&choice);

       switch(choice)
       {
         case 1:create();
                break;

         case 2:display();
                break;

         case 3:insert();
                 break;

         case 4:delete();
                 break;

         case 5:return;

         default:printf("\n Invalid choice\n");
        } // end of switch
     } // end of infinite while loop
} // end of main

// a. Creating an Array of N Integer Elements
void create()
{
 printf("\nEnter the size of the array elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements of the array\n");
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}

//b. Display of Array Elements with Suitable Headings
void display()
{
 printf("\n The array elements are:\n");
 for(i=0;i<n;i++)
      printf("a[%d] = %d\n",i, a[i]);
}

// c. Inserting an Element (ELEM) at a given valid Position (POS)
void insert()
{
 printf("\nEnter the position for the new element\n");
 scanf("%d",&pos);
 // check for invalid position
 if(pos>=n+1)
  printf("Insertion not possible\n");
 else
    {
     printf("\n Enter the element to be inserted:\t");
     scanf("%d",&elem);
     for(i=n-1;i>=pos;i--)
           a[i+1]=a[i]; // right shift elements before insertion
    a[pos]=elem; // insert element
    n++; // increase number of elements by 1
    }
}

//d. Deleting an Element at a given valid Position(POS)
void delete()
{
 printf("\n Enter the position of the element to be deleted\n");
 scanf("%d",&pos);
 if(pos>=n+1)
  printf("Deletion not possible");
 else
    {
     printf("\n The deleted element is %d",a[pos]); // display the deleting element at the given position
     for(i=pos;i<n-1;i++)
           a[i]=a[i+1]; // left shift elements after deletion
     n--; // reduce number of elements by 1
    }
}
