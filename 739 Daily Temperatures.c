typedef struct node{
    int index;
    int value;
}list;

int* dailyTemperatures(int* T, int TSize, int* returnSize){
	int i, j, k, index = 0;
	list *arr = (list *)malloc(sizeof(list) * TSize);
	int *re = (int *)malloc(sizeof(int) * TSize);
	for(i = 0; i < TSize; i++){
		if(index == 0){
			arr[index].index = i;
			arr[index].value = T[i];
			index++;
		}else{
			if(arr[index - 1].value < T[i]){
				while(index){
					index--;
					re[arr[index].index] = i - arr[index].index;
				}
				arr[index].index = i;
				arr[index].value = T[i];
				index++;
			}else{
				for(j = 0, same_count = 0; j < index; j++){
					if(arr[j].value < T[i]){
						re[arr[j].index] = i;
					}else if(arr[j].value == T[i]){
						same_count++;
						continue;
					}
					else
						break;
				}
				if(j == 0){
					for(j = index; j >0; j--){
						arr[j].index = arr[j - 1].index;
						arr[j].value = arr[j - 1].value;
					}
					index++;
					arr[0].index = i;
					arr[0].value = T[i];
				}else if(same_count == 0){
					
				}
				
			}
		}
	}
}


