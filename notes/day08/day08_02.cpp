#include <cstddef>
#include <iostream>
#include <string>

int main(){
   // std::string input = "a1b2c3";
   std::string input;
   std::cin >> input ;
   // 先计算所有的存储的数字的大小
   int cout = 0;
   size_t i = 0;
   for(;i <= input.size()-1;i++){
      if (input[i] >= 48 && input[i] <= 57) {
         cout++;
      }
   }
   // std::cout << "i = " << i << std::endl;
   // std::cout << "size = " << sizeof("number");
   input.resize(input.size() + 5 * cout);
   std::cout << "input's size" << input.size() << std::endl;
   size_t sNewIndex = input.size()-1;
   for(int j = i-1;j >= 0;j--){
      // 数字的情况
      if (input[j] >= 48 && input[j] <= 57) {
         input[sNewIndex--] = 'r';
         input[sNewIndex--] = 'e';
         input[sNewIndex--] = 'b';
         input[sNewIndex--] = 'm';
         input[sNewIndex--] = 'u';
         input[sNewIndex--] = 'n';
      }else {
         input[sNewIndex--] = input[j]; 
      }
   }
   std::cout << input << std::endl;

   // std::cout << "number's size" << sizeof("number") << std::endl;

   // std::cout << s << std::endl;
   return 0;
}
