/* 5.Design, Develop and Implement a Program in C for the following Stack Applications
   a. Evaluation of postfix expression with single digit operands and operators: +, -, *, /, %, ^
   b. Solving Tower of Hanoi problem with N disks
*/

#include<stdio.h>
#include<math.h>
void push(float);
float pop();
void evaluate(char[]);
float stack[20];
int top=-1;

void main()
{
	int choice,n;
	char postfix[100];
	while(1) // infinate loop for menu
	{
           printf("\n STACK APPLICATIONS");
	   printf("\n Enter your Choice: ");
           printf("\n 1. Evaluation of postfix expression with single digit operands and operators");
           printf("\n 2. Solving Tower of Hanoi problem with N disks");
           printf("\n 3. Exit \n");
           scanf("%d", &choice);
        switch(choice)
        {
            case 1 : printf("Enter a valid postfix expression\n");
                     scanf("%s",postfix);
                     evaluate(postfix);
                     break;
            case 2 :  printf("\n Enter the number of discs:\n");
                     scanf("%d",&n);
                     tower(n,'A','C','B');
                     printf("\n Total number of moves are %d",(int)pow(2,n)-1);
                     break;
            case 3 : return;
            default : printf("\n Invalid Choice");
        } // end of switch
	} // end of menu
} // end of main

// push item to stack
void push(float item)
{
	stack[++top]=item;
} // end of push

// pop item from stack
float pop()
{
	return stack[top--];
} // end of pop

// function to postfix expression with single digit operands and operators: +, -, *, /, %, ^
void evaluate(char postfix[100])
{
    int i;
    float op1, op2, res;
    char symb;
	for(i=0;postfix[i]!='\0';i++) // repeate until end of string
	{
		symb=postfix[i];
		if(isdigit(symb)) // check for digit or not
			push(symb-'0'); // if digit push to top of stack -'0' is for ascii to number conversion
		switch(symb)
		{
            case '+':op2=pop();
                     op1=pop();
                     res=op1+op2;
                     push(res);
                     break;
            case '-':op2=pop();
                     op1=pop();
                     res=op1-op2;
                     push(res);
                     break;
            case '*':op2=pop();
                     op1=pop();
                     res=op1*op2;
                     push(res);
                    break;
            case '/':op2=pop();
                     op1=pop();
                     if(op2==0)
                        {
                            printf("Division by zero Error\n");
                            return;
                        }
                    res=op1/op2;
                    push(res);
                    break;
            case '%': op2=pop();
                      op1=pop();
                    if(op2==0)
                        {
                            printf("Division by zero Error\n");
                            return;
                        }
                     res=(int)op1%(int)op2; // typecast operands to int because % supports only int operands
                     push(res);
                     break;
            case '^':op2=pop();
                     op1=pop();
                     res=pow(op1,op2);
                     push(res);
                     break;
			}// end of switch
		} // end of for
	res=pop(); // pop the final answer from top of stack
	if(top==-1) // Check for empty stack, If true then its valid postfix expression
        printf("\n Result: %f\n ",res); // Display the final answer
    else
    { //otherwise invalid postfix expression
       printf("\nINVALID POSTFIX EXPRESSION\n");
       top=-1; //reset top to -1
    }

} // end of evaluate function

// Recursive function for Solving Tower of Hanoi problem with N disks
void tower(int n,int source,int destination,int aux)
{
     if(n==0)
        return;
     tower(n-1,source,aux,destination);
     printf("\n Move disc %d from %c to %c",n,source,destination);
     tower(n-1,aux,destination,source);
} // end of tower function
