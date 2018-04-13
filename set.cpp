/*
Assignment no. Group E-20
Title : To create ADT that implements the SET concept. 
	a. Add (new Element) -Place a value into the set   b. Remove (element)
 Remove the value  c. Contains (element) Return true if element is in collection  d. Size () Return number 	of values in 	collection Iterator () Return an iterator used 	to loop over collection e. 	Intersection  of two sets, f. Union of two sets,  g. Difference between 	two sets, h. 	Subset 
Roll No.: 05 				Class: SE-A
*****************************************************************/
#include<iostream>
using namespace std;
class SET							// Class SET 
{
	public:
	int a[10];
	int cnt;
	public:
		SET()						//Set class constructor
		{
			cnt=0;
		}
	
		void insert();
		void size();
		void display();
		void remove();
		void search(int x);
		void intersection(SET A,SET B);
		void union_(SET A,SET B);
		void differance(SET A,SET B);
		void subset(SET A, SET B);
};

void SET::insert()
{
	cout<<"\nEnter the Set elements:\t"<<endl;
	cin>>a[cnt];
	cnt++;
}

void SET::remove()
{
	cnt--;
	cout<<a[cnt]<<"\ndeleted sucessfully"<<endl;
}

void SET::display()
{
	cout<<"\nSET elements are:\t";
	for(int i=0;i<cnt;i++)
	{
	      cout<<a[i]<<"   ";
	}
}

void SET::search(int x)
{
	int flag=0;
	for(int i=0;i<cnt;i++)
	{
		if(a[i]==x)
		{
			flag++;
		}
	}
	if(flag==1)
	{
		cout<<"Element found"<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}
}

void SET::size()
{
	cout<<"Size of SET is:"<<cnt<<endl;

}

void SET::intersection(SET A,SET B)
{
	int flag=0;
	for(int i=0;i<A.cnt;i++)
	{
		flag=0;
		for(int j=0;j<B.cnt;j++)
		{	
			if(A.a[i]==B.a[j])
			{
				flag++;
				break;
			}
		}
		if(flag==1)
		{
			a[cnt]=A.a[i];
			cnt++;
		}
	}
}

void SET::union_(SET A,SET B)
{
   	int flag=0;
   	for(int i=0;i<A.cnt;i++)
   	{
   		a[cnt]=A.a[i];
   		cnt++;
   	}
   	for(int i=0;i<B.cnt;i++)
   	{
    		flag=0;
     		for(int j=0;j<cnt;j++)
       		{
			if(B.a[i]==a[j])
		 	{
		 		flag++;
		 		break;
		 	}
                	}
      		if(flag==0)
     		{
     			a[cnt]=B.a[i];
      			cnt++;
    	 	}
  	}
}

void SET::differance(SET A,SET B)
{
	int flag=0;
	for(int i=0;i<A.cnt;i++)
	{
		flag=0;
		for(int j=0;j<B.cnt;j++)
		{	
			if(A.a[i]==B.a[j])
			{
				flag++;
				break;
			}
		}
		if(flag==0)
		{
			a[cnt]=A.a[i];
			cnt++;
		}
	}
}

void SET::subset(SET A,SET B)
{
	for(int i=0;i<A.cnt;i++)
	{
		for(int j=0;j<B.cnt;j++)
		{	
			if(A.a[i]==B.a[j])
			{
				cnt++;
				break;
			}
		}
	}

	if(cnt==B.cnt)
	{
		cout<<"B is subset of A\n";
	}
	else
	{
		cout<<"B is not subset of A\n";
	}
}

