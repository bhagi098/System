/* Assignment No. Group B-9
Title: Write a function to get the number of vertices in an undirected
graph and its edges. You may assume that no edge is input twice. 
i.Use adjacency list representation of the graph and find runtime of the function 
ii.Use adjacency matrix representation of the graph and find runtime of the function.
***************************************************************/
#include<iostream>
using namespace std;

class node							// Node Declaration
{
	public:
	char data;
	node *next;
};	

class Graph							// Class Declaration
{
	node *x[10];
	int a[10][10];
	public:
		void accept();
		void display();
		void acceptlist();
		void displaylist();
		int vcount;
};

 void Graph::accept()					//Accept Matrix
{
	int i,j;
	cout<<"enter the size of matrix:";
	cin>>vcount;
	for(i=0;i<vcount;i++)
	{	
		for(j=0;j<vcount;j++)
		{
				cout<<"enter the value for edge 								between"<<i<<"and"<<j<<":";
				cin>>a[i][j];
		}
	}
}
	
void Graph::display()						//Display Matrix			
{
	int i,j;
	cout<<"the matrix is";
	for(i=0;i<vcount;i++)
	{	
		cout<<"\n";
		for(j=0;j<vcount;j++)
			{
				cout<<"\t";
				cout<<" "<<a[i][j];
			}
	}
}

void Graph::acceptlist()						//Accept List
{
	int count;
	node *temp,*head;
	cout<<"enter the no.of vertex";
	cin>>vcount;
	for(int i=0;i<vcount;i++)
	{
		x[i]=new node();
		cout<<"enter the value"<<i+1;
		cin>>x[i]->data;
		x[i]->next=NULL;
		head=x[i];
		cout<<"enter how many nodes are connected to vertex"<<x[i]->data<<":";
		cin>>count;
		for(int j=0;j<count;j++)
		{
			temp=new node();
			cout<<"enter the value:";
			cin>>temp->data;
			temp->next=NULL;
			head->next=temp;
			head=head->next;
		}
	}
}	

void Graph::displaylist()						//Display List
{
	node *temp;
	cout<<endl;
	for(int i=0;i<vcount;i++)
	{
		cout<<"\n";
		cout<<x[i]->data<<"--> \t";
		temp=x[i];
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<temp->data<<"-->";
		}
	}
	cout<<"NULL";
}			
		
int main()							//Main Function
{
 	Graph g;						// Class grpah object
 	int ch;
 	do
 	{
 		cout<<"\n.....MENU......";
 		cout<<"\n 1.accept adjacency matrix\n 2.display adjacency matrix\n 3.accept  adjacency list\n 4.display  adjacencyss list";
 		cout<<"\n enter your choice";
 		cin>>ch;
		switch(ch)
 		{
 			case 1:				//Accept adjacency matrix
				g.accept();
 				break;
 
			case 2: 				//Display adjacency matrix
				g.display();
 				break;
 
			case 3:				//Accept adjacency List
				g.acceptlist();
 				break;
 
			case 4:				//Display adjacency List
				g.displaylist();
 				break;
		}
 
 	}while(ch!=5);	
	return 0;
 }
 

/**********************OUTPUT***************************

gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ 4.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

.....MENU......
 1.accept adjacency matrix
 2.display adjacency matrix
 3.accept  adjacency list
 4.display  adjacencyss list
 enter your choice1
enter the size of matrix:3
enter the value for edge between 0 and 0 : 1
enter the value for edge between 0 and 1 : 1
enter the value for edge between 0 and 2: 0
enter the value for edge between 1 and 0 : 0
enter the value for edge between 1 and 1 : 1
enter the value for edge between 1 and 2 : 1
enter the value for edge between 2 and 0 : 1
enter the value for edge between 2 and 1: 0
enter the value for edge between 2 and 2: 1

 enter your choice2
the matrix is
	 1	 1	 0
	 0	 1	 1
	 1	 0	 1


enter your choice3

enter the no.of vertex3
enter the value1 A
enter how many nodes are connected to vertexA: 2
enter the value: B
enter the value: C

enter the value2 B
enter how many nodes are connected to vertexB: 1
enter the value: A

enter the value3 C
enter how many nodes are connected to vertexC: 2
enter the value: A
enter the value: B


 enter your choice4
A--> 	B-->C-->
B--> 	A-->
C--> 	A-->B-->NULL

*/
	


