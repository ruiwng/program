#include  <stdio.h>
#include  <string.h>
#include  <math.h>

//f(n)=f(n-1)*f(0)+f(n-2)*f(1)+f(n-3)*f(n-2)....+f(0)*f(n-1) (n>=3)
//f(2)=2;
//f(1)=1;

int arr_length[20]={1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,
	129644790,477638700,1767263190};
int start_pos[20]={0,1,2,4,9,23,65,197,626,2056,6918,23714,82500,290512,1033412,3707852,13402697,48760367,
	178405157,656043857};

struct tree_node
{
	tree_node* left_child;
	tree_node* right_child;
	tree_node():left_child(NULL),right_child(NULL){}
};

tree_node* generate_tree(int n)
{
	if(n==0)
		return NULL;
	if(n==1)
		return new tree_node;
	int lower_bound=1;
	int high_bound=19;
	int median;
	while(lower_bound<=high_bound)
	{
		median=(lower_bound+high_bound)>>1;
		if(start_pos[median]>n)
			high_bound=median-1;
		else if(start_pos[median]<n)
			lower_bound=median+1;
		else
			break;
	}
	if(start_pos[median]>n)
		--median;
	n-=start_pos[median];
	int sum=0;
	int left_count=0,right_count=0;
	for(;left_count<median;++left_count)
	{
		sum+=arr_length[left_count]*arr_length[median-1-left_count];
		if(sum>n)
		{
			sum-=arr_length[left_count]*arr_length[median-1-left_count];
			break;
		}
	}
	n-=sum;
	right_count=median-1-left_count;
	int left_number=start_pos[left_count];
	int right_number=start_pos[right_count];
	while(n>=arr_length[right_count])
	{
		++left_number;
		n-=arr_length[right_count];
	}
	right_number+=n;
	tree_node* current_node=new tree_node;
	current_node->left_child=generate_tree(left_number);
	current_node->right_child=generate_tree(right_number);
	return current_node;
}

void inorder(tree_node* n,char* dest)
{
	if(n==NULL)
	    return;
	char temp[100];
	memset(temp,0,sizeof(temp));
	inorder(n->left_child,temp);
	if(temp[0]!='\0')
	{
		strcpy(dest,"(");
		strcat(dest,temp);
		strcat(dest,")");
	}
	strcat(dest,"X");
	memset(temp,0,sizeof(temp));
	inorder(n->right_child,temp);
	if(temp[0]!='\0')
	{
		strcat(dest,"(");
		strcat(dest,temp);
		strcat(dest,")");
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		tree_node* head=generate_tree(n);
		char str[10000];
		memset(str,0,sizeof(str));
		inorder(head,str);
		printf("%s\n",str);
	}
	return 0;
}