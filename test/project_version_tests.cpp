#include <cmake_cpptk/version.hpp>

#include <gtest/gtest.h>

#include <format>

TEST(project_version_tests, test_version)
{
    constexpr unsigned major = 0;
    constexpr unsigned minor = 1;
    constexpr unsigned patch = 0;

    static_assert(cmake_cpptk::version.major() == major);
    static_assert(cmake_cpptk::version.minor() == minor);
    static_assert(cmake_cpptk::version.patch() == patch);
    ASSERT_EQ(cmake_cpptk::version.str(), std::format("{}.{}.{}", major, minor, patch));

    static_assert(cmake_cpptk::version == cmake_cpptk::numver());
    static_assert(cmake_cpptk::version == cmake_cpptk::numver(major, minor, patch));
    static_assert(cmake_cpptk::version < cmake_cpptk::numver(major, minor + 1, patch));
}
