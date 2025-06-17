#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> pid(n), bt(n), remaining_bt(n), wt(n, 0), tat(n), ct(n);
    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> bt[i];
        remaining_bt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    int time = 0;
    vector<int> gantt;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (remaining_bt[i] > tq) {
            time += tq;
            remaining_bt[i] -= tq;
            q.push(i);
        } else {
            time += remaining_bt[i];
            ct[i] = time;
            tat[i] = ct[i];
            wt[i] = tat[i] - bt[i];
            remaining_bt[i] = 0;
        }

        gantt.push_back(pid[i]);
    }
    float total_wt = 0, total_tat = 0;
    cout << "\nPR\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << pid[i] << "\t" << bt[i] << "\t" << ct[i] << "\t"
             << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;
    cout << "\n\nGantt Chart (Order of Execution):\n|";
    for (int p : gantt) {
        cout << " P" << p << " |";
    }
    cout << "\n";
    time = 0;
    for (int p : gantt) {
        int idx = p - 1;
        if (bt[idx] > tq) {
            if (remaining_bt[idx] > 0)
                bt[idx] -= tq;
            else
                bt[idx] -= bt[idx];
            time += (bt[idx] >= tq ? tq : bt[idx]);
        } else {
            time += (bt[idx] >= tq ? tq : bt[idx]);
        }
        cout << setw(5) << time;
    }
    cout << "\n";

    return 0;
}
