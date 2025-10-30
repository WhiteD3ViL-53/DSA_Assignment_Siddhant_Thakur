class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1; // one number missing
        int xor1 = 0, xor2 = 0;

        // XOR of all nums (1 to n)
        for (int i = 1; i <= n; i++){ 
            xor1 ^= i;
        }
        // XOR of all elements in the given array
        for (int x : arr){
            xor2 ^= x;
        }
        // XOR of both gives the missing element
        return xor1 ^ xor2;
    }
};
