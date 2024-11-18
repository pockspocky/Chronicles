//
// Created by Eric Zhong on 11/17/24.
//
#include <iostream>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;

int L, N, rf, rb;
pair<int, int> r[100005];
stack<pair<int, int>> st;
vector<pair<int, int>> v;
int total;
int ac = 1;
int diff;
int pos = 0;

ifstream fin ("reststops.in");
ofstream fout ("reststops.out");

int main () {
    fin >> L >> N >> rf >> rb;
    for (int i = 0; i < N; i++) {
        int a, b;
        fin >> a >> b;
        r[i] = {a, b};
    }

    st.push(r[0]);

    while (!st.empty() && ac < N) {
        pair<int, int> a = r[ac];
        pair<int, int> top = st.top();
        while (top.second < a.second && !st.empty()) st.pop();
        st.push(a);
        ac++;
    }

    diff = rf - rb;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    for (int i = v.size()-1; i >= 0; i--) {
        total += (v[i].first - pos) * diff * v[i].second;
        pos = v[i].first;
    }

    fout << total;
}