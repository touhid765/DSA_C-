class Solution {
public:
// isValid function to check if it's possible to paint within maxAllowedTime
bool isValid(vector<int>& arr, int painters, int maxAllowedTime)
{
       int requiredPainters = 1;
       int currentTime = 0;
       for (int i = 0; i < arr.size(); i++) {
           if (arr[i] > maxAllowedTime) {
               return false; // One board exceeds allowed time
           }
           if (currentTime + arr[i] <= maxAllowedTime) {
               currentTime += arr[i];
           } else {
               requiredPainters++;
               currentTime = arr[i];
           }
       }
       return (requiredPainters <= painters);
}


int minTime(vector<int>& arr, int k) {
       int n = arr.size();
       int maxVal = arr[0];
       int totalSum = arr[0];


       for (int i = 1; i < n; i++) {
           maxVal = max(maxVal, arr[i]);
           totalSum += arr[i];
       }
       int low = maxVal;
       int high = totalSum;
       int result = -1;
       while (low <= high) {
           int mid = low + (high - low) / 2;
           if (isValid(arr, k, mid)) {
               result = mid;
               high = mid - 1;
           } else {
               low = mid + 1;
           }
       }
       return result;
   }
};

