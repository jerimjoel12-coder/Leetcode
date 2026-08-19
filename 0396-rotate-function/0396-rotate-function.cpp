class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum=0,F=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            F+=i*nums[i];
        }
        long long maxi=F;
        for(int i=1;i<nums.size();i++){
            F+=sum-nums.size()*nums[nums.size() - i];
            maxi=max(maxi,F);
        }
        return maxi;
    }
};