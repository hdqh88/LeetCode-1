// Time:  O(n)
// Space: O(1)


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        if(n == 0)
            return result;
        int start = 0, end = 0;
        string path;
        for(int i = 0; i < n; i++){
            if(start == end)
                path = to_string(nums[i]);
            if(i < n - 1 && nums[i+1] == nums[i] + 1)
                end++;
            else{ 
                if(end > start)
                    path.append("->" + to_string(nums[i]));
                result.push_back(path);
                start = end = min(i + 1, n - 1);
            }
        }
        return result;
    }
};



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) {
            return ranges;
        }

        int start = nums[0], end = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i] == end + 1) {
                end = nums[i];
            } else  {
                string range = to_string(start);
                if (start != end) {
                    range.append("->" + to_string(end));
                }
                ranges.emplace_back(range);
                if (i < nums.size()) {
                    start = end = nums[i];
                }
            }
        }

        return ranges;
    }
};
