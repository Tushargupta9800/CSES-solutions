class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2+1;
        int i,c=1;
        sort(nums.begin(),nums.end());
        if(n==1)
            return nums[0];
         for(i=1;i<nums.size();i++){
             if(nums[i]==nums[i-1]){
                 c++;}
             else{
                 c=1;}
             if(c>=n){
                 break;
             }
         }
    return nums[i];}
};
