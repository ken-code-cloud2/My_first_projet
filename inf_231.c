#include <stdio.h>

void sommeMatrices() {
    int i, j, n, m;
    printf("Entrer lignes et colonnes: ");
    scanf("%d %d", &n, &m);

    int A[n][m], B[n][m], S[n][m];

    printf("Matrice A:\n");
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      scanf("%d",&A[i][j]);

    printf("Matrice B:\n");
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      scanf("%d",&B[i][j]);

    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      S[i][j]=A[i][j]+B[i][j];

    printf("Somme:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
         printf("%d ",S[i][j]);
        printf("\n");
    }
}

void produitMatrices() {
    int n,m,p;
    printf("Dimensions (n m p): ");
    scanf("%d %d %d",&n,&m,&p);

    int A[n][m],B[m][p],C[n][p];

    printf("Matrice A:\n");
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
      scanf("%d",&A[i][j]);
    printf("Matrice B:\n");
    for(int i=0;i<m;i++)
     for(int j=0;j<p;j++)
      scanf("%d",&B[i][j]);

    for(int i=0;i<n;i++)
     for(int j=0;j<p;j++) {
        C[i][j]=0;
        for(int k=0;k<m;k++)
         C[i][j]+=A[i][k]*B[k][j];
    }

    printf("Produit:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<p;j++)
         printf("%d ",C[i][j]);
        printf("\n");
    }
}

void rechercheSeq() {
    int n,x;
    printf("Taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for(int i=0;i<n;i++)
     scanf("%d",&T[i]);

    printf("Élément à chercher: ");
    scanf("%d",&x);

    int found=0;
    for(int i=0;i<n;i++)
     if(T[i]==x){
      printf("Trouvé à la position %d\n",i);
       found=1; break; 
     }
    if(!found)
     printf("Non trouvé\n");
}

void multParAddition() {
    int a,b,prod=0;
    printf("Entrer a et b (>0): ");
    scanf("%d %d",&a,&b);
    for(int i=0;i<b;i++)
     prod+=a;
    printf("%d × %d = %d\n",a,b,prod);
}

void testTrie() {
    int n;
    printf("Taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for(int i=0;i<n;i++)
     scanf("%d",&T[i]);

    int tri=1;
    for(int i=0;i<n-1;i++)
     if(T[i]>T[i+1]) {
      tri=0;
      break;
     }
    if(tri)
     printf("Tableau trié.\n");
      else printf("Non trié.\n");
}

void tri(int T[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(T[i]>T[j]) {
             int tmp=T[i]; T[i]=T[j]; T[j]=tmp;
            }
}

void mediane() {
    int n;
    printf("Taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for(int i=0;i<n;i++)
     scanf("%d",&T[i]);

    tri(T,n);

    double med;
    if(n%2==0)
     med=(T[n/2-1]+T[n/2])/2.0;
    else med=T[n/2];
    printf("Médiane = %.2f\n",med);
}

void inverser() {
    int n;
    printf("Taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for(int i=0;i<n;i++)
     scanf("%d",&T[i]);

    for(int i=0;i<n/2;i++){
      int tmp=T[i]; T[i]=T[n-1-i]; T[n-1-i]=tmp;
    }

    printf("Tableau inversé:\n");
    for(int i=0;i<n;i++)
     printf("%d ",T[i]);
    printf("\n");
}

void produitVectoriel() {
    int u[3],v[3],w[3];
    printf("Vecteur u (x y z): "); 
    for(int i=0;i<3;i++) 
    scanf("%d",&u[i]);
    printf("Vecteur v (x y z): ");
     for(int i=0;i<3;i++) 
     scanf("%d",&v[i]);

    w[0]=u[1]*v[2]-u[2]*v[1];
    w[1]=u[2]*v[0]-u[0]*v[2];
    w[2]=u[0]*v[1]-u[1]*v[0];

    printf("u × v = (%d, %d, %d)\n",w[0],w[1],w[2]);
}

void produitVecteurMatrice() {
    int n,m;
    printf("Dimensions vecteur (1 x n) et matrice (n x m): ");
    scanf("%d %d",&n,&m);

    int V[n],M[n][m],R[m];
    printf("Vecteur:\n");
     for(int i=0;i<n;i++)
      scanf("%d",&V[i]);
    printf("Matrice:\n");
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
      scanf("%d",&M[i][j]);

    for(int j=0;j<m;j++){
     R[j]=0; 
     for(int i=0;i<n;i++) R[j]+=V[i]*M[i][j];
    }

    printf("Résultat: (");
    for(int j=0;j<m;j++)
     printf("%d ",R[j]);
    printf(")\n");
}

int main() {
    int choix;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche séquentielle\n");
        printf("4. Multiplication a × b (additions)\n");
        printf("5. Tester si un tableau est trié\n");
        printf("6. Médiane d'un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur × matrice\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1: sommeMatrices(); break;
            case 2: produitMatrices(); break;
            case 3: rechercheSeq(); break;
            case 4: multParAddition(); break;
            case 5: testTrie(); break;
            case 6: mediane(); break;
            case 7: inverser(); break;
            case 8: produitVectoriel(); break;
            case 9: produitVecteurMatrice(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while(choix!=0);

    return 0;
}