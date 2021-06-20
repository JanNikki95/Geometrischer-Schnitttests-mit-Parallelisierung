#pragma once
#include <vector>
#include "Point3D.h"

bool IsColinear(Point3D a, Point3D b, Point3D c) {

    Vektor3D ab = b - a;
    Vektor3D ac = c - a;

    return std::abs((ab.y() * ac.z()) - (ab.z() * ac.y())) < FLT_EPSILON
        && std::abs((ab.z() * ac.x()) - (ab.x() * ac.z())) < FLT_EPSILON
        && std::abs((ab.x() * ab.y()) - (ab.y() * ac.x())) < FLT_EPSILON;
}

bool IsPlanar(Point3D a, Point3D b, Point3D c, Point3D d) {
    Vektor3D da = a - d;
    Vektor3D db = b - d;
    Vektor3D dc = c - d;

    float res = dot(da, cross(db, dc));

    return std::abs(res) < FLT_EPSILON;
}

enum class Orientation {
    OnPlane, BehindPlane, InFrontOfPlane, NoOrientation
};

Orientation OrientationTrianglePoint(Point3D a, Point3D b, Point3D c, Point3D d) {

    Vektor3D da = a - d;
    Vektor3D db = b - d;
    Vektor3D dc = c - d;

    float vol = dot(da, cross(db, dc));

    if (std::abs(vol) < FLT_EPSILON) {
        return Orientation::OnPlane;
    }
    else if (vol < 0.0f) {
        return Orientation::InFrontOfPlane;
    }
    else if(vol > 0.0f){
        return Orientation::BehindPlane;
    }
    else {
        return Orientation::NoOrientation;
    }
}

void ExtremePointsAlongDirection(Vektor3D dir, const std::vector<Point3D>& pt, size_t& imin, size_t& imax) {
    if (pt.size() == 0) return;

    float proj = dot(pt[0], dir);
    float minproj = proj, maxproj = proj;

    for (size_t i = 1; i < pt.size(); ++i) {

        proj = dot(pt[i], dir);

        if (proj < minproj) {
            minproj = proj;
            imin = i;
        } else if (proj > maxproj) {
            maxproj = proj;
            imax = i;
        }

    }
}