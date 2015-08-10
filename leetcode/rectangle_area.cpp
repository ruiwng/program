#include  <stdio.h>

int compute(int A, int B, int C, int D, int E, int F, int G, int H, int *num)
{
	int all_area = (C - A)*(D - B) + (G - E)*(H - F);
	int arry[4] = {0, 0, 0, 0};
	*num = 0; 
	if(A >= E && A <= G && B >= F && B <= H)
	{
		arry[0] = 1;
		++(*num);
	}
	if(C >= E && C <= G && B >= F && B <= H)
	{
		arry[1] = 1;
		++(*num);
	}
	if(C >= E && C <= G && D >= F && D <= H)
	{
		arry[2] = 1;
		++(*num);
	}
	if(A >= E && A <= G && D >= F && D <= H)
	{
		arry[3] = 1;
		++(*num);
	}
	if(*num == 4)
		all_area -= (C - A)*(D - B);
	else if(*num == 2)
	{
		if(arry[0] == 1 && arry[1] == 1)
			all_area -= (C - A)*(H - B);
		else if(arry[1] == 1 && arry[2] == 1)
			all_area -= (D - B)*(C - E);
		else if(arry[2] == 1 && arry[3] == 1)
			all_area -= (C - A) * (D - F);
		else
			all_area -= (D - B)*(G - A);
	}
	else if(*num == 1)
	{
		if(arry[0] == 1)
			all_area -= (G - A)*(H - B);
		else if(arry[1] == 1)
			all_area -= (C - E)*(H - B);
		else if(arry[2] == 1)
			all_area -= (C - E)*(D - F);
		else
			all_area -= (G - A)*(D - F);
	}
	return all_area;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int num;
	int area = compute(A, B, C, D, E, F, G, H, &num);
	if(num == 0)
		area = compute(E, F, G, H, A, B, C, D, &num);
	if(num == 0)
	{
		if(E > A && E < C && G > A && G < C && B > F && B < H && D > F && D < H)
			area -= (G - E)*(D - B);
		else if(A > E && A < G && C > E && C < G && F > B && F < D && H > B && H < D) 
			area -= (C - A)*(H - F);
	}
	return area;
}

int main()
{
	int result = computeArea(-5, -2, 5, 1, -3, -3, 3, 3);
	printf("%d\n", result);
	return 0;
}