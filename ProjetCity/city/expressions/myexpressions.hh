#include <string>
#include "expression.hh"
#include <vector>

class RAYON : public Expression {
public:
    RAYON() = default;
    RAYON(const RAYON &) = default;
    RAYON(ExpressionPtr rayon);
    /*

    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _rayon;
};

class Construire : public Expression {
public:
    Construire() = delete;
    Construire(const Construire &) = default;
    Construire(ExpressionPtr rayon,std::vector<ExpressionPtr> sts);
    /*

    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _rayon;
    std::vector<ExpressionPtr> _statements;
};

class COORD : public Expression {
public:
    COORD() = delete;
    COORD(const COORD &) = default;
    COORD(ExpressionPtr x,ExpressionPtr y,ExpressionPtr z);

    double calculer(const Contexte& contexte) const override;
    /*
		calculer Can be used to check coords for a house

		or just use the getters below 
	*/
    ExpressionPtr x(const Contexte& contexte) const {return _x.calculer(contexte);}
    ExpressionPtr y(const Contexte& contexte) const {return _y.calculer(contexte);}
    ExpressionPtr z(const Contexte& contexte) const {return _z.calculer(contexte);}


private:
    ExpressionPtr _x,_y,_z;
};

class NODE : public Expression {
public:
    NODE() = delete;
    NODE(const NODE &) = default;
    NODE(ExpressionPtr iMaison);
    /*
	This can revceive a COORD, OPexpression, or IDMaison
	each when calculer() returns the graph node number
	for the house
    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
};

class Maison : public Expression {
public:
    Maison()=default;
    Maison(const Maison &) = default;
    Maison(const std::string &);

    double calculer(const Contexte& contexte) const override;

    void setCOORD(ExpressionPtr coord) {_coord=coord};

private:
    std::string _nom;
    COORD _coord;
};

class IDMaison : public Expression {
public:
    IDMaison() = delete;
    IDMaison(const IDMaison &) = default;
    IDMaison(const std::string &);
	/*
	Like variable this is to help make the 
	<std::string, Maison> map
	*/

    double calculer(const Contexte& contexte) const override;

private:
    std::string _nom;
};

class Route : public Expression {
public:
    Route() = delete;
    Route(const Route &) = default;
    Route(ExpressionPtr src,ExpressionPtr dst);
    /*
	This can revceive a COORD, OPexpression, or IDMaison
	each when calculer() returns the graph node number
	for the house
    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _src, _dst;
};

class Tourner : public Expression {
public:
    Tourner() = delete;
    Tourner(const Tourner &) = default;
    Tourner(ExpressionPtr iMaison,double dir);
    /*
	This can revceive a COORD, OPexpression, or IDMaison
	each when calculer() returns the graph node number
	for the house
    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
    double _dir;
};

class Orienter : public Expression {
public:
    Orienter() = delete;
    Orienter(const Orienter &) = default;
    Orienter(ExpressionPtr iMaison,ExpressionPtr deg);
    /*
		
    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison, _deg;
};

class Deplacer : public Expression {
public:
    Deplacer() = delete;
    Deplacer(const Deplacer &) = default;
    Deplacer(ExpressionPtr iMaison,ExpressionPtr coord);
    /*
	
    */

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison, _coord;
};

class Detruire : public Expression {
public:
    Detruire() = delete;
    Detruire(const Detruire &) = default;
    Detruire(ExpressionPtr iMaison);
    Detruire(ExpressionPtr src,ExpressionPtr dst);
    /*
			
	*/

    double calculer(const Contexte& contexte) const override;

private:
	bool _maison; //flag for house or road delete, init in constrctr
    ExpressionPtr _src, _dst;
};

class Position : public Expression {
public:
    Position() = delete;
    Position(const Position &) = default;
    Position(ExpressionPtr iMaison);
    /*
		cout pos?
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
};

class Orientation : public Expression {
public:
    Orientation() = delete;
    Orientation(const Orientation &) = default;
    Orientation(ExpressionPtr iMaison);
    /*
		cout deg?
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
};

class Voisinage : public Expression {
public:
    Voisinage() = delete;
    Voisinage(const Voisinage &) = default;
    Voisinage(ExpressionPtr iMaison);
    /*
		cout Voisins?
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
};

class Affect : public Expression {
public:
    Affect() = delete;
    Affect(const Affect &) = default;
    Affect(ExpressionPtr idvar, ExpressionPtr exp);
    /*
		cout Voisins?
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _idvar, _exp;
};

class Coloriser : public Expression {
public:
    Coloriser() = delete;
    Coloriser(const Coloriser &) = default;
    Coloriser(ExpressionPtr iMaison, ExpressionPtr color);
    /*
		
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison, _color;
};

class Couleur : public Expression {
public:
    Couleur() = delete;
    Couleur(const Couleur &) = default;
    Couleur(ExpressionPtr iMaison);
    /*
		cout couleur?
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison;
};

class Voisin : public Expression {
public:
    Voisin() = delete;
    Voisin(const Voisin &) = default;
    Voisin(ExpressionPtr iMaison, ExpressionPtr exp);
    /*
		
	*/

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _iMaison, _exp;
};

class hexRGB : public Expression {
public:
    hexRGB() = delete;
    hexRGB(const hexRGB &) = default;
    hexRGB(const std::string &);
    /*
		This one is a bit particular..
		because #ffffff won't change from the moment it's writteb
		I can calculate x, y, z in the constructor

		now why make this an expression?
		well.. I've gotten used to typeing ExpressionPtr (at leaste autocorrect has  ..some how this has turned into an exercise of explaining why everything should be a pointer... btw important stuff is at the left most end of any line.. the further to the right we go (I don't use wordwrap (which is probs why:)) the weirder it gets)
		but also why not return a wavelength from calculer?
		could be used t o   s o r t  b y   c  o  l  o  u  r
    */


    double calculer(const Contexte& contexte) const override;

    double x() const {return _x;}
    double y() const {return _y;}
    double z() const {return _z;}

private:
    double _x,_y,_z;
};

class Si : public Expression {
public:
    Si() = delete;
    Si(const Si &) = default;
    Si(ExpressionPtr exp,std::vector<ExpressionPtr> statements ,std::vector<ExpressionPtr> else_sts);

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _exp;
    std::vector<ExpressionPtr> _statements, _else_sts;
};

class TantQue : public Expression {
public:
    TantQue() = delete;
    TantQue(const TantQue &) = default;
    TantQue(ExpressionPtr exp,std::vector<ExpressionPtr> statements ,std::vector<ExpressionPtr> else);

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _exp;
    std::vector<ExpressionPtr> _statements;
};

class Repeter : public Expression {
public:
    Repeter() = delete;
    Repeter(const Repeter &) = default;
    Repeter(ExpressionPtr exp,std::vector<ExpressionPtr> statements ,std::vector<ExpressionPtr> else);

    double calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _exp;
    std::vector<ExpressionPtr> _statements;
};//J'aurrais bien aime' moins me repeter...