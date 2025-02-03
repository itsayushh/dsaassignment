#include <bits/stdc++.h>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* top;
    int stackSize;
    
public:
    Stack() : top(nullptr), stackSize(0) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    bool isEmpty() const {
        return top == nullptr;
    }
    int size() const {
        return stackSize;
    }
    void push(int value) {
        try {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            stackSize++;
            std::cout << "Pushed " << value;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        }
    }
    
    void pop() {
        if (isEmpty()) {
            std::cout << "Error: Cannot pop from an empty stack\n";
            return;
        }
        
        Node* nodeToDelete = top;
        top = top->next;
        delete nodeToDelete;
        stackSize--;
        std::cout << "Popped element from the stack\n";
    }
    
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        
        std::cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    int peek() const {
        if (isEmpty()) {
            std::cout << "Error: Cannot peek an empty stack\n";
            throw std::runtime_error("Stack is empty");
        }
        
        return top->data;
    }
};

int main() {
    Stack stack;
    
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    
    stack.push(15);
    stack.push(1412);
    stack.push(2121);
    stack.push(21);
    stack.push(81);
    
    std::cout << "Stack size: " << stack.size() << std::endl;
    
    stack.pop();
    
    stack.display();
    
    try {
        std::cout << "Top element: " << stack.peek() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    Stack emptyStack;
    emptyStack.pop();
    
    try {
        std::cout << emptyStack.peek() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    return 0;
}