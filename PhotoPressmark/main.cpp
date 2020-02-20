#include <iostream>
#include <ctime>

#include "actions.h"

using namespace std;


int main() {
    string folderPath = {};

    cout << "Enter path to folder (with THIS slash '\') " << endl;
    cin >> folderPath;
    cout << endl;

    int count = 0;
    cout << "Enter number of thread" << endl;
    cin >> count;

    {
        unsigned int start_time = clock();

        make(folderPath, count);

        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        cout << endl;
        cout << search_time << endl;
    }

    return 0;
}