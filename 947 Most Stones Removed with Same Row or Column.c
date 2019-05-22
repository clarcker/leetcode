/*
	false
*/

int find_br(int *arr, int size, int x){
	int i;
	for(i = 1; i <= size; i++){
		if(arr[i] == x)
			return i;
	}
	return 0;
}

int removeStones(int** stones, int stonesSize, int* stonesColSize){
	int i ,j, max;
	int point;
	int *p = (int *)calloc(sizeof(int) * 10001);
	for(i = 0, max = 0; i < stonesSize; i++){
		max = stones[i][0] > max ? stones[i][0]:max
		max = stones[i][1] > max ? stones[i][1]:max
		if(p[stones[i][0] + 1] == 0 && p[stones[i][1] + 1] == 0){
			p[stones[i][0] + 1] = -1;
			p[stones[i][1] + 1] = stones[i][0] + 1;
		}else if(p[stones[i][0] + 1] != 0 && p[stones[i][1] + 1] == 0){
			if(p[stones[i][0] + 1] < 0){
				p[stones[j][1] + 1] = find_br(p, max, stones[i][0] + 1);
				p[stones[i][0] + 1]--;
			}else{
				p[stones[j][1] + 1] = p[stones[i][0] + 1];
				p[p[stones[i][0] + 1]]--;
			}
		}else if(p[stones[i][0] + 1] == 0 && p[stones[i][1] + 1] != 0){
			if(p[stones[j][0] + 1] < 0){
				p[stones[i][1] + 1] = find_br(p, max, stones[j][0] + 1);
				p[stones[j][0] + 1]--;
			}else{
				p[stones[i][1] + 1] = p[stones[j][0] + 1];
				p[p[stones[j][0] + 1]]--;
			}
		}else if(p[stones[i][0] + 1] != 0 && p[stones[i][1] + 1] != 0){
			if(p[stones[i][0] + 1])
		}
	}
}




