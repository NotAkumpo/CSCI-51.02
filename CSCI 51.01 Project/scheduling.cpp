#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

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
            this->firstResponse = -1;
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
        void minusRemainingTime(int timeSlice) {
            this->remainingTime -= timeSlice;
        }

        void setFirstResponse(int firstResponse) {
            this->firstResponse = firstResponse;
        }

        void setTermination(int termination) {
            this->termination = termination;
        }

        void setWaiting(int waitTime) {
            this->waiting = waitTime;
        }

        void setTurnaround(int turnaround) {
            this->turnaround = turnaround;
        }

        void setResponseTime(int responseTime) {
            this->responseTime = responseTime;
        }

        void addWaiting(int waitTime) {
            this->waiting += waitTime;
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


    for (Process& process : processes) {
        firstResponse = max(currentTime, process.getArrival());
        
        if (process.getArrival() < currentTime) {
            process.setWaiting(currentTime - process.getArrival());
            waitTime += (currentTime - process.getArrival());
        } else {
            idleTime += (process.getArrival() - currentTime);
            currentTime = process.getArrival();
        }
        

        process.setResponseTime(firstResponse - process.getArrival());
        responseTime += (firstResponse - process.getArrival());

        cout << firstResponse << " " << process.getIndex() << " " << process.getBurst() << "X" << endl;
        currentTime += process.getBurst();
        process.setTurnaround(currentTime - process.getArrival());
        turnaround += (currentTime - process.getArrival());
    }

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << endl;
    cout << "Throughput: " << fixed << setprecision(2) << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << endl;
    cout << "Waiting Time:" << endl;
    for (Process& process : processes) {
        cout << "   Process " << process.getIndex() << ": " << process.getWaiting() << "ns" << endl;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (static_cast<double>(waitTime) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Turnaround Time:" << endl;
    for (Process& process : processes) {
        cout << "   Process " << process.getIndex() << ": " << process.getTurnaround() << "ns" << endl;
    }
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (static_cast<double>(turnaround) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Response Time:" << endl;
    for (Process& process : processes) {
        cout << "   Process " << process.getIndex() << ": " << process.getResponseTime() << "ns" << endl;
    }
    cout << "Average Response Time: " << fixed << setprecision(2) << (static_cast<double>(responseTime) / numProcesses) << "ns" << endl; 
}

void SJF(int numProcesses, vector<Process> processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), getEarlier);

    // Make a queue to hold the processes
    vector<Process> queue;
    vector<Process> processes2;

    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;

    while (!queue.empty() || !processes.empty()){
        // If queue is empty, add the first process to the queue
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
        queue[0].setWaiting(currentTime - queue[0].getArrival());
        waitTime += (currentTime - queue[0].getArrival());


        cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getBurst() << "X" << endl;
        queue[0].setResponseTime(currentTime - queue[0].getArrival());
        responseTime += (currentTime - queue[0].getArrival());
        currentTime += queue[0].getBurst();
        queue[0].setTurnaround(currentTime - queue[0].getArrival());
        turnaround += (currentTime - queue[0].getArrival());
        processes2.push_back(queue[0]);
        queue.erase(queue.begin());
    }

    sort(processes2.begin(), processes2.end(), getEarlier);

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << endl;
    cout << "Throughput: " << fixed << setprecision(2) << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << endl;
    cout << "Waiting Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getWaiting() << "ns" << endl;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (static_cast<double>(waitTime) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Turnaround Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getTurnaround() << "ns" << endl;
    }
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (static_cast<double>(turnaround) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Response Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getResponseTime() << "ns" << endl;
    }
    cout << "Average Response Time: " << fixed << setprecision(2) << (static_cast<double>(responseTime) / numProcesses) << "ns" << endl; 
};

