void subseq(int count1,int count2,string v,vector<string> &ans,int n){
        if(count1==n){
            // if there are n open '(', we simply push the rest closing ')'
            while(count2<n){
                v+=")";
                count2+=1;
            }
			// v is pushed to the answer vector
			
            ans.push_back(v);
            return;
        }
		
        subseq(count1+1,count2,v+"(",ans,n);
		
        if(count2<count1){
            subseq(count1,count2+1,v+")",ans,n);    
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string v;
        subseq(0,0,v,ans,n);

        return ans;
    }
