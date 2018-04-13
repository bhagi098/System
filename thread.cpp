#include<iostream>
using namespace std;
class tnode
{
	public:
	int data;
	tnode *left;
	tnode *right;
	int lbit,rbit;
};
class tbt
{
	public:
	tnode *head;
	tnode *root;
	tbt()
	{
		root=NULL;
		head=NULL;
	}
	void create();
	void preorder();
};

void tbt:: create()
{
	tnode *t,*x;
	int flag=0;
	char ans;
	head=new tnode();
	head->left=head;
	head->right=head;
	head->lbit=1;
	head->rbit=1;

	root=new tnode();
	cout<<"\nEnter the root:";
	cin>>root->data;
	root->left=head;
	root->right=head;
	root->lbit=1;
	root->rbit=1;
	head->left=root;
	head->lbit=0;
	do
	{
		flag=0;
		t=root;
		x=new tnode();
		cout<<"\nEnter data";
		cin>>x->data;
		x->lbit=1;
		x->rbit=1;
		while(flag==0)
		{
			if(x->data < t->data)
			{
				if(t->lbit==1)
				{
					t->lbit=0;
					x->left=t->left;
					t->left=x;
					x->right=t;
					flag++;
				}
				else
				{
					t=t->left;
				}
			}	
			else if(x->data > t->data)
			{
				if(t->rbit==1)
				{
					x->right=t->right;
					t->right=x;
					x->left=t;
					t->rbit=0;
					flag++;					
				}
				else
				{
					t=t->right;
				}
			}
			else
			{
				cout<<"\n Node is already exist.....!!!";
			}
		}
		cout<<"\n Do you want to add more nodes:";
		cin>>ans;
	}while(ans=='Y'|| ans=='y');
}

void tbt:: preorder()
{
	tnode *t;
	t=root;
	int flag=0;
	while(t!=head)
	{
		if(flag==0)
		{
			cout<<t->data<<"  ";
		}
		if(t->lbit==0&& flag==0)
		{
			t=t->left;
		}
		else if(t->rbit==1)
		{
			t=t->right;
			flag=1;
		}
		else if(t->rbit==0)
		{
			t=t->right;
			flag=0;
		}
	}

}
int main()
{
	int ch;
	tbt th;
	do
	{
		cout<<"\nMenu";
		cout<<"\n 1.create tree";
		cout<<"\n 2.display tree";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: th.create();
					break;
			case 2: th.preorder();
					break;
		 
		}
	}while(ch!=3);
	return 0;
}
/* Output
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ the.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

Menu
 1.create tree
 2.display tree
 Enter your choice:1

Enter the root:15

Enter data10

 Do you want to add more nodes:y

Enter data5

 Do you want to add more nodes:y

Enter data12

 Do you want to add more nodes:y

Enter data20

 Do you want to add more nodes:y

Enter data17

 Do you want to add more nodes:y

Enter data25

 Do you want to add more nodes:n

Menu
 1.create tree
 2.display tree
 Enter your choice:2
15  10  5  12  20  17  25   */
