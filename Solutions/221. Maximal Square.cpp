class Solution {
public:
    bool safe(int x,int y,vector<vector<char>>& mat){
        if(x<0||y<0||x>=mat.size()||y>=mat[0].size()||mat[x][y]=='0'){
            return 0;
        }
        return 1;
    }
    int min3(int x,int y,int z){
        return min(x,min(y,z));
    }
    int rec(int x,int y,vector<vector<char>>& mat,vector<vector<int>>&dp){
        if(!safe(x,y,mat)){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int a=1+rec(x,y+1,mat,dp);
        int b=1+rec(x+1,y,mat,dp);
        int c=1+rec(x+1,y+1,mat,dp);
        return dp[x][y]=min3(a,b,c);
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ma=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ma=max(ma,rec(i,j,mat,dp));
            }
        }
        return ma*ma;
    }
};