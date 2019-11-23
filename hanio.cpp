//
// Created by 派星星 on 2019/11/23.
//
#include "global.h"


void _hanio(char a, char b, char c, int depth) {
    if (depth == 1) {
        cout << "mv " << a << " to " << c << endl;
        return;
    }

    // move blocks above the biggest block to b
    _hanio(a, c, b, depth - 1);

    // move the biggest block to c
    cout << "mv " << a << " to " << c << endl;

    // move blocks above the biggest block to c
    _hanio(b, a, c, depth - 1);
}

void hanio() {
    _hanio('A', 'B', 'C', 3);
}