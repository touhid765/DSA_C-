#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
   vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       long long actualSum = 0, actualSquareSum = 0;
       long long n = grid.size();
       long long N = n * n;


       // Compute the actual sum and sum of squares from the grid
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               int num = grid[i][j];
               actualSum += num;
               actualSquareSum += (long long)num * num;
           }
       }


       // Expected sum of numbers from 1 to N
       long long expectedSum = (N * (N + 1)) / 2;


       // Expected sum of squares of numbers from 1 to N
       long long expectedSquareSum = (N * (N + 1) * (2 * N + 1)) / 6;


       // Let repeated = a, missing = b
       // a - b = sumDifference
       long long sumDifference = actualSum - expectedSum;


       // a^2 - b^2 = squareSumDifference = (a - b)(a + b)
       long long squareSumDifference = actualSquareSum - expectedSquareSum;


       // (a + b) = squareSumDifference / (a - b)
       long long sum_ab = squareSumDifference / sumDifference;


       // Solving equations:
       // repeated = (a + b + a - b)/2 = (sum_ab + sumDifference) / 2
       // missing  = (a + b - (a - b))/2 = (sum_ab - sumDifference) / 2
       int repeated = (sum_ab + sumDifference) / 2;
       int missing = (sum_ab - sumDifference) / 2;


       return {repeated, missing};
   }
};


int main() {
   // Example: 1 is repeated, 3 is missing
   vector<vector<int>> grid = {
       {1, 2},
       {1, 4}
   };


   Solution sol;
   vector<int> result = sol.findMissingAndRepeatedValues(grid);


   cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;


   return 0;
}




