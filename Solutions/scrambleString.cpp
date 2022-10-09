class Solution {
public:

bool solve(string s1, string s2 , unordered_map<string , bool> &mp){
    //base case
    if( s1.compare(s2) == 0 ) // if strings are same
        return true;
    
    if( s1.size() <= 1 )  
        return false;  
    
    // memoization step
    string key = s1 + ':' + s2;
    if( mp.find(key) != mp.end() )
        return mp[key];
    
    int n = s1.size();
    bool flag = false;
    
    for( int i=1 ; i<=n-1 ; i++ ){
        bool cond1 = solve( s1.substr(0,i) , s2.substr(n-i,i) , mp) == true  &&
                     solve( s1.substr(i,n-i) , s2.substr(0,n-i) , mp) == true;
         
        bool cond2 = solve( s1.substr(0,i) , s2.substr(0,i) , mp) == true  &&
                     solve( s1.substr(i,n-i) , s2.substr(i,n-i) , mp) == true;
            
            
        if( cond1 || cond2 ){
            flag = true;
            break;
        }
    }
    
    return mp[key] = flag;
}

bool isScramble(string s1, string s2) {
    if( s1.size() != s2.size() )
        return false;
    
    if( s1.empty() && s2.empty() )
        return true;
            
    // using map for memoization
    unordered_map<string , bool> mp;
    
    return solve(s1,s2,mp);
}
};
