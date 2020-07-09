namespace Part1.Common
{
    public class TreeBuilder
    {
        public static TreeNode SimpleTree()
        {
            TreeNode root = new TreeNode(1);
            TreeNode nd1 = new TreeNode(3);
            TreeNode nd2 = new TreeNode(2);
            TreeNode nd3 = new TreeNode(5);
            TreeNode nd4 = new TreeNode(3);
            TreeNode nd5 = new TreeNode(9);

            // Making the edges
            root.left = nd1;
            root.right = nd2;
            nd1.left = nd3;
            nd1.right = nd4;
            nd2.right = nd5;

            return root;
        }
    }
}
