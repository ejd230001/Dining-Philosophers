// CoarsePetersenLock.h
#ifndef COARSE_PETERSEN_LOCK_H
#define COARSE_PETERSEN_LOCK_H

#include <atomic>
#include <stack>

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
 * Recursively calls itself until all locks needed are acquired 
 *
 * @param index Index of the lock to be acquired
 * @param prevIndex Index of the previous lock acquired, used to decide if the lock is being acquired by the left or right child
 * @param lockArray Array of PetersenLocks used to implement the tournament tree
 */
void acquire(int index, int prevIndex, PetersenLock* lockArray);

/** 
 * Releases a lock at a given index
 * Recursively calls itself until all locks acquired by the thread were released
 *
 * @param index Index of the lock to be released
 * @param path Stack that holds the indices of locks acquired by the thread
 * @param lockArray Array of PetersenLocks used to implement the tournament tree
 */
void release(int indexInTree, stack<int> path, PetersenLock* lockArray);

/** 
 * Returns the path of locks from root to the desired thread
 *
 * @param indexInTree Index of the thread that a path is needed for
 */
stack<int> getPath(int indexInTree);

#endif
