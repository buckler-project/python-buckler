#define BOOST_PYTHON_STATIC_LIB 

#include <boost/python.hpp>


int add(int a, int b)
{
    return a + b;
}

BOOST_PYTHON_MODULE(simple)
{
    using namespace boost::python;
    def("add", &add);
}

