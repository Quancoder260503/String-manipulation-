#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
char s[N + 1];
vector<int>kmp(char s[]){
     int n = strlen(s); 
     vector<int>pin(n); 
     for(int i = 1, j = 0; i < n; i++){
          while(j > 0 && s[i] != s[j]) j = pin[j - 1];
          if(s[i] == s[j]) j++; 
          pin[i] = j; 
     }
     return pin; 
}
signed main(){
     int len = 0; 
     while(scanf("%c",&s[len]) == 1){
         len++;
     }
     s[len] = '\0'; 
     int ans = 0;
     for(int i = 0; i < len; i++){
           vector<int>pi = kmp(s + i);
           ans = max(ans, *max_element(pi.begin(),pi.end())); 
     }
     cout << ans << endl; 
     return 0; 
} 
