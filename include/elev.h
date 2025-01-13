#ifndef PROIECT_ELEV_H
#define PROIECT_ELEV_H
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "nota.h"

class Elev : public User {
    std::string clasa;
protected:
    std::vector<Nota> note;
public:
    friend class Profesor;
    Elev();
    Elev(const std::string& nume, const std::string& prenume, const std::string& nrTelefon,
        int ziNastere, int lunaNastere, int anNastere, const std::string& clasa, const std::vector<Nota>& note);
    Elev(const std::string& nume, const std::string& prenume, const std::string& nrTelefon,
        int ziNastere, int lunaNastere, int anNastere, const std::string& clasa);
    ~Elev() override;
    friend std::ostream& operator<<(std::ostream& out, const Elev& e);
    friend std::istream& operator>>(std::istream& in, Elev& e);
    void afiseazaNote();
    double getMedieGenerala();
    const std::string& getNume() const;
    const std::string& getPrenume() const;
    void afiseazaNotePentruData(int zi, int luna, int an);
    void arePermisiuni() override;
    void areVenit() override;
    void elevValid();
};

#endif
