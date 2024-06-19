#include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using pl = std::pair<ll, ll>;
    using vl = std::vector<long long>;
    using vp = std::vector<pl>;
    using vs = std::vector<string>;
    using vvl = std::vector<vl>;
    using sl = std::set<ll>;
    using ml = std::map<ll, ll>;
    using MAXHeap = std::priority_queue<ll>;
    using MINHeap = std::priority_queue<ll, vector<ll>, greater<ll>>;
     
    ll mod = 1e9 + 7;
    ll MAX = 1e9;
     
    #define rep(i,a,b) for(ll i = a;i < b;i++)
    #define rev(i,a,b) for(ll i = a;i >= b;i--)
    #define pb push_back
    #define po pop_back
    #define mp make_pair
    #define eb emplace_back
    #define ub upper_bound
    #define lb lower_bound
    #define F first
    #define S second
     
    #define mset(m, v) memset(m, v, sizeof(m))
    #define gcd(a, b) __gcd(a, b)
    #define lcm(a, b) ((a * b) / gcd(a, b))
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
     
    #define vin(v) rep(i, 0, v.size()) cin >> v[i]
    #define vout(v) rep(i, 0, v.size()) cout << v[i] << " "; cout << endl;
    #define all(o) (o).begin(), (o).end()
    #define sum(v) accumulate(all(v), 0LL)
    #define ass(v,x)  iota(all(v), x)
     
    #define asort(o) sort((o).begin(), (o).end())
    #define dsort(o) sort((o).rbegin(), (o).rend())
    #define ub_index(v, x) (ub(all(v), x) - v.begin())
    #define lb_index(v, x) (lb(all(v), x) - v.begin())
    
    void build(int v,string&t,vector<vector<int>>&seg,int tl,int tr){
        if(tl==tr){
            seg[v][t[tl]-'a']++;
        }else{
            int tm=(tl+tr)/2;
            build(2*v,t,seg,tl,tm);
            build(2*v+1,t,seg,tm+1,tr);
            for(int i=0;i<26;i++){
                seg[v][i]=seg[2*v][i]+seg[2*v+1][i];
            }
        }
    }
    vector<int> distinct(int v,vector<vector<int>>&seg,int tl,int tr,int l,int r){
        if(l>r) return vector<int>(26,0);
        if(l==tl && r==tr){
            return seg[v];
        }
        int tm=(tl+tr)/2;
        vector<int> v1=distinct(2*v,seg,tl,tm,l,min(tm,r));
        vector<int> v2=distinct(2*v+1,seg,tm+1,tr,max(tm+1,l),r);
        vector<int> v3(26,0);
        for(int i=0;i<26;i++){
            v3[i]=v1[i]+v2[i];
        }
        return v3;
    }
    void update(int v, string &t, vector<vector<int>> &seg, int tl, int tr, int i, char x) {
    if (tl == tr) {
        seg[v][t[i] - 'a']--;
        t[i] = x;
        seg[v][x - 'a']++;
    } else {
        int tm = (tl + tr) / 2;
        if (i <= tm) {
            update(2 * v, t, seg, tl, tm, i, x);
        } else {
            update(2 * v + 1, t, seg, tm + 1, tr, i, x);
        }
        for (int j = 0; j < 26; j++) {
            seg[v][j] = seg[2 * v][j] + seg[2 * v + 1][j];
        }
    }
}
    int main() {
       string t="abacaba";
       cin>>t;
       int n=t.length();
       vector<vector<int>> seg(4*n,vector<int>(26,0));
       build(1,t,seg,0,n-1);
       int q;
       cin>>q;
       vector<int> v1;
       for(int j=0;j<q;j++){
        int x;
        cin>>x;
        if(x==1){
            int index;
            char z;
            cin>>index>>z;
            update(1,t,seg,0,n-1,index-1,z);
        }else{
            int l,r;
            cin>>l>>r;
            vector<int> v=distinct(1,seg,0,n-1,l-1,r-1);
            int count=0;
            for(int i=0;i<26;i++) if(v[i]>0) count++;
            v1.push_back(count);
        }
       }
       for(int&x:v1) cout<<x<<endl;
    return 0;
}


