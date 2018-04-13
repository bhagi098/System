/*
Assignment No:	Group F-22
TITLE:- Assume we have two input and two output tapes to perform the sorting. 
The internal memory can hold and sort m records at a time. Write a
   	     program in  java for external sorting. Find out  time complexity.
************************************************************/

#include<iostream>
using namespace std;
int main()							//Main function 
{
	int a[10],b[10],c[20],n1,n2,cnt=0,i=0,j=0;

	cout<<"\nEnter array 1 count:";
	cin>>n1;

	cout<<"\nEnter array 1 in ascending order:";
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
	}

	cout<<"\nEnter array 2 count:";
	cin>>n2;

	cout<<"\nEnter array 2 in ascending order:";
	for(i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	
	for(i=0,j=0;i<n1&&j<n2;)
	{
		if(a[i]<b[j])
		{
			c[cnt]=a[i];
			i++;
			cnt++;
		}



		else
		{
			c[cnt]=b[j];
			j++;
			cnt++;
		}
	}
	
	if(i!=n1)
	{
		for(;i<n1;i++)
		{
			c[cnt]=a[i];
			cnt++;
		}		
	}	
	
	if(j!=n2)
	{
		for(;j<n2;j++)
		{			
			c[cnt]=b[j];
			cnt++;	
		}		
	}	

	cout<<"\nSorted array : ";
	
	for(i=0;i<cnt;i++)
	{
		cout<<c[i]<<"\n";
	}

	return 0;

}








/*********************OUTPUT***************************
guest-n2p2Mv@gescoe-OptiPlex-3010:~/Desktop$ g++ merge.cpp
guest-n2p2Mv@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

Enter array 1 count:4

Enter array 1 in ascending order:10
11
12
13

Enter array 2 count:4

Enter array 2 in ascending order:1
2
3
4

Sorted array :
1
2
3
4
10
11
12
13

*/				


