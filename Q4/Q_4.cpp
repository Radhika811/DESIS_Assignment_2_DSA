#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue <int> qu;
        vector <int> vis (n,0);
        vis[0]=1;
        for (int i=minJump;i<min(n,maxJump+1);i++){
            if (s[i]=='0') {
                vis[i]=1;
            }
        }
        int p1=minJump, p2=maxJump;
        for (int i=p1;i<=p2;i++) if (s[i]=='0') vis[i]=1;
        p1=1; p2=maxJump+1-minJump;
        for (int i=p1; i<=p2 ; i++) if (vis[i]==1) qu.push(i);
        cout<<qu.size()<<'j'<<endl;
        for (int i=maxJump+1;i<n;i++) {
            if (!qu.empty()) {
                if (s[i]=='0') vis[i]=1;
                if (qu.front()==i-maxJump) qu.pop();
            }
            if (vis[i+1-minJump]==1) qu.push(i+1-minJump);
        }
        if (vis[n-1]==1) return true;
        return false;


        
    }
};