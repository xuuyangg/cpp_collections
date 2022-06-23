/*
created by xuyang in zju
*/


#include <queue>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    auto cmp = [](auto first, auto second) {
        return first[0] + first[1] > second[0] + second[1];
    };
    priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp);
    pq.push(vector<int>{1,2});
    pq.push(vector<int>{1,3});
    pq.push(vector<int>{1,4});
    pq.push(vector<int>{1,5});
    pq.push(vector<int>{0,0});
    while(!pq.empty()) {
        std::cout << pq.top()[0] << ' ' << pq.top()[1] << endl;
        pq.pop();
    }
    return 0;
}