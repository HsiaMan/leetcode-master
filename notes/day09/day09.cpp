#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;
int main(){

    std::string s = "the sky is blue";
    
}
string reverseWords(string s){
    int left = 0;int right = s.size()-1;
    int fast = 0,slow = 0;
    for (size_t i = 0; i <= s.size(); i++) {
            
            swap(s[left],s[right]);
            left++;
            right--;
    }
    int cout = 0;
    for (int j = s.size(); j >=0; j--) {
        cout++;
        if (s[j] == ' ') {
            std::reverse(s.begin(), s.begin() + cout-1);
            while (s[j+1] == ' ') {

            }
        }
    }
    return s;
}


