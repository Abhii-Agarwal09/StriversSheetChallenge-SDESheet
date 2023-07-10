//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i]});
        }
        int cnt = 1;
        sort(meetings.begin(), meetings.end());
        int s = meetings[0].first;
        int e = meetings[0].second;
        // cout << "start " << s << " end " << e << endl;
        for (int i = 1; i < n; i++) {
            int ns = meetings[i].first;
            int ne = meetings[i].second;
            // cout << "ns " << ns << " ne " << ne << endl;  
            if (ne < e) {
                s = ns;
                e = ne;
            } else if (ns > e) {
                cnt++;
                s = ns;
                e = ne;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends