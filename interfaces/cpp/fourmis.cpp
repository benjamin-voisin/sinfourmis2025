#include "sinfourmis.h"
#include "memoire.h"

#include <iostream>
#include <vector>

reine_retour cpp_reine_activation(fourmi_etat fourmis[], const unsigned int nb_fourmis,
                                  const reine_etat *etat, const salle *salle) {
    std::vector<fourmi_etat> ouvrieres(fourmis, fourmis + nb_fourmis);
    return {.action = REINE_PASSE, .arg = 0};
}

fourmi_retour cpp_fourmi_activation(fourmi_etat *etat, const salle *salle) {
    std::cout << "prout" << std::endl;
    return {.action = FOURMI_PASSE, .arg = 0, .depose_pheromone = false, .pheromone = 0};
}

extern "C" {
reine_retour reine_activation(fourmi_etat fourmis[], const unsigned int nb_fourmis,
                              const reine_etat *etat, const salle *salle) {
    return cpp_reine_activation(fourmis, nb_fourmis, etat, salle);
}

fourmi_retour fourmi_activation(fourmi_etat *etat, const salle *salle) {
    return cpp_fourmi_activation(etat, salle);
}
}
