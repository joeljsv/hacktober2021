class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, int>> qop;
        qop.push({root, 0});
        int ans = 0;
        int first, last;
        while (!qop.empty()) {
            int size = qop.size();
            int min = qop.front().second;

            for (int i = 0; i < size; i++) {
                TreeNode* node = qop.front().first;
                int cur = qop.front().second - min;
                qop.pop();
                if (i == 0)
                    first = cur;
                if (i == size - 1)
                    last = cur;

                if (node->left) {
                    qop.push({node->left, 2 * cur + 1});
                }
                if (node->right) {
                    qop.push({node->right, 2 * cur + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};