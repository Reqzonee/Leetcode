class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int endtime = 0;
        int n = customers.size();
        double waitingtime = 0;
        for(int i = 0; i < customers.size(); i++){
            int nextstarttime = max(endtime, customers[i][0]);
            endtime = nextstarttime+customers[i][1];
            waitingtime += (endtime-customers[i][0]);
        }
        return waitingtime*1.0/n;
    }
};