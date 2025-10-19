# include <iostream>

using namespace std;

int main()
{
   int A[3][5] = {0};
   *(*(A+2) +1) =99;

   for(int i=0 ; i<3 ;i++){

        for(int j=0 ; j<5 ;j++){

        cout<< A[i][j]<<" ";
    
   }
        cout<<endl;

   }

}
