#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int st, ft, idx; // idx = activity number (1,2,3...)
};

bool cmp(Activity a, Activity b)
{
    return a.ft < b.ft; // sort by finish time
}

int main()
{
    int n;
    cin >> n;

    Activity act[100];

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].st >> act[i].ft;
        act[i].idx = i + 1; // original activity number
    }

    // sort
    sort(act, act + n, cmp);

    int result[100];
    int count = 0;

    // first activity select
    result[count++] = act[0].idx;
    int lastFinish = act[0].ft;

    // greedy selection
    for (int i = 1; i < n; i++)
    {
        if (act[i].st >= lastFinish)
        {
            result[count++] = act[i].idx;
            lastFinish = act[i].ft;
        }
    }

    // output format (important)
    cout << "Solution set = {";
    for (int i = 0; i < count; i++)
    {
        cout << result[i];
        if (i != count - 1) cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}
