class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,N=s.length(),lt=0,maxfreq=0;
        vector<int> cnt(26,0);
        for(int rt=0;rt<N;rt++){
            char ch=s[rt];            
            maxfreq=max(maxfreq,++cnt[(ch-'A')]);
            while(rt-lt+1-maxfreq > k){
                cnt[(s[lt]-'A')]--;
                lt++;
            }
            ans=max(ans,rt-lt+1);
        }
        return ans;

    }
};