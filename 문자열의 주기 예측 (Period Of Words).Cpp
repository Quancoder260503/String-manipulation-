#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
string s;
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
     cin >> n;
     cin >> s; 
     vector<int>pi = kmp(s); 
     long long ans = 0;
     for(int i = 0; i < pi.size(); i++){
           if(pi[i] == 0) continue; 
           if(pi[pi[i] - 1]) pi[i] = pi[pi[i] - 1];
           ans += i + 1 - pi[i]; 
     }
     cout << ans << endl;
     return 0; 
} 
