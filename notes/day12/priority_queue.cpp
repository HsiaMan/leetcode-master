#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

// 1. 定义病患结构体
class Patient {
public:
    int _priority;       // 优先级 (0-10, 10最高)
    std::string _name;   // 姓名
    int _arrival_order;  // 到达顺序 (用于优先级相同时的辅助排序)
Patient(int p ,std::string n ,int a ):_priority(p),_name(n),_arrival_order(a){}
    // 2. 重载 < 运算符 (这是优先级队列排序的核心)
    // 注意：priority_queue 默认是大顶堆，它会把“最大”的元素放在堆顶。
    // 在比较函数中，如果我们想让 priority 大的排在前面，
    // 当 return true 时，表示当前元素优先级低，会被排在后面。
    bool operator<(const Patient& other) const {
        if (this->_priority != other._priority) {
            // 优先级不相等时，数值小的排在后面
            return this->_priority < other._priority; 
        }
        // 如果优先级相等，则比较到达顺序，先到的应该先看
        // 在 priority_queue 中，如果我们要“先来后到”，
        // 到达序号大的反而应该被视为“较小”优先级排在后面
        return this->_arrival_order > other._arrival_order;
    }
};

int main() {
    // 3. 创建优先级队列
    // 类型是 Patient，底层容器用 vector，排序规则用 Patient 内部定义的 <
    std::priority_queue<Patient> er_queue;

    // 4. 模拟病患到达
    std::cout << "--- 正在登记病患 ---" << std::endl;
    
    // push 操作的时间复杂度是 O(log N)
   std::vector<Patient> v1 = {{3, "张三", 1},
                                   {10, "李四", 2},
                                   {5, "王五", 3},
                                   {5, "赵六", 4}
                                  };
   //  er_queue.push(); // 感冒
   //  er_queue.push(); // 严重外伤 (最高优先级)
   //  er_queue.push(); // 持续发烧
   //  er_queue.push(); // 腹痛 (与王五优先级相同，但后到)

    std::cout << "当前急诊室人数: " << er_queue.size() << "\n\n";

    // 5. 医生开始叫号
    std::cout << "--- 医生开始诊疗 ---" << std::endl;
    
    while (!er_queue.empty()) {
        // top() 获取当前优先级最高的病患，时间复杂度 O(1)
        Patient current = er_queue.top();
        
        std::cout << "叫号: " << current._name 
                  << " [优先级: " << current._priority 
                  << ", 到达序号: " << current._arrival_order << "]" << std::endl;
        
        // pop() 移除最前面的元素并重新调整堆，时间复杂度 O(log N)
        er_queue.pop();
    }

    return 0;
}
