#include  <stdio.h>
#include  <map>
#include  <vector>
#include  <algorithm>
using namespace std;
struct record
{
    int number;
    int play_count;
    int KILL;
    int ERR;
    int HIT;
    int BLOCK;
    int DIG;
    record(int n=0,int p=1,int K=0,int E=0,int H=0,int B=0,int D=0):number(n),play_count(p),KILL(K),ERR(E),HIT(0),BLOCK(B),
                                                    DIG(D){
        
    }
    bool operator<(const record& r) const
    {
        return this->number<r.number;
    }
};

int main()
{
    char operation[5];
    vector<record> record_array;
    map<int,int> pos_record;
    int index=0;
    int KILL_count=0,ERR_count=0,HIT_count=0,BLOCK_count=0,DIG_count=0;
    int game_number=0;
    freopen("text.txt","r",stdin);
    while(scanf("%s",operation)!=EOF)
    {
        if(operation[0]=='C')
        {
            ++game_number;
            int num_player;
            scanf("%d",&num_player);
            for(int i=0;i<num_player;++i)
            {
                int temp;
                scanf("%d",&temp);
                map<int,int>::iterator iter=pos_record.find(temp);
                if(iter!=pos_record.end())
                    ++record_array[iter->second].play_count;
                else
                {
                    pos_record.insert(make_pair(temp,index++));
                    record_array.push_back(record(temp));
                }
            }
        }
        else if(operation[0]=='R')
        {
            printf("Player  Hit Pct    KPG      BPG      DPG\n");
            printf("-----------------------------------------\n");
            sort(record_array.begin(),record_array.end());
            int len=record_array.size();
            for(int i=0;i<len;++i)
            {
                double hit_percent=0.0;
                int t=record_array[i].KILL+record_array[i].ERR+record_array[i].HIT;
                if(t!=0)
                    hit_percent=static_cast<double>(record_array[i].KILL-record_array[i].ERR)/t;
                printf("%02d   %+9.3lf%9.3lf%9.3lf%9.3lf\n",record_array[i].number,
                       hit_percent,static_cast<double>(record_array[i].KILL)/record_array[i].play_count,static_cast<double>(record_array[i].BLOCK)/record_array[i].play_count,static_cast<double>(record_array[i].DIG)/record_array[i].play_count);
            }
            double sum_percent=0.0;
            int s=KILL_count+ERR_count+HIT_count;
            if(s!=0)
                sum_percent=static_cast<double>(KILL_count-ERR_count)/s;
            printf("team %+9.3lf%9.3lf%9.3lf%9.3lf\n\n",sum_percent,static_cast<double>(KILL_count)/game_number,static_cast<double>(BLOCK_count)/game_number,static_cast<double>(DIG_count)/game_number);
            record_array.clear();
            index=0;
            pos_record.clear();
            KILL_count=ERR_count=HIT_count=BLOCK_count=DIG_count=0;
            game_number=0;
        }
        else
        {
            int temp;
            scanf("%d",&temp);
            switch(operation[0])
            {
            case 'H':
                ++HIT_count;
                ++record_array[pos_record[temp]].HIT;
                break;
            case 'K':
                ++KILL_count;
                ++record_array[pos_record[temp]].KILL;
                break;
            case 'E':
                ++ERR_count;
                ++record_array[pos_record[temp]].ERR;
                break;
            case 'D':
                ++DIG_count;
                ++record_array[pos_record[temp]].DIG;
                break;
            case 'B':
                ++BLOCK_count;
                ++record_array[pos_record[temp]].BLOCK;
            }
        }
    }
    return 0;
}
