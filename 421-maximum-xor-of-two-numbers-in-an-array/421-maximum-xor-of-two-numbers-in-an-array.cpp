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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie; // object of trie class
        
        for(int i : nums)trie.insert(i);
        
        
        int mx = 0;
        for(int i : nums){
            int ans = trie.findMax(i);
            mx = max(mx,ans);
        }
        
        return mx;
    }
};