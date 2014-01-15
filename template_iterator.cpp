 template<class T> class Stack {
     struct Link {
       T* data;
       Link* next;
       Link(T* dat, Link* nxt)
         : data(dat), next(nxt) {}
     }* head;
   public:
     Stack() : head(0) {}
     ~Stack();
     void push(T* dat) {
       head = new Link(dat, head);
     }
     T* peek() const {
       return head ? head->data : 0;
     }
     T* pop();
     // Nested iterator class:
     class iterator; // Declaration required
     friend class iterator; // Make it a friend
     class iterator { // Now define it
       Stack::Link* p;
     public:
iterator(const Stack<T>& tl) : p(tl.head) {} // Copy-constructor:
iterator(const iterator& tl) : p(tl.p) {}
// The end sentinel iterator:
iterator() : p(0) {}


// operator++ returns boolean indicating end: bool operator++() {
      if(p->next)
        p = p->next;
      else p = 0; // Indicates end of list
      return bool(p);
    }
bool operator++(int) { return operator++(); } T* current() const {
      if(!p) return 0;
      return p->data;
    }
    // Pointer dereference operator:
    T* operator->() const {
require(p != 0, "PStack::iterator::operator->returns 0");
      return current();
    }
    T* operator*() const { return current(); }
    // bool conversion for conditional test:
    operator bool() const { return bool(p); }
    // Comparison to test for end:
    bool operator==(const iterator&) const {
      return p == 0;
    }
    bool operator!=(const iterator&) const {
      return p != 0;
    }
  };
  iterator begin() const {
    return iterator(*this);
  }
  iterator end() const { return iterator(); }
};
template<class T> Stack<T>::~Stack() {
  while(head)
    delete pop();
}

template<class T> T* Stack<T>::pop() {
  if(head == 0) return 0;
  T* result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}

int main() {
  ifstream file("file.cpp");
  Stack<string> textlines;
  // Read file and store lines in the Stack:
  string line;
  while(getline(file, line))
		textlines.push(new string(line));
int i = 0;
// Use iterator to print lines from the list: 
Stack<string>::iterator it = textlines.begin(); 
Stack<string>::iterator* it2 = 0;
while(it != textlines.end()) {
    cout << it->c_str() << endl;
    it++;
    if(++i == 10) // Remember 10th line
      it2 = new Stack<string>::iterator(it);
  }
  cout << (*it2)->c_str() << endl;
  delete it2;
} ///:~