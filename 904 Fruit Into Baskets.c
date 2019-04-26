int totalFruit(int* tree, int treeSize) {
	int baskets[2][2] = {0};
	baskets[0][0] = baskets[1][0] = -1; //init -1 for empty
	int max = 0;
	int i, j;
	for(i = 0; i < treeSize; i++){
		if(baskets[0][0] == -1)
		{
			baskets[0][0] = tree[i];
			baskets[0][1] = 1;
		}else if(baskets[1][0] == -1){
			baskets[1][0] = tree[i];
			baskets[1][1] = 1;
		}else{
			if(baskets[0][0] == tree[i])
				baskets[0][1]++;
			else if(baskets[1][0] == tree[i])
				baskets[1][1]++;
			else{
				if(max < baskets[1][1] + baskets[0][1])
					max = baskets[1][1] + baskets[0][1];
				if(tree[i - 1] == baskets[1][0]){
					for(j = i - 1; j >= 0 && tree[j] == baskets[1][0]; j--)
						;
					baskets[1][1] = i - 1 - j;
					baskets[0][0] = tree[i];
					baskets[0][1] = 1;
				}else{
					for(j = i - 1; j >= 0 && tree[j] == baskets[0][0]; j--)
						;
					baskets[0][1] = i - 1 - j;
					baskets[1][0] = tree[i];
					baskets[1][1] = 1;
				}
			}
		}
	}
	if (max < baskets[1][1] + baskets[0][1])
		max = baskets[1][1] + baskets[0][1];
	return max;
}
