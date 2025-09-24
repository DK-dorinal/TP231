#include <stdio.h>

/* Prototypes des fonctions */
void sommeMatrices(int n, int m, int M1[n][m], int M2[n][m], int M3[n][m]);
void produitMatrices(int n, int m, int p, int M1[n][m], int M2[m][p], int M3[n][p]);
int rechercheSequentielle(int taille, int tab[taille], int valeur);
int produitEntiers(int a, int b);
int estTrie(int taille, int tab[taille]);
float median(int taille, int tab[taille]);
void inverserTableau(int taille, int tab[taille]);
void produitVectoriel(int vect1[3], int vect2[3], int resultat[3]);
void produitVecteurMatrice(int n, int m, int vect[n], int M[n][m], int resultat[m]);

/* Fonction d affichage du menu */
void afficherMenu() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Somme de matrices\n");
    printf("2. Produit de matrices\n");
    printf("3. Recherche sequentielle\n");
    printf("4. Produit d entiers\n");
    printf("5. Verifier si un tableau est trie\n");
    printf("6. Calculer la mediane d un tableau\n");
    printf("7. Inverser un tableau\n");
    printf("8. Produit vectoriel\n");
    printf("9. Produit vecteur x matrice\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

int main() {
    int choix;
    
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch(choix) {
            case 0:
                printf("Au revoir !\n");
                break;
                
            case 1: {
                int n, m;
                printf("\n--- SOMME DE MATRICES ---\n");
                printf("Nombre de lignes : ");
                scanf("%d", &n);
                printf("Nombre de colonnes : ");
                scanf("%d", &m);
                
                int M1[n][m], M2[n][m], M3[n][m];
                
                printf("Saisie de la matrice 1 :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        printf("M1 (ligne %d, colonne %d) : ", i+1, j+1);
                        scanf("%d", &M1[i][j]);
                    }
                }
                    
                printf("Saisie de la matrice 2 :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        printf("M2 (ligne %d, colonne %d) : ", i+1, j+1);
                        scanf("%d", &M2[i][j]);
                    }
                }
                    
                sommeMatrices(n, m, M1, M2, M3);
                
                printf("Resultat de la somme :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++)
                        printf("%d ", M3[i][j]);
                    printf("\n");
                }
                break;
            }
            
            case 2: {
                int n, m, p;
                printf("\n--- PRODUIT DE MATRICES ---\n");
                printf("Lignes de la matrice 1 : ");
                scanf("%d", &n);
                printf("Colonnes de la matrice 1 / Lignes de la matrice 2 : ");
                scanf("%d", &m);
                printf("Colonnes de la matrice 2 : ");
                scanf("%d", &p);
                
                int M1[n][m], M2[m][p], M3[n][p];
                
                printf("Saisie de la matrice 1 :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        printf("M1 (ligne %d, colonne %d) : ", i+1, j+1);
                        scanf("%d", &M1[i][j]);
                    }
                }
                    
                printf("Saisie de la matrice 2 :\n");
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < p; j++) {
                        printf("M2 (ligne %d, colonne %d) : ", i+1, j+1);
                        scanf("%d", &M2[i][j]);
                    }
                }
                    
                produitMatrices(n, m, p, M1, M2, M3);
                
                printf("Resultat du produit :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < p; j++)
                        printf("%d ", M3[i][j]);
                    printf("\n");
                }
                break;
            }
            
            case 3: {
                int taille, valeur;
                printf("\n--- RECHERCHE SEQUENTIELLE ---\n");
                printf("Taille du tableau : ");
                scanf("%d", &taille);
                
                int tab[taille];
                for(int i = 0; i < taille; i++) {
                    printf("Element %d : ", i+1);
                    scanf("%d", &tab[i]);
                }
                    
                printf("Valeur a chercher : ");
                scanf("%d", &valeur);
                
                int resultat = rechercheSequentielle(taille, tab, valeur);
                if(resultat != -1)
                    printf("Valeur trouvee a l indice %d\n", resultat);
                else
                    printf("Valeur non trouvee\n");
                break;
            }
            
            case 4: {
                int a, b;
                printf("\n--- PRODUIT D ENTIERS ---\n");
                printf("a : ");
                scanf("%d", &a);
                printf("b : ");
                scanf("%d", &b);
                
                if(a < 0 || b < 0) {
                    printf("Erreur : les valeurs doivent etre positives\n");
                } else {
                    printf("Resultat : %d\n", produitEntiers(a, b));
                }
                break;
            }
            
            case 5: {
                int taille;
                printf("\n--- VERIFICATION TABLEAU TRIE ---\n");
                printf("Taille du tableau : ");
                scanf("%d", &taille);
                
                int tab[taille];
                for(int i = 0; i < taille; i++) {
                    printf("Element %d : ", i+1);
                    scanf("%d", &tab[i]);
                }
                    
                if(estTrie(taille, tab))
                    printf("Le tableau est trie\n");
                else
                    printf("Le tableau n est pas trie\n");
                break;
            }
            
            case 6: {
                int taille;
                printf("\n--- CALCUL DE LA MEDIANE ---\n");
                printf("Taille du tableau : ");
                scanf("%d", &taille);
                
                int tab[taille];
                for(int i = 0; i < taille; i++) {
                    printf("Element %d : ", i+1);
                    scanf("%d", &tab[i]);
                }
                    
                printf("Mediane : %.2f\n", median(taille, tab));
                break;
            }
            
            case 7: {
                int taille;
                printf("\n--- INVERSION DE TABLEAU ---\n");
                printf("Taille du tableau : ");
                scanf("%d", &taille);
                
                int tab[taille];
                for(int i = 0; i < taille; i++) {
                    printf("Element %d : ", i+1);
                    scanf("%d", &tab[i]);
                }
                    
                inverserTableau(taille, tab);
                
                printf("Tableau inverse :\n");
                for(int i = 0; i < taille; i++)
                    printf("%d ", tab[i]);
                printf("\n");
                break;
            }
            
            case 8: {
                int vect1[3], vect2[3], resultat[3];
                printf("\n--- PRODUIT VECTORIEL ---\n");
                
                for(int i = 0; i < 3; i++) {
                    printf("Vecteur 1 (coord %d) : ", i+1);
                    scanf("%d", &vect1[i]);
                }
                    
                for(int i = 0; i < 3; i++) {
                    printf("Vecteur 2 (coord %d) : ", i+1);
                    scanf("%d", &vect2[i]);
                }
                    
                produitVectoriel(vect1, vect2, resultat);
                
                printf("Resultat : ");
                for(int i = 0; i < 3; i++)
                    printf("%d ", resultat[i]);
                printf("\n");
                break;
            }
            
            case 9: {
                int n, m;
                printf("\n--- PRODUIT VECTEUR x MATRICE ---\n");
                printf("Dimension du vecteur : ");
                scanf("%d", &n);
                printf("Colonnes de la matrice : ");
                scanf("%d", &m);
                
                int vect[n], M[n][m], resultat[m];
                
                for(int i = 0; i < n; i++) {
                    printf("Vecteur (coord %d) : ", i+1);
                    scanf("%d", &vect[i]);
                }
                    
                printf("Saisie de la matrice :\n");
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        printf("M (ligne %d, colonne %d) : ", i+1, j+1);
                        scanf("%d", &M[i][j]);
                    }
                }
                    
                produitVecteurMatrice(n, m, vect, M, resultat);
                
                printf("Resultat : ");
                for(int i = 0; i < m; i++)
                    printf("%d ", resultat[i]);
                printf("\n");
                break;
            }
            
            default:
                printf("Choix invalide !\n");
        }
        
        if(choix != 0) {
            printf("\nAppuyez sur Entree pour continuer...");
            getchar();
            getchar();
        }
        
    } while(choix != 0);
    
    return 0;
}

