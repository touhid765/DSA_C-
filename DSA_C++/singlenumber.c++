#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
   int singleNumber(vector<int>& nums)
   {
       int n = nums.size();
       int xorResult = 0;


       // XOR all elements: duplicates cancel out, single remains
       for (int i = 0; i < n; i++) {
           xorResult ^= nums[i];
       }
       return xorResult;
   }
};


int main() {
   // Test case: all elements appear twice except 4
   vector<int> nums = {2, 3, 5, 4, 5, 3, 2};


   Solution sol;
   int result = sol.singleNumber(nums);


   cout << "Single number is: " << result << endl;


   return 0;
}
