struct children
{
	int rating;
	int index;
	children():rating(0),index(0){}
	bool operator<(const children& c) const
	{
		return this->rating<c.rating;
	}
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<children> children_array(ratings.size());
		vector<int> candy_array(ratings.size());
		for(int i=0;i<ratings.size();++i)
		{
			children_array[i].index=i;
			children_array[i].rating=ratings[i];
		}
		sort(children_array.begin(),children_array.end());
		int candy_sum=0;
		for(int i=0;i<ratings.size();++i)
		{
			int temp1=1,temp2=1;
			if(children_array[i].index>0)
			{
				int left=children_array[i].index-1;
				if(ratings[left]<children_array[i].rating)
					temp1=candy_array[left]+1;
			}
			if(children_array[i].index<ratings.size()-1)
			{
				int right=children_array[i].index+1;
				if(ratings[right]<children_array[i].rating)
					temp2=candy_array[right]+1;
			}
			candy_array[children_array[i].index]=max(temp1,temp2);
			candy_sum+=candy_array[children_array[i].index];
		}
		return candy_sum;
    }
};