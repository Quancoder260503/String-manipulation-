#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
string a,b;
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
     getline(cin,a);
     getline(cin,b); 
     string s = b + '?' + a;
     vector<int>pia = kmp(s);
     int n = b.length();
     int ans = 0; 
     vector<int>res;
     for(int i = n; i < pia.size(); i++){ 
           if(pia[i] == n){
                res.push_back(i - 2 * n + 1); 
                //printf("%d ",i - 2 * n + 1); 
           }
     }
     cout << res.size() << endl; 
     for(int i = 0; i < res.size(); i++){
          cout << res[i] << ' ';
     }
     return 0; 
} 
