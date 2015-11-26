// Binary Search: iteration


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            int mid2 = mid + 1;
            if(nums[mid] < nums[mid2])
                left = mid2;
            else
                right = mid;
        }
        return right;
    }
};
