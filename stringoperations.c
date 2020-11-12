/*  Design, Develop and Implement a Program in C for the following operations on Strings
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. Report suitable messages in case
PAT does not exist in STR
Support the program with functions for each of the above operations. Don't use Built-in functions.  */


#include<stdio.h>

// user defined parameterized functions prototype
int length(char[]);
int match(char[], char[], int, int);
int compare(char[], char[]);


// main ( ) to drive the code
void main()
{

// local declarations
   char str[100], pat[100], rep[100], t[100], d[100];
	int ls, lp, lr;
	int i, j, l, l1=0, k=0;

// Read strings
	printf("\n Enter main String :");
	gets(str);
	printf("\n Enter pattern String :");
	gets(pat);
	printf("\n Enter Replace String :");
	gets(rep);

// find the length of strings
    ls = length(str);
    lp = length(pat);
    lr = length(rep);

// check weather pattern matches or not
    if (ls < lp || !match(str, pat, ls, lp))
          printf("\n Pattern Not found!!!!\n");
    else // if pattern matches
        {
        // Replaces all occurrences of pattern in string
            for (i=0;i<ls;i++) // loop for the size of main string
                {
                    for(j=0; j<lp; j++) // copy the first chunk form main string of pattern length
                        t[j]=str[i+j]; // store in temporary string
                    t[j]='\0'; // end the temporary string
                    if (compare(t,pat)==0) // compare temporary string with pattern string
                    {
                        k++; // count number of replaces
                        for(l=0;l<lr;l++)
                            d[l1++]=rep[l];
                    i=i+(lp-1);
                    }
                    else
                     d[l1++]=str[i];
                }
        d[l1]='\0'; // end of destination string

// display the results
        printf("\n The number of string replaced =%d \n", k);
        printf("\n Original String =%s \n", str);
        printf("\n Pattern String =%s \n", pat);
        printf("\n Replace String =%s \n", rep);
        printf("\n String after replacement =%s \n", d);
    }
}

// function to find the length of string
int length(char str[])
{
    int i, len =0;
    for (i = 0; str[i] != '\0'; i++)
         len++;
    return len;
}

// function to compare two strings
int compare(char str1[],char str2[])
{
  int i=0;
  while (str1[i] == str2[i] && str1[i] != '\0')
      i++;
   if (str1[i] > str2[i])
      return 1;
   else if (str1[i] < str2[i])
      return -1;
   else
      return 0; // both strings are same
 }

// function to match pattern string in given string
int match(char text[], char pattern[], int ls, int lp)
{
  int c, d, e;

  for (c = 0; c <= ls - lp; c++) {
    e = c;

    for (d = 0; d < lp; d++)
        {
          if (pattern[d] == text[e])
            e++;
          else
            break;
        }
    if (d == lp)
      return 1; // return 1 if there is a pattern match
  }
return 0; // return 0 if pattern does not found
}
