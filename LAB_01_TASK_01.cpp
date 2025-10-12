#include<iostream>
#include<cmath>

using namespace std;
class Term{
	
	public:
		int coefficient;
		int power;
};

class Polynomial 
{
	
	protected:
	    Term *A ;
		int term_no;
		int degree;
		
	public:
		
	Polynomial()
	{
		A= new Term [10];
		term_no=0;
		
	}
	Polynomial(const Polynomial& other)
	{
		term_no = other.term_no;
		for(int i=0 ; i<=term_no ;i++)
		{
			A[i].coefficient=other.A[i].coefficient;
			A[i].power=other.A[i].power;
		}
	}
	
	
	void addTerm(int coeff=0, int pow=0) 
	{
		A[term_no].coefficient=coeff;
	    A[term_no].power=pow;
		term_no += 1;
	}
	
	int getDegree() 
	{
		
		for(int i=0 ; i<=term_no ;i++)
		{
			if(A[i].power>degree)
			{
				degree=A[i].power;
			}
		}
		return degree;
	 } 
	int getCoefficient(int pow)
	{
		for(int i=0 ; i<=term_no ;i++)
		{
			if(A[i].power == pow)
			{
				return A[i].coefficient;
			}
		}
	}
	
	Polynomial derivative()
	{
		Polynomial X;
		for(int i=0 ; i<=term_no ;i++)
		{
			if(A[i].power != 0)
			{
				int co =  A[i].coefficient*A[i].power;
			    int pow = A[i].power-1;
			    X.addTerm(co , pow);
			}	
		}	
		return X;
	} 
	
	Polynomial antiDerivative() 
	{
		Polynomial X;
		for(int i=0 ; i<=this->term_no ;i++)
		{
			int co =  A[i].coefficient/(A[i].power+1);
			int pow = A[i].power+1;
			X.addTerm(co , pow);
				
		}	
		return X;
		
		
	} 
	
	void addToCoefficient(int co,int pow)
	{
		for(int i=0 ; i<=term_no ;i++)
		{
			if(A[i].power == pow)
			{
				A[i].coefficient += co;
			}
		}
	}
	
	void clear() 
	{

		for(int i=0 ; i<=term_no ;i++)
		{
			A[i] = {0};

		}
		
	}
	void setCoefficient( int newCoefficient, int pow=0)  
	{
		for(int i=0 ; i<=term_no ;i++)
		{
			if(A[i].power == pow)
			{
				A[i].coefficient = newCoefficient;
			}
		}
		
	}
	
	int operator()(int value)
	{
		int val=0;
		
		for(int i=0 ; i<=term_no ;i++)
		{
			val += A[i].coefficient*(pow(value,A[i].power));
		}
		
		return val;
	}
	
	friend ostream& operator<<(ostream &out, const Polynomial &p)
	{
		for(int i=0 ; i< p.term_no ;i++)
		{
			cout<<p.A[i].coefficient<<"x^"<<p.A[i].power<<" + ";
		}
		cout<<endl;
		
	}
	
	~Polynomial()
	{
		delete[] A;
	}
	
	Polynomial operator+(const Polynomial &other)
	{
		Polynomial y;
		int x = 0;

		for(int i=0 ; i<= this->term_no ;i++)
		{
			for(int j=0 ; j<= other.term_no ;j++)
		    {
		    	if(this->A[i].power == other.A[j].power )
		    	{
		    		y.A[x].coefficient = this->A[i].coefficient + other.A[j].coefficient;
		    		y.A[x].power = this->A[i].power ;
  				    x++;
				}
				else
				{
					y.A[x].coefficient = other.A[j].coefficient;
					y.A[x].power  = other.A[j].power;
					x++;
				}
		    
		    }
		}
		return y;
	}

	
	Polynomial operator*(const Polynomial &other)
	{
		Polynomial y;
		int x = 0;
		for(int i=0 ; i<= this->term_no ;i++)
		{
			for(int j=0 ; j<= other.term_no ;j++)
		    {
		    	y.A[x].coefficient = this->A[i].coefficient * other.A[j].coefficient;
		    	y.A[x].power  = this->A[i].power  * other.A[j].power ;
  				x++;
		    }
		}
		
		return y;
	}
	

};
      
int main()
{
	
	Polynomial T;
	T.addTerm(2,5);
	T.addTerm(4,4);
	T.addTerm(6,3);
	T.addTerm(7,2);
	T.addTerm(2,1);
	T.addTerm(10,0);
	
	
	cout<<(T.derivative());
	
	cout<<(T.antiDerivative() );
	
	cout<<T(5);
	
	cout<<endl;
	
	cout<<T;
	 
	
}



