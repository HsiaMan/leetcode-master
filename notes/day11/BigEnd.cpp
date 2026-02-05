#include <iostream>
   using namespace std;
bool is_big_endian(){
   int num = 1;
   if (*(char * ) & num == 1) {
      // 当前系统为小端
      return false;
   }else {
      return true;
   }
}

int main() {
    int num = 0x12345678;
   // 大端的数据低地址存高位，小端的话，低地址存地位数据
    char* p = (char*)&num;

    cout << "原始数据：" << hex << num << endl;

    if (is_big_endian()) {
        cout << "当前系统为大端序" << endl;
        cout << "字节序为：";
        for (int i = 0 ; i < sizeof(num); i++) {
            std::cout << hex <<(int) * (p + i) << "";
        }
      //   for (int i = 0; i < sizeof(num); i++) {
      //       cout << hex << (int)*(p + i) << " ";
      //   }
        cout << endl;
    } else {
        cout << "当前系统为小端序" << endl;
        cout << "字节序为：";
        for (int i = sizeof(num) - 1; i >= 0; i--) {
            cout << hex << (int)*(p + i) << " ";
        }
        cout << endl;
    }

    return 0;
}
