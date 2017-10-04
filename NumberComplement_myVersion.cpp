class Solution {
public:
    int findComplement(int num) {
        int negated = 0;
        int div = 0;
        for(div; div <= 31; ++div) {
            if(exp2(div) <= num && exp2(div+1) > num) break;
        }
        return negated = (int)exp2(div+1) - 1 - num;
        

    }
};
