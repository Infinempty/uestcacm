//#pragma GCC target("avx2")
//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);
class Solution {
public:
    int n,m;
    bool check_pos(vector<string> chessborad,int x,int y){
        bool l=0,r=0;
        for(int i=x;i<n;i++){
            if(chessborad[i][y]=='.')break;
            if(chessborad[i][y]=='X'){
                r=1;
                break;
            }
        }
        for(int i=x;~i;i--){
            if(chessborad[i][y]=='.')break;
            if(chessborad[i][y]=='X'){
                l=1;
                break;
            }
        }
        if(l&&r)return true;
        l=r=0;
        for(int i=y;i<m;i++){
            if(chessborad[x][i]=='.')break;
            if(chessborad[x][i]=='X'){
                r=1;
                break;
            }
        }
        for(int i=y;~i;i--){
            if(chessborad[x][i]=='.')break;
            if(chessborad[x][i]=='X'){
                l=1;
                break;
            }
        }
        if(l&&r)return true;
        l=r=0;
        for(int xx=x,yy=y;xx<n&&yy<m;xx++,yy++){
            if(chessborad[xx][yy]=='.')break;
            if(chessborad[xx][yy]=='X'){
                r=1;
                break;
            }
        }
        for(int xx=x,yy=y;xx>-1&&yy>-1;xx--,yy--){
            if(chessborad[xx][yy]=='.')break;
            if(chessborad[xx][yy]=='X'){
                l=1;
                break;
            }
        }
        if(l&&r)return true;
        l=r=0;
        for(int xx=x,yy=y;xx>-1&&yy<m;xx--,yy++){
            if(chessborad[xx][yy]=='.')break;
            if(chessborad[xx][yy]=='X'){
                r=1;
                break;
            }
        }
        for(int xx=x,yy=y;yy>-1&&xx<n;yy--,xx++){
            if(chessborad[xx][yy]=='.')break;
            if(chessborad[xx][yy]=='X'){
                l=1;
                break;
            }
        }
        if(l&&r)return true;
        return false;
    }
    int check(vector<string> chessborad,int x,int y){
        bool ok=1;
        chessborad[x][y]='X';
        while(ok){
            ok=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(chessborad[i][j]=='O'){
                        bool tmp=check_pos(chessborad,i,j);
                        if(tmp)ok=tmp;
                        if(tmp)chessborad[i][j]='X';
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt+=chessborad[i][j]=='X';
            }
        }
        return cnt;
    }
    int flipChess(vector<string>& chessboard) {
        n=chessboard.size();
        m=chessboard[0].size();
        int pre=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre+=chessboard[i][j]=='X';
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(chessboard[i][j]!='.')continue;
                ans=max(ans,check(chessboard,i,j)-pre-1);
            }
        }
        return ans;
    }
}s;
void mainwork(int T){
    vector<string> now={"..X",".O.","..."};
    printf("%d\n",s.flipChess(now));
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}