// Definition for a binary tree node.

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution_Stack_Smart {
    public List<Integer> inorderTraversal(TreeNode root) {
        TreeNode current = root;
        var stack = new Stack<TreeNode>();
        var list = new ArrayList<Integer>();

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }
            var node = stack.pop();
            list.add(node.val);
            current = node.right;
        }
        return list;
    }
}

class Solution_Stack_Normal {
    public List<Integer> inorderTraversal(TreeNode root) {
        var stack = new Stack<TreeNode>();
        var list = new ArrayList<Integer>();
        var map = new HashMap<TreeNode, Boolean>();
        stack.push(root);
        while (!stack.isEmpty()) {
            var node = stack.pop();
            if (node == null) {
                continue;
            }
            if (map.getOrDefault(node, false)) {
                list.add(node.val);
                continue;
            }
            map.put(node, true);

            stack.push(node.right);
            stack.push(node);
            stack.push(node.left);
        }
        return list;
    }
}

class Solution_AC_Recursive {
    private void inorder(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        var list = new ArrayList<Integer>();
        inorder(root, list);
        return list;
    }
}