#include "DataConfig.h"

DataConfig::DataConfig(QObject *parent) : QObject(parent) {
    int array1[4][4] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 0, 0, 0},
                        {1, 1, 0, 1}};

    QVector<QVector<int>> v;
    for (auto &i : array1) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(1, v);

    int array2[4][4] = {{1, 0, 1, 1},
                        {0, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1}};

    v.clear();
    for (auto &i : array2) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(2, v);


    int array3[4][4] = {{0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}};
    v.clear();
    for (auto &i : array3) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(3, v);


    int array4[4][4] = {{0, 1, 1, 1},
                        {1, 0, 0, 1},
                        {1, 0, 1, 1},
                        {1, 1, 1, 1}};
    v.clear();
    for (auto &i : array4) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(4, v);


    int array5[4][4] = {{1, 0, 0, 1},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 0, 0, 1}};
    v.clear();
    for (auto &i : array5) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(5, v);


    int array6[4][4] = {{1, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 0},
                        {1, 0, 0, 1}};
    v.clear();
    for (auto &i : array6) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(6, v);


    int array7[4][4] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}};
    v.clear();
    for (auto &i : array7) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(7, v);

    int array8[4][4] = {{0, 1, 0, 1},
                        {1, 0, 0, 0},
                        {0, 0, 0, 1},
                        {1, 0, 1, 0}};
    v.clear();
    for (auto &i : array8) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(8, v);

    int array9[4][4] = {{1, 0, 1, 0},
                        {1, 0, 1, 0},
                        {0, 0, 1, 0},
                        {1, 0, 0, 1}};
    v.clear();
    for (auto &i : array9) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(9, v);


    int array10[4][4] = {{1, 0, 1, 1},
                         {1, 1, 0, 0},
                         {0, 0, 1, 1},
                         {1, 1, 0, 1}};
    v.clear();
    for (auto &i : array10) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(10, v);


    int array11[4][4] = {{0, 1, 1, 0},
                         {1, 0, 0, 1},
                         {1, 0, 0, 1},
                         {0, 1, 1, 0}};
    v.clear();
    for (auto &i : array11) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(11, v);

    int array12[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {1, 1, 1, 1},
                         {0, 0, 0, 0}};
    v.clear();
    for (auto &i : array12) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(12, v);

    int array13[4][4] = {{0, 1, 1, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 1, 1, 0}};
    v.clear();
    for (auto &i : array13) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(13, v);

    int array14[4][4] = {{1, 0, 1, 1},
                         {0, 1, 0, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1}};
    v.clear();
    for (auto &i : array14) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(14, v);


    int array15[4][4] = {{0, 1, 0, 1},
                         {1, 0, 0, 0},
                         {1, 0, 0, 0},
                         {0, 1, 0, 1}};
    v.clear();
    for (auto &i : array15) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(15, v);


    int array16[4][4] = {{0, 1, 1, 0},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    v.clear();
    for (auto &i : array16) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(16, v);

    int array17[4][4] = {{0, 1, 1, 1},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0},
                         {1, 1, 1, 0}};
    v.clear();
    for (auto &i : array17) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(17, v);


    int array18[4][4] = {{0, 0, 0, 1},
                         {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {1, 0, 0, 0}};
    v.clear();
    for (auto &i : array18) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(18, v);

    int array19[4][4] = {{0, 1, 0, 0},
                         {0, 1, 1, 0},
                         {0, 0, 1, 1},
                         {0, 0, 0, 0}};
    v.clear();
    for (auto &i : array19) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(19, v);

    int array20[4][4] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0}};
    v.clear();
    for (auto &i : array20) {
        QVector<int> v1;
        for (int &j : i) {
            v1.push_back(j);
        }
        v.push_back(v1);
    }

    mData.insert(20, v);
}
