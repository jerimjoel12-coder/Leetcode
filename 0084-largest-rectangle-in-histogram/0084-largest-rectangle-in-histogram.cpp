class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea=0;
        int N=heights.size();
        for(int i=0;i<N;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int oi=st.top();
                st.pop();
                //int width = st.empty() ? N : N - st.top() - 1;
                int curr=heights[oi]*(st.empty()?i:i-st.top()-1);
                maxarea=max(maxarea,curr);
            }
            st.push(i);
        }
        while(!st.empty()){
           int oi=st.top();
           st.pop();
            //int width =( st.empty() ? N : N - st.top() - 1);
            int curr=heights[oi]* (st.empty() ? N : N - st.top() - 1);
            maxarea=max(maxarea,curr);
        }
        return maxarea;
    }
};