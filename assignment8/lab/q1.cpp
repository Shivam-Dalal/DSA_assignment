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
	int root_node;p
	cout<<"enter root node";
	Node* root=new Node(cin>>root_node);
	cout<<"enter choice:/n 1->left node 2-> right node \n,3 ->exit";
	while(true){
		int num;
		cin>>num;
		if(num==1){
			cin>>root_node;
			root->left=new Node(root_node);
			root=root->left;
		}
		if(num==2){
			cin>>root_node;
			root->right=new Node(root_node);
			root=root->right;
		}
		else:
			break;
	}
	return 0;
}
