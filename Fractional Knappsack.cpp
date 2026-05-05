#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

struct Item{
    double p , w , r ;
};

bool cmp (Item a , Item b)
{
    return a.r > b.r;
}

int main()
{
    int n ; cin >> n ;
    int c ; cin >> c;

    Item a[n];

    for (int i = 0 ; i < n; i++)
    {
        cin >> a[i].p >> a[i].w;
        a[i].r = a[i].p / a[i].w; // FIXED
    }

    sort(a, a + n, cmp);

    double wg = 0;
    double pf = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(wg + a[i].w <= c)
        {
            wg += a[i].w;
            pf += a[i].p;
        }
        else
        {
            double as = c - wg;
            pf += (a[i].p * (as / a[i].w));
            break;
        }
    }

    cout << "Maximum Profit: " << pf;

    return 0;
}
