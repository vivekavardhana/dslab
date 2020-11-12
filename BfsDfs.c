/* 11. Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS method.*/

#include<stdio.h>

int a[20][20], q[20], visited[20];
int n, i, j, f=0, r=-1;

void create_graph() // Create the Digraph using Adjacency matrix
{
    printf("\n Enter the number of cities: ");
                    scanf("%d",&n);
                    printf("\n Enter graph data in matrix form:\n");
                    for(i=1;i<=n;i++)
                        for(j=1;j<=n;j++)
                            scanf("%d",&a[i][j]); // read adjacency matrix
    return;
}

void bfs(int v) // Reachability using Breadth First Search
{
	for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i]) // check weather node is visited
            q[++r]=i; // if not add it Queue
    if(f<=r) // check for non empty Queue
	{
		visited[q[f]]=1; // set visited status for front node of Queue
		bfs(q[f++]); // recursive call BSF
	}
}// end of BSF

void main()
{
	int v, choice;
	while(1)
	{
        printf("\n1. Create a Digraph of N cities using Adjacency Matrix");
        printf("\n2. Print all the nodes reachable from a given starting node in a digraph using BFS method") ;
        printf("\n3. Exit");
        printf("\n Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:	create_graph();
                    break;

            case 2: printf("Enter the source vertex: ");
                    scanf("%d",&v);
                    if((v<1)||(v>n)) // check for valid source entry
                        printf("\nEnter a valid source vertex");
                     else // if valid begin test for reachability
                     {
                      for(i=1;i<=n;i++) // begin with assuming all cities are not visited
                            visited[i]=0;
                       visited[v]=1; // source is visited
                       bfs(v); // cal BFS to check reachability
                       printf("The reachable nodes from node %d:\n",v);
                       for(i=1;i<=n;i++) // display reachable cities from the source city
                        if(visited[i] &&  i !=v)
                                printf("node %d\n",i);
                     }
                    break;
            case 3:return;
            default:printf("\nInvalid Choice");
        } // end of switch
	} // end of while
} // end of main
