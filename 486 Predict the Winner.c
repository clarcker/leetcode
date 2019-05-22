bool PredictTheWinner(int* nums, int numsSize){
	int (*arr)[2] = (int (*)[2])malloc(sizeof(int) * 2 * numsSize);
	bool re;
	int i, j, temp;
    if(numsSize == 1)
        return true;
	for(i = 0; i < numsSize - 1; i++){
		arr[i][0] = nums[i] > nums[i + 1] ? nums[i]:nums[i + 1];
		arr[i][1] = nums[i] < nums[i + 1] ? nums[i]:nums[i + 1];
	}
	for(i = 2; i < numsSize; i++){
		for(j = 0; j + i< numsSize; j++){
			if(nums[j] + arr[j + 1][1] > nums[j + i] + arr[j][1]){
				arr[j][1] = arr[j + 1][0];
				arr[j][0] = nums[j] + arr[j + 1][1];
			}else{
				temp = arr[j][1];
				arr[j][1] = arr[j][0];
				arr[j][0] = nums[j + i] + temp;
			}
		}
	}
	re = arr[0][0] >= arr[0][1];
    //printf("%d %d",arr[0][0], arr[0][1]);
	free(arr);
	return re;
}


