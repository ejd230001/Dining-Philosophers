// Philosopher.h
#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

/** 
 * Function that lets the philosopher think for a random amount of time between 1 and 500 milliseconds
 *
 * @param threadNum ID of the thread/philosopher
 */
void think(int threadNum);

/** 
 * Function that lets the philosopher eat for a random amount of time between 1 and 500 milliseconds
 *
 * @param threadNum ID of the thread/philosopher
 */
void eat(int threadNum);

#endif