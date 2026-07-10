class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c : tokens){
            
            if( c == "+"){
                int s1 = st.top() ;
                st.pop();
                int s2 = st.top() ;
                st.pop();
                st.push(s1 + s2);
            }
            else if( c == "-"){
                int s1 = st.top() ;
                st.pop();
                int s2 = st.top() ;
                st.pop();
                st.push(s2 - s1);
            }
            else if( c == "*"){
                int s1 = st.top();
                st.pop();
                int s2 = st.top() ;
                st.pop();
                st.push(s1 * s2);
            }
            else if( c == "/"){
                int s1 = st.top() ;
                st.pop();
                int s2 = st.top() ;
                st.pop();
                st.push(s2/s1);
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
