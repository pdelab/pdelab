// Copyright (C) 2017 Chris N. Richardson and Garth N. Wells
//
// This file is part of DOLFIN.
//
// DOLFIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// DOLFIN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with DOLFIN. If not, see <http://www.gnu.org/licenses/>.

#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
// #include <pybind11/petsc.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/eval.h>

#include <dolfin/common/Variable.h>
#include <dolfin/geometry/BoundingBoxTree.h>
#include <dolfin/mesh/BoundaryMesh.h>
#include <dolfin/mesh/Mesh.h>
#include <dolfin/mesh/MeshColoring.h>
#include <dolfin/mesh/MeshData.h>
#include <dolfin/mesh/MeshEditor.h>
#include <dolfin/mesh/CellType.h>
#include <dolfin/mesh/MeshTopology.h>
#include <dolfin/mesh/MeshGeometry.h>
#include <dolfin/mesh/MeshEntity.h>
#include <dolfin/mesh/MeshView.h>
#include <dolfin/mesh/Vertex.h>
#include <dolfin/mesh/Edge.h>
#include <dolfin/mesh/Face.h>
#include <dolfin/mesh/Facet.h>
#include <dolfin/mesh/Cell.h>
#include <dolfin/mesh/MeshEntityIterator.h>
#include <dolfin/mesh/MeshFunction.h>
#include <dolfin/mesh/MeshPartitioning.h>
#include <dolfin/mesh/MeshValueCollection.h>
#include <dolfin/mesh/MeshQuality.h>
#include <dolfin/mesh/SubDomain.h>
#include <dolfin/mesh/SubMesh.h>
#include <dolfin/mesh/SubsetIterator.h>
#include <dolfin/mesh/DomainBoundary.h>
#include <dolfin/mesh/PeriodicBoundaryComputation.h>
#include <dolfin/mesh/MeshTransformation.h>
#include <dolfin/mesh/MultiMesh.h>
#include <dolfin/function/Expression.h>


#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <dolfin/geometry/Point.h>
#include <dolfin/mesh/CellType.h>
// #include <dolfin/generation/BoxMesh.h>
// #include <dolfin/generation/UnitTriangleMesh.h>
// #include <dolfin/generation/UnitCubeMesh.h>
// #include <dolfin/generation/UnitDiscMesh.h>
// #include <dolfin/generation/SphericalShellMesh.h>
#include <dolfin/generation/UnitSquareMesh.h>
#include <dolfin/generation/RectangleMesh.h>
// #include <dolfin/generation/UnitIntervalMesh.h>
// #include <dolfin/generation/IntervalMesh.h>

#include "casters.h"

#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>

#ifdef HAS_PYBIND11_PETSC4PY
#include <petsc4py/petsc4py.h>
#endif

#include "casters.h"

#include <dolfin/common/Array.h>
#include <dolfin/la/solve.h>
#include <dolfin/la/BlockVector.h>
#include <dolfin/la/BlockMatrix.h>
#include <dolfin/la/GenericLinearOperator.h>
#include <dolfin/la/GenericLinearSolver.h>
#include <dolfin/la/GenericTensor.h>
#include <dolfin/la/GenericMatrix.h>
#include <dolfin/la/GenericVector.h>
#include <dolfin/la/IndexMap.h>
#include <dolfin/la/LinearAlgebraObject.h>
#include <dolfin/la/LinearOperator.h>
#include <dolfin/la/Matrix.h>
#include <dolfin/la/Vector.h>
#include <dolfin/la/Scalar.h>
#include <dolfin/la/TensorLayout.h>
#include <dolfin/la/DefaultFactory.h>
#include <dolfin/la/EigenFactory.h>
#include <dolfin/la/EigenMatrix.h>
#include <dolfin/la/EigenVector.h>
#include <dolfin/la/PETScFactory.h>
#include <dolfin/la/PETScKrylovSolver.h>
#include <dolfin/la/PETScLUSolver.h>
#include <dolfin/la/PETScLinearOperator.h>
#include <dolfin/la/PETScMatrix.h>
#include <dolfin/la/PETScNestMatrix.h>
#include <dolfin/la/PETScOptions.h>
#include <dolfin/la/PETScPreconditioner.h>
#include <dolfin/la/PETScVector.h>
#include <dolfin/la/SUNDIALSNVector.h>
#include <dolfin/la/TpetraFactory.h>
#include <dolfin/la/TpetraMatrix.h>
#include <dolfin/la/TpetraVector.h>
#include <dolfin/la/TrilinosPreconditioner.h>
#include <dolfin/la/MueluPreconditioner.h>
#include <dolfin/la/BelosKrylovSolver.h>
#include <dolfin/la/LUSolver.h>
#include <dolfin/la/KrylovSolver.h>
#include <dolfin/la/SLEPcEigenSolver.h>
#include <dolfin/la/SparsityPattern.h>
#include <dolfin/la/solve.h>
#include <dolfin/la/VectorSpaceBasis.h>
#include <dolfin/la/test_nullspace.h>


// #include <dolfin.h>
namespace py = pybind11;

dolfin::Matrix create_mesh(dolfin::Matrix A) {
//   if (grid_size < 3) return 0;

  dolfin::Point zeros(0.0, 0.0, 0.0);
  dolfin::Point ones(1.0, 1.0, 1.0);
//   dolfin::BoxMesh m2(zeros, ones, grid_size, grid_size, grid_size);
  dolfin::Matrix B(A);

//   int num_cells = int(mesh.num_cells());

  return B;
}

int sizemesh(dolfin::Mesh mesh) {

  int num_cells = int(mesh.num_cells());

  return num_cells;
}

PYBIND11_MODULE(mesh, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("sizemesh", &sizemesh, "A function which adds two numbers");

    m.def("create_mesh", &create_mesh, "A function which adds two numbers");
}

// namespace dolfin_wrappers
// {

//   void mesh(py::module& m)
//   {
//     // Make dolfin::SubDomain from pointer
// //     m.def("make_dolfin_subdomain",
// //           [](std::uintptr_t e)
// //           {
// //             dolfin::SubDomain *p = reinterpret_cast<dolfin::SubDomain *>(e);
// //             return std::shared_ptr<const dolfin::SubDomain>(p);
// //           });

// //      // dolfin::Vertex
// //     py::class_<dolfin::Vertex, std::shared_ptr<dolfin::Vertex>, dolfin::MeshEntity>
// //       (m, "Vertex", "DOLFIN Vertex object")
// //       .def(py::init<const dolfin::Mesh&, std::size_t>())
// //       .def("point", &dolfin::Vertex::point)
// //       .def("x", (double (dolfin::Vertex::*)(std::size_t) const) &dolfin::Vertex::x );

//   }


// }