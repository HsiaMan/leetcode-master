#include <iostream>
#include <vector>
int main(){
   std::vector<int> v = {1,2,3,4,5};
   for (auto it = v.begin(); it != v.end(); ++it) {
      if (* it %2 == 0) {
         it = v.erase(it);
      }else {
         it++;
      }
   }
}
