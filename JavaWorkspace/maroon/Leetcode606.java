package org.debojyotim;

// Problem URL: https://leetcode.com/problems/construct-string-from-binary-tree/
// Status: Accepted

class Solution {
    public String tree2str(TreeNode root) {
        StringBuilder stringBuilder = new StringBuilder();
        boolean toBeAppened;

        if( root == null ) return "";

        if( root.left == null ) {
            toBeAppened = true;
        }
        else {
            toBeAppened = false;
        }

        String leftString = tree2str(root.left);
        String rightString = tree2str(root.right);

        stringBuilder.append(root.val);

        if( false == toBeAppened ) {
            stringBuilder.append("(");
            stringBuilder.append(leftString);
            stringBuilder.append(")");

            stringBuilder.append("(");
            stringBuilder.append(rightString);
            stringBuilder.append(")");
        }

        return stringBuilder.toString();
    }
}
