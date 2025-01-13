#include "meniu.h"

Meniu::Meniu() {}
Meniu::~Meniu() {}
Meniu& Meniu::inst() {
    static Meniu *m = new Meniu();
    return *m;
}
void Meniu::run() {
    std::vector<User> u;
    std::vector<Profesor> p;
    std::vector<Elev> e;
    std::cout << "0. Stop\n"
                 "1. Adauga profesor\n"
                 "2. Adauga elev\n"
                 "3. Adauga user\n"
                 "4. Permisiuni particulare user\n"
                 "5. Vizualizeaza media generala\n"
                 "6. Vizualizeaza notele pentru o zi\n"
                 "7. Sorteaza si afiseaza elevii in ordine lexicografica inversa\n"
                 "8. Sorteaza descrescator profesorii dupa lungimea numelui si a prenumelui\n"
                 "9. Afiseaza data nasterii pentru un utilizator\n"
                 "10. Afisare venit pentru user\n"
                 "11. Validare profesor/ elev\n";
    int caz = 1;
    while (caz) {
        std::cin >> caz;
        switch (caz) {
            case 1: {
                Profesor p1;
                std::cin >> p1;
                p.push_back(p1);
                break;
            }
            case 2: {
                Elev e1;
                std::cin >> e1;
                e.push_back(e1);
                break;
            }
            case 3: {
                User u1;
                std::cin >> u1;
                u.push_back(u1);
                break;
            }
            case 4: {
                std::cout << "Vizualizare permisiuni pentru user/profesor/elev? (u/p/e): ";
                char tip;
                std::cin >> tip;
                if (tolower(tip) == 'u') {
                    std::cout << "Introduceti indexul userului (maxim: " << static_cast<int>(u.size()) - 1 << "): ";
                    int indexU;
                    std::cin >> indexU;
                    if (indexU < static_cast<int>(u.size()))
                        u[indexU].arePermisiuni();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(tip) == 'p') {
                    std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                    int indexP;
                    std::cin >> indexP;
                    if (indexP < static_cast<int>(p.size())) {
                        p[indexP].arePermisiuni();
                        int caz;
                        std::cin >> caz;
                        int indexE;
                        if (caz == 0 || caz == 1) {
                            std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                            std::cin >> indexE;
                            if (indexE >= static_cast<int>(e.size()))
                                std::cout << "Indexul nu este valid.\n";
                        }
                        if (caz == 0)
                            p[indexP].adaugaNotaElev(e[indexE]);
                        else if (caz == 1) {
                            int zi, luna, an;
                            std::cout << "Introduceti data: ";
                            std::cin >> zi >> luna >> an;
                            double val;
                            std::cout << "Nota cautata: ";
                            std::cin >> val;
                            p[indexP].modificaNotaElev(e[indexE], zi, luna, an, val);
                        }
                    }
                }
                else if (tolower(tip) == 'e') {
                    std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                    int indexE;
                    std::cin >> indexE;
                    if (indexE < static_cast<int>(e.size()))
                        e[indexE].arePermisiuni();
                    else std::cout << "Indexul nu este valid.\n";
                    }
                else std::cout << "Indexul nu este valid.\n";
                break;
            }
            case 5: {
                std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                int indexE;
                std::cin >> indexE;
                if (indexE < static_cast<int>(e.size()))
                    std::cout << "Media generala a elevului: " << e[indexE].getMedieGenerala() << "\n";
                else std::cout << "Indexul nu este valid.\n";
                break;
            }
            case 6: {
                std::cout << "Introduceti data pentru vizualizarea notei: ";
                int zi, luna, an;
                std::cin >> zi >> luna >> an;
                std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                int indexE;
                std::cin >> indexE;
                if (indexE < static_cast<int>(e.size()))
                    e[indexE].afiseazaNotePentruData(zi, luna, an);
                else std::cout << "Indexul nu este valid.\n";
                break;
            }
            case 7: {
                std::sort(e.begin(), e.end(), [](const Elev& e1, const Elev& e2) {
                    return e1 < e2;
                });
                for (size_t i = 0; i < e.size(); i++) {
                    std::cout << e[i];
                }
                break;
            }
            case 8: {
                std::sort(p.begin(), p.end(), [](const Profesor& p1, const Profesor& p2) {
                    return p1 > p2;
                });
                for (size_t i = 0; i < p.size(); i++)
                    std::cout << p[i];
                break;
            }
            case 9: {
                std::cout << "Vizualizare data nasterii pentru user/profesor/elev? (u/p/e): ";
                char tip;
                std::cin >> tip;
                if (tolower(tip) == 'u') {
                    std::cout << "Introduceti indexul userului (maxim: " << static_cast<int>(u.size()) - 1 << "): ";
                    int indexU;
                    std::cin >> indexU;
                    if (indexU < static_cast<int>(u.size()))
                        u[indexU].afiseazaDataNasterii();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(tip) == 'p') {
                    std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                    int indexP;
                    std::cin >> indexP;
                    if (indexP < static_cast<int>(p.size()))
                        p[indexP].afiseazaDataNasterii();
                }
                else if (tolower(tip) == 'e') {
                    std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                    int indexE;
                    std::cin >> indexE;
                    if (indexE < static_cast<int>(e.size()))
                        e[indexE].afiseazaDataNasterii();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else std::cout << "Indexul nu este valid.\n";
                break;
            }
            case 10: {
                std::cout << "Vizualizare venit pentru user/profesor/elev (u/p/e): ";
                char val;
                std::cin >> val;
                if (tolower(val) == 'u') {
                    std::cout << "Introduceti indexul userului (maxim: " << static_cast<int>(u.size()) - 1 << "): ";
                    int indexU;
                    std::cin >> indexU;
                    if (indexU < static_cast<int>(u.size()))
                        u[indexU].areVenit();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(val) == 'p') {
                    std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                    int indexP;
                    std::cin >> indexP;
                    if (indexP < static_cast<int>(p.size()))
                        p[indexP].areVenit();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(val) == 'e') {
                    std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                    int indexE;
                    std::cin >> indexE;
                    if (indexE < static_cast<int>(e.size()))
                        e[indexE].areVenit();
                    else std::cout << "Indexul nu este valid.\n";
                }
                break;
            }
            case 11: {
                std::cout << "Validare profesor/elev (p/e): ";
                char val;
                std::cin >> val;
                if (tolower(val) == 'p') {
                    std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                    int indexP;
                    std::cin >> indexP;
                    if (indexP < static_cast<int>(p.size()))
                        p[indexP].profesorValid();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(val) == 'e') {
                    std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                    int indexE;
                    std::cin >> indexE;
                    if (indexE < static_cast<int>(e.size()))
                        e[indexE].elevValid();
                    else std::cout << "Indexul nu este valid.\n";
                }
            }
        }
    }
}
