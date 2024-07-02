#include <bits/stdc++.h>

using namespace std;

long long finalValue(long long x,long long y,int k) {
  if (x % y == 0) {
    x /= y;
  }

  for (int i = 0; i < k; ++i) {
     x++;
    if (y > 1 && x % y != 0) {
      break;
    }
  }
  return x;
}

int main() {
    vector<vector<long long>> dp={{1 ,3 ,1},{2, 3 ,1},{24, 5, 5},{16, 3 ,2},{2, 2 ,1},{1337 ,18, 1},{1, 2 ,144133},{12345678 ,3 ,10},{998244353 ,2 ,998244353},{998244353, 123456789 ,998244352},{998244354, 998241111 ,998244352},{998244355, 2 ,9982443},{1000000000 ,1000000000 ,1000000000}};
    for(auto x:dp){
    cout<<finalValue(x[0],x[1],x[2])<<endl;
    }
  return 0;
}
