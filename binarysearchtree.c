/* 10 . Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in In-order, Pre-order and Post-order
c. Search the BST for a given element (KEY) and report the appropriate message
e. Exit. */

#include<stdio.h>
struct node // DLL node for Tree with left_link value and right_link
{
	int value;
	struct node *ltree;
	struct node *rtree;
};
typedef struct node* NODE;

NODE getnode() // create a node
{
	NODE x;
	x=(NODE) malloc (sizeof(struct node));
    x->ltree=NULL;
    x->rtree=NULL;
	return x;
} // end of getnode

NODE create(int item, NODE root) // create a  BST for the given values
{
	NODE temp,cur,prev;
	int i;
	temp=getnode(); // create node
	temp->value=item; // store value
	if(root==NULL) // if empty tree then new node itself is ROOT of BST
	{
		root=temp;
		return root;
	}
	else // otherwise add new node to BST
	{
		prev=NULL;
		cur=root;
		while (cur!=NULL) // find the leaf node
		{
			prev=cur;
			cur=(temp->value<cur->value)?cur->ltree:cur->rtree; // condition to choose left or right subtree
		}
		if(temp->value<prev->value) // if new node smaller than ROOT then make it as left child
			prev->ltree=temp;
		else if(temp->value>prev->value) // otherwise if new node greater than ROOT then make it as right child
			prev->rtree=temp;
		}
		return root;
}

void in(NODE IN) // Recursive INORDER traversal function
{
	if(IN!=NULL) // if tree is not empty then traverse
	{
		in(IN->ltree); // left child
		printf("%d\t",IN->value); // Root
		in(IN->rtree); //right child
	}
}

void pre(NODE PRE)  // Recursive PREORDER traversal function
{
	if(PRE!=NULL) // if tree is not empty then traverse
	{
		printf("%d\t",PRE->value); // Root
		pre(PRE->ltree); // left child
		pre(PRE->rtree); //right child
	}
}

void post(NODE POST) // Recursive POSTORDER traversal function
{
	if(POST!=NULL) // if tree is not empty then traverse
	{
		post(POST->ltree); // left child
		post(POST->rtree); //right child
		printf("%d\t",POST->value); // Root
	}
}

void search(NODE root) // Binary Search on BST for given Key element
{
	int item, found=0;
	NODE cur;
	printf("enter the element to be searched\n");
	scanf("%d",&item); // read key
	if(root==NULL) // check for empty tree
	{
		printf("tree is empty\n");
		return;
	}
	// for non-empty tree search for key in BST
	cur=root;
	while(cur!=NULL) // repeat until end
	{
		if(item==cur->value) // check key and root value is same SUCESSFULL SEARCH
		{
			found = 1; // set flag
			printf("Found key %d in tree\n",cur->value);
		}
		if(item<cur->value) // check key is greater than root value then choose right subtree
			cur=cur->ltree;
		else // otherwise choose left subtree
			cur=cur->rtree;
	} // end of while

	if(found==0) // if found flag is Zero then UNSUCESSFULL SEARCH
		printf("Key not found\n");
} // end of search

void main()
{
	int choice, item, n, i;
	NODE root=NULL;
	while(1)
	{
		 printf("\n1. Create BST of N Integers");
		 printf("\n2. BST Traversal");
		 printf("\n3. Binary Search");
		 printf("\n4. Exit");
		 printf("\nEnter Your Choice: ");
		 scanf("%d",&choice);
		 switch(choice)
		 {
			  case 1:   printf("\n Enter number elements : ");
                        scanf("%d",&n);
                        for (i =0; i<n; i++)
                        {
                            printf("Enter the item to be inserted\n");
                            scanf("%d",&item);
                            root=create(item,root);
                        }
                        break;
			  case 2:   if(root==NULL) // check for empty tree
                            printf("Tree is empty\n");
                        else
                        {   // for non-empty tree traverse BST
                            printf("\n\nPREORDER traversal\n");
                            pre(root);
                            printf("\n\nINORDER traversal\n");
                            in(root);
                            printf("\n\nPOSTORDER traversal\n");
                            post(root);
                        }
                        break;
			  case 3:   search(root);
                        break;
			  case 4:   return;
			  default:  printf("\n Invalid Choice\n");
		 } // end of switch
	} // end of while
} // end of main
