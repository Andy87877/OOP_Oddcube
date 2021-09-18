#include <iostream>
#include <iomanip>
using namespace std;

class oop{//oop
    public:
        int n;//n*n
        int row;//上一個數字(橫)
        int col;//上一個數字(直)
};
oop list{};

void Do() {//計算
//向右上填 如有就往下填
    int arr[list.n][list.n];

    for (int i = 0; i < list.n; i++) { //預設為0 以方便判斷
        for (int j = 0; j < list.n; j++) {
            arr[i][j] = 0;
        }
    }

    //第一個數字在第一行中間
    list.row = int((list.n-1)/2);
    list.col = 0;
    arr[list.col][list.row] = 1; 

    //填入每個數字  
    for (int i = 2; i <= list.n*list.n; i++) {
        //變更位置
        list.row += 1; //橫
        list.col -= 1; //直

        if (list.row >= list.n) {//最右邊
            list.row = 0;
        }

        if (list.col < 0) {//最上面
            list.col = (list.n - 1);
        }

        //如果撞到數字
        while(arr[list.col][list.row] != 0) {
            list.col += 2; //往下
            list.row -= 1; //往左
            if (list.row < 0) {//最左邊
                list.row = list.n-1;
            }

            if (list.col >= list.n) {//最下面
                list.col = list.col - list.n;
            }
        }

        arr[list.col][list.row] = i; //放入數字
    }

    //輸出
    for (int i = 0; i < list.n; i++) {
        for (int j = 0; j < list.n; j++) {
            cout << setw(5) << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() { 
    cin >> list.n; //cin n
    Do();//計算
}

