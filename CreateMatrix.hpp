/*
    创建迷宫矩阵
    1.用户输入矩阵的长m(列数)、宽n(行数)；
    2.用户输入障碍的最小长度obsMinL、最大长度obsMaxL、障碍的个数obsNum；
    3.生成初始矩阵initMatrix;
    4.生成obsNum个障碍的起始x、y位置以及横竖方向obsDir；
    5.保存所有障碍的信息到C:/middleFile/随机数_obsInfo.txt；
    6.根据障碍信息，将每一个障碍布置到矩阵中；
    7.保存初始矩阵initMatrix到C:/middleFile/随机数_initMatrix.txt；
    8.将生成好的初始矩阵initMatrix返回。
*/
#pragma once
#include "head.hpp"

//用户变量
int m,n,obsMinL,obsMaxL,obsNum;
vector<int>obsx,obsy;     //每个obs的x、y坐标
vector<int>obsdir;  //每个obs的方向
vector<int>obslen;  //每个obs的长度 - 0：横向 1：纵向
vector<vector<int>>matrix;

//prototype
void initInfo(void);
void obsCreate(void);
void saveInfo(void);

vector<vector<int>>& createMatrix(void){    //主函数
    initInfo();//1.输入初始信息，并生成初始空数组
    //2.生成障碍
    obsCreate();
    //3.保存矩阵及障碍信息
    saveInfo();    
    return matrix;  //完成步骤8
}

void initInfo(void){    //1.输出初始化信息 - 完成步骤1~3
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
    matrix = vector<vector<int>>(m,vector<int>(n,0));
}

void obsCreate(void){ //2.生成障碍 - 完成步骤4、6
    default_random_engine e;    //随机数引擎
    uniform_int_distribution<int> u_len(obsMinL,obsMaxL);   //均匀分布的整数随机数
    uniform_int_distribution<int> u_x(0,m);
    uniform_int_distribution<int> u_y(0,n);
    uniform_int_distribution<int> u_dir(0,1);
    e.seed(time(0));
    for(int i = 0;i < obsNum;i++){  //2.1.生成obsNum个随机障碍
        int x = u_x(e);     //生成x坐标
        int y = u_y(e);     //生成y坐标
        int len = u_len(e); //生成长度
        int direction = u_dir(e);   //生成方向
        //2.2.将障碍布置到Matrix中
        //判断长度是否合法
        if(!direction && (x+len>m))len = m-x;
        if(direction && y+len>n)len = n-y;
        obsx.push_back(x);  //x是列 - x的长度方向
        obsy.push_back(y);  //y是行 - y是宽度方向
        obsdir.push_back(direction);
        obslen.push_back(len);
        //将从x、y开始的障碍布置到数组中
        for(int i = 0;i < len;i++){
            matrix[y][x] = -1;
            if(x>m || y>n)break;    //保险
            if(direction)y++;
            else x++;
        }
    }
}

void saveInfo(void){  //3.保存相关信息 - 完成步骤5、7
    //1.保存矩阵信息
    string fname;
    default_random_engine e;
    uniform_int_distribution<int> u(0,INT_MAX);
    e.seed(time(0));
    int randomNum = u(e)%100000;
    fname = fname + "C:/middleFile/"+to_string(randomNum)+"_initMatrix.txt";
    ofstream f(fname);
    if(!f.is_open()){
        cout<<"打开初始化矩阵文件失败...\n";
        exit(-1);
    }
    for(int i = 0;i < matrix.size();i++){   //保存矩阵
        for(int j = 0;j < matrix[0].size();j++)
            f<<to_string(matrix[i][j])<<" ";
        f<<endl;
    }
    f.close();
    fname.clear();
    randomNum = u(e)%100000;
    fname = fname+"C:/middleFile/"+to_string(randomNum)+"_obsInfo.txt";
    ofstream f1(fname);
    if(!f1.is_open()){
        cout<<"打开初始化矩阵文件失败...\n";
        exit(-1);
    }
    for(int i = 0;i < obsNum;i++){  //保存障碍信息
        f1<<"X:"<<to_string(obsx[i])<<"\tY:"<<to_string(obsy[i])<<"\tLEN:"<<to_string(obslen[i])<<
        "\tdirec:"<<obsdir[i]<<endl;
    }
}


