#include<iostream>
#include <cstring>  


using namespace std;

class Array_ND
{
	private:
		int N;
		int* p;
		int size;
		int dimensions[100];
		
		
	public:	
	
	    Array_ND ( int n, int dim_size[])
		{
            this->N = n;
            for(int i=0 ; i<n ;i++)
            {
            	size*=dim_size[i];
			}
			for(int i=0 ; i<n ;i++)
            {
            	this->dimensions[i] = dim_size[i];
			}
	    	p = new int [size];
	    	
	    	for (int i = 0; i < size; i++)
			{
				p[i] = 0;
			}
		}
		
		Array_ND (const Array_ND & other)
		{
	    	this->N = other.N ;
            this->size =other.size;
	    	this->p = new int [size];
	    	for(int i=0 ; i<N ;i++)
            {
            	this->dimensions[i] = other.dimensions[i];
			}
	    	memcpy(p,other.p,size*(sizeof(int)));

		}
		
		~ Array_ND ()
		{
			delete[] p;
			
		}
		
		int getIndexValue(int arr[])
		{
			int x=0;
			if(N==1)
			{
				x=arr[0];
			}
			else
			{
				int D=1;
				for(int i=1;i<=N ; i++)
				{
					int j=i+1;
			
					
					while(j<=N)
					{
						D *= this->dimensions[j]  ;
					}
					int y= arr[i]*D;
					x+= y;
				}
			}
			return p[x];

		}
		
		void setIndexValue(int arr[],int val)
		{
			int x=0;

			if(N==1)
			{
				x=arr[0];
			}
			else
			{
				int D=1;
				for(int i=1;i<=N ; i++)
				{
					int j=i+1;
			
					while(j<=N)
					{
						D *= this->dimensions[j]  ;
					}
					int y= arr[i]*D;
					x+= y;
				}
			}
			p[x]=val;
		}
		void printArray()
		{
			
			
		}
		
	
		
		int* addressOfIndex (int arr[]) 
		{
			int x=0;

			if(N==1)
			{
				x=arr[0];
			}
			else
			{
				int D=1;
				for(int i=1;i<=N ; i++)
				{
					int j=i+1;
			
					while(j<=N)
					{
						D *= this->dimensions[j]  ;
					}
					int y= arr[i]*D;
					x+= y;
				}
			}
			return p + x;
		}  
		
	
		
}; 

int main()
{
	int di_size[3]={5,3,10};
	
	Array_ND T(3, di_size);

    int index_set1[3] = {4,2,8};
    int index_set2[3] = {1,1,1};
    int index_set3[3] = {4,2,9};
    int index_set4[3] = {2,2,2};
    int index_set5[3] = {3,3,3};
   
    T.setIndexValue(index_set1 , 5);
    T.setIndexValue(index_set2 , 4);
    T.setIndexValue(index_set3 , 6);
    T.setIndexValue(index_set4 , 4); 
    T.setIndexValue(index_set5 , 7) ;

    cout << "Full Array:"<<endl;
    T.printArray();



    cout << "Address of [4][2][8]: " << T.addressOfIndex(index_set1) << endl;

    cout<<"The value at [3][3][3] " << T.getIndexValue(index_set5) <<endl;
    

    return 0;
	
}
