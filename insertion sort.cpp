#include <iostream>
using namespace std;

bool isLessThan(char const *a, char const *b)
{
    while (*a!=0){
        if(*a>*b){
            return 0;
        }
        if(*a<*b){
            return 1;
        }
        a++;
        b++;
    }
    return *b!=0;

}
bool isMoreThan(char const *a, char const *b)
{

    while (*a!=0){
        if(*a>*b){
            return 1;
        }
        if(*a<*b){
            return 0;
        }
        a++;
        b++;
    }
    return *b!=0;

}

void insertionSortAsc(char const **a, int n)
{
    for (int i = 1; i < n; i++)
    {
        char const *k = a[i];
        int j = i - 1;
        while (j >= 0 && isLessThan(k, a[j]))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
            //this is where we need to shift values to the right
            //how can we accomplish this so that all values greater
            //than k end up shifted to the right once.
        }


    }


void insertionSortDesc(char const **a, int n)
{
    for (int i = 1; i < n; i++)
    {
        char const *k = a[i];
        int j = i - 1;
        while (j >= 0 && isMoreThan(k, a[j]))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }

}

int main(int argc, char **argv)
{
    char const *a[] = {"Austin", "Myles", "Haris", "Domantas", "Malcolm"};
    int n = 5;

    insertionSortAsc(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    cout << endl;
 
    insertionSortDesc(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl; 

}
