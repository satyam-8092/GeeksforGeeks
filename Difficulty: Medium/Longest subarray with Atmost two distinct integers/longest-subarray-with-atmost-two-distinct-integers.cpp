class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size() ;
        map<int , int> mp ;
        int j = 0 , diff = 0 , ans = 0 ;
        
        for(int i = 0 ; i < n ; i ++){
            int num = arr[i] ;
            if(mp[num] == 0) diff ++ ;
            mp[num] ++ ;
            while(diff > 2){
                int num2 = arr[j] ;
                j ++ ;
                mp[num2] -- ;
                if(mp[num2] == 0) diff -- ;
            }
            ans = max(ans , i - j + 1) ;
        }
        return ans ;
    }
};