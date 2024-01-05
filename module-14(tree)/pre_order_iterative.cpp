#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* input_binary_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1) {
        root = NULL;
    } else {
        root = new Node(val);
    }
    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            f->left = new Node(l);
            q.push(f->left);
        } else {
            f->left = NULL;
        }

        if (r != -1) {
            f->right = new Node(r);
            q.push(f->right);
        } else {
            f->right = NULL;
        }
    }

    return root;
}

void pre_order_recursive(Node* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    pre_order_recursive(root->left);
    pre_order_recursive(root->right);
}

void pre_order_iterative(Node* root) {
    stack<Node*> s;
    Node* p = root;

    while (p != NULL || !s.empty()) {
        if (p != NULL) {
            cout << p->val << " ";
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void in_order_iterative(Node* root) {
    stack<Node*> s;
    while(root != NULL || !s.empty()) {
        if(root != NULL) {
            s.push(root);
            root = root->left;
        }else {
            root = s.top();
            s.pop();
            cout<<root->val<<" ";
            root = root->right;
        }
    }
}

void post_order_iterative(Node* root) {
    stack<Node*> s;
    while(root != NULL || !s.empty()) {
        if(root != NULL) {
            s.push(root);
            root = root->left;
        }else {
            root = s.top();
            s.pop();
            if(root > 0) {
                s.push(-root);
                root = root->right;
            }else {
                cout<<root->val<<" ";
                root = NULL;
            }
        }
    }
}

int main() {
    Node* root = input_binary_tree();
    // pre_order_recursive(root);
    // pre_order_iterative(root);
    in_order_iterative(root);

    return 0;
}