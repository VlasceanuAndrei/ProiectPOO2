#ifndef PROIECT_PROFESOR_H
#define PROIECT_PROFESOR_H
#include <iostream>
#include <string>
#include "user.h"
#include "elev.h"
#include "nota.h"

class Profesor : public User{
    std::string materie;
    int salariu;
public:
    Profesor();
    Profesor(const std::string& nume, const std::string& prenume, const std::string& nrTelefon, int ziNastere, int lunaNastere,  int anNastere, const std::string& materie, int salariu);
    Profesor(const std::string& nume, const std::string& prenume, const std::string& nrTelefon, const std::string& materie, int salariu);
    Profesor(const Profesor& other);
    Profesor& operator=(const Profesor& other);
    ~Profesor() override;
    friend std::ostream& operator<<(std::ostream& out, const Profesor& p);
    friend std::istream& operator>>(std::istream& in, Profesor& p);
    void adaugaNotaElev(User& u);
    void modificaNotaElev(User& u, int zi, int luna, int an, double val);
};

#endif