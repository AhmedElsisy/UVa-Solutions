#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

int getCnt(int x){
    int l = 0 , r = 1e6 , ret = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if((1ll * mid * (mid - 1)) / 2 <= x)ret = mid , l = mid + 1;
        else r = mid - 1;
    }
    return ret;
}


void solve(int one , int zero , vector<int> &a){
    if(1ll * a[1] + a[2] != 1ll * one * zero){
        return;
    }
    vector<int> info(zero , 0);
    int rem = a[1];
    for(int &x : info)
        x = min(rem , one) , rem -= min(rem , one);
    info.pb(0);


    string res = "";
    int cnt1 = one - info[0];
    while(cnt1--)
        res.pb('1');

    for(int i = 0 ; i + 1 < (int)info.size() ; ++i){
        cnt1 = info[i] - info[i + 1];
        res.pb('0');
        while(cnt1--)
            res.pb('1');
    }
    vector<int> copiedA(4 , 0);
    for(int i = 0 ; i <(int)res.size() ; ++i){
        if(res[i] == '0')zero-- , copiedA[0] += zero , copiedA[1] += one;
        else one-- , copiedA[3] += one , copiedA[2] += zero;
    }
    if(copiedA != a)return;
    cout << res << "\n";
    exit(0);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    vector<int> a(4);
    for(int &x : a)
        cin >> x;

    vector<vector<int> > call(2 , vector<int>());
    if(!a[0])call[0].pb(0);
    if(!a[3])call[1].pb(0);

    int zero = getCnt(a[0]);
    int one = getCnt(a[3]);

    call[0].pb(zero);
    call[1].pb(one);

    for(int x : call[0]){
        for(int y : call[1]){
            if(!x && !y)continue;
            solve(y , x , a);
        }
    }

    cout << "Impossible\n";
}
