 string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        vector<bool>vis(26,0);

        for(auto x:s){
            freq[x-'a']++;
        }

        stack<char>st;
        
        for(int i=0; i<s.size();i++){

            while(!st.empty() && st.top() > s[i] && vis[s[i]-'a']==0 && freq[st.top()-'a']>0){
                vis[st.top()-'a'] = 0;
                st.pop();
            }

            if(vis[s[i]-'a']==0){
                vis[s[i]-'a'] = 1;
                st.push(s[i]);
            }

            freq[s[i]-'a']--;

        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }