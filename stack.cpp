#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

/*stack with fixed size and type*/
class StackInt{
	enum {ssize=100};
	int stack[ssize];
	int top;

public:
	StackInt():top(0){};
	void push(int val){
		assert(top<ssize);
		stack[top++]=val;
	}
	int pop(){
		assert(top>0);
		return stack[--top];
	}
};

/*stack template with fixed size*/
template<class T>
class StackTemplate {
	enum { ssize = 100 };
	T stack[ssize];
	int top;
public:
	StackTemplate() : top(0) {}
	void push(const T& i) {
		assert(top<ssize);
			stack[top++] = i;
	}
	T pop() {
		assert(top>0);
		return stack[--top];
   }
   
   int size() { return top; }
};

/*stack template with dynamic size and type*/
template<class T>
class StackWithMin {
	vector<T> datas;
	vector<size_t>	minStack;
public:
	void push(T data) {
	  datas.push_back(data);
		if(minStack.empty()||data<=datas[minStack.back()])
			minStack.push_back(datas.size()-1);		
	}
	
	void pop() 
	{
		assert(!datas.empty());
		if(datas.back()==datas[minStack.back()])
			minStack.pop_back();
		datas.pop_back();	  	
	}
	
	T min()
	{
		assert(!datas.empty() && !minStack.empty());
		return datas[minStack.back()];	  	
	}
};



int main(int argc, char** argv) 
{
	StackWithMin<int>	stack;
	cout<<"push stack"<<endl;	
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(2);
	stack.push(5);
	stack.push(6);
	stack.push(5);
	stack.push(8);
	stack.push(7);
	stack.push(9);
	stack.push(2);
	stack.push(1);
	cout<<"pop stack"<<endl;
	for(int i=0; i<12; i++){
		cout<<"min="<<stack.min()<<endl;		
		stack.pop();
	}
	
	return 0;
}