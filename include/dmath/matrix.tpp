#include "vector.tpp"

template <typename T, std::size_t M, std::size_t N>
struct Matrix : public Vector<Vector<T,N>, M>
{

};
