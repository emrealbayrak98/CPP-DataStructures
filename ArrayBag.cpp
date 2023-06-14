#include <stdio.h>
#include <iostream>
#include "ArrayBag.h"

using namespace std;

ArrayBag::ArrayBag()
{
    maxItems = DEFAULT_CAPACITY;
    itemCount = 0;
}

int ArrayBag::getCurrentSize() const
{
    
    return itemCount;
}

bool ArrayBag::isEmpty() const
{
    return itemCount == 0;
}

bool ArrayBag::add(const std::string& newEntry)
{
    bool hasRoomToAdd = itemCount < maxItems;
    if (hasRoomToAdd) {
        items[itemCount++] = newEntry;
    }
    return hasRoomToAdd;
}

bool ArrayBag::remove(const std::string& anEntry)
{
    int itemToBeRemoved = getIndexOf(anEntry);
    bool canRemoveItem = itemToBeRemoved >= 0;
    if (canRemoveItem) {
        items[itemToBeRemoved] = items[--itemCount];
    }
    return canRemoveItem;
}

void ArrayBag::clear()
{
    itemCount = 0;
}

void ArrayBag::displayContent() const
{
    for (int idx = 0; idx < itemCount; idx++) {
        std::cout << items[idx] << " ";
    }
}

bool ArrayBag::contains(const std::string& anEntry) const
{
    return getIndexOf(anEntry) >= 0;
}

int ArrayBag::getFrequencyOf(const std::string& anEntry) const
{
    int frequency = 0;
    for (int idx = 0; idx < itemCount; idx++) {
        if (items[idx] == anEntry) {
            frequency++;
        }
    }
    cout << "Freq of " << anEntry << " is " << frequency << endl;
    return frequency;
}

void ArrayBag::printMessage() const{
    cout << "Size is " << getCurrentSize()  <<  endl;
}

// private
int ArrayBag::getIndexOf(const std::string& target) const
{
    for (int idx = 0; idx < itemCount; idx++) {
        if (items[idx] == target) {
            return idx;
        }
    }
    return -1;
}
int main(){
    string a;
    string entry;
    ArrayBag create;
    for (int i = 0; i < 6; i++)
    {
         getline(cin,entry);
         create.add(entry);
    }

    
    create.displayContent();
    create.getCurrentSize();
    create.printMessage();
    for (int f=create.getFrequencyOf("4") ; f > 0 ; f--)
    {
        create.remove("4");
    }
    
    create.displayContent();
    create.getCurrentSize();
    create.printMessage();
    create.getFrequencyOf("4");
    
    // create.getFrequencyOf("3");
    

    // create.printMessage();
    return 0;
}
