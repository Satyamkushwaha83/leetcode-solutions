class Solution {
public:
    string maximumOddBinaryNumber(string s) {
    string ans(1, s[0]);
        for(int i=1; i <s.size();i++)
        {
            if(s[i]=='1')
            {
                ans=s[i]+ans;
            }
            else
            {
                ans=ans+s[i];
            }

        }
        int pos = ans.find('1');
        ans.erase(pos, 1);
        ans += '1';
        return ans;

    }
};