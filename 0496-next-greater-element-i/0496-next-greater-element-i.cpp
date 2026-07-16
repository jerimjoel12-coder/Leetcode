class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next;
        stack<int> s;
        int N=nums2.size();
        for(int i=N-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            next[nums2[i]]=s.empty()?-1:s.top();
            s.push(nums2[i]);
        }
        vector<int> res;
        for(int num:nums1){
            res.push_back(next[num]);
        }
        return res;
    }
};