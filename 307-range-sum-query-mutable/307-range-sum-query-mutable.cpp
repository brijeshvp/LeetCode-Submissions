class NumArray {
public:
    // segment tree
    vector<int> seg;
    int n;
    void build(int ind,int lo,int hi,vector<int> &nums){
        if(lo==hi){
            seg[ind] = nums[lo];
            return;
        }
        
        int mid = lo + (hi-lo)/2;
        
        build(2*ind+1,lo,mid,nums);
        build(2*ind+2,mid+1,hi,nums);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    int sum_query(int ind,int lo,int hi,int l,int r){
        if(l>hi || r<lo)return 0;
        
        if(lo>=l && hi<=r)return seg[ind];
        
        int mid = lo + (hi-lo)/2;
        int left = sum_query(2*ind+2,mid+1,hi,l,r);
        int right = sum_query(2*ind+1,lo,mid,l,r);
        
        return left+right;
    }
    
    void update_query(int ind,int lo,int hi,int i,int val){
        if(lo==hi){
            seg[ind] = val;
            return;
        }
        
        int mid = lo + (hi-lo)/2;
        if(i<=mid) update_query(2*ind+1,lo,mid,i,val);
        else update_query(2*ind+2,mid+1,hi,i,val);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];     
    }
    
    NumArray(vector<int>& nums) {
        // buid segement tree
        n = nums.size();
        seg.clear();
        seg.resize(4*n,0);
        
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update_query(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sum_query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */