#include <cstdlib>
#include "RecipeList.h"

using std::cout;
using std::endl;

int main()
{
  RecipeList currentList = RecipeList();

  currentList.importAll();
  Recipe* temporary2 = currentList.findRecipe("r2");
  temporary2->printRecipeName();
  temporary2->printIngredients();
  temporary2->printInstructions();

  currentList.findByIngredient("a");
  /*
  currentList.addRecipe();




  //currentList.removeRecipe("val");
  //currentList.findRecipe("val");
  cout << "FBI\n";
  currentList.findByIngredient("1");
  */
  return 0;
}


//TODO List
/*
PRINT INSTRUCTIONS MAY NOT WORK!
Fix printIngredients-DONE
Implement cooking directions-DONE
Find recipes with specific ingredients-DONE
Export data-DONE
Import data-DONE
Flip ingredient and ingredient amount
********************************************
//Possible features
Frequency statistic

Sorting system

Find which ingredients are the most common throughout all recipes
Whichever recipe contains the most common ingredients will be placed first in recipeList


Searching by ingredients

Returns array of pointers to recipes inside recipeList
if ingredient exists inside recipe, add the recipe to the array of pointers
*/
