#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

const int ITERATIONS = 1000;
mutex mtx;

void printMessageNoMutex(const string& message) {
    for (int i = 0; i < ITERATIONS; ++i) {
        cout << message << " " << i << endl;  // No protection, interleaved output
    }
}

void printMessageWithMutex(const string& message) {
    for (int i = 0; i < ITERATIONS; ++i) {
        lock_guard<mutex> lock(mtx);
        cout << message << " " << i << endl;  // Too many locks
    }
}

void printMessageBuffered(const string& message) {
    string output;
    for (int i = 0; i < ITERATIONS; ++i) {
        output += message + " " + to_string(i) + "\n";
    }
    lock_guard<mutex> lock(mtx);
    cout << output;  // Locks once per thread
}

void printMessageStringStream(const string& message) {
    ostringstream buffer;
    for (int i = 0; i < ITERATIONS; ++i) {
        buffer << message << " " << i << "\n";
    }
    lock_guard<mutex> lock(mtx);
    cout << buffer.str();  // Locks once per thread
}

void benchmark(void (*printFunc)(const string&), const string& testName) {
    auto start = high_resolution_clock::now();

    thread t1(printFunc, "Thread 1");
    thread t2(printFunc, "Thread 2");

    t1.join();
    t2.join();

    auto end = high_resolution_clock::now();
    cout << testName << " Execution Time: " 
         << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
}

int main() {
    benchmark(printMessageNoMutex, "No Mutex");
    benchmark(printMessageWithMutex, "Mutex (Per Line)");
    benchmark(printMessageBuffered, "Buffered Output");
    benchmark(printMessageStringStream, "String Stream");

    return 0;
}
