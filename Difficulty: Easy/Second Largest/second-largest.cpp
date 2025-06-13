class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<2) return -1;
        int maxi=0,maxi2=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi2=maxi;
                maxi=arr[i];
            }
            else if(arr[i]>maxi2 && arr[i]!=maxi) maxi2=arr[i];
        }
       if(maxi2!=0) return maxi2;
       else return -1;
    }
};