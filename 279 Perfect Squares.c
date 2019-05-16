/*
    ��ƽ�������κ�һ���������Ա�ʾΪ4������ƽ���ͱ���7 = 1*1 + 2*2 + 1*1 + 1*1 + 0*0
    ���ۣ�����ܱ�4��������ȥ4����Ӱ�������
    ���һ��������8����7����ض������ĸ�ƽ�������
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
