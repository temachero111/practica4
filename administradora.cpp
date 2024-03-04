#include "administradora.h"

void Administradora::agregarInicio(const Neurona& neurona) {
    neuronas.insert(neuronas.begin(), neurona);
}

void Administradora::agregarFinal(const Neurona& neurona) {
    neuronas.push_back(neurona);
}

std::vector<Neurona> Administradora::obtenerNeuronas() const {
    return neuronas;
}
