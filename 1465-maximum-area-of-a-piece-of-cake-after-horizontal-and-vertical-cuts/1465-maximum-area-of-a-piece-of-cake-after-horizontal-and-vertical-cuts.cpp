
class Solution {
public:
    #define MOD 1000000007  
    
    int maxArea(int h, int w, vector<int>& ho, vector<int>& v) {
//         int left = 0, top = 0;
//         sort(ho.begin(),ho.end());
//         sort(v.begin(),v.end());
        
//         long long mxArea = 0;
//         long long vertDist;
//         for(int i=0;i<v.size();++i){
//             vertDist = abs(v[i]-left);
//             long long horDist;
//             for(int j=0;j<ho.size();++j){
//                 horDist = abs(ho[j]-top);
//                 mxArea = max(mxArea,(vertDist*horDist)%MOD);
//                 top = ho[j];
//             }
//             horDist = abs(h-top);
//             mxArea = max(mxArea,(vertDist*horDist)%MOD);
            
//             left = v[i];
//         }
        
//         vertDist = abs(w-left);
//         long long horDist;
//         top = 0;
//         for(int j=0;j<ho.size();++j){
//             horDist = abs(ho[j]-top);
//             mxArea = max(mxArea,(vertDist*horDist)%MOD);
//             top = ho[j];
//         }
//         horDist = abs(h-top);
//         mxArea = max(mxArea,(vertDist*horDist)%MOD);
        
//         return mxArea;
        
        
        int left = 0, top = 0;
        sort(ho.begin(),ho.end());
        sort(v.begin(),v.end());
        
        // long long mxArea = 0;
        int mxHeight=0, mxWidth=0;
        for(int i=0;i<v.size();++i){
            mxWidth = max(mxWidth,abs(left-v[i]));
            left = v[i];
        }
        mxWidth = max(mxWidth,abs(left-w));
        
        for(int i=0;i<ho.size();++i){
            mxHeight = max(mxHeight,abs(top-ho[i]));
            top = ho[i];
        }
        mxHeight = max(mxHeight,abs(top-h));
        
        return (1LL*mxHeight*mxWidth)%MOD;
    }
};