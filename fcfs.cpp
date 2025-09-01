#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    int burstTime[n], waitingTime[n], turnaroundTime[n];

    cout << "Enter Burst Times for each process:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ": ";
        cin >> burstTime[i];
    }

    // Initialize first process waiting time to 0
    waitingTime[0] = 0;

    // Calculate waiting time for each subsequent process
    for(int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    // Calculate turnaround time for all processes
    for(int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    // Display the results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    // Calculate average waiting time and average turnaround time
    float totalWaiting = 0, totalTurnaround = 0;
    for(int i = 0; i < n; i++) {
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
    }

    cout << "\nAverage Waiting Time: " << totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / n << endl;

    return 0;
}
