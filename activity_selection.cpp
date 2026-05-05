#include <iostream>   // input-output (cin, cout) ব্যবহার করার জন্য
#include <algorithm>  // sort ফাংশন ব্যবহার করার জন্য

using namespace std;

// একটি activity (কাজ) represent করার জন্য structure
struct Activity {
    int st;   // activity এর start time (শুরু সময়)
    int ft;   // activity এর finish time (শেষ সময়)
    int idx;  // original index (ইনপুটে কোন নম্বর ছিল সেটা)
};

// finish time অনুযায়ী sort করার জন্য compare function
bool cmp(Activity a, Activity b)
{
    return a.ft < b.ft;   // যার finish time ছোট সে আগে থাকবে
}

int main()
{
    int n;
    cin >> n;   // কয়টা activity আছে সেটা ইনপুট নেওয়া

    Activity act[20];   // maximum 20টা activity রাখা যাবে

    // প্রতিটি activity এর start এবং finish time ইনপুট নেওয়া
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].st >> act[i].ft;  // start এবং finish time ইনপুট
        act[i].idx = i; // original index save করা (কোন input ছিল সেটা মনে রাখতে)
    }

    // finish time অনুযায়ী সব activity sort করা
    sort(act, act + n, cmp);

    int A[20];   // selected activity গুলোর index রাখার জন্য
    int count = 0;  // কয়টা activity select হয়েছে সেটা count করবে

    // প্রথম activity automatically select করা (greedy rule অনুযায়ী)
    A[count++] = 0;
    int j = 0;   // last selected activity এর index (sorted array অনুযায়ী)

    // বাকি activity গুলো check করা
    for (int i = 1; i < n; i++)
    {
        // যদি current activity start time >= last selected activity finish time
        if (act[i].st >= act[j].ft)
        {
            A[count++] = i; // এই activity select করা
            j = i;          // last selected update করা
        }
    }

    // output শুরু
    cout << "Selected Activities:\n";

    // selected activity গুলো print করা
    for (int i = 0; i < count; i++)
    {
        cout << act[A[i]].idx << "-->"   // original index দেখানো
             << act[A[i]].st << " "      // start time
             << act[A[i]].ft << endl;    // finish time
    }

    // মোট কয়টা activity select হয়েছে
    cout << "Maximum activities = " << count << endl;

    return 0;  // program শেষ
}
