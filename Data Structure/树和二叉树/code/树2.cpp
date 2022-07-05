//哈夫曼编码与解码
#include <bits/stdc++.h>
#define N 100		//叶子结点最大数量
#define M 2 * N - 1 //所有结点最大数量

typedef struct HTNode //结点
{
	int weight;					//权重
	int parent, lchild, rchild; //双亲、左右孩子结点
	char data;					//字符
} HTNode, HT[M + 1];
HT ht;

typedef struct HCNode
{
	int bit[200]; //编码
	int start;	  //该编码的末尾位置
} HCNode, HC[100];
HC hc;

int str[1000] = {0};
int len = 0;

void select(int pos, int *x1, int *x2)
{
	int min = 100000;
	for (int i = 1; i <= pos; i++)
	{
		if (ht[i].weight < min && ht[i].parent == 0) //注意判断该节点必须没有双亲节点
		{
			min = ht[i].weight;
			*x1 = i;
		}
	}
	min = 100000;
	for (int i = 1; i <= pos; i++)
	{
		if (i == *x1)
			continue;
		if (ht[i].weight < min && ht[i].parent == 0) //注意判断该节点必须没有双亲节点
		{
			min = ht[i].weight;
			*x2 = i;
		}
	}
}

void initTree(int n)
{
	int x1, x2;
	for (int i = 1; i <= 2 * n - 1; i++) //对所有结点初始化
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++) //叶子结点的data域
	{
		getchar();
		scanf("%c", &ht[i].data);
	}
	for (int i = 1; i <= n; i++) //叶子结点的weight域
	{
		scanf("%d", &ht[i].weight);
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		select(i, &x1, &x2); //找到序号为i的结点之前的两个最小权重结点
		//两个最小权重结点组成一棵树，以i处的结点为根节点，直至循环结束所有结点组成一棵树
		ht[i + 1].weight = ht[x1].weight + ht[x2].weight;
		ht[x1].parent = i + 1;
		ht[x2].parent = i + 1;
		ht[i + 1].lchild = x1;
		ht[i + 1].rchild = x2;
	}
}

void encode(int n)
{
	for (int i = 1; i <= n; i++)
	{
		hc[i].start = n;	  //编码长度最多为n
		int c = i;			  //当前叶子结点序号
		int p = ht[c].parent; //叶子结点双亲序号
		while (p)
		{
			if (ht[p].lchild == c)
				hc[i].bit[hc[i].start] = 0;
			else
				hc[i].bit[hc[i].start] = 1;
			hc[i].start--;	  //准备录入下一位编码
			c = p;			  //上溯
			p = ht[c].parent; //上溯，直到while循环结束
		}
		hc[i].start++; //while循环中，start多退了一位。
	}
}

void printCode(int n)
{
	len = 0;
	char code[1000];
	scanf("%s", code);
	for (int i = 0; i < strlen(code); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (code[i] == ht[j].data)
			{
				for (int k = hc[j].start; k <= n; k++)
				{
					printf("%d", hc[j].bit[k]);
					str[len] = hc[j].bit[k]; //存储待破解编码
					len++;
				}
			}
		}
	}
	printf("\n");
}

void decode(int n) //译码并输出
{
	int t;
	for (int i = 0; i < len;)
	{
		t = 2 * n - 1;								   //根节点
		while (ht[t].lchild != 0 && ht[t].rchild != 0) //当找到叶子节点时，退出循环
		{
			if (str[i] == 0)
				t = ht[t].lchild;
			else
				t = ht[t].rchild;
			i++;
		}
		printf("%c", ht[t].data);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	initTree(n);
	encode(n);
	printCode(n);
	decode(n);
	return 0;
}