#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vpii vector<pair<ll, ll>>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define alice cout << "ALICE" << endl;
#define bob cout << "BOB" << endl;
#define fr(i,n) for(ll i= 0; i < (n); i++) 
#define each(a,x) for(auto &a: x)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define read(a) each(x, a) { cin>>x; }
#define print(x) for(const auto &e: (x)){ cout<<e<<" "; } cout<<endl
#define print_pair(x) for(const auto &e: (x)) { cout<<e.ff<<" "<<e.ss<<endl; }
#define print_map(x) for(const auto &e: (x)) { cout<<e.ff<<" "<<e.ss<<endl; }
#define print_2d_vector(x) for(const auto &e: (x)) { for(const auto &f: e) { cout<<f<<" "; } cout<<endl; }
#define print_set(x) for(const auto &e: (x)) { cout<<e<<" "; } cout<<endl
#define print_map_pair(x) for(const auto &e: (x)) { cout<<e.ff.ff<<" "<<e.ff.ss<<" "<<e.ss<<endl; }
#define print_map_vector(x) for(const auto &e: (x)) { cout<<e.ff<<" "<<endl; prll(e.ss); }
#define print_vector_pair(x) for(const auto &e: (x)) { cout<<e.ff<<" "<<e.ss<<endl; }


int main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    ll t, n, a;
    cin >> t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin >> a;
        }
        if(n==1) cout << 1 << endl;
        else {
            for(int i=0; i<n; i++) cout << 2 << " ";
            cout << endl;
        }
    }
    

return 0;
}