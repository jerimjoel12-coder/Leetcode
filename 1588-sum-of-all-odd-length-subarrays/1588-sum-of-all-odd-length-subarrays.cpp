class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for (int i=0;i<n;i++) {
            int totsub=(i+1)*(n-i);
            int oddsub=(totsub+1)/2;
            ans+=arr[i]*oddsub;
        }
        return ans;
    }
};