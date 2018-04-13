/*
Assignment no. Group B-11
Title: You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.
Roll No. :05					Class: SE-A
***************************************************************/

#include<iostream>
using namespace std;
class node						//Class node
{
      public:
      char v1,v2;
      int wt;
     
};

class MST						//MST class
{
      public:
      node a[10],b[10];
      int Ecnt;
      int Rcnt;
      int cost;
      
           MST()
           {
              Ecnt=0;
              Rcnt=1;
            }
      void Readgraph();
      void kruskal();//By using kruskal's algorithm
      void Display(node x[10],int cnt);
};

void MST::Readgraph()			//Accept edges, vertex & weight of graph
{
            cout<<"\nHow many edges you want:";
            cin>>Ecnt;
            
            for(int i=1;i<=Ecnt;i++)
            {
                  cout<<"\nEnter start vertex:";
                  cin>>a[i].v1;
                  
                  cout<<"\nEnter end vertex:";
                  cin>>a[i].v2;
                  
                  cout<<"\nEnter weight of edges:";
                  cin>>a[i].wt;
             }
 }
 
 void MST::kruskal()			//Kruskals Method
 {
 		int flag=0;
 		cost=0;
 		b[Rcnt].v1=a[1].v1;
 		b[Rcnt].v2=a[1].v2;
 		b[Rcnt].wt=a[1].wt;
 		cost=cost+a[1].wt;
 		
 		for(int i=2;i<=Ecnt;i++)
 			{
 				flag=0;
 				for(int j=1;j<=Rcnt;j++)
 				{
 				
 				 	if(a[i].v1==b[j].v1||a[i].v1==b[j].v2)
 				 	{
 					flag++;
 					break;
 				}
 			}
 			for(int j=1;j<=Rcnt;j++)
 				{
 					if(a[i].v2==b[j].v1||a[i].v2==b[j].v2)
 					
 					{	
 						flag++;
 						break;
 					}
 				}
 					if(flag<2)
 						{
 							Rcnt++;
 							b[Rcnt].v1=a[i].v1;
 							b[Rcnt].v2=a[i].v2;
 							b[Rcnt].wt=a[i].wt;
 							cost=cost+b[Rcnt].wt;
 					}
 		   }
 }
 
 
 
 void MST::Display(node x[10],int cnt)		// To Display MST
 {
            cout<<"\nv1"<<"\tv2"<<"\tweight\n";
            cout<<"\n--------------------------------";
            for(int i=1;i<=cnt;i++)
            {
                  cout<<"\n"<<x[i].v1<<"\t"<<x[i].v2<<"\t"<<x[i].wt<<endl;
            }
}

int main()					//Main Function
{
      MST M;
     cout<<"\nEnter graph in ascending order\n";
      M.Readgraph(); 
      cout<<"\n***Graph is***:";
      M.Display(M.a,M.Ecnt);
      cout<<"\nMinimal Spanning tree is:";
      M.kruskal();
      M.Display(M.b,M.Rcnt);
      cout<<"\n\tCost of minimal spanning tree is: ";
      cout<<M.cost<<endl;
     return 0;
}

/*		output
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ mst1.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

           
Enter graph in ascending order

How many edges you want:5

Enter start vertex:a

Enter end vertex:c

Enter weight of edges:10

Enter start vertex:c

Enter end vertex:b

Enter weight of edges:20

Enter start vertex:a

Enter end vertex:b

Enter weight of edges:30

Enter start vertex:c

Enter end vertex:d

Enter weight of edges:40

Enter start vertex:b

Enter end vertex:d

Enter weight of edges:50

***Graph is***:
v1	v2	weight

--------------------------------
a	c	10

c	b	20

a	b	30

c	d	40

b	d	50

Minimal Spanning tree is:
v1	v2	weight

--------------------------------
a	c	10

c	b	20

c	d	40

Cost of minimal spanning tree is: 70
gescoe@gescoe-OptiPlex-3010:~/Desktop$ 
*/
