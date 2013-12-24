#include <iostream>
#include <queue>
using namespace std;


// bi Search tree, all value are different
struct tree_node
{
   tree_node* left;
   tree_node* right;
   int val;
};

class BinarySearchTree
{
	private:
		tree_node* root;

	public:
		BinarySearchTree():root(NULL){};
		~BinarySearchTree();
				
	public:	
    bool isEmpty() const;
		void insert(int);
		void remove(int);				
				
		// deep first search
		void print_inorder();
		void inorder(tree_node*);
		void print_preorder();
    void preorder(tree_node*);
    void print_postorder();
    void postorder(tree_node*);

		// wide first search
		void print_wideorder();
				
		// find path which match the value provided
		void findPath(tree_node* node, int expectedsum, vector<int>& path, int& currentSum);
		void print_findPath(int expectedsum);
		
		// mirror binary tree
		void mirrortree();
		void mirror(tree_node* node);
};

BinarySearchTree::~BinarySearchTree()
{
	// TBD release memore here
}


bool BinarySearchTree::isEmpty() const 
{ 
	return root==NULL;
}

void BinarySearchTree::insert(int val)
{
	tree_node* parent = NULL;	
	if(isEmpty()){
		root = new tree_node;
		root->left=NULL;
		root->right=NULL;
		root->val=val;
	}else{
		/* search the insert point from root*/
		tree_node* curr=root;		
		while(curr){
			/* keep parent for future use */
			parent = curr;
			if(val == curr->val){
				return; // not needed to add node here
			}
			else if(val < curr->val){
				curr = curr->left;
			}
			else{
				curr = curr->right;
			}
		}
		
		/* add new leaf to the branch */
		tree_node* t = new tree_node;
		t->val = val;
		t->left = NULL;
		t->right = NULL;
		
		if(t->val < parent->val){
			parent->left = t;
		}else{
			parent->right = t;
		}
	}
}

void BinarySearchTree::remove(int val)
{
	// http://www.cplusplus.com/forum/general/1551/
}

void BinarySearchTree::print_inorder()
{
	inorder(root);
	cout<<endl;
}

void BinarySearchTree::inorder(tree_node *p)
{
	if(p){
		inorder(p->left);
		cout<<p->val<<" ";
		inorder(p->right);		
	}
}

void BinarySearchTree::print_preorder()
{
	preorder(root);
	cout<<endl;	
}

void BinarySearchTree::preorder(tree_node *p)
{
	if(p){
		cout<<p->val<<" ";
		preorder(p->left);
		preorder(p->right);		
	}	
}

void BinarySearchTree::print_postorder()
{
	postorder(root);
	cout<<endl;
}

void BinarySearchTree::postorder(tree_node *p)
{
	if(p){
		postorder(p->left);
		postorder(p->right);		
		cout<<p->val<<" ";		
	}	
}

void BinarySearchTree::print_wideorder()
{
	if(isEmpty()) return;
	
	queue<tree_node*> nodequeue;
	nodequeue.push(root);
	
	tree_node* node;
	while(!nodequeue.empty())
	{
		node=nodequeue.front();
		nodequeue.pop();
		cout<<node->val<<" ";
		
		if(node->left)
			nodequeue.push(node->left);

		if(node->right)
			nodequeue.push(node->right);
	}
	cout << endl;
}

void BinarySearchTree::print_findPath(int expectedsum)
{
	vector<int> path;
	int	currentSum=0;	
	findPath(root, expectedsum, path, currentSum);	
}

void BinarySearchTree::findPath(tree_node* node, int expectedsum, vector<int>& path, int& currentSum)
{
	if(node==NULL) return;	
	
	currentSum+=node->val;
	path.push_back(node->val);
		
	bool isLeaf = node->left==NULL && node->right==NULL;
	if(currentSum==expectedsum && isLeaf){
		/* found a path, print out it */
		vector<int>::iterator iter=path.begin();
		for(; iter!=path.end(); ++iter){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
	
	if(node->left)
		findPath(node->left, expectedsum, path, currentSum);
	
	if(node->right)
		findPath(node->right, expectedsum, path, currentSum);	
	
	currentSum-=node->val;
	path.pop_back();
}

void BinarySearchTree::mirrortree()
{
	if(isEmpty()) return;
	mirror(root);
}

void BinarySearchTree::mirror(tree_node* node)
{
	tree_node* tmp = node->left;
	node->left = node->right;
	node->right = node->left;
		
	if(node->left)
		mirror(node->left);
		
	if(node->right)
		mirror(node->right);
}

int main(int argc, char** argv)
{
	BinarySearchTree	b;
	
	int a[10]={3,5,7,9,1,2,6,8,0,4};
	for(int i=0; i<10; i++){
		b.insert(a[i]);
		b.print_wideorder();		
	}
	
	/* wide search with a queue*/
	b.print_wideorder();
	
	/* deep search */
	b.print_inorder();
	b.print_preorder();
	b.print_postorder();
	
	/*find path value == input value*/	
	b.print_findPath(6);	
}

