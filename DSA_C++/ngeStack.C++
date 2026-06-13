class solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i=nums.size()-1; i>=0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
        if (s.empty()) {
            m[nums[i]] = -1;
        } else {
            m[nums[i]] = s.top();
        }
        vector<int>ans;
        for (int num : nums) {
            ans.push_back(m[num]);
        }
        return ans;
    }