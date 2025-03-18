#include <iostream>
#include <unistd.h>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]){

    int f = fork();

    if (f == 0){
        if (execv("/usr/bin/xclock", argv) == -1){
            cout << "Exec() for xclock failed";
        }
    } else {
        int i = 1;
        while (true){

            // Print the current date time
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            std::tm local_time = *std::localtime(&now_c);
            std::cout << "[" << std::put_time(&local_time, "%Y-%m-%d") << "] " << std::put_time(&local_time, "%H:%M:%S") << std::endl;


            if (i == 3){
                cout << "“This program has gone on for far too long. Type Ctrl+C to abort this timer application.”" << endl;
                i = 0;
            }
            // Wait 10 seconds
            sleep(10);
            i++;
        }

    }
    

    return 0;

}