#include "IntegerLinkedList.hpp"
#include <vector>


IntegerLinkedList::IntegerLinkedList(): head(nullptr) {}

IntegerLinkedList::IntegerLinkedList(const IntegerLinkedList &rhs) : head(nullptr) {
    copyNodes(rhs.head);    
}

void IntegerLinkedList::copyNodes(IntegerLinkedListNode* currentRHS) {
    while (currentRHS != nullptr) {
        this->appendDigit(currentRHS->data);
        currentRHS = currentRHS->next;
    }
}

void IntegerLinkedList::deallocateNodes() {
    IntegerLinkedListNode* current = head;
    while (current != nullptr) {
        IntegerLinkedListNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}


IntegerLinkedList & IntegerLinkedList::operator=(const IntegerLinkedList &rhs) {
    deallocateNodes();
    copyNodes(rhs.head);
    return *this;
}

IntegerLinkedList::IntegerLinkedList(IntegerLinkedList &&rhs): head(rhs.head) {
    rhs.head = nullptr;
}

IntegerLinkedList & IntegerLinkedList::operator=(IntegerLinkedList &&rhs){
    deallocateNodes();
    head = rhs.head;
    rhs.head = nullptr;

    return *this;
}



IntegerLinkedList::~IntegerLinkedList() {
    deallocateNodes();
}

IntegerLinkedList IntegerLinkedList::operator+(const IntegerLinkedList & rhs) {
    IntegerLinkedList result;
    int carry = 0;
    IntegerLinkedListNode* leftNode = head;
    IntegerLinkedListNode* rightNode = rhs.head;

    while (leftNode != nullptr || rightNode != nullptr || carry > 0) {
        int leftDigit = (leftNode) ? leftNode->data : 0;
        int rightDigit = (rightNode) ? rightNode->data : 0;
        int sum = leftDigit + rightDigit + carry;
        
        result.appendDigit(sum % 10);
        carry = sum / 10;

        if (leftNode) leftNode = leftNode->next;
        if (rightNode) rightNode = rightNode->next;
    }

    return result;
}


bool IntegerLinkedList::operator==(const IntegerLinkedList& rhs) const {
    IntegerLinkedListNode* leftNode = head;
    IntegerLinkedListNode* rightNode = rhs.head;

    while (leftNode != nullptr && rightNode != nullptr) {
        if (leftNode->data != rightNode->data) return false;
        leftNode = leftNode->next;
        rightNode = rightNode->next;
    }

    return (leftNode == nullptr && rightNode == nullptr);
}

bool IntegerLinkedList::operator!=(const IntegerLinkedList& rhs) const {
    return !(*this == rhs);
}

IntegerLinkedList IntegerLinkedList::fromString(const std::string& s) {
    IntegerLinkedList result;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] < '0' || s[i] > '9') {
            throw std::invalid_argument("Invalid character in string");
        }
        result.appendDigit(s[i] - '0');
    }
    return result;
}

IntegerLinkedList IntegerLinkedList::fromInt(int i) {
    IntegerLinkedList result;
    if (i == 0) {
        result.appendDigit(0);
        return result;
    }

    i = std::abs(i);

    while (i > 0) {
        result.appendDigit(i % 10);
        i /= 10;
    }

    return result;
}



std::ostream & operator<<(std::ostream & s, const IntegerLinkedList & rhs) {
    IntegerLinkedListNode* current = rhs.head;
    std::vector<int> digits;

    // Collect digits in a vector to reverse print
    while (current) {
        digits.push_back(current->data);
        current = current->next;
    }

    // Print digits from most significant to least significant
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        s << *it;
    }

    return s;
}