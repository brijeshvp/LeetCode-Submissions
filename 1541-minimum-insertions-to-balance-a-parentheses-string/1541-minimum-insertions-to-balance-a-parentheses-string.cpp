class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();
        
        int moves = 0;
        for(int i=0;i<n;){
            if(s[i]=='('){st.push('('); i++; continue;}
            int ctClosing = 0;
            while(s[i]==')'){
                ctClosing++;
                i++;
            }
            if(ctClosing!=0){
                if(ctClosing%2!=0){
                    moves++;
                    ctClosing++;
                    
                }
                int reqOpening = ctClosing/2;
                int availableOpening = min((int)st.size(),reqOpening);
                moves+= reqOpening - availableOpening;
                
                while(availableOpening--){
                    st.pop();
                }
            }
        }
        // cout<<"req "<<reqOpening<<" "<<" avail "<<availableOpening<<" ";
        // cout<<st.size();
        moves+= 2*st.size();
        return moves;
    }
};