#include <iostream>
using namespace std;

void merge(int a[], int f, int mid, int l)
{
    int i = f, j = mid + 1, k = f;
    int tmp[100000];

    while (i <= mid && j <= l)
    {
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= l)
        tmp[k++] = a[j++];

    for (int x = f; x <= l; x++)
        a[x] = tmp[x];
}

void mergeSort(int a[], int f, int l)
{
    if (f < l)
    {
        int m = f + (l - f) / 2;
        mergeSort(a, f, m);
        mergeSort(a, m + 1, l);
        merge(a, f, m, l);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
