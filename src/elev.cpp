#include "elev.h"

Elev::Elev() {}
Elev::Elev(const std::string& nume, const std::string& prenume, const std::string& nrTelefon,
        int ziNastere, int lunaNastere, int anNastere, const std::string& clasa, const std::vector<Nota>& note) :
        User(nume, prenume, nrTelefon, ziNastere, lunaNastere, anNastere), clasa(clasa), note(note) {}
Elev::Elev(const std::string& nume, const std::string& prenume, const std::string& nrTelefon,
        int ziNastere, int lunaNastere, int anNastere, const std::string& clasa) :
        User(nume, prenume, nrTelefon, ziNastere, lunaNastere, anNastere), clasa(clasa) {}
Elev::~Elev() {
        note.clear();
}
std::ostream& operator<<(std::ostream& out, const Elev& e) {
        out << "Elevul " << e.nume << " " << e.prenume << " cu nr. de telefon" <<
        e.nrTelefon << " ,din clasa " << e.clasa << "\n";
        return out;
}
std::istream& operator>>(std::istream& in, Elev& e) {
        std::cout << "Nume:";
        in >> e.nume;
        std::cout << "Prenume:";
        in >> e.prenume;
        std::cout << "Nr. telefon:";
        in >> e.nrTelefon;
        std::cout << "Introduceti data nasterii? (0/1):";
        int caz;
        in >> caz;
        if(caz) {
                std::cout << "Data nasterii:";
                in >> e.ziNastere >> e.lunaNastere >> e.anNastere;
        }
        std::cout << "Clasa:";
        in >> e.clasa;
        return in;
}
void Elev::afiseazaNote() {
        if (note.size() == 0)
                std::cout << "Nu exista note asociate elevului.\n";
        else {
                std::cout << "Notele elevului sunt:\n";
                for (size_t i = 0; i < note.size(); i++)
                        std::cout << note[i];
        }
}
double Elev::getMedieGenerala() {
        if (note.size() == 0)
                return 0;
        else {
                double s = 0;
                for (size_t i = 0; i < note.size(); i++)
                        s += note[i].getNota();
                return s / note.size();
        }
}
const std::string& Elev::getNume() const {
        return this->nume;
}
const std::string& Elev::getPrenume() const {
        return this->prenume;
}
void Elev::afiseazaNotePentruData(int zi, int luna, int an) {
        std::string temp = std::to_string(zi) + "-" + std::to_string(luna) + "-" + std::to_string(an);
        if (note.size() == 0)
                std::cout << "Nu exista note asociate elevului.\n";
        else {
                for (size_t i = 0; i < note.size(); i++)
                        if (temp.compare(note[i].getDataFormatata()) == 0)
                                std::cout << note[i];
        }
}
void Elev::arePermisiuni() {
        std::cout << "Elevul poate vizualiza notele sale.\n";
        std::cout << "Doriti afisarea? (0/1): ";
        int caz;
        std::cin >> caz;
        if (caz == 1)
                this->afiseazaNote();
}
void Elev::areVenit() {
        if (this->getMedieGenerala() >= 8.5)
                std::cout << "Elevul primeste bursa.\n";
        else std::cout << "Elevul nu primeste bursa.\n";
}
void Elev::elevValid() {
        if (this->dateValide()) {
                if (clasa != "")
                        std::cout << "Elevul poate fi validat.\n";
        }
        else std::cout << "Elevul nu poate fi validat.\n";
}
