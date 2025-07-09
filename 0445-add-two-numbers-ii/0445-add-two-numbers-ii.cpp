class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1 = "", num2 = "";

        while (l1) {
            num1 += to_string(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            num2 += to_string(l2->val);
            l2 = l2->next;
        }

        string result = addStrings(num1, num2);

        ListNode* head = new ListNode(result[0] - '0');
        ListNode* current = head;

        for (int i = 1; i < result.size(); i++) {
            current->next = new ListNode(result[i] - '0');
            current = current->next;
        }

        return head;
    }

    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = i >= 0 ? a[i--] - '0' : 0;
            int digit2 = j >= 0 ? b[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }

        return res;
    }
};
