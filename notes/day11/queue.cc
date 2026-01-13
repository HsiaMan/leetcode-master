#include <iostream>
#include <ostream>
#include <queue>
int main(){

   std::queue<int> _que1;
   _que1.push(1);
   int ele = _que1.front();
   // int ele = _que1.back();
   std::cout << ele << std::endl; 
   int a = 5;
   while (--a) {
      std::cout << "a = "<< a  << "\n";

   }
   std::cout << "a = " << a << std::endl;
   int b =5;
   for (; b>0; b--) {
      std::cout << "b = " << b << std::endl;
   }
   
}
