#ifndef P_THREADS_THREADS_H
#define P_THREADS_THREADS_H
using namespace std;
struct ThreadArguments {
    string file{};
    int sum{};
};

int getSumUsingThread(int fileCount);
int getSumUsingThreads(int fileCount);
#endif
