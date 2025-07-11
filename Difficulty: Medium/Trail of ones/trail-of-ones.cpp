class Solution {
public:
    int countConsec(int n) {
        int a = 0, b = 0;
        for (int i = n; i; i--) {
            int p = a + b;
            b = a + (1 << (n - i));
            a = p;
        }
        return a;
    }
};