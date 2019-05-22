struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX 1000
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int len = MAX;
	struct TreeNode **arr = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
	int index_arr = 0, index_re = 0;
	struct TreeNode *p = root;
	int *re = (int *)malloc(sizeof(int) * MAX);
	while(p){
		if(p->left){
			arr[index_arr++] = p;
			p = p->left;
		}else{
			if(index_re < len){
				re[index_re++] = p->val;
			}else{
				re = realloc((void *)re, sizeof(int) * (MAX + len));
				len += MAX;
				re[index_re++] = p->val;
			}
			if(p->right){
				p = p->right;
			}else{
				if(index_arr > 0s){
					p = arr[--index_arr];
					if(index_re < len){
						re[index_re++] = p->val;
					}else{
						re = realloc((void *)re, sizeof(int) * (MAX + len));
						len += MAX;
						re[index_re++] = p->val;
					}
				}else
					p = NULL;
			}
		}
	}
	*returnSize = index_re;
	free(arr);
	return re;
}


