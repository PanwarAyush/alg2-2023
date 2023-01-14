#include<bits/stdc++.h>
using namespace std;

int fractional_knapsack(vector <int> weights, vector <int> values, int capacity){
    int len = weights.size(),index,value_to_consider,total_value = 0;
    vector <pair <float, int>> ratio(len, make_pair(0.0, 0));
    for(int i = 0; i < len; i++)
        ratio[i] = make_pair(values[i]/weights[i], i);
    sort(ratio.rbegin(), ratio.rend());
    for(int i = 0; i < len; i++){
        if(capacity == 0) break;
        index = ratio[i].second;
        if(weights[index] <= capacity) {
            capacity -= weights[index];
            total_value += values[index];
        }
        else{
            value_to_consider = values[index] * (float(capacity)/float(weights[index]));
            total_value += value_to_consider;
            capacity = 0;
        }
    }
    return total_value;
}

int main()
{
    int n, capacity;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout << "Enter the weights of the items\n";
    vector <int> weights(n);
    for(int i=0;i<n;i++){
      printf("weight[%d]=",i+1);
      cin>>weights[i];
    }
    cout << "Enter the values/Frequency of each item: " << endl;
    vector <int> values(n);
    for(int i=0;i<n;i++){
      printf("value[%d]=",i+1);
      cin>>values[i];
    } 
    cout << "Enter the capacity of the knapsack: " << endl;
    cin >> capacity;
    
    cout << "The maximum value possible based on current list is: " <<  fractional_knapsack(weights, values, capacity) << endl;
}
