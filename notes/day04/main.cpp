#include <cstddef>
#include <iostream>
int main(){
   size_t n = 10;
   int i = 0;
   while (n--) {
      std::cout <<" i = "<< i++ << std::endl; 
      std::cout <<" n = " << n << std::endl;
   }
   return 0;

}
