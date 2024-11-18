//
// Created by Eric Zhong on 11/17/24.
//
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long n;
long long co = 0;
long long c[2000005];

ifstream fin;
ofstream fout("lemonade.out");


int main () {
    fin.open("lemonade.in");
    fin >> n;
    for (long long i = 0; i < n; i++) {
        fin >> c[i];
    }
    sort(c, c+n);
    for (long long i = n - 1; i >= 0; i--) {
        if (c[i] >= co) {
            co++;
        }
        else {
            fout << co;
            break;
        }
    }
}
