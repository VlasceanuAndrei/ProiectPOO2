#include "user.h"

User::User() {
    this->nume = "";
    this->prenume = "";
    this->nrTelefon = "";
    this->ziNastere = 0;
    this->lunaNastere = 0;
    this->anNastere = 0;
}
User::User(const std::string& nume, const std::string& prenume, const std::string& nrTelefon, int ziNastere, int lunaNastere, int anNastere) :
    nume(nume), prenume(prenume), nrTelefon(nrTelefon), ziNastere(ziNastere), lunaNastere(lunaNastere), anNastere(anNastere) {}
User::User(const std::string& nume, const std::string& prenume, const std::string& nrTelefon) :
    nume(nume), prenume(prenume), nrTelefon(nrTelefon), ziNastere(0), lunaNastere(0), anNastere(0) {}
User::User(const User& other) {
    this->nume = other.nume;
    this->prenume = other.prenume;
    this->nrTelefon = other.nrTelefon;
    this->ziNastere = other.ziNastere;
    this->lunaNastere = other.lunaNastere;
    this->anNastere = other.anNastere;
}
User& User::operator=(const User& other) {
    if(this != &other) {
      this->nume = other.nume;
      this->prenume = other.prenume;
      this->nrTelefon = other.nrTelefon;
      this->ziNastere = other.ziNastere;
      this->lunaNastere = other.lunaNastere;
      this->anNastere = other.anNastere;
    }
    return *this;
}
User::~User() {}
std::ostream& operator<<(std::ostream& out, const User& u) {
    out << "Utilizatorul " << u.nume << " " << u.prenume << " cu nr. de telefon " <<
        u.nrTelefon << ", data nasterii " << u.ziNastere << " " << u.lunaNastere << " " << u.anNastere << "\n";
    return out;
};
std::istream& operator>>(std::istream& in, User& u) {
    std::cout << "Nume:";
    in >> u.nume;
    std::cout << "Prenume:";
    in >> u.prenume;
    std::cout << "Nr. telefon:";
    in >> u.nrTelefon;
    std::cout << "Introduceti data nasterii? (0/1):";
    int caz;
    in >> caz;
    if(caz) {
        std::cout << "Data nasterii:";
        in >> u.ziNastere >> u.lunaNastere >> u.anNastere;
    }
    u.ziNastere = u.lunaNastere = u.anNastere = 0;
    return in;
}
bool User::operator<(const User& u) const { //ordonare lexicografica inversa dupa nume
    return u.nume.compare(this->nume) < 0;
}
bool operator>(const User& u1, const User& u2) { //ordonare descrescatoare dupa lungimea numelui + prenumelui
    int lu1 = u1.nume.length() + u1.prenume.length();
    int lu2 = u2.nume.length() + u2.prenume.length();
    return lu1 > lu2;
}
void User::afiseazaDataNasterii() {
    std::cout << "Data nasterii: " << ziNastere << " " << lunaNastere << " " << anNastere << "\n";
}
