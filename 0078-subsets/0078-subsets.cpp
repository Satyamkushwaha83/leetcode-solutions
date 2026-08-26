class Solution {
public:
     void  sub(vector<int>&  arr, int index, int n, vector<vector<int>> &ans, vector<int> temp)
     {
        if(index==n)
        {
            ans.push_back(temp);
            return ;
        }
        sub(arr, index+1, n, ans, temp);
        temp.push_back(arr[index]);
          sub(arr, index+1, n, ans, temp);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sub(nums,0,nums.size(),ans,temp);
        return ans;
    }
 
};