#include <iostream>

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