int main()							//Main function
{
	SET A,B,C,s1;
	int ch;
	int x,n1,n2;
	do
	{
		cout<<"\nOPERATIONS:\n1.INSERT\n2.DISPLAY\n3.SIZE\n4.DELETE\n5.SEARCH\n6.INTERSECTION\n7.union \n8.differance\n9subset"<<endl;
		cout<<"\nEnter choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:				//Insert
				s1.insert();
		       	 	break;
			
			case 2:				//Display
				s1.display();
		             	break;
			
			case 3:				//Size			
				s1.size();
			       	break;
	      	
			case 4:				//Delete
				s1.remove();
	      	       		break;
	      		case 5:				//Search
				cout<<"\nEnter the no. to be searched:";
	      	       		cin>>x;
	      	       		s1.search(x);
	      	 	 	break;
	            
			case 6:				//Intersection
				cout<<"\nEnter no. of elements of set A:";
	                   		cin>>n1;
	                   		for(int i=0;i<n1;i++)
	                   		{
	                   			A.insert();
	                   		}
	                   		cout<<"\nEnter no. of elements of set B:";
	                   		cin>>n2;
	                   		for(int j=0;j<n2;j++)
	                   		{
	                   			B.insert();
	                   		}
	                   		C.intersection(A,B);
	                   		C.display();
	                   		break;	                                   
	                   
	          	 	case 7:				//Union
				cout<<"\nEnter no. of elements of set A:";
	                   		cin>>n1;
	                   		for(int i=0;i<n1;i++)
	                   		{
	                   			A.insert();
	                   		}
	                   		cout<<"\nEnter no. of elements of set B:";
	                   		cin>>n2;
	                   		for(int j=0;j<n2;j++)
	                   		{
	                   			B.insert();
	                   		}
	                   		C.union_(A,B);
	                   		C.display();
	                   		break;
	           
	         		case 8:			//Difference
				cout<<"\nEnter no. of elements of set A:";
	                   		cin>>n1;
	                   		for(int i=0;i<n1;i++)
	                   		{
	                   			A.insert();
	                   		}
	                   		cout<<"\nEnter no. of elements of set B:";
	                   		cin>>n2;
	                   		for(int j=0;j<n2;j++)
	                   		{
	                   			B.insert();
	                   		}
	                   		C.differance(A,B);
	                   		cout<<"\n the elments only in set A are:";
	                   		C.display();
	                   		break;
		
			case 9:    			//Subset
				cout<<"\nEnter no. of elements of set A:";
	                   		cin>>n1;
	                   		for(int i=0;i<n1;i++)
	                   		{
	                   			A.insert();
	                   		}
	                   		cout<<"\nEnter no. of elements of set B:";
	                   		cin>>n2;
	                   		for(int j=0;j<n2;j++)
	                   		{
	                   			B.insert();
	                   		}
	                   		C.subset(A,B);
	                   		break;
	  	}
	}while(ch!=9);
	return 0;
}

/*********************OUTPUT*************************
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ set1.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

OPERATIONS:
1.INSERT
2.DISPLAY
3.SIZE
4.DELETE
5.SEARCH
6.INTERSECTION
7.UNION 
8.DIFFERENCE
9.SUBSET

Enter choice:1
Enter the Set elements:	10

Enter choice:1
Enter the Set elements:	20


Enter choice:1
Enter the Set elements:	30

Enter choice:1
Enter the Set elements:	40


Enter choice:2
SET elements are:	10   20   30   40  


Enter choice:3
Size of SET is:4


Enter choice:4
40 ---- deleted sucessfully


Enter choice:2
SET elements are:	10   20   30 


Enter choice:5
Enter the no. to be searched : 20
Element found



Enter choice:6
Enter no. of elements of set A:4
Enter the Set elements:	1
Enter the Set elements:	2
Enter the Set elements:	3
Enter the Set elements:	4

Enter no. of elements of set B:4
Enter the Set elements:	3
Enter the Set elements:	4
Enter the Set elements:	5
Enter the Set elements:	6

SET elements are:	3   4  


Enter choice:7
Enter no. of elements of set A:4
Enter the Set elements:	1
Enter the Set elements:	2
Enter the Set elements:	3
Enter the Set elements:	4

Enter no. of elements of set B:4
Enter the Set elements:	4
Enter the Set elements:	5
Enter the Set elements:	6
Enter the Set elements:	7

SET elements are:	1   2   3   4   5   6   7 


Enter choice:8
Enter no. of elements of set A:4
Enter the Set elements:	1
Enter the Set elements:	2
Enter the Set elements:	3
Enter the Set elements:	4



Enter no. of elements of set B:4
Enter the Set elements:	3
Enter the Set elements:	4
Enter the Set elements:	5
Enter the Set elements:	6

the elments only in set A are:
SET elements are:	1   2 



Enter choice:9
Enter no. of elements of set A:4
Enter the Set elements:	10
Enter the Set elements:	20
Enter the Set elements:	30
Enter the Set elements:	40

Enter no. of elements of set B:3
Enter the Set elements:	10
Enter the Set elements:	20
Enter the Set elements:	30

B is subset of A


Enter choice:9
Enter no. of elements of set A:4
Enter the Set elements:	10
Enter the Set elements:	20
Enter the Set elements: 30
Enter the Set elements:	40

Enter no. of elements of set B:3
Enter the Set elements:	50
Enter the Set elements:	60
Enter the Set elements:	70

B is not subset of A

*/ 



