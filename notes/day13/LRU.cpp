#include <list>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class Node{
   public:
      int _key,_value;
      Node * _next;
      Node * _pre;
      Node(int k,int v):_key(k),_value(v){   
      }
};
class DoubleList{
   private:
      //头尾虚节点
      Node * _head;
      Node * _tail;
      int _size;
public:
   DoubleList(){
      // 初始化双向链表的数据
      _head = new Node(0,0);
      _tail = new Node(0,0);
      _head->_next = _tail;
      _tail->_pre = _head;
      _size = 0;
   }
   void addLast(Node * x){
      x->_pre = _tail->_pre;
      x->_next = _tail;
      _tail->_pre->_next = x;
      _tail->_pre = x;
      _size++;

   }

   void remove(Node  * & x ){
      x->_pre->_next = x->_next;
      x->_next->_pre = x->_pre;
      delete  x;
      x = nullptr;
      _size--;

   }
   // 删除链表中第一个节点，并返回该节点
   Node * removeFirst(){
      if (_head->_next == _tail) 
         return nullptr;
      Node * first = _head->_next;
      remove(first);
      return first;
   }
   // 返回链表长度
   int getSize(){
      return _size;
   }
};
class LRUCache{
   private:
      std::unordered_map<int , Node * >_mp;
      DoubleList _cache;
      // 最大容量
      int _cap;
      void makeReccently(int  & key){
         Node * x = _mp[key];
         // 先从链表中删除这个节点
         _cache.remove(x);
         // 重新插到队尾
         _cache.addLast(x);
      }
      void addRecently(int key,int val){
         Node * x = new Node(key,val);
         _cache.addLast(x);
      }
      // 删除一个key
      void deleteKey(int key){
         Node * x = _mp[key];
         // 从链表中删除
         _cache.remove(x);
         // 从map中删除
         _mp.erase(key);
      }
      // 删除最久未使用的元素
      void removeLeastRecently(){
         // 链表头部的第一个元素就是最久未使用的
         Node * deleteNode = _cache.removeFirst();
         // 同时别忘了从map中删除它的key
         int deleteKey = deleteNode->_key;
         _mp.erase(deleteKey);
      }

   public:
      LRUCache(int capacity):_cap(capacity){};

      int get(int key){
         if (!_mp.count(key)) {
            return -1;
         }
         // 将该数据提升为最近使用的
         makeReccently(key);
         return _mp[key]->_value;
      }
      void put(int key,int val){
         if (_mp.count(key)) {
            // 删除旧的数据
            deleteKey(key);
            // 新插入的数据为最近使用的数据
            addRecently(key, val);
            return;
         }
         if (_cap == _cache.getSize()) {
            // 删除最近未使用的元素
            removeLeastRecently();
         }
         // 添加未最近使用的元素
         addRecently(key, val);
      }
}; 

int min(){  
   std::list<std::pair<int, int>> cache;
   // 这个iterator其实指向的是某一个list节点的位置，本质上就是一个链表节点指针
   std::unordered_map<int ,std::list<std::pair<int, int>>::iterator> mp;

   return 0;
}
