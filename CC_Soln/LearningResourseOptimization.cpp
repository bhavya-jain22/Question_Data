
// https://www.codechef.com/problems/LEREO

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>


vi courseSt, courseEnd;
vector<ll> bundlePrice, bundleValue;
vector<vector<ll>> dpBundle, dpCourse;
vector<pair<int, int>> courses;
void solve();
long long solveBundle(int bundle, int budget);
long long solveCourse(int bundle, int course, int budget);

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}


void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    bundlePrice.assign(m+1, 0LL);
    bundleValue.assign(m+1, 0);
    courseSt.assign(m+1, -1);
    courseEnd.assign(m+1, -1);
    vector<vector<pair<int, int>>> bundles(m+1); //{price, val}
    
    for(int i=0; i<n; i++) {
        int b, price, val;
        cin >> b >> price >> val;
        bundles[b].push_back({price, val});
        bundleValue[b] += val;
    }
    for(int i=1; i<=m; i++) cin >> bundlePrice[i];
    
    
    for(int i=1; i<=m; i++) {
        courseSt[i] = courses.size();
        for(auto& x: bundles[i]) {
            courses.push_back(x);
        }
        courseEnd[i] = courses.size();
    }
    
    dpBundle.assign(m+2, vector<ll>(p+1, -1));
    dpCourse.assign(n+1, vector<ll>(p+1, -1));
    
    cout << solveBundle(m, p) << endl;
}

long long solveBundle (int bundle, int budget) {
    if(budget == 0 || bundle == 0) return 0;
    
    auto& best = dpBundle[bundle][budget];
    if(best != -1) return best;
    
    // take courses of that bundle
    best = solveCourse(bundle, courseEnd[bundle], budget);
    
    // take whole bundle
    if(bundlePrice[bundle] <= budget) best = max(best, bundleValue[bundle] + solveBundle(bundle-1, budget-bundlePrice[bundle]) );
    
    return best;
}

long long solveCourse(int bundle, int course, int budget) {
    if(course==courseSt[bundle]) return solveBundle(bundle-1, budget);
    auto& best = dpCourse[course][budget];
    auto [price, val] = courses[course-1];
    if(best != -1) return best;
    
    // skip the course
    best = solveCourse(bundle, course-1, budget);
    
    // take the course
    if(price<=budget) best = max(best, val + solveCourse(bundle, course-1, budget-price) );
    return best;
}