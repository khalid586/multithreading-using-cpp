#include <iostream>
#include <thread>

using namespace std;

void printMessage(const string& message) {
    for (int i = 0; i < 5000; ++i) {
        cout << message << " " << i << endl;
    }
}

int main() {

    // A simple race condition
    thread t1(printMessage,"thread-1");
    thread t2(printMessage,"thread-2");

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    cout << "Main thread finished execution" << endl;
    return 0;
}
