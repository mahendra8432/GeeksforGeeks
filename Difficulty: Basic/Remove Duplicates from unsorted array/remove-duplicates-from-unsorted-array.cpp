// User function Template for C++

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int,int>map;
        vector<int>ans(arr.size(),-1),ans2;
        for(int i=0;i<arr.size();i++){
          if(map.find(arr[i])==map.end())  map[arr[i]]=i;
        }
        for(auto p:map){
            int c=p.first;
            int d=p.second;
            ans[d]=c;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=-1) ans2.push_back(arr[i]);
        }
        return ans2;
    }
};