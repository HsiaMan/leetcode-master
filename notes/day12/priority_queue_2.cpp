#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int val;
    int priority;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) {
        return a.priority < b.priority; // 大优先级先出
    }
};

int main() {
    priority_queue<Node, vector<Node>, Cmp> pq;

    pq.push({10, 2});
    pq.push({20, 5});
    pq.push({30, 1});

    cout << pq.top().val << endl;  // 20
}
