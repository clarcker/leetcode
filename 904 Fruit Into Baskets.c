/*
    In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
    思路： 维护一个二维数组，行号表示篮子，arr[0][0] 记录0号篮子收集水果的种类，arr[0][1]表示现已收集多少个了
对所给树的数组从0开始循环，如果篮子为空则入蓝，不为空则判断是否和已收集水果种类相同；相同则入蓝，对应个数+1；不同则记录此时收集水果个数，查看上一个水果种类，清空另外一个水果蓝并重新统计水果个数。

*/

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
