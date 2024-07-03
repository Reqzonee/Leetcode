class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        for(int i = 0; i <= arr.size()-3; i++){
            bool flag = true;
            for(int j = i; j < i+3; j++){
                if(arr[j]%2==0){
                    flag = false;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};