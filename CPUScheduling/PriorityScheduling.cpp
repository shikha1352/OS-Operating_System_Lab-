#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<int> pid(n),bt(n),priority(n),wt(n),tat(n);
    cout << "Enter Burst Time and Priority for each process:\n";
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> bt[i]>> priority[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[j] < priority[i]) {
                swap(priority[i], priority[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    float total_wt=0,total_tat=0;
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    cout << "\nPR\tBT\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << bt[i] << "\t"
             << priority[i] << "\t\t"
             << wt[i] << "\t"
             << tat[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";
    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < n; i++) {
        cout << "  P" << pid[i] << "  |";
    }
    cout << "\n";
    int ct = 0;
    for (int i = 0; i < n; i++) {
        ct += bt[i];
        cout << setw(6) << ct;
    }
    cout << "\n";

    return 0;
}
