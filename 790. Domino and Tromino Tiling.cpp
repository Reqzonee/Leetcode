class Solution {
public:
    int numTilings(int n) {
            int md=1e9;
    md+=7;

        map<long long , long long> m;
        m[0]=0;
        m[2]=1;
        m[4]=2;
        m[6]=5;
        m[8]=11;
        if(n<=4){
            return m[2*n];
        }

        for(int i = 5; i <= n; i++){
            m[2*i]=m[2*i-2]*2+m[2*i-6];
            m[2*i]=m[2*i]%md;
        }
        return m[2*n];
    }
};