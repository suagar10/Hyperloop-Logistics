#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 16

int G[14][14];
int finpath[14]; 
int k=0;

void dijkstra(int G[14][14],int n,int startnode, int endnode);

int main()
{
	int i,j,n=14,u,v;
	printf("City Key: \n");
	printf("0 -> Delhi\n");
	printf("1 -> Kanpur\n");
	printf("2 -> Patna\n");
	printf("3 -> Kolkata\n");
	printf("4 -> Chennai\n");
	printf("5 -> Hyderabad\n");
	printf("6 -> Bangalore\n");
	printf("7 -> Trivandrum\n");
	printf("8 -> Mumbai\n");
	printf("9 -> Surat\n");
	printf("10 -> Ahmedabad\n");
	printf("11 -> Jaipur\n");
	printf("12 -> Bhopal\n");
	printf("13 -> Nagpur\n");
	int G[14][14] = {{0,5,0,0,0,0,0,0,14,0,0,0,0,0},
	             {0,0,0,10,0,0,0,0,0,0,11,0,6,0},
				 {0,6,0,0,0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,17,15,0,0,0,0,0,0,0,0},
				 {22,0,0,0,0,0,3,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,13,0,0,12,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0,0,14,0,0},
				 {0,0,0,0,8,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,7,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,13,20,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,3,0,7,0,0},
				 {0,0,0,0,0,0,0,0,0,0,0,0,11,0},
				 {0,0,0,0,0,0,0,0,8,0,0,0,0,6},
				 {0,0,10,0,0,0,0,0,8,0,0,0,0,0}};
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	printf("\nEnter the ending node:");
	scanf("%d",&v);
	dijkstra(G,n,u,v);
	
	//Knapsack part
	get();
    printf("\n The Sack is arranged in the order\n");
    sort();
    knapsack(0,0.0,0.0);
    show();
    getch();
	
	return 0;
}
 
void dijkstra(int G[14][14],int n,int startnode,int endnode)
{
 
	int cost[14][14],distance[14],pred[14];
	int visited[14],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	//print the path and distance of the given city route
	
			printf("\nDistance of node%d=%d",endnode,distance[endnode]);
			printf("\nPath=%d",endnode);
			finpath[k]=endnode;
			k=k+1;
			
			j=endnode;
			do
			{
				j=pred[j];
				printf("<-%d",j);
				finpath[k]=j;
				k=k+1;
			}while(j!=startnode);
}

int w[40],i,j,p[40],q;
int n,m;
float unit[40];
int y[40],x[40],fp=-1,fw;
void get()
{
printf("\n\n\t Cargo Details \n");
printf("Maximum capacity of our Hyperloop carriage is 15 tonnes\n");
n=k;
m=15;
int pr,flag=0,kk;
for(i=0;i<n;i++)
   {
   printf("\n Enter the weight of the item %d : ",i+1);
   scanf("%d",&w[i]);
   printf("\n Enter the profit of the item %d : ", i+1);
   scanf("%d", &p[i]);
   printf("Does this city have priority? (0/1)");
   scanf("%d",&pr);
   if(pr==1)
   {
   	p[i]+=100;
   }
}
}
 
void show()
{
float s=0.0;
printf("\n\tItem\tWeight\tCost\tUnit Profit\tSelected ");
for(i=0;i<n;i++)
printf("\n\t%d\t%d\t%d\t%f\t%d",i+1,w[i],p[i],unit[i],x[i]);
printf("\n\n The Sack now holds following items : ");
for(i=0;i<n;i++)
if(x[i]==1)
   {
   printf("%d  ",i+1);
   s += (float) p[i] * (float) x[i];
   }
 
printf("\n Maximum Profit: %f ",s);
}
 
/*Arrange the item based on high profit per Unit*/
void sort()
{
int t,t1;
float t2;
for(i=0;i<n;i++)
unit[i] = (float) p[i] / (float) w[i];
for(i=0;i<n-1;i++)
   {
   for(j=i+1;j<n;j++)
      {
      if(unit[i]  < unit[j])
         {
         t2 = unit[i];
         unit[i] = unit[j];
         unit[j] = t2;
         t = p[i];
         p[i] = p[j];
         p[j] = t;
         t1 = w[i];
         w[i] = w[j];
         w[j] =t1;
         }
      }
    }
}
 
float bound(float cp,float cw,int k)
{
float b = cp;
float c = cw;
for(i=k;i<=n;i++)
{
   c = c+w[i];
   if( c < m)
      b = b +p[i];
   else
   return (b+(1-(c-m)/ (float)w[i])*p[i]);
}
return b;
}
 
void knapsack(int k,float cp,float cw)
{
 if(cw+w[k] <= m)
   {
   y[k] = 1;
   if(k <= n)
      knapsack(k+1,cp+p[k],cw+w[k]);
   if(((cp+p[k]) > fp) && ( k == n))
      {
      fp = cp+p[k];
      fw = cw+w[k];
      for(j=0;j<=k;j++)
      x[j] = y[j];
      }
    }
if(bound(cp,cw,k) >= fp)
{
 y[k] = 0;
 if( k <= n)
 knapsack(k+1,cp,cw);
 if((cp > fp) && (k == n))
   {
   fp = cp;
   fw = cw;
   for(j=0;j<=k;j++)
   x[j] = y[j];
   }
}
}
