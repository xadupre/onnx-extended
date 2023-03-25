#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "c_conv.h"

namespace py = pybind11;
using namespace onnx_c_ops;

PYBIND11_MODULE(op_conv_, m) {
  m.doc() =
#if defined(__APPLE__)
      "C++ Reference Implementation for operator Conv."
#else
      R"pbdoc(C++ Reference Implementation for operator Conv.)pbdoc"
#endif
      ;

  py::class_<ConvFloat16> clf(
      c_ops, "ConvFloat16",
      R"pbdoc(Implements float runtime for operator Conv. The code is inspired from
`conv.cc <https://github.com/microsoft/onnxruntime/blob/master/onnxruntime/core/providers/cpu/nn/conv.cc>`_
in :epkg:`onnxruntime`. Supports float only.)pbdoc");

  clf.def(py::init<>());
  clf.def("init", &ConvFloat16::init,
          "Initializes the runtime with the ONNX attributes.");
  clf.def("compute", &ConvFloat16::compute,
          "Computes the output for operator Conv.");

  py::class_<ConvFloat> clf(
      c_ops, "ConvFloat",
      R"pbdoc(Implements float runtime for operator Conv. The code is inspired from
`conv.cc <https://github.com/microsoft/onnxruntime/blob/master/onnxruntime/core/providers/cpu/nn/conv.cc>`_
in :epkg:`onnxruntime`. Supports float only.)pbdoc");

  clf.def(py::init<>());
  clf.def("init", &ConvFloat::init,
          "Initializes the runtime with the ONNX attributes.");
  clf.def("compute", &ConvFloat::compute,
          "Computes the output for operator Conv.");

  py::class_<ConvDouble> cld(
      c_ops, "ConvDouble",
      R"pbdoc(Implements float runtime for operator Conv. The code is inspired from
`conv.cc <https://github.com/microsoft/onnxruntime/blob/master/onnxruntime/core/providers/cpu/nn/conv.cc>`_
in :epkg:`onnxruntime`. Supports double only.)pbdoc");

  cld.def(py::init<>());
  cld.def("init", &ConvDouble::init,
          "Initializes the runtime with the ONNX attributes.");
  cld.def("compute", &ConvDouble::compute,
          "Computes the output for operator Conv.");
}

} // namespace onnx_c_ops