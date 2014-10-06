//
//  main.cpp
//  Stack Implementation
//
//  Created by Badri Krishnan on 9/30/14.
//  Copyright (c) 2014 Badri Krishnan. All rights reserved.
//

#include <iostream>
using namespace std;

class Stack{
public:
    Stack();
    ~Stack();
    void push(void *data);
    void *pop();
    void print();
protected:
    typedef struct Element {
        struct Element *next;
        void *data;
    } Element;
    
    Element *top;
    
};

Stack::Stack(){
    top = NULL;
}

/*Loops one by one through the linked stack and deletes the top until nothing is left*/
Stack::~Stack() {
    while(top) {
        Element *elm = top->next;
        delete top;
        top = elm;
    }
}
/*Takes data as the parameter and creates new link node and then sets element next equal to current top and then sets top equal to the new element thus finishing the "Push" operation*/
void Stack::push(void *data){
    Element *push_elm = new Element;
    push_elm->data = data;
    push_elm->next = top;
    top = push_elm;
}
/*Check if the top is null, if not then we set pop_data equal to data at top, then move the top pointer the next element in stack, and delete the pop node*/
void *Stack::pop() {
    void *pop_data;
    
    if(top == NULL)
        return pop_data;
    
    pop_data = top->data;
    Element *pop_elm = top;
    top = pop_elm->next;
    delete pop_elm;
    return pop_data;
}
/*Print out the values of stack until we reach an elm pointer whose value is NULL*/
void Stack::print() {
    Element *elm = top;
    while(elm) {
        cout << *(static_cast<int*>(elm->data)) << " " ;
        elm = elm->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Stack *st = new Stack;
    int n1 = 10;
    int n2 = 20;
    int n3 = 30;
    int n4 = 40;
    int n5 = 50;
    st->push(&n1);
    st->push(&n2);
    st->push(&n3);
    st->push(&n4);
    st->push(&n5);
    st->print();
    cout << *(static_cast<int*>(st->pop()))<< " poped\n";
    cout << *(static_cast<int*>(st->pop()))<< " poped\n";
    st->print();
    cout << endl;
}
