#ifndef __USEEIGEN_H__
#define __USEEIGEN_H__

#include <iostream>
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等)
#include <Eigen/Dense>

#include <ctime>
#define MATRIX_SIZE 50


namespace MHJ_PROJ {

    class eigenTools{
    public:
          eigenTools();
          ~eigenTools();
          void useEigenBuiltInDataType();
    private:
          int _m;
    };

};


#endif
