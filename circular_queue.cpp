#include <iostream>
using namespace std;

#define SIZE 5

// 🔄 Circular Queue Class
class CircularQueue
{
private:
    int queue[SIZE];
    int front;
    int rear;
    int count;

public:

    // 🚀 Constructor
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    // ➕ Enqueue - Insert an element
    void enqueue(int value)
    {
        // 🚫 Check if Queue is Full
        if (count == SIZE)
        {
            cout << "\n❌ Queue is Full!" << endl;
            return;
        }

        // 🔄 Move rear circularly
        rear = (rear + 1) % SIZE;

        // 📥 Insert value
        queue[rear] = value;
        count++;

        cout << "\n✅ " << value << " inserted successfully!" << endl;
    }

    // ➖ Dequeue - Delete an element
    void dequeue()
    {
        // 🚫 Check if Queue is Empty
        if (count == 0)
        {
            cout << "\n❌ Queue is Empty!" << endl;
            return;
        }

        int value = queue[front];

        // 🔄 Move front circularly
        front = (front + 1) % SIZE;

        count--;

        cout << "\n🗑️ " << value << " deleted successfully!" << endl;
    }

    // 👀 Display Queue
    void display()
    {
        // 🚫 Check if Queue is Empty
        if (count == 0)
        {
            cout << "\n❌ Queue is Empty!" << endl;
            return;
        }

        cout << "\n📋 Circular Queue: ";

        // 🔄 Display elements circularly
        for (int i = 0; i < count; i++)
        {
            cout << queue[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};

// 🏁 Main Function
int main()
{
    CircularQueue cq;

    int choice;
    int value;

    // 🎯 Program Heading
    cout << "========================================" << endl;
    cout << "     🔄 CIRCULAR QUEUE USING ARRAY      " << endl;
    cout << "========================================" << endl;

    do
    {
        // 📌 Menu
        cout << "\n----------- 📋 MENU -----------" << endl;
        cout << "1️⃣  Enqueue (Insert)" << endl;
        cout << "2️⃣  Dequeue (Delete)" << endl;
        cout << "3️⃣  Display" << endl;
        cout << "4️⃣  Exit" << endl;
        cout << "-------------------------------" << endl;

        cout << "👉 Enter your choice: ";
        cin >> choice;

        // 🔀 Switch Case
        switch (choice)
        {
        case 1:
            // ➕ Insert
            cout << "📥 Enter value to insert: ";
            cin >> value;

            cq.enqueue(value);
            break;

        case 2:
            // ➖ Delete
            cq.dequeue();
            break;

        case 3:
            // 👀 Display
            cq.display();
            break;

        case 4:
            // 👋 Exit
            cout << "\n👋 Program exited successfully!" << endl;
            break;

        default:
            // ⚠️ Invalid Choice
            cout << "\n⚠️ Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
