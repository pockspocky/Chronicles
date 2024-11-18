//
// Created by Eric Zhong on 2024/10/27.
//

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

struct DTNode {
    int parent = -1;
    // self if == -1
};

DTNode DTset[10005];

int n;
map <int, int> v;

ifstream fin;
ofstream fout("planting.out");

int main () {
    fin.open("planting.in");
    fin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        fin >> a >> b;
        v[a]++;
        v[b]++;
    }
    int max = -1;
    for (auto p : v) {
        if (p.second > max) max = p.second;
    }

    fout << max + 1;
}