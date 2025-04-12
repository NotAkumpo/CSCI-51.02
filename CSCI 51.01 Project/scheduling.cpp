#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    private:
        int arrival;
        int burst;
        int priority;
        int remainingTime;
        int index;

    public:
        Process(int arrival, int burst, int priority, int index) {
            this->arrival = arrival;
            this->burst = burst;
            this->priority = priority;
            this->remainingTime = burst;
            this->index = index;
        }

        // Getters for private members
        int getArrival() const {
            return arrival;
        }

        int getBurst() const {
            return burst;
        }

        int getPriority() const {
            return priority;
        }

        int getRemainingTime() const {
            return remainingTime;
        }

        int getIndex() const {
            return index;
        }
};

// Comparator for sorting processes by arrival time
bool getEarlier(const Process& p1, const Process& p2) {
    if (p1.getArrival() == p2.getArrival()) {
        return p1.getIndex() < p2.getIndex(); // Sort by index if arrival times are equal
    }
    return p1.getArrival() < p2.getArrival();
};

void FCFS(int numProcesses, vector<Process> processes) {
    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), getEarlier);

    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;
    int termination = 0;


    for (const Process& process : processes) {
        firstResponse = max(currentTime, process.getArrival());
        
        if (process.getArrival() < currentTime) {
            waitTime += (termination - process.getArrival());
            cout << "Wait Time: " << waitTime << endl;
        } else {
            idleTime += (process.getArrival() - termination);
            currentTime = process.getArrival();
        }
        termination = firstResponse + process.getBurst();
        
        turnaround += (termination - process.getArrival());
        responseTime += (firstResponse - process.getArrival());

        cout << firstResponse << " " << process.getIndex() << " " << process.getBurst() << "X" << endl;
        currentTime += process.getBurst();
    }

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << "Throughput: " << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << "Waiting Time: " << (static_cast<double>(waitTime) / numProcesses) << endl;
    cout << "Turnaround Time: " << (static_cast<double>(turnaround) / numProcesses) << endl;
    cout << "Response Time: " << (static_cast<double>(responseTime) / numProcesses) << endl; 
}

void STF(int numProcesses, vector<Process> processes) {
    
    // cout << "Round Robin Scheduling Algorithm" << endl;
    // // Print the processes for debugging
    // for (int j=0; j < numProcesses; j++){
    //     cout << "Process " << j+1 << ": Arrival: " << processes[j].getArrival() 
    //          << ", Burst: " << processes[j].getBurst() 
    //          << ", Priority: " << processes[j].getPriority() 
    //          << ", Index: " << processes[j].getIndex() << endl;
    // }
    // cout << endl;
};

void SRTF(int numProcesses, vector<Process> processes) {

};

void PQ(int numProcesses, vector<Process> processes) {

};

void RR(int numProcesses, vector<Process> processes, int timeSlice) {

};

int main(void){
    // Get the number of test cases
    int testCases = 0;
    cin >> testCases;

    // For loop to go through each test case
    for (int i=0; i < testCases; i++){
        // Time slice in case of Round Robin
        int timeSlice = 0;

        // Create variables for number of processes and algorithm used per test case
        int numProcesses = 0;
        string schedAlgo = "";

        // Get the number of processes and type of scheduling algorithm
        cin >> numProcesses >> schedAlgo;

        cout << "Test Case #" << i+1 << ": " << numProcesses << " processes, Scheduling Algorithm: " << schedAlgo << endl;

        if (schedAlgo == "RR"){
            cin >> timeSlice;
            cout << "Time Slice: " << timeSlice << endl;
        }

        // Create a vector of processes
        vector<Process> processes;

        // Populate the vector with processes
        for (int j=0; j < numProcesses; j++){
            int arrival, burst, priority;

            cin >> arrival >> burst >> priority;

            processes.emplace_back(arrival, burst, priority, j+1);
        }

        // Output the test case number
        cout << i+1 << endl;

        // Call the appropriate scheduling algorithm for each test case
        if (schedAlgo == "SRTF"){
            SRTF(numProcesses, processes);
        }
        else if (schedAlgo == "FCFS"){
            FCFS(numProcesses, processes);
        }
        else if (schedAlgo == "STF"){
            STF(numProcesses, processes);
        }
        else if (schedAlgo == "P"){
            PQ(numProcesses, processes);
        }
        else if (schedAlgo == "RR"){
            RR(numProcesses, processes, timeSlice);
        }
        else {
            cout << "Invalid scheduling algorithm." << endl;
        }
    }

    return 0;
}