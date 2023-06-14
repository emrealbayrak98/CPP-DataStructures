#include "StackArray.h"
#include <vector>
#include <cassert>

template <class ItemType>
Stack<ItemType>::Stack(): top(-1)
{
}

template <class ItemType>
bool Stack<ItemType>::isEmpty() const
{
    return top < 0;
}

template <class ItemType>
bool Stack<ItemType>::isFull() const
{
    return (top >= MAX_ITEM-1);
}

template <class ItemType>
bool Stack<ItemType>::push(const ItemType& newEntry) 
{
    
    if(!isFull())
    {
        top += 1;
        items[top] = newEntry;
    }
    return !isFull();
}

template <class ItemType>
bool Stack<ItemType>::pop()
{
    if(!isEmpty())
    {
        top -= 1;
    }
    return !isEmpty();
}

template <class ItemType>
ItemType Stack<ItemType>::peek() const
{
    //use precondition 
    assert(!isEmpty());

    return items[top];
}

template <class ItemType>
int  Stack<ItemType>::sizeOfStack() 
{
    return (top+1);
}

