#include "nota.h"

Nota::Nota() {}
Nota::Nota(double nota, int zi, int luna, int an) : nota(nota),
    zi(zi), luna(luna), an(an) {}
std::ostream& operator<<(std::ostream& out, const Nota& n) {
    out << "Nota" << n.nota << " din data de " << n.zi << " " << n.luna <<
        " " << n.an << "\n";
    return out;
}
Nota::~Nota() {}
std::istream& operator>>(std::istream& in, Nota& n) {
    std::cout << "Nota:";
    in >> n.nota;
    std::cout << "Din data de:";
    in >> n.zi >> n.luna >> n.an;
    return in;
}
void Nota::modificaNota(double val) {
    this->nota = val;
}
double Nota::getNota() const {
    return this->nota;
}
std::string Nota::getDataFormatata() const {
    return std::to_string(this->zi) + "-" + std::to_string(this->luna) + "-" + std::to_string(this->an);
}
