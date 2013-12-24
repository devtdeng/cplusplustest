#include <iostream>
using namespace std;


typedef struct node{
	int val;
	struct node* pNext;
}NODE, *PNODE;

////// linked list implementation without class ///////
PNODE createlinkedlist()
{
	PNODE head=NULL;
	PNODE tail=NULL;
	int val;
	while(1){
		cout<<"please input a value(stop with 32767): ";
		cin>>val;
		if(val==32767) break;
		
		if(head){
			tail->pNext=new NODE;
			tail=tail->pNext;
			tail->val=val;
			tail->pNext=NULL;
		}else{
			head = new NODE;
			head->val=val;
			head->pNext=NULL;
			tail=head;
		}		
	}
	return head;
}

void printlinkedlist(PNODE head)
{
	while(head){
		cout << head->val << " ";
		head=head->pNext;
	}
	cout << endl;
}

void deletelinkedlistnode(PNODE node)
{
	// don't know previous node, so copy data from next node and delete next one
	// but this doesn't do well with last node....
	if(node==NULL || node->pNext==NULL) return;
	
	node->val=node->pNext->val;
	node->pNext=node->pNext->pNext;
	delete node->pNext;
}

void destorylinkedlist(PNODE head)
{
	while(head){
		PNODE tmp=head;
		head=head->pNext;
		delete tmp;
	}
}


// remove duplicate node
// need correction 
void deletelinkedlistdups(PNODE head)
{
	if(head==NULL) return;
	
	PNODE previous=head;
	PNODE current=previous->pNext;
	
	// make sure all nodes before current are not duplicated
	// scan from head to current, if there are identical val, remove current and move current to next, until end of linked list
	while(current){
		PNODE runner=head;
		while(runner!=current){
			if(runner->val==current->val){
				previous->pNext=current->pNext;
				delete current;
				current=previous->pNext;
				break;
			}
			runner=runner->pNext;			
		}
		
		if(runner==current){
			previous=current;
			current=current->pNext;
		}		
	}	
}

PNODE reverselinkedlist(PNODE pHead)
{
  PNODE pTmp;
  PNODE pPre = NULL;
  while(pHead) {
      pTmp = pHead->pNext;
      pHead->pNext = pPre;
      pPre = pHead;
      pHead = pTmp;
  }
  return pPre;
}

////// find a start of a circular linked list ///////
PNODE findbeginning(PNODE head)
{
	if(head==NULL) return NULL;

	// first step, check if n1 and n2 can meet at somewhere
	PNODE slow=head;
	PNODE fast=head;
	while(fast && fast->pNext){
		slow=slow->pNext;
		fast=fast->pNext->pNext;
		if(slow==fast)
			break; /*circular linked list*/
	}
	
	// n2 reaches end of the linked list, it is not circular list
	if(fast==NULL || fast->pNext==NULL)
		return NULL;
	
	// or it is cirulcar list, find the beginning node
	slow=head;
	while(slow!=fast){
		slow=slow->pNext;
		fast=fast->pNext;
	}
	return fast;
}

PNODE getlastklist(PNODE head, int k)
{
	PNODE	p1=head;
	PNODE	p2=head;
	
	// suppose k>0
	while(p1 && k--){
		p1=p1->pNext;
	}
	
	if(k && p1==NULL) // k>length of linked list
		return NULL;
	
	while(p1){
		p1=p1->pNext;
		p2=p2->pNext;
	}
	
	return p2;
}


////// linked list implementation with class ///////
class MyList{
private:
	PNODE	pHead;// linked list head pointer
	int	cnt;		// item count
public:
	MyList();
	virtual ~MyList();
	
public:
	void Init();
	void Add(int val);
	void Delete(int val);
	bool InsertAt(int k);
	void Travel(); 	
	void Sort();
	
protected:
	void BubbleSort();
	void SelectSort();
};




MyList::MyList(){
	this->pHead=NULL;
	cnt = 0;
}	

MyList::~MyList(){
	while(this->pHead==NULL){
		PNODE pTemp=pHead->pNext;
		delete pHead;
		pHead=pTemp;
	}
	this->pHead=NULL;
}	

void MyList::Init(){
	int	val;
	PNODE	pTail=NULL;
	
	while(1){
		cout<<"please input a value(stop with 100): ";
		cin>>val;

		if(val==100) break;	// end
		
		if(this->pHead!=NULL){		// not empty
			// find tail first
			pTail=pHead;
			while(pTail->pNext)
				pTail=pTail->pNext;
			
			pTail->pNext=new NODE;
			pTail=pTail->pNext;
			pTail->val=val;
			pTail->pNext=NULL;
		}else{						// empty
			pHead=new NODE;
			pHead->val=val;
			pHead->pNext=NULL;
			pTail=pHead;
		}
		cnt++;
	}
}	

void MyList::Add(int val){
	if(this->pHead==NULL){	// not empty
		// find tail first
		PNODE pTail=this->pHead;
		while(pTail->pNext)
			pTail=pTail->pNext;
		
		pTail->pNext=new NODE;
		pTail=pTail->pNext;
		pTail->val=val;
		pTail->pNext=NULL;
	}else{					// empty
		pHead=new NODE;
		pHead->val=val;
		pHead->pNext=NULL;
	}	
}

void MyList::Travel(){
	PNODE p=this->pHead;
	while(p){
		cout << p->val << " ";
		p=p->pNext;
	}
	cout << endl;
}

bool MyList::InsertAt(int k){
	return true;
}

// delete first node with val;
void MyList::Delete(int val){
	// not implemented yet
	PNODE p=this->pHead;
	PNODE pre=NULL;
	
	while(p){
		if(p->val==val){		// found
			if(pre==NULL) {
				this->pHead=p->pNext;
			}
			else{
				pre->pNext=p->pNext;
			}
			delete p;
			break;
		}
		pre=p;		// set pre to current node
		p=p->pNext;	// move p to next node
	}
}


int main(int argc, char** argv)
{
	/* implemented linked list with class */
	/*
	MyList* pmylist=new MyList();
	if(pmylist){
		pmylist->Init();		
		pmylist->Travel();
		
		pmylist->Delete(10);
		pmylist->Travel();		
		delete pmylist;
	}*/
		
	PNODE head=createlinkedlist();
	printlinkedlist(head); // before remove dups
	//deletelinkedlistdups(head);
	head=reverselinkedlist(head);
	printlinkedlist(head); // after remove dups
	
	PNODE k=getlastklist(head, 4);
	printlinkedlist(k); // after remove dups

	destorylinkedlist(head);
}



