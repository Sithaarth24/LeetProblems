class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0;
        int curr = 0;
        int next = 0;
        int i;
        for(i = 2;i<=n;i++){
            next = min(prev+cost[i-2], curr+cost[i-1]);
            // cout<<prev<<" "<<curr<<" "<<next<<endl;
            prev = curr;
            curr = next;
        }
        return next;
    }
};