class Solution {
  public:
    int fact(int t){
        if(t<1) return 0;
        int fact=1;
        for(int i=2;i<=t;i++) fact=fact*i;
        return fact;
    }
    int vowelCount(string& s) {
        // code here
        int n=s.length();
        vector<int>t(5,0);
        for(int i=0;i<n;i++){
            if(s[i]=='a') t[0]++;
            else if(s[i]=='e') t[1]++;
            else if(s[i]=='i') t[2]++;
            else if(s[i]=='o') t[3]++;
            else if(s[i]=='u') t[4]++;
        }
        int mul=1;
        int count=0;
        for(auto p:t){
            if(p!=0) {
                mul*=p;
                count++;
            }
            
        }
        return fact(count)*mul;
        
    }
};