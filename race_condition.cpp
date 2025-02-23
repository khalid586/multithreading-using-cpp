#include <iostream>
#include <thread>

using namespace std;

void printMessage(const string& message) {
    for (int i = 0; i < 50000; ++i) {
        cout << message << " " << i << endl;
    }
}

void loop(string s){
    int i = 0;

    while(i < 500){
       i++;
       cout << s << ' ' << i << '\n';
    }

}

int main() {
    // thread t1(printMessage, "Thread 1");
    // thread t2(printMessage, "Thread 2");


    thread t3(loop,"thread-1");
    thread t4(loop,"thread-2");

    // Wait for both threads to finish execution
    t3.join();
    t4.join();

    cout << "Main thread finished execution" << endl;
    return 0;
}
