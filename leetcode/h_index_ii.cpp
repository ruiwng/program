int hIndex(int* citations, int citationsSize) {
        int result = 0;
		for(int i = citationsSize - 1; i >= 0; --i)
		{
			int temp = citationsSize - i;
			if((i != 0 && citations[i] >= temp && citations[i - 1] <= temp) ||
				(i == 0 && citations[i] >= temp))
			{
				result = temp;
				break;
			}
		}
		return result;
}

int main()
{

}