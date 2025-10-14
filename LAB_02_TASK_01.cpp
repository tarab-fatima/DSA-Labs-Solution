#include <iostream>

using namespace std;

void printND(int n)
{
	if(n==1)
	{
		cout<<"I";
	}
	else
	{

		for(int i=1;i<=n ; i++)
		{
			int j=i+1;

			cout<<"I"<<i;
			while(j<=n)
			{
				cout<<"U"<<j;
				j++;
			}
			cout<<"+ ";
		}
    }
    cout<<"0";

}
	
int main()
{

	printND(8);
}
