#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head;

    int size(Node* startNode)
    {
        if (!startNode) return 0;
        return 1 + size(startNode->next);
    }

    public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(int value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print()
    {
        Node* temp = head;
        while (temp)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    Node* reverseRecursive(Node* node)
    {
        if (!node || !node->next)
        {
            return node;
        }

        Node* newHead = reverseRecursive(node->next);

        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }

    void reverse()
    {
        head = reverseRecursive(head);
    }

    int getFactorial();
};

int factorial (int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int LinkedList::getFactorial()
{
    return factorial(size(head));
}

int main()
{
    LinkedList list;
    list.push_back(5);
    list.push_back(15);
    list.push_back(25);

    list.print();
    list.reverse();
    list.print();

    std::cout << list.getFactorial();
}