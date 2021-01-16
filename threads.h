#ifndef P_THREADS_THREADS_H
#define P_THREADS_THREADS_H
using namespace std;
// Нужен для того, чтобы передавать несколько аргументов в функцию, выполняющейся не в основном потоке
struct ThreadArguments {
    string file{};
    int sum{};
};

int getSumUsingThread(int fileCount);
int getSumUsingThreads(int fileCount);
#endif
