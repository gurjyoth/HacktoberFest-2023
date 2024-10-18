#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *items;  // Dynamic array for queue items
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        items = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] items;  // Free allocated memory
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Adding an element
    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << element << endl;
            return;
        }
        if (front == -1) front = 0;  // First element being added
        rear = (rear + 1) % capacity;
        items[rear] = element;
        cout << "Inserted " << element << endl;
    }

    // Removing an element
    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return -1;  // Indicate failure
        }
        int element = items[front];
        if (front == rear) {  // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return element;
    }

    // Displaying the queue
    void display() {
        if (isEmpty()) {
            cout << "Empty Queue" << endl;
            return;
        }
        cout << "Front -> " << front << endl;
        cout << "Items -> ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << items[i] << " ";
        }
        cout << items[rear] << endl;  // Print the last item
        cout << "Rear -> " << rear << endl;
    }

    // Get the size of the queue
    int size() {
        if (isEmpty()) return 0;
        return (rear - front + capacity) % capacity + 1;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CircularQueue q(size);
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check Size\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                q.enQueue(element);
                break;
            case 2:
                element = q.deQueue();
                if (element != -1) {
                    cout << "Deleted Element is " << element << endl;
                }
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Current size of the queue: " << q.size() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
