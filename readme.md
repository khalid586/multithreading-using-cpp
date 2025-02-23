## Multithreading
- [Program](#program)
- [Process](#process)
- [Thread](#thread)
- [Race condition](#race-condition)
- [Mutex lock](#mutex-lock)


### Program
- A program is a set of instructions(not being executed) saved in a file.

Below the code saved in a file is called a program.

```c++

#include <iostream>

using namespace std;


int main() {
    cout << "hello";
    return 0;
}


```

[Back to top](#multithreading)

### Process
- A running program is referred as a process. 

When the code(file) below is running it is known as process.

```c++

#include <iostream>

using namespace std;


int main() {
    cout << "hello";
    return 0;
}
```

[Back to top](#multithreading)

### Thread
- A thread is the smallest unit of execution within a process which is responsible for performing specific tasks of the process.

A thread has been spun in c++.

```c++
#include<iostream>
#include<thread>
using namespace std;

void task(){
    cout << "Hi from thread\n";
}

int main(){
    thread t(task);

    t.join();

    cout << "Hi from main function\n";
    return 0;
}
```

[Back to top](#multithreading)

### Race Condition
- Race condition is such a condition where multiple threads/ processes are trying to modify a shared resource concurrently and the outcome depends on the **unpredictable** order of execution

```c++
#include <iostream>
#include <thread>

using namespace std;

void printMessage(const string& message) {
    for (int i = 0; i < 5000; ++i) {
        cout << message << " " << i << endl;
    }
}

int main() {
    thread t1(printMessage,"thread-1");
    thread t2(printMessage,"thread-2");

    // Wait for both threads to finish execution
    t1.join();
    t2.join();

    cout << "Main thread finished execution" << endl;
    return 0;
}

```

[Back to top](#multithreading)

### Mutex Lock
- Mutex(Mutual exclusion) lock is a synchronization mechanism which prevents multiple threads from accessing shared resources simultaneously to prevent race condition. 

[Back to top](#multithreading)