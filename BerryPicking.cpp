//
// Created by Eric Zhong on 10/11/24.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int b;
int mini = 10000, maxi = -1;
int t[1005];
int q;
vector <int> r;
vector <int> result;

int s (int a, int b) {
    return a > b;
}

signed main () {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mini = min(a, mini);
        maxi = max(maxi, a);
        t[i] = a;
    }

    for (int i = mini; i <= maxi; i++) {
        for (int j = 0; j < n; j++) {
            q += t[j]/i;
            r.push_back(t[j]%i);
        }
        if (b - q <= 0) {
            result.push_back((b / 2) * i);
        }
        else {
            int p = q * i;
            bool flag;
            if (q >= b / 2) {
                p -= (b / 2) * i;
            }
            else flag = true;
            int a = q;
            sort(r.begin(), r.end(), s);
            for (int j = 0; j < b-q; j++) {
                if (a >= b / 2 && flag) {
                    p = 0;
                    flag = !flag;
                }
                p += r[j];
                a++;
            }
            result.push_back(p);
        }
        q = 0;
        r.clear();
    }
    sort(result.begin(), result.end(), s);
    cout << result[0];
}


