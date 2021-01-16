#include <iostream>
#include <ctime>
#include <pthread.h>
#include "threads.h"
using namespace std;

int main() {
    const int fileCount = 10;
    clock_t t1, t2;

    t1 = clock();
    cout << "1 thread sum: " << getSumUsingThread(fileCount) << endl;
    t2 = clock();
    cout << "1 thread time: " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;

    t1 = clock();
    cout << "10 threads sum: " << getSumUsingThreads(fileCount) << endl;
    t2 = clock();
    cout << "10 threads time: " << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
}
