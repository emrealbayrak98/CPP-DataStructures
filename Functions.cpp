#include <iostream>
#include "LinkedBag.h"
#include "Node.h"
#include "StackArray.h"
#include "queue.h"


using namespace std;
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int array[],int size){
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
}
//Q1
bool removeDup(int array[],int number,int size){
    //1 4 4 5
    for(int i=0;i<size;i++){
        if (array[i]==number)
        {
            array[i] = array[size-1];
            size--;
        }
        
    }


    printArray(array,size);
    return true;
}
//Q2
void mergeArrays(int array1[],int size1,int array2[],int size2){
    int size4= size1 + size2;
    int array3[size4];
    //int size3;
    int i=0;

    for (i = 0; i < size1; i++)
        {
        array3[i]=array1[i];
        }
    for (int a = 0; a < size2; a++,i++)
    {
        {
        array3[i]=array2[a];
        }
    }

    
    printArray(array3,size4);

}
//Q4
int occurrences(int array[],int size,int target){
    int occurence=0;
    for (int i = 0; i < size; i++)
    {
        if (array[i]==target)
        {
            occurence++;
        }
        
    }
    return occurence;
}
//Q5
void printReverse(string array[],int size){
    int a= size-1;
    for (int i = 0; i < size; i++,a--)
    {
        cout << array[a] << " ";
    }
    
}

//Q6
int mulRecursive(int number1,int number2){
    
    number2--;
    if(number2!=0){
        number1=number1+mulRecursive(number1,number2);
    }

    return number1;
//123567
}


void coctailsort(int arr[],int N){
    int temp;
    printArray(arr,N);
    cout << endl;
    for (int pass = 0; pass < N/2; pass++)
    {
        
        for (int j = 0; j < N-1-pass; j++ )
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
            // 5 7 2 3 1 6
        }
        
        for (int j = N -1 ; j > pass+1; j-- )
        {
            if (arr[j]<arr[j-1])
            {
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
            // 5 7 2 3 1 6
        }
        
        
    }
    printArray(arr,N);
    
}

