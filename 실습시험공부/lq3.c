element dequeue(QueueType *q) {
	QueueNode *temp = q->front;
	element item;

	if(is_empty(q)) {
		error("stack is empty");
		exit(1);
	}
	else {
		item = temp->item;
		q->front = q->front->link;
		if ( q->front == NULL)
			q->rear = NULL;
		free(temp);

		return item;
	}
}

element peek(QeueueType *q) {
	element item;
	if(is_empty(q)) {
		error("error")';
		exit(1);
	else {
		item = q->front->item;
		return item;
	}
}

void printqueues(QeueueType q) {
	QueueNode *temp = q.front;
	printf("printing all item");
	while(temp != NULL) {
		printf("%d", temp->item);
		temp = temp->link;
	}
	printf("\n");
}
