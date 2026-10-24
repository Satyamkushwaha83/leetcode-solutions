class MyCircularQueue {
public:
    int* arr;
    int front;
    int rear;
    int size;
    bool full;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = 0;
        rear = -1;
        full = false;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;

        if ((rear + 1) % size == front) {
            full = true;
        }

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = 0;
            rear = -1;
            full = false;
        } else {
            front = (front + 1) % size;
            full = false;
        }

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return rear == -1;
    }

    bool isFull() {
        return full;
    }
};