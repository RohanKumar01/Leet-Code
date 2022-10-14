#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int sum,msum;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            sum=a[i];
            msum=sum;
        }
        else
        {
            sum=max(sum+a[i],a[i]);
            msum=max(sum,msum);
        }
    }
    cout<<msum<<endl;
  return 0;
}