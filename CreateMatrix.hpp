/*
    �����Թ�����
    1.�û��������ĳ�m(����)����n(����)��
    2.�û������ϰ�����С����obsMinL����󳤶�obsMaxL���ϰ��ĸ���obsNum��
    3.���ɳ�ʼ����initMatrix;
    4.����obsNum���ϰ�����ʼx��yλ���Լ���������obsDir��
    5.���������ϰ�����Ϣ��C:/middleFile/�����_obsInfo.txt��
    6.�����ϰ���Ϣ����ÿһ���ϰ����õ������У�
    7.�����ʼ����initMatrix��C:/middleFile/�����_initMatrix.txt��
    8.�����ɺõĳ�ʼ����initMatrix���ء�
*/
#pragma once
#include "head.hpp"

//�û�����
int m,n,obsMinL,obsMaxL,obsNum;
vector<int>obsx,obsy;     //ÿ��obs��x��y����
vector<int>obsdir;  //ÿ��obs�ķ���
vector<int>obslen;  //ÿ��obs�ĳ��� - 0������ 1������
vector<vector<int>>matrix;

//prototype
void initInfo(void);
void obsCreate(void);
void saveInfo(void);

vector<vector<int>>& createMatrix(void){    //������
    initInfo();//1.�����ʼ��Ϣ�������ɳ�ʼ������
    //2.�����ϰ�
    obsCreate();
    //3.��������ϰ���Ϣ
    saveInfo();    
    return matrix;  //��ɲ���8
}

void initInfo(void){    //1.�����ʼ����Ϣ - ��ɲ���1~3
    cout<<"���������ĳ�:";
    cin>>m;
    cout<<"���������Ŀ�:";
    cin>>n;
    cout<<"�������ϰ�����С����:";
    cin>>obsMinL;
    cout<<"�������ϰ�����󳤶�:";
    cin>>obsMaxL;
    cout<<"�������ϰ��ĸ���:";
    cin>>obsNum;
    matrix = vector<vector<int>>(m,vector<int>(n,0));
}

void obsCreate(void){ //2.�����ϰ� - ��ɲ���4��6
    default_random_engine e;    //���������
    uniform_int_distribution<int> u_len(obsMinL,obsMaxL);   //���ȷֲ������������
    uniform_int_distribution<int> u_x(0,m);
    uniform_int_distribution<int> u_y(0,n);
    uniform_int_distribution<int> u_dir(0,1);
    e.seed(time(0));
    for(int i = 0;i < obsNum;i++){  //2.1.����obsNum������ϰ�
        int x = u_x(e);     //����x����
        int y = u_y(e);     //����y����
        int len = u_len(e); //���ɳ���
        int direction = u_dir(e);   //���ɷ���
        //2.2.���ϰ����õ�Matrix��
        //�жϳ����Ƿ�Ϸ�
        if(!direction && (x+len>m))len = m-x;
        if(direction && y+len>n)len = n-y;
        obsx.push_back(x);  //x���� - x�ĳ��ȷ���
        obsy.push_back(y);  //y���� - y�ǿ�ȷ���
        obsdir.push_back(direction);
        obslen.push_back(len);
        //����x��y��ʼ���ϰ����õ�������
        for(int i = 0;i < len;i++){
            matrix[y][x] = -1;
            if(x>m || y>n)break;    //����
            if(direction)y++;
            else x++;
        }
    }
}

void saveInfo(void){  //3.���������Ϣ - ��ɲ���5��7
    //1.���������Ϣ
    string fname;
    default_random_engine e;
    uniform_int_distribution<int> u(0,INT_MAX);
    e.seed(time(0));
    int randomNum = u(e)%100000;
    fname = fname + "C:/middleFile/"+to_string(randomNum)+"_initMatrix.txt";
    ofstream f(fname);
    if(!f.is_open()){
        cout<<"�򿪳�ʼ�������ļ�ʧ��...\n";
        exit(-1);
    }
    for(int i = 0;i < matrix.size();i++){   //�������
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
        cout<<"�򿪳�ʼ�������ļ�ʧ��...\n";
        exit(-1);
    }
    for(int i = 0;i < obsNum;i++){  //�����ϰ���Ϣ
        f1<<"X:"<<to_string(obsx[i])<<"\tY:"<<to_string(obsy[i])<<"\tLEN:"<<to_string(obslen[i])<<
        "\tdirec:"<<obsdir[i]<<endl;
    }
}


