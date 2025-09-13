#include "../header/FinePetersenLock.h"

void acquire(int index, int direction, PetersenLock* lockArray) {
    //cout << "Acquiring lock " << index << endl;
    //cout << "Left Flag: " << lockArray[index].flag[0] << endl;
    //cout << "Right Flag: " << lockArray[index].flag[1] << endl;
    //cout << "Turn: " << lockArray[index].turn << endl;

    // Checks whether the chopstick is being picked up by the left or right philosopher
    if (direction == 0) {
        // Petersen's algorithm on the left side
        lockArray[index].flag[0] = true;
        lockArray[index].turn = 1;

        // Busy wait
        while (lockArray[index].flag[1] && lockArray[index].turn != 0) {
            //cout << "Waiting on lock" << index << endl;
            //sleep(3);
        }
    }
    else {
        // Petersen's algorithn on the right side
        lockArray[index].flag[1] = true;
        lockArray[index].turn = 0;

        // Busy wait
        while (lockArray[index].flag[0] && lockArray[index].turn != 1) {
            //cout << "Waiting on lock" << index << endl;
            //sleep(3);
        }
    }
}

void release(int index, int direction, PetersenLock* lockArray) {
    // Release the appropriate side of the lock
    if (direction == 0) 
        lockArray[index].flag[0] = false;
    else
        lockArray[index].flag[1] = false;
}