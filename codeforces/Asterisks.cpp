#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926536
#define ll long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main(){
fastio
 
int n;
cin >> n;
for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        cout<<"*"<<" ";
    }
    cout<<endl;
}
}