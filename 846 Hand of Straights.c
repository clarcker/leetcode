
void merge_sort(int *arr, int n){
	if(!arr || n <= 1)
		return;
    int *list_arr = (int *)malloc(sizeof(int) * n); //list_arr for insert sort
    int i, j , len, k, t;
    for(len = 1; len < n; len *= 2){
        for(i = 0, t = 0; i < n; i += len * 2){
            for(j = 0, k = 0;j < len && k < len && i + j + len< n && i + k < n;){
                if(arr[i + k] < arr[i + j + len]){
                    list_arr[t++] = arr[i + k];
                    k++;
                }else{
                    list_arr[t++] = arr[i + j + len];
                    j++;
                }
            }
            while(k < len && i + k < n){
                list_arr[t++] = arr[i + k];
                k++;
            }
            while(j < len && i + j + len< n){
                list_arr[t++] = arr[i + j + len];
                j++;
            }
        }
        memcpy(arr, list_arr, sizeof(int) * n);
    }
	free(list_arr);
}

bool isNStraightHand(int* hand, int handSize, int W){
	int *arr = (int *)calloc(1, sizeof(int) * handSize);
	merge_sort(hand, handSize);
	int i, j, head;
	for(head = 0; head < handSize;){
		for(i = head; i < handSize && arr[i] != 0; i++)
			;
		head = i;
		if(head >= handSize)
			break;
		for(j = 0; j < W && i < handSize;i++){
			if(arr[i] == 0){
				if(hand[i] - hand[head] == j){
					j++;
					arr[i] = 0;
				}else if(hand[i] - hand[head] > j)
					return false;
			}
		}
		if(j != W)
			return false;
	}
	return true;
}







