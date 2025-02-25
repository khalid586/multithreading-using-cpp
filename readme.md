# Table of contents
- [Program](#program)
- [Process](#process)
- [Thread](#thread)
- [Concurrency](#concurrency)
- [Parallelism](#parallelism)
- [Race condition](#race-condition)
- [Mutex lock](#mutex-lock)


## Program
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

[Back to top](#table-of-contents)

## Process
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

[Back to top](#table-of-contents)

## Thread
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

[Back to top](#table-of-contents)

## Concurrency
- Executing multiple tasks as the same time but not necessarily simultaneously, often by switching context is known as concurrency.

[Example: Race condition](#race-condition)

[Back to top](#table-of-contents)

## Parallelism
- Executing multiple tasks at the same simultaneously by using multiple cores, is known as parallelism. 

```python
import multiprocessing
import os
def task(n):
    print(f"Processing {n} (PID: {os.getpid()})")

if __name__ == "__main__":
    processes = []
    for i in range(4):  # Creating 4 processes
        p = multiprocessing.Process(target=task, args=(i,))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()  # Wait for all processes to finish

    print('this is the end!')
```

## Race Condition
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

[Back to top](#table-of-contents)

## Mutex Lock
- Mutex(Mutual exclusion) lock is a synchronization mechanism which prevents multiple threads from accessing shared resources simultaneously to prevent race condition. 
    - Cons:
      - If any of the threads go into infinite loop without releasing the lock it will cause a deadlock and other threads won't be able to access the mutex.


[Back to top](#table-of-contents)