class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int N = num.size();
        int idx = -1;
        for(int i = N-2; i >= 0; i--){
            if(num[i] < num[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1) return -1;
        for(int i = N-1; i >= 0; i--){
            if(num[idx] < num[i]){
                swap(num[idx],num[i]);
                break;
            }
        }
        reverse(num.begin()+idx+1,num.end());
        long long Num = stoll(num);
        return Num > INT_MAX ? -1 : Num;
    }
};