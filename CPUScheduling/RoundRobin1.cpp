
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int>p(n), At(n), bt(n), ct(n), tat(n), wt(n), rb(n);
    cout << "Enter burst time:\n";
    for (int i = 0; i < n; ++i) {
        p[i]=i+1;
        cin >> bt[i];
        rb[i] = bt[i];
    }
    int qt;
    cout << "Enter quantum time: ";
    cin >> qt;
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int>gp,gc;
    int completed=0,current_time=0;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if (rb[i] > qt) {
            current_time += qt;
            rb[i] -= qt;
            gp.push_back(p[i]);
            gc.push_back(current_time);

        } else {
            current_time += rb[i];
            ct[i] = current_time;
            rb[i] = 0;
            completed++;
            gp.push_back(p[i]);
            gc.push_back(current_time);
        }
        if (rb[i] > 0) {
            q.push(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        tat[i] = ct[i] - At[i];
        wt[i] = tat[i] - bt[i];
    }
    cout<<"|";
    for(int i=0;i<gp.size();i++){
        cout<<"  p"<<gp[i]<<"  |";
    }
    cout<<endl;
    cout<<0;
    for(int i=0;i<gc.size();i++){
        cout<<"      "<<gc[i];
    }
    cout<<endl;

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << i+1 << "\t" << At[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}
