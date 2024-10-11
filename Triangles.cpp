//
// Created by Eric Zhong on 9/6/24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    int i;
    int x, y;
    int sum = 0;
};

bool fx1 (Node a, Node b) {
    if (a.y <= b.y) {
        return true;
    }
    return false;
}

bool fx2 (Node a, Node b) {
    if (a.x <= b.x) {
        return true;
    }
    return false;
}

void computeSumx (vector<Node>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        vect[0].sum += abs(vect[0].x - vect[i].x);
    }
    for (int i = 1; i < vect.size(); i++) {
        vect[i].sum = abs(vect[i-1].x - vect[i].x);
    }
}

void computeSumy (vector<Node>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        vect[0].sum += abs(vect[0].y - vect[i].y);
    }
    for (int i = 1; i < vect.size(); i++) {
        vect[i].sum = abs(vect[i-1].y - vect[i].y);
    }
}

int n;

long long total;

unordered_map<int, vector<Node>> xGroup;
unordered_map<int, vector<Node>> yGroup;

vector <Node> aSet;

set<int> uniqx;
set<int> uniqy;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        uniqx.insert(x);
        uniqy.insert(y);
        Node a = {i, x, y};
        aSet.push_back(a);
        xGroup[x].push_back(a);
        yGroup[y].push_back(a);
    }

    for (int i : uniqx) {
        sort(xGroup[i].begin(), xGroup[i].end(), fx1);
    }
    for (int i : uniqy) {
        sort(yGroup[i].begin(), yGroup[i].end(), fx2);
    }

    for (int i : uniqy) {
        computeSumy(xGroup[i]);
    }

    for (int i : uniqx) {
        computeSumx(yGroup[i]);
    }

    for (Node i : aSet) {
        total += (xGroup[i.y][0].sum + yGroup[i.x][0].sum) / 2;
    }

    cout << total % (10 ^ 9 + 7);
// xg is x same
    // yg is y same

}