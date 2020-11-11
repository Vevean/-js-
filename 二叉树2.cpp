#include<stdio.h>
#include<malloc.h>
typedef struct node{
	struct node *lchild;
	char data;
	struct node *rchild;
}BTNode;
//创建二叉树
//销毁二叉树
//先序遍历
//中序遍历
//后序遍历
//输出二叉树
//求高度
//统计叶子节点数 
int creatBTNode(BTNode * &BT,char *str,int n){
	printf("%d ",n);
	char ch = str[n];
	printf("%c \n",ch);
	n++;
	if(ch!='\0')//'\0'对应的ASCII码是0，是ASCII码表中的第一个字符，即空字符；判断一个字符串是否结束的标志就是看是否遇到‘\0’。
		{
			if(ch=='^'){
				BT = NULL;
			}
			else{
				BT = new BTNode;
				BT->data=ch;
				n=creatBTNode(BT->lchild,str,n);
				n=creatBTNode(BT->rchild,str,n);
			}
		}
		return n;
}
void destroyBTNode(BTNode * &BT){
	if(BT!=NULL){
		destroyBTNode(BT->lchild);
		destroyBTNode(BT->rchild);
		free(BT);
		BT=NULL;
	}
}
void preOrder(BTNode * &BT){
	if(BT!=NULL){
		printf("%c",BT->data);
		preOrder(BT->lchild);
		preOrder(BT->rchild);
	}
}
void inOrder(BTNode * &BT){
	if(BT!=NULL){
		inOrder(BT->lchild);
		printf("%c",BT->data);
		inOrder(BT->rchild);
	}
}
void postOrder(BTNode * &BT){
	if(BT!=NULL){
		postOrder(BT->lchild);
		postOrder(BT->rchild);
		printf("%c",BT->data);
	}
}
void displayBTNode(BTNode * &BT){
	if(BT!=NULL){
		printf("%c",BT->data);
		displayBTNode(BT->lchild);
		displayBTNode(BT->rchild);
	}else{
		printf("^");
	}
}
int BTHeight(BTNode * &BT){
	int lchildh;
	int rchildh;
	int h;
	if(BT==NULL){
		return 0;
	}else{
		lchildh=BTHeight(BT->lchild);
		rchildh=BTHeight(BT->rchild);
		h=(lchildh>rchildh)?(lchildh+1):(rchildh+1);
		return h;
	}
}
int leaf(BTNode * &BT){
	int ans=0;
	if(BT!=NULL){
		leaf(BT->lchild);
		leaf(BT->rchild);
		if((BT->lchild==NULL)&&(BT->rchild==NULL)) ans++;
	}
	return ans;
}
int main(){
	BTNode *BT;
	printf("输入字符串: ");
	char *str=(char*)malloc(sizeof(char)*1024);
	scanf("%s",str);
	creatBTNode(BT,str,0);
	printf("二叉树建立成功\n");
	printf("二叉树为: ");
	displayBTNode(BT);
	printf("先序遍历为: ");
	preOrder(BT);
	int h = BTHeight(BT);
	printf("\n"); 
	printf("树的高度为: %d",h);
	printf("\n");
	printf("树的叶子结点数目为: ");
	int count=leaf(BT);
	printf("%d",count);
	printf("\n");
	destroyBTNode(BT);
	if(BT==NULL){
		printf("销毁成功");
	} 
	return 0;
}
