#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* insererDebut(Noeud* tete, int val) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = val;
    nouveau->suivant = tete;
    return nouveau;
}

Noeud* supprimerOccurrences(Noeud* tete, int val) {
    Noeud* tmp;
    while (tete && tete->valeur == val) {
        tmp = tete;
        tete = tete->suivant;
        free(tmp);
    }
    Noeud* courant = tete;
    while (courant && courant->suivant) {
        if (courant->suivant->valeur == val) {
            tmp = courant->suivant;
            courant->suivant = tmp->suivant;
            free(tmp);
        } else courant = courant->suivant;
    }
    return tete;
}

Noeud* insererTrieSimple(Noeud* tete, int val) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = val;
    if (!tete || tete->valeur >= val) {
        nouveau->suivant = tete;
        return nouveau;
    }
    Noeud* courant = tete;
    while (courant->suivant && courant->suivant->valeur < val)
        courant = courant->suivant;
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;
    return tete;
}

void afficherSimple(Noeud* tete) {
    while (tete) {
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

typedef struct NoeudD {
    int valeur;
    struct NoeudD *precedent, *suivant;
} NoeudD;

NoeudD* insererTrieDouble(NoeudD* tete, int val) {
    NoeudD* nouveau = (NoeudD*)malloc(sizeof(NoeudD));
    nouveau->valeur = val;
    nouveau->precedent = nouveau->suivant = NULL;
    if (!tete || tete->valeur >= val) {
        nouveau->suivant = tete;
        if (tete) tete->precedent = nouveau;
        return nouveau;
    }
    NoeudD* courant = tete;
    while (courant->suivant && courant->suivant->valeur < val)
        courant = courant->suivant;
    nouveau->suivant = courant->suivant;
    if (courant->suivant) courant->suivant->precedent = nouveau;
    nouveau->precedent = courant;
    courant->suivant = nouveau;
    return tete;
}

void afficherDouble(NoeudD* tete) {
    while (tete) {
        printf("%d <-> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

typedef struct NoeudC {
    int valeur;
    struct NoeudC* suivant;
} NoeudC;

NoeudC* insererTeteCirculaire(NoeudC* queue, int val) {
    NoeudC* nouveau = (NoeudC*)malloc(sizeof(NoeudC));
    nouveau->valeur = val;
    if (!queue) {
        nouveau->suivant = nouveau;
        return nouveau;
    }
    nouveau->suivant = queue->suivant;
    queue->suivant = nouveau;
    return queue;
}

NoeudC* insererQueueCirculaire(NoeudC* queue, int val) {
    NoeudC* nouveau = (NoeudC*)malloc(sizeof(NoeudC));
    nouveau->valeur = val;
    if (!queue) {
        nouveau->suivant = nouveau;
        return nouveau;
    }
    nouveau->suivant = queue->suivant;
    queue->suivant = nouveau;
    return nouveau;
}

void afficherCirculaire(NoeudC* queue) {
    if (!queue) return;
    NoeudC* courant = queue->suivant;
    do {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    } while (courant != queue->suivant);
    printf("(circulaire)\n");
}

typedef struct NoeudDC {
    int valeur;
    struct NoeudDC *precedent, *suivant;
} NoeudDC;

NoeudDC* insererTeteDC(NoeudDC* queue, int val) {
    NoeudDC* nouveau = (NoeudDC*)malloc(sizeof(NoeudDC));
    nouveau->valeur = val;
    if (!queue) {
        nouveau->suivant = nouveau->precedent = nouveau;
        return nouveau;
    }
    NoeudDC* tete = queue->suivant;
    nouveau->suivant = tete;
    nouveau->precedent = queue;
    tete->precedent = nouveau;
    queue->suivant = nouveau;
    return queue;
}

NoeudDC* insererQueueDC(NoeudDC* queue, int val) {
    NoeudDC* nouveau = (NoeudDC*)malloc(sizeof(NoeudDC));
    nouveau->valeur = val;
    if (!queue) {
        nouveau->suivant = nouveau->precedent = nouveau;
        return nouveau;
    }
    NoeudDC* tete = queue->suivant;
    nouveau->suivant = tete;
    nouveau->precedent = queue;
    tete->precedent = nouveau;
    queue->suivant = nouveau;
    return nouveau;
}

void afficherDC(NoeudDC* queue) {
    if (!queue) return;
    NoeudDC* courant = queue->suivant;
    do {
        printf("%d <-> ", courant->valeur);
        courant = courant->suivant;
    } while (courant != queue->suivant);
    printf("(circulaire)\n");
}

int main() {
    int choix, val;
    Noeud* listeSimple = NULL;
    NoeudD* listeDouble = NULL;
    NoeudC* listeCirculaire = NULL;
    NoeudDC* listeDoubleCirculaire = NULL;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Supprimer toutes les occurrences dans une liste simplement chaînée\n");
        printf("2. Insertion dans une liste simplement chaînée triée\n");
        printf("3. Insertion dans une liste doublement chaînée triée\n");
        printf("4. Insertion en tête et en queue dans une liste simplement chaînée circulaire\n");
        printf("5. Insertion en tête et en queue dans une liste doublement chaînée circulaire\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrer une valeur : ");
                scanf("%d", &val);
                listeSimple = insererDebut(listeSimple, val);
                printf("Entrer une valeur à supprimer : ");
                scanf("%d", &val);
                listeSimple = supprimerOccurrences(listeSimple, val);
                afficherSimple(listeSimple);
                break;
            case 2:
                printf("Entrer une valeur à insérer : ");
                scanf("%d", &val);
                listeSimple = insererTrieSimple(listeSimple, val);
                afficherSimple(listeSimple);
                break;
            case 3:
                printf("Entrer une valeur à insérer : ");
                scanf("%d", &val);
                listeDouble = insererTrieDouble(listeDouble, val);
                afficherDouble(listeDouble);
                break;
            case 4:
                printf("1. Insérer en tête\n2. Insérer en queue\nChoix : ");
                scanf("%d", &val);
                if (val == 1) {
                    printf("Entrer une valeur : ");
                    scanf("%d", &val);
                    listeCirculaire = insererTeteCirculaire(listeCirculaire, val);
                } else {
                    printf("Entrer une valeur : ");
                    scanf("%d", &val);
                    listeCirculaire = insererQueueCirculaire(listeCirculaire, val);
                }
                afficherCirculaire(listeCirculaire);
                break;
            case 5:
                printf("1. Insérer en tête\n2. Insérer en queue\nChoix : ");
                scanf("%d", &val);
                if (val == 1) {
                    printf("Entrer une valeur : ");
                    scanf("%d", &val);
                    listeDoubleCirculaire = insererTeteDC(listeDoubleCirculaire, val);
                } else {
                    printf("Entrer une valeur : ");
                    scanf("%d", &val);
                    listeDoubleCirculaire = insererQueueDC(listeDoubleCirculaire, val);
                }
                afficherDC(listeDoubleCirculaire);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}