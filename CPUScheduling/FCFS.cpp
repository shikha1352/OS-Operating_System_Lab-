#include<iostream>
#include<vector>
using namespace std;
void fcfs(vector<int>&process, int n, vector<int>&burstTime){
    vector<int>waitingTime(n),turnTime(n);
    int totalWt=0, totalTurn=0; 
    waitingTime[0] = 0;
    cout<<endl<<"Process"<<"\t"<<"Brust Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turn Around Time"<<endl;
    for(int i=0; i<n; i++){
        if(i>0){
           waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
        }
        totalWt += waitingTime[i];
        turnTime[i] = burstTime[i] + waitingTime[i];
        totalTurn += turnTime[i];
 
        cout<<"P"<<process[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t  "<<turnTime[i]<<endl;
    }
    cout<<'\n'<<"Average waiting time: "<< (float)totalWt/ (float)n << endl;
    cout<<"Average turn around time: "<< (float)totalTurn/ (float)n << '\n'<<'\n';
}
int main(){
    int n;
    cout<<"Enter the process number: ";
    cin>>n;
    vector<int>process(n),burstTime(n);
    cout<<"Enter process number & brust time : ";
    for(int i=0; i<n; i++){
        cin>>process[i]>>burstTime[i];
    }
    fcfs(process, n, burstTime);
    return 0;
}