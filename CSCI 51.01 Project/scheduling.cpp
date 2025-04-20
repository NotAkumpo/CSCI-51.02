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
        int firstResponse;
        int termination;
        int waiting;
        int turnaround;
        int responseTime;

    public:
        Process(int arrival, int burst, int priority, int index) {
            this->arrival = arrival;
            this->burst = burst;
            this->priority = priority;
            this->remainingTime = burst;
            this->index = index;
            this->firstResponse = 0;
            this->termination = 0;
            this->waiting = 0;
            this->turnaround = 0;
            this->responseTime = 0;
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

        int getFirstResponse() const {
            return firstResponse;
        }

        int getTermination() const {
            return termination;
        }

        int getWaiting() const {
            return waiting;
        }

        int getTurnaround() const {
            return turnaround;
        }

        int getResponseTime() const {
            return responseTime;
        }

        // Setters for private members
        void setRemainingTime(int remainingTime) {
            this->remainingTime = remainingTime;
        }

        void setFirstResponse(int firstResponse) {
            this->firstResponse = firstResponse;
        }

        void setTermination(int termination) {
            this->termination = termination;
        }

        void setWaiting(int waiting) {
            this->waiting = waiting;
        }

        void setTurnaround(int turnaround) {
            this->turnaround = turnaround;
        }

        void setResponseTime(int responseTime) {
            this->responseTime = responseTime;
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


    for (const Process& process : processes) {
        firstResponse = max(currentTime, process.getArrival());
        
        if (process.getArrival() < currentTime) {
            waitTime += (currentTime - process.getArrival());
        } else {
            idleTime += (process.getArrival() - currentTime);
            currentTime = process.getArrival();
        }
        
        responseTime += (firstResponse - process.getArrival());

        cout << firstResponse << " " << process.getIndex() << " " << process.getBurst() << "X" << endl;
        currentTime += process.getBurst();
        turnaround += (currentTime - process.getArrival());
    }

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << "Throughput: " << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << "Waiting Time: " << (static_cast<double>(waitTime) / numProcesses) << endl;
    cout << "Turnaround Time: " << (static_cast<double>(turnaround) / numProcesses) << endl;
    cout << "Response Time: " << (static_cast<double>(responseTime) / numProcesses) << endl; 
}

void SJF(int numProcesses, vector<Process> processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), getEarlier);

    vector<Process> queue;

    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;
    int pn = 0;
    int qn = 0;

    while (!queue.empty() || !processes.empty()){
        // Empty queue means the CPU is idle
        if (queue.empty()){
            queue.push_back(processes[0]);
            processes.erase(processes.begin());
            if (queue[0].getArrival() > currentTime) {
                idleTime += (queue[0].getArrival() - currentTime);
                currentTime = queue[0].getArrival();
            }
        }
        // Insert into queue the processes that have arrived in the correct order
        while (!processes.empty() && processes[0].getArrival() <= currentTime){
            for (int i = 0; i < queue.size(); i++){
                if (processes[0].getBurst() < queue[i].getBurst()){
                    queue.insert(queue.begin() + i, processes[0]);
                    break;
                }
                else if (processes[0].getBurst() == queue[i].getBurst()){
                    if (processes[0].getArrival() < queue[i].getArrival()){
                        queue.insert(queue.begin() + i, processes[0]);
                    }
                    else {
                        queue.insert(queue.begin() + i + 1, processes[0]);
                    }
                    break;
                }
                else if (i == queue.size() - 1){
                    queue.push_back(processes[0]);
                    break;
                }
            }
            processes.erase(processes.begin());
        }
        waitTime += (currentTime - queue[0].getArrival());


        cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getBurst() << "X" << endl;
        responseTime += (currentTime - queue[0].getArrival());
        currentTime += queue[0].getBurst();
        turnaround += (currentTime - queue[0].getArrival());
        queue.erase(queue.begin());
    }

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << "Throughput: " << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << "Waiting Time: " << (static_cast<double>(waitTime) / numProcesses) << endl;
    cout << "Turnaround Time: " << (static_cast<double>(turnaround) / numProcesses) << endl;
    cout << "Response Time: " << (static_cast<double>(responseTime) / numProcesses) << endl; 
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
        else if (schedAlgo == "SJF"){
            SJF(numProcesses, processes);
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