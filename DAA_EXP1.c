#include<stdio.h>
#include<math.h>

double Factorial(double n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    double a;
    a=Factorial(n-1);
    return n*a;
}

double n3(double n)
{
    double cube;
    cube=pow(n,3);
    return cube;
}

double pow32n(double n)
{
    double result;
    result=pow(3.0/2.0,n);
    return result;
}

double lgn(double n)
{
    double result;
    result=log2(n);
    return result;
}

double lnlnn(double n)
{
    double result;
    result=log(log(n));
    return result;
}

double lglgn(double n)
{
    double result;
    result=log2(log2(n));
    return result;
}

double lg2n(double n)
{
    double result;
    result=pow(log2(n),2);
    return result;
}

double nlgn(double n)
{
    double result;
    result=n*log2(n);
    return result;
}

double n2n(double n)
{
    double result;
    result=n*pow(2,n);
    return result;
}

double en(double n)
{
    double result;
    result=exp(n);
    return result;
}

int main()
{
    printf("n      n^3      (3/2)^n      logn      loglogn      (lgn)^2      lglgn      nlgn      n(2^n)      e^n\n");
    for(int i=1; i<=100; i++)
    {
        printf("%lf     %lf       %lf           %lf        %lf            %lf          %lf",i,n3(i),pow32n(i),lgn(i),lnlnn(i),lg2n(i),lglgn(i));
        printf("        %lf        %lf            %lf",nlgn(i),n2n(i),en(i));

        if(i<=20)
        {
            double a;
            a=Factorial(i);
            printf("      %lf     %lf       %lf           %lf        %Lf            %lf          %lf",a,n3(a),pow32n(a),lgn(a),lnlnn(a),lg2n(a),lglgn(a));
            printf("      %lf        %lf            %Lf",nlgn(a),n2n(a),en(a));
        }
        printf("\n");
    }
}
