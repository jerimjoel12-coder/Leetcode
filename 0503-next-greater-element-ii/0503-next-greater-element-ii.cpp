class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N=nums.size();
        vector<int> ans(N,-1);
        stack<int> s;
        for(int i=0;i<2*N;i++){
            int num=nums[i%N];
            while(!s.empty() && nums[s.top()]< num){
                ans[s.top()]=num;
                s.pop();
            }
            if(i<N) s.push(i);
        }
        return ans;
    }
};