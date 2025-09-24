#ifndef TP_H
#define TP_H

/* Somme de matrices */
void sommeMatrices(int n, int m, int M1[n][m], int M2[n][m], int M3[n][m]);

/* Produit de matrices */
void produitMatrices(int n, int m, int p, int M1[n][m], int M2[m][p], int M3[n][p]);

/* Recherche séquentielle dans un tableau */
int rechercheSequentielle(int taille, int tab[taille], int valeur);

/* a × b pour a,b > 0 */
int produitEntiers(int a, int b);

/* Tester si un tableau est trié */
int estTrie(int taille, int tab[taille]);

/* Le médian dans un tableau */
float median(int taille, int tab[taille]);

/* Inverser un tableau */
void inverserTableau(int taille, int tab[taille]);

/* Produit vectoriel */
void produitVectoriel(int vect1[3], int vect2[3], int resultat[3]);

/* Produit vecteur × matrice */
void produitVecteurMatrice(int n, int m, int vect[n], int M[n][m], int resultat[m]);

#endif