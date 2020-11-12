/*9. Design, Develop and Implement a Program in C for the following operations on Singly Circular
Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in
POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operation */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 struct node // polynomial node
{
	int coef;
	int x,y,z;
   	struct node  *link;
};
typedef struct  node *NODE;

NODE getnode() // create a node
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
} // end of getnode

NODE readpoly()
{
	NODE temp,head,cur;
   	char ch;
  	head=getnode(); // create a head node and set all values to -1 it is similar to FIRST in SLL program
   	head->coef=-1;
   	head->x=-1;
	head->y=-1;
	head->z=-1;
   	head->link=head; // self reference
   	do
	{
      		temp=getnode(); // create a polynomial node
      		printf("\nEnter the coefficient and exponent in decreasing order\n");
      		scanf("%d%d%d%d",&temp->coef,&temp->x,&temp->y,&temp->z );
      		cur=head;
      		while(cur->link!=head) // find the last node
	    			cur=cur->link;
      		cur->link=temp; // connect new node to the last node
      		temp->link=head; // point back to head
      		printf("\nDo you want to enter more coefficients(y/n)");
		fflush(stdin); // to clear the stdin buffer
 		scanf("%c",&ch);
     	} while(ch =='y' || ch == 'Y');
      	return  head; // return the polynomial list
} // end of readpoly

int compare(NODE a,NODE b) // function to compare the A and B polynomial nodes
{
	if(a->x > b->x)
       		return 1;
	else if(a->x < b->x)
		return -1;
    	else if(a->y > b->y)
       		return 1;
	else if(a->y < b->y)
		return -1;
	else if(a->z > b->z)
		return 1;
	else if(a->z < b->z)
		return -1;
       		return 0;
} // end of compare

void attach(int cf,int x1,int y1, int z1, NODE *ptr) // function to attach the A and B polynomial node to C Polynomial
{
        NODE temp;
        temp=getnode();
        temp->coef=cf;
        temp->x=x1;
        temp->y=y1;
        temp->z=z1;
        (*ptr)->link=temp;
        *ptr=temp;
} // end of attach

NODE addpoly(NODE a,NODE b) // function to add polynomial A and B i.e, C=A+B
{
	NODE  starta,c ,lastc;
     	int sum,done=0;
     	starta=a;
     	a=a->link;
     	b=b->link;
     	c=getnode(); // create list C to store A+B
     	c->coef=-1;
     	c->x=-1;
     	c->y=-1;
     	c->z=-1;
     	lastc=c;
     	do{
            switch(compare(a,b))
            {
                case -1:attach(b->coef,b->x,b->y,b->z,&lastc);
                    b=b->link;
                    break;
                case 0:if(starta==a) done=1;
                    else{
                        sum=a->coef+b->coef;
                    if(sum)
                        attach(sum,a->x, a->y,a->z,&lastc);
                        a=a->link;b=b->link;
                           }
                    break;
                case 1:  if(starta==a) done=1;
                    attach(a->coef,a->x, a->y,a->z,&lastc);
                    a=a->link;
                    break;
            }
      	}while(!done); // repeate until not done
      	lastc->link=c; // point back to head of C
      	return c; // return answer
      }

 void print(NODE ptr) // to print the polynomial
 {
 	NODE cur;
      	cur=ptr->link;
      	while(cur!=ptr) // To print from HEAD node till END node
      	{
			printf("%d*x^%d*y^%d*z^%d",cur->coef,cur->x, cur->y, cur->z);
			cur=cur->link; // move to next node
			if (cur!=ptr)
                		printf(" + ");
		}
    } // end of print

 void evaluate(NODE ptr) // function to evaluate the final polynomial
 {
 	int res=0;
 	int x,y,z, ex,ey,ez,cof;
  	NODE cur;
  	printf("\nEnter the values of x, y,z"); // read values of X, Y and Z
 	scanf("%d", &x);
 	scanf("%d", &y);
 	scanf("%d", &z);
    cur=ptr->link; // start with HEAD
    while(cur!=ptr) // Repeat until the end of list
      	{
			ex=cur->x; // exponent of x
			ey=cur->y; // exponent of y
			ez=cur->z; // exponent of z
			cof=cur->coef; // coefficient
			res+=cof*pow(x,ex)*pow(y,ey)*pow(z,ez); // compute result for each polynomial
			cur=cur->link; // move to next node
		}
	printf("\nresult: %d",res);
} // end of evaluate

void main(void)
{
	int i, ch;
   	NODE a=NULL,b,c;
   	while(1)
    {
 		printf("\n1: Represent first polynomial A");
		printf("\n2: Represent Second polynomial B");
		printf("\n3: Display the polynomial A");
		printf("\n4: Display the polynomial B");
		printf("\n5: Add A & B polynomials"); // C=A+B
		printf("\n6: Evaluate polynomial C");
		printf("\n7: Exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		  	case 1: printf("\nEnter the elements of the polynomial A");
					a=readpoly();
					break;
			case 2:printf("\nEnter the elements of the polynomial B");
				  	b= readpoly();
					break;
			case 3:	print(a); // display polynomial A
				break;
			case 4:print(b); // display polynomial A
				break;
            case 5: c=addpoly(a,b); // C=A+B
					printf("\nThe sum of two polynomials is: ");
					print(c); // display polynomial C
					printf("\n");
					break;
			case 6:evaluate(c); // Evaluate polynomial C
                    break;
			case 7: return;
			default: printf("\nInvalid choice!\n");
		} //end of switch
	} // end of while
} // end of main
