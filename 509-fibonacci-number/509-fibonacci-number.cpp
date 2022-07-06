class Solution {
public:
//     // bottom-up -> TC:- O(N) and SC:- O(N)
//     int fib(int n) {
//        vector<int> fibonacci(31,-1);
        
//         fibonacci[0] = 0;
//         fibonacci[1] = 1;
//         for(int i=2;i<=n;++i){
//             fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
//         }
//         return fibonacci[n];
//     }
    
    // bottom-up -> TC:- O(N) and SC:- O(1)
    int fib(int n) {
        int fib_0 = 0;
        int fib_1 = 1;
        int fib_2 = n;  // if n == 0 -> ans = 0 ans if n == 1 -> ans = 1
        for(int i=2;i<=n;++i){
            fib_2 = fib_1 + fib_0;
            fib_0 = fib_1;
            fib_1 = fib_2;
        }
        return fib_2;
    }
};