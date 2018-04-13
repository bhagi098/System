/*
ASSIGNMENT NO : Group C-14
TITLE:	Consider telephone book database of N clients. Make use of a hash 
		table implementation to quickly look up client’s telephone number.
*****************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class hashtable					//Create Class hashtable
{
	public:
	  	char name[20];
	  	long int mobile;
};

class directory					//Create directory class
{
   	hashtable a[10];
  	public :        
   		void insert();
		void search();
		void display();   
  		directory()				//directory class constructor
  		{
    			for(int i=0;i<10;i++)
    			{
				a[i].name[0]='\0';
			      	a[i].mobile=-1;
    			}    
  		}
};

 
void directory::insert()				//insert data in directory
{
  	char n[20],ans;
  	double m;
  	int x,key,i;
  	do
  	{  
    		cout<<"\nEnter the name :";
    		cin>>n;
    		cout<<"\nEnter the mobile number :";
    		cin>>m;
    		x=(char)n[0];
    		key=x%10;
    		if(a[key].name[0]=='\0')
    		{
        			strcpy(a[key].name,n);
        			a[key].mobile=m ;
    		}    
    		else
    		{
            		while(a[key].name[0]!='\0')
      			{      
        				key++;  
				if(key==9)
				{
					key=0;
				}    
      			}
	  	  	strcpy(a[key].name,n);
	    		a[key].mobile=m;    
   		}
   		cout<<"\nDo you want to add more details(Y/N):";
  		cin>>ans;
  	} while(ans=='y'||ans=='Y');
}

void directory::display()					//Display Data
{
      	cout<<"\nName \t Mobile no";
   	for(int i=0;i<10;i++)
   	{
          		cout<<"\n"<<a[i].name<<"\t"<<a[i].mobile;
        	}
}


void directory::search()					//To search data
{
	int searchkey,temp;
	char x[20];
	cout<<"Enter name to search:";
	cin>>x;
	temp=(char)x[0];
	searchkey=temp%10;
	if(a[searchkey].name[0]!='\0')
	{
		cout<<"\n"<<a[searchkey].name;
		cout<<"\n"<<a[searchkey].mobile;
	}
	else
	{
		cout<<"Key not found";
	}
}

int main()							//Main Method
{
	int ch;
	directory d;
	do
	{	
	  	cout<<"---MENU----";
	  	cout<<"\n1.Insert.\n2.Display.\n3.Search.";
	  	cout<<"\nEnter your choice:";
	  	cin>>ch;
		switch(ch)
  		{    
		    case 1:			//insert data
       				d.insert();
		       		break;       
		    case 2:			//display data
			      	d.display();
       				break;
		    case 3:			//search data
				d.search();
				break;
   
   		}
	}while(ch!=5);
	return 0;
}

/***********************Output***********************
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ hash5.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out
---MENU----
1.Insert.
2.Display.
3.Search.
Enter your choice:1

Enter the name :abc

Enter the mobile number :9876543210

Do you want to add more details(Y/N):y

Enter the name :pqr

Enter the mobile number :4536789012

Do you want to add more details(Y/N):y  

Enter the name :def

Enter the mobile number :5678901234

Do you want to add more details(Y/N):n


Enter your choice:2

Name 	 Mobile no
def	5678901234
	-1
pqr	4536789012
	-1
	-1
	-1
	-1
abc	9876543210
	-1
	-1

Enter your choice:3
Enter name to search:abc

abc
9876543210

Enter your choice:3
Enter name to search:ytu
Key not found
*/