bool palindrome(int array[],int size){
    Stack myStack;
    Queue myq;
    for (int i = 0; i < size; i++)
    {
        myStack.push(array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        myq.enqueue(array[i]);
    }
    for (int i = 0; i < size/2; i++)
    {
        int a = myStack.peek();
        int b = myq.peek();
        if (a!=b)
        {
            return false;
        }
        myq.dequeue();
        myStack.pop();
    }
    return true;

}
int minValue(Queue myq){
    int min=myq.peek();
    int size=myq.size();
    for(int i=0;i<size;i++){
        if (myq.peek()<min)
        {
            min=myq.peek();
        }
        myq.dequeue();
    }
    return min;

}

void longest(int array[],int* n,int size){
    int max;
    int difference=0;
    int md[]={max,difference};
    for (int z = 4; z > 0; z--)
    {
        
        if(md[1]==0){
            for (int i = 0; i < size-1; i++){
        int b=i+1;
            if (array[i]<array[b])
            {
                difference= array[b]-array[i];
                if (difference>md[1])
                {
                    md[1]=difference;
                    md[0]=b;
                }
                
            }
        
        }
        }
        //10,9,2,5,3,7,101,18 
        else{
            md[1]=0;
            int a=md[0];
            for (int i = -1; i < a-1; i++){
        int b=i+1;
            if (array[i+1]<array[b+1])
            {
                difference= array[b+1]-array[i+1];
                if (difference>md[1])
                {
                    md[1]=difference;
                    md[0]=b;
                }
                
            }
        
        }

        }
        
    n[z-1]=array[(md[0])];
    }
     //10,9,2,5,3,7,101,18  
}

int Ascending(Node* myptr){
    if(myptr->next==nullptr){
            return 1;
        }
    if(myptr->item<myptr->next->item){
        
        return Ascending(myptr->next);
    }
    else{
        return 0;
    }
}

void insertionSort(int arr[], int n) 
{ 
    int temp;
    printArray(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        temp = i;
        while (arr[i+1]<arr[i] && i>=0)
        {
            swap(&arr[i], &arr[i + 1]);
            i--;
            printArray(arr, n);
            cout << endl;
        }
        i=temp;
        
    }
    
} 
void commonItems(int array1[],int array2[],int size1,int size2){
    for (int i = 0; i < size1; i++)
    {
        for (int b = 0; b < size2 ; b++)
        {
            if (array1[i]==array2[b]&&(array1[i]!=array1[i-1] && array2[b]!=array2[b-1]))
            {
                cout << array1[i] << " " ;
            }
            
        }
        // int a[]={1,1,3,3,5,7,17,25,33,41};
        // int a1[]={1,5,5,10,13,17,33,41,45,53,51};
    }
    
    
}
int FindFrequency(int array[],int size,int target){
    int low=0;
    int mid;
    int high=size-1;
    int freq=0;

    while (high >= low)
    {
        mid= (high + low)/2;
        if (array[mid]==target)
        {
            freq++;
            break;
        }
        if (array[mid] > target)
        {
            high= mid-1;
        }
        if (array[mid] < target)
        {
            low= mid+1;
        }
        
    }
    while (array[mid]==array[mid+1])
    {
        freq++;
        mid+=1;
    }
    mid-=(freq-1);
    while (array[mid]==array[mid-1])
    {
        freq++;
        mid-=1;
    }
    return freq;
    
    
}

    
void merge(int array[],int low,int high){
    int mid= low + (high - low) / 2;
    int leftsize=mid-low+1;
    int rightsize=high-mid;
    int leftarray[leftsize];
    int rightarray[rightsize];
    for (int i = 0; i < leftsize; i++)
    {
        leftarray[i] = array[low+i];
    }
    for (int i = 0; i < rightsize; i++)
    {
        rightarray[i] = array[mid +1+i];

    }
    int i_R=0;
    int i_L=0;
    int i_T=low;
    while(i_L <leftsize && i_R <rightsize)
    {
        if (leftarray[i_L]<=rightarray[i_R])
        {
            array[i_T]=leftarray[i_L];  
            i_L++;
        }
        else 
        {
            array[i_T]=rightarray[i_R];
            i_R++;
        }
        i_T++;
    }
    while (i_R<rightsize)
    {
        array[i_T]=rightarray[i_R];
        i_R++;
        i_T++;
    }
    while (i_L < leftsize)
    {
        array[i_T]=leftarray[i_L];
        i_L++;
        i_T++;
    }
        
        
        
//1,13,14,14,2,17,18,22  
}

void mergeSort(int array[],int low,int high){
    
    if (low >= high)
        return;
        
    int mid= low + (high - low) / 2;
    mergeSort(array,low,mid);
    mergeSort(array,mid+1,high);
    merge(array,low,high);
    

}
//0     1    2   3   4   5   6   7    
//low           mid
//low 
void quicksort(int array[],int low,int high){
    
}               
int main(){
    //int a[]={'D','C','B','A'};
    int a[]={156,7,3,25,14,3,15,17,65,156,97,84,55,14,3,17,65,3,25,84,3,156,25,34,85};
    // int a[]={14,3,17,65,3,25,84,3,156,25,34,85};
    //int a[]={1,3,4,4,5,7,8,12,12,12,14,17,17};
    // int a[]={1,5,5,10,13,4,7,17,18,22};
    // int a[]={1,13,14,14,2,17,18,22};
    //string b[]={"Bu","deneme","amacli","yazilmis","bir","string","girdisidir."};
    // string b[]={"1","11","7","5","7","2","6","10","11","11","43","9"};

    int sizea= sizeof(a)/sizeof(a[0]);
    //int sizea1= sizeof(a1)/sizeof(a[0]);


//     int sizeb= sizeof(b)/sizeof(b[0]);
//     LinkedBag linkedbag1;
    
//     for (int i = 0; i < sizea; i++)
//     {
//         linkedbag1.add_rand(a[i]); 
//     }

//     Node* linkedbag1ptr = linkedbag1.headPtr;
//     cout << Ascending(linkedbag1.headPtr);

//     linkedbag1.printBag();
//     cout << endl;
    
//     cout << linkedbag1.sumBag();

//     cout << endl;    

//     printReverse(b,sizeb);
//     cout << mulRecursive(3,2);
    // coctailsort(a,sizea);
//     cout << a << endl << *a << endl << *(a +2) << endl << a[0] << endl << &a[0]<< endl;

//     Stack mystack1;
//     for (int i = 0; i < sizea; i++)
//     {
//         mystack1.push(a[i]); 
//     }
//     Stack mystack2;
//     Stack mystack3;

//     char dummy = mystack1.peek();
//     mystack2.push(mystack1.peek());
//     mystack1.pop();
//     mystack2.push(mystack1.peek());
//     mystack1.pop();
//     mystack3.push(mystack1.peek());
//     mystack1.pop(); //c
//     mystack1.push(mystack2.peek());
//     mystack2.pop();
//     mystack3.push(mystack2.peek());
//     mystack2.pop();
//     mystack2.push(mystack1.peek());
//     mystack1.pop();
//     mystack3.push(mystack1.peek());
//     mystack1.pop();
//     mystack3.push(mystack2.peek());
//     mystack2.pop();




    
//     cout << mystack.peek();
//     string t_f="false";
//     if (palindrome(a1,sizea1))
//     {
//         t_f="true";
//     }
//     cout << t_f;

//     Queue myqueue;
//     for (int i = 0; i < sizea; i++)
//     {
//         myqueue.enqueue(a[i]); 
//     }
    
//     Queue* myqueueptr= &myqueue;

//     int n[4];
//     longest(a,n,sizea);

        // printArray(a,sizea);


//     cout << minValue(myqueue);
    
//     commonItems(a,a1,sizea,sizea1);

//     linkedbag1.printBag();
//     removeLargest(linkedbag1.headPtr);
//     std::cout << "After removal of the largest: " << endl;
//     linkedbag1.printBag();

//     cout << FindFrequency(a,sizea,12);
// merge(a,0,sizea-1);
// mergeSort(a,0,sizea-1);
// printArray(a,sizea);
insertionSort(a,sizea);
    return 0;
}
