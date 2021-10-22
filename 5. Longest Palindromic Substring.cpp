class Solution {
public:
    string longestPalindrome(string s) {
        int index=0,len=0,left=0,right=0;        

        for(int i=0;i<s.length();i++){
         
          left=i,right=i;
            while(left>=0 && right<s.length() && s[left]==s[right])left--,right++;
               int l1= right-left-1;
           
          left=i,right=i+1;      
            while(left>=0 && right<s.length() && s[left]==s[right])left--,right++;
               int l2=right-left-1;
            
            int ans=max(l1,l2);
            
            if(ans>len){
               index=i-(ans-1)/2;
               len=ans;
            }
        }
        
        return  s.substr(index,len);
    }
};
