
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s_0 = 0, s_1 = 0;

        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0)
                s_0++;
            else
                s_1++;
        }

        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (s_0 == 0)
                    return s_1;
                s_0--;
            }
            else {
                if (s_1 == 0)
                    return s_0;
                s_1--;
            }
        }

        return 0;
    }
};
