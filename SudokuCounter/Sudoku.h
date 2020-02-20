#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

struct trueNumber;
struct Top;
struct ZeroPoint;

std::vector<ZeroPoint *> checkZero(int (&mainMass)[9][9]);

void checkVertical(int (&mainMass)[9][9], ZeroPoint *obj);

void checkHorizontal(int (&mainMass)[9][9], ZeroPoint *obj);

void checkSquare(int (&mainMass)[9][9], ZeroPoint *obj);

size_t manager(int (&mass)[9][9], int from);

void showMass(int (&mass)[9][9]);

struct trueNumber {
    trueNumber() {
        for (int i = 0; i <= 10; i++) {
            mass[i] = true;
        }
    }

    bool mass[11]{};
};

struct Top {
    int horizontal = 0;
    int vertical = 0;
};

struct ZeroPoint {
    ZeroPoint(int hor, int ver) : horizontal(hor), vertical(ver) {

        squareTop = new Top;
        house = new trueNumber;

        int hor0;
        int ver0;

        if (horizontal < 3) {
            hor0 = 2;
        } else if (horizontal < 6) {
            hor0 = 5;
        } else { hor0 = 8; }

        if (vertical < 3) {
            ver0 = 2;
        } else if (vertical < 6) {
            ver0 = 5;
        } else { ver0 = 8; }

        squareTop->vertical = ver0;
        squareTop->horizontal = hor0;
    }

    int horizontal = 0;
    int vertical = 0;
    Top *squareTop;
    trueNumber *house;
};


#endif //SUDOKU_H
