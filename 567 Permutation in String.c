/*
    Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
    思路： 制造一个arr[26] 用来记录s1所有字母，并求其和，另外再运行一个数组arr2[26]记录当前录入的s2的字母，录入字符个数为s2的长度，并求其和，如果两个数组和相等，说明有可能相同，则检查每个字母是否一致，如果不同向前移位，并修改字符数组对应值。
    注意例如s1 = "ab" s2="bac" 返回true，因为ba在里面
*/
bool checkInclusion(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 > len2)
		return false;
	int arr1[26] = {0};
	int arr2[26] = {0};
	int i, j, sum1, sum2;
	for(i = 0, sum1 = 0, sum2 = 0; i < len1; i++){
		arr1[s1[i] - 'a']++;
		arr2[s2[i] - 'a']++;
		sum1 += s1[i];
		sum2 += s2[i];
	}
	for(; i < len2; i++){
		if(sum1 == sum2){
			for(j = 0; j < 26 && arr1[j] == arr2[j]; j++)
				;
			if(j == 26)
				return true;

		}
		sum2 -= s2[i - len1];
		arr2[s2[i - len1] - 'a']--;
		sum2 += s2[i];
		arr2[s2[i] - 'a']++;
	}
	if(sum1 == sum2){
		for(j = 0; j < 26 && arr1[j] == arr2[j]; j++)
			;
		if(j == 26)
			return true;

	}
	return false;
}
