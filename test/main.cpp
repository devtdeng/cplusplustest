//
//  main.cpp
//  testC++
//
//  Created by Deng Tao on 1/15/14.
//  Copyright (c) 2014 dev tdeng. All rights reserved.
//
#include <iostream>
#include "clibrary.h"
#include "container.h"
#include "iotest.h"
#include "multithread.h"

using namespace std;

void my_handler(int param)
{
    // TBD
}

void clibrarytest()
{
    // assert.h
    assert(1);
    
    // ctypes.h
    cout << isalpha(65) << endl;    // 1
    
    // errno.h
    cout << errno << endl;          // 0
    
    // iso646.h
    
    // locale.h
    setlocale(LC_ALL,NULL);
    
    // math.h
    cout << cosf(10) << endl;       // -0.839072
    
    // setjmp.h
    jmp_buf env;
    int val=setjmp(env);
    cout << val << endl;
    if (!val) longjmp(env, 1);
    
    // signal.h
    /*
    void (*prev_handler)(int);
    prev_handler = signal(SIGINT, my_handler);
    raise(SIGINT);
     */
    
    // stdarg.h
    
    // string.h
    char    str1[]="this is a string";
    char    str2[40];
    strcpy(str2, str1);
    cout << str2 << endl;
}

void contaninertest()
{
    // <array> -- fixed-size container
    array<int, 10>myarr = {3,5,5,7,4,5,1,1,2,9};
    myarr.back();
    myarr.front();

    // <deque> -- double-ended queue
    deque<int>mydeque;
    mydeque.push_back(10);
    mydeque.push_front(5);
    mydeque.front();
    mydeque.back();
    
    // <forward_list> -- singly-linked list
    forward_list<int> myflist;
    myflist.insert_after(myflist.before_begin(), 100);
    
    // <list>  -- doubly-linked list
    list<int> mylist;
    mylist.size();
    
    // <map>, <multimap>, <unordered_map>
    // pair<key, value>
    map<char, int>mymap;
    mymap.insert(pair<char, int>('b',100));
    mymap.insert(pair<char, int>('a',200));
    mymap.insert(pair<char, int>('c',400));
    mymap.insert(pair<char, int>('d',300));
    mymap.insert(pair<char, int>('a',500)); // this doesn't work, key is unique
    for(auto it = mymap.begin(); it!= mymap.end(); it++){
        cout << it->first << " " << it->second << endl;;
    }
    
    // <queue> -- FIFO
    queue<int>  myqueue;
    myqueue.push(100);
    myqueue.pop();
    myqueue.pop();  // bad access
    
    // <set>, <multiset>, <unordered_set> -- value is itself the key, must be unique.
    int myints[]= {10,20,30,40,50};
    set<int> myset (myints,myints+5);        // range
    
    // <stack> -- LIFO
    stack<int>  mystack;
    mystack.push(100);
    if(!mystack.empty())
        mystack.pop();
    
    // <vector> -- array can change size
    vector<int> myvector;
    myvector.push_back(100);
    if(!myvector.empty())
        myvector.pop_back();
}

void iotest()
{
    char str[256];
    ifstream    ifs("iostest.h");
    ofstream    ofs("iostest.h.bak");

    ifs.getline(str, 256);
    ofs.write(str,256);
}

mutex  mtx;
void print_thread(int n, char ch)
{
    mtx.lock();
    for(int i=0; i<n; i++){
        cout << ch;
    }
    cout << endl;
    mtx.unlock();
}

void multithread()
{
    thread th1(print_thread, 50, 'A');
    thread th2(print_thread, 50, 'B');
    
    th1.join();
    th2.join();
}

int main(int argc, const char * argv[])
{
    string  str1("Hellow World!");
    cout << str1 << endl;
    //reverse(str1.begin(), str1.end());
    //cout << str1 << endl;
    
    cout << "pelease select:" <<endl;
    cout << "clibrarytest: 1" <<endl;
    cout << "contaninertest: 2" <<endl;
    cout << "input/output: 3" <<endl;
    cout << "multi-thread: 4" <<endl;
    
    int sel;
    cin >> sel;
    
    switch (sel) {
        case 1:
            clibrarytest();
            break;
        case 2:
            contaninertest();
            break;
        case 3:
            iotest();
            break;
        case 4:
            multithread();
            break;
        default:
            break;
    }
    return 0;
}

