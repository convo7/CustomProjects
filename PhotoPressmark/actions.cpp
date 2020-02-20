#include "actions.h"

using namespace std;

string exeption(string a) {
    return a;
}

void threadMaker(vector<vector<string>> &parts, string &folderPath) {

    std::vector<std::thread> threads;
    threads.reserve(parts.size());

    int secondCount = 0;
    for (const auto &x : parts) {
        threads.emplace_back(makeCrypto, x);
        secondCount++;
    }

    try {
        if (parts.size() < secondCount) {
            throw exeption("ERROR: treadMaker -> threads count not match!"); //NOLINT
        }
    }
    catch (string &str) {
        cout << str << endl;
        return;
    }

    for (auto &thread : threads) {
        thread.join();
        secondCount++;
    }
}

int fileCount(string &folderPath) {
    DIR *dir;
    struct dirent *ent;

    int i = 0;

    const char *myFolderPath = folderPath.c_str();

    if ((dir = opendir(myFolderPath)) != NULL) {

        int c = 0;

        while ((ent = readdir(dir)) != NULL) {
            if (c < 2) {
                c++;
            } else {
                i++;
            }
        }
        closedir(dir);
    }
    return i;
}

vector<string> makeStack(string &folderPath, int start, int end) {

    vector<string> partOfFiles = {};

    DIR *dir;
    struct dirent *ent;
    const char *myFolderPath = folderPath.c_str();
    if ((dir = opendir(myFolderPath)) != nullptr) {

        int i = 1;
        while ((ent = readdir(dir)) != nullptr) {
            if (i >= start && i <= end) {

                if (strcmp(ent->d_name, "..") == 0 || strcmp(ent->d_name, ".") == 0) continue;

                char fullPath[150] = {};
                strcat(fullPath, myFolderPath);
                strcat(fullPath, ent->d_name);

                std::cout << fullPath << std::endl;

                partOfFiles.emplace_back(fullPath);
                i++;

            } else { i++; }
        }
        closedir(dir);
    }

    return partOfFiles;
}

void make(string &folderPath, int countThreads) {
    try {
        if (countThreads <= 0) {
            throw exeption("ERROR: make -> wrong thread number");
        }
    }
    catch (string &str) {
        cout << str << endl;
        return;
    }

    int fullCount = fileCount(folderPath);

    vector<vector<string>> parts = {};

    int diff = fullCount % countThreads;

    int step = fullCount / countThreads;
    int z = 0;
    int tmp = 0;

    int start = 0, end = 0;
    while (z < countThreads) {
        if (tmp == 0) {
            start = 1;
            end += step;
            tmp += step;

            parts.push_back(makeStack(folderPath, start, end));

        } else {

            start = tmp + 1;
            tmp += step;
            end = tmp;

            parts.push_back(makeStack(folderPath, start, end));
        }
        if (z + 1 == countThreads) {
            if (diff != 0) {
                start = tmp + 1;
                tmp += step;
                //end = tmp + diff;

                end = fullCount;
                parts.push_back(makeStack(folderPath, start, end));
            }
        }
        z++;
    }

    try {
        if (fullCount != end) { throw exeption("ERROR: make -> count of files not match"); }
    }
    catch (string &str) {
        cout << str << endl;
    }

    threadMaker(parts, folderPath);
}


void makeCrypto(vector<string> path) {

    for (const auto &x : path) {
        const char *myPath = x.c_str();
        cryptor(myPath);
    }
}

void cryptor(const char *name) {
    std::string pass = "12345678";
    ifstream fin(name, ios::binary);
    ofstream fout;
    long len;
    char *p;
    fin.seekg(0, ios::end);
    len = fin.tellg();
    fin.seekg(0, ios::beg);
    p = new char[len + 1];
    fin.read(p, sizeof(char) * len);
    fout.open(name, ios::binary);
    for (unsigned int i = 0; i < sizeof(char) * len; i++)
        for (auto &symbol : pass)
            p[i] ^= symbol;
    fout.write((char *) p, sizeof(char) * len);
    delete[]p;
}