#include <iostream>
#include <memory>
class Good :public std::enable_shared_from_this<Good>{
   public:
      std::shared_ptr<Good> getSelf(){
      // 会返回一个现有的、共享同一个内存块的 shared_ptr 
      return shared_from_this();
   }
   ~Good(){std::cout << "Destroyed" << std::endl;}

};
int main(){
   auto p1 = std::make_shared<Good>();
   auto p2 = p1->getSelf();
   std::cout << "Cout:" << p1.use_count() << std::endl;

   // 下，面的就是错误的
   Good g;
   auto p = g.getSelf();
   return 0;
   
}
