#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
int main(){
   const std::string s = "abadhkafkahfkahfkalhf";
   std::string strSub = s.substr(0,5);
   std::cout << strSub << "\n";
   const std::string s2 = "19216800";
   std::cout << s2.size() << std::endl;
   std::vector<std::vector<std::string>> res ;
   const std::string path = "abcd";
   std::vector<std::string> path2;
   path2.push_back(s2);
   for (const auto & ele : path2) {
      std::cout << ele;
   }
   std::cout << "\n";
   std::string s3 = "123";
   std::cout << stoi(s3)<< "\n";
   std::vector<int > nums;
   for(size_t i = 0; i < 10;i++){
      nums.push_back(i);
   }
   for (const auto &ele : nums) {
      std::cout << ele << std::endl;
   }
   return 0;
}
