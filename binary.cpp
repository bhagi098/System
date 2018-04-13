/* Assignment no: Group A-2
Title :Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the 
order given. After constructing a binary tree - 
i.Insert new node 
ii.Find number of nodes in longest path
iii.Minimum data value found in the tree  
iv.Change a tree so that the roles of the left and right pointers are swapped at every node  
v.Search a value.
************************************************************/
 # include <iostream>
 # include <cstdlib>
using namespace std;
 
class node				// Node Declaration			
{
	public:
        		int info;
       		struct node *left;
        		struct node *right;

}*root;

class BST				// Class Declaration
{
	public:
		node *root;
            	void insert(node *,node *);
            	void display(node *, int);
		int min(node *);
            	int height(node *);
  		void mirror(node *);
		void preorder(node *);
       		void inorder(node *);
            	void postorder(node *);
           
		BST()			//BST class constructor 
            	{
			root = NULL;
            	}
};

int main()				// Main Contains Menu
{
	int choice, num;
        	BST bst;			//BST class object
        	node *temp;
        	while (1)
        	{
		cout<<"-----------------"<<endl;
            	cout<<"Operations on BST"<<endl;
            	cout<<"-----------------"<<endl;
            	cout<<"1.Insert Element "<<endl;
           	cout<<"2.Display"<<endl;
                   cout<<"3.Min value find"<<endl;
                  	cout<<"4.Height"<<endl;
                   cout<<"5.Mirror of node"<<endl;
                   cout<<"6.Preorder"<<endl;
                   	cout<<"7.Inorder"<<endl;
                   cout<<"8.Postorder"<<endl;
         		cout<<"9.Quit"<<endl;

        		cout<<"Enter your choice : ";
            	cin>>choice;
            	switch(choice)
            	{
           			 case 1:		//Insert Element	
					temp = new node();
                				cout<<"Enter the number to be inserted : ";
    	    				cin>>temp->info;
                				bst.insert(bst.root, temp);
                				break;

                     		case 2:		//Display Element
					cout<<"Display BST:"<<endl;
					bst.display(bst.root,1);
                				cout<<endl;
                				break;
                
           			case 3:		//Minimum value
					cout<<"Min value of tree"<<endl;
            				cout<<temp->info;
            				bst.min(bst.root);
            				cout<<endl;
	   				break;
            		
				case 4:		//height of tree
					int h;
            				h=bst.height(bst.root);
            				cout<<"Height of tree="<<h;
            				cout<<endl;
            				break;
            
				case 5:		//Mirror image of tree
					cout<<"Mirror";
            				bst.mirror(bst.root);
            				bst.display(bst.root,1);	
            				break;
            
				case 6:		//Preorder display
					cout<<" \n Display preorder Binary tree = ";
					bst.preorder(bst.root);
					cout<<endl;
            				break;
             			case 7:		//Inorder display
					cout<<" \n Display inorder Binary tree = ";
					bst.inorder(bst.root);
					cout<<endl;
            				break;
             		
				case 8:		//Postorder display
					cout<<" \n Display postorder Binary tree=";
					bst.postorder(bst.root);
					cout<<endl;
            				break;
            	
				case 9:			
					exit(1);

            			default:
				  	cout<<"Wrong choice"<<endl;
            	}
        	}
}

void BST::insert(node *tree, node *newnode) // Inserting Element in Tree
{
	if (root == NULL)
        	{
            	root = new node;
            	root->info = newnode->info;
            	root->left = NULL;
           	root->right = NULL;
            	cout<<"Root Node is Added"<<endl;
            	return;
        	}
        	if (tree->info == newnode->info)
        	{
            	cout<<"Element already in the tree"<<endl;
            	return;
        	}
        	if (tree->info > newnode->info)
        	{
            	if (tree->left != NULL)
            	{
                		insert(tree->left, newnode);	
    		}
	    	else
    		{
                		tree->left = newnode;
                		(tree->left)->left = NULL;
        			(tree->left)->right = NULL;
                		cout<<"Node Added To Left"<<endl;
                		return;
            	}

        	}

	else
        	{
            	if (tree->right != NULL)
            	{
                		insert(tree->right, newnode);
            	}
            	else
            	{
                		tree->right = newnode;
                		(tree->right)->left = NULL;
               		(tree->right)->right = NULL;
                		cout<<"Node Added To Right"<<endl;
              		return;
          		}	
        	}
}

void BST::display(node *ptr, int level)	// Display Tree Structure
{
	int i;
        	if (ptr != NULL)
        	{
		display(ptr->right, level+1);
            	cout<<endl;
            	if (ptr == root)
              		cout<<"Root->:  ";
		else
            	{
                		for (i = 0;i < level;i++)
                    		cout<<"       ";
    		}
            	cout<<ptr->info;
            	display(ptr->left, level+1);
        	}
}

int BST::min(node *root)
{
	node *temp;
	if(root==NULL)
	{
		cout<<"Tree is empty";
	}
	else
	{
		temp=root;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return(temp->info);
	}
} 

int BST::height(node *root)
{
	int lheight,rheight;
        	if(root==NULL)
        	{
             	return(0);
        	}
        	if(root->left==NULL && root->right==NULL)
        	{
                	return(0);
        	}
        	lheight=height(root->left);
        	rheight=height(root->right);
        	if(lheight>rheight)
        	{
               	//cout<<"left side longest path is:"<<1+lheight;
                	return(1+lheight);
        	}
        	else
        	{
                	//cout<<"right side longest path is:"<<1+rheight;
                	return(1+rheight);
        	}

	
}

void BST::mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}
	
}

void BST::preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		cout<<ptr->info<<"\t";
		preorder(ptr->left);
		preorder(ptr->right);
		cout<<endl;
	}
}

void BST::inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->info<<"\t";
		inorder(ptr->right);
		cout<<endl;
	}
}

void BST::postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->info<<"\t";
		cout<<endl;
	}
}

/********************OUTPUT**************************


gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ b5.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out
-----------------
Operations on BST
-----------------
1.Insert Element 
2.Display
3.Min value find
4.Height
5.Mirror of node
6.Preorder
7.Inorder
8.Postorder
9.Quit
Enter your choice : 1
Enter the number to be inserted : 12
Root Node is Added

Enter your choice : 1
Enter the number to be inserted : 10
Node Added To Left


Enter your choice : 1
Enter the number to be inserted : 14
Node Added To Right


Enter your choice : 1
Enter the number to be inserted : 7
Node Added To Left




Enter your choice : 6
 Display preorder Binary tree = 
12	14	10	7	6	


Enter your choice : 7 
 Display inorder Binary tree = 
14	12	10	7	6	


Enter your choice : 8
 Display postorder Binary tree = 
14	6	7	10	12	
            

*/


