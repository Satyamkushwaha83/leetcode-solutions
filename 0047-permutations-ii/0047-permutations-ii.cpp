class Solution {
public:
     void per(vector<int>& arr, int index, vector<vector<int>>& ans) {
        if (arr.size() == index) {
            ans.push_back(arr);
            return;
        }
        vector<bool> use(21, 0);
        for (int i = index; i < arr.size(); i++) {
            if (use[arr[i] + 10] == 0) {
                swap(arr[i], arr[index]);
                per(arr, index + 1, ans);
                swap(arr[index], arr[i]);
                use[arr[i] + 10] = 1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        per(nums, 0, ans);
        return ans;
    }
};