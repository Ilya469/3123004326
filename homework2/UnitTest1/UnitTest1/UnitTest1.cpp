#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept> // Ϊ�� std::runtime_error
#include "TextUtils.h" // ȷ���������ͷ�ļ�

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextUtilsTests
{
    TEST_CLASS(TextUtilsTests)
    {
    public:

        // ���Զ�ȡ�����ڵ��ļ�ʱ�׳����쳣
        TEST_METHOD(TestMethod_ReadFile_FileNotFound)
        {
            // һ�����Բ����ڵ��ļ�·��
            std::string filePath = "nonexistent_file.txt";

            // ��֤ read_file �������ļ�������ʱ�׳� std::runtime_error
            Assert::ExpectException<std::runtime_error>([=] {
                read_file(filePath);
                });
        }
    };
}