class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       queue<int>q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }

        int i=0;
        int rotation=0;
        while(!q.empty() && rotation<q.size())
        {
            if(q.front()==sandwiches[i])
            {
                q.pop();
                i++;
                rotation=0;
            }
            else{
                q.push(q.front());
                q.pop();
                rotation++;
            }
        }
        return q.size(); 

    }
};