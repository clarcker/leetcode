int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	int *line = (int *)malloc(sizeof(int) * gridSize);
	int *row = (int *)malloc(sizeof(int) * gridColSize[0]);
	int i, j, max, re, min;
	for(i = 0; i < gridSize; i++){
		for(j = 0, max = grid[i][j]; j < gridColSize[i]; j++){
			if(max < grid[i][j])
				max = grid[i][j];
		}
		row[i] = max;
	}
	for(j = 0; j < gridColSize[0]; j++){
		for(i = 0, max = grid[i][j]; i < gridSize; i++)
			if(max < grid[i][j])
				max = grid[i][j];
		line[j] = max;
	}
	for(i = 0, re = 0; i < gridSize; i++){
		for(j = 0; j < gridColSize[i]; j++){
			min = row[i]  < line[j] ? row[i]:line[j];
			re += min - grid[i][j];
		}
	}
	free(line);
	free(row);
	return re;
}

