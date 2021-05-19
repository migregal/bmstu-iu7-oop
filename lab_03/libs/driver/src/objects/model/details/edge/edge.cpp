#include <objects/model/details/edge/edge.h>

Edge::Edge(const std::size_t &pt1, const std::size_t &pt2) : pt1_idx(pt1), pt2_idx(pt2){};

std::size_t Edge::get_fst() const {
    return pt1_idx;
}

std::size_t Edge::get_snd() const {
    return pt2_idx;
}

void Edge::set_fst(const std::size_t &fst) {
    pt1_idx = fst;
}

void Edge::set_snd(const std::size_t &snd) {
    pt2_idx = snd;
}