#include <bits/stdc++.h>
using namespace std;

void swaap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int f, int l)
{
    int pivot = a[f];
    int i = f;
    int j = l;

    while (i < j)
    {
        while (a[i] <= pivot && i < l)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swaap(a[i], a[j]);
    }

    swaap(a[f], a[j]);
    return j;
}

void quicksort(int a[], int f, int l)
{
    if (f < l)
    {
        int p = partition(a, f, l);
        quicksort(a, f, p - 1);
        quicksort(a, p + 1, l);
    }
}

int main()
{
    int a[] = {6, 3, 8, 11, 14, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

