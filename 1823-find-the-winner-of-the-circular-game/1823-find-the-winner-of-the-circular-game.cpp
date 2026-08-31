// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> arr;
//         for(int i=1;i<=n;i++)
//         {
//             arr.push_back(i);
//         }
//         int i=0;
//         while(arr.size()>1)
//         {
//             int idx=(i+k-1)%arr.size();
//             arr.erase(arr.begin()+idx);
//             i=idx;
//         }
//         return arr[0];
//     }
// };
class Solution {
public:
    int find(int n, int k) {
        if (n == 1)
            return 0;

        int ind = find(n - 1, k);
        ind = (ind + k) % n;

        return ind;  
    }

    int findTheWinner(int n, int k) {
        int result = find(n, k); 
        return result + 1;
    }
};