//
// Created by 派星星 on 2019/11/23.
//
#include "global.h"

#define BoardSize 8
struct pt {
    int x;
    int y;
};

char board[BoardSize][BoardSize];
int tile = 0;

void ptBoard() {
    for (int i = 0; i < BoardSize; ++i) {
        for (int j = 0; j < BoardSize; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void initBoard() {
    for (int i = 0; i < BoardSize; ++i) {
        for (int j = 0; j < BoardSize; ++j) {
            board[i][j] = '.';
        }
    }
}

void setPoint(struct pt t, char c) {
    board[t.y][t.x] = c;
}

bool inSquare(struct pt o, struct pt b, int size) {
    return b.x >= o.x && b.x < o.x + size &&
           b.y >= o.y && b.y < o.y + size;
}

void solve(struct pt o, struct pt strange, int size) {
    if (size == 1) return;
    ptBoard();

    int s = size / 2;
    int t = ++tile;


    struct pt _pt = o;
    struct pt new_st;
    if (inSquare(_pt, strange, s)){
        solve(_pt, strange, s);
    }else{
        new_st = {o.x + s - 1, o.y + s -1};
        setPoint(new_st, 'A' + t);
        solve(_pt, new_st, s);
    }


    _pt = {o.x + s, o.y};
    if (inSquare(_pt, strange, s)){
        solve(_pt, strange, s);
    }else{
        new_st = {o.x + s, o.y + s -1};
        setPoint(new_st, 'A' + t);
        solve(_pt, new_st, s);
    }


    _pt = {o.x, o.y + s};
    if (inSquare(_pt, strange, s)){
        solve(_pt, strange, s);
    }else{
        new_st = {o.x + s - 1, o.y + s};
        setPoint(new_st, 'A' + t);
        solve(_pt, new_st, s);
    }


    _pt = {o.x + s, o.y + s};
    if (inSquare(_pt, strange, s)){
        solve(_pt, strange, s);
    }else{
        new_st = {o.x + s, o.y + s};
        setPoint(new_st, 'A' + t);
        solve(_pt, new_st, s);
    }
}

void cover_board() {
    initBoard();
    struct pt strange = {6, 3};
    setPoint(strange, '@');

    cout << "the init board:" << endl;
    ptBoard();

    solve({0, 0}, strange, BoardSize);
    ptBoard();
}