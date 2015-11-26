class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> result;
        int pre = lower - 1;
        for(int i = 0; i <= n; i++){
            int after = i == n ? upper + 1 : nums[i];
            if(after == pre + 2)
                result.push_back(to_string(pre + 1));
            else if(after > pre + 2)
                result.push_back(to_string(pre+1) + "->" + to_string(after-1));
            pre = after;
        }
        return result;
    }
};
