#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
string s;
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
     while(getline(cin,s)){
          if(s == ".") break; 
          vector<int>pi = kmp(s); 
          int n = s.length();
          cout << (n % (n - pi[n - 1]) != 0 ? 1 : n / (n - pi[n - 1])) << endl; 
     }
     return 0; 
} 
