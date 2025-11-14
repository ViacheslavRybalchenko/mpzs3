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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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

int recursiveDouble(ListNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int carry = recursiveDouble(node->next);
    int doubledValue = node->val * 2 + carry;

    node->val = doubledValue % 10;
    return doubledValue / 10;
}

ListNode* doubleIt(ListNode* head) {
    int finalCarry = recursiveDouble(head);

    if (finalCarry > 0) {
        ListNode* newHead = new ListNode(finalCarry);
        newHead->next = head;
        return newHead;
    }

    return head;
}

int main() {
    setupConsole();
    std::cout << "--- Завдання 6: Подвоїти число ---" << std::endl;

    ListNode* head1 = createList({ 1, 8, 9 });
    std::cout << "Input: ";
    printList(head1);
    head1 = doubleIt(head1);
    std::cout << "Output: ";
    printList(head1);

    ListNode* head2 = createList({ 9, 9, 9 });
    std::cout << "Input: ";
    printList(head2);
    head2 = doubleIt(head2);
    std::cout << "Output: ";
    printList(head2);

    return 0;
}