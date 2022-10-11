class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int size = v.size();
        
        /* ulta loop chalenge agar 9 hua to 0 krdenge nhi to piche next me 1 add krke
        return kra denge*/
        
        for(int i=size-1;i>=0;i--){
            if(v[i]==9){
                v[i] = 0;
            }
            else{
                v[i]++;
                return v;
            }
        }
        
        //condition for 9
        //agar sirf 9 rhega to else me ghusega hi nhi, hense return bhi nhi hoga
        v[0] = 1;
        v.push_back(0);
        return v;
        
    }
};
