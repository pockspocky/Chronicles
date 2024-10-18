//
// Created by Eric Zhong on 10/14/24.
//
#include <iostream>

using namespace std;

bool m[1005][1005];
int n;

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'L') {
                m[i][j] = false;
            }
            else m[i][j] = true;
        }
    }

    // col fix
    for (int i = 0; i < n; i++) {
        if (m[0][i]) {
            for (int j = 0; j < n; j++) {
                m[j][i] = !m[j][i];
            }
        }
    }

    // row fix
    for (int i = 1; i < n; i++) {
        if (m[i][0]) {
            for (int j = 0; j < n; j++) {
                m[i][j] = !m[i][j];
            }
        }
    }

    bool flag = 1;

    for (int i = 1; i < n ; i++) {
        for (int j = 1; j < n; j++) {
            if (!m[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
                flag = !flag;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) {
        cout << 1 << " " << 1 << endl;
    }

}