#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   string multiply(string num1, string num2);
};
string Solution::multiply(string nums1, string nums2) {
   int n = nums1.size();
   int m = nums2.size();
   string ans(n + m, '0');
   for(int i = n - 1; i>=0; i--){
      for(int j = m - 1; j >= 0; j--){
         int p = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
         ans[i+j+1] = p % 10 + '0';
         ans[i+j] += p / 10 ;
      }
   }
   for(int i = 0; i < m + n; i++){
      if(ans[i] !='0')return ans.substr(i);
   }
   return "0";
}
int main(){
   Solution ob;
   string x,y;
   getline(cin,x);
   getline(cin,y);
   cout << ob.multiply(x, y);
}