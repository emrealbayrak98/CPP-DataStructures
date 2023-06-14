#include <iostream>
using namespace std;

// A function to perform swap operation
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to print array contents
void printarray(int array[],int size){
    
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " ;
    }
    // cout << endl;
    
}

// A function to implement selection sort
void selectionSort(int array[],int size){
    int counter=0;
    cout << "Unsorted array: " ;
    printarray(array,size);
    cout << endl << "Sorted array: " ;
    bool isSwapable = true;
    

        for(int pass=0;pass < size -1; pass++){
            if(isSwapable){
            bool isSwapable = false;
            for(int index=pass+1;index < size ;index++){
            if(array[pass] > array[index]){
                int temp = array[pass];
                array[pass]=array[index];
                array[index] = temp;
                bool isSwapable = true;

                }
                counter++;

            
            }
    // cout << "Pass: " << pass << endl;
    // printarray(array,size);
        }
    }
    printarray(array,size);
    cout << endl << "Steps required: " << counter << endl;
}

// A function to implement selection sort
void selectionSort2(int array[],int size){
    int counter=0;
    int minIdx;
    int temp;
    cout << "Unsorted array: " ;
    printarray(array,size);
    cout << endl << "Sorted array: " ;
    
    for(int pass=0;pass < size -1; pass++){
        minIdx = pass;
        for(int i=pass+1;i < size ;i++){
            if(array[i] < array[minIdx]){
                minIdx = i;
                }
                temp = array[pass];
                array[pass]=array[minIdx];
                array[minIdx] = temp;
                counter++;
            
        }
    // cout << "Pass: " << pass << endl;
    // printarray(array,size);
    }

    printarray(array,size);
    cout << endl << "Steps required: " << counter << endl;
}

// A function to implement bubble sort
void bubbleSort(int array[],int size){
    cout << "Unsorted array: " ;
    printarray(array,size);
    cout << endl << "Sorted array: " ;
    int counter2=0;
    int counter=0;
    int pass=0;
    bool isSwapable = true;
    for(int i=0;i < size -1 ; i++){
        
        if(isSwapable){
        isSwapable = false;    
        counter=0;
        
        for(int index = pass +1;index < size ;index++,pass++){
            if(array[pass] > array[index]){
                int temp = array[pass];
                array[pass]=array[index];
                array[index] = temp;
                isSwapable= true;
                }
            // Print for each step
            // cout << endl << "step" << counter2 << ": " << endl;
            // printarray(array,size);
            counter++;
            counter2++;
            
        }
        printarray(array,size);
        cout << endl;
        pass = pass - counter ;
        }
    }
     
    printarray(array,size);
    cout << endl << "Steps required: " << counter2 << endl;
}  
 
// A function to implement bubble sort
void bubbleSort2(int arr[], int size)
{
    cout << "Unsorted array: " ;
    printarray(arr,size);
    cout << endl << "Sorted array: " ;
    int counter=0;
    bool isSwapable = true;
    //15 12 15 20 21 25
    for (int i = 0; i < size - 1; i++)
        if(isSwapable){
        isSwapable = false;
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++){
            
            counter++;
            if (arr[j] > arr[j + 1]){
                isSwapable = true;
                swap(&arr[j], &arr[j + 1]);
                }
            printarray(arr,size);
            cout << endl; 
        }
               
    }
    
    cout << endl << "Steps required: " << counter << endl;
}

int main(){
    // ARRAY EXAMPLES:
    int sz=10;
    int array1[sz];
    // int array1[]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    // int array1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    // int array1[]={1,2,3,1,5,6,1,8,9,2,11,12,13,14,15};
    // int array1[]={10,21,1,94,84,22,13,79,13,21,18,15,3,12,7};
    for(int i=0;i<sz;i++)
      array1[i]=rand()%50;
    int size1 = sizeof(array1) / sizeof(array1[0]);
    
    // selectionSort(array1,size1);
    // selectionSort2(array1,size1);
    bubbleSort2(array1,size1);
    // bubbleSort2(array1,size1);


}