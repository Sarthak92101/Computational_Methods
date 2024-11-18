#include<stdio.h>
#include<math.h>
#define f(x) cos(x) - x * exp(x)
int main(){
    float x0,x1,x2,f0,f1,f2,e;
    int step=1;
    up:
    printf("Enter the value of x0:");
    scanf("%f",x0);
    
    printf("Enter the value of x1:");
    scanf("%f",x1);
    
    f0=f(x0);
    f1=f(x1);
    
    if(f1*f2>0){
        printf("Please change the value of x0 or x1");
        goto up;
    }
    
    printf("\nsteps\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    
    do{
    x2=(x0+x1)/2.0;
    f2=f(x2);
    printf("%d\t\t%f\t\t%f\t\t%f\t\t%f",step,x0,x1,x2,f2);
    if(f0*f2<0){
        x1=x2;
        f1=f2;
    }else{
        x0=f2;
        f0=f2;
    }
    step+=1;    
    }
    while(fabs(f2)>e);
    printf("root is %f",x2);
    return 0;
}







