#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
int main(){
   // std::vector<int> num1 = {1,2,3,4,5,6,7};
   // for(int i = 0;i < num1.size();i++){
   //    std::cout << "i = " << i << std::endl;
   //    std::cout << "num[" <<i<< "]=" << num1[i] << std::endl;
   // }


   std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
   std::string s =  "    hello world  blue sky ";
   int slow = 0,fast = 0;
   // 字符串开头的位置
   for (size_t i = 0 ; i < s.size(); i++) {
      // 删除空格,
      // 是否需要跳过空格
      if (s[i] != ' ') {
         if (slow != 0 ) s[slow++] = ' ';
         while (i < s.size() && s[i] != ' ') {
            s[slow++] = s[i++];
         }
      }
   }


   // for (int i = 0 ; i < s.size(); i++) {
   //    // 这个是为了跳过空格
   //    // 是否需要插入空格
   //    if (s[i] != ' ') {
   //       // 是否需要插入分隔符
   //       if(slow != 0) s[slow++] = ' ';
   //       while (i < s.size() && s[i] != ' ') {
   //          s[slow++] = s[i++];
   //       }  
   //    }
   // }



   // for (int i = 0; i < s.size(); ++i) {
   //    // 遇到非空就处理，删除所有空格
   //    if (s[i] != ' ') {
   //       // 不是第一个单词就要插入一个空格
   //       if (slow != 0) s[slow++] = ' ';
   //       // 双指针移动
   //       while (i < s.size() && s[i] != ' ')  {
   //          // 开始移动字符
   //          s[slow++] = s[i++];
   //       }
   //    }
   // }
   std::cout << "s.size() before" << s.size() << std::endl;
   
   s.resize(slow);
   std::cout << s << std::endl;
   int left = 0;int right = s.size() -1;
   while (left <= right) {
      std::swap(s[left],s[right]);
      left++;right--;
   }
   std::cout << s << std::endl;
   std::cout << "s.size() = " << s.size() << std::endl;





   return 0;
}
