//
// Created by Eric Zhong on 10/17/24.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int n, m;
set <int> c;
stack <int> st;
vector <pair<int, int>> in;

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        in.push_back(pair<int, int> (a, b));
    }
    int ac = 0;
    for (int i = n-1; i >= 0; i--) {
        pair <int, int> a = in[i];
        bool f = c.count(a.first);
        bool s = c.count(a.second);

        if (!f) {
            c.insert(a.first);
            ac++;
            st.push(ac);
            continue;
        }
        if (!s) {
            ac++;
            c.insert(a.second);
            st.push(ac);
            continue;
        }
        st.push(ac);
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}