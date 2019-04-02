#include "RecipeList.h"

//Declaration
RecipeList::RecipeList(){
  nextRecipe = NULL;
  previousRecipe = NULL;
  current = NULL;
}


//setters

//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}
