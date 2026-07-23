class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2){
            return nums;
        }
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};