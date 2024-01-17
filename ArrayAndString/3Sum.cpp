#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        int n = nums.size();
        for(int i=0;i<n-2;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[l] + nums[r] + nums[i];
                vector<int>temp;
                if(sum==0){
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                    l++;
                    while(l<r && nums[l]==nums[l-1]) l++;  // to avoid duplicate triplets
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        return ans;
    }

int main()
{
    vector<int>nums = {-1,0,1,2,-1,-4};
    
    vector<vector<int>>ans = threeSum(nums);
    if(ans.size()==0) cout<<"No such pairs"<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}