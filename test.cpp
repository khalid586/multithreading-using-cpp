#include <iostream>
#include <thread>

void printMessage(const std::string& message) {
    for (int i = 0; i < 50000; ++i) {
        std::cout << message << " " << i << std::endl;
    }
}

int main() {
    std::thread t1(printMessage, "Thread 1");
    std::thread t2(printMessage, "Thread 2");

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    std::cout << "Main thread finished execution" << std::endl;
    return 0;
}
