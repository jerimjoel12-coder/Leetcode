class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ls[256];
        for(int i=0;i<256;i++)
            ls[i]=-1;
        int st=0;
        int max=0;
        for(int i=0;s[i]!='\0';i++)
        {
            char c=s[i];
            if(ls[c]>=st)
                st=ls[c]+1;
            ls[c]=i;
            int pres=i-st+1;
            if(pres>max)
                max=pres;
        }
        return max;
    }
};