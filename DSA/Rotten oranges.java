private static int[] xdir = new int[]{-1, 1, 0, 0};

private static int[] ydir = new int[]{0, 0, -1, 1};

private boolean isValid(int i, int j, int rows, int cols){

    return i>=0 && j>=0 && i<rows && j<cols;

}

public int orangesRotting(int[][] grid) {

    if(grid == null || grid.length == 0) return 0;

    int rows = grid.length;

    int cols = grid[0].length;

    int time = 0;

    int freshOrangeCount = 0;

    Queue<Integer> queue = new ArrayDeque<>();

    for(int i=0; i<rows; i++){

        for(int j=0; j<cols; j++){

            if(grid[i][j] == 2){

                queue.add(i*cols+j); //inserting row and col index in 1D form so as to avoid packing and unpacking

            } else if(grid[i][j]==1){

                freshOrangeCount++;

            }

        }

    }

    if(freshOrangeCount == 0) return 0;

    while(!queue.isEmpty()){

        int size = queue.size();

        while(size-- > 0){

            int top = queue.poll();

            int r = top/cols;

            int c = top%cols;

            for(int i=0; i<4; i++){

                int newR = r+xdir[i];

                int newC = c+ydir[i];

                if(isValid(newR, newC, rows, cols) && grid[newR][newC]==1){

                    grid[newR][newC] = 2;

                    queue.add(newR*cols + newC);

                    freshOrangeCount--;

                }

            }

        }

        if(queue.size() > 0){

            ++time;

        }

    }

    return freshOrangeCount>0?-1:time;

}
