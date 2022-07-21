class Node{
public:
    Node* links[2];
    
    bool containsKey(bool bit){
        return links[bit]!=NULL;
    }
    
    void insertKey(bool bit,Node *node){
        links[bit] = node;
    }
    
    Node* getNext(bool bit){
        return links[bit];
    }
};

class Trie{
private:
    Node *root;
public:
    // constructor to initialize trie -> to initialize root of trie
    Trie(){
        root = new Node();
    }
    
    // O(32)
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;--i){
            bool ithBit = (num&(1<<i))!=0;
//             bool ithBit = (num>>i)&1;
            if(!node->containsKey(ithBit)){
                node->insertKey(ithBit,new Node());
            }
            node = node->getNext(ithBit);
        }
    }
    
    // O(32)
    int findMax(int x){
        Node *node = root;
        
        int mx = 0;
        for(int i=31;i>=0;--i){
            bool ithBit = (x&(1<<i))!=0;    
//             bool ithBit = (x>>i)&1;
            if(node->containsKey(1-ithBit)){
                mx = mx | (1<<i);
                node = node->getNext(1-ithBit);
            }
            else{
                node = node->getNext(ithBit);
            }
        }
        return mx;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        
        vector<pair<int,pair<int,int>>> offlineQueries;
        int q = queries.size();
        for(int i=0;i<q;++i){
            int xi = queries[i][0];
            int mi = queries[i][1];
            
            offlineQueries.push_back({mi,{xi,i}});
        }
        
        sort(offlineQueries.begin(),offlineQueries.end());
        
        Trie trie; // object of trie class
        vector<int> ans(q);
        int arrIndex = 0;
        int n = nums.size();
        for(int i=0;i<q;++i){
            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int queryIndex = offlineQueries[i].second.second;
            
            
            while(arrIndex<n && nums[arrIndex]<=mi){
                trie.insert(nums[arrIndex]);
                arrIndex++;
            }
            if(arrIndex==0)ans[queryIndex] = -1;
            else ans[queryIndex] = trie.findMax(xi);
        }
        return ans;
    }
};