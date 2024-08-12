class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k1, vector<int>& nums1) {
        k = k1;
        for(auto& i : nums1)
            pq.push(i);
        while(!pq.empty() && pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(k > pq.size()) return -1;
        if(pq.size() == k) return pq.top();
        pq.pop();
        return pq.top();
    }
};