class Solution {
public:
    vector<int> findClosestElements(vector<int>& ar, int k, int x) {
        // find the point which is closest to the x
        const int n = ar.size();
        int l = 0;
        int r = ar.size()-1;
        int ans = 0;
        if(ar[r] < x) ans = r;
        while(l <= r){
            int mid = (l+r)>>1;
            if(ar[mid] == x){
                ans = mid;
                break;
            }
            if(x < ar[mid]){
                if(mid > 0 && x > ar[mid-1]){
                    if(abs(ar[mid] - x) > abs(ar[mid-1] - x))
                        ans = mid - 1;
                    else ans = mid;
                    break;
                }
                r = mid-1;
            }else{
                if(mid < n - 1 && x < ar[mid+1]){
                    if(abs(ar[mid] - x) > abs(ar[mid+1] - x))
                        ans = mid + 1;
                    else ans = mid;
                    break;
                }
                
                l = mid+1;
            }
        }
        l = ans - 1;
        r = ans + 1;
        int j = 1;        
        while(j < k){
            if(l < 0) ++r;
            else if(r >= n) --l;
            else if(abs(ar[l] - x) <= abs(ar[r] - x)) --l;
            else ++r;
            ++j;
        }
        return vector<int>(ar.begin()+l+1,ar.begin()+r);
    }
};