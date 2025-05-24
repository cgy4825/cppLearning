#include<iostream>
#include "sales_item.h"

using namespace std;

int main(){
    // Sales_item book;
    // cin >> book;
    // cout << book << endl;

    Sales_item total;
    if(cin >> total){
        Sales_item trans;//保存和的变量
        while(cin >> trans){
            if(total.isbn == trans.isbn){
                total += trans;
            }else{
                //打印前一本书的结果
                cout << total << endl;
                total = trans;
            }
        }
        cout <<total << endl;//打印最后一本书的结果

    }else{
        //没有输入
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}