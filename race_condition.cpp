#include <iostream>
#include <thread>

using namespace std;

void printMessage(const string& message) {
    for (int i = 0; i < 50000; ++i) {
        cout << message << " " << i << endl;
    }
}

int main() {
    thread t1(printMessage, "Thread 1");
    thread t2(printMessage, "Thread 2");

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    cout << "Main thread finished execution" << endl;
    return 0;
}
