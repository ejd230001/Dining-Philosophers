#include <iostream>
#include <thread>
#include <string>
#include "../header/FinePetersenLock.h"
#include "../header/Philosopher.h"

using namespace std;

/** 
 * Main function utilized by worker threads to simulate philosophers.
 * Calls the function to think, then acquires the locks, calls the function to eat, then release the locks
 *
 * @param threadNum Unique value given to each thread
 * @param lockArray Array of PetersenLocks used to implement the tournament tree
 * @param numWorkers Total number of threads created, used to calculate the threads position in the tree
 * @param run Input from user to decide whether each philosopher should think and eat indefinitely or not
 *
 */
void philosopherThread(int threadNum, PetersenLock* lockArray, int numWorkers, int run);

// Driver function, takes in input, initializes all threads
int main(int argc, char *argv[]) {
    // Initialize variable that holds the number of threads
    int n;

    // Validate correct number of arguments was given
    if (argc != 2) {
        cerr << "Correct number of arguments not given." << endl;
        exit(1);
    }
    
    // Ensure that the argument given is valid and assign it to n
    try {
        n = stoi(argv[1]);
    }
    catch (const exception &error) {
        cerr << "Invalid input given." << endl;
        exit(1);
    }
    if (n <= 0) {
        cerr << "Number of philosophers must be greater than 0." << endl;
        exit(1);
    }
    
    // Create array of locks used as a tournament tree and initialize array of threads
    PetersenLock* lockArray = new PetersenLock[n];
    thread* workers = new thread[n];

    // Take in user input to decide of philosophers should think and eat indefinitely or not
    int run = false;
    cout << "Single Run (0) or Infinite Loop (1): ";
    cin >> run;

    // Validate input
    if (cin.fail() || (run != 0 && run != 1)) {
        cerr << "Invalid input. Please enter 0 or 1." << endl;
        exit(1);
    }

    // Create worker threads
    for (int i = 0; i < n; i++) {
        workers[i] = thread(philosopherThread, i, lockArray, n, run);
    }

    // Wait for worker threads to finish
    for (int i = 0; i < n; i++) {
        workers[i].join();
    }

    // Free up space used by arrays
    delete[] lockArray;
    delete[] workers;
}

void philosopherThread(int threadNum, PetersenLock* lockArray, int numWorkers, int run) {
    do {
        // Call function to think
        think(threadNum);

        // Acquire left chopstick, then right chopstick, unless you are the last philosopher
        if (threadNum < numWorkers - 1) {
            acquire(threadNum, 0, lockArray);
            acquire((threadNum + 1) % numWorkers, 1, lockArray);
        }
        else {
            acquire((threadNum + 1) % numWorkers, 1, lockArray);
            acquire(threadNum, 0, lockArray);
        }

        // Call function to eat, then release appropriate locks
        eat(threadNum);
        release(threadNum, 0, lockArray);
        release((threadNum + 1) % numWorkers, 1, lockArray);
    } while(run);
}