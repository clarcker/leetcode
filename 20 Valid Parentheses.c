bool isValid(char * s){
	char *arr = (char *)malloc(sizeof(char) * strlen(s));
	int i, j;
	for(i = 0, j = 0; s[i] != '\0'; i++){
		if(s[i] == '(')
			arr[j++] = '(';
		else if(s[i] == '[')
			arr[j++] = '[';
		else if(s[i] == '{')
			arr[j++] = '{';
		else if(s[i] == ')'){
			if(!j || arr[--j] != '(')
				return false;
		}
		else if(s[i] == ']'){
			if(!j ||arr[--j] != '[')
				return false;
		}
 		else if(s[i] == '}'){
			if(!j ||arr[--j] != '{')
				return false;
		}
	}
	if(j != 0)
		return false;
	return true;
}
