/* 12. Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine the records in file F.
Assume that file F is maintained in memory by a Hash Table(HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are Integers.
Design and develop a Program in C that uses Hash function H: K -->L as H(K)=K mod m (remainder method),
and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) using linear probing. */
#include <stdio.h>
#define MAX 10

void linear_prob(int a[MAX])
{
	int flag, key, i, addrs, count;
	char  ans;
	do
	{
    flag=0;
    count=0;
	printf("\n Enter 4 digit Key : ");
	scanf("%4d", &key); // read a key
	addrs=key%10; // generate single digit key for given key
	if(a[addrs]== -1) // check for empty entry in Hash table
		a[addrs] = key; // if yes the add to HT
	else // if entry exits then avoid collision
	{
		printf("\nCollision Detected...!!!\n");
		i=0;
		while(i<MAX) // check for next available empty location in HT
		{
			if (a[i]!=-1)
                count++; // count empty location in HT
			i++;
		} // end of while
		if(count == MAX) // if HT is full then display HT and return
		{
			printf("\n Hash table is full \n");
			display(a); // Display HT
			return;
		} // end of if
        printf("\nCollision avoided successfully using LINEAR PROBING\n");
		for(i=addrs+1; i<MAX; i++) // if there is empty space after key in HT then make a entry in HT
			if(a[i] == -1)
			{
				a[i] = key;
				flag =1;
				break;
			} // end of if
		i=0;
		while((i<addrs) && (flag==0)) // check for empty space before key in HT then make a entry in HT
		{
			if(a[i] == -1)
			{
				a[i] = key;
				flag=1;
				break;
			} // end of if
			i++;
		} // end of while
	} // end of else
	printf("\n Do you wish to continue ? (y/n) ");
	fflush(stdin);
	scanf("%c",&ans);
	} while(ans=='y' || ans == 'Y') ;// end of  do while
} // end of linear probe

void display(int a[MAX]) // display the HT
{
      int i;
      printf("\n the HASH TABLE is\n Addrs \t Key");
      for(i=0; i<MAX; i++)
            printf("\n %d \t %d ", i, a[i]);
}// end of display

void main()
    {
        int a[MAX], i, choice;
        for (i=0;i<MAX;i++) // initialize HT with no entries
            a[i] = -1;
        while(1)
            {
                printf("\n Collision handling by Linear Probing ");
                printf("\n1. Insert into Hash table");
                printf("\n2. Display Hash table");
                printf("\n3. Exit");
                printf("\n Enter your Choice : ");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1:	linear_prob(a);
                            break;
                    case 2:	display(a);
                            break;
                    case 3: return;
                    default: printf("\n Invalid Choice");
                } // end of switch
            } // end of while
   } // end of main
