/*
copyright xu(xusiwei1236@163.com), all right reserved.

Sqrt A
=======

Implement int sqrt(int A).

Compute and return the square root of A.

*/

#ifdef BINARY

class Solution {
public:
    int mySqrt(int A) {
        int lo = 0;
        int hi = A/2+1; // A*A/4 + A + 1 > A

        // binary search
        while (lo <= hi) {
            long long m = lo + (hi - lo)/2;
            long long s = m * m;
            if (s == A) return m;
            else if (s < A) {
                lo = m + 1;
            }
            else {
                hi = m - 1;
            }
        }
        return hi;
    }
};

#else // BINARY

class Solution {
public:
    int mySqrt(int A) {
        // Newton Iteration: x[n+1] = x[n] - f(x[n])/f'(x[n])
        // http://blog.csdn.net/xusiwei1236/article/details/25657611
        // A is root of f(x) = 0,  f(x) = x*x - A.
        // > f'(x) = 2*x
        //   x1 = x0 - (x0*x0 - A)/(2*x0)
        //      = (x0*x0 + A)/(2*x0)
		double x = A;
		if(A == 0) return 0;
		do{
            x = (x + A/x)/2;
        }while(std::fabs(x*x - A) > 0.25);
        return (int)x;
    }
};

#endif

