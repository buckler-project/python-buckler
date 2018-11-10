#define BOOST_PYTHON_STATIC_LIB 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <boost/python.hpp>

#include "../lib/buckler/src/buckler.hpp"


class PyBuckler : public buckler::Buckler 
{
public:
    PyBuckler(boost::python::object object) {
        using namespace boost::python;
        
        PyObject *py_object = object.ptr();
        
        Py_buffer py_buf;
        PyObject_GetBuffer(py_object, &py_buf, PyBUF_SIMPLE);
        
        unsigned char * buf = (unsigned char *)py_buf.buf;
        int size = py_buf.len;

        target.SetBuffer(buf, size);
        SetUp(target);
    }
    
    bool _Scan() {
        Scan();
        return result.is_hit;
    }
};

BOOST_PYTHON_MODULE(buckler)
{
    using namespace boost::python;

    class_<PyBuckler>("buckler", init<boost::python::object>())
        .def("scan", &PyBuckler::_Scan, "");
}