void SRTF(int numProcesses, vector<Process> processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), getEarlier);

    // Make a queue to hold the processes
    vector<Process> queue;
    vector<Process> processes2;

    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;
    int nextArrival = 0;
    int timeSlice = 0;
    int coStarttime = 0;
    int coTimeslice = 0;
    int coIndex = 0;
    bool noTerminate = false;
    bool carryOver = false;

    while (!queue.empty() || !processes.empty()){
        // If queue is empty, add the first process to the queue
        if (queue.empty()){
            queue.push_back(processes[0]);
            processes.erase(processes.begin());
            if (queue[0].getArrival() > currentTime) {
                idleTime += (queue[0].getArrival() - currentTime);
                currentTime = queue[0].getArrival();
            }
        }
        if (!processes.empty()){
            nextArrival = processes[0].getArrival();
            timeSlice = nextArrival - currentTime;
        }
        else {
            timeSlice = INT_MAX;
        }

        if (queue[0].getFirstResponse() == -1){
            queue[0].setFirstResponse(currentTime);
            queue[0].setResponseTime(currentTime - queue[0].getArrival());
            responseTime += (currentTime - queue[0].getArrival());
        }
        
        if (timeSlice >= queue[0].getRemainingTime()){
            if (carryOver){
                coTimeslice += queue[0].getRemainingTime();
                cout << coStarttime << " " << coIndex << " " << coTimeslice << "X" << endl;
                coTimeslice = 0;
            } else {
                cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getRemainingTime() << "X" << endl;
            }
            noTerminate = false;
            queue[0].setTurnaround(currentTime + queue[0].getRemainingTime() - queue[0].getArrival());
            queue[0].addWaiting(queue[0].getTurnaround() - queue[0].getBurst());
            waitTime += (queue[0].getTurnaround() - queue[0].getBurst());
            turnaround += queue[0].getTurnaround();
            currentTime += queue[0].getRemainingTime();
            processes2.push_back(queue[0]);
            queue.erase(queue.begin());
        }
        else {
            noTerminate = true;
            coIndex = queue[0].getIndex();
            coTimeslice += timeSlice;
            queue[0].minusRemainingTime(timeSlice);
            if (!carryOver){
                coStarttime = currentTime;
            }
            currentTime += timeSlice;
        }

        while (!processes.empty() && processes[0].getArrival() == currentTime){
            for (int i = 0; i < queue.size(); i++){
                if (processes[0].getRemainingTime() < queue[i].getRemainingTime()){
                    queue.insert(queue.begin() + i, processes[0]);
                    if (i == 0){
                        carryOver = false;
                    }
                    else {
                        carryOver = true;
                    }
                    break;
                }
                else if (processes[0].getRemainingTime() == queue[i].getRemainingTime()){
                    if (processes[0].getArrival() < queue[i].getArrival()){
                        queue.insert(queue.begin() + i, processes[0]);
                        if (i == 0){
                            carryOver = false;
                        }
                        else {
                            carryOver = true;
                        }
                    }
                    else {
                        queue.insert(queue.begin() + i + 1, processes[0]);
                        carryOver = true;
                    }
                    break;
                }
                else if (i == queue.size() - 1){
                    queue.push_back(processes[0]);  
                    carryOver = true;
                    break;
                }
            }
            processes.erase(processes.begin());
        }

        if (noTerminate && !carryOver){
            cout << coStarttime << " " << coIndex << " " << coTimeslice << endl;
            coTimeslice = 0;
        }

    }

    sort(processes2.begin(), processes2.end(), getEarlier);

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << endl;
    cout << "Throughput: " << fixed << setprecision(2) << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << endl;
    cout << "Waiting Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getWaiting() << "ns" << endl;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (static_cast<double>(waitTime) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Turnaround Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getTurnaround() << "ns" << endl;
    }
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (static_cast<double>(turnaround) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Response Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getResponseTime() << "ns" << endl;
    }
    cout << "Average Response Time: " << fixed << setprecision(2) << (static_cast<double>(responseTime) / numProcesses) << "ns" << endl; 

};

