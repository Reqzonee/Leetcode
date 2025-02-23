class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreachable = 0;
        for(int i =  0; i < n; i++){
            if(i > maxreachable){
                return false;
            }
            maxreachable = max(maxreachable, i+nums[i]);
        }
        return true;
    }
};