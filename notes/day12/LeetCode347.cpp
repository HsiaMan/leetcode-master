#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
int main(){
   std::vector<int > v= {1,2,3,4,1,2,3,2,1,2,3,2,1,1,2,3};
   std::unordered_map<int, int> counts;
   int k = 3;
   // 记录出现的次数
   for (int & num : v) {
      counts[num]++;
   }
   // 先进行打印
   for (auto & elem : counts) {
      std::cout << "elem_first" << elem.first << "   elem_second" << elem.second << "\n";
   }
   using PII = std::pair<int, int>;
   // PII(数据类型) std::vector<PII>底层容器 std::greater<PII>(比较器-最关键)
   std::priority_queue<PII,std::vector<PII>,std::greater<PII>> pq;

   // 遍历map，维护大小为 k 的小顶堆
   for (auto & elem : counts) {
      pq.push({elem.second,elem.first});  //插入{频率，数字}

      if (pq.size() > k) {
         // 弹出频率最小的
         pq.pop();      
      }
   }
   // 取出结果
   std::vector<int> result;
   while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
   }
   

   return 0;


}
