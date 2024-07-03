#include <bits/stdc++.h>
using namespace std;
void func(long long n){
    if(n%2==0){
        int cnt=0;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        if(cnt>0) cout<<2<<"^"<<cnt<<" ";
    }
    for(long long d=3;d*d<=n;d+=2){
        int cnt=0;
        while(n%d==0){
            cnt++;
            n/=d;
        }
        if(cnt>0) cout<<d<<"^"<<cnt<<" ";
    }
    if(n>1) cout<<n<<"^1"<<endl;
}
int main(){
    long long n;
    while(1){
        cin>>n;
        if(n==0) return 0;
        else{
            func(n);
        }
    }
    return 0;
}