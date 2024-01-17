 #include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {

        if(num1=="0" || num2=="0") return "0";
        
        vector<int>result(num1.size()+num2.size(),0);

        for(int i=num1.size()-1; i>=0;i--){
            int carry = 0;
            for(int j=num2.size()-1; j>=0;j--){
                int prod = (num1[i]-'0')*(num2[j]-'0') + carry + result[i+j+1];
                result[i+j+1] = prod % 10;
                carry = prod/10;
            }
            result[i] += carry;
        }

        int i = 0;
        while(i<result.size() && result[i]==0) i++;

        string ans = "";
        while(i<result.size()){
            ans += result[i] + '0';
            i++;
        }

        return ans;
    }
    
int main()
{
    string a = "123";
    string b = "456";
    
    cout<<multiply(a,b)<<endl;

    return 0;
}