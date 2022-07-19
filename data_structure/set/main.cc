#include <iostream>
#include <set>

using namespace std;

int main() {

    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.first <= b.first && a.second <= b.first;
    };
    set<pair<int, int>, decltype(cmp)> s(cmp);

    s.insert(pair<int, int>(1,2));
    s.insert(pair<int, int>(2,3));
    s.insert(pair<int, int>(1,2));
    for (auto item : s) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}

/*
output:
1 2
2 3
*/