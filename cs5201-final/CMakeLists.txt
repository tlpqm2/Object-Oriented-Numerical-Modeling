cmake_minimum_required(VERSION 3.3)
project(final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES driver.cpp Vector.h Vector.hpp RectangularMatrix.h RectangularMatrix.hpp MatrixBase.h
        GaussianElimination.h PDEsolver.h PDEsolver.hpp QRdecomp.h QRdecomp.hpp QRsolver.h
        QRsolver.hpp TriangularMatrix.hpp TriangularMatrix.h LowerTriangularMatrix.h LowerTriangularMatrix.hpp)
add_executable(final ${SOURCE_FILES})