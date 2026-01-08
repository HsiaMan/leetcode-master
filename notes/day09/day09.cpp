#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --- 1. unique_ptr 场景：独占资源 ---
class Logger {
private:
    std::string m_name; 

public:
    // 构造函数：初始化 m_name
    Logger(std::string name) : m_name(name) { 
        std::cout << "[Logger] Create: " << m_name << std::endl; 
    }

    // 析构函数
    ~Logger() { 
        std::cout << "[Logger] destroy: " << m_name << std::endl; 
    }

    // 成员函数：使用 m_name 打印日志
    void log(std::string msg) { 
        std::cout << "[" << m_name << "] " << msg << std::endl; 
    }
};

// --- 2. shared_ptr & weak_ptr 场景：共享任务与循环引用 ---
class Task {
public:
    string _taskName;
    shared_ptr<Task> _nextTask;     // 强引用：指向下一个任务
    weak_ptr<Task> _prevTask;       // 弱引用：指向前一个任务（防止循环引用）
    Task(string name) : _taskName(name) { cout << "[Task] created: " << _taskName << endl; }
    ~Task() { cout << "[Task] destroyed: " << _taskName << endl; }

    void execute() { cout << "[执行中] " << _taskName << endl; }
};

int main() {
    cout << "---  unique_ptr ---" << endl;
    {
        // 使用 make_unique 创建独占指针
        unique_ptr<Logger> sysLogger = make_unique<Logger>("系统主日志，使用unique_ptr");
        sysLogger->log("系统启动中...");

        // unique_ptr 不能拷贝，下面这行会编译报错：
        // unique_ptr<Logger> errorPtr = sysLogger; 

        // 只能移动所有权，将所有权转移给newOwner
        unique_ptr<Logger> newOwner = std::move(sysLogger); 
        if (!sysLogger) {
            cout << "sysLogger 现在为空，所有权已转移。" << endl;
        }
        newOwner->log("所有权成功转移给 newOwner。");
    } // 此时 newOwner 超出作用域，Logger 被自动销毁

    cout << "\n--- 开始演示 shared_ptr & weak_ptr ---" << endl;
    shared_ptr<Task> worker1_ref; // 外部引用，用于演示引用计数

    {
        // 创建两个任务
        auto taskA = make_shared<Task>("任务A (下载)");
        auto taskB = make_shared<Task>("任务B (解析)");

        // 设置任务链：A -> B
        taskA->_nextTask = taskB;
        
        // 设置任务链：B -> A (如果这里也用 shared_ptr，就会形成死锁/内存泄漏)
        // 使用 weak_ptr，引用计数不会增加
        taskB->_prevTask = taskA; 
      

        cout << " Task A reference count: " << taskA.use_count() << endl; // 结果为 2 (taskA 自己 + taskB 的 prevTask 不算计数)
        // 注意：因为 prevTask 是 weak_ptr，所以 A 的计数其实只有 1（taskA 本身）
        // 实际计数：taskA(1), taskB(2, 因为被 taskA 强引用)

        worker1_ref = taskA; 
        cout << "worker1_ref 也引用了 A，计数: " << taskA.use_count() << endl; // 2
        
        // 演示 weak_ptr 的使用
        if (auto parent = taskB->_prevTask.lock()) { // 必须 lock() 提权为 shared_ptr 才能访问
            cout << "通过 B 找到前置任务: " << parent->_taskName << endl;
        }

    } // 离开此作用域后，taskB 计数清零被销毁，进而导致 taskA 的计数减 1

    cout << "\n--- 演示 worker1_ref 最终销毁 ---" << endl;
    cout << "worker1_ref 名字: " << worker1_ref->_taskName << endl;
    worker1_ref.reset(); // 手动清空 worker1_ref
    
    cout << "程序结束。" << endl;
    return 0;
}
