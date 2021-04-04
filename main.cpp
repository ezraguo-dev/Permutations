#include <iostream>
#include <map>
#include <vector>

using namespace std;

void copy_ptr(const int* const source_ptr, const int len, int* dest_ptr){
    for(int i=0;i<len;i++){
        dest_ptr[i] = source_ptr[i];
    }
}

void print_ptr(const int* const ptr, const int len){
    cout<<"(";
    cout<<ptr[0];

    for(int i=1;i<len;i++){
        cout<<","<<ptr[i];
    }
    cout<<") ";
}

int main(){
    std::map<int,vector<int*>> combination_res;
    int n=6;

    vector<int*> _1_combination_vec;
    for(int i=0;i<5;i++){
        int* tmp = new int[1];
        tmp[0] = i;
        _1_combination_vec.push_back(tmp);
    }
    combination_res[1]=_1_combination_vec;

    for(int i=2;i<=n;i++){
        vector<int*> pre_vec = combination_res[i-1];
        vector<int*> _next_vec;

        for(auto iter : pre_vec){
            int last_idx = iter[i-2];
            for(int j=last_idx+1;j<n;j++){
                int* tmp = new int[i];
                copy_ptr(iter,i-1,tmp);
                tmp[i-1] = j;
                _next_vec.push_back(tmp);
            }
        }

        combination_res[i] = _next_vec;
    }

    for(auto iter : combination_res){
        cout<<"#"<<iter.first<<":\n";
        for(auto _ptr : iter.second){
            print_ptr(_ptr,iter.first);
        }
        cout<<endl;
    }

    //release
    for(auto iter : combination_res){
        for(auto _ptr : iter.second){
            delete[] _ptr;
        }
    }
}