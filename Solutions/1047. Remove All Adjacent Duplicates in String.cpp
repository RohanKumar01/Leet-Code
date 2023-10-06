// First solution using String Operations

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        int n = s.size();
        string ans;
        
        for(int i=0;i<n;i++)
        {
            if(ans.back()==s[i])
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};


// Second Solution Using stack operations

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        int n = s.size();
        string ans;
        
        for(auto x: s)
        {
            if(!st.empty() && st.top() == x)
            {
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }
        
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};
