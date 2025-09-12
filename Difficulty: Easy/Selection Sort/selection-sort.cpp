class Solution {
  public:
    // har pass me smallest element find karke pahale rakhana hai. 
    void selectionSort(vector<int> &arr) {
        // code here
        int n=arr.size();
        int minindex=0;
        for(int i=0;i<n;i++){
            minindex=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minindex]) minindex=j;
            }
            swap(arr[i],arr[minindex]);
        }
    }
};