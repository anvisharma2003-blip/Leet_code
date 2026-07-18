class Solution {
public:
    vector<vector<int>> ans;
    void sol(int index,vector<int>& candidates,int target,vector<int>& temp){
    if(target==0){
    ans.push_back(temp);
    return;
   }
   if(index==candidates.size()||target<0){
    return;
   }
   temp.push_back(candidates[index]);
   sol(index,candidates,target-candidates[index],temp);
   temp.pop_back();
   sol(index + 1, candidates, target, temp);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> temp;
       sol(0,candidates,target,temp);
       return ans;
    }
};