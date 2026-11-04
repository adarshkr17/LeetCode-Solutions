class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;

            path.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        path.clear();

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);

        return ans;
    }
};