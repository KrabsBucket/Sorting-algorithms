#include <bits/stdc++.h>
using namespace std;


void mergearr(vector<int>& arr, int left, int mid , int right)

{   
     int lp = left;
     int rp = mid+1;
     int idx = 0;
    

     vector<int> temp(right - left +1);

     while (lp <= mid && rp <= right)
     {
         if (arr[lp] <= arr[rp])
         {
             temp[idx] = arr[lp];
             lp++;
         }


         else
         {
             temp[idx] = arr[rp];
             rp++;
                 
         }
         idx++;

     }

     while(lp <= mid)
     {

         temp[idx] = arr[lp];
         lp++;
         idx++;
 
     }
     while (rp <= right)
     {
         temp[idx] = arr[rp];
         rp ++;
         idx++;
     }

     for (int i =0 ; i < temp.size(); i++)
     {
         arr[i+ left] = temp[i];

     }


}

void arrbreak(vector<int>& arr, int left , int right)
    {
        int mid = left + (right - left)/2;
    
        if (left>= right)
        {
            return;
        }


        arrbreak(arr, left, mid);

        arrbreak(arr, mid+1, right);

        mergearr(arr, left, mid, right);



    }
int main (){
    int n; 
    cout << "Enter size of the array: ";
    cin  >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    arrbreak(arr, 0 , n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}
 
