#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
string s,a,b;
int n;
vector<int>kmp(string &s){
     int n = s.length(); 
     vector<int>pin(n); 
     for(int i = 1, j = 0; i < n; i++){
          while(j > 0 && s[i] != s[j]) j = pin[j - 1];
          if(s[i] == s[j]) j++; 
          pin[i] = j; 
     }
     return pin; 
}
signed main(){
     cin >> a; 
     cin >> b; 
     s = a + "?" + b + b; 
     vector<int>pi = kmp(s);
     long long ans = 0;
     for(int i = a.length(); i + 1 < s.length(); i++){
            if(pi[i] == a.length()) ans += 1; 
     }
     cout << ans << endl; 
     return 0; 
} 
