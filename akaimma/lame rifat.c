#include<stdio.h>
//void change_value(int *q);
void change_value(int *q)
{
    int *p[]= {q+3,q+2,q+1,q};
    //printf("*p[0]=%d p=%d db_p=%d **db_p=%d *p[2]=%d **(p+3)=%d",*p[0],p,db_p,*p[2],**(p+3),**db_p);
    int **db_p=p;
    printf("*p[0]=%d p=%d db_p=%d **db_p=%d *p[2]=%d **(p+3)=%d *(*p-1)=%d *p-1=%d\n",*p[0],p,db_p,*p[2],**(p+3),**db_p,*(*p-1),(*p-1));
    *(*p-1)=(*p[0])++;
    printf("*p[0]=%d p=%d db_p=%d **db_p=%d *p[2]=%d **(p+3)=%d *(*p-1)=%d (*p-1)=%d\n",*p[0],p,db_p,*p[2],**(p+3),**db_p,*(*p-1),(*p-1));
    *p[2]=db_p - p;
    printf("*p[0]=%d p=%d db_p=%d **db_p=%d *p[2]=%d **(p+3)=%d *(*p-1)=%d (*p-1)=%d\n",*p[0],p,db_p,*p[2],**(p+3),**db_p,*(*p-1),(*p-1));
    **(p+3)= **db_p + 5;
    printf("*p[0]=%d p=%d db_p=%d **db_p=%d *p[2]=%d **(p+3)=%d *(*p-1)=%d (*p-1)=%d\n",*p[0],p,db_p,*p[2],**(p+3),**db_p,*(*p-1),(*p-1));
    return;
}
int main()
{
    int arr[5]= {10,20,30,40};
    int i;
    change_value(arr);
    for(i=0; i<4; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
