#pragma once

namespace Transform
{
    struct Vertex
    {
        float x;
        float y;
    };

    struct Vector
    {
        float x_meter;
        float y_meter;
    };

    Vertex MoveVertex(Vertex point, Vector meter)
    {
        point.x += meter.x_meter;
        point.y += meter.y_meter;
        return point;
    }

    Vertex RotateVertex(Vertex point, float angle_degree)
    {
        float angle_radian = angle_degree * 3.14159265f / 180.0f;
        float cos_angle = cos(angle_radian);
        float sin_angle = sin(angle_radian);
        float x_new = point.x * cos_angle - point.y * sin_angle;
        float y_new = point.x * sin_angle + point.y * cos_angle;
        point.x = x_new;
        point.y = y_new;
        return point;
    }

    Vertex ScaleVertex(Vertex point, Vector meter)
    {
        point.x *= meter.x_meter;
        point.y *= meter.y_meter;
        return point;
    }
};
