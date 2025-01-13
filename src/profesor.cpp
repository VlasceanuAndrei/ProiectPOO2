#include "profesor.h"

Profesor::Profesor() {}
Profesor::Profesor(const std::string& nume, const std::string& prenume, const std::string& nrTelefon, int ziNastere, int lunaNastere,  int anNastere, const std::string& materie, int salariu) :
    User(nume, prenume, nrTelefon, ziNastere, lunaNastere, anNastere), materie(materie), salariu(salariu) {}
Profesor::Profesor(const std::string& nume, const std::string& prenume, const std::string& nrTelefon, const std::string& materie, int salariu) :
    User(nume, prenume, nrTelefon), materie(materie), salariu(salariu) {}
Profesor::Profesor(const Profesor& other) : User(other){
    this->materie = other.materie;
    this->salariu = other.salariu;
}
Profesor& Profesor::operator=(const Profesor& other) {
    if (this != &other) {
        User::operator=(other);
        this->materie = other.materie;
        this->salariu = other.salariu;
    }
    return *this;
}
Profesor::~Profesor() {}
std::ostream& operator<<(std::ostream& out, const Profesor& p) {
    out << "Profesorul " << p.nume << " " << p.prenume << " cu nr. de telefon" <<
        p.nrTelefon << " ,preda " << p.materie << " , avand salariul " << p.salariu << "\n";
    return out;
}
std::istream& operator>>(std::istream& in, Profesor& p) {
    std::cout << "Nume:";
    in >> p.nume;
    std::cout << "Prenume:";
    in >> p.prenume;
    std::cout << "Nr. telefon:";
    in >> p.nrTelefon;
    std::cout << "Introduceti data nasterii? (0/1):";
    int caz;
    in >> caz;
    if(caz) {
        std::cout << "Data nasterii:";
        in >> p.ziNastere >> p.lunaNastere >> p.anNastere;
    }
    std::cout << "Materie:";
    in >> p.materie;
    std::cout << "Salariu:";
    in >> p.salariu;
    return in;
}
void Profesor::adaugaNotaElev(User& u) {
    Elev *e = dynamic_cast<Elev*>(&u);
    if (e != nullptr) {
        Nota n;
        std::cout << "Introduceti nota pentru elevul " << e->getNume() << " " << e->getPrenume() << "\n";
        std::cin >> n;
        e->note.push_back(n);
    }
    else std::cout << "Userul nu este elev!\n";
}
void Profesor::modificaNotaElev(User &u, int zi, int luna, int an, double val) {
    Elev *e = dynamic_cast<Elev*>(&u);
    if (e != nullptr) {
        std::string temp = std::to_string(zi) + "-" + std::to_string(luna) + "-" + std::to_string(an);
        for (size_t i = 0; i < e->note.size(); i++) {
            if (e->note[i].getDataFormatata().compare(temp) == 0 && e->note[i].getNota() == val) {
                int notaNoua;
                std::cout << "Nota noua: ";
                std::cin >> notaNoua;
                e->note[i].modificaNota(notaNoua);
            }
        }
    }
}
void Profesor::arePermisiuni() {
    std::cout << "Profesorul poate adauga/ modifica notele elevilor.\n";
    std::cout << "Doriti sa adaugati (0) sau sa modificati (1) o nota?";
}
void Profesor::areVenit() {
    std::cout << "Venitul profesorului este de " << this->salariu << " lei.\n";
}
void Profesor::profesorValid() {
    if (this->dateValide()) {
        if (salariu > 0 && materie != "")
            std::cout << "Profesorul poate fi validat.\n";
    }
    else std::cout << "Profesorul nu poate fi validat.\n";
}
