#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct MyClass {
  virtual bool call(int i) {
    return i == 0;
  }
};

struct MockMyClass : public MyClass {
  MOCK_METHOD1(call, bool(int));
};

void externalCall(MyClass& mc, int i) {
  mc.call(i);
}

TEST(MyGroup, test_mock) {
  using testing::AtLeast;
  
  MockMyClass mc;

  EXPECT_CALL(mc, call(5)).Times(1);
  
  externalCall(mc, 5);
}
