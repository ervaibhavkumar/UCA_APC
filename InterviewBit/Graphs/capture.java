import java.util.*;

public class capture {

	static void dfs(ArrayList<StringBuilder> a, int i, int j, int r, int c, char prevC, char newC) {

		if(i<0||i>=r||j<0||j>=c) return;

		if(a.get(i).charAt(j) != prevC) return;

		a.get(i).setCharAt(j,newC);

		dfs(a,i+1,j,r,c,prevC,newC);
		dfs(a,i-1,j,r,c,prevC,newC);
		dfs(a,i,j+1,r,c,prevC,newC);
		dfs(a,i,j-1,r,c,prevC,newC);
	}

	static void change(ArrayList<StringBuilder> a) {
		int r = a.size();
		int c = a.get(0).length();

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(a.get(i).charAt(j) == 'O') {
					a.get(i).setCharAt(j,'-');
				}
			}
		}

		for(int i=0;i<c;i++) {
			if(a.get(0).charAt(i) == '-') {
				dfs(a,0,i,r,c,'-','O');
			}
		}

		for(int i=0;i<r;i++) {
			if(a.get(c-1).charAt(i) == '-') {
				dfs(a,i,c-1,r,c,'-','O');
			}
		}

		for(int i=c-1;i>=0;i--) {
			if(a.get(r-1).charAt(i) == '-') {
				dfs(a,r-1,i,r,c,'-','O');
			}
		}

		for(int i=r-1;i>=0;i--) {
			if(a.get(0).charAt(i) == '-') {
				dfs(a,i,0,r,c,'-','O');
			}
		}

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(a.get(i).charAt(j) == '-') {
					a.get(i).setCharAt(j,'X');
				}
			}
		}
	}

	public static void main(String[] args) {
		ArrayList<StringBuilder> a= new ArrayList<StringBuilder>();

		a.add(new StringBuilder("XXXX"));
		a.add(new StringBuilder("XOOX"));
		a.add(new StringBuilder("XXOX"));
		a.add(new StringBuilder("XOXX"));

		change(a);
		System.out.println(a);
	}
}