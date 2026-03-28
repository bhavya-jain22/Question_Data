#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int>A(n+1), pos(n+1), l(n+2), r(n+2);
	    for(int i=1; i<=n;i++){
	        cin>>A[i];
	        pos[A[i]]=i;
	    }
	    
	    for(int i=0; i<n+2; i++){
	        l[i]= i-1;
	        r[i]=i+1;
	    }
	    
	    long long ans =0;
	    
	    for (int v = 1; v <= n; v++) {
	        int i = pos[v];
	        int l1 = l[i];
	        int r1 = r[i];
	        int l2 = (l1 > 0) ? l[l1] : 0;
	        int r2 = (r1 <= n) ? r[r1] : n + 1;
	        
	        if (l1 > 0) {
	            ans += (long long)v * (l1 - l2) * (r1 - i);}
	            if (r1 <= n) ans += (long long)v * (i - l1) * (r2 - r1);
	            r[l1] = r1;
	            l[r1] = l1;
	        
	    }
	    
	    cout<<ans<<endl;
	}

}
