//
//  MatrixTest.cpp
//  MNNTests
//
//  Created by MNN on 2019/01/10.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#include "MNNTestSuite.h"
#include "Matrix.h"

using namespace MNN::CV;

class MatrixScaleTest : public MNNTestCase {
public:
    virtual ~MatrixScaleTest() = default;
    virtual void run() {
        Matrix m;
        m.setRectToRect(Rect{20, 21, 40, 41}, Rect{0, 0, 100, 100}, Matrix::kCenter_ScaleToFit);
        Point p;
        m.invert(&m);
        m.mapXY(50, 50, &p);

        MNN_ASSERT(p.fX == 30);
        MNN_ASSERT(p.fY == 31);
    }
};
MNNTestSuiteRegister(MatrixScaleTest, "cv/matrix/scale");
