#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int st;
    int ft;
};

bool cmp(Activity a, Activity b)
{
    return a.ft < b.ft;   // finish time অনুযায়ী sort
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity act[20];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].st >> act[i].ft;
    }

    // Step 1: sort according to finish time
    sort(act, act + n, cmp);

    int A[20];
    int count = 0;

    // Step 2: select first activity
    A[count++] = 0;
    int j = 0;

    // Step 3 & 4
    for (int i = 1; i < n; i++)
    {
        if (act[i].st >= act[j].ft)
        {
            A[count++] = i;
            j = i;
        }
    }

    cout << "Selected Activities:\n";
    for (int i = 0; i < count; i++)
    {
        cout << act[A[i]].st << " " << act[A[i]].ft << endl;
    }

    cout << "Maximum activities = " << count << endl;

    return 0;
}
