class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i=0;i<n;i++){
            int j=i;
            while (j<nums.size()){
                res.push_back(nums[j]);
                j+=n;
            }
        }
        return res;
    }
};