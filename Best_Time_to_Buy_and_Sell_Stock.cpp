class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[0],d=0;
        for(int i=0;i<prices.size();i++){
           d=max(d,prices[i]-m);
           m=min(m,prices[i]);
        }
        return d;
        
    }
};
