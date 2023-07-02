int Solution::solve(vector<int> &A, int B) {
    int cnt = 0;
    int n = A.size();
    int xr = 0;
    map<int, int> mp;
    mp[xr]++; (0, 1);
        
    for (int i = 0; i < n; i++) {
        xr ^= A[i];
        int x = xr ^ B;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}
