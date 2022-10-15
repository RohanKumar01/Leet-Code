class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.size();
        
        int i = n-1;
        
        while(i >= 0 && s[i] == ' ') --i;
        
        for(; (i >= 0) && (s[i] != ' '); --i){
            ++ans;
        }
        
        return ans;
    }
};
