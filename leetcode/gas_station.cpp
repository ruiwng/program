
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int current_gas=gas[0];
	int start=0;
	int end=0;
	while(true)
	{
		while(true)
		{
			current_gas-=cost[end];
			if(++end==gasSize)
				end=0;
			if(current_gas<0)
				break;
			if(end==start)
				return start;
			current_gas+=gas[end];
		}
		while(current_gas<0)
		{
			current_gas-=gas[start];
			current_gas+=cost[start];
			if(++start==gasSize)
				return -1;
		}
		current_gas+=gas[end];
	}
}

int main()
{
	int gas[1]={4};
	int cost[1]={5};
	int result=canCompleteCircuit(gas,1,cost,1);
	return 0;
}