typedef struct {
    int x;
    int y;
}coord;
int numIslands(char** grid, int gridSize, int* gridColSize){
	if(!grid || !gridColSize || !gridSize)
		return 0;
	int i, j, seq_index = 0;
    int count = 0;
    int x, y;
    coord *seq = (coord *)calloc(1, sizeof(coord) * gridSize * gridColSize[0]);
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i] ; j++){
            if(grid[i][j] == '1'){
                if(i - 1  >= 0 && grid[i - 1][j] == '1'){
                    seq[seq_index].x = i -1;
                    seq[seq_index].y = j;
                    seq_index++;
                }
                if(j - 1 >= 0 && grid[i][j - 1] == '1'){
                    seq[seq_index].x = i;
                    seq[seq_index].y = j - 1;
                    seq_index++;
                }
                if(i + 1 < gridSize && grid[i + 1][j] == '1'){
                    seq[seq_index].x = i + 1;
                    seq[seq_index].y = j;
                    seq_index++;
                }
                if(j + 1 < gridColSize[i] && grid[i][j + 1] == '1'){
                    seq[seq_index].x = i;
                    seq[seq_index].y = j + 1;
                    seq_index++;
                }
                grid[i][j] = '0';
                count++;
                while(seq_index > 0){
                    seq_index--;
                    x = seq[seq_index].x;
                    y = seq[seq_index].y;
                    grid[x][y] = '0';
                    if(x - 1  >= 0 && grid[x - 1][y] == '1'){
                        seq[seq_index].x = x -1;
                        seq[seq_index].y = y;
                        seq_index++;
                    }
                    if(y - 1 >= 0 && grid[x][y - 1] == '1'){
                        seq[seq_index].x = x;
                        seq[seq_index].y = y - 1;
                        seq_index++;
                    }
                    if(x + 1 < gridSize && grid[x + 1][y] == '1'){
                        seq[seq_index].x = x + 1;
                        seq[seq_index].y = y;
                        seq_index++;
                    }
                    if(y + 1 < gridColSize[x] && grid[x][y + 1] == '1'){
                        seq[seq_index].x = x;
                        seq[seq_index].y = y + 1;
                        seq_index++;
                    }

                }
            }
        }
    }
	free(seq);
    return count;
}
