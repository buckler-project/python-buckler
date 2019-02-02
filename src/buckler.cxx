#define BOOST_PYTHON_STATIC_LIB 

#include <vector>
#include <map>
#include <Python.h>
#include <boost/python.hpp>

#include <buckler/base.hpp>
#include <buckler/buckler.hpp>

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

    class_<PyBuckler>("Buckler")
        .def("scan", &PyBuckler::_Scan)
        .def("hits", &PyBuckler::GetHits);
}
