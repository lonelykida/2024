/*
    创建迷宫矩阵
    1.用户输入矩阵的长m(列数)、宽n(行数)；
    2.用户输入障碍的最小长度obsMinL、最大长度obsMaxL、障碍的个数obsNum；
    3.生成初始矩阵initMatrix；
    4.生成obsNum个障碍的起始x、y位置以及横数方向obsDir；
    5.保存所有障碍的信息到./middleFile/随机数_obsInfo.txt；
    6.根据障碍信息，将每一个障碍布置到矩阵中；
    7.保存初始矩阵initMatrix到./middleFile/随机数_initMatrix.txt；
    8.将生成好的初始矩阵initMatrix返回。
*/
#include "head.hpp"

//用户变量
int m,n,obsMinL,obsMaxL,obsNum;
vector<int>obsx,obsy;     //每个obs的x、y坐标
vector<int>obsdir;  //每个obs的方向

vector<vector<int>>& createMatrix(void){
    vector<vector<int>>matrix = initInfo();//1.输入初始信息，并生成初始空数组
    //2.生成障碍

    
    
}

vector<vector<int>>& initInfo(void){    //1，输出初始化信息
    //把步骤1~3都做完了
    cout<<"请输入矩阵的长:";
    cin>>m;
    cout<<"请输入矩阵的宽:";
    cin>>n;
    cout<<"请输入障碍的最小长度:";
    cin>>obsMinL;
    cout<<"请输入障碍的最大长度:";
    cin>>obsMaxL;
    cout<<"请输入障碍的个数:";
    cin>>obsNum;
    vector<vector<int>>matrix(m,vector<int>(n,0));
    return matrix;
}

void obsCreate(vector<vector<int>>&matrix){ //2.生成障碍
    default_random_engine e;    //随机数引擎
    uniform_int_distribution<int> u_len(obsMinL,obsMaxL);   //均匀分布的整数随机数
    uniform_int_distribution<int> u_x(0,m);
    uniform_int_distribution<int> u_y(0,n);
    e.seed(time(0));
    for(int i = 0;i < obsNum;i++){  //生成obsNum个随机障碍
        int x = u_x(e);     //生成x坐标
        int y = u_y(e);     //生成y坐标
        
    }
}