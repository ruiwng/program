#include  <unordered_map>
using namespace std;

struct list_record
{
	int key;
	int value;
	list_record* prev;
	list_record* next;
	list_record(int k=0,int v=0):key(k),value(v),prev(NULL),next(NULL){}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
		this->current_size=0;
		list_start=NULL;
		list_end=NULL;
    }
    
    int get(int key) {
        LRU_map_iterator iter=LRU_cache.find(key);
		if(iter==LRU_cache.end())//didn't find the key
			return -1;
		else
		{//find the key and erase it from the list and push it back to the end of the list
			
			list_record* p=iter->second;
			if(p!=list_end)
			{
				list_erase(p);
				list_push(p);
			}			
			return p->value;
		}
    }
    void set(int key, int value) {
        LRU_map_iterator iter=LRU_cache.find(key);
		if(iter!=LRU_cache.end())
		{
			//find the key and erase it from the list and push it back to the end of the list
			list_record* p=iter->second;
			p->value=value;
			if(p!=list_end)
			{
				list_erase(p);
				list_push(p);
			}
		}
		else
		{
			//doesn't find the key, it's a new key
			list_record* p=new list_record(key,value);
			LRU_cache.insert(make_pair(key,p));
			list_push(p);
			if(++current_size>capacity)//the capacity of the LRU exceeded, so the least used element, that is, the element pointed to by list_start will be poped. at the same time, erase the record in the hash map.
			{
				LRU_cache.erase(list_start->key);
				--current_size;
				list_pop();
			}
		}
    }
private:
    void list_erase(list_record* p)//erase the element pointed to by p.
	{
		if(p->prev!=NULL)
		{
		    p->prev->next=p->next;
			p->next->prev=p->prev;
		}
		else
		{
			list_start=p->next;
			list_start->prev=NULL;
		}
	}
	void list_push(list_record* p)// push the element pointed to by p to the end of the link list.
	{
		if(list_start==NULL)
			list_start=list_end=p;
		else
		{
			p->prev=list_end;
			list_end->next=p;
			list_end=p;
		}
	}
	void list_pop()//erase the first element of the link list.
	{
		list_record* p=list_start;
		list_start=list_start->next;
		delete p;
	}
private:
	list_record* list_start;
	list_record* list_end;
	typedef unordered_map<int,list_record*> LRU_map;
	typedef LRU_map::iterator LRU_map_iterator;
	int current_size;
	LRU_map LRU_cache;
	int capacity;
};

int main()
{
	LRUCache cache(2);
	cache.set(2,1);
	cache.set(1,1);
	int result=cache.get(2);
	cache.set(4,1);
	result=cache.get(1);
	result=cache.get(2);
	return 0;
}