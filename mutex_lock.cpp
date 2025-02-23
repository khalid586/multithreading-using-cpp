#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printMessage(const std::string& message) {
    for (int i = 0; i < 50000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Ensures only one thread prints at a time
        std::cout << message << " " << i << std::endl;
    }
}

int main() {
    std::thread t1(printMessage, "Thread 1");
    std::thread t2(printMessage, "Thread 2");

    t1.join();
    t2.join();

    std::cout << "Main thread finished execution" << std::endl;
    return 0;
}
