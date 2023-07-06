#include <iostream>

const int MAX_SIZE = 100;

class Stack 
{
    int arr[MAX_SIZE]{}, top{};

public:
    Stack() : top(-1) {}

    bool isEmpty() 
    {
        return top == -1;
    }

    bool isFull() 
    {
        return top == MAX_SIZE - 1;
    }

    void push(int data) 
    {
        if (isFull())
        {
            std::cout << "Stack Overflow. Cannot push element." << std::endl;
            return;
        }

        top++;
        arr[top] = data;
        std::cout << "Element " << data << " pushed to stack." << std::endl;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            std::cout << "Stack Underflow. Cannot pop element." << std::endl;
            return;
        }

        int data = arr[top];
        top--;
        std::cout << "Element " << data << " popped from stack." << std::endl;
    }

    int search(int data) 
    {
        if (isEmpty()) 
        {
            std::cout << "Stack is empty. Cannot search element." << std::endl;
            return -1;
        }

        for (int i = top; i >= 0; i--) 
        {
            if (arr[i] == data) 
                return i;            
        }

        return -1;
    }

    void display()
    {
        if (isEmpty()) 
        {
            std::cout << "Stack is empty. Nothing to display." << std::endl;
            return;
        }

        std::cout << "Elements in the stack: ";

        for (int i = 0; i <= top; i++) 
        {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;
    }

    int findLargest() 
    {
        if (isEmpty()) 
        {
            std::cout << "Stack is empty. Cannot find the largest element." << std::endl;
            return -1;
        }

        int largest = arr[0];

        for (int i = 1; i <= top; i++) 
        {
            if (arr[i] > largest) 
                largest = arr[i];
        }
        
        return largest;
    }
};

int main()
{
    Stack stack;
    int choice{}, element{};

    do 
    {
        system("cls");
        std::cout << "STACK DATA STRUCTURE PROGRAM" << std::endl << std::endl;
        std::cout << "[1] ADD" << std::endl;
        std::cout << "[2] DELETE" << std::endl;
        std::cout << "[3] SEARCH ELEMENT (IDENTIFY THE INDEX OF THE ELEMENT)" << std::endl;
        std::cout << "[4] DISPLAY ELEMENTS" << std::endl;
        std::cout << "[5] IDENTIFY THE LARGEST INTEGER" << std::endl;
        std::cout << "[6] EXIT" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "ERROR: Invalid Choice. Please Try Again: ";
            std::cin >> choice;
        }

        switch (choice) 
        {
        case 1:
        {
            std::cout << "Enter the element to push: ";
            std::cin >> element;
            stack.push(element);
            system("pause");
            break;
        }
        case 2:
        {
            stack.pop();
            system("pause");
            break;
        }
        case 3:
        {
            std::cout << "Enter the element to search: ";
            std::cin >> element;
            int index = stack.search(element);

            if (index != -1) 
                std::cout << "Element found at index " << index << std::endl;
            else 
                std::cout << "Element not found in the stack." << std::endl;

            system("pause");
            break;
        }
        case 4:
        {
            stack.display();
            system("pause");
            break;
        }
        case 5:
        {
            int largest = stack.findLargest();

            if (largest != -1) 
                std::cout << "Largest element in the stack: " << largest << std::endl;

            system("pause");
            break;
        }
        case 6:
        {
            std::cout << "Exiting program..." << std::endl << std::endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}
