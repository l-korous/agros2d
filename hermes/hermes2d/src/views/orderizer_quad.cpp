/// Simple quad.

static int num_vert_quad_simple[2]  = { 12, 12 };

static double3 vert_quad_simple[] =
{
  { -1, -1, 4.0 },
  {  1, -1, 4.0 },
  {  0.0,   0.0,  4.0 },
  {  1, -1, 5.0 },
  {  1,  1, 5.0 },
  {  0.0,   0.0,  5.0 },
  {  1,  1, 4.0 },
  { -1,  1, 4.0 },
  {  0.0,   0.0,  4.0 },
  { -1,  1, 5.0 },
  { -1, -1, 5.0 },
  {  0.0,   0.0,  5.0 },
};

static int num_elem_quad_simple[2]  = { 4 , 4};

static int3 elem_quad_simple[] =
{
  {0,1,2},
  {3,4,5},
  {6,7,8},
  {9,10,11}
};

static int num_edge_quad_simple[2] = {4, 4};

static int3 edge_quad_simple[] =
{
  { 0,  1, 0},
  { 1,  4, 1},
  { 4,  7, 2},
  {7, 10, 3}
};

// triangles
static int num_vert_tri_simple[2]  = { 3, 3 };

static double3 vert_tri_simple[] =
{
  { -1.0,  -1.0,  4.0 },
  {  1.0,  -1.0,  4.0 },
  { -1.0,   1.0,  4.0 }
};

static int num_elem_tri_simple[2]  = { 1 , 1};

static int3 elem_tri_simple[] =
{
  {0,1,2}
};

static int num_edge_tri_simple[2] = {3, 3};

static int3 edge_tri_simple[] =
{
  { 0, 1, 0 },
  { 1, 2, 1 },
  { 2, 0, 2 },
};




/// Edge orders.

static int num_vert_quad[2]  = { 29, 77 };

static double3 vert_quad0[] =
{
  {  0.0,   0.0,  0.0 },
  { -1.0,  -1.0,  0.0 },
  {  1.0,  -1.0,  0.0 },
  {  0.85, -0.85, 0.0 },
  { -0.85, -0.85, 0.0 },
  {  1.0,  -1.0,  1.0 },
  {  1.0,   1.0,  1.0 },
  {  0.85,  0.85, 1.0 },
  {  0.85, -0.85, 1.0 },
  {  1.0,   1.0,  2.0 },
  { -1.0,   1.0,  2.0 },
  { -0.85,  0.85, 2.0 },
  {  0.85,  0.85, 2.0 },
  { -1.0,   1.0,  3.0 },
  { -1.0,  -1.0,  3.0 },
  { -0.85, -0.85, 3.0 },
  { -0.85,  0.85, 3.0 },
  { -0.85, -0.85, 4.0 },
  {  0.85, -0.85, 4.0 },
  {  0.0,   0.0,  4.0 },
  {  0.85, -0.85, 5.0 },
  {  0.85,  0.85, 5.0 },
  {  0.0,   0.0,  5.0 },
  {  0.85,  0.85, 4.0 },
  { -0.85,  0.85, 4.0 },
  {  0.0,   0.0,  4.0 },
  { -0.85,  0.85, 5.0 },
  { -0.85, -0.85, 5.0 },
  {  0.0,   0.0,  5.0 },
};

