#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
string s;
int n;
int A[N + 1]; 
int B[N + 1]; 
vector<int>kmp(vector<int>&a){
     int n = a.size(); 
     vector<int>pin(n); 
     for(int i = 1, j = 0; i < n; i++){
          while(j > 0 && a[i] != a[j]) j = pin[j - 1];
          if(a[i] == a[j]) j++; 
          pin[i] = j; 
     }
     return pin; 
}
bool solve(){
     sort(A + 1, A + n + 1);
     sort(B + 1, B + n + 1); 
     vector<int>dif;
     for(int i = 1; i < n; i++){
          dif.push_back((-A[i] + A[i + 1])); 
     }
     dif.push_back(360000 - A[n] + A[1]); 
     dif.push_back(-1); 
     for(int i = 1; i < n; i++){
          dif.push_back((-B[i] + B[i + 1])); 
     }
     dif.push_back(360000 - B[n] + B[1]); 
     for(int i = 1; i < n; i++){
          dif.push_back((-B[i] + B[i + 1])); 
     }
     dif.push_back(360000 - B[n] + B[1]); 
     vector<int>pdif = kmp(dif); 
     for(int i = n; i < dif.size(); i++){
            if(pdif[i] == n){
                 return 1;
            }
     }
     return 0;
}
signed main(){
     cin >> n;
     for(int i = 1; i <= n; i++){
          cin >> A[i]; 
     }
     for(int i = 1; i <= n; i++){
         cin >> B[i];
     }
     bool ans = solve(); 
     if(ans){
           cout << "possible\n";
           return 0;
     }
     cout << "impossible\n"; 
     return 0; 
} 
