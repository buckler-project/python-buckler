#define BOOST_PYTHON_STATIC_LIB 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <Python.h>
#include <boost/python.hpp>

#include "../lib/buckler/src/base.hpp"
#include "../lib/buckler/src/buckler.hpp"
#include "../lib/buckler/src/utils.hpp"
#include "../lib/buckler/src/signature.hpp"


class PyBuckler : public buckler::Buckler 
{
public:
    buckler::Result result;

    PyBuckler() {}
    
    bool _Scan(boost::python::object object) {
        using namespace boost::python;
        
        PyObject *py_object = object.ptr();
        
        Py_buffer py_buf;
        PyObject_GetBuffer(py_object, &py_buf, PyBUF_SIMPLE);
        
        unsigned char * buf = (unsigned char *)py_buf.buf;
        int size = py_buf.len;

        target = buckler::Target(buf, size);
        Load();

        std::cout << signatures.repository.parent_path << std::endl;

        result = Scan();

        
        
        return result.has_hit;
    }

    boost::python::list GetHits() {
        boost::python::list list;        
       
        for (auto itr = result.hits.begin(); itr != result.hits.end(); ++itr) {
            boost::python::dict dict;

            dict["scanner"] = itr->scanner;
            dict["signatures"] = itr->signature;
            dict["signature_file"] = itr->signature_file;

            list.append(dict);
        }

        return list;
    }
};

BOOST_PYTHON_MODULE(buckler)
{
    using namespace boost::python;

    class_<PyBuckler>("buckler")
        .def("scan", &PyBuckler::_Scan)
        .def("hits", &PyBuckler::GetHits);
}
