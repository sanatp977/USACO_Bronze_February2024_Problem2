#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
   int n;
   ll m;
   cin>>n>>m;
   string s; cin>>s;
   vector<ll> arr(n);
   vector<bool>left(n);
   vector<bool>right(n);
   ll sum = 0;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       sum+=arr[i];
   }
   for(int i=0;i<n;i++){
       if(s[i]=='R'&&s[(i+1)%n]=='L'){
           left[i] = true;
           right[(i+1)%n] = true;
       }
   }
   for(int i=0;i<n;i++){
     ll cnt = 0;
     if(left[i]){
     int j = (i-1+n)%n;
     while(s[j]=='R'){
         cnt+=arr[j];
         j--;
         if(j<0){
             j+=n;
         }
     }
     sum-= min(cnt,m);
     }
     if(right[i]){
     int j = (i+1)%n;
     while(s[j]=='L'){
         cnt+=arr[j];
         j++;
         if(j>n-1){
             j-=n;
         }
     }
     sum-= min(cnt,m);
     }
   }
   cout<<sum;
}

