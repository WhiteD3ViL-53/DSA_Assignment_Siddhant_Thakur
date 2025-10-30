/*
struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x; next = NULL;
    }
};
*/

class Solution {
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    // Removes all the leading zeros and if all are zeros then return the single node 0
    Node* trimLeadingZeros(Node* head) {
        while (head && head->data == 0) head = head->next;
        if (!head) return new Node(0);
        return head;
    }

public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // normalizing inputs ie no 0s
        head1 = trimLeadingZeros(head1);
        head2 = trimLeadingZeros(head2);

        // 2) making least significant bits come first by reversing
        Node* a = reverse(head1);
        Node* b = reverse(head2);

        // 3) school like addition
        int carry = 0;
        Node dummy(-1);
        Node* tail = &dummy;

        while (a || b || carry) {
            int sum = carry;
            if (a) { sum += a->data; a = a->next; }
            if (b) { sum += b->data; b = b->next; }

            tail->next = new Node(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }

        // 4) ensuring no leading zeros by reversing back to fwd order
        Node* res = reverse(dummy.next);
        res = trimLeadingZeros(res); // handling the "0" case correctly

        return res;
    }
};
