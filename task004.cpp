#include <stdio.h>
#define D 3
#define M 4
void row_totals(const double r[D][M],double t[D]) {
    for(int i=0;i<D;i++){t[i]=0;for(int j=0;j<M;j++)t[i]+=r[i][j];}
}
void column_averages(const double r[D][M],double a[M]) {
    for(int j=0;j<M;j++){a[j]=0;for(int i=0;i<D;i++)a[j]+=r[i][j];a[j]/=D;}
}
void maximum_value(const double r[D][M],double *mx,int *di,int *mo) {
    *mx=r[0][0];*di=0;*mo=0;
    for(int i=0;i<D;i++)for(int j=0;j<M;j++)if(r[i][j]>*mx){*mx=r[i][j];*di=i;*mo=j;}
}
void deficient(const double r[D][M],const double avg[M]) {
    double state=0;for(int j=0;j<M;j++)state+=avg[j];state/=M;
    for(int i=0;i<D;i++){double total=0;for(int j=0;j<M;j++)total+=r[i][j];
        if(total<0.60*state*M)printf("District %d below 60%% threshold\n",i+1);}
}
int main(void) {
    const double r[D][M]={{10,20,30,40},{20,30,40,50},{5,10,15,20}};
    double t[D],a[M],mx;int di,mo;
    row_totals(r,t);column_averages(r,a);maximum_value(r,&mx,&di,&mo);
    for(int i=0;i<D;i++)printf("District %d total = %.1f\n",i+1,t[i]);
    for(int j=0;j<M;j++)printf("Month %d average = %.2f\n",j+1,a[j]);
    printf("Maximum = %.1f at district %d month %d\n",mx,di+1,mo+1);
    deficient(r,a);return 0;
}