/* Definitions des fonctions */
void sommeMatrices(int n, int m, int M1[n][m], int M2[n][m], int M3[n][m]) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            M3[i][j] = M1[i][j] + M2[i][j];
}

void produitMatrices(int n, int m, int p, int M1[n][m], int M2[m][p], int M3[n][p]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            M3[i][j] = 0;
            for(int k = 0; k < m; k++)
                M3[i][j] += M1[i][k] * M2[k][j];
        }
    }
}

int rechercheSequentielle(int taille, int tab[taille], int valeur) {
    for(int i = 0; i < taille; i++)
        if(tab[i] == valeur)
            return i;
    return -1;
}

int produitEntiers(int a, int b) {
    int resultat = 0;
    for(int i = 0; i < b; i++)
        resultat += a;
    return resultat;
}

int estTrie(int taille, int tab[taille]) {
    for(int i = 0; i < taille-1; i++)
        if(tab[i] > tab[i+1])
            return 0;
    return 1;
}

float median(int taille, int tab[taille]) {
    for(int i = 0; i < taille-1; i++) {
        for(int j = 0; j < taille-i-1; j++) {
            if(tab[j] > tab[j+1]) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    
    if(taille % 2 == 1)
        return tab[taille/2];
    else
        return (tab[taille/2 - 1] + tab[taille/2]) / 2.0;
}

void inverserTableau(int taille, int tab[taille]) {
    for(int i = 0; i < taille/2; i++) {
        int temp = tab[i];
        tab[i] = tab[taille-1-i];
        tab[taille-1-i] = temp;
    }
}

void produitVectoriel(int vect1[3], int vect2[3], int resultat[3]) {
    resultat[0] = vect1[1] * vect2[2] - vect1[2] * vect2[1];
    resultat[1] = vect1[2] * vect2[0] - vect1[0] * vect2[2];
    resultat[2] = vect1[0] * vect2[1] - vect1[1] * vect2[0];
}

void produitVecteurMatrice(int n, int m, int vect[n], int M[n][m], int resultat[m]) {
    for(int j = 0; j < m; j++) {
        resultat[j] = 0;
        for(int i = 0; i < n; i++)
            resultat[j] += vect[i] * M[i][j];
    }
}
