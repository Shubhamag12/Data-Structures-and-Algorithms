#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>>dp;

int dfs(int x,int y,vector<vector<int>>mat){
    
    if(dp[x][y])
        return dp[x][y];
    int ans=1;
    vector<vector<int>> mov={{-1,0},{1,0},{0,1},{0,-1}};
    for(int i=0;i<4;i++){
        int X=x+mov[i][0];
        int Y=y+mov[i][1];
        if(X<0 || X>=N || Y<0 || Y>=M)
            continue;
        if(mat[X][Y]<=mat[x][y])
            continue;
        ans=max(ans,1+dfs(X,Y,mat));
    }
    dp[x][y]=ans;
    return ans;
}

int longestIncreasingPath(vector<vector<int>> mat){
    int n=mat.size();
    int m=mat[0].size();
    N=n;
    M=m;
    dp=vector<vector<int>>(n,vector<int>(m,0));
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res=max(res,dfs(i,j,mat));
        }
    }
    return res;


}




int main(){
    vector<vector<int>> mat={
        {18,1,12,16,5,18,14,14,6,4,9,4,4,5,3,9,9,12,18,2,19,4,5,14,16,6,15,8,9,0},
        {9,10,11,15,15,8,2,17,17,2,0,18,8,14,19,8,1,2,3,1,19,6,13,16,0,15,0,17,13,1},
        {13,11,15,6,4,8,3,8,19,0,7,4,3,2,15,10,2,9,18,7,10,2,0,17,5,4,13,1,10,4},
        {5,9,12,11,4,9,19,15,2,13,3,17,7,2,5,18,17,7,9,15,10,15,2,12,2,10,14,18,2,4},
        {14,6,18,5,18,10,18,5,9,13,7,15,11,6,18,4,12,17,18,15,1,4,15,13,19,11,11,1,13,7},
        {8,16,12,4,9,12,17,5,10,4,2,5,11,2,6,0,0,16,14,0,3,19,10,19,7,14,2,1,18,4},
        {17,3,3,5,0,16,13,3,4,4,15,1,14,11,12,9,8,3,13,15,17,18,11,2,15,3,3,19,1,12},
        {0,1,11,7,7,4,10,14,2,6,5,11,11,0,18,8,12,13,6,3,5,6,8,0,2,6,5,18,3,17},
        {13,16,18,8,19,9,19,0,18,16,16,5,0,2,16,9,4,7,11,13,8,16,7,4,10,17,0,0,19,18},
        {19,14,14,16,17,7,8,17,8,16,12,8,4,19,14,5,19,4,5,5,19,7,17,18,8,0,5,5,18,11},
        {18,8,6,16,13,0,13,8,18,17,14,14,9,10,16,0,3,15,0,9,6,9,2,8,6,13,4,4,12,5},
        {15,4,1,12,1,6,12,17,16,11,14,4,5,9,11,17,15,6,14,18,3,5,17,19,19,7,7,1,7,8},
        {14,16,19,11,5,6,0,0,13,2,8,10,8,10,13,2,19,5,6,15,15,4,3,6,3,16,18,18,18,5},
        {16,6,17,15,7,12,1,10,3,10,10,8,12,11,3,6,9,11,5,19,19,16,12,19,5,6,9,4,0,6},
        {2,11,16,12,16,9,18,10,18,0,6,17,1,14,4,6,8,18,18,14,2,6,1,16,2,9,17,8,5,1},
        {12,14,17,9,7,0,3,18,12,17,12,12,0,19,8,12,17,0,10,12,0,2,0,7,16,16,3,19,19,9},
        {5,5,2,19,19,4,17,0,2,3,5,15,10,1,6,10,1,19,14,17,9,1,3,10,13,9,17,8,11,17},
        {14,19,8,4,15,5,13,13,2,3,1,15,6,18,16,17,12,17,2,2,19,1,3,5,18,17,19,13,2,15},
        {5,3,0,15,9,9,6,16,7,18,17,13,8,3,14,3,11,14,6,12,1,18,16,19,1,0,19,0,16,13},
        {2,6,6,1,3,6,2,16,11,7,12,12,3,7,15,10,1,9,11,2,7,7,16,18,18,8,18,2,12,4},
        {10,16,10,13,13,19,4,19,1,2,14,14,0,7,12,7,14,9,12,5,11,7,12,3,9,2,0,0,16,3},
        {5,18,7,3,8,19,19,13,6,14,0,2,0,3,16,3,8,7,1,10,18,15,15,6,5,10,19,11,14,14},
        {3,19,16,4,9,4,7,5,8,10,15,19,18,12,4,8,4,19,10,1,8,0,15,18,4,11,2,6,2,12},
        {9,19,0,14,11,8,6,11,3,11,14,8,1,14,19,17,14,17,15,13,12,7,11,12,11,15,10,18,7,6},
        {17,2,7,18,14,3,4,13,17,7,8,4,4,13,9,11,14,13,18,16,2,16,0,4,14,4,15,6,12,7},
        {7,6,18,4,7,12,6,0,16,3,9,0,19,5,0,11,15,7,9,2,5,7,0,7,18,1,18,12,2,18},
        {19,6,15,14,0,18,10,13,16,19,18,15,0,3,15,14,18,0,10,1,3,11,6,10,18,15,12,0,17,15},
        {8,8,18,7,15,6,19,9,18,5,11,6,5,11,1,3,17,18,15,5,7,5,12,9,9,3,3,13,8,19},
        {12,17,10,7,2,13,15,11,15,1,6,15,3,15,12,1,11,12,11,6,7,18,18,11,8,14,7,4,8,3},
        {4,0,11,7,6,9,2,2,6,15,0,4,14,12,5,7,12,8,4,15,19,10,5,7,3,15,7,6,11,13},
        {12,10,6,9,11,12,11,4,3,0,18,0,6,4,6,7,5,10,17,12,7,11,17,9,2,16,2,5,5,3},
        {13,12,16,18,2,17,2,4,6,12,1,5,17,1,9,9,3,1,6,12,18,17,8,1,7,4,17,17,6,14},
        {2,11,9,11,7,15,14,12,17,4,17,2,11,15,16,14,9,2,8,18,13,1,17,19,15,16,11,2,11,10},
        {1,8,6,2,0,18,18,13,0,3,5,0,18,14,1,15,18,19,14,11,6,1,13,1,12,18,8,9,12,9},
        {19,14,5,1,17,3,17,14,13,7,5,8,4,18,16,12,16,9,1,13,8,17,15,12,11,19,16,7,15,3},
        {6,2,13,15,18,8,7,14,8,3,19,7,17,17,8,16,8,11,8,9,3,10,7,3,9,0,14,9,17,17},
        {16,6,2,12,3,3,6,17,16,16,14,13,0,3,16,5,3,6,16,8,0,7,13,0,15,17,3,0,3,9},
        {10,15,7,7,3,5,11,7,15,5,0,17,2,3,9,13,17,4,19,19,3,2,4,15,18,6,4,16,2,10},
        {17,1,13,12,12,5,5,6,5,16,15,2,19,11,0,6,6,15,9,6,18,7,13,3,1,4,16,16,18,12},
        {1,2,1,11,8,13,15,12,8,18,2,8,11,10,18,4,12,10,14,10,12,19,10,11,3,0,7,16,13,18},
        {10,15,0,14,6,4,4,3,4,9,17,19,13,16,2,16,15,0,3,14,2,7,6,19,10,2,0,0,13,14},
        {14,5,14,15,7,12,13,16,8,15,19,0,3,2,15,4,11,15,19,5,0,15,1,8,3,15,17,5,4,5},
        {4,5,11,7,3,16,19,12,6,15,6,15,12,4,3,14,0,4,1,18,18,18,7,12,0,18,10,2,9,7},
        {11,8,11,18,0,6,9,9,3,8,8,5,0,5,12,13,7,9,15,15,1,6,1,8,17,2,14,12,16,0},
        {13,0,18,0,3,10,8,16,9,2,3,14,15,6,19,16,9,15,13,4,0,7,19,4,18,1,1,1,16,0},
        {9,5,16,9,0,18,3,11,13,11,1,12,15,18,16,2,19,8,0,11,16,14,4,11,18,5,2,13,11,0},
        {17,13,9,9,12,13,17,6,0,18,5,19,7,2,12,2,3,4,15,5,1,9,5,8,15,14,8,7,18,19},
        {19,17,10,18,3,4,16,9,2,19,1,11,0,2,5,1,5,4,11,14,17,4,17,12,14,6,12,2,15,8},
        {12,3,10,9,2,17,0,19,12,16,14,19,3,9,0,9,13,4,14,8,17,10,3,12,2,12,13,19,19,17},
        {12,11,2,10,15,11,2,0,4,12,8,14,1,15,14,6,11,9,17,15,12,0,0,2,14,8,17,1,2,9},
        {10,8,7,0,6,19,18,5,6,9,7,17,0,0,15,18,4,13,10,13,3,15,2,1,12,4,9,14,3,4},
        {7,17,14,19,11,8,18,14,16,16,13,14,17,13,16,1,5,14,16,1,9,9,13,7,8,2,11,9,18,1},
        {18,13,2,14,18,2,13,5,9,16,19,11,19,8,5,16,12,10,2,3,0,12,8,13,13,16,2,5,3,13},
        {15,13,16,3,6,6,15,13,17,5,2,1,13,7,13,15,4,19,12,6,18,7,8,12,2,17,13,5,9,3},
        {16,4,17,11,3,6,0,5,4,16,15,19,11,3,6,0,3,3,6,0,8,9,18,12,10,11,9,13,19,14},
        {8,12,7,6,0,13,5,3,14,5,19,7,7,15,11,16,0,13,4,8,7,9,8,8,13,2,15,3,15,18},
        {10,12,11,3,19,19,15,13,8,13,14,12,12,17,0,17,17,12,1,7,4,9,18,1,8,10,3,19,13,9},
        {4,14,10,14,11,13,17,2,8,14,14,16,7,6,16,4,19,1,19,6,17,18,17,8,12,16,16,12,16,17},
        {0,17,14,3,2,5,3,1,4,1,13,8,18,5,18,1,2,2,4,15,12,14,10,1,16,8,2,10,8,1},
        {13,12,7,11,19,0,16,12,7,9,17,3,7,19,15,11,6,11,7,1,19,0,0,17,18,9,16,16,1,11},
        {4,14,1,2,15,19,0,5,7,15,7,14,4,3,2,3,19,19,7,8,15,3,0,7,2,10,16,18,10,2},
        {0,7,4,2,8,1,19,4,5,15,19,3,4,7,4,10,5,9,17,4,5,13,5,13,10,12,12,2,0,3},
        {13,16,1,15,13,17,19,17,0,4,2,16,16,16,17,6,5,17,13,8,5,10,17,18,1,11,18,11,13,4},
        {15,17,14,7,6,6,9,8,4,3,9,5,19,6,18,16,18,16,8,10,10,15,2,18,6,11,8,5,8,8},
        {5,8,12,8,16,15,4,15,9,2,2,3,19,1,3,8,17,9,0,0,5,14,0,16,10,4,16,11,6,7},
        {12,3,4,3,15,7,5,16,2,12,18,3,2,17,14,2,7,2,16,15,17,7,15,9,7,6,16,2,8,7},
        {10,9,1,1,14,8,0,15,9,14,15,13,18,0,10,12,0,9,7,0,10,5,16,9,7,2,18,6,16,7},
        {0,15,17,10,0,16,11,8,16,8,9,9,6,0,10,8,0,9,0,3,10,14,16,15,2,14,8,7,2,14},
        {6,0,14,2,2,16,13,10,15,6,14,17,12,16,4,18,3,12,3,16,16,14,2,8,15,18,9,17,11,7},
        {15,0,6,15,6,17,6,14,16,10,18,10,10,7,15,9,9,16,7,19,4,16,16,11,17,19,15,9,11,2}
    };
    cout << longestIncreasingPath(mat);
}