#include <iostream>

using namespace std;

int findMin(int a[], int n)
{
    int min = a[0];
    int index=0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
        min = a[i];
        index=i;
        }
    }
    return index;

}

int findMax(int a[], int n)
{
    int max = a[0];
    int index=0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
        max = a[i];
        index=i;
        }
    }

    return index;
}

void swap(int *a, int *b)
{
    int storenum= *a;
    *a=*b;
    *b=storenum;
}

void selectionSort(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        

        //find min of sub array starting i to end

        int minIndex = findMin(&a[i],n-i);
        
        //swap min with the left most value
        swap(&a[minIndex+i], &a[i]);
        



    }
    
}

int main()
{
    int d[] = {6, 0, 7, 2, 14, -1, 8, 9};

    int minIndex = findMin(d, 8);
    cout << "minIndex:  expected=5 actual=" << minIndex << endl;

    int maxIndex = findMax(d, 8);
    cout << "maxIndex:  expected=4 actual=" << maxIndex << endl;

    swap(&d[3], &d[4]);
    cout << "d[3] and d[4] after swap: expected=(14,2) actual=(" << d[3] << "," << d[4] << ")" << endl;

    int *a = &d[0];
    int *b = &d[1];
    swap(a, b);
    swap(a, &d[2]);
    cout << "*a, *b, and d[2] after swap: expected=(7, 6, 0) actual=(" << *a << ", " << *b << ", " << d[2] << ")" << endl;

    selectionSort(d, 8);
    cout << "expected -1, 0, 2, 6, 7, 8, 9, 14," << endl;
    cout << "actual ";
    for(int i = 0; i < 8; i++)
        cout << d[i] << ", ";
}
