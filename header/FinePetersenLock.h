// FinePetersenLock.h
#ifndef FINE_PETERSEN_LOCK_H
#define FINE_PETERSEN_LOCK_H

#include <atomic>

using namespace std;

// Standard implementation of Petersen's Lock
struct PetersenLock {
    atomic<bool> flag[2];
    atomic<int> turn;

    PetersenLock() {
        flag[0] = false;
        flag[1] = false;
        turn = 0;
    }
};

/** 
 * Acquires a lock at a given index
 *
 * @param index Index of the lock to be acquired
 * @param direction Indicates whether the chopstick is being acquired by the philsopher to the left or right
 * @param lockArray Array of PetersenLocks used to implement the tournament tree
 */
void acquire(int index, int direction, PetersenLock* lockArray);

/** 
 * Releases a lock at a given index
 *
 * @param index Index of the lock to be released
 * @param direction Indicates whether the chopstick is being released by the philsopher to the left or right
 * @param lockArray Array of PetersenLocks used to implement the tournament tree
 */
void release(int index, int direction, PetersenLock* lockArray);

#endif
