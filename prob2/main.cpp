#include "inf_int.h"



int main(){
    string input;
    vector<string> v(0);
    bool terminate = false;
    
    do{
        cout<<"Input: ";
        getline(cin,input);

        if(input == "0") break;
        int startidx = 0;
        for(int i=0;i<input.length();i++){
            if(input[i + 1] == ' ' || i + 1 == input.length()){
                v.push_back(input.substr(startidx,i - startidx + 1));
                startidx = i + 2;
            }
        }  

        cout<<"Output: ";
        inf_int a(v[0]);
        inf_int b(v[2]);

        switch (v[1][0])
        {
        case '+':
            cout<<(a+b)<<endl;
            break;

        case '-':
            cout<<(a-b)<<endl;
            break;

        case '*':
            cout<<(a*b)<<endl;
            break;
        }

        v.clear();
    }while(!terminate);
    return 0;
}
