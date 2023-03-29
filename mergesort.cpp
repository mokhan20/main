#include <iostream>

using namespace std;

void merge(int *a, int lengthofA, int lengthofB)
{
  
    int temp[100];

    int foo[lengthofA];
    int foo2[lengthofB];
    int iA=0;
    int iB=0;
    int iC=0;
    for(int i=0;i<lengthofA; i++){
        foo[i]=a[i];
    }
    for(int i=0;i<lengthofB; i++){
        foo2[i]=a[i+lengthofA];
    }
    
    
    while (iA<lengthofA && iB<lengthofB){
        if (foo[iA]<=foo2[iB]){
        temp[iC]=foo[iA];
        iA++;
        iC++;
    }  
        else {
            temp[iC]=foo2[iB];
            iB++;
            iC++;
        }
    }      
    while (iA<lengthofA){
        temp[iC]=foo[iA];
        iA++;
        iC++;
    }
    while (iB<lengthofB){
        temp[iC]=foo2[iB];
        iB++;
        iC++;
    } 
       
    for(int i = 0; i < lengthofA+lengthofB; i++){
        a[i]=temp[i];
        }

}
    


void mergeSort(int *a, int n)
{
    if(n==0 || n==1){
        return;
    }
mergeSort(a,n/2);
mergeSort(&a[(n/2)], n-n/2);
merge(a, n/2, n-n/2);

}

int main()
{
    int b[] = {3,5,7,8,2,4,6,7,9};
    int lengthOfLeft = 4, lengthOfRight = 5;
    merge(b, lengthOfLeft, lengthOfRight);
      for(int i = 0; i < lengthOfLeft + lengthOfRight; i++)
        cout << b[i] << endl;

    cout << "----------------------" << endl;  

 
int a[] = {3,2,8,4,5,1,2, -1, -12};
int n = 9;
int left= 4;
int right= 5;

mergeSort(a, n);

for(int i = 0; i < n; i++)
     cout << a[i] << endl;


}
