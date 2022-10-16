#include<bits/stdc++.h>
using namespace std;

class MyCalendarThree {
public:
    map<int,int> mmap;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        mmap[start]++,mmap[end]--;
        int ans=0,curr=0;
        for(auto i:mmap)
            curr+=i.second,ans=max(ans,curr);
        return ans;
    }
};