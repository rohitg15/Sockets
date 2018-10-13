#ifndef _TEST_RECORD_H_
#define _TEST_RECORD_H_

#include "gtest/gtest.h"

class RecordTest : public ::testing::Test
{
protected:

    RecordTest();

    virtual ~RecordTest();

    virtual void SetUp();

    virtual void TearDown();
};

#endif  //  _TEST_RECORD_H_