#### [383. 赎金信](https://leetcode.cn/problems/ransom-note/)

```C++
class Solution {
public:
    // bool canConstruct(string ransomNote, string magazine) {
    //     // 如果信比杂志还长，肯定做不出来
    //     if(ransomNote.size() > magazine.size())
    //         return false;
        
    //     std::unordered_map<char,int> str_map;
    //     // 统计杂志中所有的字符
    //     for(char c : magazine){
    //         str_map[c]++;
    //     }
    //     // 检查赎金信里的每个字母
    //     for(char c:ransomNote){
    //         // 用去一个字母
    //         str_map[c]--;
    //         // 用去了之后，库存为负，说明不够
    //         if(str_map[c] < 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    bool canConstruct(string ransomNote, string magazine) {
        //使用纯数组
        if(ransomNote.size() > magazine.size())
            return false;
        // 构建一个26 长度的字符
        int array[26] = {0};
        for(int i = 0;i < magazine.size();i++){
            array[magazine[i] - 'a']++;
        }
        for(int i = 0 ;i < ransomNote.size();i++){
            array[ransomNote[i]-'a']--;
            if(array[ransomNote[i]-'a'] < 0){
                return false;
            }
        }
        return true;
        
    }
};
```

这个题目和`LeetCode242`题目不一样，那一题两个字符的长度是一样的，这题两个长度是不一样的。所以在比较的时候，不可以用同一个长度

>[!CAUTION]
>
>**在本题的情况下，使用map的空间消耗要比数组大一些的，因为map要维护红黑树或者哈希表，而且还要做哈希函数，是费时的！数据量大的话就能体现出来差别了。 所以数组更加简单直接有效！**

CPP 中的 `std::string`中，`size()`和`length()`没有任何区别，他们的作用完全相同，返回结果也完全一样，时间复杂度都是`O(1)`

##### `size()`和`length()`的区别是什么

- **size()**：是为了与其他 STL 容器（如 std::vector、std::list、std::map）保持**一致性**。在 C++ 中，几乎所有容器都有 size() 函数来表示它包含多少个元素。
- **length()**：是符合人类的**自然语言习惯**。在处理文本时，我们通常会说“字符串的长度”（length），而不是“字符串的大小”（size）。这主要是为了让从其他语言（如 C 语言的 strlen）熟悉

#### [15. 三数之和](https://leetcode.cn/problems/3sum/)

对于这题

#### `push_back`和`emplace_back`区别

`push_back`接受一个已存在的队形（需要拷贝或移动构造）

`emplace_back`直接在容器内存中构造对象（无需拷贝移动，直接调用构造函数）

```C++
std::vector<std::vector<int>> result;
result.push_back({nums[i],nums[left],nums[right]});  //正确
result.emplace_back(vector<int>{nums[i],nums[left],nums[right])	//正确、
result.emplace_back({nums[i],nums[left],nums[right]});	//错误
```

- **push_back**：它的参数明确要求是一个元素对象（在本例中是 vector<int>）。当你传入 {a, b, c} 时，编译器知道你需要构造一个 vector<int>，所以它会自动帮你完成转换。
- **emplace_back**：是一个**模板函数**，它设计初衷是让你传入构造函数的**参数**，然后在容器内部直接构造对象。当你传入 {nums[i], nums[left], nums[right]} 时，emplace_back 并不知道这个大括号到底是要构造一个 vector<int>，还是一个自定义的结构体，或者是别的什么。编译器无法从 {...} 中推导出模板参数类型，所以报错。

##### 什么时候用`emplace_bcak`

`emplace_back()`不能直接推到大括号`{}`，如果必须要用的话，必须显示告诉类型`emplace_back(std::vector<int>{a,b,c})`

只有当传入的参数直接对应构造函数的参数列表时，`emplace_back`才好用

例：

假设你有一个结构体 struct Person { string name; int age; }; 和 vector<Person> v;

- v.push_back({"Tom", 18}); // 正确，自动转 Person
- v.emplace_back("Tom", 18); // 正确，直接把 "Tom" 和 18 传给 Person 的构造函数（性能最好）
- v.emplace_back({"Tom", 18}); // **错误！** 同样无法推导大括号

##### 核心区别

假设你的 vector 是一个房间，你要往里放一个沙发（对象）。

##### **push_back：（搬运）**

1. 创建一个临时对象。
2. **拷贝**或者**移动**到 vector 的内存空间。
3. **销毁临时对象**。

##### **emplace_back：（原地构造）**

1. **传入构造函数的参数**）。
2. （**在 vector 内存中直接构造对象**）。

这是 emplace_back 最容易“翻车”的地方：**模板推导失败**。

- **push_back 的参数**：它明确知道自己要一个 vector<int> 对象。当你给它 {1, 2, 3} 时，它知道：“噢，这是给我的参数，我要把它变成一个 vector<int> 搬进去。”
- **emplace_back 的参数**：它是**万能模板**（Variadic Templates）。它看到的参数是 {1, 2, 3}，它就糊涂了：“这个 {1, 2, 3} 到底是个数组？是个结构体？还是个列表？”因为它要直接把参数传给构造函数，但在推导阶段，它**无法确定**这个大括号对应哪个构造函数。

**结论**：emplace_back 不能直接推导大括号 {}。如果你非要用，必须显式告诉它类型：emplace_back(std::vector<int>{a, b, c})。

##### 性能对比

```c++
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) { cout << "构造了\n"; }
};

vector<Person> v;
// push_back 写法
v.push_back(Person("张三", 20)); 
// 过程：1. 构造临时对象 -> 2. 拷贝/移动到容器-> 3. 析构临时对象
// emplace_back 写法
v.emplace_back("李四", 25); 
// 过程：1. 直接在 vector 内存里构造 Person。省事！
```

##### 到底该用哪个

在现代 C++ 开发中，建议遵循以下原则：

| 场景                       | 推荐做法         | 原因                                 |
| -------------------------- | ---------------- | ------------------------------------ |
| **直接传入大括号 {}**      | **push_back**    | 语法最简洁，不会报错。               |
| **传入多个参数构造对象**   | **emplace_back** | 性能最高，省去临时对象的开销。       |
| **已经有一个现成的对象**   | **push_back**    | 两者效果一样，push_back 语义更清楚。 |
| **基础类型 (int, double)** | **随便**         | 对于基础类型，两者性能完全没区别。   |

#### [18. 四数之和](https://leetcode.cn/problems/4sum/)

