#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stdio.h>
#include<multimap>

using namespace std;

#define rn return
#define int32 int
#define endl '\n'
#define boost sync_with_stdio(false); cin.tie(0)

struct node
{
	int32 low, high, max;
	node *left;
	node *right;
};

node* CreateNewNode(int32 l,int32 h)
{
    node* temp = new node();
    temp->low = l;
    temp->high = h;
    temp->max = h;
    temp->left = NULL;
    temp->right = NULL;

    rn temp;
}

node* InsertNode(node *root,int32 l,int32 h)
{
    if(root==NULL)
    {
        root = CreateNewNode(l,h);
    }
    else if(l > root->low )
    {
        root->max = max(root->high,h);
        root->right = InsertNode(root->right,l,h);
    }
    else
    {
        root->max = max(root->high,h);
        root->left = InsertNode(root->left,l,h);
    }
    rn root;

}

node* SearchNode(node *root,int32 l,int32 h)
{
    if (root == NULL)
            rn NULL;
        if (root->low<=h && root->high>=l)
            rn root;
        if (root->left != NULL && (root->left)->max >= l)
            rn SearchNode(root->left, l, h);
        rn SearchNode(root->right, l, h);

}

void ChangeNode(node* node1, node* node2)
{
	node1->low=node2->low;
	node1->high=node2->high;
}

void RemoveNode(node* current,node* root, node* parent, bool head)
{
	int32 child=0;
	bool left=false, right=false;
	if(current->low <= parent->low) left=true;
	else right=true;

	if(current->left) child++;
	if(current->right) child++;

	if(child==0){
		if(head){
			parent=NULL;
			rn;
		}
		if(left) parent->left=NULL;
		else parent->right=NULL;
	}
	else if(child==1){
		if(head){
			if(current->left) root=root->left;
			else root=root->right;
			rn;
		}
		if(left){
			if(current->right) parent->left=current->right;
			else parent->left=current->left;
		}
		else{
			if(current->right) parent->right=current->right;
			else parent->right=current->left;
		}
	}
	else{
		node* temp=current;
		temp=temp->left;
		if(temp->right){
			while(temp->right){
				parent=temp;
				temp=temp->right;
			}
			ChangeNode(current, temp);
			parent->right=NULL;
		}
		else{
			ChangeNode(current, temp);
			RemoveNode(temp, root,current, false);
		}
	}
}

node* DeleteNode(node* root,node* temp_node)
{
    node* current=new node();
    current = root;
	node *parent= new node();
	parent = root;
	while(true){
		if(current==NULL){
			cout<<"The interval you requested to delete does not exist"<<endl;
			break;
		}
		if(temp_node->low < current->low){
			parent=current; current=current->left;
		}
		else if(temp_node->low > current->low){
			parent=current; current=current->right;
		}
		else{
			RemoveNode(current,root, parent, false);
			break;
		}
	}
}

int main()
{
	boost;
	 node *root = NULL;
	 cout<<"Enter the number of intervals you want to insert."<<endl;
	 int32 n,l,h;
	 cin>>n;
	 for(int32 i=1;i<=n;i++)
	 {
		cin>>l>>h;
	    root = InsertNode(root,l,h);
	 }
	 cout<<root->low<<endl;
	 cout<<"Enter the number of search queries"<<endl;
	 cin>>n;
 for(int32 i=0;i<n;i++)
 {
     cin>>l>>h;
     node *temp = new node();
     temp = SearchNode(root,l,h);
     if(temp)
     {
         cout<<"There is an overlap and the overlap interval is: "<<temp->low<<" "<<temp->high<<endl;
     }
     else
        cout<<"No overlapping interval found."<<endl;
 }
 cout<<"Enter the number of nodes you want to delete."<<endl;
 cin>>n;
 for(int32 i=0;i<n;i++)
 {
     cin>>l>>h;
     node *temp = new node();
     temp = CreateNewNode(l,h);
     DeleteNode(root,temp);
     cout<<"The given interval has been deleted."<<endl;
 }
 rn 0;
}
