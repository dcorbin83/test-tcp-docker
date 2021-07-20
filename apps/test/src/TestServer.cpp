#include "gtest/gtest.h"
#include "third_party/Config/include/Config.h"
#include <stdio.h>

TEST(TestServer, when_set_Port_Message_Should_Works)
{
    Config aConfig;
    aConfig.set("1000", "new message");

    EXPECT_EQ(aConfig.getPort(), 1000);
    EXPECT_EQ(strcmp(aConfig.getMessage(), "new message"), 0);
}

TEST(TestServer, when_Unset_Port_Should_Default)
{
    Config aConfig;
    aConfig.set("", "new message");

    EXPECT_EQ(aConfig.getPort(), Config::DEFAULT_PORT);
}

TEST(TestServer, when_Unset_Message_Should_Default)
{
    Config aConfig;
    aConfig.set("1000", "");

    EXPECT_EQ(strcmp(aConfig.getMessage(), Config::DEFAULT_MESSAGE), 0);
}

TEST(TestServer, when_Unset_all_Should_Default)
{
    Config aConfig;
    aConfig.set("", "");

    EXPECT_EQ(aConfig.getPort(), Config::DEFAULT_PORT);
    EXPECT_EQ(strcmp(aConfig.getMessage(), Config::DEFAULT_MESSAGE), 0);
}