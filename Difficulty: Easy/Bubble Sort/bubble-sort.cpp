class Solution {
  public:
  // In each pass put largest element at the last(filling sorted array from end)
    void bubbleSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        bool swapped=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]) {
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
            }
            if(!swapped) break;
        }
    }
};