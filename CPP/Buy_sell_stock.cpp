class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0 ;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
	       // ValleyPeak 
};
