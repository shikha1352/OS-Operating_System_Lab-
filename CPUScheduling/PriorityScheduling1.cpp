#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Process {
    int id;
    int at;
    int bt;
    int priority;
    int ct, wt, tat;
    bool completed;
};
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);
    cout << "Enter Arrival Time, Burst Time, and Priority:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].at >> p[i].bt >> p[i].priority;
        p[i].completed = false;
    }
    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;
    vector<int> gantt;
    while (completed != n) {
        int idx = -1;
        int highest_priority = 1e9;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= current_time) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highest_priority) {
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].wt = current_time - p[idx].at;
            if (p[idx].wt < 0) 
                p[idx].wt = 0;
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            current_time += p[idx].bt;
            p[idx].completed = true;
            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
            gantt.push_back(p[idx].id);

            completed++;
        } else {
            current_time++;
        }
    }

    cout << "\nPR\tAT\tBT\tPriority\tCT\tWT\tTAT\n";
    for (const auto &proc : p) {
        cout << "P" << proc.id << "\t"
             << proc.at << "\t"
             << proc.bt << "\t"
             << proc.priority << "\t\t"
             << proc.ct << "\t"
             << proc.wt << "\t"
             << proc.tat << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";
    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < gantt.size(); ++i) {
        cout << "  P" << gantt[i] << "  |";
    }
    cout << "\n0";
    current_time = 0;
    for (int i = 0; i < gantt.size(); ++i) {
        for (auto &proc : p) {
            if (proc.id == gantt[i]) {
                if (current_time < proc.at) current_time = proc.at;
                current_time += proc.bt;
                cout << setw(6) << current_time;
                break;
            }
        }
    }
    cout << "\n";

    return 0;
}
