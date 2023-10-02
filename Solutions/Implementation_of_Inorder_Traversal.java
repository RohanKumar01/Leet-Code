class Node{
    int data;
    Node left, right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class subrat {

    static void inOrderTrav(Node curr, ArrayList < Integer > inOrder) {
        if (curr == null)
            return;

        inOrderTrav(curr.left, inOrder);
        inOrder.add(curr.data);
        inOrderTrav(curr.right, inOrder);
    }
}
