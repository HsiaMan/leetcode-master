#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cstring>
#include <vector>
#include <array>

int main(){
   char s1[8] = "abcdefg";
   std::vector<std::array<char, 8>> v1;
   v1.emplace_back(std::array<char,8>{'a','b','d','e','d','j','m','n'});
   for(const auto & elem: v1.at(0)){
      std::cout << "elem = " << elem << std::endl;
   }
   std::string v2 = {'a','b','c','d','e','f','g','h','i','j','k'};
   for (const auto & elem: v2) {
      std::cout << elem << std::endl;
   }
   std::reverse(v2.begin(), v2.end());
   std::cout << "v2 ="<< v2 << std::endl;
   std::array<char, 11> v3 = {'a','b','c','d','e','f','g','h','i','j','\0'};
   // std::reverse(v3.begin(), v3.end());
   std::cout << "v3 = " << v3.data() << std::endl;
   std::cout << "v3[1]= " << v3[1] << std::endl;

   
   // 下面的写法是错误的
   // std::vector<char> s(8) = {'a','b','d','e','d','j','m','n'};
   std::vector<char> s2 = {'a','b','d','e','d','j','m','n'};
   char * sPtr = s1;
   for(int i = 0; i < strlen(s1);i++){
      std::cout << "sPtr[" <<i <<"]" <<  sPtr[i] << std::endl;
   }  
   std::vector<int> num1 ={1,3,46,67,8};
   for (const auto & elem  : num1) {
      std::cout << elem<< std::endl;
   }
   for (auto it= num1.begin(); it != num1.end() ;++it) {
      std::cout << *it << std::endl;
   }
   

   // std::vector<char> s[8] = "abcdefg";
   return 0;
   
}
