#ifndef LinkedBag_h
#define LinkedBag_h

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedBag{
private:
    
    int itemCount;
    
    Node* getPointerTo(const int target) const{
    Node* targetPtr = headPtr;
    while (targetPtr != nullptr) {
        if (targetPtr->item == target) {
            return targetPtr;
        }
        targetPtr = targetPtr->next;
    }
    return targetPtr;
};
public:
    Node* headPtr;
    LinkedBag(){
    headPtr = nullptr;
    itemCount = 0;
};
    virtual ~LinkedBag(){
    clear();
};
    int getCurrentSize() const{
    return itemCount;
};
    bool isEmpty() const{
    return itemCount == 0;
};
    bool add(const int newEntry){
    if(itemCount == 0){
        headPtr = new Node(newEntry);
    }
    else{
        Node* nodeToBeAdded = new Node(newEntry);
        if (nodeToBeAdded ->item < headPtr->item) {
            nodeToBeAdded->next = headPtr;
            headPtr = nodeToBeAdded;
        }
        else{
            Node* prev = nullptr;
            Node* cur  = headPtr;
            while ((cur != nullptr) && (cur->item < nodeToBeAdded->item)) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nodeToBeAdded;
            nodeToBeAdded->next = cur;
        }
    }
    itemCount++;
    return true;
};
bool add_rand(const int newEntry){
    if(itemCount == 0){
        headPtr = new Node(newEntry);
    }
    else{
        Node* nodeToBeAdded = new Node(newEntry);
        Node* cur = headPtr;
        Node* prev ;
        while (cur->next != nullptr)
        {
            cur=cur->next;
        }
        cur->next = nodeToBeAdded;
        nodeToBeAdded->next=nullptr;
    }
    itemCount++;
    return true;
};

    bool remove(const int anEntry){
    do
    {
    Node* nodeToBeRemoved = getPointerTo(anEntry);
    bool canRemoveItem = (nodeToBeRemoved != nullptr);
    if(canRemoveItem){
        if (nodeToBeRemoved == headPtr) {
            headPtr = headPtr->next;
        }
        else{
            Node* prev = headPtr;
            while (prev->next != nodeToBeRemoved) {
                prev = prev->next;
            }
            prev->next = nodeToBeRemoved->next;
        }
        nodeToBeRemoved->next = nullptr;
        delete nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        itemCount--;
    }    /* code */
    } while (getFrequencyOf(anEntry)!=0);
    

    return true;
};
    void clear(){
    Node* nodeToBeRemoved = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->next;
        nodeToBeRemoved->next = nullptr;
        delete nodeToBeRemoved;
        nodeToBeRemoved = headPtr;
    }
    itemCount = 0;
};
    bool contains(const int anEntry) const{
    return (getPointerTo(anEntry) != nullptr);
};
    int getFrequencyOf(const int anEntry) const{
    int frequency = 0;
    for (Node* cur = headPtr; cur != nullptr; cur = cur->next) {
        if (anEntry == cur->item) {
            frequency++;
        }
    }
    return frequency;
};
    void printBag() const{
    Node* cur = headPtr;
    while (cur != nullptr) {
        std::cout << cur->item << " ";
        cur = cur->next;
    }
};
//Q3
    int sumBag() const{
        int sum=0;
        Node* cur=headPtr;
        while(cur!=nullptr){
            sum += cur->item;
            cur = cur->next;
        }
        return sum;
    };
};

    
    void removeLargest(Node* headptr){
        Node* cur = headptr->next;
        Node* prev = headptr;
        int max;

        while (cur->next!=nullptr)
        {
           if (cur->item > prev->item)
           {
            prev = cur;
           }
           cur = cur->next; 
        }
        cur = headptr->next;;
        max=prev->item;
        prev = headptr;

        while (cur->next!=nullptr)
        {
            
            
            if (cur->item == max)
           {
            
            prev->next = cur->next;
            
           }
        
            prev = prev->next;
            cur = prev->next;
        }
        

        
    }
#endif /* LinkedBag_h */
