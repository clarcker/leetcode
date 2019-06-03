/*
	not the base
*/

typedef struct node{
	int posi;
	int count;
	struct node *next;
}node;

void free_all_node(node *head){
	node *p, *q;
	p = head;
	q = p->next;
	while(q) {
		free(p);
		p = q;
		q = q->next;
	}
}

node *List_Insert_Sort(node *head, int posi){
	if(!head){
		head = (node *)malloc(sizeof(node));
		head->count = 1;
		head->posi = posi;
		head->next = NULL;
		return head;
	}
	node *p, *q, *temp;
	if(head->posi > posi){
		p = (node *)malloc(sizeof(node));
		p->count = 1;
		p->next = head;
		p->posi = posi;
		return p;
	}else if(head->posi == posi){
		head->count++;
		return head;
	}
	p = head;
	q = head->next;
	while(q){
		if(q->posi > posi){
			temp = (node *)malloc(sizeof(node));
			temp->next = q;
			p->next = temp;
			temp->count = 1;
			temp->posi = posi;
			break;
		}else if(q->posi == posi){
			q->count++;
			break;
		}
		p = q;
		q = q->next;
	}
	if(!q){
		temp = (node *)malloc(sizeof(node));
		p->next = temp;
		temp->count = 1;
		temp->posi = posi;
		temp->next = NULL;
	}
	return head;
}
int get_max(node *head){
	if(!head)
		return -1;
	node *p;
	int max = head->count;
	p = head;
	while(p){
		if(p->count > max)
			max = p->count;
		p = p->next;
	}
	return max;
}
int leastBricks(int** wall, int wallSize, int* wallColSize){
	int i, j, posi, max;
	node * head = NULL;
	for(i = 0; i < wallSize; i++){
		for(j = 0, posi = 0; j < wallColSize[i] - 1; j++){
			posi += wall[i][j];
			head = List_Insert_Sort(head, posi);
		}
	}
	max = get_max(head);
	free_all_node(head);
	return wallSize - max;
}





