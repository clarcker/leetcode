bool stoneGame(int* piles, int pilesSize){
	int (*arr)[2] = (int (*)[2])malloc(sizeof(int) * 2 * pilesSize);
	bool re;
	int i, j, temp;
	for(i = 0; i < pilesSize - 1; i++){
		arr[i][0] = piles[i] > piles[i + 1] ? piles[i]:piles[i + 1];
		arr[i][1] = piles[i] < piles[i + 1] ? piles[i]:piles[i + 1];
	}
	for(i = 2; i < pilesSize; i++){
		for(j = 0; j + i< pilesSize; j++){
			if(piles[j] + arr[j + 1][1] > piles[j + i] + arr[j][1]){
				arr[j][1] = arr[j][0];
				arr[j][0] = piles[j] + arr[j + 1][1];
			}else{
				temp = arr[j][1];
				arr[j][1] = arr[j][0];
				arr[j][0] = piles[j + i] + temp;
			}
		}
	}
	re = arr[0][0] > arr[0][1];
    //printf("%d %d",arr[0][0], arr[0][1]);
	free(arr);
	return re;
}

