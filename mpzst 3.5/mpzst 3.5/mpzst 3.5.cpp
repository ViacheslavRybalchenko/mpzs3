#define NOMINMAX
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>

void setupConsole() {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    std::cout << "[ ";
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr ]" << std::endl;
}

ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void deleteNode(ListNode* node) {
    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 5: Видалити вузол ---" << std::endl;

    ListNode* head = createList({ 4, 5, 1, 9 });
    std::cout << "Input: ";
    printList(head);

    ListNode* nodeToDelete = head->next;
    std::cout << "Deleting node with value: " << nodeToDelete->val << std::endl;
    deleteNode(nodeToDelete);

    std::cout << "Output: ";
    printList(head);

    return 0;
}