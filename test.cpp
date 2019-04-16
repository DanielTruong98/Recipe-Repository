#include <cstdlib>
#include "RecipeList.h"

using std::cout;
using std::endl;

int main()
{
  RecipeList currentList = RecipeList();

  currentList.addRecipe();
  Recipe* temporary = currentList.findRecipe("val");
  temporary->printRecipeName();
  temporary->printIngredients();
  temporary->printInstructions();

  currentList.addRecipe();
  Recipe* temporary2 = currentList.findRecipe("val2");
  temporary2->printRecipeName();
  temporary2->printIngredients();
  temporary->printInstructions();

  currentList.removeRecipe("val");
  currentList.findRecipe("val");
  cout << "FBI\n";
  currentList.findByIngredient("1");
  return 0;
}


//TODO List
/*
PRINT INSTRUCTIONS MAY NOT WORK!
Fix printIngredients-DONE
Implement cooking directions-DONE
Find recipes with specific ingredients
Export data
Import data
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
