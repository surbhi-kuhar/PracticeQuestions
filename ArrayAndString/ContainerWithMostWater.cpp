#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {

        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxi = INT_MIN;

        while(i<j){
            if(height[i]<height[j]){
                maxi = max(maxi,(j-i)*height[i]);
                i++;
            }
            else{
                maxi = max(maxi,(j-i)*height[j]);
                j--;
            }
        }

        return maxi;
    }

int main()
{
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    
    cout<<maxArea(height)<<endl;

    return 0;
}