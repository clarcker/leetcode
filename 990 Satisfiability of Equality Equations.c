void merge(char *arr, char M, char X){
	int i;
	for(i = 0; i < 26; i++){
		if(arr[i] == X)
			arr[i] = M;
	}
}

bool equationsPossible(char ** equations, int equationsSize){
	char *p = (char *)calloc(1, sizeof(char) * 26);
	int i, j;
	char a, b;
	for(i = 0; i < equationsSize; i++){
		if(equations[i][1] == '='){
			a = equations[i][0];
			b = equations[i][3];
			if(p[a - 'a'] == '\0' && p[b - 'a'] == '\0'){
				p[a - 'a'] = a;
				p[b - 'a'] = a;
			}else if(p[a - 'a'] == '\0' && p[b - 'a'] != '\0')
				p[a - 'a'] = p[b - 'a'];
			else if(p[a - 'a'] != '\0' && p[b - 'a'] == '\0'){
				p[b - 'a'] = p[a - 'a'];
			}else if(p[a - 'a'] != '\0' && p[b - 'a'] != '\0' && p[a - 'a'] != p[b - 'a'])
				merge(p, p[a - 'a'], p[b - 'a']);
		}
	}
	for(i = 0; i < equationsSize; i++){
		if(equations[i][1] == '!'){
			a = equations[i][0];
			b = equations[i][3];
			if(a == b)
				return false;
			if(p[a - 'a'] == '\0' && p[b - 'a'] == '\0'){
				p[a - 'a'] = a;
				p[b - 'a'] = b;
			}else if(p[a - 'a'] == '\0' && p[b - 'a'] != '\0')
				p[a - 'a'] = a;
			else if(p[a - 'a'] != '\0' && p[b - 'a'] == '\0'){
				p[b - 'a'] = b;
			}else if(p[a - 'a'] != '\0' && p[b - 'a'] != '\0' && p[a - 'a'] == p[b - 'a'])
				return false;
		}
	}
	return true;
}
