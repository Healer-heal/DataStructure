#include<stdio.h>
typedef struct {
	int position;
	int start;
	int end;
}meet;

void sort(meet* meet1,int num) {    //�������ʱ�������������ǰ�� 
	int i,j,flag;
	meet t;
	for(i=0;i<num-1;i++) {
		flag=1;
		for(j=0;j<num-1-i;j++) {
			if(meet1[j].end>meet1[j+1].end) {
				t=meet1[j];
				meet1[j]=meet1[j+1];
				meet1[j+1]=t;
				flag=0;
			}
		}
	if(flag == 1 ) {
		break;
	}	
	}
}

int main()
{
	int num,i;
	printf("���������ĸ���:\n");
	scanf("%d",&num);
	meet list[num];
	meet t1;
	for(i=0;i<num;i++) {
		printf("������������š���ʼʱ�䡢��ֹʱ��(�ÿո�ֿ�)\n");
		scanf("%d",&list[i].position);
		scanf("%d",&list[i].start);
		scanf("%d",&list[i].end);
	}
	sort(list,num);//������Ľ���ʱ�䰴�մ�С������������ 
	t1=list[0];
	printf("%d�Ż���\n",list[0].position);
	for(i=1;i<num;i++) {
		if(list[i].end==t1.end) {
			continue;
		}
		if(list[i].start>=t1.end)	{
			t1=list[i];
			printf("%d�Ż���\n",list[i].position);
		}
	}
	return 0;
}
