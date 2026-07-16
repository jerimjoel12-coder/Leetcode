class Solution {
public:
    string winningPlayer(int x, int y) {
    int chance=min(x,y/4);
    if(chance%2==0){
        return "Bob";
    }
    return"Alice";
    }
};