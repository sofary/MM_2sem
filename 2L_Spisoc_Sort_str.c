#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	char *str;
	struct list *prev, *next;
} list;
void addElem(list **L, char *str) ;
list *createList(const char *name) ;
void freeList(list *p);
void printList(list *p) ;
list *delElem(list *p) ;
void paste(list* l1, list* l2);
list *swapList(list *p) ;


//добавление элемента в список при заполнении
void addElem(list **L, char *str) 
{
	if (!*L) {
		*L = (list*)malloc(sizeof(list));
		(*L)->prev = (*L)->next = NULL;
		(*L)->str = str;
		return ;
	}
	list *tmp = *L;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (list*)malloc(sizeof(list));
	tmp->next->next = NULL;
	tmp->next->prev = tmp;
	tmp->next->str = str;
}
//создание списка
list *createList(const char *name) 
{
	list *L = NULL;
	FILE *f = fopen(name, "r");
	for (char *s = malloc(1000); fgets(s, 1000, f); s = malloc(1000))
		addElem(&L, s);
	fclose(f);
	return L;
}
//полная очистка списка
void freeList(list *p) 
{
	if (!p) return ;
	freeList(p->next);
	free(p->str);
	free(p);
}
//вывод списка
void printList(list *p) 
{
	if (!p) return ;
	printf("%s", p->str);
	printList(p->next);
}
//удаление элемента списка и его возвращение
list *delElem(list *p) 
{
	if(p->prev && p->next)
	{
	p->prev->next=p->next;
	p->next->prev=p->prev;
	p->prev=NULL;
	p->next=NULL;
	}
	else if(p->next)
	{
		p->next->prev=NULL;
		p->next=NULL;
	}
	else if(p->prev)
	{
		p->prev->next=NULL;
		p->prev=NULL;
	}
	return p;
}

//вставка готового узла
void paste(list* l1, list* l2)
{
	list *next1;
	next1=l1->next;
	l2->prev=l1;
	if(l1->next)
	{
		l1->next=l2;		
		l2->next=next1;		
		next1->prev=l2;
	}
	else
	{
		l1->next=l2;
		l2->next=NULL;
	}
}
//смена мест двух соседних узлов
list *swapList(list *p) 
{
	list *k=p->next;
	list *tmp = delElem(p);//все указатели в NULL
	paste(k,tmp);// what ;  after what
	while(k->prev)
		k=k->prev;
	return k;
}

int main(void) {
	list *L = createList("1.txt");
	int flag = 0;	
	printList(L);
	printf("____________________\n");	
//пузырёк
	while (1) {
		while (L->next && !flag) {
			if (strlen(L->str) > strlen(L->next->str)) {
				swapList(L);
				flag = 1;
			} else L = L->next;
		}
		if (!flag) break;
		while (L->prev)
			L = L->prev;
		flag = 0;
	}
	
	while (L->prev)
		L = L->prev;

	printList(L);
	freeList(L);
	return 0;
}