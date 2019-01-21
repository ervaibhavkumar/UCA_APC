import java.util.*;

public class black_shapes {

	static void dfs(ArrayList<String> a, int i, int j, boolean[][] visited, int r, int c) {
		if(i<0 || i>r-1) {
			return;
		}
		if(j<0 || j>c-1) {
			return;
		}
		if(a.get(i).charAt(j) == 'O' || visited[i][j]) return;

		visited[i][j] = true;
		dfs(a,i+1,j,visited,r,c);
		dfs(a,i-1,j,visited,r,c);
		dfs(a,i,j+1,visited,r,c);
		dfs(a,i,j-1,visited,r,c);
	}

	static void black(ArrayList<String> a) {
		int count = 0;
		int r = a.size();
		int c = a.get(0).length();
		boolean[][] visited = new boolean[r][c]; 
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(a.get(i).charAt(j) == 'X' && visited[i][j] == false) {
					dfs(a,i,j,visited,r,c);
					count++;
				}
			}
		}
		System.out.println(count);
	}

	public static void main(String[] args) {
		ArrayList<String> as = new ArrayList<String>();
		// as.add("OOOXOOO");
		// as.add("OOXXOXO");
		// as.add("OXOOOXO");
		// as.add("XXX");
		// as.add("XXX");
		// as.add("XXX");
		black(as);
	}
}