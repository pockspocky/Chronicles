//
// Created by Eric Zhong on 9/13/24.
//
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int k;

int cows[100005];

unordered_map<int, vector<int>> moves;
unordered_map<int, int> groups;
unordered_map<int, set<int>> res;

int main() {
    cin >> n >> k;

    for (int i = 1; i < 100005; i++) {
        cows[i] = i;
        moves[cows[i]].push_back(i);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        moves[cows[a]].push_back(b);
        moves[cows[b]].push_back(a);
        swap(cows[a], cows[b]);
    }

    for (int i = 1; i <= n; i++) {
        groups[i] = cows[i];
    }

    for (int i = 1; i <= n; i++) {
        int c = i;
        set<int> a;
        do {
            a.insert(cows[c]);
            c = cows[c];
        } while (c != i);
        set <int> x;
        for (int z : a) {
            for (int v : moves[z]) x.insert(v);
        }
        for (int p : a) {
            res[p] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i].size() << endl;
    }
}


