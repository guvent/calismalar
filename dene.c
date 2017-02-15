#include<stdio.h>
#include<math.h>

int ustal(int,int);

int main()
{

  int a = 1394;
  int b = 2011;
  int c = 0;

	c = ustal(a,3);

  printf("Sonuc : %i\n",c);

  return 0;
}






int ustal(int x,int y)
{
	for(int i=1;i<y;i++)
	{
		x = x * x;
	}
	

	return x;
}

int n(int x,int y)
{
	int z;
	z= x*y;
	return z;
	
}

int f(int x,int y)
{
	int z;
	z=(x-1)*(y-1);
	return z;
}

int d(int k,int f,int e)
{
	int z;
	z = (k*f+1) / e;
	return z;
}

int p(int e,int n,int mj)
{
	int z;
	z = (mj^e) % n;
	return z;

}

int g(int p,int d,int n)
{
	int z;
	z = (p ^ n);
	

	return z;
	
}



