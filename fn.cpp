#include <bits/stdc++.h> // সব standard library একসাথে include
using namespace std;    // std:: না লিখে সরাসরি ব্যবহার করার জন্য
#define nl '\n'         // newline এর shortcut

// Item নামে structure বানানো
struct Item{
    double p , w , r ; // p = profit, w = weight, r = profit/weight ratio
};

// sort করার জন্য comparator function
bool cmp (Item a , Item b)
{
    return a.r > b.r; // যার ratio বেশি সে আগে থাকবে (descending order)
}

int main()
{
    int n ; cin >> n ; // মোট কয়টা item আছে input নেওয়া
    int c ; cin >> c;  // knapsack capacity (সর্বোচ্চ ওজন)

    Item a[n]; // n সংখ্যক item রাখার array

    // প্রতিটি item এর profit, weight এবং ratio হিসাব
    for (int i = 0 ; i < n; i++)
    {
        cin >> a[i].p >> a[i].w;   // profit ও weight input
        a[i].r = a[i].p / a[i].w;  // ratio = profit/weight
    }

    sort(a, a + n, cmp); // ratio অনুযায়ী descending order এ sort

    double wg = 0;   // এখন পর্যন্ত মোট weight
    double pf = 0.0; // এখন পর্যন্ত মোট profit

    // প্রতিটি item check করা
    for(int i = 0; i < n; i++)
    {
        // যদি পুরো item নেওয়া যায়
        if(wg + a[i].w <= c)
        {
            wg += a[i].w;  // weight যোগ
            pf += a[i].p;  // profit যোগ
        }
        else // পুরোটা নেওয়া না গেলে fractional নেওয়া
        {
            double as = c - wg; // যতটুকু capacity বাকি আছে
            pf += (a[i].p * (as / a[i].w)); // ওই অংশের profit যোগ
            break; // bag পূর্ণ, loop শেষ
        }
    }

    cout << "Maximum Profit: " << pf; // সর্বোচ্চ profit print

    return 0; // program শেষ
}
