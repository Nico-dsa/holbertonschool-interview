#include "slide_line.h"

/**
 * Décale les éléments non nuls du tableau vers la direction spécifiée.
 * Les éléments sont déplacés vers le début ou la fin du tableau, en fonction de la direction.
 *
 * @param line Le tableau d'entiers à traiter.
 * @param size La taille du tableau.
 * @param direction La direction du décalage (SLIDE_LEFT ou SLIDE_RIGHT).
 */
void shift(int *line, size_t size, int direction) {
    int swap = 1;
    while (swap) {
        swap = 0;
        for (size_t i = (direction == SLIDE_LEFT) ? 1 : size - 2; 
             (direction == SLIDE_LEFT) ? (i < size) : (i != (size_t)-1); 
             i += (direction == SLIDE_LEFT) ? 1 : -1) {
            if (line[i] != 0 && line[i - (direction == SLIDE_LEFT ? 1 : -1)] == 0) {
                line[i - (direction == SLIDE_LEFT ? 1 : -1)] = line[i];
                line[i] = 0;
                swap = 1; // Indique qu'un échange a eu lieu.
            }
        }
    }
}

/**
 * Fusionne les éléments adjacents identiques du tableau.
 * Si deux éléments consécutifs sont égaux, ils sont fusionnés en un seul,
 * avec leur valeur sommée, et l'espace libéré est mis à zéro.
 *
 * @param line Le tableau d'entiers à traiter.
 * @param size La taille du tableau.
 * @param direction La direction de la fusion (SLIDE_LEFT ou SLIDE_RIGHT).
 */
void merge(int *line, size_t size, int direction) {
    for (size_t i = (direction == SLIDE_LEFT) ? 0 : size - 1; 
         (direction == SLIDE_LEFT) ? (i < size - 1) : (i > 0); 
         i += (direction == SLIDE_LEFT) ? 1 : -1) {
        if (line[i] != 0 && line[i] == line[i + (direction == SLIDE_LEFT ? 1 : -1)]) {
            line[i] += line[i + (direction == SLIDE_LEFT ? 1 : -1)];
            line[i + (direction == SLIDE_LEFT ? 1 : -1)] = 0;
        }
    }
}

/**
 * Fonction principale pour faire glisser et fusionner un tableau d'entiers.
 * Cette fonction simule une étape du jeu 2048 sur une ligne horizontale.
 * Les éléments identiques sont fusionnés et les espaces vides sont comblés.
 *
 * @param line Le tableau d'entiers à glisser et fusionner.
 * @param size La taille du tableau.
 * @param direction La direction du glissement (SLIDE_LEFT ou SLIDE_RIGHT).
 * @return 1 si le traitement a réussi, 0 en cas d'échec (direction invalide).
 */
int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0; // Retourne 0 pour une direction invalide.
    }

    // Déplacer les éléments non nuls vers l'extrémité spécifiée.
    shift(line, size, direction);

    // Fusionner les éléments contigus identiques.
    merge(line, size, direction);

    // Réaligner les éléments après fusion.
    shift(line, size, direction);

    return 1; // Succès de l'opération.
}
