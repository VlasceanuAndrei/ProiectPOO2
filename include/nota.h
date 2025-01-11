#ifndef PROIECT_NOTA_H
#define PROIECT_NOTA_H
#include <iostream>

class Nota {
    double nota;
    int zi;
    int luna;
    int an;
public:
    Nota();
    Nota(double nota, int zi, int luna, int an);
    ~Nota();
    friend std::ostream& operator<<(std::ostream& out, const Nota& n);
    friend std::istream& operator>>(std::istream& in, Nota& n);
    void modificaNota(double val);
    double getNota() const;
    std::string getDataFormatata() const;
};

#endif