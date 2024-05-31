#include "../src/Logger.h"
#include <gtest/gtest.h>


struct LoggerFixture : public testing::Test{
    Log::LogLevel logLevel = Log::LogLevel::LogInfo;

    static void SetUpTestSuite() {
        Log::Logger::getInstance().setOutputFile("/Logs.txt");
        Log::Logger::getInstance().setLogLevel(Log::LogLevel::LogInfo);
    }

};

TEST_F(LoggerFixture, test_open_file)
{

}

TEST_F(LoggerFixture, test_set_level)
{
    //Arrange
    //nothing to do here, because we have fixture

    //Act


    //Assert
    EXPECT_EQ(Log::LogLevel::LogInfo, Log::Logger::getInstance().logLevel());
}
//
//TEST(Logger,test_open_file)
//{
//    //Arrange
//    //nothing to do here, because we have fixture
//
//    //Act
//    Log::Logger::getInstance().setOutputFile("/Logs.txt");
//    Log::Logger::getInstance().setLogLevel(Log::LogLevel::LogInfo);
//    Log::LogLevel logLevel = Log::Logger::getInstance().logLevel();
//
//    //Assert
//   // EXPECT_EQ(Log::LogLevel::LogInfo,logLevel);
//}
//
//TEST(Logger,test_set_level)
//{
//    //Arrange
//
//    //Act
//    Log::Logger::getInstance().setOutputFile("/Logs.txt");
//    Log::Logger::getInstance().setLogLevel(Log::LogLevel::LogInfo);
//    Log::LogLevel logLevel = Log::Logger::getInstance().logLevel();
//
//    //Assert
//    // EXPECT_EQ(Log::LogLevel::LogInfo,logLevel);
//}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}