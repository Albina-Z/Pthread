#include <iostream>
#include <fstream>
#include "threads.h"
using namespace std;

// Считывает файл, путь к которому передан через args->file, считает сумму каждого числа в файле
// и сохраняет эту сумму в args->file
void* getSumFromFile(void* args) {
    int lineSum;
    ifstream infile;
    string number, line;

    auto *arguments = (ThreadArguments*) args;
    infile.open(arguments->file);
    arguments->sum = 0;
    while (!infile.eof()) {
        getline(infile, line);
        lineSum = 0;
        for (char character : line) {
            if (character != ' ') number += character;
            else {
                lineSum = lineSum + stoi(number);
                number.clear();
            }
        }
        lineSum = lineSum + stoi(number);
        number.clear();
        arguments->sum = arguments->sum + lineSum;
    }
    infile.close();
}

int getSumUsingThread(int fileCount) {
    ThreadArguments arguments;
    int sum = 0;
    for (int i = 0; i < fileCount; i++) {
        arguments.file = "../files/" + to_string(i + 1) + ".txt";
        getSumFromFile(&arguments);
        sum = sum + arguments.sum;
    }
    return sum;
}

int getSumUsingThreads(int fileCount) {
    pthread_t threads[fileCount];
    auto* arguments = new ThreadArguments[fileCount];
    int sum = 0;
    // Создаем потоки и запускаем
    for (int i = 0; i < fileCount; i++) {
        arguments[i].file = "../files/" + to_string(i + 1) + ".txt";
        pthread_create(&threads[i], NULL, getSumFromFile, &arguments[i]);
    }
    // Соединяем потоки и ждем выполнение каждого
    for (int i = 0; i < fileCount; i++) {
        pthread_join(threads[i], NULL);
        sum = sum + arguments[i].sum;
    }
    delete[] arguments;
    return sum;
}