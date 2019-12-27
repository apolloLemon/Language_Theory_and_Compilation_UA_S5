README.txt
Coyle Matthew
Coustance Nathan

City Project - Théorie des langages et compilation

/!\ Nous sommes conscients que cette version n'est pas aboutie.
	(Elle fonctionne mais peut occasionner quelques erreurs.)

	En effet, la plupart des idées sont là mais la conception de l'AST
	et de la ville auraient pu être meilleure.


Fonctionnement :

=> TOUT est Expression
Pour l'AST, tout est une expression, on a juste à se souvenir de calculer()
Mais il y a des dynamics cast (pour les getters de coord et idmaison)

=> Vecteurs de coordonnées, index de maisons
Au début :  on prenait 3 chiffres aléatoires entre 0 et le rayon,
			on vérifiait que combinés, ils formaient des coordonnées valides. (somme paire inférieure à rayon*2)
			on vérifiait que les coordonnées étaient disponible.

Cette méthode n'est pas la plus efficace puisque générer des coordonnées aléatoire
dans une grande zone quand seulement un endroit est disponible peu prendre un temps
aléatoirement long.

Donc on génère un vecteur avec toutes les coordonnées possibles afin de choisir
des coordonnées aléatoires parmis une liste de coordonénes disponibles.

Le schéma pour les coordonnées des hexagones est le suivant :
	La première couche sont les différentes permutations de {-1,0,1}
	Chaque couche peut être calculée en fonction des couches inférieures
		Emplacement aligné avec une axe : 
				(numéro de la couche) * (coordonnées de la cellule de la première couche alignée)
		Sinon :
				On additionne les coordonnées des deux emplacements inférieurs connexes
