class Solution {
public:
    int dp[1001][2];
    int n;
    int rec(int i,int dir,vector<int>&nums){
        if(dp[i][dir]!=-1)
        return dp[i][dir];
        int ans=1;
        if(dir){//up
        
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                ans=max(ans,rec(j,0,nums)+1);
            }
        }
        }else{//down
        for(int j=0;j<i;j++){
            if(nums[j]>nums[i]){
                ans=max(ans,rec(j,1,nums)+1);
            }
        }
        }
        return dp[i][dir]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
         n=nums.size();
        int ans=INT_MIN;
       memset(dp,-1,sizeof(dp));
       for(int i=0;i<n;i++){
        ans=max(ans,max(rec(i,0,nums),rec(i,1,nums)));
       }
       return ans;
    }
};
