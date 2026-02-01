
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
  // 存储数字对应的字符串
  const string letterMap[10] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz", // 9
};
  string s ;
  vector<string>path;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return path;
        dfs(digits,0);
        return path;
    }
    void dfs(const string & digits,int startIndex){
      // 终止剪枝
      if(s.size() == startIndex){
        path.push_back(s);
        return;
      }
      // 处理当前层
      int digit = digits[startIndex] - '0';    // 讲字符数字转换成整数下标
      string letters = letterMap[digit];  // 拿到对应的字母集
      
      for(int i = startIndex;i <letters.size();++i){
        s.push_back(letters[i]);    // 进程；选字母
        dfs(digits,startIndex + 1);
        s.pop_back(); 
      }
    }
};
int main(){
  


   return 0;
}
