#define BOOST_PYTHON_STATIC_LIB 

#include <boost/python.hpp>


class accumulator {
public:
    int operator()(int v) {
        v_ += v;
        return v_;
    }

    int value() const {
        return v_;
    }

private:
    int v_;
};



BOOST_PYTHON_MODULE(simple)
{
    using namespace boost::python;

    class_<accumulator>("accumulator")
        .def("__call__",
             &accumulator::operator())
        .add_property("value", &accumulator::value)
        ;
}

