#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int dipIndex=-1;
        int swapIndex=0;
        for(int i = n-2; i>=0;i--){
            if(nums[i] < nums[i+1]){
                dipIndex = i;
                break;
            }
        }

        if(dipIndex==-1) reverse(nums.begin(),nums.end());

        else{
            for(int i=n-1;i>dipIndex;i--){
                if(nums[i]>nums[dipIndex]){
                    swapIndex = i;
                    break;
                }
            }

            swap(nums[dipIndex],nums[swapIndex]);
            reverse(nums.begin()+dipIndex+1,nums.end());
        }
    
    }

int main()
{
    vector<int>nums = {3,2,1};
    
    nextPermutation(nums);
    
    for(auto x:nums){
        cout<<x<<" ";
    }
    
    cout<<endl;
    
    vector<int>nums2 = {1,2,3};
    
    nextPermutation(nums2);
    
    for(auto x:nums2){
        cout<<x<<" ";
    }

    return 0;
}                            