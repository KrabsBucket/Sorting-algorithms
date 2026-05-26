#include <iostream>
#include <vector>

using namespace std;


void radix(vector<unsigned int>&vec)
{
    int n = vec.size();
    vector<unsigned int> output(n);
    for (int shift = 0; shift < 32 ; shift+=8)
    {
        
        vector<unsigned int> count(256, 0);
        

        for(int i =0; i<n; i++)
        {
            unsigned char byte_val = (vec[i]>>shift) & 0xFF;
            count[byte_val]++;
        }

        for (int i = 1; i < 256; i++)
        {
            count[i] += count[i-1];
        }

        for(int i = n-1; i >= 0; i--)
        {
            unsigned char byte = (vec[i] >> shift ) & 0xFF;
            output[count[byte]-1] = vec[i];
            count[byte]--;

        }

        for (int i = 0; i < n; i++)
        {
            vec[i] = output[i];
        }
  
    }
}

int main()
{
    int n; 
    cout << "Enter size of array: ";
    cin >> n;
    vector<unsigned int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    
    radix(vec);

    for (int i =0; i < n; i++)
    {
        cout << vec[i] <<"\n";
    }


    
    


}
