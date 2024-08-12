class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k1, vector<int>& nums1):pq(nums1.begin(),nums1.end()),k(k1) {
        while(pq.size() > k)
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