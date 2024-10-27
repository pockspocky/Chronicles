#include <iostream>
#include <set>
#include <bitset>

using namespace std;

struct DTNode {
    int parent = -1;
    // self if == -1
};

DTNode DTset[10005];

int findRoot(DTNode x) {
    if (x.parent == -1) {
        return x.parent;
    }

    else {
        x.parent = findRoot(DTset[x.parent]);
        return x.parent;
    };
}

bool join (DTNode a, DTNode b) {
    int af = findRoot(a);
    int bf = findRoot(b);

    if (af == bf) return 0;
    else {
        DTset[bf].parent = af;
        return 1;
    }
}

int n, m;
set <int> un;
int inis;

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        char s;
        cin >> s >> a >> b;
        DTset[b].parent = a;
    }
    for (int i = 0; i < n; i++) {
        if (DTset[i].parent != -1) {
            un.insert(DTset[i].parent);
        }
    }
    inis = un.size();
    cout << 1;
    for (int i = 0; i < inis; i++) {
        cout << 0;
    }
}