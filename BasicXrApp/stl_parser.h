#pragma once

#include <DirectXMath.h>
#include <fstream>

typedef struct {
    unsigned char data[80];
} STL_HEADER;

typedef struct {
    float data[3];
} normal_vector;

typedef struct {
    float data[3];
} vertex;

typedef struct {
    normal_vector norm;
    vertex points[3];
    unsigned short atribute_byte_count;
} triangle;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} color;

typedef struct {
    color diffuse;
    color specular;
    color ambient;
} material;

typedef struct {
    DirectX::XMFLOAT4* output;
    DirectX::XMFLOAT3* normal;
    DirectX::XMFLOAT3* vertices;
    unsigned int* indices;
} output_data;

class StlParser {
public:
    static output_data ParseToTriangleMesh(
        const char* stlFileName, unsigned int& number_of_triangles, float xoffset, float yoffset, float zoffset, float size_coef);
};