#include<iostream>
using namespace std;
int  main()
{
   int n,temp;
   cout<<"Enter No Of Elements:\n";
   cin>>n;
   int arr[n];
   cout<<"Enter Elements:\n";
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
   for(int j=0;j<n-1;j++)
   {
      bool flag=false;
      for(int k=0;k<n-1-j;k++)
      {
         if(arr[k]>arr[k+1])
         {
         temp=arr[k];
         arr[k]=arr[k+1];
         arr[k+1]=temp;
         flag=true;
         }
      }
      if(!flag)
      {
         break;
      }
   }
   cout<<"Displaying after bubble sort:\n";
   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<"\t";
   }
   cout<<endl;
   return 0;
}
