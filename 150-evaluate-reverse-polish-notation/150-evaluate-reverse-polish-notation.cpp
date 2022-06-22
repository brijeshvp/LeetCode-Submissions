class Solution {
public:
    bool isOperator(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/")return true;
        
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        
        for(int i=0;i<n;++i){
            if(isOperator(tokens[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if(tokens[i]=="+")st.push(b+a);
                else if(tokens[i]=="-")st.push(b-a);
                else if(tokens[i]=="*")st.push(b*a);
                else if(tokens[i]=="/")st.push(b/a);
            }
            else{
                int operand = stoi(tokens[i]);
                st.push(operand);
            }
        }
        return st.top();
    }
};