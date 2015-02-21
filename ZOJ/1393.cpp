#include  <stdio.h>
#include  <string.h>

char cube[6][3][4];

void rotation(int index,bool left,char &up_1,char &up_2,char &up_3,
			  char &left_1,char &left_2,char &left_3,
			  char &right_1,char &right_2,char &right_3,
			  char &down_1,char &down_2,char &down_3)
{
	if(left)
	{
		//rotate the face counter-clockwise
		char temp=cube[index][0][0];
		cube[index][0][0]=cube[index][0][2];
		cube[index][0][2]=cube[index][2][2];
		cube[index][2][2]=cube[index][2][0];
		cube[index][2][0]=temp;
		temp=cube[index][1][0];
		cube[index][1][0]=cube[index][0][1];
		cube[index][0][1]=cube[index][1][2];
		cube[index][1][2]=cube[index][2][1];
		cube[index][2][1]=temp;
		//rotate the boundary 
		temp=up_1;
		up_1=right_1;
		right_1=down_3;
		down_3=left_3;
		left_3=temp;

		temp=up_2;
		up_2=right_2;
		right_2=down_2;
		down_2=left_2;
		left_2=temp;

		temp=up_3;
		up_3=right_3;
		right_3=down_1;
		down_1=left_1;
		left_1=temp;
	}
	else
	{
	    //rotate the face clockwise
		char temp=cube[index][0][0];
		cube[index][0][0]=cube[index][2][0];
		cube[index][2][0]=cube[index][2][2];
		cube[index][2][2]=cube[index][0][2];
		cube[index][0][2]=temp;
		temp=cube[index][1][0];
		cube[index][1][0]=cube[index][2][1];
		cube[index][2][1]=cube[index][1][2];
		cube[index][1][2]=cube[index][0][1];
		cube[index][0][1]=temp;
		//rotate the boundary
		temp=up_1;
		up_1=left_3;
		left_3=down_3;
		down_3=right_1;
		right_1=temp;

		temp=up_2;
		up_2=left_2;
		left_2=down_2;
		down_2=right_2;
		right_2=temp;

		temp=up_3;
		up_3=left_1;
		left_1=down_1;
		down_1=right_3;
		right_3=temp;
	}
}
int main()
{
	char str[20];
	while(scanf("%s",str)!=EOF)
	{
		if(strcmp(str,"ENDOFINPUT")==0)
			break;
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				scanf("%s",&cube[0][j][k]);
		for(int i=0;i<3;++i)
		{
			for(int j=1;j<5;++j)
			{
				for(int k=0;k<3;++k)
					scanf("%s",&cube[j][i][k]);
			}
		}
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				scanf("%s",&cube[5][j][k]);
		while(scanf("%s",str)!=EOF)
		{
			if(strcmp(str,"END")==0)
				break;
			char rotate[10];
			scanf("%s",rotate);
			if(strcmp(str,"front")==0)
				rotation(2,strcmp(rotate,"left")==0,
					cube[0][2][0],cube[0][2][1],cube[0][2][2],
					cube[1][0][2],cube[1][1][2],cube[1][2][2],
					cube[3][0][0],cube[3][1][0],cube[3][2][0],
					cube[5][0][0],cube[5][0][1],cube[5][0][2]);
			else if(strcmp(str,"left")==0)
				rotation(1,strcmp(rotate,"left")==0,
					cube[0][0][0],cube[0][1][0],cube[0][2][0],
					cube[4][0][2],cube[4][1][2],cube[4][2][2],
					cube[2][0][0],cube[2][1][0],cube[2][2][0],
					cube[5][2][0],cube[5][1][0],cube[5][0][0]);
			else if(strcmp(str,"right")==0)
				rotation(3,strcmp(rotate,"left")==0,
					cube[0][2][2],cube[0][1][2],cube[0][0][2],
					cube[2][0][2],cube[2][1][2],cube[2][2][2],
					cube[4][0][0],cube[4][1][0],cube[4][2][0],
					cube[5][0][2],cube[5][1][2],cube[5][2][2]);
			else if(strcmp(str,"back")==0)
				rotation(4,strcmp(rotate,"left")==0,
					cube[0][0][2],cube[0][0][1],cube[0][0][0],
					cube[3][0][2],cube[3][1][2],cube[3][2][2],
					cube[1][0][0],cube[1][1][0],cube[1][2][0],
					cube[5][2][2],cube[5][2][1],cube[5][2][0]);
			else if(strcmp(str,"top")==0)
				rotation(0,strcmp(rotate,"left")==0,
					cube[4][0][2],cube[4][0][1],cube[4][0][0],
					cube[1][0][0],cube[1][0][1],cube[1][0][2],
					cube[3][0][2],cube[3][0][1],cube[3][0][0],
					cube[2][0][0],cube[2][0][1],cube[2][0][2]);
			else
				rotation(5,strcmp(rotate,"left")==0,
					cube[2][2][0],cube[2][2][1],cube[2][2][2],
					cube[1][2][2],cube[1][2][1],cube[1][2][0],
					cube[3][2][0],cube[3][2][1],cube[3][2][2],
					cube[4][2][2],cube[4][2][1],cube[4][2][0]);
		}
		bool success=true;
		for(int i=0;success&&i<6;++i)
		{
			char color=cube[i][0][0];
			for(int j=0;success&&j<3;++j)
			{
				for(int k=0;success&&k<3;++k)
					if(cube[i][j][k]!=color)
						success=false;
			}
		}
		if(success)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}