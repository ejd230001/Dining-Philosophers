#include "../header/CoarsePetersenLock.h"

void acquire(int index, int prevIndex, PetersenLock* lockArray) {
    //cout << "Acquiring lock " << index << endl;
    //cout << "Left Flag: " << lockArray[index].flag[0] << endl;
    //cout << "Right Flag: " << lockArray[index].flag[1] << endl;
    //cout << "Turn: " << lockArray[index].turn << endl;

    // Checks whether the lock is being acquired by the left or right child
    if (prevIndex % 2 == 1) {
        // Left child Petersen's Algorithm
        lockArray[index].flag[0] = true;
        lockArray[index].turn = 1;

        // Busy wait
        while (lockArray[index].flag[1] && lockArray[index].turn != 0) {
            //cout << "Waiting on lock" << index << endl;
            //sleep(3);
        }
    }
    else {
        // Right child Petersen's Algorithm
        lockArray[index].flag[1] = true;
        lockArray[index].turn = 0;

        // Busy wait
        while (lockArray[index].flag[0] && lockArray[index].turn != 1) {
            //cout << "Waiting on lock" << index << endl;
            //sleep(3);
        }
    }

    // Acquire the next lock up in the tournament tree
    if (index != 0)
        acquire((index - 1) / 2, index, lockArray);
}

void release(int indexInTree, stack<int> path, PetersenLock* lockArray) {
    // Pop the next lock to be released from the stack
    int current = path.top();
    path.pop(); 

    // If the the current index is the threads index in the tree, return, all locks have been released
    if (current == indexInTree) {
        return;
    }
    //cout << "Releasing lock " << current << endl;

    // Release the appropriate side of the lock based on whether the next lock is a left or right child
    if (path.top() % 2 == 1) 
        lockArray[current].flag[0] = false;
    else
        lockArray[current].flag[1] = false;

    // Release the next lock in the path
    release(indexInTree, path, lockArray);
}

stack<int> getPath(int indexInTree) {
    // Initialize stack
    stack<int> path;

    // Find stack of locks used to reach the thread from the root
    while (indexInTree != 0) {
        path.push(indexInTree);
        indexInTree = (indexInTree - 1) / 2;
    }
    path.push(0);

    return path;
}