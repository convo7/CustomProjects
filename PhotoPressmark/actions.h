#ifndef ACTIONS_H
#define ACTIONS_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <thread>
#include <dirent.h>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

string exeption(string a);

void threadMaker(vector<vector<string>> &parts, string &folderPath);

void f2();

void make(string &folderPath, int countThreads);

void makeCrypto(vector<string> path);

int fileCount(string &folderPath);

void cryptor(const char *name);

void path(char *folderName);

#endif //ACTIONS_H
