#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int>p(n), At(n), bt(n), ct(n), tat(n), wt(n), rb(n);
    cout << "Enter arrival time and burst time:\n";
    for (int i = 0; i < n; ++i) {
            p[i]=i+1;
        cin >> At[i] >> bt[i];
        rb[i] = bt[i];
    }
    int qt;
    cout << "Enter quantum time: ";
    cin >> qt;
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int>gp,gc;
    int completed=0,current_time=0;
    while (completed < n) {
        if (q.empty()) {
            int min_time = INT_MAX, index = -1;
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && At[i] < min_time) {
                    min_time = At[i];
                    index = i;
                }
            }
            current_time = At[index];
            q.push(index);
            visited[index] = true;
        }

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
        vector<int>a;
        vector<int>b;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && At[j] <= current_time) {
                a.push_back(At[j]);
                b.push_back(j);
                visited[j] = true;
            }
        }
        for(int k=0;k<a.size();k++){
            for(int j=k+1;j<a.size();j++){
                if(a[j]<a[k]){
                    swap(a[j],a[k]);
                    swap(b[j],b[k]);
                }
            }
        }
        for(int j=0;j<b.size();j++){
            q.push(b[j]);
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
