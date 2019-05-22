
void merge(int *arr, int size, int M, int X){
	int i;
	for(i = 1; i <= size; i++){
		if(arr[i] == X)
			arr[i] = M;
	}
}

int findCircleNum(int** M, int MSize, int* MColSize){
	int *p = (int *)calloc(1, sizeof(int) * (MSize + 1));
	int i, j;
	for(i = 0; i < MSize; i++){
		for(j = 0; j <= i; j++){
			if(M[i][j] == 1){
				if(p[j + 1] == 0 && p[i + 1] == 0){
					p[i + 1] = i + 1;
					p[0]++;
					p[j + 1] = i + 1;
				}else if(p[j + 1] == 0 && p[i + 1] != 0){
					p[j + 1] = p[i + 1];
				}else if(p[j + 1] != 0 && p[i + 1] == 0)
					p[i + 1] = p[j + 1];
				else{
					merge(p, MSize, p[i + 1], p[j + 1]);
					p[0]--;
				}
			}
		}
	}
	for(i = 0; i <= MSize; i++){
		printf("%d %d\n", i, p[i]);
	}
	i = p[0];
	free(p);
	return i;
}


