#include <iostream>
#include <latch>
#include <list>
#include <stack>
#include <vector>
int main(){
   // std::vector<int> v = {1,2,3,4,5};
   // for (auto it = v.begin(); it != v.end(); ++it) {
   //    if (* it %2 == 0) {
   //       it = v.erase(it);
   //    }else {
   //       it++;
   //    }
   // }  
   std::stack<int> in;
   std::stack<int> out;
   in.push(1);
   in.push(2);
   in.push(3);
   in.push(4);
   in.push(5);

   while (!in.empty()) {
      int result = in.top();
      in.pop();
      out.push(result);
   }
   while (!out.empty()) {
      int result = out.top();
      out.pop();
      std::cout << "top's elem is " << result <<  std::endl;
   }
   std::list<int> l1;
   l1.push_back(1);
   l1.push_back(2);
   l1.push_back(3);
   l1.push_back(4);
   l1.push_back(5);
   int elem = l1.front();
   std::cout << "elem is " << elem << std::endl;
   while (!l1.empty()) {
      int result = l1.front();

      std::cout << l1.back();
      l1.pop_back();

   }
   return 0;
   
}
// class MyQueue {
// public:
//     MyQueue() {
      
//     }
    
//     void push(int x) {
//       std::stack<int> in;
//       std::stack<int> out;

//     }
    
//     int pop() {
        
//     }
    
//     int peek() {
        
//     }
    
//     bool empty() {
//         return 
//     }
// };
