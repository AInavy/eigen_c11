#include "useEigen.h"

namespace MHJ_PROJ {
    eigenTools::eigenTools()
    {
        std::cout<<"run constructor function"<<std::endl;
    }
    eigenTools::~eigenTools()
    {
        std::cout<<"run destructor function"<<std::endl;
    }

    void eigenTools::useEigenBuiltInDataType()
    {
        Eigen::Matrix<float, 2, 3> matrix_23;
        Eigen::Vector3d v_3d;
        Eigen::Matrix<float, 3, 1> vd_3d;

        Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();

        Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;

        Eigen::MatrixXd matrix_x;

        // matrix Eigen array operation
        matrix_23 << 1, 2, 3, 4, 5, 6;
        std::cout<<matrix_23<<std::endl;

        //traversal Matrix
        for(int i = 0; i < matrix_23.rows(); i++)
        {
            for(int j = 0; j < matrix_23.cols(); j++)
            {
                std::cout<<matrix_23(i,j)<<"\t";
            }
            std::cout<<std::endl;
        }

        //matrix + - * /
        v_3d << 1, 2, 3;
        vd_3d << 4, 5, 6;
        // 但是在Eigen里你不能混合两种不同类型的矩阵，像这样是错的, 应该显式转换
        Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
        std::cout<<result<<std::endl;

        Eigen::Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
        std::cout<<result2<<std::endl;

        //some Matrix Operation
        matrix_33 = Eigen::Matrix3d::Random();
        std::cout<<matrix_33<<std::endl<<std::endl;

        std::cout<<matrix_33.transpose()<<std::endl<<std::endl;
        std::cout<<matrix_33.sum()<<std::endl<<std::endl;
        std::cout<<matrix_33.trace()<<std::endl<<std::endl;
        std::cout<<10*matrix_33<<std::endl<<std::endl;
        std::cout<<matrix_33.inverse()<<std::endl<<std::endl;
        std::cout<<matrix_33.determinant()<<std::endl<<std::endl;

        //svd
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
        std::cout<<"Eigen values = \n"<<eigen_solver.eigenvalues()<<std::endl<<std::endl;
        std::cout<<"Eigen vectors = \n"<<eigen_solver.eigenvectors()<<std::endl<<std::endl;

        //solve equations
        // 我们求解 matrix_NN * x = v_Nd 这个方程
        // N的大小在前边的宏里定义，它由随机数生成
        // 直接求逆自然是最直接的，但是求逆运算量大
        Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
        matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
        Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd;
        v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

        std::clock_t time_stt = std::clock();
        // 直接求逆
        Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
        std::cout<<"equations results: "<<x.transpose()<<std::endl;
        std::cout<<"time use in normal inverse is "<< 1000*(std::clock() - time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<std::endl;


        // 通常用矩阵分解来求，例如QR分解，速度会快很多
        time_stt = std::clock();
        x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
        std::cout<<"equations results: "<<x.transpose()<<std::endl;
        std::cout<<"time use Qr decomposition is "<< 1000*(std::clock() - time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<std::endl;



    }

}
