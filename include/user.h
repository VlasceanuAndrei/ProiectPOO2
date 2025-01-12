#ifndef PROIECT_USER_H
#define PROIECT_USER_H
#include <iostream>
#include <string>

class User {
protected:
    std::string nume;
    std::string prenume;
    std::string nrTelefon;
    int ziNastere;
    int lunaNastere;
    int anNastere;
public:
    User();
    User(const std::string& nume, const std::string& prenume, const std::string& nrTelefon,
        int ziNastere, int lunaNastere, int anNastere);
    User(const std::string& nume, const std::string& prenume, const std::string& nrTelefon);
    User(const User& other);
    User& operator=(const User& other);
    virtual ~User();
    friend std::ostream& operator<<(std::ostream& out, const User& u);
    friend std::istream& operator>>(std::istream& in, User& u);
    bool operator<(const User& u1) const;
    friend bool operator>(const User& u1, const User& u2);
    void afiseazaDataNasterii();
    virtual void arePermisiuni();
    virtual void areVenit();
};

#endif
