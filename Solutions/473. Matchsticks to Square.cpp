class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
         int n=matchsticks.size();
         int s=(1<<n);
         vector<int>dp(s,-1);
         dp[0]=0;
         int sum=0;
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        if(sum%4!=0){
            return 0;
        }
        int p=sum/4;
         for(int mask=0;mask<s;mask++){
             if(dp[mask]==-1){
                 continue;
             }
             for(int i=0;i<n;i++){
                 if(!(mask&(1<<i)) && dp[mask]+matchsticks[i]<=p){
                     dp[(mask)|(1<<i)]=(dp[mask]+matchsticks[i])%p;
                 }
             }
         }
        return dp[s-1]==0;
    }
};