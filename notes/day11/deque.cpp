#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    deque<int> dq2;

    dq2.push_back(1);   // 尾插
    dq2.push_back(2);
    dq2.push_front(0);  // 头插

    // 当前 deque: [0, 1, 2]

    cout << dq2.front() << endl;  // 0
    cout << dq2.back() << endl;   // 2

    dq2.pop_front();  // 删除 0
    dq2.pop_back();   // 删除 2

    // 当前 deque: [1]

    for (int x : dq2) {
        cout << x << " ";
    }
    cout << endl;
   vector<int> v1 = {1,-2,3,4,-5,8,10,-19,20};
   deque<int> dq;
   for (const auto & elem : v1) {
      dq.push_back(elem);
   }
   std::cout << "dq_front() = " << dq.front() << std::endl;
   dq.pop_front();
   std::cout << "dq_front() = " << dq.front() << std::endl;
   // vector<int> result;
   // int k = 3;
   // // 从队尾移除比当前元素小的
   // for (int i = 0; i < v1.size(); i++) {
   //    while (!dq.empty() && v1[dq.back()] <= v1[i]) {
   //       dq.pop_back();
   //    }
   //    dq.push_back(i);
   //    // 移除滑出窗口的元素
   //    if (!dq.empty() && dq.front() <= i -k) {
   //       dq.pop_front();
   //    }
   //    // 当前窗口形成后，记录最大值
   //    if (i > k -1) {
   //       result.push_back(v1[dq.front()]);

   //    }

   // }
   return 0;
}
