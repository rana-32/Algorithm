#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int st; // activity এর start time
    int ft; // activity এর finish time
};

bool cmp(Activity a, Activity b)
{
    return a.ft < b.ft;   // finish time ছোট হলে আগে থাকবে (finish time অনুযায়ী sort)
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n; // মোট কয়টা activity আছে

    Activity act[20]; // সর্বোচ্চ ২০টা activity রাখার জন্য array

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].st >> act[i].ft; // প্রতিটি activity এর start এবং finish time input
    }

    // Step 1: finish time অনুযায়ী activity গুলো sort করা
    sort(act, act + n, cmp);

    int A[20]; // select হওয়া activity এর index রাখার জন্য array
    int count = 0; // কয়টা activity select হয়েছে তা রাখবে

    // Step 2: প্রথম activity select করা
    A[count++] = 0; // প্রথম activity select
    int j = 0; // last selected activity এর index

    // Step 3 & 4: বাকি activity গুলো check করা
    for (int i = 1; i < n; i++)
    {
        // যদি current activity এর start time ≥ last selected activity এর finish time
        if (act[i].st >= act[j].ft)
        {
            A[count++] = i; // activity select করা
            j = i; // last selected activity update করা
        }
    }

    cout << "Selected Activities:\n";
    for (int i = 0; i < count; i++)
    {
        cout << act[A[i]].st << " " << act[A[i]].ft << endl;
        // selected activity এর start এবং finish time print
    }

    cout << "Maximum activities = " << count << endl; // মোট কতগুলো activity select হয়েছে

    return 0;
}
