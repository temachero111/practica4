#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H


#include <vector>
#include "neurona.h"

class Administradora {
public:
    void agregarInicio(const Neurona& neurona);
    void agregarFinal(const Neurona& neurona);
    std::vector<Neurona> obtenerNeuronas() const;

private:
    std::vector<Neurona> neuronas;
};
#endif // ADMINISTRADORA_H
