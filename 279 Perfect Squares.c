/*
    四平方定理：任何一个数都可以表示为4个数的平方和比如7 = 1*1 + 2*2 + 1*1 + 1*1 + 0*0
    推论；如果能被4整除，除去4，则不影响个数，
    如果一个数除以8，余7，则必定是由四个平方数组成
*/


int numSquares(int n){
	int i, j;
	while(n % 4 == 0)
		n /= 4;
	if(n % 8 == 7)
		return 4;
	j = (int)sqrt(n);
	if(j * j == n)
		return 1;
	for(i = j; i > 0; i--){
		j  = sqrt(n - i * i);
		if(j * j == n - i * i)
			return 2;
	}
	return 3;
}
