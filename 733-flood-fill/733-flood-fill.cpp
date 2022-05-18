class Solution {
public:
     void dfs(int i,int j,vector<vector<int>> &image,int initColor,int newColor){
        int m = image.size();
        int n = image[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)return;
        if(image[i][j]!=initColor)return;
        
        image[i][j] = newColor;
        dfs(i,j-1,image,initColor,newColor);
        dfs(i,j+1,image,initColor,newColor);
        dfs(i-1,j,image,initColor,newColor);
        dfs(i+1,j,image,initColor,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>&image, int sr,int sc, int newColor){
        if(image[sr][sc]!=newColor) dfs(sr,sc,image,image[sr][sc],newColor);
        return image;
    }
};