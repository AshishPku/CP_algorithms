#include <bits/stdc++.h>
using namespace std;
int func(int i,int&n,int&l,int&r,vector<int>&nums,vector<int>&dp){
    if(i<n){
        if(dp[i]!=-1) return dp[i];
        int sum=0,ans=0;
        int j=i;
        bool flag=true;
        while(j<n && sum<=r){
            sum+=nums[j];
            if(sum>=l && sum<=r){
                flag=false;
                return 1+func(j+1,n,l,r,nums,dp);
            }
            j++;
        }
        if(flag) ans=max(ans,func(i+1,n,l,r,nums,dp));
        return dp[i]=ans;
    }else{
        return 0;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> nums(n);
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<func(0,n,l,r,nums,dp)<<endl;
    }
    return 0;
}