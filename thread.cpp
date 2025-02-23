#include<iostream>
#include<thread>
using namespace std;

void task(){
    cout << "Hi from thread\n";
}

int main(){
    // A simple thread
    thread t(task);

    t.join();

    cout << "Hi from main function\n";
    return 0;
}