void PQ(int numProcesses, vector<Process> processes) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), getEarlier);

    // Make a queue to hold the processes
    vector<Process> queue;
    vector<Process> processes2;

    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;
    int nextArrival = 0;
    int timeSlice = 0;
    int coStarttime = 0;
    int coTimeslice = 0;
    int coIndex = 0;
    bool noTerminate = false;
    bool carryOver = false;

    while (!queue.empty() || !processes.empty()){
        // If queue is empty, add the first process to the queue
        if (queue.empty()){
            queue.push_back(processes[0]);
            processes.erase(processes.begin());
            if (queue[0].getArrival() > currentTime) {
                idleTime += (queue[0].getArrival() - currentTime);
                currentTime = queue[0].getArrival();
            }
        }
        if (!processes.empty()){
            nextArrival = processes[0].getArrival();
            timeSlice = nextArrival - currentTime;
        }
        else {
            timeSlice = INT_MAX;
        }

        if (queue[0].getFirstResponse() == -1){
            queue[0].setFirstResponse(currentTime);
            queue[0].setResponseTime(currentTime - queue[0].getArrival());
            responseTime += (currentTime - queue[0].getArrival());
        }
        
        if (timeSlice >= queue[0].getRemainingTime()){
            if (timeSlice == INT_MAX){
                cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getRemainingTime() << "X" << endl;
            }
            else if (carryOver){
                coTimeslice += queue[0].getRemainingTime();
                cout << coStarttime << " " << coIndex << " " << coTimeslice << "X" << endl;
                coTimeslice = 0;
            } else {
                cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getRemainingTime() << "X" << endl;
            }
            noTerminate = false;
            queue[0].setTurnaround(currentTime + queue[0].getRemainingTime() - queue[0].getArrival());
            queue[0].addWaiting(queue[0].getTurnaround() - queue[0].getBurst());
            waitTime += (queue[0].getTurnaround() - queue[0].getBurst());
            turnaround += queue[0].getTurnaround();
            currentTime += queue[0].getRemainingTime();
            processes2.push_back(queue[0]);
            queue.erase(queue.begin());
        }
        else {
            noTerminate = true;
            coIndex = queue[0].getIndex();
            coTimeslice += timeSlice;
            queue[0].minusRemainingTime(timeSlice);
            if (!carryOver){
                coStarttime = currentTime;
            }
            currentTime += timeSlice;
        }

        while (!processes.empty() && processes[0].getArrival() == currentTime){
            for (int i = 0; i < queue.size(); i++){
                if (processes[0].getPriority() > queue[i].getPriority()){
                    queue.insert(queue.begin() + i, processes[0]);
                    if (i == 0){
                        carryOver = false;
                    }
                    else {
                        carryOver = true;
                    }
                    break;
                }
                else if (processes[0].getPriority() == queue[i].getPriority()){
                    if (processes[0].getBurst() < queue[i].getBurst()){
                        queue.insert(queue.begin() + i, processes[0]);
                        if (i == 0){
                            carryOver = false;
                        }
                        else {
                            carryOver = true;
                        }
                    }
                    else if (processes[0].getBurst() == queue[i].getBurst()){
                        if (processes[0].getArrival() < queue[i].getArrival()){
                            queue.insert(queue.begin() + i, processes[0]);
                            if (i == 0){
                                carryOver = false;
                            }
                            else {
                                carryOver = true;
                            }
                        }
                        else {
                            queue.insert(queue.begin() + i + 1, processes[0]);
                            carryOver = true;
                        }
                    }
                    else {
                        queue.insert(queue.begin() + i + 1, processes[0]);
                        carryOver = true;
                    }
                    break;
                }
                else if (i == queue.size() - 1){
                    queue.push_back(processes[0]);
                    carryOver = true;
                    break;
                }
            }
            processes.erase(processes.begin());
        }

        if (noTerminate && !carryOver){
            cout << coStarttime << " " << coIndex << " " << coTimeslice << endl;
            coTimeslice = 0;
        }

    }

    sort(processes2.begin(), processes2.end(), getEarlier);

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << endl;
    cout << "Throughput: " << fixed << setprecision(2) << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << endl;
    cout << "Waiting Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getWaiting() << "ns" << endl;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (static_cast<double>(waitTime) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Turnaround Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getTurnaround() << "ns" << endl;
    }
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (static_cast<double>(turnaround) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Response Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getResponseTime() << "ns" << endl;
    }
    cout << "Average Response Time: " << fixed << setprecision(2) << (static_cast<double>(responseTime) / numProcesses) << "ns" << endl; 
};

