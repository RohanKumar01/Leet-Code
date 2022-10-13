class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int>ans;
        sort(arr.begin(),arr.end());
        
        int i=0;
        while(i<arr.size())
        {
            int count=1;
            
            for(int j=i;j<arr.size()-1;j++)
            {
                if(arr[j]==arr[j+1])
                    count++;
                else
                    break;
            }
            ans.push_back(count);
            i=i+count;
        }
        
        sort(ans.begin(),ans.end());
        for(int k=0;k<ans.size()-1;k++)
        {
            if(ans[k]==ans[k+1])
                return false;
        }
        return true;
    }
};
