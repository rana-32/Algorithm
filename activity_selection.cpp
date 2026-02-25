#include <iostream>
using namespace std;

struct Activity {
    int st; // start time
    int ft; // finish time
};

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity act[20]; // এখানে ২০টা activity রাখার জন্য array বানানো
    cout << "Enter start and finish times:\n";

    for (int i = 0; i < n; ++i) {
        cin >> act[i].st; // start time input
        cin >> act[i].ft; // finish time input
    }

    int A[20]; // select হওয়া activity এর index রাখবে
    int count = 0; // select হওয়া activity এর সংখ্যা

    // প্রথম activity select করি
    A[count++] = 0; // index 0 select
    int j = 0; // last selected activity এর index

    // বাকি activity check করি
    for (int i = 1; i < n; i++) {
        if (act[i].st >= act[j].ft) { // যদি start time >= last selected finish
            A[count++] = i; // select করি
            j = i; // last selected update করি
        }
    }

    // Output
    cout << "Selected activity indices: ";
    for (int i = 0; i < count; i++) {
        cout << A[i] << " ";
    }
    cout << "\nMaximum activities = " << count << endl;

    return 0;
}
