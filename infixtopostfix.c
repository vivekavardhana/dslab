/*4.Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix Expression.
Program should support for both parenthesized and free parenthesized expressions with the operators:
+, -, *, /, %(Remainder), ^(Power) and alphanumeric operands. */

#include<stdio.h>
void infix_to_postfix();
void push(char);
char pop();
int priority(char);
char infix[30], postfix[30],stack[30];
int top=-1;

void main()
{
	printf("Enter the valid Infix expression \n");
	scanf("%s",infix);
	infix_to_postfix();
	printf("\n Infix expression : %s",infix);
	printf("\n Postfix expression : %s\n",postfix);
}

// push symbol to stack
void push(char item)
{
	stack[++top]=item;
} // end of function push

// pop symbol from stack
char pop()
{
	return stack[top--];
} //  end of function pop

// check the priority of operator
int priority(char symb)
{
	int p;
	switch(symb)
	{
		case '+':
		case '-':	p=1;
                    break;
		case '*':
		case '/':
		case '%': 	p=2;
                    break;
		case '^':
		case '$':	p=3;
                    break;
		case '(':
		case ')':	p=0;
                    break;
		case '#': 	p=-1;
                    break;
	} // end of switch
	return p;
} // end of function priority

//converting an Infix Expression to Postfix Expression
void infix_to_postfix()
{
	int i=0,j=0;
	char symb,temp;
	push('#');
	for(i=0;infix[i]!='\0';i++)
	{
		symb=infix[i];
		switch(symb)
		{
			case '(': push(symb); // push all symbols inside the ( to top of stack
                         break;
			case ')': temp=pop(); //pop symbol from top of stack
                      while(temp!='(') //pop all symbols from top of stack and store in postfix until (
                        {
                            postfix[j++]=temp;
                            temp=pop();
                        } // end of while
                        break;
			case'+':
			case'-':
			case'*':
			case'/':
			case'%':
			case'^':
            case'$': while(priority(stack[top])>=priority(symb)) // check for priority of operator
                        {
                            temp=pop();
                            postfix[j++]=temp;
                        }
					push(symb);
					break;
			default: postfix[j++]=symb;
            } // end of switch
		} // end of for
		while(top>0) // pop remaining all symbols form top of stack and store to postfix
		{
			temp=pop();
			postfix[j++]=temp;
        } // end of while
		postfix[j]='\0'; // end string postfix
	} // end of function infix_to_postfix
