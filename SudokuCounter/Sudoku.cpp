#include <iostream>
#include "Sudoku.h"

std::vector<ZeroPoint *> massZero{};

std::vector<ZeroPoint *> checkZero(int (&mainMass)[9][9]) {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            if (mainMass[i][j] == 0) {
                auto *obj = new ZeroPoint(i, j);
                massZero.push_back(obj);
            }
        }
    }
    return massZero;
}

void checkVertical(int (&mainMass)[9][9], ZeroPoint *obj) {
    for (int i = 0; i <= 8; i++) {
        if (mainMass[i][obj->vertical] != 0)
            obj->house->mass[mainMass[i][obj->vertical]] = false;
    }
}

void checkHorizontal(int (&mainMass)[9][9], ZeroPoint *obj) {
    for (int i = 0; i <= 8; i++) {
        if (mainMass[obj->horizontal][i] != 0)
            obj->house->mass[mainMass[obj->horizontal][i]] = false;
    }
}

void checkSquare(int (&mainMass)[9][9], ZeroPoint *obj) {
    int hor = obj->squareTop->horizontal;
    int ver = obj->squareTop->vertical;

    for (int i = hor; i > hor - 2; i--) {
        for (int j = ver; j > ver - 2; j--) {
            obj->house->mass[mainMass[i][j]] = false;
        }
    }
}

size_t manager(int (&mass)[9][9], int from) {

    short countFalse = 0;

    for (; from < massZero.size(); from++) //NOLINT
    {
        checkVertical(mass, massZero[from]);
        checkHorizontal(mass, massZero[from]);
        checkSquare(mass, massZero[from]);

        for (int i = 1; i <= 9; i++) {

            if (massZero[from]->house->mass[i]) {
                mass[massZero[from]->horizontal][massZero[from]->vertical] = i;
                massZero[from]->house->mass[i] = false;
                countFalse = 0;
                break;
            } else {
                countFalse++;
            }

            if (countFalse == 9)
                if (from - 1 < 0)
                    return from - 1;
        }
    }
    return massZero.size();
}

void showMass(int (&mass)[9][9]) {
    for (auto &mas : mass) {
        for (int ma : mas) {
            std::cout << ma << " ";
        }
        std::cout << std::endl;
    }
}