static double3 vert_quad1[] =
{
  {  0.0,   0.0,  0.0 },

  { -1.0, -1.0, 0.0},
  { -0.5, -1.0, 0.0},
  {  0.0, -1.0, 0.0},
  {  0.5, -1.0, 0.0},
  {  1.0, -1.0, 0.0},

  { -0.85, -0.85, 0.0},
  { -0.25, -0.85, 0.0},
  {  0.25, -0.85, 0.0},
  {  0.85, -0.85, 0.0},

  { -0.85, -0.85, 4.0},
  { -0.25, -0.85, 4.0},
  {  0.25, -0.85, 4.0},
  {  0.85, -0.85, 4.0},

  { -0.5, -0.5, 4.0},
  {  0.0, -0.5, 4.0},
  {  0.5, -0.5, 4.0},
  { -0.25, -0.25, 4.0},
  {  0.25, -0.25, 4.0},
  {  0.0, 0.0, 4.0},

  { 1, -1, 1.0},
  { 1, -0.5, 1.0},
  { 1, 0, 1.0},
  { 1, 0.5, 1.0},
  { 1, 1, 1.0},
  { 0.85, -0.85, 1.0},
  { 0.85, -0.25, 1.0},
  { 0.85, 0.25, 1.0},
  { 0.85, 0.85, 1.0},

  { 0.85, -0.85, 5.0},
  { 0.85, -0.25, 5.0},
  { 0.85, 0.25, 5.0},
  { 0.85, 0.85, 5.0},

  { 0.5, -0.5, 5.0},
  { 0.5, 0, 5.0},
  { 0.5, 0.5, 5.0},
  { 0.25, -0.25, 5.0},
  { 0.25, 0.25, 5.0},
  { 0, 0, 5.0},

  { 1, 1, 2},
  { 0.5, 1, 2},
  { 0, 1, 2},
  { -0.5, 1, 2},
  { -1, 1, 2},
  { 0.85, 0.85, 2},
  { 0.25, 0.85, 2},
  { -0.25, 0.85, 2},
  { -0.85, 0.85, 2},

  { 0.85, 0.85, 4},
  { 0.25, 0.85, 4},
  { -0.25, 0.85, 4},
  { -0.85, 0.85, 4},

  { 0.5, 0.5, 4},
  { 0, 0.5, 4},
  { -0.5, 0.5, 4},
  { 0.25, 0.25, 4},
  { -0.25, 0.25, 4},
  { 0, 0, 4}
  ,
  { -1, 1, 3},
  { -1, 0.5, 3},
  { -1, 0, 3},
  { -1, -0.5, 3},
  { -1, -1, 3},
  { -0.85, 0.85, 3},
  { -0.85, 0.25, 3},
  { -0.85, -0.25, 3},
  { -0.85, -0.85, 3},

  { -0.85, 0.85, 5},
  { -0.85, 0.25, 5},
  { -0.85, -0.25, 5},
  { -0.85, -0.85, 5},

  { -0.5, 0.5, 5},
  { -0.5, 0, 5},
  { -0.5, -0.5, 5},
  { -0.25, 0.25, 5},
  { -0.25, -0.25, 5},
  { 0, 0, 5},


};


static int num_elem_quad[2]  = { 12 , 64};

static int3 elem_quad0[] =
{
  {0,1,2},
  {0,2,3},
  {4,5,6},
  {4,6,7},
  {8,9,10},
  {8,10,11},
  {12,13,14},
  {12,14,15},
  {16,17,18},
  {19,20,21},
  {22,23,24},
  {25,26,27}
};


static int3 elem_quad1[] =
{

  { 0, 1, 5},
  { 1, 2, 6},
  { 2, 3, 7},
  { 3, 4, 8},
  { 1, 6, 5},
  { 2, 7, 6},
  { 3, 8, 7},
  { 9, 10, 13},
  { 10, 11, 14},
  { 11, 12, 15},
  { 13, 14, 16},
  { 10, 14, 13},
  { 14, 15, 17},
  { 11, 15, 14},
  { 16, 17, 18},
  { 14, 17, 16},

  { 19, 20, 24},
  { 20, 21, 25},
  { 21, 22, 26},
  { 22, 23, 27},
  { 20, 25, 24},
  { 21, 26, 25},
  { 22, 27, 26},
  { 28, 29, 32},
  { 29, 30, 33},
  { 30, 31, 34},
  { 32, 33, 35},
  { 29, 33, 32},
  { 33, 34, 36},
  { 30, 34, 33},
  { 35, 36, 37},
  { 33, 36, 35},

  { 38, 39, 43},
  { 39, 40, 44},
  { 40, 41, 45},
  { 41, 42, 46},
  { 39, 44, 43},
  { 40, 45, 44},
  { 41, 46, 45},
  { 47, 48, 51},
  { 48, 49, 52},
  { 49, 50, 53},
  { 51, 52, 54},
  { 48, 52, 51},
  { 52, 53, 55},
  { 49, 53, 52},
  { 54, 55, 56},
  { 52, 55, 54},

  { 57, 58, 62},
  { 58, 59, 63},
  { 59, 60, 64},
  { 60, 61, 65},
  { 58, 63, 62},
  { 59, 64, 63},
  { 60, 65, 64},
  { 66, 67, 70},
  { 67, 68, 71},
  { 68, 69, 72},
  { 70, 71, 73},
  { 67, 71, 70},
  { 71, 72, 74},
  { 68, 72, 71},
  { 73, 74, 75},
  { 71, 74, 73}

};

static int num_edge_quad[2] = {4, 16};

static int3 edge_quad0[] =
{
  { 0,  1, 0},
  { 4,  5, 1},
  { 8,  9, 2},
  {12, 13, 3}
};

static int3 edge_quad1[] =
{
  {  0,  1, 0 },
  {  1,  2, 0 },
  {  2,  3, 0 },
  {  3,  4, 0 },
  { 19, 20, 1 },
  { 20, 21, 1 },
  { 21, 22, 1 },
  { 22, 23, 1 },
  { 38, 39, 2 },
  { 39, 40, 2 },
  { 40, 41, 2 },
  { 41, 42, 2 },
  { 57, 58, 3 },
  { 58, 59, 3 },
  { 59, 60, 3 },
  { 60, 61, 3 }
};

