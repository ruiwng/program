#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int a_win = 0, b_win = 0;
		for(int i = 0;i < n; ++i)
		{
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(b == a + c && d != a + c)
				++a_win;
			else if(d == a + c && b != a + c)
				++b_win;
		}
		printf("%d %d\n", b_win, a_win);
	}
	return 0;
}