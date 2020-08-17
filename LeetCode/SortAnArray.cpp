class Solution {
public:
    void Merge(int s,int mid,int e,vector<int> &a){
        const int n = mid - s + 1;
        const int m = e - mid;
        // cout<<s<<" "<<mid<<" "<<e<<" "<<n<<"  "<<m<<endl;
        vector<int> left(n);
        vector<int> right(m);
        for(int i=0;i<n;++i){
            left[i] = a[i + s];
        }
        
        for(int j=0;j<m;++j){
            // cout<<e<<" "<<(j+mid+1)<<endl;
            right[j] = a[j + mid + 1];
        }
        // return;
        int l = 0,r = 0, k = s;
        while(l < n and r < m){
            if(left[l] < right[r]){
                a[k++] = left[l++];
            }else{
                a[k++] = right[r++];
            }
        }
        while(l < n){
            a[k++] = left[l++];
        }
        while(r < m){
            a[k++] = right[r++];
        }
        
    }
    void mergeSort(int s,int e,vector<int> &ar){
        if(s >= e) return;
        int mid = (s+e) >> 1;
        mergeSort(s,mid,ar);
        mergeSort(mid+1,e,ar);
        
        Merge(s,mid,e,ar);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};