// triangles
static int num_vert_tri[2]  = { 16, 38 };

static double3 vert_tri0[] =
{
  { -1.0/3.0,  -1.0/3.0,  0.0 },

  { -1.0,  -1.0,  0.0 },
  {  1.0,  -1.0,  0.0 },
  {  0.64, -0.85, 0.0 },
  { -0.85, -0.85, 0.0 },

  {  1.0,  -1.0,  1.0 },
  { -1.0,   1.0,  1.0 },
  { -0.85,  0.64, 1.0 },
  {  0.64, -0.85, 1.0 },

  { -1.0,   1.0,  2.0 },
  { -1.0,  -1.0,  2.0 },
  { -0.85, -0.85, 2.0 },
  { -0.85,  0.64, 2.0 },

  { -0.85,  0.64, 4.0 },
  { -0.85, -0.85, 4.0 },
  {  0.64, -0.85, 4.0 },
};

static double3 vert_tri1[] =
{
  { -1.0/3.0,  -1.0/3.0,  0.0 },

  { -1.0,  -1.0,  0.0 },
  { -0.5,  -1.0,  0.0 },
  {  0.0,  -1.0,  0.0 },
  {  0.5,  -1.0,  0.0 },
  {  1.0,  -1.0,  0.0 },
  {  0.64, -0.85, 0.0 },
  {  0.15, -0.85, 0.0 },
  { -0.35, -0.85, 0.0 },
  { -0.85, -0.85, 0.0 },

  {  1.0,  -1.0,  1.0 },
  {  0.5,  -0.5,  1.0 },
  {  0.0,   0.0,  1.0 },
  { -0.5,   0.5,  1.0 },
  { -1.0,   1.0,  1.0 },
  { -0.85,  0.64, 1.0 },
  { -0.35,  0.15, 1.0 },
  {  0.15, -0.35, 1.0 },
  {  0.64, -0.85, 1.0 },

  { -1.0,   1.0,  2.0 },
  { -1.0,   0.5,  2.0 },
  { -1.0,   0.0,  2.0 },
  { -1.0,  -0.5,  2.0 },
  { -1.0,  -1.0,  2.0 },
  { -0.85, -0.85, 2.0 },
  { -0.85, -0.35, 2.0 },
  { -0.85,  0.15, 2.0 },
  { -0.85,  0.64, 2.0 },

  { -0.85,  0.64, 4.0 },
  { -0.85,  0.15, 4.0 },
  { -0.85, -0.35, 4.0 },
  { -0.85, -0.85, 4.0 },
  { -0.35, -0.85, 4.0 },
  {  0.15, -0.85, 4.0 },
  {  0.64, -0.85, 4.0 },
  {  0.15, -0.35, 4.0 },
  { -0.35,  0.15, 4.0 },
  { -0.35, -0.35, 4.0 },
};


static int num_elem_tri[2]  = { 7 , 30};

static int3 elem_tri0[] =
{
  {0,1,2},
  {0,2,3},
  {4,5,6},
  {4,6,7},
  {8,9,10},
  {8,10,11},
  {12,13,14},
};


static int3 elem_tri1[] =
{
  {0,1,8},
  {1,7,8},
  {1,2,7},
  {2,6,7},
  {2,3,6},
  {3,5,6},
  {3,4,5},

  {9,10,17},
  {10,16,17},
  {10,11,16},
  {11,15,16},
  {11,12,15},
  {12,14,15},
  {12,13,14},

  {18,19,26},
  {19,25,26},
  {19,20,25},
  {20,24,25},
  {20,21,24},
  {21,23,24},
  {21,22,23},

  {27,28,36},
  {28,29,31},
  {29,30,31},
  {28,31,36},
  {27,36,35},
  {36,31,32},
  {35,36,32},
  {35,32,34},
  {34,32,33},
};

static int num_edge_tri[2] = {3, 12};

static int3 edge_tri0[] =
{
  { 0, 1, 0 },
  { 4, 5, 1 },
  { 8, 9, 2 },
};

static int3 edge_tri1[] =
{
  { 0, 1, 0 },
  { 1, 2, 0 },
  { 2, 3, 0 },
  { 3, 4, 0 },

  {  9, 10, 1 },
  { 10, 11, 1 },
  { 11, 12, 1 },
  { 12, 13, 1 },

  { 18, 19, 2 },
  { 19, 20, 2 },
  { 20, 21, 2 },
  { 21, 22, 2 },
};
