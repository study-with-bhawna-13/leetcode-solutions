class Solution {
public:
    double bPow(double x, long n){
        if(n==0 || x==1) return 1;
        if(n==1) return x;
        if(n<0) return bPow(1/x,-n);
        if(n%2 == 0) {
            double y=bPow(x,n/2);
            return y*y;
        }else{
            double y=bPow(x,(n-1)/2);
            return x*y*y;
        }
    }
    double myPow(double x, int n) {
        return bPow(x,n);
    }
};