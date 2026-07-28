class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> ans;
       set<vector<int>> unique;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i-1]==nums[i]) continue;
        for(int j=i+1;j<nums.size();j++){
            long long sum=nums[i]+nums[j];
            int l=j+1;
            int r=nums.size()-1;
            long long newtarget=(long long)target-(long long)sum;
            while(l<r){
                if(nums[l]+nums[r]<newtarget) l++;
                else if(nums[l]+nums[r]>newtarget) r--;
                else if(nums[l]+nums[r]==newtarget){
                    vector<int> temp={nums[i],nums[j],nums[l],nums[r]};
                    sort(temp.begin(),temp.end());
                    unique.insert(temp);
                    l++;
                    r--;
                }
            }
        }
       }
       ans.assign(unique.begin(),unique.end());
       return ans;
    }
};