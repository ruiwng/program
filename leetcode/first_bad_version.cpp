// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int lower = 1;
	int higher = n;
	while(lower < higher)
	{
		int middle = lower+ ((higher - lower ) >> 1);
		if(middle == lower || middle == higher)
		    break;
		if(isBadVersion(middle))
			higher = middle;
		else 
			lower = middle;
	}
	if(isBadVersion(lower))
	   return lower;
	else
	    return higher;
}

int main()
{

}