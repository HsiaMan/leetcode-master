#include <iostream>
#include <queue>
#include <utility>
#include <vector>
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

   // using PII = std::pair<int , int>;
   // std::vector<int> v2 = {12,12,23,4,5,6,78,10,56};
   std::pair<int, int> p1 = {2,4};
   std::vector<std::pair<int, int>> p2= {{2,3},{2,3},{3,4},
                                    {5,6},{7,8},{9,10}};
   for (const auto & elem : p2) {
      std::cout << "first elem = " << elem.first << " second elem = " 
      << elem.second << std::endl;

   }

   

    cout << pq.top().val << endl;  // 20
}
