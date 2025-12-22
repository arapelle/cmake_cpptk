#include <cmakecc/version.hpp>

#include <gtest/gtest.h>

#include <format>

TEST(project_version_tests, test_version)
{
    constexpr unsigned major = 0;
    constexpr unsigned minor = 1;
    constexpr unsigned patch = 0;

    static_assert(cmakecc::version.major() == major);
    static_assert(cmakecc::version.minor() == minor);
    static_assert(cmakecc::version.patch() == patch);
    ASSERT_EQ(cmakecc::version.str(), std::format("{}.{}.{}", major, minor, patch));

    static_assert(cmakecc::version == cmakecc::numver());
    static_assert(cmakecc::version == cmakecc::numver(major, minor, patch));
    static_assert(cmakecc::version < cmakecc::numver(major, minor + 1, patch));
}
