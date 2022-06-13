class Solution {
public:
    void helper(int ind, vector<string> &res, string ds, string digits, string map[]){
        if(ind>=digits.size()){
            res.push_back(ds);
            return;
        }
        int num = digits[ind]-'0';
        string val = map[num];
        
        for(int i=0; i<val.size(); i++){
            ds.push_back(val[i]);
            helper(ind+1, res, ds, digits, map);
           
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        string map[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(0, res,"", digits, map);
        return res;
    }
};
