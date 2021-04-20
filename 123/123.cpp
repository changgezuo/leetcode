class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        vector<int>gobal(3);
        vector<int>part(3);
        for(int i=0;i<prices.size()-1;++i){
            int dif=prices[i+1]-prices[i];
            for(int j=2;j>=1;j--){
                part[j]=max(gobal[j-1]+(dif>0?dif:0),part[j]+dif);
                gobal[j]=max(part[j],gobal[j]);
            }
        }
        return gobal[2];
    }
};