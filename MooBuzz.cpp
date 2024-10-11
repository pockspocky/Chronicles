//
// Created by Eric Zhong on 9/30/24.
//
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


vector<long long> list;
long long n;

ifstream fin;
ofstream fout("moobuzz.out");


int main () {

    fin.open("moobuzz.in");
    fin >> n;
    // cin >> n;
    for (long long i = 1; i <= n+60; i += 15) {
        list.push_back(i);
        list.push_back(i+1);
        list.push_back(i+3);
        list.push_back(i+6);
        list.push_back(i+7);
        list.push_back(i+10);
        list.push_back(i+12);
        list.push_back(i+13);
    }

    fout << list[n-1];
    // cout << list[n-1];
}