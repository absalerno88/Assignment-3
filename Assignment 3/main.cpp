#include "ExpressionManager.h"
#include "Queue.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ExpressionManager manager;
    string input;

    while (true) {
        cout << "Enter an infix expression or type 'quit' to exit: ";
        getline(cin, input);

        if (input == "quit") {
            break;
        }

        // Read an infix expression from the user
        manager.readExpression(input);

        // Conver the expression to postfix and print it
        manager.convertAndPrint();
    }


    Queue<int> queue; // Queue of integers for testing

    cout << "\nTransitioning to Queue testing. \n";
    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Get Size\n";
        cout << "6. Quit Queue Testing\n";
        cout << "Enter your choice: "; 

        int choice;
        cin >> choice;
        if (cin.fail()) { // Input validation
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        int value;
        switch (choice) {
            case 1: // Enqueue
                cout << "Enter an integer value to enqueue: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input
                    cout << "Invalid input. Please enter an integer.\n";
                } else {
                    queue.enqueue(value);
                    cout << value << " enqueued.\n";
                }
                break;
            case 2: // Dequeue
                if (queue.isEmpty()) {
                    cout << "Queue is empty, nothing to dequeue.\n";
                } else {
                    value = queue.dequeue();
                    cout << value << " dequeued.\n";
                }
                break;
            case 3: // Peek
                if (queue.isEmpty()) {
                    cout << "Queue is empty, nothing at the front.\n";
                } else {
                    value = queue.peek();
                    cout << "Front value: " << value << "\n";
                }
                break;
            case 4: // Check if Empty
                cout << (queue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5: // Get Size
                cout << "Queue size: " << queue.size() << "\n";
                break;
            case 6: // Quit Queue Testing
                cout << "Exiting Queue testing.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
