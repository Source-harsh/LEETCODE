class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        if(n<1000000) return n-999;
        if(n<1000000000){
            long long count = 999999-999;
            count += (n-999999)*2;
            return count;
        }
        if(n<1000000000000){
            long long count = 999999-999;
            count += (999999999-999999)*2;
            count += (n-999999999)*3;
            return count;
        }
        if(n<1000000000000000){
            long long count = 999999-999;
            count += (999999999-999999)*2;
            count += (999999999999-999999999)*3;
            count += (n-999999999999)*4;
            return count;
        }
        long long count = 999999-999;
            count += (999999999-999999)*2;
            count += (999999999999-999999999)*3;
            count += (999999999999999-999999999999)*4;
            return count+5;
    }
};