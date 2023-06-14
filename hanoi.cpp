//
//  main.cpp
//  hanoi
//
//  Created by İsmail Uyanik on 10/7/22.
//

#include <iostream>

void hanoi(int n, char source, char destination, char auxillary){
    
    if (n == 1) {
        printf("Move the top disk from %c to %c\n", source, destination);
        return;
    }
    hanoi(n-1, source, auxillary, destination);
    printf("Move the top disk from %c to %c\n", source, destination);
    hanoi(n-1, auxillary, destination, source);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int n = 5;
    hanoi(n, 'A', 'C', 'B');
    
    return 0;
}
