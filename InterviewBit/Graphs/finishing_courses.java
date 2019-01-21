import java.util.*;
public class finishing_courses {
	static boolean[] marked;
	static boolean[] recStack;

	public static boolean dfs(Graph g , int v, int par) {
		marked[v] = true;
		for(int w:g.a.get(v)) {
			if(!marked[w]) {
				if(dfs(g,w,v)) 
					return true;
			}
			else if(w!=par) {
				return true;
			}
		}
		return false;
	}

	public static boolean cycle(Graph g) {
		for(int i=0;i<g.V();i++)
			if(!marked[i])
				if(dfs(g,i,-1)) 
					return true;
		return false;
	}

	static int finish(int n, ArrayList<Integer> b, ArrayList<Integer> c) {
		Graph g = new Graph(n+1);
		marked = new boolean[n+1];
		for(int i=0;i<b.size();i++) {
			g.addEdge(b.get(i) , c.get(i));
		}

		if(cycle(g)) {
			return 0;
		}
		return 1;
	}
	public static void main(String[] args) {
		int n = 5;
		ArrayList<Integer> b = new ArrayList<Integer>();
		b.add(1);
		b.add(3);
		b.add(4);
		b.add(5);
		ArrayList<Integer> c = new ArrayList<Integer>();
		c.add(2);
		c.add(1);
		c.add(5);
		c.add(3);

		System.out.println(finish(n,b,c));
	}
}

class Graph {
	int v;
	ArrayList<ArrayList<Integer>> a = new ArrayList<>();

	int V() {
		return v;
	}
	Graph(int v) {
		this.v = v;
		for(int i=0;i<v;i++) {
			a.add(new ArrayList<Integer>());
		}
	}
	void addEdge(int v, int w) {
		a.get(v).add(w);
	}
}