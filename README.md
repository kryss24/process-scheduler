 pour la priorite avec preemtion , j'ai decide plutot de faire la priorite non premmtive l'algoritheme execute le processus avec la plus grande priotite si 2 processus ont la meme priorite alors on utilse 
 le fcfs pour executer
 voici l'algorithme ici mais lorsque j'execute dans le code principale je rencontre tellement d'erreur
 
i1 lorsque j'ai fait le priote sans preemtion apres avoir corriger les erreus  des que je coche cette option l'application se ferme
i2 on voit que toute la grille ne s'affichce pas c'est comme si c'etait bloque
i3 on voit bien le decalage entre les  processus  lorsque les processus  ont le meme temsps d'execution notamment le processus p2 et P4; P4 devait continuer directement a la suite de P2 ainsi que P1 et p3
i4  decalge d'une colonne entre P2 et P4 
je ne comprends pas le probleme de decalage


Ici , j'ai ameliorer l'interface la grille pour la simulation du fcfs ainsi que la couleur des barres de progression 
mais j'ai remarque que la fenetre est petite pour afficher toute la grille du genre la grille calle  a 23 au lieu de continuer  j'ai essaye de modifier les tailles des  // Dimensions de la grille
    const int cellWidth = 30;  // Largeur de chaque cellule
    const int rowHeight = 20;  // Hauteur de chaque rangée
    const int xOffset = 100;    // Décalage horizontal (pour les temps)
    const int yOffset = 50;     // Décalage vertical (pour commencer à dessiner  ca n'a pas donne 
et aussi que lorsqu'on entre les dates d'arriver des processus par ordre aleatoire 9,6,2,5 ca fonctionne bien mais il ya un decalage d'une colonne entre le premier et le deuxieme processus a etre execute  lorsque je modifie l'algorithme fcfs maintenant ca ne donne plus
