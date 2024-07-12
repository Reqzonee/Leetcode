class Solution {
public:
    int removeab(string s, int x, int y, string &newstring){
        int ans = 0;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(s[i]=='b'){
                if(!st.empty() && st.top()=='a'){
                    st.pop();
                    ans+=x;
                }
                else{
                    st.push(s[i]);
                }

            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            newstring += st.top();
            st.pop();
        }
        reverse(newstring.begin(), newstring.end());


        return ans;
    }
    int removeba(string s, int x, int y, string &newstring){
        int ans = 0;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    ans+=y;
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            newstring += st.top();
            st.pop();
        }
        reverse(newstring.begin(), newstring.end());


        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "",s2 = "";

        int ans1 = removeab(s, x, y, s1);
        int ans2 = removeba(s1, x, y, s2);


        string s3 = "", s4 = "";

        int ans3 = removeba(s, x, y, s3);
        cout << ans3 << endl;
        cout << s3 << endl;
        int ans4 = removeab(s3, x, y, s4);

        return max(ans1+ans2, ans3+ans4);
    }
};