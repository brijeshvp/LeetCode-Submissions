class Solution {
public:
    vector<int> nse_ind_left(vector<int> &a){
        vector<int> ans;

        int n = a.size();
        int pseudo_index = -1;
        stack<pair<int,int>> st;

        for(int i=0;i<n;++i){
            if(st.size()==0){
                // cout<<a[i]<<" "<<"empty ";
                ans.push_back(pseudo_index);
            }
            else if(st.size()>0){
                // cout<<a[i]<<" "<<"not emptyyy ";
                if(st.top().first<a[i])ans.push_back(st.top().second);
                else if(st.top().first >= a[i]){
                    while(!st.empty() && st.top().first >= a[i])st.pop();

                    if(st.empty())ans.push_back(pseudo_index);
                    else ans.push_back(st.top().second);
                }
            }
            st.push({a[i],i});
        }

        return ans;
    }

    vector<int> nse_ind_right(vector<int> &a){
        vector<int> ans;

        int n = a.size();
        int pseudo_index = n;
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;--i){
            if(st.size()==0){
                ans.push_back(pseudo_index);
            }
            else if(st.size()>0){
                if(st.top().first<a[i])ans.push_back(st.top().second);
                else if(st.top().first >= a[i]){
                    while(!st.empty() && st.top().first >= a[i])st.pop();

                    if(st.empty())ans.push_back(pseudo_index);
                    else ans.push_back(st.top().second);
                }
            }
            st.push({a[i],i});
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = nse_ind_left(heights);
        vector<int> right = nse_ind_right(heights);
        // for(int i=0;i<left.size();++i)cout<<left[i]<<" ";

        int n = heights.size();
        vector<int> width(n,0);
        for(int i=0;i<n;++i){
            width[i] = right[i]-left[i]-1;
        }

        long long mx = INT_MIN;
        for(int i=0;i<n;++i){
            mx = max(mx,1LL*heights[i]*width[i]);
        }
        return (int)mx;
    }
};