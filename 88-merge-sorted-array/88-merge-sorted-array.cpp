class Solution {
public:
      // INPLACE
    // ind ptr -> at last of num1(m+n-1) to put largest elts there
    // i = m-1(actual last elt of num1) and j = n-1(last elt of num2)
    // compare num1 and num2 -> place larger elts at ind(elt)
     void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
         int ind = m+n-1;
         int i=m-1,j=n-1;
         
         while(i>=0 && j>=0){
             if(num1[i]>num2[j]){
                 num1[ind] = num1[i];
                 i--;
                 ind--;
             }
             else if(num2[j]>=num1[i]){
                 num1[ind] = num2[j];
                 j--;
                 ind--;
             }
         }
         
         // NO NEED
         // while(i>=0){
         //     num1[ind] = num1[i];
         //     i--;
         //     ind--;
         // }
         
         while(j>=0){
             num1[ind] = num2[j];
             j--;
             ind--;
         }
     }
};