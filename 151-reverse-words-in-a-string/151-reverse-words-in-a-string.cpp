class Solution {
public:
    string reverseWords(string s) {
        // hello world
        // reversed = “world hello”;
        // helper = “world”

        // step-1 -> reverse string word by word
        string reversed="", helper="";
        for(int i=0;i<s.size();++i){
            if(s[i]!=' '){
                helper+=s[i];
            }
            else{
                if(reversed=="")reversed = helper + reversed;
                else reversed = helper + " " + reversed;
                helper = "";
            }
        }
        if(reversed=="")reversed = helper + reversed;
        else reversed = helper + " " + reversed;
        helper = "";

        // reversed = “  world     hello   ”
        // step-2 -> remove extra whitespaces(if any)
        bool isSpace = true;
        string word = "";
        string reversed_without_whitespaces = "";
        for(int i=0;i<reversed.size();++i){
            if(reversed[i]!=' '){
                reversed_without_whitespaces+=reversed[i];
                isSpace = false;
            }
            else{
                if(!isSpace)reversed_without_whitespaces+=' ';
                isSpace = true;
            }
        }
        return reversed_without_whitespaces;
    }
};