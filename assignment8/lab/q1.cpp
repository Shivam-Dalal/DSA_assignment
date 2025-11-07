#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class solution{
  vector<int> pre, in, post;
  void allTraversals(Node* root) {
    if (root == NULL) return;
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else post.push_back(it.first->data);
    }
  }
};
int main(){
  Node* root=new Node(1);
  root->left=new Node(2);
  root->left->right=new Node(4);
  root->right=new Node(3);
  root->right->left=new Node(5);
  return 0;
}
