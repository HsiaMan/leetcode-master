#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // 模拟宾客进门顺序
    vector<string> guests = {"Alice", "Bob", "Alice", "Charlie", "Bob"};
    
    // 创建一个 uset 作为“签到表”
    unordered_set<string> checkInList;

    for (string name : guests) {
        // 【关键点】：查找签到表里有没有这个人
        // find() 如果没找到，会返回 end()
        if (checkInList.find(name) != checkInList.end()) {
            cout << name << " 已经在派对里了，跳过！" << endl;
        } else {
            cout << "欢迎 " << name << " 进入派对。" << endl;
            // 第一次见到，把它记入签到表
            checkInList.insert(name);
        }
    }
    return 0;
}
