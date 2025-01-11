#include "meniu.h"

Meniu::Meniu() {}
Meniu::~Meniu() {}
Meniu& Meniu::inst() {
    Meniu *m = new Meniu();
    return *m;
}
void Meniu::run() {
    std::vector<Profesor> p;
    std::vector<Elev> e;
    std::cout << "0. Stop\n"
                 "1. Adauga profesor\n"
                 "2. Adauga elev\n"
                 "3. Adauga nota\n"
                 "4. Vizualizeaza note\n"
                 "5. Vizualizeaza media generala\n"
                 "6. Vizualizeaza notele pentru o zi\n"
                 "7. Sorteaza si afiseaza elevii in ordine lexicografica inversa\n"
                 "8. Modifica nota\n"
                 "9. Sorteaza descrescator profesorii dupa lungimea numelui si a prenumelui\n"
                 "10. Afiseaza data nasterii pentru un utilizator";
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
                std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                int indexP;
                std::cin >> indexP;
                std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                int indexE;
                std::cin >> indexE;
                if (indexE < static_cast<int>(e.size()) && indexP < static_cast<int>(p.size()))
                    p[indexP].adaugaNotaElev(e[indexE]);
                else std::cout << "Valorile introduse pentru index nu sunt valide.\n";
                break;
            }
            case 4: {
                std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                int indexE;
                std::cin >> indexE;
                if (indexE < static_cast<int>(e.size()))
                    e[indexE].afiseazaNote();
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
                std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                int indexP;
                std::cin >> indexP;
                std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                int indexE;
                std::cin >> indexE;
                std::cout << "Introduceti data pentru modificarea notei: ";
                int zi, luna, an;
                std::cin >> zi >> luna >> an;
                std::cout << "Introduceti nota cautata: ";
                int nota;
                std::cin >> nota;
                if (indexE < static_cast<int>(e.size()) && indexP < static_cast<int>(p.size()))
                    p[indexP].modificaNotaElev(e[indexE], zi, luna, an, nota);
                else std::cout << "Valorile introduse pentru index nu sunt valide.\n";
                break;
            }
            case 9: {
                std::sort(p.begin(), p.end(), [](const Profesor& p1, const Profesor& p2) {
                    return p1 > p2;
                });
                for (size_t i = 0; i < p.size(); i++)
                    std::cout << p[i];
                break;
            }
            case 10: {
                std::cout << "Vizualizare data pentru profesor sau elev? (p/e): ";
                char val;
                std::cin >> val;
                if (tolower(val) == 'p') {
                    std::cout << "Introduceti indexul profesorului (maxim: " << static_cast<int>(p.size()) - 1 << "): ";
                    int indexP;
                    std::cin >> indexP;
                    if (indexP < static_cast<int>(p.size()))
                        p[indexP].afiseazaDataNasterii();
                    else std::cout << "Indexul nu este valid.\n";
                }
                else if (tolower(val) == 'e') {
                    std::cout << "Introduceti indexul elevului (maxim: " << static_cast<int>(e.size()) - 1 << "): ";
                    int indexE;
                    std::cin >> indexE;
                    if (indexE < static_cast<int>(e.size()))
                        e[indexE].afiseazaDataNasterii();
                    else std::cout << "Indexul nu este valid.\n";
                }
                break;
            }
        }
    }
}
