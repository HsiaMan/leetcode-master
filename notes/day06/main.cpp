#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
#include <unordered_set>

void setExample() {
    std::unordered_set<int> visited;
    visited.insert(10);
    
    if (visited.count(10)) { // 如果存在则返回1，否则返回0
        // 已访问过
    }
}
void mapExample() {
    // 1. 定义
    std::unordered_map<std::string, int> scores;

    // 2. 插入
    scores["Alice"] = 95;
    scores.insert({"Bob", 80});

    // 3. 查找
    if (scores.find("Alice") != scores.end()) {
        int s = scores["Alice"];
    }

    // 4. 遍历
    for (auto const& [name, score] : scores) { // C++17 结构化绑定
        std::cout << name << ": " << score << std::endl;
    }
}

class SimpleHashTable {
private:
    // 桶的数量
    int BUCKET_;
    // 使用 vector 包含 list 来处理冲突 (链地址法)
   //    vector (下标)      list (链表内容)
   // [ 0 ]  ------>  (空)
   // [ 1 ]  ------>  {"Apple", 50}  -->  {"Orange", 80}  -->  nullptr
   // [ 2 ]  ------>  (空)
   // [ 3 ]  ------>  (空)
   // [ 4 ]  ------>  {"Banana", 100} -->  nullptr
    vector<list<pair<string, int>>> table_;

    // 哈希函数：简单的取模运算
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % BUCKET_ ;
    }

public:
    SimpleHashTable(int b) : BUCKET_(b) {
        table_.resize(BUCKET_);
    }

    // 插入
    void insert(string key, int value) {
        int index = hashFunction(key);
        // 检查是否已存在，存在则更新
        for (auto& pair : table_[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // 不存在则存入链表
        table_[index].push_back({key, value});
    }

    // 查找
    int get(string key) {
        int index = hashFunction(key);
        for (auto& pair : table_[index]) {
            if (pair.first == key) return pair.second;
        }
        return -1; // 未找到
    }
};


int main() {
    SimpleHashTable ht(10);
    ht.insert("Apple", 50);
    ht.insert("Banana", 100);

    cout << "Apple value: " << ht.get("Apple") << endl;   // 输出 50
    cout << "Banana value: " << ht.get("Banana") << endl; // 输出 100
    mapExample();
    return 0;
}



