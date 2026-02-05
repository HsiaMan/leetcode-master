#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    int x;

    A(int x = 0) : x(x) {
        cout << "构造 A(" << x << ")\n";
    }

    A(const A& other) {
        x = other.x;
        cout << "拷贝构造 A(" << x << ")\n";
    }

    ~A() {
        cout << "析构 A(" << x << ")\n";
    }
};

int main() {
    vector<A> v;
    v.push_back(A(1));
   cout << "第二次push_back----" << endl; 
    v.push_back(A(2));
   vector<A> v2;
   cout << "换用emplace_back()-----" <<endl;
   v2.emplace_back(3);
   v2.emplace_back(4);
   cout << "-----" <<endl;
   vector<A> v3(5);
   v3.emplace_back(5);
   v3.emplace_back(6);
}
