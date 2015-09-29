#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <algorithm>
using namespace std;

#define    NUM       110

struct point
{
	 int x, y;
};

int cross_product(const point &a, const point &b, const point &c)
{
	return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}

int dist(const point &lhs, const point &rhs)
{
	return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

point point_array[NUM];

struct point_cmp
{
	bool operator()(const point &lhs, const point &rhs) const
	{
		int direct = cross_product(point_array[0], lhs, rhs);
		if(direct != 0)
			return direct < 0;
		return dist(point_array[0], lhs) < dist(point_array[0], rhs);
	}
};

int main()
{
	int n;
	while(scanf("%d", &n) != EOF && n)
	{
		int min_point = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &point_array[i].x, &point_array[i].y);
			if(i != 0 && (point_array[i].y < point_array[min_point].y || (point_array[i].y == point_array[min_point].y && point_array[i].x < point_array[min_point].x)))
				min_point = i;
		}

		if(n == 1)
		{
			printf("0.00\n");
			continue;
		}
		else if(n == 2)
		{
			printf("%.2lf\n", 2 * sqrt(dist(point_array[0], point_array[1])));
			continue;
		}

		point temp = point_array[0];
		point_array[0] = point_array[min_point];
		point_array[min_point] = temp;
		sort(point_array + 1, point_array + n, point_cmp());

		vector<int> record;
		record.push_back(0);
		record.push_back(1);
		record.push_back(2);

		for(int i = 3; i < n; ++i)
		{
			while(true)
			{
				int x = record[record.size() - 2];
				int y = record[record.size() - 1];
				if(cross_product(point_array[y], point_array[x], point_array[i]) <= 0)
					record.pop_back();
				else
					break;
			}
			record.push_back(i);
		}

		double dist_sum = 0.0;

		int length = record.size();
		for(int i = 0; i < length - 1; ++i)
			dist_sum += sqrt(dist(point_array[record[i]], point_array[record[i + 1]]));
		dist_sum += sqrt(dist(point_array[record[0]], point_array[record[length - 1]]));

		printf("%.2lf\n", dist_sum);
	}
	return 0;
}