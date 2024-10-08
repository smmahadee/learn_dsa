#include <limits.h>

#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void display_node(Node *head) {
    cout << "Your linked lists are: ";

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void display_node_recursively(Node *head) {
    if (head != NULL) {
        cout << head->val << " ";
        display_node_recursively(head->next);
    }
}

void insert_a_node(Node *&head, int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        cout << endl << "Inserted at head." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    cout << endl << "Inserted at tail." << endl;
}

void insert_at_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void insert_at_any_position(Node *&head, int pos, int val) {
    Node *newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        cout << endl << "Inserted at head." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == NULL) {
            cout << endl << "Invalid position." << endl;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void count_node(Node *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    cout << "Toal node elements are: " << count << endl;
}

int count_node_recursive(Node *head) {
    if (head->next == NULL) return 1;

    head = head->next;
    return 1 + count_node_recursive(head);
}

long long int sum_of_all_node(Node *head) {
    long long int sum = 0;

    while (head != NULL) {
        sum += head->val;
        head = head->next;
    }

    return sum;
}

long long int sum_of_all_node_recursive(Node *head) {
    if (head) {
        return head->val + sum_of_all_node_recursive(head->next);
    } else {
        return 0;
    }
}

int find_max(Node *head) {
    int max = INT_MIN;

    while (head != NULL) {
        if (max < head->val) max = head->val;

        head = head->next;
    }

    return max;
}

int find_max_recursive(Node *head) {
    if (head == NULL) return INT_MIN;

    int returnValue = find_max_recursive(head->next);

    return head->val > returnValue ? head->val : returnValue;

    // if(head->val > returnValue) {
    //     return head->val;
    // }else {
    //     return returnValue;
    // }
}

int find_index(Node *head, int el) {
    int index = 1;

    while (head != NULL) {
        if (head->val == el) return index;

        index++;
        head = head->next;
    }

    return -1;
}

Node *search_node_recursive(Node *head, int el) {
    if (head == NULL) return NULL;

    if (head->val == el) {
        return head;
    } else {
        return search_node_recursive(head->next, el);
    }
}

Node *improve_search_node_function(Node *&head, int el) {
    Node *temp = head;
    Node *q = NULL;

    while (temp != NULL) {
        if (temp->val == el) {
            q->next = temp->next;
            temp->next = head;
            head = temp;
            return head;
        } else {
            q = temp;
            temp = temp->next;
        }
    }

    return NULL;
}

void insert_in_sorted_list(Node *&head, int el) {
    Node *newNode = new Node(el);
    Node *p = head;
    Node *q = NULL;

    while (p && p->val < el) {
        q = p;
        p = p->next;
    }

    if (p == head) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = q->next;
        q->next = newNode;
    }
}

void delete_node(Node *&head, int pos) {
    if (pos == 1) {
        Node *deleteNoe = head;
        head = head->next;
        delete deleteNoe;
    } else {
        Node *p = head;
        Node *q = NULL;

        for (int i = 0; i < pos - 1 && p; i++) {
            q = p;
            p = p->next;
        }

        if (p) {
            Node *deleteNode = p;
            q->next = p->next;
            delete deleteNode;
        }
    }
}

bool is_sorted(Node *head) {
    bool flag = true;

    while (head->next != NULL) {
        if (head->val > head->next->val) {
            flag = false;
            break;
        }

        head = head->next;
    }

    return flag;
}

