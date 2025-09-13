#include "../header/Philosopher.h"

void think(int threadNum) {
    // Seed random number generator
    srand(threadNum * 2 + time(nullptr));

    // Create a random number
    int random = rand() % 500 + 1;

    // Think
    cout << "Philosopher " << threadNum << " has started thinking" << endl;
    this_thread::sleep_for(chrono::milliseconds(random));
    cout << "Philosopher " << threadNum << " has finished thinking" << endl;
}

void eat(int threadNum) {
    // Seed random number generator
    srand(threadNum + time(nullptr));

    // Create a random number
    int random = rand() % 500 + 1;

    // Eat
    cout << "Philosopher " << threadNum << " has started eating" << endl;
    this_thread::sleep_for(chrono::milliseconds(random));
    cout << "Philosopher " << threadNum << " has finished eating" << endl;
}