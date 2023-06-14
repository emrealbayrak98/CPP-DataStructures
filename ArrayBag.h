#ifndef ArrayBag_h
#define ArrayBag_h

#include <string>   // For string objects

class ArrayBag
{
private:
   static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
   std::string items[DEFAULT_CAPACITY];   // Array of bag items
   int itemCount;                         // Current count of bag items
   int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain
   // the target.
   int getIndexOf(const std::string& target) const;

public:
    ArrayBag();
    int  getCurrentSize() const;
    bool isEmpty() const;
    bool add(const std::string& newEntry);
    bool remove(const std::string& anEntry);
    void clear();
    bool contains(const std::string& anEntry) const;
    int  getFrequencyOf(const std::string& anEntry) const;
    void displayContent() const;
    void printMessage() const;
    // void printMessage(const bool& message) const;
    // void printMessage(const int& message) const;
    
};

#endif

