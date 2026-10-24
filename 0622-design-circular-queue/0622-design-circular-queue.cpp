
class MyCircularQueue {
public:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;
    int size;
    int cap;

    MyCircularQueue(int k) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        cap = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } 
        else {
            newNode->prev = rear;
            newNode->next = front;

            rear->next = newNode;
            front->prev = newNode;

            rear = newNode;

        }

        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } 
        else {
            Node* temp = front;

            front = front->next;
            front->prev = rear;
            rear->next = front;

            delete temp;
        }

        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return front->data;
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    bool isFull() {
        return size == cap;
    }
};

// class MyCircularQueue {
// public:
//     int* arr;
//     int front;
//     int rear;
//     int size;
//     bool full;

//     MyCircularQueue(int k) {
//         size = k;
//         arr = new int[size];
//         front = 0;
//         rear = -1;
//         full = false;
//     }

//     bool enQueue(int value) {
//         if (isFull()) {
//             return false;
//         }

//         rear = (rear + 1) % size;
//         arr[rear] = value;

//         if ((rear + 1) % size == front) {
//             full = true;
//         }

//         return true;
//     }

//     bool deQueue() {
//         if (isEmpty()) {
//             return false;
//         }

//         if (front == rear) {
//             front = 0;
//             rear = -1;
//             full = false;
//         } else {
//             front = (front + 1) % size;
//             full = false;
//         }

//         return true;
//     }

//     int Front() {
//         if (isEmpty()) {
//             return -1;
//         }

//         return arr[front];
//     }

//     int Rear() {
//         if (isEmpty()) {
//             return -1;
//         }

//         return arr[rear];
//     }

//     bool isEmpty() {
//         return rear == -1;
//     }

//     bool isFull() {
//         return full;
//     }
// };

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */