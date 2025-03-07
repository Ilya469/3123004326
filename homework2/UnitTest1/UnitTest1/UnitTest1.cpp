#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept> // 为了 std::runtime_error
#include "TextUtils.h" // 确保包含你的头文件

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextUtilsTests
{
    TEST_CLASS(TextUtilsTests)
    {
    public:

        // 测试读取不存在的文件时抛出的异常
        TEST_METHOD(TestMethod_ReadFile_FileNotFound)
        {
            // 一个明显不存在的文件路径
            std::string filePath = "nonexistent_file.txt";

            // 验证 read_file 函数在文件不存在时抛出 std::runtime_error
            Assert::ExpectException<std::runtime_error>([=] {
                read_file(filePath);
                });
        }
    };
}