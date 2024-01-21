#include <iostream>
#include <queue>

using namespace std;

// 30 20 40 10 25 35 50 -1 -1 -1 -1 -1 -1 -1 -1

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

void in_order_recursive(Node* root) {
    if (root == NULL) return;

    in_order_recursive(root->left);
    cout << root->val << " ";
    in_order_recursive(root->right);
}

void insert_in_sorted_position(Node* root, int x) {
    Node* newNode = new Node(x);
    Node* followerNode = NULL;

    while (root != NULL) {
        followerNode = root;
        if (root->val == x) {
            return;
        } else if (root->val > x) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    if (followerNode->val > x) {
        followerNode->left = newNode;
    } else {
        followerNode->right = newNode;
    }
}

Node* recursive_insert(Node* p, int key) {
    if (p == NULL) {
        return p = new Node(key);
    }

    if (key < p->val) {
        p->left = recursive_insert(p->left, key);
    } else {
        p->right = recursive_insert(p->right, key);
    }

    return p;
}


int main() {
    Node* root = input_binary_tree();
    // in_order_recursive(root);
    insert_in_sorted_position(root,55);
    in_order_recursive(root);

    return 0;
}