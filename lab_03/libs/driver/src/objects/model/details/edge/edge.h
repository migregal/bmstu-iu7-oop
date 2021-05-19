#pragma once

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t &pt1, const std::size_t &pt2);
    Edge(const Edge &_edge) = default;
    ~Edge() = default;

    [[nodiscard]] std::size_t get_fst() const;
    [[nodiscard]] std::size_t get_snd() const;

    void set_fst(const std::size_t &fst);
    void set_snd(const std::size_t &snd);

private:
    std::size_t pt1_idx;
    std::size_t pt2_idx;
};