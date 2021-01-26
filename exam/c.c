#include <stdio.h>
#include <stdlib.h>
struct link {
	int num;
	struct link *next;
};

void arrange( struct link *, struct link *, int, int);	//学生需要完成的函数
void printList( struct link * );					//输出链表

void printList( struct link *h )	//输出链表
{	struct link *p = h->next;
	while ( p != NULL )
	{	printf( "%d, ", p->num );
		p = p->next;
	}
	printf("\n");
	return;
}

int main()
{
	int lowerlimit, upperlimit, m;
	struct link *hdA, *hdN, *q;
	
	hdA = (struct link *)malloc(sizeof(struct link));
	hdA->num = 0;
	hdA->next = NULL;	//建立带表头结点的空链表 hdA
	q = hdA;
	while( 1 )	//按照输入数据顺序建立链表
	{
		scanf( "%d", &m );
		if( m < 0 )		//输入非负整数，直到输入负数为止
			break;
		q->next = (struct link *)malloc(sizeof(struct link));
		q->next->num = m;
		q->next->next = NULL;
		q = q->next;
	}
	printf("haA = ");	printList( hdA );
	scanf( "%d,%d", &lowerlimit, &upperlimit );
	hdN = (struct link *)malloc(sizeof(struct link));
	hdN->num = 0;
	hdN->next = NULL;			//建立带表头结点的空链表 hdN
	arrange( hdA, hdN, lowerlimit, upperlimit );	//学生需编写的函数
	printf("haA = ");	printList( hdA );
	printf("haN = ");	printList( hdN );
	return 0;
}
void Insert(struct link *hC,struct link *node){
    while(hC->next!=NULL)hC=hC->next;
    hC->next = node;
}
void Work(struct link *hA, struct link *hC, int a, int b ){
	while(hA){
		if(hA->next){
			struct link *n = hA->next;
            if(n->num>a&&n->num<b){
                hA->next = n->next;
                n->next = NULL;
				//printf("%d %d %d\n", n->num,a,b);
				Insert(hC, n);
				break;
            }
		}
		hA = hA->next;
	}
}
int Check(struct link *hA,int a,int b){
	while(hA){
		if(hA->num>a&&hA->num<b)
			return 1;
		hA= hA->next;
	}
	return 0;
}
void arrange( struct link *hA, struct link *hC, int a, int b )
{
	int k = 0;
    while(Check(hA,a,b)){
		Work(hA, hC, a, b);
	}
}
/*
1 2 5 10 -1
0,2
*/