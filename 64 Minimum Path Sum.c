int minPathSum(int** grid, int gridSize, int* gridColSize){
	int **arr = (int **)malloc(sizeof(int *) * gridSize);
	int i, j, re = 0;
	for(i = 0; i < gridSize; i++){
		arr[i] = (int *)malloc(sizeof(int) * gridColSize[i]);
        //printf("%d\n", gridColSize[i]);
	}

	arr[0][0] = grid[0][0];
	for(i = 1; i < gridSize; i++)
		arr[i][0] = arr[i - 1][0] + grid[i][0];
	for(i = 1; i < gridColSize[0]; i++)
		arr[0][i] = arr[0][i - 1] + grid[0][i];

	for(i = 1; i < gridSize; i++){
		for(j = 1; j < gridColSize[i]; j++){
			if(arr[i - 1][j] < arr[i][j - 1])
				arr[i][j] = arr[i - 1][j] + grid[i][j];
			else
				arr[i][j] = arr[i][j - 1] + grid[i][j];
		}
	}
    //printf("%d %d", gridSize - 1, gridColSize[gridSize - 1]);

	re = arr[gridSize - 1][gridColSize[gridSize - 1] - 1];  //err:gridColSize[gridSize - 1]
    //printf("%d", re);

	for(i = 0; i < gridSize; i++)
		free(arr[i]);
    free(arr);
	return re;
}


