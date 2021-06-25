#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

//ofstream fout("test.txt");

class LCS{
public:
    string a,b;
    int num;
    int DP[500][500]{};
    string arr[1000];

    LCS(const string& x,const string& y){
        a = x,b = y;
        memset(DP,0,sizeof (DP));
        memset(arr,0,sizeof (arr));
        num = 0;
    }
    ~LCS()=default;
    void set_DP(){
        for (int i = 0; i <= a.length(); ++i) {
            for (int j = 0; j <= b.length(); ++j) {
                if(i == 0 || j ==0 ) {
                    DP[i][j] = 0;
                    continue;
                }
                if(a.at(i-1)==b.at(j-1)){
                    DP[i][j]= DP[i-1][j-1]+1;
                }if(a.at(i-1)!=b.at(j-1)){
                    if(DP[i-1][j] >= DP[i][j-1]){
                        DP[i][j] = DP[i-1][j];
                    }
                    if(DP[i-1][j] <= DP[i][j-1]){
                        DP[i][j] = DP[i][j-1];
                    }

                }
            }
        }
    }
    void input_str(string s){
        if (num!=0) {
            for (int i = 0; i < num; ++i) {
                if (arr[i] == s)
                    return;
            }
        }
        arr[num++] = s;
    }
    void LCS_traceback(string str,int a_len,int b_len){
        //if(DP[a_len][b_len]==0)return;
        while(a_len > 0 && b_len > 0){
            if(a[a_len-1] == b[b_len-1]){
                str.push_back(b[b_len-1]);
                a_len--,b_len--;
            }else{
                if(DP[a_len-1][b_len]>DP[a_len][b_len-1]){
                    a_len--;
                }else if(DP[a_len-1][b_len]<DP[a_len][b_len-1]){
                    b_len--;
                }
                else{
                    LCS_traceback(str,a_len, b_len - 1);
                    LCS_traceback(str,a_len - 1, b_len);
                    return ;
                }
            }
        }
        reverse(str.begin(),str.end());
        input_str(str);
    }
    void print_DP(){
        for (int i = 0; i <= a.length(); ++i) {
            for (int j = 0; j <= b.length(); ++j) {
                cout<< DP[i][j]<<" ";
            }
            cout<< endl;
        }
    }
    int print_LCS(){

        if(DP[a.length()][b.length()] == 0){
            return 0;
        }
        sort(arr,arr+num);
        for (int i = 0; i < num; ++i) {
            cout << arr[i]<<endl;
        }
        return 1;
    }
};



int main(){
    string a,b;
    int cont = 0;
    while(1){
        cin>> a >>b;
        if(cin.get()==EOF) break;
        LCS test(a, b);
        string str;
        test.set_DP();
        test.LCS_traceback(str, a.length() + 1, b.length() + 1);
        //if(cont!= 0)
        if(test.print_LCS()==0)
            cout<< "No common sequence."<< endl;
        cout<< endl;
        cont++;
    }
    //fout.close();
}
