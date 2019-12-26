/////	//////	//////	//////		//		//	//////
//	//	//		//	//	//	 //		///	   ///	//
// //	//		//	//	//	 //		////  ////	//
/////	////	//////	//	 //		//	//	//	////
//	//	//		//	//	//	 //		//		//	//
//	//	//		//	//	//	 //		//		//	//
//	//	//////	//	//	//////		//		//	//////

Il write this first in English, and give it as a translation exercise to my counter part

=>	Every thing is Expression
For my AST, pretty much everything is an expression, why so I only have to remember to calculer to get what I need

=>	Vector of coords, house index pair
At first my solution (and that of a few of my comerades) was to 
	pick 3 random numbers between 0 and the radius
	check that combined they made a valid coord (sum of numbers is even and within radius*2)
	check the coordinate is availiable

	This falls appart when you're generating random coords for a large zone
	and only one spot is free.
	A more efficient method is needed

So lets generate a vector with all the legal coordinates so we can randomly choose new coordinates from a open subset
The pattern found in the hex coords was:
	the first layer is a particular order of the permutations of {-1,0,1}
	each subsequent layer can be calculated for the layers below
		aligned with the axes: layernum * "coords of the first layer hex below it"
		else: the sum of the two touching lower layer hexes 