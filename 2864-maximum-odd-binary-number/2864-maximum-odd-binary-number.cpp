class Solution {
public:
    string maximumOddBinaryNumber(string s) {
 int n = s.size();
        sort(s.rbegin(),s.rend());
        int pos = s.find('1');
        s.erase(pos, 1);
        s += '1';
        return s;

    }
};