void RR(int numProcesses, vector<Process> processes, int origTimeSlice) {
    // Sort processes by burst time
    sort(processes.begin(), processes.end(), getEarlier);

    // Make a queue to hold the processes
    vector<Process> queue;
    vector<Process> processes2;

    int timeSlice = origTimeSlice;
    int currentTime = 0;
    int idleTime = 0;
    int waitTime = 0;
    int turnaround = 0;
    int responseTime = 0;
    int firstResponse = 0;
    int nextArrival = 0;
    int coStarttime = 0;
    int coTimeslice = 0;
    int coIndex = 0;
    bool noTerminate = false;
    bool carryOver = false;
    Process previousProcess = Process(0, 0, 0, 0); // Initialize to a dummy process

    while (!queue.empty() || !processes.empty()){
        // If queue is empty, add the first process to the queue
        if (queue.empty()){
            queue.push_back(processes[0]);
            processes.erase(processes.begin());
            if (queue[0].getArrival() > currentTime) {
                idleTime += (queue[0].getArrival() - currentTime);
                currentTime = queue[0].getArrival();
            }
        }

        if (queue[0].getFirstResponse() == -1){
            queue[0].setFirstResponse(currentTime);
            queue[0].setResponseTime(currentTime - queue[0].getArrival());
            responseTime += (currentTime - queue[0].getArrival());
        }

        previousProcess = queue[0];

        if (timeSlice >= queue[0].getRemainingTime()){
            if (carryOver){
                coTimeslice += queue[0].getRemainingTime();
                cout << coStarttime << " " << coIndex << " " << coTimeslice << "X" << endl;
                coTimeslice = 0;
            } else {
                cout << currentTime << " " << queue[0].getIndex() << " " << queue[0].getRemainingTime() << "X" << endl;
            }
            noTerminate = false;
            timeSlice -= queue[0].getRemainingTime();
            if (timeSlice == 0){
                timeSlice = origTimeSlice;
            }
            queue[0].setTurnaround(currentTime + queue[0].getRemainingTime() - queue[0].getArrival());
            waitTime += (queue[0].getTurnaround() - queue[0].getBurst());
            queue[0].addWaiting(queue[0].getTurnaround() - queue[0].getBurst());
            turnaround += queue[0].getTurnaround();
            currentTime += queue[0].getRemainingTime();
            processes2.push_back(queue[0]);
            queue.erase(queue.begin());
        }
        else {
            noTerminate = true;
            coIndex = queue[0].getIndex();
            coTimeslice += timeSlice;
            queue[0].minusRemainingTime(timeSlice);
            if (!carryOver){
                coStarttime = currentTime;
            }
            currentTime += timeSlice;
            timeSlice = origTimeSlice;
        }

        while (!processes.empty() && processes[0].getArrival() <= currentTime){
            queue.push_back(processes[0]);
            processes.erase(processes.begin());
        }
        queue.push_back(queue[0]);
        queue.erase(queue.begin());

        if (previousProcess.getIndex() == queue[0].getIndex()){
            carryOver = true;
        } else {
            carryOver = false;
        }

        if (noTerminate && !carryOver){
            cout << coStarttime << " " << coIndex << " " << coTimeslice << endl;
            coTimeslice = 0;
        }
    }

    sort(processes2.begin(), processes2.end(), getEarlier);

    cout << "CPU Utilization: " << (static_cast<double>(currentTime - idleTime) / currentTime * 100) << "%" << endl;
    cout << endl;
    cout << "Throughput: " << fixed << setprecision(2) << (static_cast<double>(numProcesses) / currentTime) << endl;
    cout << endl;
    cout << "Waiting Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getWaiting() << "ns" << endl;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << (static_cast<double>(waitTime) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Turnaround Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getTurnaround() << "ns" << endl;
    }
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << (static_cast<double>(turnaround) / numProcesses) << "ns" << endl;
    cout << endl;
    cout << "Response Time:" << endl;
    for (Process& process : processes2) {
        cout << "   Process " << process.getIndex() << ": " << process.getResponseTime() << "ns" << endl;
    }
    cout << "Average Response Time: " << fixed << setprecision(2) << (static_cast<double>(responseTime) / numProcesses) << "ns" << endl; 
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

        cout << endl;
        cout << "===================================================================================================================" << endl;
        cout << endl;

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