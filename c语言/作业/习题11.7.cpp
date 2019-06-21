#include <stdio.h>
#include <stdlib.h>

struct List
{
	int val;
	struct List *next = 0;
};

inline void emplace_front(struct List *before_begin,int _val);

int main()
{
	struct List *L = (struct List*)calloc(1, sizeof(struct List));
	struct List *NEW = (struct List*)calloc(1, sizeof(struct List));
	printf("输入若干个正整数(以-1结尾):\n");
	int val;
	while (1)
	{
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}
		if (val > 0)
		{
			emplace_front(L, val);
		}
	}
	struct List *i;
	for (i = L->next; i; i = i->next)
	{
		if (i->val % 2)
		{
			emplace_front(NEW, i->val);
		}
	}
	printf("奇数有:\n");
	for (i = NEW->next; i; i = i->next)
	{
		printf("%d ", i->val);
	}
	printf("\n");
	return 0;
}

void emplace_front(struct List *before_begin, int _val)
{
	struct List *create = (struct List*)calloc(1, sizeof(struct List));
	create->val = _val;
	create->next = before_begin->next;
	before_begin->next = create;
}
