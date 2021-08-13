#ifndef MESH4_H
#define MESH4_H

#include "Ray4.h"
#include "Hittable4.h"

class Mesh4 : public Hittable4 {
public:
	Mesh4() {}

    virtual bool hit(const Ray4& r,
        double t_min,
        double t_max,
        hit_record4& rec) const override;

    void AddTetrahedron(Tetrahedron& t) {
        this->tetrahedra.push_back(t);
    }

private:
    std::vector<Tetrahedron> tetrahedra;
};

bool Mesh4::hit(const Ray4& r,
    double t_min,
    double t_max,
    hit_record4& rec) const {

    hit_record4 temp;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (Tetrahedron t : tetrahedra) {
        if (t.hit(r, t_min, t_max, temp)) {
            hit_anything = true;
            closest_so_far = temp.t;
            rec = temp;
            break;
        }
    }
    return hit_anything;
}
#endif