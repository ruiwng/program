#include  <stdio.h>
#include  <math.h>
#include  <vector>
using namespace std;

struct student
{
    int absence;
    int bonus;
    double avg;
    student(int absen=0,int b=0,int a=0):absence(absen),bonus(b),avg(a){
        
    }
};

int main()
{
    int num_class;
    printf("MAKING THE GRADE OUTPUT\n");
    freopen("test.txt","r",stdin);
    while(scanf("%d",&num_class)!=EOF)
    {
        for(int i=0;i<num_class;++i)
        {
            int num_student,num_test;
            double mean=0.0;
            scanf("%d%d",&num_student,&num_test);
            vector<student> student_array;
            student_array.reserve(num_student);
            for(int j=0;j<num_student;++j)
            {
                int min_grad=100;
                int sum=0;
                student stu;
                for(int k=0;k<num_test;++k)
                {
                    int temp;
                    scanf("%d",&temp);
                    sum+=temp;
                    if(temp<min_grad)
                        min_grad=temp;
                }
                if(num_test>2)
                    stu.avg=static_cast<double>((sum-min_grad))/(num_test-1);
                else
                    stu.avg=static_cast<double>(sum)/num_test;
                int bonus;
                scanf("%d",&stu.bonus);
                mean+=stu.avg;
                scanf("%d",&stu.absence);
                student_array.push_back(stu);
            }
            mean/=num_student;
            double sd=0.0;
            for(int j=0;j<num_student;++j)
                sd+=(student_array[j].avg-mean)*(student_array[j].avg-mean);

            for(int j=0;j<num_student;++j)
                student_array[j].avg+=student_array[j].bonus/2*3;
            
            sd=sqrt(sd/num_student);
            int grad_sum=0;
            for(int i=0;i<num_student;++i)
            {
                int current_grad;
                if(student_array[i].avg>=mean+sd)
                    current_grad=4;
                else if(student_array[i].avg>=mean)
                    current_grad=3;
                else if(student_array[i].avg>=mean-sd)
                    current_grad=2;
                else
                    current_grad=1;
                current_grad-=student_array[i].absence/4;
                if(current_grad<0)
                    current_grad=0;
                if(student_array[i].absence==0)
                {
                    if(++current_grad>4)
                        current_grad=4;
                }
                grad_sum+=current_grad;
            }
            printf("%.1lf\n",static_cast<double>(grad_sum)/num_student);
        }        
    }
    printf("END OF OUTPUT\n");
    return 0;
}