void remove_duplicate(Node *head) {
    Node *p = head;
    Node *q = p->next;

    while (q != NULL) {
        if (p->val == q->val) {
            p->next = q->next;
            delete q;
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }

    cout << "deleted" << endl;
}

void reverse_list_by_elements(Node *head) {
    Node *p = head;
    int totalElement = count_node_recursive(head);

    int arr[totalElement];
    int i = 0;

    while (p != NULL) {
        arr[i++] = p->val;
        p = p->next;
    }

    p = head;
    i--;

    while (p != NULL) {
        p->val = arr[i--];
        p = p->next;
    }
}

void reverse_list_by_slider_points(Node *&head) {
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    head = q;
}

void reverse_list_by_recursion(Node *q, Node *p, Node *&head) {
    if (p != NULL) {
        reverse_list_by_recursion(p, p->next, head);
        p->next = q;
    } else {
        head = q;
    }
}

void concatenate_two_list(Node *first, Node *second) {
    while (first->next != NULL) {
        first = first->next;
    }

    first->next = second;
}

void merge_two_sorted_list(Node *head, Node *second, Node * third) {
    Node *first = head;
    Node *last = NULL;

    if (first->val < second->val) {
        third = first;
        last = first;
        first = first->next;
        last->next = NULL;
    } else {
        third = second; 
        last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first != NULL && second != NULL) {
        if (first->val < second->val) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first != NULL) last->next = first;
    if (second != NULL) last->next = second;

    // head = third;

    // display_node(third);
}

int main() {
    bool flag = true;
    Node *head = NULL;
    Node *head2 = NULL;
    Node *third = NULL;
    Node *tail = NULL;
    Node *tail2 = NULL;

    while (flag) {
        cout << endl << "0. Terminate program" << endl;
        // cout << "1. Create a node." << endl;
        // cout << "2. Insert a node at any position." << endl;
        cout << "3. Display node." << endl;
        // cout << "4. Count all node." << endl;
        // cout << "5. Sum of all node." << endl;
        // cout << "6. Find max value of the list." << endl;
        cout << "7. Search an element in list." << endl;
        // cout << "8. Insert in a sorted list." << endl;
        // cout << "9. Delete a node." << endl;
        // cout << "10.Check is the list sorted or not." << endl;
        // cout << "11.Remove duplicate element." << endl;
        cout << "12.Create multiple node." << endl;
        // cout << "13.Reverse list using elements." << endl;
        // cout << "14.Reverse list using slider points." << endl;
        // cout << "15.Reverse list using recursion." << endl;
        cout << "16.Create second linked list." << endl;
        cout << "17.Display two linked list." << endl;
        cout << "18.Concetenate two linked list." << endl;
        cout << "19.Merge two sorted linked list." << endl;

        cout << endl << "Choose an option: ";

        int op;
        cin >> op;

        if (op == 0) {
            flag = false;

        } else if (op == 1) {
            int val;
            cout << "Insert a value: ";
            cin >> val;

            insert_a_node(head, val);
        } else if (op == 2) {
            int pos;
            int value;
            cout << "Enter a position: ";
            cin >> pos;
            cout << "Enter a value: ";
            cin >> value;

            insert_at_any_position(head, pos, value);
        } else if (op == 3) {
            display_node(head);
            // cout << endl << "Your linked list are: ";
            // display_node_recursively(head);
            // cout << endl;
        } else if (op == 4) {
            count_node(head);
            int result = count_node_recursive(head);
            cout << "Total node are : " << result << endl;
        } else if (op == 5) {
            // long long int result = sum_of_all_node(head);
            long long int result = sum_of_all_node_recursive(head);
            cout << "Sum is : " << result << endl;
        } else if (op == 6) {
            // int max = find_max(head);
            int max = find_max_recursive(head);
            cout << "Maximum value is: " << max << endl;
        } else if (op == 7) {
            cout << "Enter which element want to search: ";
            int el;
            cin >> el;

            // Node *resultNode = search_node_recursive(head, el);
            Node *resultNode = improve_search_node_function(head, el);

            if (resultNode != NULL) {
                int index = find_index(head, resultNode->val);
                cout << "This element exist in " << index << " position"
                     << endl;
            } else {
                cout << "This element doesn't exist." << endl;
            }
        } else if (op == 8) {
            cout << "Enter a value: ";
            int val;
            cin >> val;

            insert_in_sorted_list(head, val);
        } else if (op == 9) {
            cout << "Enter a position";
            int pos;
            cin >> pos;

            delete_node(head, pos);
        } else if (op == 10) {
            bool result = is_sorted(head);

            if (result) {
                cout << "The list is sorted" << endl;
            } else {
                cout << "The list is not sorted" << endl;
            }
        } else if (op == 11) {
            remove_duplicate(head);
        } else if (op == 12) {
            cout << "Enter a value, write -1 to stop: ";
            int val;

            while (true) {
                cin >> val;
                if (val == -1) break;
                insert_at_tail(head, tail, val);
            }
        } else if (op == 13) {
            reverse_list_by_elements(head);
        } else if (op == 14) {
            reverse_list_by_slider_points(head);
        } else if (op == 15) {
            reverse_list_by_recursion(NULL, head, head);
        } else if (op == 16) {
            cout << "Enter a value, write -1 to stop: ";
            int val;

            while (true) {
                cin >> val;
                if (val == -1) break;
                insert_at_tail(head2, tail2, val);
            }
        } else if (op == 17) {
            display_node(head);
            cout << endl;
            display_node(head2);
        } else if (op == 18) {
            concatenate_two_list(head, head2);
        }else if(op == 19) {
            merge_two_sorted_list(head, head2, third);
            display_node(third);
        }
    }

    return 0;
}