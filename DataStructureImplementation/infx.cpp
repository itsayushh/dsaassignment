#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    string ans;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while (!st.empty() && prec(st.top())>prec(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
string infixToPrefix(string s){
    string ans;
    stack<char> st;
    reverse(s.begin(),s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while (!st.empty() && st.top()!=')')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while (!st.empty() && prec(st.top())>prec(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1 = infixToPrefix("(a-b/c)*(a/k-l)");
    string s2 = infixToPostfix("(a-b/c)*(a/k-l)");
    cout<<s1<<" "<<s2<<"\n";

}