class Node {
    public int end;
    public Node[] next;

    public Node() {
        end = 0;
        next = new Node[10];
        for (int i = 0; i < 10; i++) {
            next[i] = null;
        }
    }
}

class Trie {
    public Node head;

    public Trie() {
        head = new Node();
    }

    public void insert(String word) {
        Node curr = head;
        for (int i = 0; i < word.length(); i++) {
            if (curr.next[word.charAt(i) - '0'] == null) {
                curr.next[word.charAt(i) - '0'] = new Node();
            }
            curr = curr.next[word.charAt(i) - '0'];
        }
        curr.end++;
    }

    public boolean check(String str) {
        Node curr = head;
        for (int i = 0; i < str.length(); i++) {
            if (curr.end > 0) {
                return false;
            }
            curr = curr.next[str.charAt(i) - '0'];
        }
        return curr.end == 0;
    }
}
public static boolean solution(String[] a) {
    Trie trie = new Trie();
    for (String str : a) {
        trie.insert(str);
    }
    for (String str : a) {
        if (!trie.check(str)) {
            return false;
        }
    }
    return true;
}