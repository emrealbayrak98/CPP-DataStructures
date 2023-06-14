//
//  Node.h
//  LinkedBag
//
//  Created by İsmail Uyanik on 10/20/22.
//

#ifndef Node_h
#define Node_h

class Node{
    private:
    public:
        int item;
        Node* next;
        Node(const int anItem){
            item = anItem;
            next = nullptr;
        }
};

#endif /* Node_h */
