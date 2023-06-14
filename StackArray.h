
#ifndef _STACKARRAY_H
#define _STACKARRAY_H

#include "StackArray.h"
#include <vector>
#include <cassert>
//Max array size
#define MAX_ITEM 50


class Stack
{
private:
    char items[MAX_ITEM];
    int top;
public:
    //Constrction fuction
    Stack(): top(-1)
    {
    };
    //add new element to top of the array if it is not full
    bool push(int newEntry){
    
    if(!isFull())
    {
        top += 1;
        items[top] = newEntry;
    }
    return !isFull();
    };
    //delete  top element  of the array if it is not empty
    bool pop(){
    if(!isEmpty())
    {
        top -= 1;
    }
    return !isEmpty();
    };
    //Check the array is empty or not
    bool isEmpty() const{
    return top < 0;
    };
    //Check the array is full or not
    bool isFull() const{
    return (top >= MAX_ITEM-1);
    };
    //Return the top element of the stack
    char peek() const{
    //use precondition 
    assert(!isEmpty());

    return items[top];
    };
    //return size of stack
    int sizeOfStack(){
    return (top+1);
    } ;

};

#endif