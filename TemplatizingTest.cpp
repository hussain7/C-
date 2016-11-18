
// This is about writing a single boost test case using templates and use it in such a way for diffrent types.
// Lets say we have an enviorment which we want to test for three diffrenet configurations .In usual case we have to write 
// three test cases but using some meta programming shit we can do it in a signle test case.
#include <boost/mpl/integral_c.hpp>
#include <boost/test/unit_test.hpp>

// environment parameters structure
struct env
{

};
// configuration type of the environment defined three different type of configuration structures.
    struct CONFIG_ONE;
    struct CONFIG_TWO;
    struct CONFIG_THREE;

// common fixture
struct envFixture
{
    // we create different environment depending on the type of configurations. Config 1
    env* createEnv(CONFIG_ONE const&)
    {
        auto ev = new env();
        return ev;
    }
    // we create different environment depending on the type of configurations. Config 2
    env* createEnv(CONFIG_TWO const&)
    {
        auto ev = new env();
        return ev;
    }
    // we create different environment depending on the type of configurations. Config 3
    env* createEnv(CONFIG_THREE const&)
    {
        auto ev = new env();
        return ev;
    }
}

// create a boost mpl list for the different type of configurations for the environment.
typedef boost::mpl::list<CONFIG_ONE, CONFIG_TWO, CONFIG_THREE> EnvConfigList;

// run the boost template case . It will run three times accoriding to number of configurations provided.
BOOST_FIXTURE_TEST_CASE_TEMPLATE(TestCaseName, env, EnvConfigList,
                                 envFixture)
{
    auto ev = createEnv(env());
    // bla bla bla..

}
