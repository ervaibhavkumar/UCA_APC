class Node {
	int key;
	int value;
	Node next;
	Node prev;

	public Node(int k, int v) {
		key = k;
		value = v;
	}
}

class LL {
	private int capacity;
	private HashMap<Integer, Node> m = new HashMap<Integer, Node>();
	Node head = null;
	Node end = null;
	public LL(int c) {
		capacity = c;
	}
	private void removeNode(Node n) {
		if(n.prev!=null) {
			n.prev.next = n.next;
		}
		else {
			head = n.next;
		}

		if(n.next!=null) {
			n.next.prev = n.next;
		}
		else {
			end = n.prev;
		}

	}

	private void setHead(Node n) {
		n.next = head;
		n.pre = null;

		if(head!=null) {
			head.prev = n;
		}
		head = n;
		if(end==null) end = head;
	}

	public int get(int key) {
		if(m.contains(key)) {
			Node nn = m.get(key);
			removeNode(nn);
			setHead(nn);
			return nn.value;
		}
		return -1;
	}
	public void set(int key, int value) {
		if(m.contains(key)) {
			Node pre = m.get(key);
			pre.value = value;
			removeNode(pre);
			setHead(pre);
		}
		else {
			node nn = new Node(key,value);
			if(m.size() >= capacity) {
				m.remove(end.key);
				removeNode(end);
				setHead(nn);
			}
			else {
				setHead(nn);
			}
			m.put(key, nn);
		}
	}
}
