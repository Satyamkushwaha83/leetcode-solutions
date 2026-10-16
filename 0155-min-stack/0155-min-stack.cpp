#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty()) {
            minSt.push(value);
        } else {
            minSt.push(min(value, minSt.top()));
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};



// class MinStack {
//     int *arr;
//     int peek;
//     int size;
//     int *minar;
//     public:
//     MinStack() {
//         size=3000;
//         arr=new int[size];
//         peek=-1;
//         minar= new int[size];
//     }
//     void push(int value)
//     {
//                 if(peek==size-1)
//         {
//             return ;
//         }
//             peek++;
//             arr[peek]=value;
//             if(peek==0)
//             {
//                 minar[peek]=value;;
//             }
//              else {
//               minar[peek] = min(minar[peek - 1], value);
//         }
//     }
//         void pop()
//         {
//             if(peek==-1){
//                 return;
//             }
//             peek--;
//         }
//         int top(){
//             if(peek ==-1)
//             {
//                 return -1;
//             }
//             return arr[peek];
//         }
//         int getMin() {
//         if (peek == -1) {
//             return -1;
//         }

//         return minar[peek];
//     }

    

// };
