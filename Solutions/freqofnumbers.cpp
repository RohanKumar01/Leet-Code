//hacktober fest
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;//number of array elements
    cin>>n;
    int a[n];
    map<int,int>mp;//map for storing the frequency
    for(int i=0;i<n;i++){
        cin>>a[i];mp[a[i]]++;
    }
    for(auto i:mp){
       cout<<i.first<<" : "<<i.second<<endl;
    }
    return 0;
}