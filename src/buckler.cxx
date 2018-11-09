#define BOOST_PYTHON_STATIC_LIB 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <boost/python.hpp>
#include "../lib/buckler/src/base.hpp"



class PyTarget :  buckler::Target {
public:
    PyTarget() {}

    bool SetTarget(boost::python::object object) {
        using namespace boost::python;
        
        PyObject *py_object = object.ptr();
        
        Py_buffer py_buf;
        PyObject_GetBuffer(py_object, &py_buf, PyBUF_SIMPLE);
        
        unsigned char * buf = (unsigned char * )py_buf.buf;
        int size = py_buf.len;

        printf("%p", py_buf.buf);

        SetBuffer(buf, size);
        

        std::cout << std::endl;
        for (auto i = buffer.begin(); i != buffer.end(); ++i) {
            std::cout << *i;
        }
        std::cout << std::endl;

        return true;
    }
};

BOOST_PYTHON_MODULE(buckler)
{
    using namespace boost::python;

    class_<PyTarget>("target", init<>())
        .def("set", &PyTarget::SetTarget, args("buf"), "");
}
