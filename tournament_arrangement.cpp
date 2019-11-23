//
// Created by 派星星 on 2019/11/23.
//
#include "global.h"

#define N 8

int table[N][N];

struct pt {
    int x;
    int y;
};

void assignmat(struct pt src_pt, struct pt tar_pt, int sz) {
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            table[tar_pt.y + i][tar_pt.x + j] = table[src_pt.y + i][src_pt.x + j];
        }
    }
}

void solve(int rows2cover) {
    if (rows2cover == 1) {
        for (int i = 0; i < N; ++i) {
            table[0][i] = i + 1;
        }
        return;
    }

    int sz = rows2cover / 2;
    solve(sz);


    for (int x1 = 0; x1 < N; x1 += rows2cover) {
        struct pt b1 = {x1, 0};
        struct pt b2 = {x1 + sz, 0};
        struct pt b3 = {x1, sz};
        struct pt b4 = {x1 + sz, sz};

        assignmat(b1, b4, sz);
        assignmat(b2, b3, sz);
    }

}

void pt_Board_() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void tournament_arrangement() {
    solve(N);
    pt_Board_();
}