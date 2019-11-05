#include <iostream>
#define MIN -1

using namespace std;
int main()
{
    int max=MIN,second_max=MIN;
    int arr[6]={0,1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<"::"<<arr[i];
    }
    for(int i=0;i<5;i++){
        if(arr[i]>max){
            second_max=max;
            max=arr[i];
        }
    }
    cout<<endl<<"Second Max:"<<second_max;
    int i;
    cin>>i;
    return 0;
}
