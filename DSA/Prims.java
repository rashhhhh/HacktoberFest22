
class Prims{
	static int V;

	public int minkey(boolean[] mstset,int[] key){
		int min = Integer.MAX_VALUE;
		int minIndex = -1;

		for(int i=0;i<V;i++){
			if(!mstset[i] && key[i] < min){
				min = key[i];
				minIndex = i;
			}
		}

		return minIndex;
	}

	public void print(int [] parent,int [] key){
		for(int i=1;i<V;i++){
			System.out.println((i+1)+" - " +(parent[i]+1)+" : "+key[i]);
		}
	}

	public void prims(int [][] graph){
		boolean [] mstset = new boolean[V];
		int [] key = new int[V];
		int [] parent = new int[V];
		for(int i=0;i<V;i++){
			key[i] = Integer.MAX_VALUE;
			mstset[i] = false;
		}

		key[0] = 0;

		for(int count = 0;count < V-1;count++){
			int u = minkey(mstset,key);
			mstset[u] = true;
			for(int v=0;v<V;v++){
				if(!mstset[v] && graph[u][v] != 0){
					key[v] = graph[u][v];
					parent[v] = u;
				}
			}
		}
		print(parent,key);
	}

	public static void main(String[] args) {
		V = 5;
		int graph[][] = {{ 0, 10, 0, 0, 5 },
	                      { 10, 0, 1, 6, 0 },
	                      { 8, 1, 0, 2, 7},
	                      { 0, 6, 2, 0, 3 },
	                      { 5, 0, 7, 3, 0 } };
		
		Prims t = new Prims();
		
		long start = System.currentTimeMillis();
		t.prims(graph);
		long finish = System.currentTimeMillis();
		long timeElapsed = finish - start;
		System.out.println("TimeElapsed: "+ timeElapsed+"ms");
	}
}