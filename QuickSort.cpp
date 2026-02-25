#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
int temp= a;
a= b ;
b= temp ;
}

int partation(int a[] , int f ,int  l)
{
    int pvt = a[f];
    int i = f ; 
    int j = l ;
    while (i<j)
    {
        while (a[i]<=pvt)
        {
            i++;
        }
        while(a[j]>pvt)
        {
            j--;
        }

        if (i<j)
        {
            swap(a[i],a[j]);
        }
    }
swap(a[f],a[j]);
return  j ; 
}

void quicksort (int a[] , int f , int l)
{
    if (f<l)//invalid range f>l
    {
    int part = partation(a, f, l );
    quicksort(a,f,part-1);
    quicksort(a,part+1,l);
   }
}




int main()
{

int a[]= { 1,2,3,2,5,4};
int size = sizeof(a)/sizeof (a[0]);

quicksort(a,0,size-1);

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

return 0 ;


}
