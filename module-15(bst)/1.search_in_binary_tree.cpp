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

Node* search_node(Node* root, int x) {
    if (root == NULL) return NULL;

    if (root->val == x) {
        return root;
    } else if (root->val > x) {
       return search_node(root->left, x);
    } else {
       return search_node(root->right, x);
    }
}

Node* search_node_iterative(Node* root, int x) {
    while(root != NULL) {
        if(root->val == x) {
            return root;
        }else if(root->val > x) {
            root = root->left;
        }else {
            root = root->right;
        }
    }

    return NULL;
}

int main() {
    Node* root = input_binary_tree();
    // in_order_recursive(root);

    // Node* res = search_node(root, 250);
    Node* res = search_node_iterative(root, 25);

    cout << endl << res->val;

    return 0;
}