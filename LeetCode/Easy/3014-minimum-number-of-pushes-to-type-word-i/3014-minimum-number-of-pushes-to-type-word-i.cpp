class Solution {
public:
    int minimumPushes(string s) {
        if (s.size() <= 8) {
            return s.size();
        }
        else if(s.size()>8 && s.size()<=16){
            return 8 + (s.size()-8)*2;
        }else if(s.size()>16 && s.size() <= 24){
            return 24 + (s.size()-16)*3;
        }else{
            return 8+16+24 + (s.size()-24)*4;
        }

        return 0;
}
};