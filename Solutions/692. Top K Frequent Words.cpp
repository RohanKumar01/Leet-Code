class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp; 
        for(string word : words){
            mp[word]++;
        }
        vector<string> final; 
        vector<pair<int,string>> res; 
        for(auto it = mp.begin(); it!=mp.end(); it++){
            res.push_back(make_pair(it->second,it->first));
        }
        // if(res[0].first==res[res.size()-1].first){
        //     for(int i = 0; i<k; i++){
        //         final.push_back(res[i].second); 
        //     }
        //     return final; 
        // }
        sort(res.begin(),res.end()); 
        
        // for(auto ele: res){
        //     cout<<ele.second<<"-"<<ele.first<<" "; 
        // }
        map<int,vector<string>> fin; 
        for(auto i : res){
            fin[i.first].push_back(i.second); 
        }
        for(auto it = fin.begin(); it!=fin.end(); it++){
            sort(it->second.begin(),it->second.end()); 
        }
        int i = 0; 
        for(auto it = fin.rbegin(); it!=fin.rend(); it++){
            for(auto c: it->second){
                if(i<k){
                    final.push_back(c); 
                }
                i++; 
            } 
        }
        
        return final; 
    }
};