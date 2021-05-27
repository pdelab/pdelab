#include "example.h"


int fact(int n) {
  if (n <= 1) return n;

  return n * fact(n - 1);
}


int create_mesh(int grid_size) {
  if (grid_size < 3) return 0;

  dolfin::Point zeros(0.0, 0.0, 0.0);
  dolfin::Point ones(1.0, 1.0, 1.0);
  dolfin::BoxMesh mesh(zeros, ones, grid_size, grid_size, grid_size);

  int num_cells = int(mesh.num_cells());

  return num_cells;
}


int sizemesh(dolfin::Mesh mesh) {

  int num_cells = int(mesh.num_cells());

  return num_cells;
}
