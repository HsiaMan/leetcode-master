#include <iostream>
#include <unordered_set>
#include <set>
#include <iostream>
#include <vector>

void setExample() {
    std::set<int> s = {50, 10, 30, 20};
    
    s.insert(40);

    // 遍历：会自动按 10, 20, 30, 40, 50 的顺序输出
    for (int x : s) {
        std::cout << x << " "; 
    }
}
int main() {
    std::unordered_set<int> mySet;

    // 1. 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10); // 重复元素，会被自动忽略

    // 2. 查找元素 (是否存在)
    // 方式 A: 使用 find()
    if (mySet.find(20) != mySet.end()) {
        std::cout << "20 存在" << std::endl;
    }

    // 方式 B: 使用 count() (结果只有 0 或 1)
    if (mySet.count(10)) {
        std::cout << "10 存在" << std::endl;
    }

    // 方式 C: C++20 引入的更简洁的 contains()
    // if (mySet.contains(30)) { ... }

    // 3. 删除元素
    mySet.erase(10);

    // 4. 遍历
    for (int x : mySet) {
        std::cout << x << " "; // 输出顺序是不确定的
    }
   std::cout << "\n";
   std::cout << "\n";
   std::vector<int> vec2 = {10,30,40,40};
   std::unordered_set<int> vecs1= {vec2.begin(),vec2.end()};
   for (auto elem : vecs1) {
      std::cout << elem << std::endl;
   }

    return 0;
}
