# include <stdio.h>
# include <malloc.h>

struct node
{
	int inf;
	struct node *lchild;
	struct node *rchild;
}*root;



void find(int item,struct node **pr,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*pr=NULL;
		return;
	}
	if(item==root->inf) /*item is at root*/
	{
		*loc=root;
		*pr=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->inf)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->inf)
		{       *loc=ptr;
			*pr=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->inf)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *pr=ptrsave;
}/*End of find()*/

void insert(int item)
{       struct node *tmp,*prent,*location;
	find(item,&prent,&location);
	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->inf=item;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(prent==NULL)
		root=tmp;
	else
		if(item<prent->inf)
			prent->lchild=tmp;
		else
			prent->rchild=tmp;
}/*End of insert()*/


void case_a(struct node *pr,struct node *loc )
{
	if(pr==NULL) /*item to be deleted is root node*/
		root=NULL;
	else
		if(loc==pr->lchild)
			pr->lchild=NULL;
		else
			pr->rchild=NULL;
}/*End of case_a()*/

void case_b(struct node *pr,struct node *loc)
{
	struct node *child;

	/*Initialize child*/
	if(loc->lchild!=NULL) /*item to be deleted has lchild */
		child=loc->lchild;
	else                /*item to be deleted has rchild */
		child=loc->rchild;

	if(pr==NULL )   /*Item to be deleted is root node*/
		root=child;
	else
		if( loc==pr->lchild)   /*item is lchild of its prent*/
			pr->lchild=child;
		else                  /*item is rchild of its prent*/
			pr->rchild=child;
}/*End of case_b()*/

void case_c(struct node *pr,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*prsuc;

	/*Find inorder successor and its prent*/
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	prsuc=ptrsave;

	if(suc->lchild==NULL && suc->rchild==NULL)
		case_a(prsuc,suc);
	else
		case_b(prsuc,suc);

	if(pr==NULL) /*if item to be deleted is root node */
		root=suc;
	else
		if(loc==pr->lchild)
			pr->lchild=suc;
		else
			pr->rchild=suc;

	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}/*End of case_c()*/
int del(int item)
{
	struct node *prent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&prent,&location);
	if(location==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(location->lchild==NULL && location->rchild==NULL)
		case_a(prent,location);
	if(location->lchild!=NULL && location->rchild==NULL)
		case_b(prent,location);
	if(location->lchild==NULL && location->rchild!=NULL)
		case_b(prent,location);
	if(location->lchild!=NULL && location->rchild!=NULL)
		case_c(prent,location);
	free(location);
}/*End of del()*/

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->inf);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder()*/

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->inf);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->inf);
	}
}/*End of postorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->inf);
		display(ptr->lchild, level+1);
	}/*End of if*/
}/*End of display()*/
main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Display\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			postorder(root);
			break;
		 case 6:
			display(root,1);
			break;
		 case 7:
            break;
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/