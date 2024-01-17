#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int i=0;
    int j=0;

    int maxi = 0;

    set<char>st;

    while(j<s.length()){
        if(st.find(s[j])!=st.end()){
            st.erase(s[i]);
            i++;
        }
        else{
            st.insert(s[j]);
            maxi = max(maxi,j-i+1);
            j++;
        }
    }

    return maxi;

}

int main()
{
    string s;
    cin>>s;
    
    cout<<lengthOfLongestSubstring(s)<<endl;
    
    return 0;
}