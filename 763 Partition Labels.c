/*
    字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
    输入: S = "ababcbacadefegdehijhklij"
    输出: [9,7,8]
    "ababcbaca", "defegde", "hijhklij"。
    思路：申请一个二维数组记录下所有字符的开始位置和终止位置，然后遍历所给字符串的长度，在二维数组中查找，1如果不存在相同字母则将其划分出来，如果存在相同字符，则循环查找二维数组中是否存在在此范围内并且不止一个的字符，如果存在，则判断是否需要修改划分长度，直至遍历所有字符串。
*/
int* partitionLabels(char* S, int* returnSize) {
	int *re = (int *)malloc(sizeof(int) * 50);
	int len_re = 0;
	int len_s = strlen(S);
	int arr[26][2];
	int i = 0, j = 0, k = 0;
	for(i = 0; i < 26; i++){
		arr[i][0] = -1;
		arr[i][1] = -1;
	}
	int flag = 0, end_i;
	for(i = 0; i < len_s; i++){
		if(arr[S[i] - 'a'][0] == -1)
			arr[S[i] - 'a'][0] = i;
		else
			arr[S[i] - 'a'][1] = i;
	}
	for(i = 0; i < len_s; ){
		j = S[i] - 'a';
		if(arr[j][0] == i && arr[j][1] == -1){
			re[len_re++] = 1;
			i++;
		}else{
			end_i = arr[j][1];
			do {
				flag = 0;
				for(j = 0; j < 26; j++){
					if(arr[j][1] > end_i && arr[j][0] > i && arr[j][0] < end_i){
						end_i = arr[j][1];
						flag = 1;
						break;
					}
				}
			}while(flag);
			re[len_re++] = end_i - i + 1;
			i = end_i + 1;
		}
	}
	*returnSize = len_re;
	return re;
}


