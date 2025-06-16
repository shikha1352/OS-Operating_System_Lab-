#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Process {
    int id;
    int bt;     
    int at;    
    int wt;     
    int tat;    
    int ct;    
};
bool sortByArrival(const Process &a, const Process &b){
    return a.at < b.at;
}
int main(){
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process>p(n);
    cout <<"Enter Arrival Time and Burst Time  for Processes:\n";
    for(int i = 0; i < n; ++i) {
        p[i].id = i + 1;
        cin >> p[i].at>>p[i].bt;
    }
    sort(p.begin(), p.end(), sortByArrival);
    int current_time = 0;
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; ++i) {
        if (current_time < p[i].at)
            current_time = p[i].at;
        p[i].wt = current_time - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        p[i].ct = current_time + p[i].bt;
        current_time += p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    cout << "\nPR\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].wt << "\t"
             << p[i].tat << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << "\n";

    // Gantt Chart
    cout << "\nGantt Chart:\n";
    cout << "|";
    for (int i = 0; i < n; ++i) {
        cout << "  P" << p[i].id << "  |";
    }
    cout << "\n";

    cout << p[0].at;
    for (int i = 0; i < n; ++i) {
        if (i == 0 && p[i].at != 0)
            cout << setw(6) << p[i].ct;
        else
            cout << setw(6) << p[i].ct;
    }
    cout << "\n";

    return 0;
}
