//
// Created by Eric Zhong on 9/23/24.
//
#include <iostream>
#include <algorithm>

using namespace std;

int mat[1005][1005];
int row[1005], row2[1005], col[1005], col2[1005];
int n;

signed main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int rw = 0;
    int cl = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        bool f = true;
        for (int j = 0; j < n; j++) {
            if (f) {
                a += mat[i][j];
                f = false;
            }
            else {
                b += mat[i][j];
                f = true;
            }
        }
        rw += max(a, b);
    }

    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        bool f = true;
        for (int j = 0; j < n; j++) {
            if (f) {
                a += mat[j][i];
                f = false;
            }
            else {
                b += mat[j][i];
                f = true;
            }
        }
        cl += max(a, b);
    }

    cout << max(rw, cl);
}