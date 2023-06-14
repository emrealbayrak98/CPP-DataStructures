#include <stdio.h>
#include "LinkedBag.h"
#include "Node.h"

int main(){
    int a;
    int b;
    LinkedBag linkedbag1;
    std::cin >> b;
        for (b; b > 0; b--){
            std::cin>> a;
            linkedbag1.add(a);    
        }
    linkedbag1.printBag();
    // if(linkedbag1.contains(4)){
    //     std::cout << " It contains 4";
    // }
    // linkedbag1.add(5);
    // linkedbag1.printBag();

    
        for (a=linkedbag1.getFrequencyOf(5); a!=0; a--)
        {
            linkedbag1.remove(5);
        }
        
    linkedbag1.printBag();
    
    
    



    return 0;
}