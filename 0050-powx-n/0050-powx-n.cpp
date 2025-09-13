// class Solution {
// public:
//     double bPow(double x, long n){
//         if(n==0 || x==1) return 1;
//         if(n==1) return x;
//         if(n<0) return bPow(1/x,-n);
//         if(n%2 == 0) {
//             double y=bPow(x,n/2);
//             return y*y;
//         }else{
//             double y=bPow(x,(n-1)/2);
//             return x*y*y;
//         }
//     }
//     double myPow(double x, int n) {
//         return bPow(x,n);
//     }
// };
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;
            }
            x *= x;
            exp /= 2;
        }
        return result;
    }
};
