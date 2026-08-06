class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n<101){
            int dig=n;
            int prod=1;

            while(dig>0){
                prod*=dig%10;
                dig/=10;
            }
            if(prod%t==0){
                return n;
            }
            n++;
        }
        return n;
    }
};