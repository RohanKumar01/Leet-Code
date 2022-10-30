vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
		int n=intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(ans[ans.size()-1][1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            }
        }
        return ans;
    }