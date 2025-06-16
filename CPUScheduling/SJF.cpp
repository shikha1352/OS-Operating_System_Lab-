#include <iostream>
#include <vector>
using namespace std;
void sjf(int n, vector<int>& process, vector<int>& bt) {
    vector<int> wt(n), tat(n);
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (bt[j] < bt[min_idx]) {
                min_idx = j;
            }
        }
        swap(bt[i], bt[min_idx]);
        swap(process[i], process[min_idx]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    int total_wt = wt[0], total_tat = tat[0];

    for (int i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << process[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }
    cout << "\nAverage Waiting Time: " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time: " << (float)total_tat / n << "\n";
    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < n; ++i) {
        cout << "  P" << process[i] << "  |";
    }
    cout << "\n0";
    int time = 0;
    for (int i = 0; i < n; ++i) {
        time += bt[i];
        cout << "\t" << time;
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> process(n), bt(n);
    cout << "Enter process ID and burst time:\n";
    for (int i = 0; i < n; ++i) {
        cin >> process[i] >> bt[i];
    }

    sjf(n, process, bt);
    return 0;
}
