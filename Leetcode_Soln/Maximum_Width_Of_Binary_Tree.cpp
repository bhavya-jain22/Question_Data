class Solution {
private:

    int bfs(TreeNode* root) {
        if(!root) return 0;
        deque<pair<TreeNode*, long long>> q;
        q.push_back({root, 0});
        long long ans = 1;

        while(!q.empty()) {

            int n = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            ans = max(ans, right-left+1);

            for(int i=0; i<n; i++) {

                TreeNode* node = q.front().first;
                long long ind = q.front().second;
                q.pop_front();

                ind -= left;

                if(node->left) q.push_back({node->left, 2*ind});
                if(node->right) q.push_back({node->right, 2*ind+1});
            }
        }

        return ans;
    }


public:
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};