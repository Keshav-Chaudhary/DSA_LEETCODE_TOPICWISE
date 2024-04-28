using LL = long long;
class Solution {
public:
    long long minEnd(int n, int x) 
    {
        LL m = n-1;
        vector<int>arr;
        while (m>0)
        {
            arr.push_back(m%2);
            m/=2;
        }
        
        vector<int>bits;
        while (x>0)
        {
            bits.push_back(x%2);
            x/=2;
        }
        
        int j = 0;
        for (int i=0; i<bits.size(); i++)
        {
            if (bits[i]==1) continue;
            if (j<arr.size()) 
            {
                bits[i] = arr[j];
                j++;
            }            
        }
        while (j<arr.size())
        {
            bits.push_back(arr[j]);
            j++;
        }
        
        LL ret = 0;
        for (int j=bits.size()-1; j>=0; j--)
            ret = ret*2+bits[j];
    
        return ret;
        
    }
};
